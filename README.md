# About

A Lua module for [bricks and bricklets by Tinkerforge
GmbH](http://www.tinkerforge.com/). Allows working standalone (with
built-in event loop) or with lua-ev.

(Lua) tinker employs luasocket and lua-pack to use the TCP/IP API  by Tinkerforge.

# Install

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
-- init the module, which connects to default brickd (localhost,port 4223).
local ipcon = tinker.ipcon()
-- create the brick instance by specifying the stackid
local lcd = ipcon:lcd20x4(2)
-- call some methods on the lcd object
lcd:backlight_on()
lcd:write_line(0,0,'Lua greetz all bricks')
lcd:backlight_off()
```

# API

The API tries to be very close to the C API provided by
tinkerforge. There are some differences though. 

## tinker (module)

### tinker.ipcon(address,port)

## ipcon (object)

### ipcon:dispatch_events()

Reads all available data on the event socket and dispatches them
(e.g. calling registered callbacks) in the current thread context.

### ipcon:lcd20x4(stackid)

Creates a lcd20x4 bricklet object for the device with the specified stackid.

## lcd20x4 (object)

### lcd20x4:write_line(x,y,text)

Writes 'text' on the display with the position specified.

### lcd20x4:clear_display()

Clears the entire display.

### lcd20x4:backlight_on()

Enables the backlight.

### lcd20x4:backlight_off()

Disables the backlight.

### bool lcd20x4:is_backlight_on()

Determines whether the backlight is on.

### lcd20x4:button_pressed(function(button_index) end)

Registers a callback, which will be called whenever a button is
pressed. The callback gets the button_index passed in.



