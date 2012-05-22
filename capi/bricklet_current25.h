/* ***********************************************************
 * This file was automatically generated on 2012-05-21.      *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generator git on tinkerforge.com                   *
 *************************************************************/

#ifndef BRICKLET_CURRENT25_H
#define BRICKLET_CURRENT25_H

#include "ip_connection.h"

/**
 * \defgroup BrickletCurrent25 Current25 Bricklet
 */

/**
 * \ingroup BrickletCurrent25
 *
 * Device for sensing current of up to 25A
 */
typedef Device Current25;

/**
 * \ingroup BrickletCurrent25
 *
 * This callback is triggered periodically with the period that is set by
 * {@link current25_set_current_callback_period}. The parameter is the current of the
 * sensor.
 * 
 * {@link CURRENT25_CALLBACK_CURRENT} is only triggered if the current has changed since the
 * last triggering.
 */
#define CURRENT25_CALLBACK_CURRENT 15

/**
 * \ingroup BrickletCurrent25
 *
 * This callback is triggered periodically with the period that is set by
 * {@link current25_set_analog_value_callback_period}. The parameter is the analog value of the
 * sensor.
 * 
 * {@link CURRENT25_CALLBACK_ANALOG_VALUE} is only triggered if the current has changed since the
 * last triggering.
 */
#define CURRENT25_CALLBACK_ANALOG_VALUE 16

/**
 * \ingroup BrickletCurrent25
 *
 * This callback is triggered when the threshold as set by
 * {@link current25_set_current_callback_threshold} is reached.
 * The parameter is the current of the sensor.
 * 
 * If the threshold keeps being reached, the callback is triggered periodically
 * with the period as set by {@link current25_set_debounce_period}.
 */
#define CURRENT25_CALLBACK_CURRENT_REACHED 17

/**
 * \ingroup BrickletCurrent25
 *
 * This callback is triggered when the threshold as set by
 * {@link current25_set_analog_value_callback_threshold} is reached.
 * The parameter is the analog value of the sensor.
 * 
 * If the threshold keeps being reached, the callback is triggered periodically
 * with the period as set by {@link current25_set_debounce_period}.
 */
#define CURRENT25_CALLBACK_ANALOG_VALUE_REACHED 18

/**
 * \ingroup BrickletCurrent25
 *
 * This callback is triggered when an over current is measured
 * (see {@link current25_is_over_current}).
 */
#define CURRENT25_CALLBACK_OVER_CURRENT 19

/**
 * \ingroup BrickletCurrent25
 *
 * Creates an object with the unique device ID \c uid. This object can then be
 * added to the IP connection.
 */
void current25_create(Current25 *current25, const char *uid);

/**
 * \ingroup BrickletCurrent25
 *
 * Returns the current of the sensor. The value is in mA
 * and between -25000mA and 25000mA.
 * 
 * If you want to get the current periodically, it is recommended to use the
 * callback {@link CURRENT25_CALLBACK_CURRENT} and set the period with 
 * {@link current25_set_current_callback_period}.
 */
int current25_get_current(Current25 *current25, int16_t *ret_current);

/**
 * \ingroup BrickletCurrent25
 *
 * Calibrates the 0 value of the sensor. You have to call this function
 * when there is no current present. 
 * 
 * The zero point of the current sensor
 * is depending on the exact properties of the analog to digital converter,
 * the length of the Bricklet cable and the temperature. Thus, if you change
 * the Brick or the environment in which the Bricklet is used, you might
 * have to recalibrate.
 * 
 * The resulting calibration will be saved on the EEPROM of the Current
 * Bricklet.
 */
int current25_calibrate(Current25 *current25);

/**
 * \ingroup BrickletCurrent25
 *
 * Returns true if more than 25A were measured.
 * 
 *  \note
 *   To reset this value you have to power cycle the Bricklet.
 */
int current25_is_over_current(Current25 *current25, bool *ret_over);

/**
 * \ingroup BrickletCurrent25
 *
 * Returns the value as read by a 12 bit analog to digital converter.
 * The value is between 0 and 4095.
 * 
 *  \note
 *   The value returned by {@link current25_get_current} is averaged over several samples
 *   to yield less noise, while {@link current25_get_analog_value} gives back raw
 *   unfiltered analog values. The only reason to use {@link current25_get_analog_value} is,
 *   if you need the full resolution of the analog to digital converter.
 * 
 * If you want the analog value periodically, it is recommended to use the 
 * callback {@link CURRENT25_CALLBACK_ANALOG_VALUE} and set the period with 
 * {@link current25_set_analog_value_callback_period}.
 */
int current25_get_analog_value(Current25 *current25, uint16_t *ret_value);

/**
 * \ingroup BrickletCurrent25
 *
 * Sets the period in ms with which the {@link CURRENT25_CALLBACK_CURRENT} callback is triggered
 * periodically. A value of 0 turns the callback off.
 * 
 * {@link CURRENT25_CALLBACK_CURRENT} is only triggered if the current has changed since the
 * last triggering.
 * 
 * The default value is 0.
 */
