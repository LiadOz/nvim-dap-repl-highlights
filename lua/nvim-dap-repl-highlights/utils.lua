local M = {}

function M.check_treesitter_parser_exists(language)
  -- nvim-treesitter/info.lua module only exists in master branch
  local ok, ts_info = pcall(require, "nvim-treesitter.info")
  local installed_parsers = {}

  if ok then
    installed_parsers = ts_info.installed_parsers()
  else
    installed_parsers = require("nvim-treesitter.config").get_installed("parsers")
  end

  for _, parser in ipairs(installed_parsers) do
    if parser == language then
      return true
    end
  end
  return false
end

return M
