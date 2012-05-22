/* ***********************************************************
 * This file was automatically generated on 2012-05-21.      *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generator git on tinkerforge.com                   *
 *************************************************************/

#ifndef BRICKLET_LCD_16X2_H
#define BRICKLET_LCD_16X2_H

#include "ip_connection.h"

/**
 * \defgroup BrickletLCD16x2 LCD16x2 Bricklet
 */

/**
 * \ingroup BrickletLCD16x2
 *
 * Device for controlling a LCD with 2 lines a 16 characters
 */
typedef Device LCD16x2;

/**
 * \ingroup BrickletLCD16x2
 *
 * This callback is triggered when a button is pressed. The parameter is
 * the number of the button (0 to 2).
 */
#define LCD_16X2_CALLBACK_BUTTON_PRESSED 9

/**
 * \ingroup BrickletLCD16x2
 *
 * This callback is triggered when a button is released. The parameter is
 * the number of the button (0 to 2).
 */
#define LCD_16X2_CALLBACK_BUTTON_RELEASED 10

/**
 * \ingroup BrickletLCD16x2
 *
 * Creates an object with the unique device ID \c uid. This object can then be
 * added to the IP connection.
 */
void lcd_16x2_create(LCD16x2 *lcd_16x2, const char *uid);

/**
 * \ingroup BrickletLCD16x2
 *
 * Writes text to a specific line (0 to 1) with a specific position 
 * (0 to 15). The text can have a maximum of 16 characters.
 * 
 * For example: (0, 5, "Hello") will write *Hello* in the middle of the
 * first line of the display.
 * 
 * The display uses a special charset that includes all ASCII characters except
 * backslash and tilde. The LCD charset also includes several other non-ASCII characters, see
 * the `charset specification <https://github.com/Tinkerforge/lcd-16x2-bricklet/raw/master/datasheets/standard_charset.pdf>`__
 * for details. The Unicode example above shows how to specify non-ASCII characters
 * and how to translate from Unicode to the LCD charset.
 */
int lcd_16x2_write_line(LCD16x2 *lcd_16x2, uint8_t line, uint8_t position, char text[16]);

/**
 * \ingroup BrickletLCD16x2
 *
 * Deletes all characters from the display.
 */
int lcd_16x2_clear_display(LCD16x2 *lcd_16x2);

/**
 * \ingroup BrickletLCD16x2
 *
 * Turns the backlight on.
 */
int lcd_16x2_backlight_on(LCD16x2 *lcd_16x2);

/**
 * \ingroup BrickletLCD16x2
 *
 * Turns the backlight off.
 */
int lcd_16x2_backlight_off(LCD16x2 *lcd_16x2);

/**
 * \ingroup BrickletLCD16x2
 *
 * Returns true if the backlight is on and false otherwise.
 */
int lcd_16x2_is_backlight_on(LCD16x2 *lcd_16x2, bool *ret_backlight);

/**
 * \ingroup BrickletLCD16x2
 *
 * Configures if the cursor (shown as "_") should be visible and if it
 * should be blinking (shown as a blinking block). The cursor position
 * is one character behind the the last text written with 
 * {@link lcd_16x2_write_line}.
 * 
 * The default is (false, false).
 */
int lcd_16x2_set_config(LCD16x2 *lcd_16x2, bool cursor, bool blinking);

/**
 * \ingroup BrickletLCD16x2
 *
 * Returns the configuration as set by {@link lcd_16x2_set_config}.
 */
int lcd_16x2_get_config(LCD16x2 *lcd_16x2, bool *ret_cursor, bool *ret_blinking);

/**
 * \ingroup BrickletLCD16x2
 *
 * Returns true if the button (0 to 2) is pressed. If you want to react
 * on button presses and releases it is recommended to use the
 * {@link LCD_16X2_CALLBACK_BUTTON_PRESSED} and {@link LCD_16X2_CALLBACK_BUTTON_RELEASED} callbacks.
 */
int lcd_16x2_is_button_pressed(LCD16x2 *lcd_16x2, uint8_t button, bool *ret_pressed);

/**
 * \ingroup BrickletLCD16x2
 *
 * Returns the name (including the hardware version), the firmware version
 * and the binding version of the device. The firmware and binding versions are
 * given in arrays of size 3 with the syntax [major, minor, revision].
 */
int lcd_16x2_get_version(LCD16x2 *lcd_16x2, char ret_name[40], uint8_t ret_firmware_version[3], uint8_t ret_binding_version[3]);

/**
 * \ingroup BrickletLCD16x2
 *
 * Registers a callback with ID \c cb to the function \c func.
 */
void lcd_16x2_register_callback(LCD16x2 *lcd_16x2, uint8_t cb, void *func);

#endif
