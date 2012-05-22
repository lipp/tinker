/* ***********************************************************
 * This file was automatically generated on 2012-05-21.      *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generator git on tinkerforge.com                   *
 *************************************************************/

#include "bricklet_io16.h"

#include <string.h>

#define FUNCTION_SET_PORT 1
#define FUNCTION_GET_PORT 2
#define FUNCTION_SET_PORT_CONFIGURATION 3
#define FUNCTION_GET_PORT_CONFIGURATION 4
#define FUNCTION_SET_DEBOUNCE_PERIOD 5
#define FUNCTION_GET_DEBOUNCE_PERIOD 6
#define FUNCTION_SET_PORT_INTERRUPT 7
#define FUNCTION_GET_PORT_INTERRUPT 8


typedef void (*interrupt_func_t)(char, uint8_t, uint8_t);

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
	char port;
	uint8_t value_mask;
} ATTRIBUTE_PACKED SetPort_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	char port;
} ATTRIBUTE_PACKED GetPort_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint8_t value_mask;
} ATTRIBUTE_PACKED GetPortReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	char port;
	uint8_t port_mask;
	char direction;
	bool value;
} ATTRIBUTE_PACKED SetPortConfiguration_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	char port;
} ATTRIBUTE_PACKED GetPortConfiguration_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint8_t direction_mask;
	uint8_t value_mask;
} ATTRIBUTE_PACKED GetPortConfigurationReturn_;

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
	char port;
	uint8_t interrupt_mask;
} ATTRIBUTE_PACKED SetPortInterrupt_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	char port;
} ATTRIBUTE_PACKED GetPortInterrupt_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint8_t interrupt_mask;
} ATTRIBUTE_PACKED GetPortInterruptReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	char port;
	uint8_t interrupt_mask;
	uint8_t value_mask;
} ATTRIBUTE_PACKED InterruptCallback_;

#if defined _MSC_VER || defined __BORLANDC__
	#pragma pack(pop)
#endif
#undef ATTRIBUTE_PACKED

