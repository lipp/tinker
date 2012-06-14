# About

A Lua module for [bricks and bricklets by Tinkerforge
GmbH](http://www.tinkerforge.com/). Allows working standalone (with
built-in event loop) or with lua-ev.

This module employs luasocket for socket communication and lua-pack
for serialization. It uses the TCP/IP API provided by Tinkerforge and
does not bind to the C API. Thus it does not rely on pthread and does not spawn threads.

# Install

## Via cloning

```shell 
$ git clone git://github.com/lipp/tinker.git
$ luarocks make rockspecs/tinker-scm-1.rockspec 
```

## Directly using luarocks

With LuaRocks > 2.0.4.1:

```shell
$ sudo luarocks install https://raw.github.com/lipp/tinker/master/rockspecs/tinker-scm-1.rockspec
```

Note: luarocks require lua-sec for doing https requests.
Install with apt

```shell
$ sudo apt-get install liblua5.1-sec1
```
or LuaRocks
```shell
$ sudo luarocks install luasec
````

# Usage

See example directory.

## Wrap-up

NOTE: requires brickd running!

```lua
-- load module
local tinker = require'tinker'
-- create an ip connection to the brickd (default ip:localhost,port:4223).
local ipcon = tinker.ipcon()
-- create an lcd instance by specifying the stackid
local lcd = ipcon:lcd_20x4(2)
-- call some methods on the lcd object
lcd:backlight_on()
lcd:write_line(0,0,'Lua is awesome')
lcd:backlight_off()
```

# API

The API tries to be very close to the APIs provided by
Tinkerforge. There are some differences though. 

## tinker (module)

### tinker.ipcon(address,port)

An ipcon object instance is required to "create" bricks or bricklets.

## ipcon (object)

### ipcon:dispatch_events()

Reads all available data on the event socket and dispatches them
(e.g. calling registered callbacks) in the current thread context.
This method is only required, if not using ipcon:loop() for event dispatching.
See [full example](https://github.com/lipp/tinker/blob/master/example/lcd20x4_buttons_ev.lua).

### ipcon:event_socket()

Returns the (luasocket) socket instance. Can be used to retrieve the
fd and do async io, e.g. with lua-ev:

```lua
local sock = ipcon:event_socket()
local fd = sock:getfd()
local io = ev.IO.new(
      function()
         ipcon:dispatch_events()
      end,fd,ev.READ)
```
See [full example](https://github.com/lipp/tinker/blob/master/example/lcd20x4_buttons_ev.lua).

### ipcon:loop()

Reads and dispatches incoming messages (e.g. triggering
callbacks). This is a very basic event loop, which only allows to
handle brick/bricklet events. If you need to process other events/IO,
use some more sophisticated event loop mechanism, like lua-ev or
employ a threading environment.

### ipcon:enumerate(arg)

Depending on the type of arg, enumerate does two different things:

#### type(arg) == 'number' or type(arg) == 'nil'

This is the sync/blocking enumerate variant.
Enumerates all available devices and returns them as a table with the
stackid as key with sub tables which contain uuid, name and
is_new. The call waits X seconds for the bricks/bricklets to answer
the enumeration before return, where X is 0.3 or arg (if arg is a number).

```lua
local ipcon = tinker.ipcon()
for stackid,dev in pairs(ipcon:enumerate()) do
    print(stackid,dev.uuid,dev.name,dev.is_new)
end
```

#### type(arg) == 'function'

This is the async/event based enumerate variant. It registers a Lua callback
function to be called whenever devices (bricks/bricklets) "post" a 
CALLBACK_ENUMERATE response. The Lua function
gets passed in the device description. The return value is a function,
which can be called to trigger enumeration. 
The example mimics the behavior of the 'sync' variant of ipcon:enumerate().

```lua
local ipcon = tinker.ipcon()
local print_enum_dev = function(dev)
      print(dev.uuid,dev.name,dev.stackid,dev.is_new)
end
local trigger_enum = ipcon:enumerate(print_enum_dev)
trigger_enum()
ipcon:loop()
```

NOTE: The uuid is NOT base 58 encoded as you see them in the brickv! 

### ipcon:lcd_20x4(stackid)

Creates a lcd20x4 bricklet object for the device with the specified stackid.

## lcd_20x4 (object)

This is an example how to use the brick/bricklet object, and how
methods and callbacks are mapped.

### lcd_20x4:write_line(x,y,text)

Writes 'text' on the display with the position specified.

### lcd_20x4:clear_display()

Clears the entire display.

### lcd_20x4:backlight_on()

Enables the backlight.

### lcd_20x4:backlight_off()

Disables the backlight.

### bool lcd_20x4:is_backlight_on()

Determines whether the backlight is on.

### lcd_20x4:button_pressed(function(button_index) end)

Registers a callback, which will be called whenever a button is
pressed. The callback gets the button_index passed in.

## Other bricks or bricklets

### Constructor

The ipcon is required to construct a new brick or bricklet instance.
It provides a method called as the brick/bricklet and takes the
stackid (NOT the uuid!) as argument: e.g.

```lua
local ipcon = tinker.ipcon()
local imu = ipcon:imu(4) -- assume stackid 4
local cur = ipcon:current_12(3) -- assume stackid 3
local temp = ipcon:temperature_ir(5) -- assume stackid 5
-- etc.
```

The create methods are always ALL lowercase and may have underscores.

### Methods

The methods are all called exactly like the TCP/IP documentation of
the respective brick/bricklet says:

```lua
local ipcon = tinker.ipcon()
local imu = ipcon:imu(4) -- assume stackid 4
local x,y,z = imu:get_acceleration() -- called exactly as in TCP/IP docu
```

### Callbacks

The callbacks can be registered by calling a method named like the
callback event (as stated in the TCP/IP documentation of the
brick/bricklet, but without CALLBACK_ prefix and all lowercase, e.g.:
CALLBACK_VOLTAGE -> voltage) and passing in the Lua function to be called. 
The Lua function gets all callback data passed in as arguments (if available).

```lua
local ipcon = tinker.ipcon()
local lcd = ipcon:lcd_20x4(6) -- assume stackid 6
-- The TCP/IP doc calls this CALLBACK_BUTTON_PRESSED
lcd:button_pressed(function(button_index) 
   print('button', button_index, 'pressed')
end)
-- block forever and wait for button press events
ipcon:loop()
```

# Status

ALL bricks and bricklet are "implemented", not all tested
though (need more bricks!). Feedback is very welcome!


