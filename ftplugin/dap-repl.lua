local session = require('dap').session()
local lang = nil

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

if lang and lang ~= '' then
  require('nvim-dap-repl-highlights').setup_injections(0, lang)
end
