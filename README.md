# nvim-dap-repl-highlights
Add syntax highlighting to the [nvim-dap](https://github.com/mfussenegger/nvim-dap) REPL buffer using treesitter.
| Before                                                                                                          | After                                                                                                          |
| --------------------------------------------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------------------------- |
| ![before](https://user-images.githubusercontent.com/20954878/235993939-a3ad95eb-9dfa-41a4-b70e-3a4e890e2adf.png) | ![image](https://user-images.githubusercontent.com/20954878/235993604-642fe658-6cc9-40e0-846c-00df11d963e1.png)|

## Requirements
* Neovim 0.9 or later
* [nvim-treesitter](https://github.com/nvim-treesitter/nvim-treesitter)

## Setup
Install the plugin and the requirements using your favourite method. Once installed, make sure you configured treesitter [highlighting](https://github.com/nvim-treesitter/nvim-treesitter#modules) then add the following to your lua config
```lua
require('nvim-dap-repl-highlights').setup()
```
After initially setting up the plugin the dap_repl parser needs to be installed, this can be done manually by running `:TSInstall dap_repl` or by using the `ensure_installed` option of nvim-treesitter.
**NOTE:** If you use the `ensure_installed` option you must first setup `nvim-dap-repl-highlights` or else the `dap_repl` parser won't be found, for example
```lua
require('nvim-dap-repl-highlights').setup()
require('nvim-treesitter.configs').setup {
  highlight = {
    enable = true,
  },
  ensure_installed = { 'dap_repl', ... },
  ...
}
```

## Usage
By default, the plugin detects the language to use in the REPL by looking at the **filetype** used to to launch dap. Obviously in order to have syntax highlighting for certain language you will need to have a treesitter parser for that language, alongside the `dap_repl` parser.
This may not fit all use cases.

You could instead use the command `:lua require('nvim-dap-repl-highlights').setup_highlights('python')` which will set python highlights in the current repl buffer. 
Alternatively the function can be called without specifiying the language, this will prompt the user for a language.

Additionally you could specify in the **dap** configuration the repl language to use, for example if you want your python repl to have javascript highlighting:
```lua
local dap = require('dap')
dap.configurations.python = {
  {
    name = "Python with javascript repl because I like to watch the world burn 🔥🔥🔥",
    type = "python",
    request = "launch",
    program = "${file}",
    repl_lang = "javascript"
  },
}
```
The repl_lang option takes precedence over the filetype.
