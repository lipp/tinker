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
}
external_dependencies = {
}
build = {
   type = "builtin",
   modules = {
      tinker = {
	 incdirs = {
	    "capi"
	 },
	 sources = {
	    "capi/ip_connection.c",
            "capi/bricklet_lcd_20x4.c", 
            "src/tinker.c"
	 },		
	 libraries = {"pthread"},
      },
   },
}
