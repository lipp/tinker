# About

A Lua binding for [bricks and bricklets by Tinkerforge
GmbH](http://www.tinkerforge.com/). Allows working standalone (with
built-in event loop) or with lua-ev.

# Build

```shell 
git clone git://github.com/lipp/tinker.git
luarocks make rockspecs/tinker-scm-1.rockspec 
```

# Usage

See example directory.


## Wrap-up

NOTE: requires brickd running!

```lua
-- load module
local tinker = require'tinker'
-- create ipcon which connects to default brickd (localhost,port 4223).
local ipcon = tinker.ipcon()
-- let the ipcon create a brick/bricklet object
local lcd = ipcon:lcd20x4()
-- call some methods on the lcd object
lcd:backlight_on()
lcd:write_line(0,0,'Lua greetz all bricks')
lcd:backlight_off()
```

# API

The API tries to be very close to the C API provided by
tinkerforge. There are some differences though. 

## tinker (module)

### tinker.ipcon(address,port,dont_start_threads)

Creates a new ipcon (ip_connection). This is some kind of root object
and factory for all bricks/bricklets you want to use.

## ipcon (object)

### ipcon:lcd20x4()

Creates a lcd20x4 bricklet object.

## lcd20x4 (object)

### lcd20x4:write_line(x,y,text)

Writes 'text' on the display with the position specified.

### lcd20x4:clear_display()

Clears the entire display.

### lcd20x4:backlight_on()

Enables the backlight.

### lcd20x4:backlight_off()

Disables the backlight.

