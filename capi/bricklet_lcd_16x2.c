/* ***********************************************************
 * This file was automatically generated on 2012-05-21.      *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generator git on tinkerforge.com                   *
 *************************************************************/

#include "bricklet_lcd_16x2.h"

#include <string.h>

#define FUNCTION_WRITE_LINE 1
#define FUNCTION_CLEAR_DISPLAY 2
#define FUNCTION_BACKLIGHT_ON 3
#define FUNCTION_BACKLIGHT_OFF 4
#define FUNCTION_IS_BACKLIGHT_ON 5
#define FUNCTION_SET_CONFIG 6
#define FUNCTION_GET_CONFIG 7
#define FUNCTION_IS_BUTTON_PRESSED 8


typedef void (*button_pressed_func_t)(uint8_t);

typedef void (*button_released_func_t)(uint8_t);

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
	uint8_t line;
	uint8_t position;
	char text[16];
} ATTRIBUTE_PACKED WriteLine_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED ClearDisplay_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED BacklightOn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED BacklightOff_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED IsBacklightOn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	bool backlight;
} ATTRIBUTE_PACKED IsBacklightOnReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	bool cursor;
	bool blinking;
} ATTRIBUTE_PACKED SetConfig_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED GetConfig_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	bool cursor;
	bool blinking;
} ATTRIBUTE_PACKED GetConfigReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint8_t button;
} ATTRIBUTE_PACKED IsButtonPressed_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	bool pressed;
} ATTRIBUTE_PACKED IsButtonPressedReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint8_t button;
} ATTRIBUTE_PACKED ButtonPressedCallback_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint8_t button;
} ATTRIBUTE_PACKED ButtonReleasedCallback_;

#if defined _MSC_VER || defined __BORLANDC__
	#pragma pack(pop)
#endif
#undef ATTRIBUTE_PACKED

