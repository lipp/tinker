/* ***********************************************************
 * This file was automatically generated on 2012-05-21.      *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generator git on tinkerforge.com                   *
 *************************************************************/

#include "bricklet_linear_poti.h"

#include <string.h>

#define FUNCTION_GET_POSITION 1
#define FUNCTION_GET_ANALOG_VALUE 2
#define FUNCTION_SET_POSITION_CALLBACK_PERIOD 3
#define FUNCTION_GET_POSITION_CALLBACK_PERIOD 4
#define FUNCTION_SET_ANALOG_VALUE_CALLBACK_PERIOD 5
#define FUNCTION_GET_ANALOG_VALUE_CALLBACK_PERIOD 6
#define FUNCTION_SET_POSITION_CALLBACK_THRESHOLD 7
#define FUNCTION_GET_POSITION_CALLBACK_THRESHOLD 8
#define FUNCTION_SET_ANALOG_VALUE_CALLBACK_THRESHOLD 9
#define FUNCTION_GET_ANALOG_VALUE_CALLBACK_THRESHOLD 10
#define FUNCTION_SET_DEBOUNCE_PERIOD 11
#define FUNCTION_GET_DEBOUNCE_PERIOD 12


typedef void (*position_func_t)(uint16_t);

typedef void (*analog_value_func_t)(uint16_t);

typedef void (*position_reached_func_t)(uint16_t);

typedef void (*analog_value_reached_func_t)(uint16_t);

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
	uint16_t position;
} ATTRIBUTE_PACKED GetPositionReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED GetAnalogValue_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint16_t value;
} ATTRIBUTE_PACKED GetAnalogValueReturn_;

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
	int16_t min;
	int16_t max;
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
	int16_t min;
	int16_t max;
} ATTRIBUTE_PACKED GetPositionCallbackThresholdReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	char option;
	uint16_t min;
	uint16_t max;
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
	uint16_t min;
	uint16_t max;
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
	uint16_t position;
} ATTRIBUTE_PACKED PositionCallback_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint16_t value;
} ATTRIBUTE_PACKED AnalogValueCallback_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint16_t position;
} ATTRIBUTE_PACKED PositionReachedCallback_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint16_t value;
} ATTRIBUTE_PACKED AnalogValueReachedCallback_;

#if defined _MSC_VER || defined __BORLANDC__
	#pragma pack(pop)
#endif
#undef ATTRIBUTE_PACKED

