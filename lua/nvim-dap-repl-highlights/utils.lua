local M = {}

M.lang = nil

function M.check_treesitter_parser_exists(language)
  local installed_parsers = require("nvim-treesitter.info").installed_parsers()
  for _, parser in ipairs(installed_parsers) do
    if parser == language then
      return true
    end
  end
  return false
end

return M
