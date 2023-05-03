local M = {}

function M.check_treesitter_parser_exists(language)
  local ok, _ = pcall(vim.treesitter.language.inspect, language)
  return ok
end

return M