int current25_set_current_callback_period(Current25 *current25, uint32_t period);

/**
 * \ingroup BrickletCurrent25
 *
 * Returns the period as set by {@link current25_set_current_callback_period}.
 */
int current25_get_current_callback_period(Current25 *current25, uint32_t *ret_period);

/**
 * \ingroup BrickletCurrent25
 *
 * Sets the period in ms with which the {@link CURRENT25_CALLBACK_ANALOG_VALUE} callback is triggered
 * periodically. A value of 0 turns the callback off.
 * 
 * {@link CURRENT25_CALLBACK_ANALOG_VALUE} is only triggered if the analog value has changed since the
 * last triggering.
 * 
 * The default value is 0.
 */
int current25_set_analog_value_callback_period(Current25 *current25, uint32_t period);

/**
 * \ingroup BrickletCurrent25
 *
 * Returns the period as set by {@link current25_set_analog_value_callback_period}.
 */
int current25_get_analog_value_callback_period(Current25 *current25, uint32_t *ret_period);

/**
 * \ingroup BrickletCurrent25
 *
 * Sets the thresholds for the {@link CURRENT25_CALLBACK_CURRENT_REACHED} callback. 
 * 
 * The following options are possible:
 * 
 * \verbatim
 *  :header: "Option", "Description"
 *  :widths: 10, 100
 *  "'x'", "Callback is turned off."
 *  "'o'", "Callback is triggered when the current is *outside* the min and max values"
 *  "'i'", "Callback is triggered when the current is *inside* the min and max values"
 *  "'<'", "Callback is triggered when the current is smaller than the min value (max is ignored)"
 *  "'>'", "Callback is triggered when the current is greater than the min value (max is ignored)"
 * \endverbatim
 * 
 * The default value is ('x', 0, 0).
 */
int current25_set_current_callback_threshold(Current25 *current25, char option, int16_t min, int16_t max);

/**
 * \ingroup BrickletCurrent25
 *
 * Returns the threshold as set by {@link current25_set_current_callback_threshold}.
 */
int current25_get_current_callback_threshold(Current25 *current25, char *ret_option, int16_t *ret_min, int16_t *ret_max);

/**
 * \ingroup BrickletCurrent25
 *
 * Sets the thresholds for the {@link CURRENT25_CALLBACK_ANALOG_VALUE_REACHED} callback. 
 * 
 * The following options are possible:
 * 
 * \verbatim
 *  :header: "Option", "Description"
 *  :widths: 10, 100
 *  "'x'", "Callback is turned off."
 *  "'o'", "Callback is triggered when the current is *outside* the min and max values"
 *  "'i'", "Callback is triggered when the current is *inside* the min and max values"
 *  "'<'", "Callback is triggered when the current is smaller than the min value (max is ignored)"
 *  "'>'", "Callback is triggered when the current is greater than the min value (max is ignored)"
 * \endverbatim
 * 
 * The default value is ('x', 0, 0).
 */
int current25_set_analog_value_callback_threshold(Current25 *current25, char option, uint16_t min, uint16_t max);

/**
 * \ingroup BrickletCurrent25
 *
 * Returns the threshold as set by {@link current25_set_analog_value_callback_threshold}.
 */
int current25_get_analog_value_callback_threshold(Current25 *current25, char *ret_option, uint16_t *ret_min, uint16_t *ret_max);

/**
 * \ingroup BrickletCurrent25
 *
 * Sets the period in ms with which the threshold callbacks
 * 
 *  {@link CURRENT25_CALLBACK_CURRENT_REACHED}, {@link CURRENT25_CALLBACK_ANALOG_VALUE_REACHED}
 * 
 * are triggered, if the thresholds
 * 
 *  {@link current25_set_current_callback_threshold}, {@link current25_set_analog_value_callback_threshold}
 * 
 * keep being reached.
 * 
 * The default value is 100.
 */
int current25_set_debounce_period(Current25 *current25, uint32_t debounce);

/**
 * \ingroup BrickletCurrent25
 *
 * Returns the debounce period as set by {@link current25_set_debounce_period}.
 */
int current25_get_debounce_period(Current25 *current25, uint32_t *ret_debounce);

/**
 * \ingroup BrickletCurrent25
 *
 * Returns the name (including the hardware version), the firmware version
 * and the binding version of the device. The firmware and binding versions are
 * given in arrays of size 3 with the syntax [major, minor, revision].
 */
int current25_get_version(Current25 *current25, char ret_name[40], uint8_t ret_firmware_version[3], uint8_t ret_binding_version[3]);

/**
 * \ingroup BrickletCurrent25
 *
 * Registers a callback with ID \c cb to the function \c func.
 */
void current25_register_callback(Current25 *current25, uint8_t cb, void *func);

#endif
