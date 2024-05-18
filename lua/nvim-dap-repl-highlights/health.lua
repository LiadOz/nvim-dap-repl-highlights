local M = {}

local rl = require('nvim-dap-repl-highlights')
local utils = require('nvim-dap-repl-highlights.utils')
local ok = vim.health.ok or vim.health.report_ok
local warn = vim.health.warn or vim.health.report_warn
local error = vim.health.error or vim.health.report_error

function M.check()
  if vim.fn.has('nvim-0.9.0') == 0 then
    error("nvim-dap-repl-highlights requires neovim version >= 0.9.0")
    return
  end

  if utils.check_treesitter_parser_exists(rl.PARSER_NAME) then
    ok("")
  else
    warn(rl.PARSER_NAME .. " parser not installed", "Run TSInstall " .. rl.PARSER_NAME)
  end
end


return M
