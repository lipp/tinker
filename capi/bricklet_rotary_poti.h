/* ***********************************************************
 * This file was automatically generated on 2012-05-21.      *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generator git on tinkerforge.com                   *
 *************************************************************/

#ifndef BRICKLET_ROTARY_POTI_H
#define BRICKLET_ROTARY_POTI_H

#include "ip_connection.h"

/**
 * \defgroup BrickletRotaryPoti RotaryPoti Bricklet
 */

/**
 * \ingroup BrickletRotaryPoti
 *
 * Device for sensing Rotary Potentiometer input
 */
typedef Device RotaryPoti;

/**
 * \ingroup BrickletRotaryPoti
 *
 * This callback is triggered periodically with the period that is set by
 * {@link rotary_poti_set_position_callback_period}. The parameter is the position of the
 * Rotary Potentiometer.
 * 
 * {@link ROTARY_POTI_CALLBACK_POSITION} is only triggered if the position has changed since the
 * last triggering.
 */
#define ROTARY_POTI_CALLBACK_POSITION 13

/**
 * \ingroup BrickletRotaryPoti
 *
 * This callback is triggered periodically with the period that is set by
 * {@link rotary_poti_set_analog_value_callback_period}. The parameter is the analog value of the
 * Rotary Potentiometer.
 * 
 * {@link ROTARY_POTI_CALLBACK_ANALOG_VALUE} is only triggered if the position has changed since the
 * last triggering.
 */
#define ROTARY_POTI_CALLBACK_ANALOG_VALUE 14

/**
 * \ingroup BrickletRotaryPoti
 *
 * This callback is triggered when the threshold as set by
 * {@link rotary_poti_set_position_callback_threshold} is reached.
 * The parameter is the position of the Rotary Potentiometer.
 * 
 * If the threshold keeps being reached, the callback is triggered periodically
 * with the period as set by {@link rotary_poti_set_debounce_period}.
 */
#define ROTARY_POTI_CALLBACK_POSITION_REACHED 15

/**
 * \ingroup BrickletRotaryPoti
 *
 * This callback is triggered when the threshold as set by
 * {@link rotary_poti_set_analog_value_callback_threshold} is reached.
 * The parameter is the analog value of the Rotary Potentiometer.
 * 
 * If the threshold keeps being reached, the callback is triggered periodically
 * with the period as set by {@link rotary_poti_set_debounce_period}.
 */
#define ROTARY_POTI_CALLBACK_ANALOG_VALUE_REACHED 16

/**
 * \ingroup BrickletRotaryPoti
 *
 * Creates an object with the unique device ID \c uid. This object can then be
 * added to the IP connection.
 */
void rotary_poti_create(RotaryPoti *rotary_poti, const char *uid);

/**
 * \ingroup BrickletRotaryPoti
 *
 * Returns the position of the Rotary Potentiometer. The value is in degree 
 * and between -150° (turned left) and 150° (turned right).
 * 
 * If you want to get the position periodically, it is recommended to use the
 * callback {@link ROTARY_POTI_CALLBACK_POSITION} and set the period with 
 * {@link rotary_poti_set_position_callback_period}.
 */
int rotary_poti_get_position(RotaryPoti *rotary_poti, int16_t *ret_position);

/**
 * \ingroup BrickletRotaryPoti
 *
 * Returns the value as read by a 12 bit analog to digital converter.
 * The value is between 0 and 4095.
 * 
 *  \note
 *   The value returned by {@link rotary_poti_get_position} is averaged over several samples
 *   to yield less noise, while {@link rotary_poti_get_analog_value} gives back raw
 *   unfiltered analog values. The only reason to use {@link rotary_poti_get_analog_value} is,
 *   if you need the full resolution of the analog to digital converter.
 * 
 * If you want the analog value periodically, it is recommended to use the 
 * callback {@link ROTARY_POTI_CALLBACK_ANALOG_VALUE} and set the period with 
 * {@link rotary_poti_set_analog_value_callback_period}.
 */
int rotary_poti_get_analog_value(RotaryPoti *rotary_poti, uint16_t *ret_value);

/**
 * \ingroup BrickletRotaryPoti
 *
 * Sets the period in ms with which the {@link ROTARY_POTI_CALLBACK_POSITION} callback is triggered
 * periodically. A value of 0 turns the callback off.
 * 
 * {@link ROTARY_POTI_CALLBACK_POSITION} is only triggered if the position has changed since the
 * last triggering.
 * 
 * The default value is 0.
 */
