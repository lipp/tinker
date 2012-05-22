/* ***********************************************************
 * This file was automatically generated on 2012-05-21.      *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generator git on tinkerforge.com                   *
 *************************************************************/

#ifndef BRICKLET_JOYSTICK_H
#define BRICKLET_JOYSTICK_H

#include "ip_connection.h"

/**
 * \defgroup BrickletJoystick Joystick Bricklet
 */

/**
 * \ingroup BrickletJoystick
 *
 * Dual-Axis Joystick with Button
 */
typedef Device Joystick;

/**
 * \ingroup BrickletJoystick
 *
 * This callback is triggered periodically with the period that is set by
 * {@link joystick_set_position_callback_period}. The parameter is the position of the
 * Joystick.
 * 
 * {@link JOYSTICK_CALLBACK_POSITION} is only triggered if the position has changed since the
 * last triggering.
 */
#define JOYSTICK_CALLBACK_POSITION 15

/**
 * \ingroup BrickletJoystick
 *
 * This callback is triggered periodically with the period that is set by
 * {@link joystick_set_analog_value_callback_period}. The parameters are the analog values
 * of the Joystick.
 * 
 * {@link JOYSTICK_CALLBACK_ANALOG_VALUE} is only triggered if the value has changed since the
 * last triggering.
 */
#define JOYSTICK_CALLBACK_ANALOG_VALUE 16

/**
 * \ingroup BrickletJoystick
 *
 * This callback is triggered when the threshold as set by
 * {@link joystick_set_position_callback_threshold} is reached.
 * The parameters are the position of the Joystick.
 * 
 * If the threshold keeps being reached, the callback is triggered periodically
 * with the period as set by {@link joystick_set_debounce_period}.
 */
#define JOYSTICK_CALLBACK_POSITION_REACHED 17

/**
 * \ingroup BrickletJoystick
 *
 * This callback is triggered when the threshold as set by
 * {@link joystick_set_analog_value_callback_threshold} is reached.
 * The parameters are the analog values of the Joystick.
 * 
 * If the threshold keeps being reached, the callback is triggered periodically
 * with the period as set by {@link joystick_set_debounce_period}.
 */
#define JOYSTICK_CALLBACK_ANALOG_VALUE_REACHED 18

/**
 * \ingroup BrickletJoystick
 *
 * This callback is triggered when the button is pressed.
 */
#define JOYSTICK_CALLBACK_PRESSED 19

/**
 * \ingroup BrickletJoystick
 *
 * This callback is triggered when the button is released.
 */
#define JOYSTICK_CALLBACK_RELEASED 20

/**
 * \ingroup BrickletJoystick
 *
 * Creates an object with the unique device ID \c uid. This object can then be
 * added to the IP connection.
 */
void joystick_create(Joystick *joystick, const char *uid);

/**
 * \ingroup BrickletJoystick
 *
 * Returns the position of the Joystick. The value ranges between -100 and
 * 100 for both axis. The middle position of the joystick is x=0, y=0. The
 * returned values are averaged and calibrated (see {@link joystick_calibrate}).
 * 
 * If you want to get the position periodically, it is recommended to use the
 * callback {@link JOYSTICK_CALLBACK_POSITION} and set the period with 
 * {@link joystick_set_position_callback_period}.
 */
int joystick_get_position(Joystick *joystick, int16_t *ret_x, int16_t *ret_y);

/**
 * \ingroup BrickletJoystick
 *
 * Returns true if the button is pressed and false otherwise.
 * 
 * It is recommended to use the {@link JOYSTICK_CALLBACK_PRESSED} and {@link JOYSTICK_CALLBACK_RELEASED} callbacks
 * to handle the button.
 */
int joystick_is_pressed(Joystick *joystick, bool *ret_pressed);

/**
 * \ingroup BrickletJoystick
 *
 * Returns the values as read by a 12 bit analog to digital converter.
 * The values are between 0 and 4095 for both axis.
 * 
 *  \note
 *   The values returned by {@link joystick_get_position} are averaged over several samples
 *   to yield less noise, while {@link joystick_get_analog_value} gives back raw
 *   unfiltered analog values. The only reason to use {@link joystick_get_analog_value} is,
 *   if you need the full resolution of the analog to digital converter.
 * 
 * If you want the analog values periodically, it is recommended to use the 
 * callback {@link JOYSTICK_CALLBACK_ANALOG_VALUE} and set the period with 
 * {@link joystick_set_analog_value_callback_period}.
 */
int joystick_get_analog_value(Joystick *joystick, uint16_t *ret_x, uint16_t *ret_y);

/**
 * \ingroup BrickletJoystick
 *
 * Calibrates the middle position of the Joystick. If your Joystick Bricklet
 * does not return x=0 and y=0 in the middle position, call this function
 * while the Joystick is standing still in the middle position.
 * 
 * The resulting calibration will be saved on the EEPROM of the Joystick
 * Bricklet, thus you only have to calibrate it once.
 */
int joystick_calibrate(Joystick *joystick);

/**
 * \ingroup BrickletJoystick
 *
 * Sets the period in ms with which the {@link JOYSTICK_CALLBACK_POSITION} callback is triggered
 * periodically. A value of 0 turns the callback off.
 * 
 * {@link JOYSTICK_CALLBACK_POSITION} is only triggered if the position has changed since the
 * last triggering.
 * 
 * The default value is 0.
 */