int io16_set_port(IO16 *io16, char port, uint8_t value_mask) {
	if(io16->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(io16);

	SetPort_ sp;
	sp.stack_id = io16->stack_id;
	sp.function_id = FUNCTION_SET_PORT;
	sp.length = sizeof(SetPort_);
	sp.port = port;
	sp.value_mask = value_mask;

	ipcon_device_write(io16, (char *)&sp, sizeof(SetPort_));

	ipcon_sem_post_write(io16);

	return E_OK;
}

int io16_get_port(IO16 *io16, char port, uint8_t *ret_value_mask) {
	if(io16->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(io16);

	io16->answer.function_id = FUNCTION_GET_PORT;
	io16->answer.length = sizeof(GetPortReturn_);
	GetPort_ gp;
	gp.stack_id = io16->stack_id;
	gp.function_id = FUNCTION_GET_PORT;
	gp.length = sizeof(GetPort_);
	gp.port = port;

	ipcon_device_write(io16, (char *)&gp, sizeof(GetPort_));

	if(ipcon_answer_sem_wait_timeout(io16) != 0) {
		ipcon_sem_post_write(io16);
		return E_TIMEOUT;
	}

	GetPortReturn_ *gpr = (GetPortReturn_ *)io16->answer.buffer;
	*ret_value_mask = gpr->value_mask;

	ipcon_sem_post_write(io16);

	return E_OK;
}

int io16_set_port_configuration(IO16 *io16, char port, uint8_t port_mask, char direction, bool value) {
	if(io16->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(io16);

	SetPortConfiguration_ spc;
	spc.stack_id = io16->stack_id;
	spc.function_id = FUNCTION_SET_PORT_CONFIGURATION;
	spc.length = sizeof(SetPortConfiguration_);
	spc.port = port;
	spc.port_mask = port_mask;
	spc.direction = direction;
	spc.value = value;

	ipcon_device_write(io16, (char *)&spc, sizeof(SetPortConfiguration_));

	ipcon_sem_post_write(io16);

	return E_OK;
}

int io16_get_port_configuration(IO16 *io16, char port, uint8_t *ret_direction_mask, uint8_t *ret_value_mask) {
	if(io16->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(io16);

	io16->answer.function_id = FUNCTION_GET_PORT_CONFIGURATION;
	io16->answer.length = sizeof(GetPortConfigurationReturn_);
	GetPortConfiguration_ gpc;
	gpc.stack_id = io16->stack_id;
	gpc.function_id = FUNCTION_GET_PORT_CONFIGURATION;
	gpc.length = sizeof(GetPortConfiguration_);
	gpc.port = port;

	ipcon_device_write(io16, (char *)&gpc, sizeof(GetPortConfiguration_));

	if(ipcon_answer_sem_wait_timeout(io16) != 0) {
		ipcon_sem_post_write(io16);
		return E_TIMEOUT;
	}

	GetPortConfigurationReturn_ *gpcr = (GetPortConfigurationReturn_ *)io16->answer.buffer;
	*ret_direction_mask = gpcr->direction_mask;
	*ret_value_mask = gpcr->value_mask;

	ipcon_sem_post_write(io16);

	return E_OK;
}

int io16_set_debounce_period(IO16 *io16, uint32_t debounce) {
	if(io16->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(io16);

	SetDebouncePeriod_ sdp;
	sdp.stack_id = io16->stack_id;
	sdp.function_id = FUNCTION_SET_DEBOUNCE_PERIOD;
	sdp.length = sizeof(SetDebouncePeriod_);
	sdp.debounce = debounce;

	ipcon_device_write(io16, (char *)&sdp, sizeof(SetDebouncePeriod_));

	ipcon_sem_post_write(io16);

	return E_OK;
}

int io16_get_debounce_period(IO16 *io16, uint32_t *ret_debounce) {
	if(io16->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(io16);

	io16->answer.function_id = FUNCTION_GET_DEBOUNCE_PERIOD;
	io16->answer.length = sizeof(GetDebouncePeriodReturn_);
	GetDebouncePeriod_ gdp;
	gdp.stack_id = io16->stack_id;
	gdp.function_id = FUNCTION_GET_DEBOUNCE_PERIOD;
	gdp.length = sizeof(GetDebouncePeriod_);

	ipcon_device_write(io16, (char *)&gdp, sizeof(GetDebouncePeriod_));

	if(ipcon_answer_sem_wait_timeout(io16) != 0) {
		ipcon_sem_post_write(io16);
		return E_TIMEOUT;
	}

	GetDebouncePeriodReturn_ *gdpr = (GetDebouncePeriodReturn_ *)io16->answer.buffer;
	*ret_debounce = gdpr->debounce;

	ipcon_sem_post_write(io16);

	return E_OK;
}

int io16_set_port_interrupt(IO16 *io16, char port, uint8_t interrupt_mask) {
	if(io16->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(io16);

	SetPortInterrupt_ spi;
	spi.stack_id = io16->stack_id;
	spi.function_id = FUNCTION_SET_PORT_INTERRUPT;
	spi.length = sizeof(SetPortInterrupt_);
	spi.port = port;
	spi.interrupt_mask = interrupt_mask;

	ipcon_device_write(io16, (char *)&spi, sizeof(SetPortInterrupt_));

	ipcon_sem_post_write(io16);

	return E_OK;
}

int io16_get_port_interrupt(IO16 *io16, char port, uint8_t *ret_interrupt_mask) {
	if(io16->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(io16);

	io16->answer.function_id = FUNCTION_GET_PORT_INTERRUPT;
	io16->answer.length = sizeof(GetPortInterruptReturn_);
	GetPortInterrupt_ gpi;
	gpi.stack_id = io16->stack_id;
	gpi.function_id = FUNCTION_GET_PORT_INTERRUPT;
	gpi.length = sizeof(GetPortInterrupt_);
	gpi.port = port;

	ipcon_device_write(io16, (char *)&gpi, sizeof(GetPortInterrupt_));

	if(ipcon_answer_sem_wait_timeout(io16) != 0) {
		ipcon_sem_post_write(io16);
		return E_TIMEOUT;
	}

	GetPortInterruptReturn_ *gpir = (GetPortInterruptReturn_ *)io16->answer.buffer;
	*ret_interrupt_mask = gpir->interrupt_mask;

	ipcon_sem_post_write(io16);

	return E_OK;
}

int io16_get_version(IO16 *io16, char ret_name[40], uint8_t ret_firmware_version[3], uint8_t ret_binding_version[3]) {
	strncpy(ret_name, io16->name, 40);

	ret_firmware_version[0] = io16->firmware_version[0];
	ret_firmware_version[1] = io16->firmware_version[1];
	ret_firmware_version[2] = io16->firmware_version[2];

	ret_binding_version[0] = io16->binding_version[0];
	ret_binding_version[1] = io16->binding_version[1];
	ret_binding_version[2] = io16->binding_version[2];

	return E_OK;
}

static int io16_callback_interrupt(IO16 *io16, const unsigned char *buffer) {
	InterruptCallback_ *ic = (InterruptCallback_ *)buffer;
	((interrupt_func_t)io16->callbacks[ic->function_id])(ic->port, ic->interrupt_mask, ic->value_mask);
	return sizeof(InterruptCallback_);
}

void io16_register_callback(IO16 *io16, uint8_t cb, void *func) {
    io16->callbacks[cb] = func;
}

void io16_create(IO16 *io16, const char *uid) {
	ipcon_device_create(io16, uid);

	io16->expected_name = "IO-16 Bricklet";

	io16->binding_version[0] = 1;
	io16->binding_version[1] = 0;
	io16->binding_version[2] = 0;

	io16->device_callbacks[IO16_CALLBACK_INTERRUPT] = io16_callback_interrupt;
}
