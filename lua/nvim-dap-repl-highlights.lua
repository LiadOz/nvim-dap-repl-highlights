local M = {}
local PARSER_NAME = 'dap_repl'

local function check_treesitter_parser_exists(language)
  local ok, _ = pcall(vim.treesitter.language.inspect, language)
  return ok
end

function M.setup_injections(bufnr, injected_lang)
  if not check_treesitter_parser_exists(PARSER_NAME) then
    vim.notify(PARSER_NAME .. " parser not found, make sure you installed it using treesitter", vim.log.levels.WARN)
    return
  end
  if not check_treesitter_parser_exists(injected_lang) then
    vim.notify(injected_lang .. " parser for injected language not found, make sure you installed it using treesitter", vim.log.levels.WARN)
    return
  end
  local injections = {}
  injections[PARSER_NAME] = '((user_input_statement) @content @combined (#set! language ' .. injected_lang .. '))'
  local tsparser = vim.treesitter.get_parser(bufnr, PARSER_NAME, {injections = injections})
  vim.treesitter.highlighter.new(tsparser)
end

function M.setup(opts)
  local parser_config = require("nvim-treesitter.parsers").get_parser_configs()
  parser_config[PARSER_NAME] = {
    install_info = {
      url = vim.fn.fnamemodify(debug.getinfo(1).source:sub(2), ":h:h"),
      files = { "src/parser.c" },
    },
    filetype = "dap-repl",
  }
end


return M
