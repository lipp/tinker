/* ***********************************************************
 * This file was automatically generated on 2012-05-21.      *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generator git on tinkerforge.com                   *
 *************************************************************/

#include "bricklet_joystick.h"

#include <string.h>

#define FUNCTION_GET_POSITION 1
#define FUNCTION_IS_PRESSED 2
#define FUNCTION_GET_ANALOG_VALUE 3
#define FUNCTION_CALIBRATE 4
#define FUNCTION_SET_POSITION_CALLBACK_PERIOD 5
#define FUNCTION_GET_POSITION_CALLBACK_PERIOD 6
#define FUNCTION_SET_ANALOG_VALUE_CALLBACK_PERIOD 7
#define FUNCTION_GET_ANALOG_VALUE_CALLBACK_PERIOD 8
#define FUNCTION_SET_POSITION_CALLBACK_THRESHOLD 9
#define FUNCTION_GET_POSITION_CALLBACK_THRESHOLD 10
#define FUNCTION_SET_ANALOG_VALUE_CALLBACK_THRESHOLD 11
#define FUNCTION_GET_ANALOG_VALUE_CALLBACK_THRESHOLD 12
#define FUNCTION_SET_DEBOUNCE_PERIOD 13
#define FUNCTION_GET_DEBOUNCE_PERIOD 14


typedef void (*position_func_t)(int16_t, int16_t);

typedef void (*analog_value_func_t)(uint16_t, uint16_t);

typedef void (*position_reached_func_t)(int16_t, int16_t);

typedef void (*analog_value_reached_func_t)(uint16_t, uint16_t);

typedef void (*pressed_func_t)();

typedef void (*released_func_t)();

#if defined _MSC_VER || defined __BORLANDC__
	#pragma pack(push)
	#pragma pack(1)
	#define ATTRIBUTE_PACKED
#elif defined __GNUC__
	#define ATTRIBUTE_PACKED __attribute__((packed))
#else
	#error unknown compiler, do not know how to enable struct packing
#endif

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED GetPosition_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	int16_t x;
	int16_t y;
} ATTRIBUTE_PACKED GetPositionReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED IsPressed_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	bool pressed;
} ATTRIBUTE_PACKED IsPressedReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED GetAnalogValue_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint16_t x;
	uint16_t y;
} ATTRIBUTE_PACKED GetAnalogValueReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED Calibrate_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint32_t period;
} ATTRIBUTE_PACKED SetPositionCallbackPeriod_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED GetPositionCallbackPeriod_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint32_t period;
} ATTRIBUTE_PACKED GetPositionCallbackPeriodReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint32_t period;
} ATTRIBUTE_PACKED SetAnalogValueCallbackPeriod_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED GetAnalogValueCallbackPeriod_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint32_t period;
} ATTRIBUTE_PACKED GetAnalogValueCallbackPeriodReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	char option;
	int16_t min_x;
	int16_t max_x;
	int16_t min_y;
	int16_t max_y;
} ATTRIBUTE_PACKED SetPositionCallbackThreshold_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED GetPositionCallbackThreshold_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	char option;
	int16_t min_x;
	int16_t max_x;
	int16_t min_y;
	int16_t max_y;
} ATTRIBUTE_PACKED GetPositionCallbackThresholdReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	char option;
	uint16_t min_x;
	uint16_t max_x;
	uint16_t min_y;
	uint16_t max_y;
} ATTRIBUTE_PACKED SetAnalogValueCallbackThreshold_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED GetAnalogValueCallbackThreshold_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	char option;
	uint16_t min_x;
	uint16_t max_x;
	uint16_t min_y;
	uint16_t max_y;
} ATTRIBUTE_PACKED GetAnalogValueCallbackThresholdReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint32_t debounce;
} ATTRIBUTE_PACKED SetDebouncePeriod_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED GetDebouncePeriod_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint32_t debounce;
} ATTRIBUTE_PACKED GetDebouncePeriodReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	int16_t x;
	int16_t y;
} ATTRIBUTE_PACKED PositionCallback_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint16_t x;
	uint16_t y;
} ATTRIBUTE_PACKED AnalogValueCallback_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	int16_t x;
	int16_t y;
} ATTRIBUTE_PACKED PositionReachedCallback_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint16_t x;
	uint16_t y;
} ATTRIBUTE_PACKED AnalogValueReachedCallback_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED PressedCallback_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED ReleasedCallback_;

