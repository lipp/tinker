/* ***********************************************************
 * This file was automatically generated on 2012-05-21.      *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generator git on tinkerforge.com                   *
 *************************************************************/

#include "bricklet_piezo_buzzer.h"

#include <string.h>

#define FUNCTION_BEEP 1
#define FUNCTION_MORSE_CODE 2


typedef void (*beep_finished_func_t)();

typedef void (*morse_code_finished_func_t)();

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
	uint32_t duration;
} ATTRIBUTE_PACKED Beep_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	char morse[60];
} ATTRIBUTE_PACKED MorseCode_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED BeepFinishedCallback_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED MorseCodeFinishedCallback_;

#if defined _MSC_VER || defined __BORLANDC__
	#pragma pack(pop)
#endif
#undef ATTRIBUTE_PACKED

int piezo_buzzer_beep(PiezoBuzzer *piezo_buzzer, uint32_t duration) {
	if(piezo_buzzer->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(piezo_buzzer);

	Beep_ b;
	b.stack_id = piezo_buzzer->stack_id;
	b.function_id = FUNCTION_BEEP;
	b.length = sizeof(Beep_);
	b.duration = duration;

	ipcon_device_write(piezo_buzzer, (char *)&b, sizeof(Beep_));

	ipcon_sem_post_write(piezo_buzzer);

	return E_OK;
}

int piezo_buzzer_morse_code(PiezoBuzzer *piezo_buzzer, char morse[60]) {
	if(piezo_buzzer->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(piezo_buzzer);

	MorseCode_ mc;
	mc.stack_id = piezo_buzzer->stack_id;
	mc.function_id = FUNCTION_MORSE_CODE;
	mc.length = sizeof(MorseCode_);
	strncpy(mc.morse, morse, 60);


	ipcon_device_write(piezo_buzzer, (char *)&mc, sizeof(MorseCode_));

	ipcon_sem_post_write(piezo_buzzer);

	return E_OK;
}

int piezo_buzzer_get_version(PiezoBuzzer *piezo_buzzer, char ret_name[40], uint8_t ret_firmware_version[3], uint8_t ret_binding_version[3]) {
	strncpy(ret_name, piezo_buzzer->name, 40);

	ret_firmware_version[0] = piezo_buzzer->firmware_version[0];
	ret_firmware_version[1] = piezo_buzzer->firmware_version[1];
	ret_firmware_version[2] = piezo_buzzer->firmware_version[2];

	ret_binding_version[0] = piezo_buzzer->binding_version[0];
	ret_binding_version[1] = piezo_buzzer->binding_version[1];
	ret_binding_version[2] = piezo_buzzer->binding_version[2];

	return E_OK;
}

static int piezo_buzzer_callback_beep_finished(PiezoBuzzer *piezo_buzzer, const unsigned char *buffer) {
	BeepFinishedCallback_ *bfc = (BeepFinishedCallback_ *)buffer;
	((beep_finished_func_t)piezo_buzzer->callbacks[bfc->function_id])();
	return sizeof(BeepFinishedCallback_);
}

static int piezo_buzzer_callback_morse_code_finished(PiezoBuzzer *piezo_buzzer, const unsigned char *buffer) {
	MorseCodeFinishedCallback_ *mcfc = (MorseCodeFinishedCallback_ *)buffer;
	((morse_code_finished_func_t)piezo_buzzer->callbacks[mcfc->function_id])();
	return sizeof(MorseCodeFinishedCallback_);
}

void piezo_buzzer_register_callback(PiezoBuzzer *piezo_buzzer, uint8_t cb, void *func) {
    piezo_buzzer->callbacks[cb] = func;
}

void piezo_buzzer_create(PiezoBuzzer *piezo_buzzer, const char *uid) {
	ipcon_device_create(piezo_buzzer, uid);

	piezo_buzzer->expected_name = "Piezo Buzzer Bricklet";

	piezo_buzzer->binding_version[0] = 1;
	piezo_buzzer->binding_version[1] = 0;
	piezo_buzzer->binding_version[2] = 0;

	piezo_buzzer->device_callbacks[PIEZO_BUZZER_CALLBACK_BEEP_FINISHED] = piezo_buzzer_callback_beep_finished;
	piezo_buzzer->device_callbacks[PIEZO_BUZZER_CALLBACK_MORSE_CODE_FINISHED] = piezo_buzzer_callback_morse_code_finished;
}
