/* ***********************************************************
 * This file was automatically generated on 2012-05-21.      *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generator git on tinkerforge.com                   *
 *************************************************************/

#include "bricklet_analog_out.h"

#include <string.h>

#define FUNCTION_SET_VOLTAGE 1
#define FUNCTION_GET_VOLTAGE 2
#define FUNCTION_SET_MODE 3
#define FUNCTION_GET_MODE 4


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
	uint16_t voltage;
} ATTRIBUTE_PACKED SetVoltage_;

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
	uint8_t mode;
} ATTRIBUTE_PACKED SetMode_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED GetMode_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint8_t mode;
} ATTRIBUTE_PACKED GetModeReturn_;

#if defined _MSC_VER || defined __BORLANDC__
	#pragma pack(pop)
#endif
#undef ATTRIBUTE_PACKED

int analog_out_set_voltage(AnalogOut *analog_out, uint16_t voltage) {
	if(analog_out->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(analog_out);

	SetVoltage_ sv;
	sv.stack_id = analog_out->stack_id;
	sv.function_id = FUNCTION_SET_VOLTAGE;
	sv.length = sizeof(SetVoltage_);
	sv.voltage = voltage;

	ipcon_device_write(analog_out, (char *)&sv, sizeof(SetVoltage_));

	ipcon_sem_post_write(analog_out);

	return E_OK;
}

int analog_out_get_voltage(AnalogOut *analog_out, uint16_t *ret_voltage) {
	if(analog_out->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(analog_out);

	analog_out->answer.function_id = FUNCTION_GET_VOLTAGE;
	analog_out->answer.length = sizeof(GetVoltageReturn_);
	GetVoltage_ gv;
	gv.stack_id = analog_out->stack_id;
	gv.function_id = FUNCTION_GET_VOLTAGE;
	gv.length = sizeof(GetVoltage_);

	ipcon_device_write(analog_out, (char *)&gv, sizeof(GetVoltage_));

	if(ipcon_answer_sem_wait_timeout(analog_out) != 0) {
		ipcon_sem_post_write(analog_out);
		return E_TIMEOUT;
	}

	GetVoltageReturn_ *gvr = (GetVoltageReturn_ *)analog_out->answer.buffer;
	*ret_voltage = gvr->voltage;

	ipcon_sem_post_write(analog_out);

	return E_OK;
}

int analog_out_set_mode(AnalogOut *analog_out, uint8_t mode) {
	if(analog_out->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(analog_out);

	SetMode_ sm;
	sm.stack_id = analog_out->stack_id;
	sm.function_id = FUNCTION_SET_MODE;
	sm.length = sizeof(SetMode_);
	sm.mode = mode;

	ipcon_device_write(analog_out, (char *)&sm, sizeof(SetMode_));

	ipcon_sem_post_write(analog_out);

	return E_OK;
}

int analog_out_get_mode(AnalogOut *analog_out, uint8_t *ret_mode) {
	if(analog_out->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(analog_out);

	analog_out->answer.function_id = FUNCTION_GET_MODE;
	analog_out->answer.length = sizeof(GetModeReturn_);
	GetMode_ gm;
	gm.stack_id = analog_out->stack_id;
	gm.function_id = FUNCTION_GET_MODE;
	gm.length = sizeof(GetMode_);

	ipcon_device_write(analog_out, (char *)&gm, sizeof(GetMode_));

	if(ipcon_answer_sem_wait_timeout(analog_out) != 0) {
		ipcon_sem_post_write(analog_out);
		return E_TIMEOUT;
	}

	GetModeReturn_ *gmr = (GetModeReturn_ *)analog_out->answer.buffer;
	*ret_mode = gmr->mode;

	ipcon_sem_post_write(analog_out);

	return E_OK;
}

int analog_out_get_version(AnalogOut *analog_out, char ret_name[40], uint8_t ret_firmware_version[3], uint8_t ret_binding_version[3]) {
	strncpy(ret_name, analog_out->name, 40);

	ret_firmware_version[0] = analog_out->firmware_version[0];
	ret_firmware_version[1] = analog_out->firmware_version[1];
	ret_firmware_version[2] = analog_out->firmware_version[2];

	ret_binding_version[0] = analog_out->binding_version[0];
	ret_binding_version[1] = analog_out->binding_version[1];
	ret_binding_version[2] = analog_out->binding_version[2];

	return E_OK;
}

void analog_out_register_callback(AnalogOut *analog_out, uint8_t cb, void *func) {
    analog_out->callbacks[cb] = func;
}

void analog_out_create(AnalogOut *analog_out, const char *uid) {
	ipcon_device_create(analog_out, uid);

	analog_out->expected_name = "Analog Out Bricklet";

	analog_out->binding_version[0] = 1;
	analog_out->binding_version[1] = 0;
	analog_out->binding_version[2] = 0;

}
