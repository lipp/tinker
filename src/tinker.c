#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"

#include <string.h>
#include <assert.h>
#include <stdio.h>

#include "tinker_lcd20x4.c"
#include "tinker_ipcon.c"


static const struct luaL_Reg tinker_module_methods [] = {
  {"ipcon",tinker_ipcon},
  {NULL,NULL}
};

struct tinker_constant {
  const char *name;
  int value;
};

struct tinker_constant tinker_constants [] = {
  {NULL,0}
};

static void tinker_register_constants(lua_State *L, struct tinker_constant *constants) {
  while(constants->name) {
    lua_pushinteger(L, constants->value);
    lua_setfield(L, -2, constants->name);
    ++constants;
  }
}

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
  tinker_register_constants(L, tinker_constants);
  return 1;
}
