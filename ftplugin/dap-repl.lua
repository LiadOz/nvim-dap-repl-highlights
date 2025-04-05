local utils = require('nvim-dap-repl-highlights.utils')
local session = require('dap').session()
local lang = utils.lang

if session then
  lang = session.config and session.config.repl_lang
  if lang == nil then
    local ok, ts_lang = pcall(require("nvim-treesitter.parsers").ft_to_lang, session.filetype)
    if ok then lang = ts_lang end
  end
  if not lang then -- allow user to provide empty string to supress this message
    vim.notify("REPL highlight language not found for current dap session", vim.log.levels.WARN)
  end
end

if lang ~= '' then
  utils.lang = require('nvim-dap-repl-highlights').setup_highlights(lang, 0)
end