int joystick_set_position_callback_period(Joystick *joystick, uint32_t period);

/**
 * \ingroup BrickletJoystick
 *
 * Returns the period as set by {@link joystick_set_position_callback_period}.
 */
int joystick_get_position_callback_period(Joystick *joystick, uint32_t *ret_period);

/**
 * \ingroup BrickletJoystick
 *
 * Sets the period in ms with which the {@link JOYSTICK_CALLBACK_ANALOG_VALUE} callback is triggered
 * periodically. A value of 0 turns the callback off.
 * 
 * {@link JOYSTICK_CALLBACK_ANALOG_VALUE} is only triggered if the analog value has changed since the
 * last triggering.
 * 
 * The default value is 0.
 */
int joystick_set_analog_value_callback_period(Joystick *joystick, uint32_t period);

/**
 * \ingroup BrickletJoystick
 *
 * Returns the period as set by {@link joystick_set_analog_value_callback_period}.
 */
int joystick_get_analog_value_callback_period(Joystick *joystick, uint32_t *ret_period);

/**
 * \ingroup BrickletJoystick
 *
 * Sets the thresholds for the {@link JOYSTICK_CALLBACK_POSITION_REACHED} callback. 
 * 
 * The following options are possible:
 * 
 * \verbatim
 *  :header: "Option", "Description"
 *  :widths: 10, 100
 *  "'x'", "Callback is turned off."
 *  "'o'", "Callback is triggered when the position is *outside* the min and max values"
 *  "'i'", "Callback is triggered when the position is *inside* the min and max values"
 *  "'<'", "Callback is triggered when the position is smaller than the min value (max is ignored)"
 *  "'>'", "Callback is triggered when the position is greater than the min value (max is ignored)"
 * \endverbatim
 * 
 * The default value is ('x', 0, 0, 0, 0).
 */
int joystick_set_position_callback_threshold(Joystick *joystick, char option, int16_t min_x, int16_t max_x, int16_t min_y, int16_t max_y);

/**
 * \ingroup BrickletJoystick
 *
 * Returns the threshold as set by {@link joystick_set_position_callback_threshold}.
 */
int joystick_get_position_callback_threshold(Joystick *joystick, char *ret_option, int16_t *ret_min_x, int16_t *ret_max_x, int16_t *ret_min_y, int16_t *ret_max_y);

/**
 * \ingroup BrickletJoystick
 *
 * Sets the thresholds for the {@link JOYSTICK_CALLBACK_ANALOG_VALUE_REACHED} callback. 
 * 
 * The following options are possible:
 * 
 * \verbatim
 *  :header: "Option", "Description"
 *  :widths: 10, 100
 *  "'x'", "Callback is turned off."
 *  "'o'", "Callback is triggered when the position is *outside* the min and max values"
 *  "'i'", "Callback is triggered when the position is *inside* the min and max values"
 *  "'<'", "Callback is triggered when the position is smaller than the min value (max is ignored)"
 *  "'>'", "Callback is triggered when the position is greater than the min value (max is ignored)"
 * \endverbatim
 * 
 * The default value is ('x', 0, 0, 0, 0).
 */
int joystick_set_analog_value_callback_threshold(Joystick *joystick, char option, uint16_t min_x, uint16_t max_x, uint16_t min_y, uint16_t max_y);

/**
 * \ingroup BrickletJoystick
 *
 * Returns the threshold as set by {@link joystick_set_analog_value_callback_threshold}.
 */
int joystick_get_analog_value_callback_threshold(Joystick *joystick, char *ret_option, uint16_t *ret_min_x, uint16_t *ret_max_x, uint16_t *ret_min_y, uint16_t *ret_max_y);

/**
 * \ingroup BrickletJoystick
 *
 * Sets the period in ms with which the threshold callbacks
 * 
 *  {@link JOYSTICK_CALLBACK_POSITION_REACHED}, {@link JOYSTICK_CALLBACK_ANALOG_VALUE_REACHED}
 * 
 * are triggered, if the thresholds
 * 
 *  {@link joystick_set_position_callback_threshold}, {@link joystick_set_analog_value_callback_threshold}
 * 
 * keep being reached.
 * 
 * The default value is 100.
 */
int joystick_set_debounce_period(Joystick *joystick, uint32_t debounce);

/**
 * \ingroup BrickletJoystick
 *
 * Returns the debounce period as set by {@link joystick_set_debounce_period}.
 */
int joystick_get_debounce_period(Joystick *joystick, uint32_t *ret_debounce);

/**
 * \ingroup BrickletJoystick
 *
 * Returns the name (including the hardware version), the firmware version
 * and the binding version of the device. The firmware and binding versions are
 * given in arrays of size 3 with the syntax [major, minor, revision].
 */
int joystick_get_version(Joystick *joystick, char ret_name[40], uint8_t ret_firmware_version[3], uint8_t ret_binding_version[3]);

/**
 * \ingroup BrickletJoystick
 *
 * Registers a callback with ID \c cb to the function \c func.
 */
void joystick_register_callback(Joystick *joystick, uint8_t cb, void *func);

#endif