int rotary_poti_set_position_callback_period(RotaryPoti *rotary_poti, uint32_t period);

/**
 * \ingroup BrickletRotaryPoti
 *
 * Returns the period as set by {@link rotary_poti_set_position_callback_period}.
 */
int rotary_poti_get_position_callback_period(RotaryPoti *rotary_poti, uint32_t *ret_period);

/**
 * \ingroup BrickletRotaryPoti
 *
 * Sets the period in ms with which the {@link ROTARY_POTI_CALLBACK_ANALOG_VALUE} callback is triggered
 * periodically. A value of 0 turns the callback off.
 * 
 * {@link ROTARY_POTI_CALLBACK_ANALOG_VALUE} is only triggered if the analog value has changed since the
 * last triggering.
 * 
 * The default value is 0.
 */
int rotary_poti_set_analog_value_callback_period(RotaryPoti *rotary_poti, uint32_t period);

/**
 * \ingroup BrickletRotaryPoti
 *
 * Returns the period as set by {@link rotary_poti_set_analog_value_callback_period}.
 */
int rotary_poti_get_analog_value_callback_period(RotaryPoti *rotary_poti, uint32_t *ret_period);

/**
 * \ingroup BrickletRotaryPoti
 *
 * Sets the thresholds for the {@link ROTARY_POTI_CALLBACK_POSITION_REACHED} callback. 
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
 * The default value is ('x', 0, 0).
 */
int rotary_poti_set_position_callback_threshold(RotaryPoti *rotary_poti, char option, int16_t min, int16_t max);

/**
 * \ingroup BrickletRotaryPoti
 *
 * Returns the threshold as set by {@link rotary_poti_set_position_callback_threshold}.
 */
int rotary_poti_get_position_callback_threshold(RotaryPoti *rotary_poti, char *ret_option, int16_t *ret_min, int16_t *ret_max);

/**
 * \ingroup BrickletRotaryPoti
 *
 * Sets the thresholds for the {@link ROTARY_POTI_CALLBACK_ANALOG_VALUE_REACHED} callback. 
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
 * The default value is ('x', 0, 0).
 */
int rotary_poti_set_analog_value_callback_threshold(RotaryPoti *rotary_poti, char option, uint16_t min, uint16_t max);

/**
 * \ingroup BrickletRotaryPoti
 *
 * Returns the threshold as set by {@link rotary_poti_set_analog_value_callback_threshold}.
 */
int rotary_poti_get_analog_value_callback_threshold(RotaryPoti *rotary_poti, char *ret_option, uint16_t *ret_min, uint16_t *ret_max);

/**
 * \ingroup BrickletRotaryPoti
 *
 * Sets the period in ms with which the threshold callbacks
 * 
 *  {@link ROTARY_POTI_CALLBACK_POSITION_REACHED}, {@link ROTARY_POTI_CALLBACK_ANALOG_VALUE_REACHED}
 * 
 * are triggered, if the thresholds
 * 
 *  {@link rotary_poti_set_position_callback_threshold}, {@link rotary_poti_set_analog_value_callback_threshold}
 * 
 * keep being reached.
 * 
 * The default value is 100.
 */
int rotary_poti_set_debounce_period(RotaryPoti *rotary_poti, uint32_t debounce);

/**
 * \ingroup BrickletRotaryPoti
 *
 * Returns the debounce period as set by {@link rotary_poti_set_debounce_period}.
 */
int rotary_poti_get_debounce_period(RotaryPoti *rotary_poti, uint32_t *ret_debounce);

/**
 * \ingroup BrickletRotaryPoti
 *
 * Returns the name (including the hardware version), the firmware version
 * and the binding version of the device. The firmware and binding versions are
 * given in arrays of size 3 with the syntax [major, minor, revision].
 */
int rotary_poti_get_version(RotaryPoti *rotary_poti, char ret_name[40], uint8_t ret_firmware_version[3], uint8_t ret_binding_version[3]);

/**
 * \ingroup BrickletRotaryPoti
 *
 * Registers a callback with ID \c cb to the function \c func.
 */
void rotary_poti_register_callback(RotaryPoti *rotary_poti, uint8_t cb, void *func);

#endif
