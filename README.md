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

### ipcon:join_thread()

Waits for the (internal) IO and message dispatch loops to finish.

### ipcon:getfd()

Returns the internal socket fd (filedescriptor) which can be used to
run an external event loop (e.g. lua-ev).

### ipcon:dispatch()

Reads all available data on the socket and dispatches them
(e.g. calling registered callbacks) in the current thread context.

### ipcon:lcd20x4(uid)

Creates a lcd20x4 bricklet object for the device with uid.

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



