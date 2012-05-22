/* ***********************************************************
 * This file was automatically generated on 2012-05-21.      *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generator git on tinkerforge.com                   *
 *************************************************************/

#include "bricklet_distance_ir.h"

#include <string.h>

#define FUNCTION_GET_DISTANCE 1
#define FUNCTION_GET_ANALOG_VALUE 2
#define FUNCTION_SET_SAMPLING_POINT 3
#define FUNCTION_GET_SAMPLING_POINT 4
#define FUNCTION_SET_DISTANCE_CALLBACK_PERIOD 5
#define FUNCTION_GET_DISTANCE_CALLBACK_PERIOD 6
#define FUNCTION_SET_ANALOG_VALUE_CALLBACK_PERIOD 7
#define FUNCTION_GET_ANALOG_VALUE_CALLBACK_PERIOD 8
#define FUNCTION_SET_DISTANCE_CALLBACK_THRESHOLD 9
#define FUNCTION_GET_DISTANCE_CALLBACK_THRESHOLD 10
#define FUNCTION_SET_ANALOG_VALUE_CALLBACK_THRESHOLD 11
#define FUNCTION_GET_ANALOG_VALUE_CALLBACK_THRESHOLD 12
#define FUNCTION_SET_DEBOUNCE_PERIOD 13
#define FUNCTION_GET_DEBOUNCE_PERIOD 14


typedef void (*distance_func_t)(uint16_t);

typedef void (*analog_value_func_t)(uint16_t);

typedef void (*distance_reached_func_t)(uint16_t);

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
} ATTRIBUTE_PACKED GetDistance_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint16_t distance;
} ATTRIBUTE_PACKED GetDistanceReturn_;

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
	uint8_t position;
	uint16_t distance;
} ATTRIBUTE_PACKED SetSamplingPoint_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint8_t position;
} ATTRIBUTE_PACKED GetSamplingPoint_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint16_t distance;
} ATTRIBUTE_PACKED GetSamplingPointReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint32_t period;
} ATTRIBUTE_PACKED SetDistanceCallbackPeriod_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED GetDistanceCallbackPeriod_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint32_t period;
} ATTRIBUTE_PACKED GetDistanceCallbackPeriodReturn_;

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
} ATTRIBUTE_PACKED SetDistanceCallbackThreshold_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED GetDistanceCallbackThreshold_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	char option;
	int16_t min;
	int16_t max;
} ATTRIBUTE_PACKED GetDistanceCallbackThresholdReturn_;

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
	uint16_t distance;
} ATTRIBUTE_PACKED DistanceCallback_;

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
	uint16_t distance;
} ATTRIBUTE_PACKED DistanceReachedCallback_;

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

