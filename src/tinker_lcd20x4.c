#include "bricklet_lcd_20x4.h"

#define TINKER_LCD20x4_META "tinker.lcd20x4"

struct tinker_lcd20x4 {
  LCD20x4 lcd;
  int index;
  lua_State *L;
  int button_pressed_callback_ref;
  int button_released_callback_ref;
};

static struct tinker_lcd20x4 * lcd20x4_array[] = {NULL, NULL, NULL, NULL};

#define DECL_TINKER_LCD20X4_ON_BUTTON_PRESSED(X)                        \
  static void tinker_lcd20x4_on_button_pressed_##X(uint8_t button) {    \
  lua_State *L = lcd20x4_array[X]->L;                                        \
  lua_rawgeti(L, LUA_REGISTRYINDEX, lcd20x4_array[X]->button_pressed_callback_ref); \
  if(!lua_isfunction(L, -1)) {                                          \
    lua_pop(L, 1);                                                      \
    return;                                                             \
  }                                                                     \
  lua_pushnumber(L, button);                                            \
lua_call(L, 1, 0);                              \
}                                               \

DECL_TINKER_LCD20X4_ON_BUTTON_PRESSED(0);
DECL_TINKER_LCD20X4_ON_BUTTON_PRESSED(1);
DECL_TINKER_LCD20X4_ON_BUTTON_PRESSED(2);
DECL_TINKER_LCD20X4_ON_BUTTON_PRESSED(3);

void *tinker_lcd20x4_on_button_pressed_callbacks[] = {
  tinker_lcd20x4_on_button_pressed_0,
  tinker_lcd20x4_on_button_pressed_1,
  tinker_lcd20x4_on_button_pressed_2,
  tinker_lcd20x4_on_button_pressed_3
};

static int tinker_lcd20x4_button_pressed(lua_State *L) {
  struct tinker_lcd20x4 *tlcd = luaL_checkudata(L, 1, TINKER_LCD20x4_META);
  luaL_checktype(L, 2, LUA_TFUNCTION);
  tlcd->button_pressed_callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
  lcd_20x4_register_callback(&tlcd->lcd, 
                             LCD_20X4_CALLBACK_BUTTON_PRESSED, 
                             tinker_lcd20x4_on_button_pressed_callbacks[tlcd->index]);
  return 0;
}

static int tinker_lcd20x4_backlight_on(lua_State* L) {
  struct tinker_lcd20x4 *tlcd = luaL_checkudata(L, 1, TINKER_LCD20x4_META);
  lcd_20x4_backlight_on(&tlcd->lcd);
  return 0;
}

static int tinker_lcd20x4_backlight_off(lua_State* L) {
  struct tinker_lcd20x4 *tlcd = luaL_checkudata(L, 1, TINKER_LCD20x4_META);
  lcd_20x4_backlight_off(&tlcd->lcd);
  return 0;
}

static int tinker_lcd20x4_clear_display(lua_State* L) {
  struct tinker_lcd20x4 *tlcd = luaL_checkudata(L, 1, TINKER_LCD20x4_META);
  lcd_20x4_clear_display(&tlcd->lcd);
  return 0;
}

static int tinker_lcd20x4_is_backlight_on(lua_State* L) {
  struct tinker_lcd20x4 *tlcd = luaL_checkudata(L, 1, TINKER_LCD20x4_META);
  bool on;
  lcd_20x4_is_backlight_on(&tlcd->lcd, &on);
  lua_pushboolean(L, on);
  return 1;
}

static int tinker_lcd20x4_write_line(lua_State* L) {
  struct tinker_lcd20x4 *tlcd = luaL_checkudata(L, 1, TINKER_LCD20x4_META);
  int line = luaL_checkinteger(L, 2);
  int position = luaL_checkinteger(L, 3);
  const char *text = luaL_checkstring(L, 4);
  lcd_20x4_write_line(&tlcd->lcd, line, position, (char *)text);
  return 0;
}

static const struct luaL_Reg tinker_lcd20x4_methods [] = {
  {"button_pressed",tinker_lcd20x4_button_pressed},
  {"backlight_on",tinker_lcd20x4_backlight_on},
  {"backlight_off",tinker_lcd20x4_backlight_off},
  {"is_backlight_on",tinker_lcd20x4_is_backlight_on},
  {"clear_display",tinker_lcd20x4_clear_display},
  {"write_line",tinker_lcd20x4_write_line},
  {NULL,NULL}
};