int linear_poti_get_position(LinearPoti *linear_poti, uint16_t *ret_position) {
	if(linear_poti->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(linear_poti);

	linear_poti->answer.function_id = FUNCTION_GET_POSITION;
	linear_poti->answer.length = sizeof(GetPositionReturn_);
	GetPosition_ gp;
	gp.stack_id = linear_poti->stack_id;
	gp.function_id = FUNCTION_GET_POSITION;
	gp.length = sizeof(GetPosition_);

	ipcon_device_write(linear_poti, (char *)&gp, sizeof(GetPosition_));

	if(ipcon_answer_sem_wait_timeout(linear_poti) != 0) {
		ipcon_sem_post_write(linear_poti);
		return E_TIMEOUT;
	}

	GetPositionReturn_ *gpr = (GetPositionReturn_ *)linear_poti->answer.buffer;
	*ret_position = gpr->position;

	ipcon_sem_post_write(linear_poti);

	return E_OK;
}

int linear_poti_get_analog_value(LinearPoti *linear_poti, uint16_t *ret_value) {
	if(linear_poti->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(linear_poti);

	linear_poti->answer.function_id = FUNCTION_GET_ANALOG_VALUE;
	linear_poti->answer.length = sizeof(GetAnalogValueReturn_);
	GetAnalogValue_ gav;
	gav.stack_id = linear_poti->stack_id;
	gav.function_id = FUNCTION_GET_ANALOG_VALUE;
	gav.length = sizeof(GetAnalogValue_);

	ipcon_device_write(linear_poti, (char *)&gav, sizeof(GetAnalogValue_));

	if(ipcon_answer_sem_wait_timeout(linear_poti) != 0) {
		ipcon_sem_post_write(linear_poti);
		return E_TIMEOUT;
	}

	GetAnalogValueReturn_ *gavr = (GetAnalogValueReturn_ *)linear_poti->answer.buffer;
	*ret_value = gavr->value;

	ipcon_sem_post_write(linear_poti);

	return E_OK;
}

int linear_poti_set_position_callback_period(LinearPoti *linear_poti, uint32_t period) {
	if(linear_poti->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(linear_poti);

	SetPositionCallbackPeriod_ spcp;
	spcp.stack_id = linear_poti->stack_id;
	spcp.function_id = FUNCTION_SET_POSITION_CALLBACK_PERIOD;
	spcp.length = sizeof(SetPositionCallbackPeriod_);
	spcp.period = period;

	ipcon_device_write(linear_poti, (char *)&spcp, sizeof(SetPositionCallbackPeriod_));

	ipcon_sem_post_write(linear_poti);

	return E_OK;
}

int linear_poti_get_position_callback_period(LinearPoti *linear_poti, uint32_t *ret_period) {
	if(linear_poti->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(linear_poti);

	linear_poti->answer.function_id = FUNCTION_GET_POSITION_CALLBACK_PERIOD;
	linear_poti->answer.length = sizeof(GetPositionCallbackPeriodReturn_);
	GetPositionCallbackPeriod_ gpcp;
	gpcp.stack_id = linear_poti->stack_id;
	gpcp.function_id = FUNCTION_GET_POSITION_CALLBACK_PERIOD;
	gpcp.length = sizeof(GetPositionCallbackPeriod_);

	ipcon_device_write(linear_poti, (char *)&gpcp, sizeof(GetPositionCallbackPeriod_));

	if(ipcon_answer_sem_wait_timeout(linear_poti) != 0) {
		ipcon_sem_post_write(linear_poti);
		return E_TIMEOUT;
	}

	GetPositionCallbackPeriodReturn_ *gpcpr = (GetPositionCallbackPeriodReturn_ *)linear_poti->answer.buffer;
	*ret_period = gpcpr->period;

	ipcon_sem_post_write(linear_poti);

	return E_OK;
}

int linear_poti_set_analog_value_callback_period(LinearPoti *linear_poti, uint32_t period) {
	if(linear_poti->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(linear_poti);

	SetAnalogValueCallbackPeriod_ savcp;
	savcp.stack_id = linear_poti->stack_id;
	savcp.function_id = FUNCTION_SET_ANALOG_VALUE_CALLBACK_PERIOD;
	savcp.length = sizeof(SetAnalogValueCallbackPeriod_);
	savcp.period = period;

	ipcon_device_write(linear_poti, (char *)&savcp, sizeof(SetAnalogValueCallbackPeriod_));

	ipcon_sem_post_write(linear_poti);

	return E_OK;
}

int linear_poti_get_analog_value_callback_period(LinearPoti *linear_poti, uint32_t *ret_period) {
	if(linear_poti->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(linear_poti);

	linear_poti->answer.function_id = FUNCTION_GET_ANALOG_VALUE_CALLBACK_PERIOD;
	linear_poti->answer.length = sizeof(GetAnalogValueCallbackPeriodReturn_);
	GetAnalogValueCallbackPeriod_ gavcp;
	gavcp.stack_id = linear_poti->stack_id;
	gavcp.function_id = FUNCTION_GET_ANALOG_VALUE_CALLBACK_PERIOD;
	gavcp.length = sizeof(GetAnalogValueCallbackPeriod_);

	ipcon_device_write(linear_poti, (char *)&gavcp, sizeof(GetAnalogValueCallbackPeriod_));

	if(ipcon_answer_sem_wait_timeout(linear_poti) != 0) {
		ipcon_sem_post_write(linear_poti);
		return E_TIMEOUT;
	}

	GetAnalogValueCallbackPeriodReturn_ *gavcpr = (GetAnalogValueCallbackPeriodReturn_ *)linear_poti->answer.buffer;
	*ret_period = gavcpr->period;

	ipcon_sem_post_write(linear_poti);

	return E_OK;
}

int linear_poti_set_position_callback_threshold(LinearPoti *linear_poti, char option, int16_t min, int16_t max) {
	if(linear_poti->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(linear_poti);

	SetPositionCallbackThreshold_ spct;
	spct.stack_id = linear_poti->stack_id;
	spct.function_id = FUNCTION_SET_POSITION_CALLBACK_THRESHOLD;
	spct.length = sizeof(SetPositionCallbackThreshold_);
	spct.option = option;
	spct.min = min;
	spct.max = max;

	ipcon_device_write(linear_poti, (char *)&spct, sizeof(SetPositionCallbackThreshold_));

	ipcon_sem_post_write(linear_poti);

	return E_OK;
}

int linear_poti_get_position_callback_threshold(LinearPoti *linear_poti, char *ret_option, int16_t *ret_min, int16_t *ret_max) {
	if(linear_poti->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(linear_poti);

	linear_poti->answer.function_id = FUNCTION_GET_POSITION_CALLBACK_THRESHOLD;
	linear_poti->answer.length = sizeof(GetPositionCallbackThresholdReturn_);
	GetPositionCallbackThreshold_ gpct;
	gpct.stack_id = linear_poti->stack_id;
	gpct.function_id = FUNCTION_GET_POSITION_CALLBACK_THRESHOLD;
	gpct.length = sizeof(GetPositionCallbackThreshold_);

	ipcon_device_write(linear_poti, (char *)&gpct, sizeof(GetPositionCallbackThreshold_));

	if(ipcon_answer_sem_wait_timeout(linear_poti) != 0) {
		ipcon_sem_post_write(linear_poti);
		return E_TIMEOUT;
	}

	GetPositionCallbackThresholdReturn_ *gpctr = (GetPositionCallbackThresholdReturn_ *)linear_poti->answer.buffer;
	*ret_option = gpctr->option;
	*ret_min = gpctr->min;
	*ret_max = gpctr->max;

	ipcon_sem_post_write(linear_poti);

	return E_OK;
}

int linear_poti_set_analog_value_callback_threshold(LinearPoti *linear_poti, char option, uint16_t min, uint16_t max) {
	if(linear_poti->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(linear_poti);

	SetAnalogValueCallbackThreshold_ savct;
	savct.stack_id = linear_poti->stack_id;
	savct.function_id = FUNCTION_SET_ANALOG_VALUE_CALLBACK_THRESHOLD;
	savct.length = sizeof(SetAnalogValueCallbackThreshold_);
	savct.option = option;
	savct.min = min;
	savct.max = max;

	ipcon_device_write(linear_poti, (char *)&savct, sizeof(SetAnalogValueCallbackThreshold_));

	ipcon_sem_post_write(linear_poti);

	return E_OK;
}

int linear_poti_get_analog_value_callback_threshold(LinearPoti *linear_poti, char *ret_option, uint16_t *ret_min, uint16_t *ret_max) {
	if(linear_poti->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(linear_poti);

	linear_poti->answer.function_id = FUNCTION_GET_ANALOG_VALUE_CALLBACK_THRESHOLD;
	linear_poti->answer.length = sizeof(GetAnalogValueCallbackThresholdReturn_);
	GetAnalogValueCallbackThreshold_ gavct;
	gavct.stack_id = linear_poti->stack_id;
	gavct.function_id = FUNCTION_GET_ANALOG_VALUE_CALLBACK_THRESHOLD;
	gavct.length = sizeof(GetAnalogValueCallbackThreshold_);

	ipcon_device_write(linear_poti, (char *)&gavct, sizeof(GetAnalogValueCallbackThreshold_));

	if(ipcon_answer_sem_wait_timeout(linear_poti) != 0) {
		ipcon_sem_post_write(linear_poti);
		return E_TIMEOUT;
	}

	GetAnalogValueCallbackThresholdReturn_ *gavctr = (GetAnalogValueCallbackThresholdReturn_ *)linear_poti->answer.buffer;
	*ret_option = gavctr->option;
	*ret_min = gavctr->min;
	*ret_max = gavctr->max;

	ipcon_sem_post_write(linear_poti);

	return E_OK;
}

int linear_poti_set_debounce_period(LinearPoti *linear_poti, uint32_t debounce) {
	if(linear_poti->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(linear_poti);

	SetDebouncePeriod_ sdp;
	sdp.stack_id = linear_poti->stack_id;
	sdp.function_id = FUNCTION_SET_DEBOUNCE_PERIOD;
	sdp.length = sizeof(SetDebouncePeriod_);
	sdp.debounce = debounce;

	ipcon_device_write(linear_poti, (char *)&sdp, sizeof(SetDebouncePeriod_));

	ipcon_sem_post_write(linear_poti);

	return E_OK;
}

int linear_poti_get_debounce_period(LinearPoti *linear_poti, uint32_t *ret_debounce) {
	if(linear_poti->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(linear_poti);

	linear_poti->answer.function_id = FUNCTION_GET_DEBOUNCE_PERIOD;
	linear_poti->answer.length = sizeof(GetDebouncePeriodReturn_);
	GetDebouncePeriod_ gdp;
	gdp.stack_id = linear_poti->stack_id;
	gdp.function_id = FUNCTION_GET_DEBOUNCE_PERIOD;
	gdp.length = sizeof(GetDebouncePeriod_);

	ipcon_device_write(linear_poti, (char *)&gdp, sizeof(GetDebouncePeriod_));

	if(ipcon_answer_sem_wait_timeout(linear_poti) != 0) {
		ipcon_sem_post_write(linear_poti);
		return E_TIMEOUT;
	}

	GetDebouncePeriodReturn_ *gdpr = (GetDebouncePeriodReturn_ *)linear_poti->answer.buffer;
	*ret_debounce = gdpr->debounce;

	ipcon_sem_post_write(linear_poti);

	return E_OK;
}

int linear_poti_get_version(LinearPoti *linear_poti, char ret_name[40], uint8_t ret_firmware_version[3], uint8_t ret_binding_version[3]) {
	strncpy(ret_name, linear_poti->name, 40);

	ret_firmware_version[0] = linear_poti->firmware_version[0];
	ret_firmware_version[1] = linear_poti->firmware_version[1];
	ret_firmware_version[2] = linear_poti->firmware_version[2];

	ret_binding_version[0] = linear_poti->binding_version[0];
	ret_binding_version[1] = linear_poti->binding_version[1];
	ret_binding_version[2] = linear_poti->binding_version[2];

	return E_OK;
}

static int linear_poti_callback_position(LinearPoti *linear_poti, const unsigned char *buffer) {
	PositionCallback_ *pc = (PositionCallback_ *)buffer;
	((position_func_t)linear_poti->callbacks[pc->function_id])(pc->position);
	return sizeof(PositionCallback_);
}

static int linear_poti_callback_analog_value(LinearPoti *linear_poti, const unsigned char *buffer) {
	AnalogValueCallback_ *avc = (AnalogValueCallback_ *)buffer;
	((analog_value_func_t)linear_poti->callbacks[avc->function_id])(avc->value);
	return sizeof(AnalogValueCallback_);
}

static int linear_poti_callback_position_reached(LinearPoti *linear_poti, const unsigned char *buffer) {
	PositionReachedCallback_ *prc = (PositionReachedCallback_ *)buffer;
	((position_reached_func_t)linear_poti->callbacks[prc->function_id])(prc->position);
	return sizeof(PositionReachedCallback_);
}

static int linear_poti_callback_analog_value_reached(LinearPoti *linear_poti, const unsigned char *buffer) {
	AnalogValueReachedCallback_ *avrc = (AnalogValueReachedCallback_ *)buffer;
	((analog_value_reached_func_t)linear_poti->callbacks[avrc->function_id])(avrc->value);
	return sizeof(AnalogValueReachedCallback_);
}

void linear_poti_register_callback(LinearPoti *linear_poti, uint8_t cb, void *func) {
    linear_poti->callbacks[cb] = func;
}

void linear_poti_create(LinearPoti *linear_poti, const char *uid) {
	ipcon_device_create(linear_poti, uid);

	linear_poti->expected_name = "Linear Poti Bricklet";

	linear_poti->binding_version[0] = 1;
	linear_poti->binding_version[1] = 0;
	linear_poti->binding_version[2] = 0;

	linear_poti->device_callbacks[LINEAR_POTI_CALLBACK_POSITION] = linear_poti_callback_position;
	linear_poti->device_callbacks[LINEAR_POTI_CALLBACK_ANALOG_VALUE] = linear_poti_callback_analog_value;
	linear_poti->device_callbacks[LINEAR_POTI_CALLBACK_POSITION_REACHED] = linear_poti_callback_position_reached;
	linear_poti->device_callbacks[LINEAR_POTI_CALLBACK_ANALOG_VALUE_REACHED] = linear_poti_callback_analog_value_reached;
}
