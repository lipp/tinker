# About

A Lua module for [bricks and bricklets by Tinkerforge
GmbH](http://www.tinkerforge.com/). Allows working standalone (with
built-in event loop) or with lua-ev.

(Lua) tinker employs luasocket and lua-pack to use the TCP/IP API  by
Tinkerforge. It does not rely on pthread and does not spawn threads.

# Install

```shell 
git clone git://github.com/lipp/tinker.git
luarocks make rockspecs/tinker-scm-1.rockspec 
```

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
-- init the module, which connects to default brickd (localhost,port 4223).
local ipcon = tinker.ipcon()
-- create the brick instance by specifying the stackid
local lcd = ipcon:lcd_20x4(2)
-- call some methods on the lcd object
lcd:backlight_on()
lcd:write_line(0,0,'Lua is awesome')
lcd:backlight_off()
```

# API

The API tries to be very close to the C API provided by
tinkerforge. There are some differences though. 

## tinker (module)

### tinker.ipcon(address,port)

An ipcon object instance is required to "create" bricks or bricklets.

## ipcon (object)

### ipcon:dispatch_events()

Reads all available data on the event socket and dispatches them
(e.g. calling registered callbacks) in the current thread context.

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

### ipcon:loop()

Reads and dispatches incoming messages (e.g. triggering callbacks).

### ipcon:enumerate(timeout)

Enumerates all available devices and returns them as a table with the
stackid as key with sub tables which contain uuid, name and
is_new. The timeout is optional and default to 0.3 secs.

```lua
local ipcon = tinker.ipcon()
for stackid,dev in pairs(ipcon:enumerate()) do
    print(stackid,dev.uuid,dev.name,dev.is_new)
end
```
NOTE: The uuid is NOT base 58 encoded as you see in the brickv! 

### ipcon:lcd_20x4(stackid)

Creates a lcd20x4 bricklet object for the device with the specified stackid.

## lcd_20x4 (object)

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
```
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

The callbacks are called like the TCP/IP documentation of
brick/bricklet says without CALLBACK_ prefix and all lowercase
(CALLBACK_VOLTAGE -> voltage). The
callback name field accesses a method, which allows to register a Lua
function. It gets all callback data passed in as arguments (if available).

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
though. Feedback is very welcome!


