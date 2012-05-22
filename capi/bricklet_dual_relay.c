/* ***********************************************************
 * This file was automatically generated on 2012-05-21.      *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generator git on tinkerforge.com                   *
 *************************************************************/

#include "bricklet_dual_relay.h"

#include <string.h>

#define FUNCTION_SET_STATE 1
#define FUNCTION_GET_STATE 2


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
	bool relay1;
	bool relay2;
} ATTRIBUTE_PACKED SetState_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED GetState_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	bool relay1;
	bool relay2;
} ATTRIBUTE_PACKED GetStateReturn_;

#if defined _MSC_VER || defined __BORLANDC__
	#pragma pack(pop)
#endif
#undef ATTRIBUTE_PACKED

int dual_relay_set_state(DualRelay *dual_relay, bool relay1, bool relay2) {
	if(dual_relay->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(dual_relay);

	SetState_ ss;
	ss.stack_id = dual_relay->stack_id;
	ss.function_id = FUNCTION_SET_STATE;
	ss.length = sizeof(SetState_);
	ss.relay1 = relay1;
	ss.relay2 = relay2;

	ipcon_device_write(dual_relay, (char *)&ss, sizeof(SetState_));

	ipcon_sem_post_write(dual_relay);

	return E_OK;
}

int dual_relay_get_state(DualRelay *dual_relay, bool *ret_relay1, bool *ret_relay2) {
	if(dual_relay->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(dual_relay);

	dual_relay->answer.function_id = FUNCTION_GET_STATE;
	dual_relay->answer.length = sizeof(GetStateReturn_);
	GetState_ gs;
	gs.stack_id = dual_relay->stack_id;
	gs.function_id = FUNCTION_GET_STATE;
	gs.length = sizeof(GetState_);

	ipcon_device_write(dual_relay, (char *)&gs, sizeof(GetState_));

	if(ipcon_answer_sem_wait_timeout(dual_relay) != 0) {
		ipcon_sem_post_write(dual_relay);
		return E_TIMEOUT;
	}

	GetStateReturn_ *gsr = (GetStateReturn_ *)dual_relay->answer.buffer;
	*ret_relay1 = gsr->relay1;
	*ret_relay2 = gsr->relay2;

	ipcon_sem_post_write(dual_relay);

	return E_OK;
}

int dual_relay_get_version(DualRelay *dual_relay, char ret_name[40], uint8_t ret_firmware_version[3], uint8_t ret_binding_version[3]) {
	strncpy(ret_name, dual_relay->name, 40);

	ret_firmware_version[0] = dual_relay->firmware_version[0];
	ret_firmware_version[1] = dual_relay->firmware_version[1];
	ret_firmware_version[2] = dual_relay->firmware_version[2];

	ret_binding_version[0] = dual_relay->binding_version[0];
	ret_binding_version[1] = dual_relay->binding_version[1];
	ret_binding_version[2] = dual_relay->binding_version[2];

	return E_OK;
}

void dual_relay_register_callback(DualRelay *dual_relay, uint8_t cb, void *func) {
    dual_relay->callbacks[cb] = func;
}

void dual_relay_create(DualRelay *dual_relay, const char *uid) {
	ipcon_device_create(dual_relay, uid);

	dual_relay->expected_name = "Dual Relay Bricklet";

	dual_relay->binding_version[0] = 1;
	dual_relay->binding_version[1] = 0;
	dual_relay->binding_version[2] = 0;

}
