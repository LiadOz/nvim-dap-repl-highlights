local M = {}

function M.check_treesitter_parser_exists(language)
  local install_dir = require("nvim-treesitter.config").get_install_dir("parser")
  for f in vim.fs.dir(install_dir) do
    if vim.fn.fnamemodify(f, ":t:r") == language then
      return true
    end
  end
  return false
end

return M
