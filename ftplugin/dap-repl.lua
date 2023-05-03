local session = require('dap').session()
local lang = nil

if session then
  lang = session.config.repl_lang or session.adapter.repl_lang
  if not lang then -- allow user to provide empty string to supress this message
    vim.notify("REPL highlight language not found for current dap session", vim.log.levels.WARN)
  end
end

if lang and lang ~= '' then
  require('nvim-dap-repl-highlights').setup_injections(0, lang)
end