#if defined _MSC_VER || defined __BORLANDC__
	#pragma pack(pop)
#endif
#undef ATTRIBUTE_PACKED

int joystick_get_position(Joystick *joystick, int16_t *ret_x, int16_t *ret_y) {
	if(joystick->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(joystick);

	joystick->answer.function_id = FUNCTION_GET_POSITION;
	joystick->answer.length = sizeof(GetPositionReturn_);
	GetPosition_ gp;
	gp.stack_id = joystick->stack_id;
	gp.function_id = FUNCTION_GET_POSITION;
	gp.length = sizeof(GetPosition_);

	ipcon_device_write(joystick, (char *)&gp, sizeof(GetPosition_));

	if(ipcon_answer_sem_wait_timeout(joystick) != 0) {
		ipcon_sem_post_write(joystick);
		return E_TIMEOUT;
	}

	GetPositionReturn_ *gpr = (GetPositionReturn_ *)joystick->answer.buffer;
	*ret_x = gpr->x;
	*ret_y = gpr->y;

	ipcon_sem_post_write(joystick);

	return E_OK;
}

int joystick_is_pressed(Joystick *joystick, bool *ret_pressed) {
	if(joystick->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(joystick);

	joystick->answer.function_id = FUNCTION_IS_PRESSED;
	joystick->answer.length = sizeof(IsPressedReturn_);
	IsPressed_ ip;
	ip.stack_id = joystick->stack_id;
	ip.function_id = FUNCTION_IS_PRESSED;
	ip.length = sizeof(IsPressed_);

	ipcon_device_write(joystick, (char *)&ip, sizeof(IsPressed_));

	if(ipcon_answer_sem_wait_timeout(joystick) != 0) {
		ipcon_sem_post_write(joystick);
		return E_TIMEOUT;
	}

	IsPressedReturn_ *ipr = (IsPressedReturn_ *)joystick->answer.buffer;
	*ret_pressed = ipr->pressed;

	ipcon_sem_post_write(joystick);

	return E_OK;
}

int joystick_get_analog_value(Joystick *joystick, uint16_t *ret_x, uint16_t *ret_y) {
	if(joystick->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(joystick);

	joystick->answer.function_id = FUNCTION_GET_ANALOG_VALUE;
	joystick->answer.length = sizeof(GetAnalogValueReturn_);
	GetAnalogValue_ gav;
	gav.stack_id = joystick->stack_id;
	gav.function_id = FUNCTION_GET_ANALOG_VALUE;
	gav.length = sizeof(GetAnalogValue_);

	ipcon_device_write(joystick, (char *)&gav, sizeof(GetAnalogValue_));

	if(ipcon_answer_sem_wait_timeout(joystick) != 0) {
		ipcon_sem_post_write(joystick);
		return E_TIMEOUT;
	}

	GetAnalogValueReturn_ *gavr = (GetAnalogValueReturn_ *)joystick->answer.buffer;
	*ret_x = gavr->x;
	*ret_y = gavr->y;

	ipcon_sem_post_write(joystick);

	return E_OK;
}

int joystick_calibrate(Joystick *joystick) {
	if(joystick->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(joystick);

	Calibrate_ c;
	c.stack_id = joystick->stack_id;
	c.function_id = FUNCTION_CALIBRATE;
	c.length = sizeof(Calibrate_);

	ipcon_device_write(joystick, (char *)&c, sizeof(Calibrate_));

	ipcon_sem_post_write(joystick);

	return E_OK;
}

int joystick_set_position_callback_period(Joystick *joystick, uint32_t period) {
	if(joystick->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(joystick);

	SetPositionCallbackPeriod_ spcp;
	spcp.stack_id = joystick->stack_id;
	spcp.function_id = FUNCTION_SET_POSITION_CALLBACK_PERIOD;
	spcp.length = sizeof(SetPositionCallbackPeriod_);
	spcp.period = period;

	ipcon_device_write(joystick, (char *)&spcp, sizeof(SetPositionCallbackPeriod_));

	ipcon_sem_post_write(joystick);

	return E_OK;
}

int joystick_get_position_callback_period(Joystick *joystick, uint32_t *ret_period) {
	if(joystick->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(joystick);

	joystick->answer.function_id = FUNCTION_GET_POSITION_CALLBACK_PERIOD;
	joystick->answer.length = sizeof(GetPositionCallbackPeriodReturn_);
	GetPositionCallbackPeriod_ gpcp;
	gpcp.stack_id = joystick->stack_id;
	gpcp.function_id = FUNCTION_GET_POSITION_CALLBACK_PERIOD;
	gpcp.length = sizeof(GetPositionCallbackPeriod_);

	ipcon_device_write(joystick, (char *)&gpcp, sizeof(GetPositionCallbackPeriod_));

	if(ipcon_answer_sem_wait_timeout(joystick) != 0) {
		ipcon_sem_post_write(joystick);
		return E_TIMEOUT;
	}

	GetPositionCallbackPeriodReturn_ *gpcpr = (GetPositionCallbackPeriodReturn_ *)joystick->answer.buffer;
	*ret_period = gpcpr->period;

	ipcon_sem_post_write(joystick);

	return E_OK;
}

int joystick_set_analog_value_callback_period(Joystick *joystick, uint32_t period) {
	if(joystick->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(joystick);

	SetAnalogValueCallbackPeriod_ savcp;
	savcp.stack_id = joystick->stack_id;
	savcp.function_id = FUNCTION_SET_ANALOG_VALUE_CALLBACK_PERIOD;
	savcp.length = sizeof(SetAnalogValueCallbackPeriod_);
	savcp.period = period;

	ipcon_device_write(joystick, (char *)&savcp, sizeof(SetAnalogValueCallbackPeriod_));

	ipcon_sem_post_write(joystick);

	return E_OK;
}

int joystick_get_analog_value_callback_period(Joystick *joystick, uint32_t *ret_period) {
	if(joystick->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(joystick);

	joystick->answer.function_id = FUNCTION_GET_ANALOG_VALUE_CALLBACK_PERIOD;
	joystick->answer.length = sizeof(GetAnalogValueCallbackPeriodReturn_);
	GetAnalogValueCallbackPeriod_ gavcp;
	gavcp.stack_id = joystick->stack_id;
	gavcp.function_id = FUNCTION_GET_ANALOG_VALUE_CALLBACK_PERIOD;
	gavcp.length = sizeof(GetAnalogValueCallbackPeriod_);

	ipcon_device_write(joystick, (char *)&gavcp, sizeof(GetAnalogValueCallbackPeriod_));

	if(ipcon_answer_sem_wait_timeout(joystick) != 0) {
		ipcon_sem_post_write(joystick);
		return E_TIMEOUT;
	}

	GetAnalogValueCallbackPeriodReturn_ *gavcpr = (GetAnalogValueCallbackPeriodReturn_ *)joystick->answer.buffer;
	*ret_period = gavcpr->period;

	ipcon_sem_post_write(joystick);

	return E_OK;
}

int joystick_set_position_callback_threshold(Joystick *joystick, char option, int16_t min_x, int16_t max_x, int16_t min_y, int16_t max_y) {
	if(joystick->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(joystick);

	SetPositionCallbackThreshold_ spct;
	spct.stack_id = joystick->stack_id;
	spct.function_id = FUNCTION_SET_POSITION_CALLBACK_THRESHOLD;
	spct.length = sizeof(SetPositionCallbackThreshold_);
	spct.option = option;
	spct.min_x = min_x;
	spct.max_x = max_x;
	spct.min_y = min_y;
	spct.max_y = max_y;

	ipcon_device_write(joystick, (char *)&spct, sizeof(SetPositionCallbackThreshold_));

	ipcon_sem_post_write(joystick);

	return E_OK;
}

int joystick_get_position_callback_threshold(Joystick *joystick, char *ret_option, int16_t *ret_min_x, int16_t *ret_max_x, int16_t *ret_min_y, int16_t *ret_max_y) {
	if(joystick->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(joystick);

	joystick->answer.function_id = FUNCTION_GET_POSITION_CALLBACK_THRESHOLD;
	joystick->answer.length = sizeof(GetPositionCallbackThresholdReturn_);
	GetPositionCallbackThreshold_ gpct;
	gpct.stack_id = joystick->stack_id;
	gpct.function_id = FUNCTION_GET_POSITION_CALLBACK_THRESHOLD;
	gpct.length = sizeof(GetPositionCallbackThreshold_);

	ipcon_device_write(joystick, (char *)&gpct, sizeof(GetPositionCallbackThreshold_));

	if(ipcon_answer_sem_wait_timeout(joystick) != 0) {
		ipcon_sem_post_write(joystick);
		return E_TIMEOUT;
	}

	GetPositionCallbackThresholdReturn_ *gpctr = (GetPositionCallbackThresholdReturn_ *)joystick->answer.buffer;
	*ret_option = gpctr->option;
	*ret_min_x = gpctr->min_x;
	*ret_max_x = gpctr->max_x;
	*ret_min_y = gpctr->min_y;
	*ret_max_y = gpctr->max_y;

	ipcon_sem_post_write(joystick);

	return E_OK;
}

int joystick_set_analog_value_callback_threshold(Joystick *joystick, char option, uint16_t min_x, uint16_t max_x, uint16_t min_y, uint16_t max_y) {
	if(joystick->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(joystick);

	SetAnalogValueCallbackThreshold_ savct;
	savct.stack_id = joystick->stack_id;
	savct.function_id = FUNCTION_SET_ANALOG_VALUE_CALLBACK_THRESHOLD;
	savct.length = sizeof(SetAnalogValueCallbackThreshold_);
	savct.option = option;
	savct.min_x = min_x;
	savct.max_x = max_x;
	savct.min_y = min_y;
	savct.max_y = max_y;

	ipcon_device_write(joystick, (char *)&savct, sizeof(SetAnalogValueCallbackThreshold_));

	ipcon_sem_post_write(joystick);

	return E_OK;
}

int joystick_get_analog_value_callback_threshold(Joystick *joystick, char *ret_option, uint16_t *ret_min_x, uint16_t *ret_max_x, uint16_t *ret_min_y, uint16_t *ret_max_y) {
	if(joystick->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(joystick);

	joystick->answer.function_id = FUNCTION_GET_ANALOG_VALUE_CALLBACK_THRESHOLD;
	joystick->answer.length = sizeof(GetAnalogValueCallbackThresholdReturn_);
	GetAnalogValueCallbackThreshold_ gavct;
	gavct.stack_id = joystick->stack_id;
	gavct.function_id = FUNCTION_GET_ANALOG_VALUE_CALLBACK_THRESHOLD;
	gavct.length = sizeof(GetAnalogValueCallbackThreshold_);

	ipcon_device_write(joystick, (char *)&gavct, sizeof(GetAnalogValueCallbackThreshold_));

	if(ipcon_answer_sem_wait_timeout(joystick) != 0) {
		ipcon_sem_post_write(joystick);
		return E_TIMEOUT;
	}

	GetAnalogValueCallbackThresholdReturn_ *gavctr = (GetAnalogValueCallbackThresholdReturn_ *)joystick->answer.buffer;
	*ret_option = gavctr->option;
	*ret_min_x = gavctr->min_x;
	*ret_max_x = gavctr->max_x;
	*ret_min_y = gavctr->min_y;
	*ret_max_y = gavctr->max_y;

	ipcon_sem_post_write(joystick);

	return E_OK;
}

int joystick_set_debounce_period(Joystick *joystick, uint32_t debounce) {
	if(joystick->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(joystick);

	SetDebouncePeriod_ sdp;
	sdp.stack_id = joystick->stack_id;
	sdp.function_id = FUNCTION_SET_DEBOUNCE_PERIOD;
	sdp.length = sizeof(SetDebouncePeriod_);
	sdp.debounce = debounce;

	ipcon_device_write(joystick, (char *)&sdp, sizeof(SetDebouncePeriod_));

	ipcon_sem_post_write(joystick);

	return E_OK;
}

int joystick_get_debounce_period(Joystick *joystick, uint32_t *ret_debounce) {
	if(joystick->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(joystick);

	joystick->answer.function_id = FUNCTION_GET_DEBOUNCE_PERIOD;
	joystick->answer.length = sizeof(GetDebouncePeriodReturn_);
	GetDebouncePeriod_ gdp;
	gdp.stack_id = joystick->stack_id;
	gdp.function_id = FUNCTION_GET_DEBOUNCE_PERIOD;
	gdp.length = sizeof(GetDebouncePeriod_);

	ipcon_device_write(joystick, (char *)&gdp, sizeof(GetDebouncePeriod_));

	if(ipcon_answer_sem_wait_timeout(joystick) != 0) {
		ipcon_sem_post_write(joystick);
		return E_TIMEOUT;
	}

	GetDebouncePeriodReturn_ *gdpr = (GetDebouncePeriodReturn_ *)joystick->answer.buffer;
	*ret_debounce = gdpr->debounce;

	ipcon_sem_post_write(joystick);

	return E_OK;
}

int joystick_get_version(Joystick *joystick, char ret_name[40], uint8_t ret_firmware_version[3], uint8_t ret_binding_version[3]) {
	strncpy(ret_name, joystick->name, 40);

	ret_firmware_version[0] = joystick->firmware_version[0];
	ret_firmware_version[1] = joystick->firmware_version[1];
	ret_firmware_version[2] = joystick->firmware_version[2];

	ret_binding_version[0] = joystick->binding_version[0];
	ret_binding_version[1] = joystick->binding_version[1];
	ret_binding_version[2] = joystick->binding_version[2];

	return E_OK;
}

static int joystick_callback_position(Joystick *joystick, const unsigned char *buffer) {
	PositionCallback_ *pc = (PositionCallback_ *)buffer;
	((position_func_t)joystick->callbacks[pc->function_id])(pc->x, pc->y);
	return sizeof(PositionCallback_);
}

static int joystick_callback_analog_value(Joystick *joystick, const unsigned char *buffer) {
	AnalogValueCallback_ *avc = (AnalogValueCallback_ *)buffer;
	((analog_value_func_t)joystick->callbacks[avc->function_id])(avc->x, avc->y);
	return sizeof(AnalogValueCallback_);
}

static int joystick_callback_position_reached(Joystick *joystick, const unsigned char *buffer) {
	PositionReachedCallback_ *prc = (PositionReachedCallback_ *)buffer;
	((position_reached_func_t)joystick->callbacks[prc->function_id])(prc->x, prc->y);
	return sizeof(PositionReachedCallback_);
}

static int joystick_callback_analog_value_reached(Joystick *joystick, const unsigned char *buffer) {
	AnalogValueReachedCallback_ *avrc = (AnalogValueReachedCallback_ *)buffer;
	((analog_value_reached_func_t)joystick->callbacks[avrc->function_id])(avrc->x, avrc->y);
	return sizeof(AnalogValueReachedCallback_);
}

static int joystick_callback_pressed(Joystick *joystick, const unsigned char *buffer) {
	PressedCallback_ *pc = (PressedCallback_ *)buffer;
	((pressed_func_t)joystick->callbacks[pc->function_id])();
	return sizeof(PressedCallback_);
}

static int joystick_callback_released(Joystick *joystick, const unsigned char *buffer) {
	ReleasedCallback_ *rc = (ReleasedCallback_ *)buffer;
	((released_func_t)joystick->callbacks[rc->function_id])();
	return sizeof(ReleasedCallback_);
}

void joystick_register_callback(Joystick *joystick, uint8_t cb, void *func) {
    joystick->callbacks[cb] = func;
}

void joystick_create(Joystick *joystick, const char *uid) {
	ipcon_device_create(joystick, uid);

	joystick->expected_name = "Joystick Bricklet";

	joystick->binding_version[0] = 1;
	joystick->binding_version[1] = 0;
	joystick->binding_version[2] = 0;

	joystick->device_callbacks[JOYSTICK_CALLBACK_POSITION] = joystick_callback_position;
	joystick->device_callbacks[JOYSTICK_CALLBACK_ANALOG_VALUE] = joystick_callback_analog_value;
	joystick->device_callbacks[JOYSTICK_CALLBACK_POSITION_REACHED] = joystick_callback_position_reached;
	joystick->device_callbacks[JOYSTICK_CALLBACK_ANALOG_VALUE_REACHED] = joystick_callback_analog_value_reached;
	joystick->device_callbacks[JOYSTICK_CALLBACK_PRESSED] = joystick_callback_pressed;
	joystick->device_callbacks[JOYSTICK_CALLBACK_RELEASED] = joystick_callback_released;
}