int lcd_16x2_write_line(LCD16x2 *lcd_16x2, uint8_t line, uint8_t position, char text[16]) {
	if(lcd_16x2->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(lcd_16x2);

	WriteLine_ wl;
	wl.stack_id = lcd_16x2->stack_id;
	wl.function_id = FUNCTION_WRITE_LINE;
	wl.length = sizeof(WriteLine_);
	wl.line = line;
	wl.position = position;
	strncpy(wl.text, text, 16);


	ipcon_device_write(lcd_16x2, (char *)&wl, sizeof(WriteLine_));

	ipcon_sem_post_write(lcd_16x2);

	return E_OK;
}

int lcd_16x2_clear_display(LCD16x2 *lcd_16x2) {
	if(lcd_16x2->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(lcd_16x2);

	ClearDisplay_ cd;
	cd.stack_id = lcd_16x2->stack_id;
	cd.function_id = FUNCTION_CLEAR_DISPLAY;
	cd.length = sizeof(ClearDisplay_);

	ipcon_device_write(lcd_16x2, (char *)&cd, sizeof(ClearDisplay_));

	ipcon_sem_post_write(lcd_16x2);

	return E_OK;
}

int lcd_16x2_backlight_on(LCD16x2 *lcd_16x2) {
	if(lcd_16x2->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(lcd_16x2);

	BacklightOn_ bo;
	bo.stack_id = lcd_16x2->stack_id;
	bo.function_id = FUNCTION_BACKLIGHT_ON;
	bo.length = sizeof(BacklightOn_);

	ipcon_device_write(lcd_16x2, (char *)&bo, sizeof(BacklightOn_));

	ipcon_sem_post_write(lcd_16x2);

	return E_OK;
}

int lcd_16x2_backlight_off(LCD16x2 *lcd_16x2) {
	if(lcd_16x2->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(lcd_16x2);

	BacklightOff_ bo;
	bo.stack_id = lcd_16x2->stack_id;
	bo.function_id = FUNCTION_BACKLIGHT_OFF;
	bo.length = sizeof(BacklightOff_);

	ipcon_device_write(lcd_16x2, (char *)&bo, sizeof(BacklightOff_));

	ipcon_sem_post_write(lcd_16x2);

	return E_OK;
}

int lcd_16x2_is_backlight_on(LCD16x2 *lcd_16x2, bool *ret_backlight) {
	if(lcd_16x2->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(lcd_16x2);

	lcd_16x2->answer.function_id = FUNCTION_IS_BACKLIGHT_ON;
	lcd_16x2->answer.length = sizeof(IsBacklightOnReturn_);
	IsBacklightOn_ ibo;
	ibo.stack_id = lcd_16x2->stack_id;
	ibo.function_id = FUNCTION_IS_BACKLIGHT_ON;
	ibo.length = sizeof(IsBacklightOn_);

	ipcon_device_write(lcd_16x2, (char *)&ibo, sizeof(IsBacklightOn_));

	if(ipcon_answer_sem_wait_timeout(lcd_16x2) != 0) {
		ipcon_sem_post_write(lcd_16x2);
		return E_TIMEOUT;
	}

	IsBacklightOnReturn_ *ibor = (IsBacklightOnReturn_ *)lcd_16x2->answer.buffer;
	*ret_backlight = ibor->backlight;

	ipcon_sem_post_write(lcd_16x2);

	return E_OK;
}

int lcd_16x2_set_config(LCD16x2 *lcd_16x2, bool cursor, bool blinking) {
	if(lcd_16x2->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(lcd_16x2);

	SetConfig_ sc;
	sc.stack_id = lcd_16x2->stack_id;
	sc.function_id = FUNCTION_SET_CONFIG;
	sc.length = sizeof(SetConfig_);
	sc.cursor = cursor;
	sc.blinking = blinking;

	ipcon_device_write(lcd_16x2, (char *)&sc, sizeof(SetConfig_));

	ipcon_sem_post_write(lcd_16x2);

	return E_OK;
}

int lcd_16x2_get_config(LCD16x2 *lcd_16x2, bool *ret_cursor, bool *ret_blinking) {
	if(lcd_16x2->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(lcd_16x2);

	lcd_16x2->answer.function_id = FUNCTION_GET_CONFIG;
	lcd_16x2->answer.length = sizeof(GetConfigReturn_);
	GetConfig_ gc;
	gc.stack_id = lcd_16x2->stack_id;
	gc.function_id = FUNCTION_GET_CONFIG;
	gc.length = sizeof(GetConfig_);

	ipcon_device_write(lcd_16x2, (char *)&gc, sizeof(GetConfig_));

	if(ipcon_answer_sem_wait_timeout(lcd_16x2) != 0) {
		ipcon_sem_post_write(lcd_16x2);
		return E_TIMEOUT;
	}

	GetConfigReturn_ *gcr = (GetConfigReturn_ *)lcd_16x2->answer.buffer;
	*ret_cursor = gcr->cursor;
	*ret_blinking = gcr->blinking;

	ipcon_sem_post_write(lcd_16x2);

	return E_OK;
}

int lcd_16x2_is_button_pressed(LCD16x2 *lcd_16x2, uint8_t button, bool *ret_pressed) {
	if(lcd_16x2->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(lcd_16x2);

	lcd_16x2->answer.function_id = FUNCTION_IS_BUTTON_PRESSED;
	lcd_16x2->answer.length = sizeof(IsButtonPressedReturn_);
	IsButtonPressed_ ibp;
	ibp.stack_id = lcd_16x2->stack_id;
	ibp.function_id = FUNCTION_IS_BUTTON_PRESSED;
	ibp.length = sizeof(IsButtonPressed_);
	ibp.button = button;

	ipcon_device_write(lcd_16x2, (char *)&ibp, sizeof(IsButtonPressed_));

	if(ipcon_answer_sem_wait_timeout(lcd_16x2) != 0) {
		ipcon_sem_post_write(lcd_16x2);
		return E_TIMEOUT;
	}

	IsButtonPressedReturn_ *ibpr = (IsButtonPressedReturn_ *)lcd_16x2->answer.buffer;
	*ret_pressed = ibpr->pressed;

	ipcon_sem_post_write(lcd_16x2);

	return E_OK;
}

int lcd_16x2_get_version(LCD16x2 *lcd_16x2, char ret_name[40], uint8_t ret_firmware_version[3], uint8_t ret_binding_version[3]) {
	strncpy(ret_name, lcd_16x2->name, 40);

	ret_firmware_version[0] = lcd_16x2->firmware_version[0];
	ret_firmware_version[1] = lcd_16x2->firmware_version[1];
	ret_firmware_version[2] = lcd_16x2->firmware_version[2];

	ret_binding_version[0] = lcd_16x2->binding_version[0];
	ret_binding_version[1] = lcd_16x2->binding_version[1];
	ret_binding_version[2] = lcd_16x2->binding_version[2];

	return E_OK;
}

static int lcd_16x2_callback_button_pressed(LCD16x2 *lcd_16x2, const unsigned char *buffer) {
	ButtonPressedCallback_ *bpc = (ButtonPressedCallback_ *)buffer;
	((button_pressed_func_t)lcd_16x2->callbacks[bpc->function_id])(bpc->button);
	return sizeof(ButtonPressedCallback_);
}

static int lcd_16x2_callback_button_released(LCD16x2 *lcd_16x2, const unsigned char *buffer) {
	ButtonReleasedCallback_ *brc = (ButtonReleasedCallback_ *)buffer;
	((button_released_func_t)lcd_16x2->callbacks[brc->function_id])(brc->button);
	return sizeof(ButtonReleasedCallback_);
}

void lcd_16x2_register_callback(LCD16x2 *lcd_16x2, uint8_t cb, void *func) {
    lcd_16x2->callbacks[cb] = func;
}

void lcd_16x2_create(LCD16x2 *lcd_16x2, const char *uid) {
	ipcon_device_create(lcd_16x2, uid);

	lcd_16x2->expected_name = "LCD 16x2 Bricklet";

	lcd_16x2->binding_version[0] = 1;
	lcd_16x2->binding_version[1] = 0;
	lcd_16x2->binding_version[2] = 0;

	lcd_16x2->device_callbacks[LCD_16X2_CALLBACK_BUTTON_PRESSED] = lcd_16x2_callback_button_pressed;
	lcd_16x2->device_callbacks[LCD_16X2_CALLBACK_BUTTON_RELEASED] = lcd_16x2_callback_button_released;
}
