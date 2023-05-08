local M = {}
M.PARSER_NAME = 'dap_repl'

local utils = require('nvim-dap-repl-highlights.utils')

function M.setup_injections(bufnr, injected_lang)
  if not utils.check_treesitter_parser_exists(M.PARSER_NAME) then
    vim.notify(M.PARSER_NAME .. " parser not found, make sure you installed it using treesitter", vim.log.levels.WARN)
    return
  end
  if not utils.check_treesitter_parser_exists(injected_lang) then
    vim.notify(injected_lang .. " parser for injected language not found, make sure you installed it using treesitter", vim.log.levels.WARN)
    return
  end
  local injections = {}
  injections[M.PARSER_NAME] = '((user_input_statement) @content @combined (#set! language ' .. injected_lang .. '))'
  local tsparser = vim.treesitter.get_parser(bufnr, M.PARSER_NAME, {injections = injections})
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
  local parser_config = require("nvim-treesitter.parsers").get_parser_configs()
  parser_config[M.PARSER_NAME] = {
    install_info = {
      url = vim.fn.fnamemodify(debug.getinfo(1).source:sub(2), ":h:h:h"),
      files = { "src/parser.c" },
    },
    filetype = "dap-repl",
  }
end


return M
