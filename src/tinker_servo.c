#include "brick_servo.h"

#define TINKER_SERVO_META "tinker.servo"

struct tinker_servo {
  Servo servo;
  int index;
  lua_State *L;
  int under_voltage_callback_ref;
  int button_released_callback_ref;
};

static struct tinker_servo * servo_array[] = {NULL, NULL, NULL, NULL};

#define DECL_TINKER_SERVO_ON_UNDER_VOLTAGE(X)                        \
  static void tinker_servo_on_under_voltage_##X(uint8_t button) {    \
  lua_State *L = servo_array[X]->L;                                        \
  lua_rawgeti(L, LUA_REGISTRYINDEX, servo_array[X]->under_voltage_callback_ref); \
  if(!lua_isfunction(L, -1)) {                                          \
    lua_pop(L, 1);                                                      \
    return;                                                             \
  }                                                                     \
  lua_pushnumber(L, button);                                            \
lua_call(L, 1, 0);                              \
}                                               \

DECL_TINKER_SERVO_ON_UNDER_VOLTAGE(0);
DECL_TINKER_SERVO_ON_UNDER_VOLTAGE(1);
DECL_TINKER_SERVO_ON_UNDER_VOLTAGE(2);
DECL_TINKER_SERVO_ON_UNDER_VOLTAGE(3);

void *tinker_servo_on_under_voltage_callbacks[] = {
  tinker_servo_on_under_voltage_0,
  tinker_servo_on_under_voltage_1,
  tinker_servo_on_under_voltage_2,
  tinker_servo_on_under_voltage_3
};

static int tinker_servo_under_voltage(lua_State *L) {
  struct tinker_servo *tservo = luaL_checkudata(L, 1, TINKER_SERVO_META);
  luaL_checktype(L, 2, LUA_TFUNCTION);
  tservo->under_voltage_callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
  servo_register_callback(&tservo->servo, 
                          SERVO_CALLBACK_UNDER_VOLTAGE,
                          tinker_servo_on_under_voltage_callbacks[tservo->index]);
  return 0;
}

static int tinker_servo_enable(lua_State* L) {
  struct tinker_servo *tservo = luaL_checkudata(L, 1, TINKER_SERVO_META);
  int servo_num = luaL_checkinteger(L, 2);
  servo_enable(&tservo->servo, servo_num);
  return 0;
}

static int tinker_servo_is_enabled(lua_State* L) {
  struct tinker_servo *tservo = luaL_checkudata(L, 1, TINKER_SERVO_META);
  int servo_num = luaL_checkinteger(L, 2);
  bool on;
  servo_is_enabled(&tservo->servo, servo_num, &on);
  lua_pushboolean(L, on);
  return 1;
}

static const struct luaL_Reg tinker_servo_methods [] = {
  {"under_voltage",tinker_servo_under_voltage},
  {"enable",tinker_servo_enable},
  {"is_enabled",tinker_servo_is_enabled},
  {NULL,NULL}
};


