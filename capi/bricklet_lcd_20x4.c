/* ***********************************************************
 * This file was automatically generated on 2012-05-21.      *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generator git on tinkerforge.com                   *
 *************************************************************/

#include "bricklet_lcd_20x4.h"

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
	char text[20];
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

int lcd_20x4_write_line(LCD20x4 *lcd_20x4, uint8_t line, uint8_t position, char text[20]) {
	if(lcd_20x4->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(lcd_20x4);

	WriteLine_ wl;
	wl.stack_id = lcd_20x4->stack_id;
	wl.function_id = FUNCTION_WRITE_LINE;
	wl.length = sizeof(WriteLine_);
	wl.line = line;
	wl.position = position;
	strncpy(wl.text, text, 20);


	ipcon_device_write(lcd_20x4, (char *)&wl, sizeof(WriteLine_));

	ipcon_sem_post_write(lcd_20x4);

	return E_OK;
}

int lcd_20x4_clear_display(LCD20x4 *lcd_20x4) {
	if(lcd_20x4->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(lcd_20x4);

	ClearDisplay_ cd;
	cd.stack_id = lcd_20x4->stack_id;
	cd.function_id = FUNCTION_CLEAR_DISPLAY;
	cd.length = sizeof(ClearDisplay_);

	ipcon_device_write(lcd_20x4, (char *)&cd, sizeof(ClearDisplay_));

	ipcon_sem_post_write(lcd_20x4);

	return E_OK;
}

int lcd_20x4_backlight_on(LCD20x4 *lcd_20x4) {
	if(lcd_20x4->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(lcd_20x4);

	BacklightOn_ bo;
	bo.stack_id = lcd_20x4->stack_id;
	bo.function_id = FUNCTION_BACKLIGHT_ON;
	bo.length = sizeof(BacklightOn_);

	ipcon_device_write(lcd_20x4, (char *)&bo, sizeof(BacklightOn_));

	ipcon_sem_post_write(lcd_20x4);

	return E_OK;
}

int lcd_20x4_backlight_off(LCD20x4 *lcd_20x4) {
	if(lcd_20x4->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(lcd_20x4);

	BacklightOff_ bo;
	bo.stack_id = lcd_20x4->stack_id;
	bo.function_id = FUNCTION_BACKLIGHT_OFF;
	bo.length = sizeof(BacklightOff_);

	ipcon_device_write(lcd_20x4, (char *)&bo, sizeof(BacklightOff_));

	ipcon_sem_post_write(lcd_20x4);

	return E_OK;
}

int lcd_20x4_is_backlight_on(LCD20x4 *lcd_20x4, bool *ret_backlight) {
	if(lcd_20x4->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(lcd_20x4);

	lcd_20x4->answer.function_id = FUNCTION_IS_BACKLIGHT_ON;
	lcd_20x4->answer.length = sizeof(IsBacklightOnReturn_);
	IsBacklightOn_ ibo;
	ibo.stack_id = lcd_20x4->stack_id;
	ibo.function_id = FUNCTION_IS_BACKLIGHT_ON;
	ibo.length = sizeof(IsBacklightOn_);

	ipcon_device_write(lcd_20x4, (char *)&ibo, sizeof(IsBacklightOn_));

	if(ipcon_answer_sem_wait_timeout(lcd_20x4) != 0) {
		ipcon_sem_post_write(lcd_20x4);
		return E_TIMEOUT;
	}

	IsBacklightOnReturn_ *ibor = (IsBacklightOnReturn_ *)lcd_20x4->answer.buffer;
	*ret_backlight = ibor->backlight;

	ipcon_sem_post_write(lcd_20x4);

	return E_OK;
}

int lcd_20x4_set_config(LCD20x4 *lcd_20x4, bool cursor, bool blinking) {
	if(lcd_20x4->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(lcd_20x4);

	SetConfig_ sc;
	sc.stack_id = lcd_20x4->stack_id;
	sc.function_id = FUNCTION_SET_CONFIG;
	sc.length = sizeof(SetConfig_);
	sc.cursor = cursor;
	sc.blinking = blinking;

	ipcon_device_write(lcd_20x4, (char *)&sc, sizeof(SetConfig_));

	ipcon_sem_post_write(lcd_20x4);

	return E_OK;
}

int lcd_20x4_get_config(LCD20x4 *lcd_20x4, bool *ret_cursor, bool *ret_blinking) {
	if(lcd_20x4->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(lcd_20x4);

	lcd_20x4->answer.function_id = FUNCTION_GET_CONFIG;
	lcd_20x4->answer.length = sizeof(GetConfigReturn_);
	GetConfig_ gc;
	gc.stack_id = lcd_20x4->stack_id;
	gc.function_id = FUNCTION_GET_CONFIG;
	gc.length = sizeof(GetConfig_);

	ipcon_device_write(lcd_20x4, (char *)&gc, sizeof(GetConfig_));

	if(ipcon_answer_sem_wait_timeout(lcd_20x4) != 0) {
		ipcon_sem_post_write(lcd_20x4);
		return E_TIMEOUT;
	}

	GetConfigReturn_ *gcr = (GetConfigReturn_ *)lcd_20x4->answer.buffer;
	*ret_cursor = gcr->cursor;
	*ret_blinking = gcr->blinking;

	ipcon_sem_post_write(lcd_20x4);

	return E_OK;
}

int lcd_20x4_is_button_pressed(LCD20x4 *lcd_20x4, uint8_t button, bool *ret_pressed) {
	if(lcd_20x4->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(lcd_20x4);

	lcd_20x4->answer.function_id = FUNCTION_IS_BUTTON_PRESSED;
	lcd_20x4->answer.length = sizeof(IsButtonPressedReturn_);
	IsButtonPressed_ ibp;
	ibp.stack_id = lcd_20x4->stack_id;
	ibp.function_id = FUNCTION_IS_BUTTON_PRESSED;
	ibp.length = sizeof(IsButtonPressed_);
	ibp.button = button;

	ipcon_device_write(lcd_20x4, (char *)&ibp, sizeof(IsButtonPressed_));

	if(ipcon_answer_sem_wait_timeout(lcd_20x4) != 0) {
		ipcon_sem_post_write(lcd_20x4);
		return E_TIMEOUT;
	}

	IsButtonPressedReturn_ *ibpr = (IsButtonPressedReturn_ *)lcd_20x4->answer.buffer;
	*ret_pressed = ibpr->pressed;

	ipcon_sem_post_write(lcd_20x4);

	return E_OK;
}

int lcd_20x4_get_version(LCD20x4 *lcd_20x4, char ret_name[40], uint8_t ret_firmware_version[3], uint8_t ret_binding_version[3]) {
	strncpy(ret_name, lcd_20x4->name, 40);

	ret_firmware_version[0] = lcd_20x4->firmware_version[0];
	ret_firmware_version[1] = lcd_20x4->firmware_version[1];
	ret_firmware_version[2] = lcd_20x4->firmware_version[2];

	ret_binding_version[0] = lcd_20x4->binding_version[0];
	ret_binding_version[1] = lcd_20x4->binding_version[1];
	ret_binding_version[2] = lcd_20x4->binding_version[2];

	return E_OK;
}

static int lcd_20x4_callback_button_pressed(LCD20x4 *lcd_20x4, const unsigned char *buffer) {
	ButtonPressedCallback_ *bpc = (ButtonPressedCallback_ *)buffer;
	((button_pressed_func_t)lcd_20x4->callbacks[bpc->function_id])(bpc->button);
	return sizeof(ButtonPressedCallback_);
}

static int lcd_20x4_callback_button_released(LCD20x4 *lcd_20x4, const unsigned char *buffer) {
	ButtonReleasedCallback_ *brc = (ButtonReleasedCallback_ *)buffer;
	((button_released_func_t)lcd_20x4->callbacks[brc->function_id])(brc->button);
	return sizeof(ButtonReleasedCallback_);
}

void lcd_20x4_register_callback(LCD20x4 *lcd_20x4, uint8_t cb, void *func) {
    lcd_20x4->callbacks[cb] = func;
}

void lcd_20x4_create(LCD20x4 *lcd_20x4, const char *uid) {
	ipcon_device_create(lcd_20x4, uid);

	lcd_20x4->expected_name = "LCD 20x4 Bricklet";

	lcd_20x4->binding_version[0] = 1;
	lcd_20x4->binding_version[1] = 0;
	lcd_20x4->binding_version[2] = 0;

	lcd_20x4->device_callbacks[LCD_20X4_CALLBACK_BUTTON_PRESSED] = lcd_20x4_callback_button_pressed;
	lcd_20x4->device_callbacks[LCD_20X4_CALLBACK_BUTTON_RELEASED] = lcd_20x4_callback_button_released;
}
