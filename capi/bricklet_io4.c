/* ***********************************************************
 * This file was automatically generated on 2012-05-21.      *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generator git on tinkerforge.com                   *
 *************************************************************/

#include "bricklet_io4.h"

#include <string.h>

#define FUNCTION_SET_VALUE 1
#define FUNCTION_GET_VALUE 2
#define FUNCTION_SET_CONFIGURATION 3
#define FUNCTION_GET_CONFIGURATION 4
#define FUNCTION_SET_DEBOUNCE_PERIOD 5
#define FUNCTION_GET_DEBOUNCE_PERIOD 6
#define FUNCTION_SET_INTERRUPT 7
#define FUNCTION_GET_INTERRUPT 8


typedef void (*interrupt_func_t)(uint8_t, uint8_t);

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
	uint8_t value_mask;
} ATTRIBUTE_PACKED SetValue_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED GetValue_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint8_t value_mask;
} ATTRIBUTE_PACKED GetValueReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint8_t pin_mask;
	char direction;
	bool value;
} ATTRIBUTE_PACKED SetConfiguration_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED GetConfiguration_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint8_t direction_mask;
	uint8_t value_mask;
} ATTRIBUTE_PACKED GetConfigurationReturn_;

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
	uint8_t interrupt_mask;
} ATTRIBUTE_PACKED SetInterrupt_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED GetInterrupt_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint8_t interrupt_mask;
} ATTRIBUTE_PACKED GetInterruptReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint8_t interrupt_mask;
	uint8_t value_mask;
} ATTRIBUTE_PACKED InterruptCallback_;

#if defined _MSC_VER || defined __BORLANDC__
	#pragma pack(pop)
#endif
#undef ATTRIBUTE_PACKED

