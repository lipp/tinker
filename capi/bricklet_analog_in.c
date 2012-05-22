/* ***********************************************************
 * This file was automatically generated on 2012-05-21.      *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generator git on tinkerforge.com                   *
 *************************************************************/

#include "bricklet_analog_in.h"

#include <string.h>

#define FUNCTION_GET_VOLTAGE 1
#define FUNCTION_GET_ANALOG_VALUE 2
#define FUNCTION_SET_VOLTAGE_CALLBACK_PERIOD 3
#define FUNCTION_GET_VOLTAGE_CALLBACK_PERIOD 4
#define FUNCTION_SET_ANALOG_VALUE_CALLBACK_PERIOD 5
#define FUNCTION_GET_ANALOG_VALUE_CALLBACK_PERIOD 6
#define FUNCTION_SET_VOLTAGE_CALLBACK_THRESHOLD 7
#define FUNCTION_GET_VOLTAGE_CALLBACK_THRESHOLD 8
#define FUNCTION_SET_ANALOG_VALUE_CALLBACK_THRESHOLD 9
#define FUNCTION_GET_ANALOG_VALUE_CALLBACK_THRESHOLD 10
#define FUNCTION_SET_DEBOUNCE_PERIOD 11
#define FUNCTION_GET_DEBOUNCE_PERIOD 12


typedef void (*voltage_func_t)(uint16_t);

typedef void (*analog_value_func_t)(uint16_t);

typedef void (*voltage_reached_func_t)(uint16_t);

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
} ATTRIBUTE_PACKED GetVoltage_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint16_t voltage;
} ATTRIBUTE_PACKED GetVoltageReturn_;

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
} ATTRIBUTE_PACKED SetVoltageCallbackPeriod_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED GetVoltageCallbackPeriod_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint32_t period;
} ATTRIBUTE_PACKED GetVoltageCallbackPeriodReturn_;

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
} ATTRIBUTE_PACKED SetVoltageCallbackThreshold_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED GetVoltageCallbackThreshold_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	char option;
	int16_t min;
	int16_t max;
} ATTRIBUTE_PACKED GetVoltageCallbackThresholdReturn_;

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
	uint16_t voltage;
} ATTRIBUTE_PACKED VoltageCallback_;

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
	uint16_t voltage;
} ATTRIBUTE_PACKED VoltageReachedCallback_;

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

