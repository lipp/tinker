#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"

#include "ip_connection.h"
#include "bricklet_lcd_20x4.h"

#include <string.h>
#include <assert.h>
#include <stdio.h>

#define TINKER_IPCON_META "tinker.ipcon"
#define TINKER_LCD20x4_META "tinker.lcd20x4"


struct tinker_ipcon {
  lua_State *L;
  IPConnection ipcon;
};

static int tinker_ipcon(lua_State *L) {
  int port = luaL_optint(L, 2, 4223);
  const char* host = luaL_optstring(L, 1, "localhost");;
  IPConnection *ipcon = lua_newuserdata(L, sizeof(IPConnection));

  if(ipcon_create(ipcon, host, port) < 0) {
    luaL_error(L, "ipcon_create failed");
  }

  luaL_getmetatable(L, TINKER_IPCON_META);
  lua_setmetatable(L, -2);

  return 1;
}

static int tinker_ipcon_destroy(lua_State* L) {
  IPConnection *ipcon = (IPConnection *)luaL_checkudata(L, 1, TINKER_IPCON_META);
  ipcon_destroy(ipcon);
  return 0;
}

static int tinker_ipcon_lcd20x4(lua_State* L) {
  IPConnection *ipcon = (IPConnection *)luaL_checkudata(L, 1, TINKER_IPCON_META);
  const char* uid = luaL_checkstring(L, 2); 
  LCD20x4 *lcd = lua_newuserdata(L, sizeof(LCD20x4));
  lcd_20x4_create(lcd, uid);
  luaL_getmetatable(L, TINKER_LCD20x4_META);
  lua_setmetatable(L, -2);
  
  if(ipcon_add_device(ipcon, lcd) < 0) {
    luaL_error(L, "ipcon_add_device failed");
  }
  return 1;
}

static int tinker_lcd20x4_backlight_on(lua_State* L) {
  LCD20x4 *lcd = (LCD20x4 *)luaL_checkudata(L, 1, TINKER_LCD20x4_META);
  lcd_20x4_backlight_on(lcd);
  return 0;
}

static int tinker_lcd20x4_backlight_off(lua_State* L) {
  LCD20x4 *lcd = (LCD20x4 *)luaL_checkudata(L, 1, TINKER_LCD20x4_META);
  lcd_20x4_backlight_off(lcd);
  return 0;
}

static int tinker_lcd20x4_clear_display(lua_State* L) {
  LCD20x4 *lcd = (LCD20x4 *)luaL_checkudata(L, 1, TINKER_LCD20x4_META);
  lcd_20x4_clear_display(lcd);
  return 0;
}

static int tinker_lcd20x4_is_backlight_on(lua_State* L) {
  LCD20x4 *lcd = (LCD20x4 *)luaL_checkudata(L, 1, TINKER_LCD20x4_META);
  bool on;
  lcd_20x4_is_backlight_on(lcd, &on);
  lua_pushboolean(L, on);
  return 1;
}

static int tinker_lcd20x4_write_line(lua_State* L) {
  LCD20x4 *lcd = (LCD20x4 *)luaL_checkudata(L, 1, TINKER_LCD20x4_META);
  int line = luaL_checkinteger(L, 2);
  int position = luaL_checkinteger(L, 3);
  char *text = luaL_checkstring(L, 4);
  lcd_20x4_write_line(lcd, line, position, text);
  return 0;
}

static const struct luaL_Reg tinker_module_methods [] = {
  {"ipcon",tinker_ipcon},
  {NULL,NULL}
};

static const struct luaL_Reg tinker_ipcon_methods [] = {
  {"destroy",tinker_ipcon_destroy},
  {"__gc",tinker_ipcon_destroy},
  {"lcd20x4",tinker_ipcon_lcd20x4},
  {NULL,NULL}
};

static const struct luaL_Reg tinker_lcd20x4_methods [] = {
  {"backlight_on",tinker_lcd20x4_backlight_on},
  {"backlight_off",tinker_lcd20x4_backlight_off},
  {"is_backlight_on",tinker_lcd20x4_is_backlight_on},
  {"clear_display",tinker_lcd20x4_clear_display},
  {"write_line",tinker_lcd20x4_write_line},
  {NULL,NULL}
};

struct tinker_constant {
  const char *name;
  int value;
};

struct tinker_constant tinker_constants [] = {};
  /*  {"SERVER_OPTIONS_DEFEAT_CLIENT_MASK",LWS_SERVER_OPTION_DEFEAT_CLIENT_MASK},
  {"SERVER_OPTION_REQUIRE_VALID_OPENSSL_CLIENT_CERT",LWS_SERVER_OPTION_REQUIRE_VALID_OPENSSL_CLIENT_CERT},
  {"WRITE_TEXT",LWS_WRITE_TEXT},
  {"WRITE_BINARY",LWS_WRITE_BINARY},
  {"WRITE_CONTINUATION",LWS_WRITE_CONTINUATION},
  {"WRITE_HTTP",LWS_WRITE_HTTP},
  {"WRITE_CLOSE",LWS_WRITE_CLOSE},
  {"WRITE_PING",LWS_WRITE_PING},
  {"WRITE_PONG",LWS_WRITE_PONG},
  {"WRITE_NO_FIN",LWS_WRITE_NO_FIN},
  {"WRITE_CLIENT_IGNORE_XOR_MASK",LWS_WRITE_CLIENT_IGNORE_XOR_MASK},
  {NULL,0}
};

static void luaws_register_constants(lua_State *L, struct luaws_constant *constants) {
  while(constants->name) {
    lua_pushinteger(L, constants->value);
    lua_setfield(L, -2, constants->name);
    ++constants;
  }
  }*/

int luaopen_tinker(lua_State *L) {
  luaL_newmetatable(L, TINKER_IPCON_META);
  lua_pushvalue(L, -1);
  lua_setfield(L, -2, "__index");
  luaL_register(L, NULL, tinker_ipcon_methods);
  luaL_newmetatable(L, TINKER_LCD20x4_META);
  lua_pushvalue(L, -1);
  lua_setfield(L, -2, "__index");
  luaL_register(L, NULL, tinker_lcd20x4_methods);
  luaL_register(L, "tinker", tinker_module_methods);
  //  luaws_register_constants(L, luaws_constants);
  return 1;
}