int io4_set_value(IO4 *io4, uint8_t value_mask) {
	if(io4->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(io4);

	SetValue_ sv;
	sv.stack_id = io4->stack_id;
	sv.function_id = FUNCTION_SET_VALUE;
	sv.length = sizeof(SetValue_);
	sv.value_mask = value_mask;

	ipcon_device_write(io4, (char *)&sv, sizeof(SetValue_));

	ipcon_sem_post_write(io4);

	return E_OK;
}

int io4_get_value(IO4 *io4, uint8_t *ret_value_mask) {
	if(io4->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(io4);

	io4->answer.function_id = FUNCTION_GET_VALUE;
	io4->answer.length = sizeof(GetValueReturn_);
	GetValue_ gv;
	gv.stack_id = io4->stack_id;
	gv.function_id = FUNCTION_GET_VALUE;
	gv.length = sizeof(GetValue_);

	ipcon_device_write(io4, (char *)&gv, sizeof(GetValue_));

	if(ipcon_answer_sem_wait_timeout(io4) != 0) {
		ipcon_sem_post_write(io4);
		return E_TIMEOUT;
	}

	GetValueReturn_ *gvr = (GetValueReturn_ *)io4->answer.buffer;
	*ret_value_mask = gvr->value_mask;

	ipcon_sem_post_write(io4);

	return E_OK;
}

int io4_set_configuration(IO4 *io4, uint8_t pin_mask, char direction, bool value) {
	if(io4->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(io4);

	SetConfiguration_ sc;
	sc.stack_id = io4->stack_id;
	sc.function_id = FUNCTION_SET_CONFIGURATION;
	sc.length = sizeof(SetConfiguration_);
	sc.pin_mask = pin_mask;
	sc.direction = direction;
	sc.value = value;

	ipcon_device_write(io4, (char *)&sc, sizeof(SetConfiguration_));

	ipcon_sem_post_write(io4);

	return E_OK;
}

int io4_get_configuration(IO4 *io4, uint8_t *ret_direction_mask, uint8_t *ret_value_mask) {
	if(io4->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(io4);

	io4->answer.function_id = FUNCTION_GET_CONFIGURATION;
	io4->answer.length = sizeof(GetConfigurationReturn_);
	GetConfiguration_ gc;
	gc.stack_id = io4->stack_id;
	gc.function_id = FUNCTION_GET_CONFIGURATION;
	gc.length = sizeof(GetConfiguration_);

	ipcon_device_write(io4, (char *)&gc, sizeof(GetConfiguration_));

	if(ipcon_answer_sem_wait_timeout(io4) != 0) {
		ipcon_sem_post_write(io4);
		return E_TIMEOUT;
	}

	GetConfigurationReturn_ *gcr = (GetConfigurationReturn_ *)io4->answer.buffer;
	*ret_direction_mask = gcr->direction_mask;
	*ret_value_mask = gcr->value_mask;

	ipcon_sem_post_write(io4);

	return E_OK;
}

int io4_set_debounce_period(IO4 *io4, uint32_t debounce) {
	if(io4->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(io4);

	SetDebouncePeriod_ sdp;
	sdp.stack_id = io4->stack_id;
	sdp.function_id = FUNCTION_SET_DEBOUNCE_PERIOD;
	sdp.length = sizeof(SetDebouncePeriod_);
	sdp.debounce = debounce;

	ipcon_device_write(io4, (char *)&sdp, sizeof(SetDebouncePeriod_));

	ipcon_sem_post_write(io4);

	return E_OK;
}

int io4_get_debounce_period(IO4 *io4, uint32_t *ret_debounce) {
	if(io4->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(io4);

	io4->answer.function_id = FUNCTION_GET_DEBOUNCE_PERIOD;
	io4->answer.length = sizeof(GetDebouncePeriodReturn_);
	GetDebouncePeriod_ gdp;
	gdp.stack_id = io4->stack_id;
	gdp.function_id = FUNCTION_GET_DEBOUNCE_PERIOD;
	gdp.length = sizeof(GetDebouncePeriod_);

	ipcon_device_write(io4, (char *)&gdp, sizeof(GetDebouncePeriod_));

	if(ipcon_answer_sem_wait_timeout(io4) != 0) {
		ipcon_sem_post_write(io4);
		return E_TIMEOUT;
	}

	GetDebouncePeriodReturn_ *gdpr = (GetDebouncePeriodReturn_ *)io4->answer.buffer;
	*ret_debounce = gdpr->debounce;

	ipcon_sem_post_write(io4);

	return E_OK;
}

int io4_set_interrupt(IO4 *io4, uint8_t interrupt_mask) {
	if(io4->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(io4);

	SetInterrupt_ si;
	si.stack_id = io4->stack_id;
	si.function_id = FUNCTION_SET_INTERRUPT;
	si.length = sizeof(SetInterrupt_);
	si.interrupt_mask = interrupt_mask;

	ipcon_device_write(io4, (char *)&si, sizeof(SetInterrupt_));

	ipcon_sem_post_write(io4);

	return E_OK;
}

int io4_get_interrupt(IO4 *io4, uint8_t *ret_interrupt_mask) {
	if(io4->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(io4);

	io4->answer.function_id = FUNCTION_GET_INTERRUPT;
	io4->answer.length = sizeof(GetInterruptReturn_);
	GetInterrupt_ gi;
	gi.stack_id = io4->stack_id;
	gi.function_id = FUNCTION_GET_INTERRUPT;
	gi.length = sizeof(GetInterrupt_);

	ipcon_device_write(io4, (char *)&gi, sizeof(GetInterrupt_));

	if(ipcon_answer_sem_wait_timeout(io4) != 0) {
		ipcon_sem_post_write(io4);
		return E_TIMEOUT;
	}

	GetInterruptReturn_ *gir = (GetInterruptReturn_ *)io4->answer.buffer;
	*ret_interrupt_mask = gir->interrupt_mask;

	ipcon_sem_post_write(io4);

	return E_OK;
}

int io4_get_version(IO4 *io4, char ret_name[40], uint8_t ret_firmware_version[3], uint8_t ret_binding_version[3]) {
	strncpy(ret_name, io4->name, 40);

	ret_firmware_version[0] = io4->firmware_version[0];
	ret_firmware_version[1] = io4->firmware_version[1];
	ret_firmware_version[2] = io4->firmware_version[2];

	ret_binding_version[0] = io4->binding_version[0];
	ret_binding_version[1] = io4->binding_version[1];
	ret_binding_version[2] = io4->binding_version[2];

	return E_OK;
}

static int io4_callback_interrupt(IO4 *io4, const unsigned char *buffer) {
	InterruptCallback_ *ic = (InterruptCallback_ *)buffer;
	((interrupt_func_t)io4->callbacks[ic->function_id])(ic->interrupt_mask, ic->value_mask);
	return sizeof(InterruptCallback_);
}

void io4_register_callback(IO4 *io4, uint8_t cb, void *func) {
    io4->callbacks[cb] = func;
}

void io4_create(IO4 *io4, const char *uid) {
	ipcon_device_create(io4, uid);

	io4->expected_name = "IO-4 Bricklet";

	io4->binding_version[0] = 1;
	io4->binding_version[1] = 0;
	io4->binding_version[2] = 0;

	io4->device_callbacks[IO4_CALLBACK_INTERRUPT] = io4_callback_interrupt;
}
