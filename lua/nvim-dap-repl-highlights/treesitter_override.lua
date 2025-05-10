local M = {}

--- The following functions are based of lua/vim/treesitter.lua ---
--- see https://github.com/neovim/neovim/issues/33944
--- since the query language is detemrined dynamically, we need to be able to change the injection language on existing buffers
--- current neovim treesitter implementation does not generate a new parser for a buffer if the same language is used
--- this is required due to needing to use the same language with different injection

local api = vim.api
parsers = {}
local LanguageTree = require('vim.treesitter.languagetree')

local function valid_lang(lang)
  return lang and lang ~= ''
end

--- Creates a new parser
---
---@param bufnr integer Buffer the parser will be tied to (0 for current buffer)
---@param lang string Language of the parser
---@param opts (table|nil) Options to pass to the created language tree
---
---@return vim.treesitter.LanguageTree object to use for parsing
local function create_parser(bufnr, lang, opts)
  -- TODO need to remove previous existing buffer
  bufnr = vim._resolve_bufnr(bufnr)

  local self = LanguageTree.new(bufnr, lang, opts)

  local function bytes_cb(_, ...)
    self:_on_bytes(...)
  end

  local function detach_cb(_, ...)
    if parsers[bufnr] == self then
      parsers[bufnr] = nil
    end
    self:_on_detach(...)
  end

  local function reload_cb(_)
    self:_on_reload()
  end

  local source = self:source() --[[@as integer]]

  api.nvim_buf_attach(
    source,
    false,
    { on_bytes = bytes_cb, on_detach = detach_cb, on_reload = reload_cb, preview = true }
  )

  return self
end

--- Returns the parser for a specific buffer and attaches it to the buffer
---
--- If needed, this will create the parser.
---
--- If no parser can be created, an error is thrown. Set `opts.error = false` to suppress this and
--- return nil (and an error message) instead. WARNING: This behavior will become default in Nvim
--- 0.12 and the option will be removed.
---
---@param bufnr (integer|nil) Buffer the parser should be tied to (default: current buffer)
---@param lang (string|nil) Language of this parser (default: from buffer filetype)
---@param opts (table|nil) Options to pass to the created language tree
---
---@return vim.treesitter.LanguageTree? object to use for parsing
---@return string? error message, if applicable
function M.get_parser(bufnr, lang, opts)
  opts = opts or {}
  local should_error = opts.error == nil or opts.error

  bufnr = vim._resolve_bufnr(bufnr)

  if not valid_lang(lang) then
    lang = M.language.get_lang(vim.bo[bufnr].filetype)
  end

  if not valid_lang(lang) then
    if not parsers[bufnr] then
      local err_msg =
        string.format('Parser not found for buffer %s: language could not be determined', bufnr)
      if should_error then
        error(err_msg)
      end
      return nil, err_msg
    end
  else -- in the original code, there is a check here if the buffer already has a parser with the same lang, this is the reason this file is required
    if not api.nvim_buf_is_loaded(bufnr) then
      error(('Buffer %s must be loaded to create parser'):format(bufnr))
    end
    local parser = vim.F.npcall(create_parser, bufnr, lang, opts)
    if not parser then
      local err_msg =
        string.format('Parser could not be created for buffer %s and language "%s"', bufnr, lang)
      if should_error then
        error(err_msg)
      end
      return nil, err_msg
    end
    parsers[bufnr] = parser
  end

  parsers[bufnr]:register_cbs(opts.buf_attach_cbs)

  return parsers[bufnr]
end

return M