int analog_in_get_voltage(AnalogIn *analog_in, uint16_t *ret_voltage) {
	if(analog_in->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(analog_in);

	analog_in->answer.function_id = FUNCTION_GET_VOLTAGE;
	analog_in->answer.length = sizeof(GetVoltageReturn_);
	GetVoltage_ gv;
	gv.stack_id = analog_in->stack_id;
	gv.function_id = FUNCTION_GET_VOLTAGE;
	gv.length = sizeof(GetVoltage_);

	ipcon_device_write(analog_in, (char *)&gv, sizeof(GetVoltage_));

	if(ipcon_answer_sem_wait_timeout(analog_in) != 0) {
		ipcon_sem_post_write(analog_in);
		return E_TIMEOUT;
	}

	GetVoltageReturn_ *gvr = (GetVoltageReturn_ *)analog_in->answer.buffer;
	*ret_voltage = gvr->voltage;

	ipcon_sem_post_write(analog_in);

	return E_OK;
}

int analog_in_get_analog_value(AnalogIn *analog_in, uint16_t *ret_value) {
	if(analog_in->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(analog_in);

	analog_in->answer.function_id = FUNCTION_GET_ANALOG_VALUE;
	analog_in->answer.length = sizeof(GetAnalogValueReturn_);
	GetAnalogValue_ gav;
	gav.stack_id = analog_in->stack_id;
	gav.function_id = FUNCTION_GET_ANALOG_VALUE;
	gav.length = sizeof(GetAnalogValue_);

	ipcon_device_write(analog_in, (char *)&gav, sizeof(GetAnalogValue_));

	if(ipcon_answer_sem_wait_timeout(analog_in) != 0) {
		ipcon_sem_post_write(analog_in);
		return E_TIMEOUT;
	}

	GetAnalogValueReturn_ *gavr = (GetAnalogValueReturn_ *)analog_in->answer.buffer;
	*ret_value = gavr->value;

	ipcon_sem_post_write(analog_in);

	return E_OK;
}

int analog_in_set_voltage_callback_period(AnalogIn *analog_in, uint32_t period) {
	if(analog_in->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(analog_in);

	SetVoltageCallbackPeriod_ svcp;
	svcp.stack_id = analog_in->stack_id;
	svcp.function_id = FUNCTION_SET_VOLTAGE_CALLBACK_PERIOD;
	svcp.length = sizeof(SetVoltageCallbackPeriod_);
	svcp.period = period;

	ipcon_device_write(analog_in, (char *)&svcp, sizeof(SetVoltageCallbackPeriod_));

	ipcon_sem_post_write(analog_in);

	return E_OK;
}

int analog_in_get_voltage_callback_period(AnalogIn *analog_in, uint32_t *ret_period) {
	if(analog_in->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(analog_in);

	analog_in->answer.function_id = FUNCTION_GET_VOLTAGE_CALLBACK_PERIOD;
	analog_in->answer.length = sizeof(GetVoltageCallbackPeriodReturn_);
	GetVoltageCallbackPeriod_ gvcp;
	gvcp.stack_id = analog_in->stack_id;
	gvcp.function_id = FUNCTION_GET_VOLTAGE_CALLBACK_PERIOD;
	gvcp.length = sizeof(GetVoltageCallbackPeriod_);

	ipcon_device_write(analog_in, (char *)&gvcp, sizeof(GetVoltageCallbackPeriod_));

	if(ipcon_answer_sem_wait_timeout(analog_in) != 0) {
		ipcon_sem_post_write(analog_in);
		return E_TIMEOUT;
	}

	GetVoltageCallbackPeriodReturn_ *gvcpr = (GetVoltageCallbackPeriodReturn_ *)analog_in->answer.buffer;
	*ret_period = gvcpr->period;

	ipcon_sem_post_write(analog_in);

	return E_OK;
}

int analog_in_set_analog_value_callback_period(AnalogIn *analog_in, uint32_t period) {
	if(analog_in->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(analog_in);

	SetAnalogValueCallbackPeriod_ savcp;
	savcp.stack_id = analog_in->stack_id;
	savcp.function_id = FUNCTION_SET_ANALOG_VALUE_CALLBACK_PERIOD;
	savcp.length = sizeof(SetAnalogValueCallbackPeriod_);
	savcp.period = period;

	ipcon_device_write(analog_in, (char *)&savcp, sizeof(SetAnalogValueCallbackPeriod_));

	ipcon_sem_post_write(analog_in);

	return E_OK;
}

int analog_in_get_analog_value_callback_period(AnalogIn *analog_in, uint32_t *ret_period) {
	if(analog_in->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(analog_in);

	analog_in->answer.function_id = FUNCTION_GET_ANALOG_VALUE_CALLBACK_PERIOD;
	analog_in->answer.length = sizeof(GetAnalogValueCallbackPeriodReturn_);
	GetAnalogValueCallbackPeriod_ gavcp;
	gavcp.stack_id = analog_in->stack_id;
	gavcp.function_id = FUNCTION_GET_ANALOG_VALUE_CALLBACK_PERIOD;
	gavcp.length = sizeof(GetAnalogValueCallbackPeriod_);

	ipcon_device_write(analog_in, (char *)&gavcp, sizeof(GetAnalogValueCallbackPeriod_));

	if(ipcon_answer_sem_wait_timeout(analog_in) != 0) {
		ipcon_sem_post_write(analog_in);
		return E_TIMEOUT;
	}

	GetAnalogValueCallbackPeriodReturn_ *gavcpr = (GetAnalogValueCallbackPeriodReturn_ *)analog_in->answer.buffer;
	*ret_period = gavcpr->period;

	ipcon_sem_post_write(analog_in);

	return E_OK;
}

int analog_in_set_voltage_callback_threshold(AnalogIn *analog_in, char option, int16_t min, int16_t max) {
	if(analog_in->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(analog_in);

	SetVoltageCallbackThreshold_ svct;
	svct.stack_id = analog_in->stack_id;
	svct.function_id = FUNCTION_SET_VOLTAGE_CALLBACK_THRESHOLD;
	svct.length = sizeof(SetVoltageCallbackThreshold_);
	svct.option = option;
	svct.min = min;
	svct.max = max;

	ipcon_device_write(analog_in, (char *)&svct, sizeof(SetVoltageCallbackThreshold_));

	ipcon_sem_post_write(analog_in);

	return E_OK;
}

int analog_in_get_voltage_callback_threshold(AnalogIn *analog_in, char *ret_option, int16_t *ret_min, int16_t *ret_max) {
	if(analog_in->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(analog_in);

	analog_in->answer.function_id = FUNCTION_GET_VOLTAGE_CALLBACK_THRESHOLD;
	analog_in->answer.length = sizeof(GetVoltageCallbackThresholdReturn_);
	GetVoltageCallbackThreshold_ gvct;
	gvct.stack_id = analog_in->stack_id;
	gvct.function_id = FUNCTION_GET_VOLTAGE_CALLBACK_THRESHOLD;
	gvct.length = sizeof(GetVoltageCallbackThreshold_);

	ipcon_device_write(analog_in, (char *)&gvct, sizeof(GetVoltageCallbackThreshold_));

	if(ipcon_answer_sem_wait_timeout(analog_in) != 0) {
		ipcon_sem_post_write(analog_in);
		return E_TIMEOUT;
	}

	GetVoltageCallbackThresholdReturn_ *gvctr = (GetVoltageCallbackThresholdReturn_ *)analog_in->answer.buffer;
	*ret_option = gvctr->option;
	*ret_min = gvctr->min;
	*ret_max = gvctr->max;

	ipcon_sem_post_write(analog_in);

	return E_OK;
}

int analog_in_set_analog_value_callback_threshold(AnalogIn *analog_in, char option, uint16_t min, uint16_t max) {
	if(analog_in->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(analog_in);

	SetAnalogValueCallbackThreshold_ savct;
	savct.stack_id = analog_in->stack_id;
	savct.function_id = FUNCTION_SET_ANALOG_VALUE_CALLBACK_THRESHOLD;
	savct.length = sizeof(SetAnalogValueCallbackThreshold_);
	savct.option = option;
	savct.min = min;
	savct.max = max;

	ipcon_device_write(analog_in, (char *)&savct, sizeof(SetAnalogValueCallbackThreshold_));

	ipcon_sem_post_write(analog_in);

	return E_OK;
}

int analog_in_get_analog_value_callback_threshold(AnalogIn *analog_in, char *ret_option, uint16_t *ret_min, uint16_t *ret_max) {
	if(analog_in->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(analog_in);

	analog_in->answer.function_id = FUNCTION_GET_ANALOG_VALUE_CALLBACK_THRESHOLD;
	analog_in->answer.length = sizeof(GetAnalogValueCallbackThresholdReturn_);
	GetAnalogValueCallbackThreshold_ gavct;
	gavct.stack_id = analog_in->stack_id;
	gavct.function_id = FUNCTION_GET_ANALOG_VALUE_CALLBACK_THRESHOLD;
	gavct.length = sizeof(GetAnalogValueCallbackThreshold_);

	ipcon_device_write(analog_in, (char *)&gavct, sizeof(GetAnalogValueCallbackThreshold_));

	if(ipcon_answer_sem_wait_timeout(analog_in) != 0) {
		ipcon_sem_post_write(analog_in);
		return E_TIMEOUT;
	}

	GetAnalogValueCallbackThresholdReturn_ *gavctr = (GetAnalogValueCallbackThresholdReturn_ *)analog_in->answer.buffer;
	*ret_option = gavctr->option;
	*ret_min = gavctr->min;
	*ret_max = gavctr->max;

	ipcon_sem_post_write(analog_in);

	return E_OK;
}

int analog_in_set_debounce_period(AnalogIn *analog_in, uint32_t debounce) {
	if(analog_in->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(analog_in);

	SetDebouncePeriod_ sdp;
	sdp.stack_id = analog_in->stack_id;
	sdp.function_id = FUNCTION_SET_DEBOUNCE_PERIOD;
	sdp.length = sizeof(SetDebouncePeriod_);
	sdp.debounce = debounce;

	ipcon_device_write(analog_in, (char *)&sdp, sizeof(SetDebouncePeriod_));

	ipcon_sem_post_write(analog_in);

	return E_OK;
}

int analog_in_get_debounce_period(AnalogIn *analog_in, uint32_t *ret_debounce) {
	if(analog_in->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(analog_in);

	analog_in->answer.function_id = FUNCTION_GET_DEBOUNCE_PERIOD;
	analog_in->answer.length = sizeof(GetDebouncePeriodReturn_);
	GetDebouncePeriod_ gdp;
	gdp.stack_id = analog_in->stack_id;
	gdp.function_id = FUNCTION_GET_DEBOUNCE_PERIOD;
	gdp.length = sizeof(GetDebouncePeriod_);

	ipcon_device_write(analog_in, (char *)&gdp, sizeof(GetDebouncePeriod_));

	if(ipcon_answer_sem_wait_timeout(analog_in) != 0) {
		ipcon_sem_post_write(analog_in);
		return E_TIMEOUT;
	}

	GetDebouncePeriodReturn_ *gdpr = (GetDebouncePeriodReturn_ *)analog_in->answer.buffer;
	*ret_debounce = gdpr->debounce;

	ipcon_sem_post_write(analog_in);

	return E_OK;
}

int analog_in_get_version(AnalogIn *analog_in, char ret_name[40], uint8_t ret_firmware_version[3], uint8_t ret_binding_version[3]) {
	strncpy(ret_name, analog_in->name, 40);

	ret_firmware_version[0] = analog_in->firmware_version[0];
	ret_firmware_version[1] = analog_in->firmware_version[1];
	ret_firmware_version[2] = analog_in->firmware_version[2];

	ret_binding_version[0] = analog_in->binding_version[0];
	ret_binding_version[1] = analog_in->binding_version[1];
	ret_binding_version[2] = analog_in->binding_version[2];

	return E_OK;
}

static int analog_in_callback_voltage(AnalogIn *analog_in, const unsigned char *buffer) {
	VoltageCallback_ *vc = (VoltageCallback_ *)buffer;
	((voltage_func_t)analog_in->callbacks[vc->function_id])(vc->voltage);
	return sizeof(VoltageCallback_);
}

static int analog_in_callback_analog_value(AnalogIn *analog_in, const unsigned char *buffer) {
	AnalogValueCallback_ *avc = (AnalogValueCallback_ *)buffer;
	((analog_value_func_t)analog_in->callbacks[avc->function_id])(avc->value);
	return sizeof(AnalogValueCallback_);
}

static int analog_in_callback_voltage_reached(AnalogIn *analog_in, const unsigned char *buffer) {
	VoltageReachedCallback_ *vrc = (VoltageReachedCallback_ *)buffer;
	((voltage_reached_func_t)analog_in->callbacks[vrc->function_id])(vrc->voltage);
	return sizeof(VoltageReachedCallback_);
}

static int analog_in_callback_analog_value_reached(AnalogIn *analog_in, const unsigned char *buffer) {
	AnalogValueReachedCallback_ *avrc = (AnalogValueReachedCallback_ *)buffer;
	((analog_value_reached_func_t)analog_in->callbacks[avrc->function_id])(avrc->value);
	return sizeof(AnalogValueReachedCallback_);
}

void analog_in_register_callback(AnalogIn *analog_in, uint8_t cb, void *func) {
    analog_in->callbacks[cb] = func;
}

void analog_in_create(AnalogIn *analog_in, const char *uid) {
	ipcon_device_create(analog_in, uid);

	analog_in->expected_name = "Analog In Bricklet";

	analog_in->binding_version[0] = 1;
	analog_in->binding_version[1] = 0;
	analog_in->binding_version[2] = 0;

	analog_in->device_callbacks[ANALOG_IN_CALLBACK_VOLTAGE] = analog_in_callback_voltage;
	analog_in->device_callbacks[ANALOG_IN_CALLBACK_ANALOG_VALUE] = analog_in_callback_analog_value;
	analog_in->device_callbacks[ANALOG_IN_CALLBACK_VOLTAGE_REACHED] = analog_in_callback_voltage_reached;
	analog_in->device_callbacks[ANALOG_IN_CALLBACK_ANALOG_VALUE_REACHED] = analog_in_callback_analog_value_reached;
}
