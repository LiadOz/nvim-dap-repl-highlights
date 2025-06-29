local M = {}
M.PARSER_NAME = 'dap_repl'

local utils = require('nvim-dap-repl-highlights.utils')
local ts_override = require('nvim-dap-repl-highlights.treesitter_override')
local buf_lang = {}

function M.get_repl_lang_for_session(session)
  if not session then
    return nil
  end
  local lang = session.config and session.config.repl_lang
  if lang == nil then
    local ok, ts_lang = pcall(require("nvim-treesitter.parsers").ft_to_lang, session.filetype)
    if ok then lang = ts_lang end
  end
  if not lang then -- allow user to provide empty string to suppress this message
    vim.notify("REPL highlight language not found for current dap session", vim.log.levels.WARN)
  end
  return lang
end

function M.setup_injections(bufnr, injected_lang)
  if injected_lang and not utils.check_treesitter_parser_exists(M.PARSER_NAME) then
    vim.notify(M.PARSER_NAME .. " parser not found, make sure you installed it using treesitter", vim.log.levels.WARN)
    return
  end
  if injected_lang and not utils.check_treesitter_parser_exists(injected_lang) then
    vim.notify(injected_lang .. " parser for injected language not found, make sure you installed it using treesitter", vim.log.levels.WARN)
    return
  end
  if injected_lang == nil then
    injected_lang = ''
  end
  if buf_lang[bufnr] == injected_lang then
    return
  end
  local injections = {}
  if injected_lang ~= '' then
    injections[M.PARSER_NAME] = '((user_input_statement) @injection.content (#set! injection.language "' .. injected_lang .. '") (#set! injection.combined) (#set! injection.include-children))'
  else
    injections = nil
  end
  buf_lang[bufnr] = injected_lang
  local tsparser = ts_override.get_parser(bufnr, M.PARSER_NAME, {injections = injections})
  vim.treesitter.highlighter.new(tsparser)
end

function M.setup_highlights(language, bufnr)
  bufnr = bufnr or 0
  if language then
    M.setup_injections(bufnr, language)
  else
    vim.ui.input({prompt = 'Enter language parser name: '}, function(input)
      if input then
        M.setup_injections(bufnr, input)
      end
    end)
  end
end

function M.setup()
  local ts_parsers = require("nvim-treesitter.parsers")
  local parser_path = vim.fn.fnamemodify(debug.getinfo(1).source:sub(2), ":h:h:h")

  -- Try to call the function that only exists in nvim-treesitter's master branch
  local ok, parser_config = pcall(ts_parsers.get_parser_configs)
  if ok then
    parser_config[M.PARSER_NAME] = {
      install_info = {
        url = parser_path,
        files = { "src/parser.c" },
      },
    }
  else
    vim.api.nvim_create_autocmd("User", {
      group = vim.api.nvim_create_augroup("nvim_dap_repl_highlights", {}),
      pattern = "TSUpdate",
      callback = function()
        ts_parsers[M.PARSER_NAME] = {
          install_info = {
            path =  parser_path,
          },
        }
      end,
    })
  end
end


return M
