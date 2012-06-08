package = "tinker"
version = "scm-1"
source = {
   url = "git://github.com/lipp/tinker.git",
}
description = {
   summary = "Lua bindings to tinkerforge bricks and bricklets.",
   homepage = "http://github.com/lipp/tinker",
   license = "MIT/X11",
}
dependencies = {
   "lua >= 5.1",
   "luasocket",
   "lpack"
}
build = {
   type = "none",
   install = {
      lua = {
         ['tinker'] = 'tinker.lua'
      }
   }
}

