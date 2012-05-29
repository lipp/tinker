#include "ip_connection.h"

#define TINKER_IPCON_META "tinker.ipcon"

struct tinker_ipcon {
  lua_State *L;
  IPConnection ipcon;
  int enumerate_callback_ref;
};

static int tinker_ipcon(lua_State *L) {
  const char* host = luaL_optstring(L, 1, "localhost");;
  int port = luaL_optint(L, 2, 4223);
  int dont_start_threads = luaL_optint(L, 3, 0);
  IPConnection *ipcon = lua_newuserdata(L, sizeof(IPConnection));

  if(ipcon_create(ipcon, host, port, dont_start_threads) < 0) {
    luaL_error(L, "ipcon_create failed");
  }

  luaL_getmetatable(L, TINKER_IPCON_META);
  lua_setmetatable(L, -2);

  return 1;
}

static int tinker_ipcon_destroy(lua_State* L) {
  IPConnection *ipcon = luaL_checkudata(L, 1, TINKER_IPCON_META);
  ipcon_destroy(ipcon);
  return 0;
}

static int tinker_ipcon_join_thread(lua_State* L) {
  IPConnection *ipcon = luaL_checkudata(L, 1, TINKER_IPCON_META);
  ipcon_join_thread(ipcon);
  return 0;
}

static int tinker_ipcon_dispatch(lua_State* L) {
  IPConnection *ipcon = luaL_checkudata(L, 1, TINKER_IPCON_META);
  ipcon_dispatch(ipcon);
  return 0;
}

static int tinker_ipcon_getfd(lua_State* L) {
  IPConnection *ipcon = luaL_checkudata(L, 1, TINKER_IPCON_META);
  lua_pushnumber(L, ipcon_get_fd(ipcon));
  return 1;
}

static int tinker_ipcon_lcd20x4(lua_State* L) {
  IPConnection *ipcon = luaL_checkudata(L, 1, TINKER_IPCON_META);
  const char* uid = luaL_checkstring(L, 2);
  int index = 0;
  while(lcd20x4_array[index] && index < sizeof(lcd20x4_array)) {
    ++index;
  }
  if(lcd20x4_array[index]) {
    luaL_error(L, "no free lcd20x4 slot");
  }
  struct tinker_lcd20x4 *tlcd = lua_newuserdata(L, sizeof(struct tinker_lcd20x4));
  lcd20x4_array[index] = tlcd;
  tlcd->index = index;
  tlcd->L = L;
  lcd_20x4_create(&tlcd->lcd, uid);
  tlcd->button_pressed_callback_ref = LUA_REFNIL;
  tlcd->button_released_callback_ref = LUA_REFNIL;
  luaL_getmetatable(L, TINKER_LCD20x4_META);
  lua_setmetatable(L, -2);
  
  if(ipcon_add_device(ipcon, &tlcd->lcd) < 0) {
    luaL_error(L, "ipcon_add_device failed");
  }
  return 1;
}

static const struct luaL_Reg tinker_ipcon_methods [] = {
  {"destroy",tinker_ipcon_destroy},
  {"__gc",tinker_ipcon_destroy},
  {"lcd20x4",tinker_ipcon_lcd20x4},
  {"join_thread",tinker_ipcon_join_thread},
  {"getfd",tinker_ipcon_getfd},
  {"dispatch",tinker_ipcon_dispatch},
  {NULL,NULL}
};