int distance_ir_get_distance(DistanceIR *distance_ir, uint16_t *ret_distance) {
	if(distance_ir->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(distance_ir);

	distance_ir->answer.function_id = FUNCTION_GET_DISTANCE;
	distance_ir->answer.length = sizeof(GetDistanceReturn_);
	GetDistance_ gd;
	gd.stack_id = distance_ir->stack_id;
	gd.function_id = FUNCTION_GET_DISTANCE;
	gd.length = sizeof(GetDistance_);

	ipcon_device_write(distance_ir, (char *)&gd, sizeof(GetDistance_));

	if(ipcon_answer_sem_wait_timeout(distance_ir) != 0) {
		ipcon_sem_post_write(distance_ir);
		return E_TIMEOUT;
	}

	GetDistanceReturn_ *gdr = (GetDistanceReturn_ *)distance_ir->answer.buffer;
	*ret_distance = gdr->distance;

	ipcon_sem_post_write(distance_ir);

	return E_OK;
}

int distance_ir_get_analog_value(DistanceIR *distance_ir, uint16_t *ret_value) {
	if(distance_ir->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(distance_ir);

	distance_ir->answer.function_id = FUNCTION_GET_ANALOG_VALUE;
	distance_ir->answer.length = sizeof(GetAnalogValueReturn_);
	GetAnalogValue_ gav;
	gav.stack_id = distance_ir->stack_id;
	gav.function_id = FUNCTION_GET_ANALOG_VALUE;
	gav.length = sizeof(GetAnalogValue_);

	ipcon_device_write(distance_ir, (char *)&gav, sizeof(GetAnalogValue_));

	if(ipcon_answer_sem_wait_timeout(distance_ir) != 0) {
		ipcon_sem_post_write(distance_ir);
		return E_TIMEOUT;
	}

	GetAnalogValueReturn_ *gavr = (GetAnalogValueReturn_ *)distance_ir->answer.buffer;
	*ret_value = gavr->value;

	ipcon_sem_post_write(distance_ir);

	return E_OK;
}

int distance_ir_set_sampling_point(DistanceIR *distance_ir, uint8_t position, uint16_t distance) {
	if(distance_ir->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(distance_ir);

	SetSamplingPoint_ ssp;
	ssp.stack_id = distance_ir->stack_id;
	ssp.function_id = FUNCTION_SET_SAMPLING_POINT;
	ssp.length = sizeof(SetSamplingPoint_);
	ssp.position = position;
	ssp.distance = distance;

	ipcon_device_write(distance_ir, (char *)&ssp, sizeof(SetSamplingPoint_));

	ipcon_sem_post_write(distance_ir);

	return E_OK;
}

int distance_ir_get_sampling_point(DistanceIR *distance_ir, uint8_t position, uint16_t *ret_distance) {
	if(distance_ir->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(distance_ir);

	distance_ir->answer.function_id = FUNCTION_GET_SAMPLING_POINT;
	distance_ir->answer.length = sizeof(GetSamplingPointReturn_);
	GetSamplingPoint_ gsp;
	gsp.stack_id = distance_ir->stack_id;
	gsp.function_id = FUNCTION_GET_SAMPLING_POINT;
	gsp.length = sizeof(GetSamplingPoint_);
	gsp.position = position;

	ipcon_device_write(distance_ir, (char *)&gsp, sizeof(GetSamplingPoint_));

	if(ipcon_answer_sem_wait_timeout(distance_ir) != 0) {
		ipcon_sem_post_write(distance_ir);
		return E_TIMEOUT;
	}

	GetSamplingPointReturn_ *gspr = (GetSamplingPointReturn_ *)distance_ir->answer.buffer;
	*ret_distance = gspr->distance;

	ipcon_sem_post_write(distance_ir);

	return E_OK;
}

int distance_ir_set_distance_callback_period(DistanceIR *distance_ir, uint32_t period) {
	if(distance_ir->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(distance_ir);

	SetDistanceCallbackPeriod_ sdcp;
	sdcp.stack_id = distance_ir->stack_id;
	sdcp.function_id = FUNCTION_SET_DISTANCE_CALLBACK_PERIOD;
	sdcp.length = sizeof(SetDistanceCallbackPeriod_);
	sdcp.period = period;

	ipcon_device_write(distance_ir, (char *)&sdcp, sizeof(SetDistanceCallbackPeriod_));

	ipcon_sem_post_write(distance_ir);

	return E_OK;
}

int distance_ir_get_distance_callback_period(DistanceIR *distance_ir, uint32_t *ret_period) {
	if(distance_ir->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(distance_ir);

	distance_ir->answer.function_id = FUNCTION_GET_DISTANCE_CALLBACK_PERIOD;
	distance_ir->answer.length = sizeof(GetDistanceCallbackPeriodReturn_);
	GetDistanceCallbackPeriod_ gdcp;
	gdcp.stack_id = distance_ir->stack_id;
	gdcp.function_id = FUNCTION_GET_DISTANCE_CALLBACK_PERIOD;
	gdcp.length = sizeof(GetDistanceCallbackPeriod_);

	ipcon_device_write(distance_ir, (char *)&gdcp, sizeof(GetDistanceCallbackPeriod_));

	if(ipcon_answer_sem_wait_timeout(distance_ir) != 0) {
		ipcon_sem_post_write(distance_ir);
		return E_TIMEOUT;
	}

	GetDistanceCallbackPeriodReturn_ *gdcpr = (GetDistanceCallbackPeriodReturn_ *)distance_ir->answer.buffer;
	*ret_period = gdcpr->period;

	ipcon_sem_post_write(distance_ir);

	return E_OK;
}

int distance_ir_set_analog_value_callback_period(DistanceIR *distance_ir, uint32_t period) {
	if(distance_ir->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(distance_ir);

	SetAnalogValueCallbackPeriod_ savcp;
	savcp.stack_id = distance_ir->stack_id;
	savcp.function_id = FUNCTION_SET_ANALOG_VALUE_CALLBACK_PERIOD;
	savcp.length = sizeof(SetAnalogValueCallbackPeriod_);
	savcp.period = period;

	ipcon_device_write(distance_ir, (char *)&savcp, sizeof(SetAnalogValueCallbackPeriod_));

	ipcon_sem_post_write(distance_ir);

	return E_OK;
}

int distance_ir_get_analog_value_callback_period(DistanceIR *distance_ir, uint32_t *ret_period) {
	if(distance_ir->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(distance_ir);

	distance_ir->answer.function_id = FUNCTION_GET_ANALOG_VALUE_CALLBACK_PERIOD;
	distance_ir->answer.length = sizeof(GetAnalogValueCallbackPeriodReturn_);
	GetAnalogValueCallbackPeriod_ gavcp;
	gavcp.stack_id = distance_ir->stack_id;
	gavcp.function_id = FUNCTION_GET_ANALOG_VALUE_CALLBACK_PERIOD;
	gavcp.length = sizeof(GetAnalogValueCallbackPeriod_);

	ipcon_device_write(distance_ir, (char *)&gavcp, sizeof(GetAnalogValueCallbackPeriod_));

	if(ipcon_answer_sem_wait_timeout(distance_ir) != 0) {
		ipcon_sem_post_write(distance_ir);
		return E_TIMEOUT;
	}

	GetAnalogValueCallbackPeriodReturn_ *gavcpr = (GetAnalogValueCallbackPeriodReturn_ *)distance_ir->answer.buffer;
	*ret_period = gavcpr->period;

	ipcon_sem_post_write(distance_ir);

	return E_OK;
}

int distance_ir_set_distance_callback_threshold(DistanceIR *distance_ir, char option, int16_t min, int16_t max) {
	if(distance_ir->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(distance_ir);

	SetDistanceCallbackThreshold_ sdct;
	sdct.stack_id = distance_ir->stack_id;
	sdct.function_id = FUNCTION_SET_DISTANCE_CALLBACK_THRESHOLD;
	sdct.length = sizeof(SetDistanceCallbackThreshold_);
	sdct.option = option;
	sdct.min = min;
	sdct.max = max;

	ipcon_device_write(distance_ir, (char *)&sdct, sizeof(SetDistanceCallbackThreshold_));

	ipcon_sem_post_write(distance_ir);

	return E_OK;
}

int distance_ir_get_distance_callback_threshold(DistanceIR *distance_ir, char *ret_option, int16_t *ret_min, int16_t *ret_max) {
	if(distance_ir->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(distance_ir);

	distance_ir->answer.function_id = FUNCTION_GET_DISTANCE_CALLBACK_THRESHOLD;
	distance_ir->answer.length = sizeof(GetDistanceCallbackThresholdReturn_);
	GetDistanceCallbackThreshold_ gdct;
	gdct.stack_id = distance_ir->stack_id;
	gdct.function_id = FUNCTION_GET_DISTANCE_CALLBACK_THRESHOLD;
	gdct.length = sizeof(GetDistanceCallbackThreshold_);

	ipcon_device_write(distance_ir, (char *)&gdct, sizeof(GetDistanceCallbackThreshold_));

	if(ipcon_answer_sem_wait_timeout(distance_ir) != 0) {
		ipcon_sem_post_write(distance_ir);
		return E_TIMEOUT;
	}

	GetDistanceCallbackThresholdReturn_ *gdctr = (GetDistanceCallbackThresholdReturn_ *)distance_ir->answer.buffer;
	*ret_option = gdctr->option;
	*ret_min = gdctr->min;
	*ret_max = gdctr->max;

	ipcon_sem_post_write(distance_ir);

	return E_OK;
}

int distance_ir_set_analog_value_callback_threshold(DistanceIR *distance_ir, char option, uint16_t min, uint16_t max) {
	if(distance_ir->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(distance_ir);

	SetAnalogValueCallbackThreshold_ savct;
	savct.stack_id = distance_ir->stack_id;
	savct.function_id = FUNCTION_SET_ANALOG_VALUE_CALLBACK_THRESHOLD;
	savct.length = sizeof(SetAnalogValueCallbackThreshold_);
	savct.option = option;
	savct.min = min;
	savct.max = max;

	ipcon_device_write(distance_ir, (char *)&savct, sizeof(SetAnalogValueCallbackThreshold_));

	ipcon_sem_post_write(distance_ir);

	return E_OK;
}

int distance_ir_get_analog_value_callback_threshold(DistanceIR *distance_ir, char *ret_option, uint16_t *ret_min, uint16_t *ret_max) {
	if(distance_ir->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(distance_ir);

	distance_ir->answer.function_id = FUNCTION_GET_ANALOG_VALUE_CALLBACK_THRESHOLD;
	distance_ir->answer.length = sizeof(GetAnalogValueCallbackThresholdReturn_);
	GetAnalogValueCallbackThreshold_ gavct;
	gavct.stack_id = distance_ir->stack_id;
	gavct.function_id = FUNCTION_GET_ANALOG_VALUE_CALLBACK_THRESHOLD;
	gavct.length = sizeof(GetAnalogValueCallbackThreshold_);

	ipcon_device_write(distance_ir, (char *)&gavct, sizeof(GetAnalogValueCallbackThreshold_));

	if(ipcon_answer_sem_wait_timeout(distance_ir) != 0) {
		ipcon_sem_post_write(distance_ir);
		return E_TIMEOUT;
	}

	GetAnalogValueCallbackThresholdReturn_ *gavctr = (GetAnalogValueCallbackThresholdReturn_ *)distance_ir->answer.buffer;
	*ret_option = gavctr->option;
	*ret_min = gavctr->min;
	*ret_max = gavctr->max;

	ipcon_sem_post_write(distance_ir);

	return E_OK;
}

int distance_ir_set_debounce_period(DistanceIR *distance_ir, uint32_t debounce) {
	if(distance_ir->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(distance_ir);

	SetDebouncePeriod_ sdp;
	sdp.stack_id = distance_ir->stack_id;
	sdp.function_id = FUNCTION_SET_DEBOUNCE_PERIOD;
	sdp.length = sizeof(SetDebouncePeriod_);
	sdp.debounce = debounce;

	ipcon_device_write(distance_ir, (char *)&sdp, sizeof(SetDebouncePeriod_));

	ipcon_sem_post_write(distance_ir);

	return E_OK;
}

int distance_ir_get_debounce_period(DistanceIR *distance_ir, uint32_t *ret_debounce) {
	if(distance_ir->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(distance_ir);

	distance_ir->answer.function_id = FUNCTION_GET_DEBOUNCE_PERIOD;
	distance_ir->answer.length = sizeof(GetDebouncePeriodReturn_);
	GetDebouncePeriod_ gdp;
	gdp.stack_id = distance_ir->stack_id;
	gdp.function_id = FUNCTION_GET_DEBOUNCE_PERIOD;
	gdp.length = sizeof(GetDebouncePeriod_);

	ipcon_device_write(distance_ir, (char *)&gdp, sizeof(GetDebouncePeriod_));

	if(ipcon_answer_sem_wait_timeout(distance_ir) != 0) {
		ipcon_sem_post_write(distance_ir);
		return E_TIMEOUT;
	}

	GetDebouncePeriodReturn_ *gdpr = (GetDebouncePeriodReturn_ *)distance_ir->answer.buffer;
	*ret_debounce = gdpr->debounce;

	ipcon_sem_post_write(distance_ir);

	return E_OK;
}

int distance_ir_get_version(DistanceIR *distance_ir, char ret_name[40], uint8_t ret_firmware_version[3], uint8_t ret_binding_version[3]) {
	strncpy(ret_name, distance_ir->name, 40);

	ret_firmware_version[0] = distance_ir->firmware_version[0];
	ret_firmware_version[1] = distance_ir->firmware_version[1];
	ret_firmware_version[2] = distance_ir->firmware_version[2];

	ret_binding_version[0] = distance_ir->binding_version[0];
	ret_binding_version[1] = distance_ir->binding_version[1];
	ret_binding_version[2] = distance_ir->binding_version[2];

	return E_OK;
}

static int distance_ir_callback_distance(DistanceIR *distance_ir, const unsigned char *buffer) {
	DistanceCallback_ *dc = (DistanceCallback_ *)buffer;
	((distance_func_t)distance_ir->callbacks[dc->function_id])(dc->distance);
	return sizeof(DistanceCallback_);
}

static int distance_ir_callback_analog_value(DistanceIR *distance_ir, const unsigned char *buffer) {
	AnalogValueCallback_ *avc = (AnalogValueCallback_ *)buffer;
	((analog_value_func_t)distance_ir->callbacks[avc->function_id])(avc->value);
	return sizeof(AnalogValueCallback_);
}

static int distance_ir_callback_distance_reached(DistanceIR *distance_ir, const unsigned char *buffer) {
	DistanceReachedCallback_ *drc = (DistanceReachedCallback_ *)buffer;
	((distance_reached_func_t)distance_ir->callbacks[drc->function_id])(drc->distance);
	return sizeof(DistanceReachedCallback_);
}

static int distance_ir_callback_analog_value_reached(DistanceIR *distance_ir, const unsigned char *buffer) {
	AnalogValueReachedCallback_ *avrc = (AnalogValueReachedCallback_ *)buffer;
	((analog_value_reached_func_t)distance_ir->callbacks[avrc->function_id])(avrc->value);
	return sizeof(AnalogValueReachedCallback_);
}

void distance_ir_register_callback(DistanceIR *distance_ir, uint8_t cb, void *func) {
    distance_ir->callbacks[cb] = func;
}

void distance_ir_create(DistanceIR *distance_ir, const char *uid) {
	ipcon_device_create(distance_ir, uid);

	distance_ir->expected_name = "Distance IR Bricklet";

	distance_ir->binding_version[0] = 1;
	distance_ir->binding_version[1] = 0;
	distance_ir->binding_version[2] = 0;

	distance_ir->device_callbacks[DISTANCE_IR_CALLBACK_DISTANCE] = distance_ir_callback_distance;
	distance_ir->device_callbacks[DISTANCE_IR_CALLBACK_ANALOG_VALUE] = distance_ir_callback_analog_value;
	distance_ir->device_callbacks[DISTANCE_IR_CALLBACK_DISTANCE_REACHED] = distance_ir_callback_distance_reached;
	distance_ir->device_callbacks[DISTANCE_IR_CALLBACK_ANALOG_VALUE_REACHED] = distance_ir_callback_analog_value_reached;
}
