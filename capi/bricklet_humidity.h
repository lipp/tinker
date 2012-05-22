/* ***********************************************************
 * This file was automatically generated on 2012-05-21.      *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generator git on tinkerforge.com                   *
 *************************************************************/

#ifndef BRICKLET_HUMIDITY_H
#define BRICKLET_HUMIDITY_H

#include "ip_connection.h"

/**
 * \defgroup BrickletHumidity Humidity Bricklet
 */

/**
 * \ingroup BrickletHumidity
 *
 * Device for sensing Humidity
 */
typedef Device Humidity;

/**
 * \ingroup BrickletHumidity
 *
 * This callback is triggered periodically with the period that is set by
 * {@link humidity_set_humidity_callback_period}. The parameter is the humidity of the
 * sensor.
 * 
 * {@link HUMIDITY_CALLBACK_HUMIDITY} is only triggered if the humidity has changed since the
 * last triggering.
 */
#define HUMIDITY_CALLBACK_HUMIDITY 13

/**
 * \ingroup BrickletHumidity
 *
 * This callback is triggered periodically with the period that is set by
 * {@link humidity_set_analog_value_callback_period}. The parameter is the analog value of the
 * sensor.
 * 
 * {@link HUMIDITY_CALLBACK_ANALOG_VALUE} is only triggered if the humidity has changed since the
 * last triggering.
 */
#define HUMIDITY_CALLBACK_ANALOG_VALUE 14

/**
 * \ingroup BrickletHumidity
 *
 * This callback is triggered when the threshold as set by
 * {@link humidity_set_humidity_callback_threshold} is reached.
 * The parameter is the humidity of the sensor.
 * 
 * If the threshold keeps being reached, the callback is triggered periodically
 * with the period as set by {@link humidity_set_debounce_period}.
 */
#define HUMIDITY_CALLBACK_HUMIDITY_REACHED 15

/**
 * \ingroup BrickletHumidity
 *
 * This callback is triggered when the threshold as set by
 * {@link humidity_set_analog_value_callback_threshold} is reached.
 * The parameter is the analog value of the sensor.
 * 
 * If the threshold keeps being reached, the callback is triggered periodically
 * with the period as set by {@link humidity_set_debounce_period}.
 */
#define HUMIDITY_CALLBACK_ANALOG_VALUE_REACHED 16

/**
 * \ingroup BrickletHumidity
 *
 * Creates an object with the unique device ID \c uid. This object can then be
 * added to the IP connection.
 */
void humidity_create(Humidity *humidity, const char *uid);

/**
 * \ingroup BrickletHumidity
 *
 * Returns the humidity of the sensor. The value
 * has a range of 0 to 1000 and is given in %RH/10 (Relative Humidity), 
 * i.e. a value of 421 means that a humidity of 42.1 %RH is measured.
 * 
 * If you want to get the humidity periodically, it is recommended to use the
 * callback {@link HUMIDITY_CALLBACK_HUMIDITY} and set the period with 
 * {@link humidity_set_humidity_callback_period}.
 */
int humidity_get_humidity(Humidity *humidity, uint16_t *ret_humidity);

/**
 * \ingroup BrickletHumidity
 *
 * Returns the value as read by a 12 bit analog to digital converter.
 * The value is between 0 and 4095.
 * 
 *  \note
 *   The value returned by {@link humidity_get_humidity} is averaged over several samples
 *   to yield less noise, while {@link humidity_get_analog_value} gives back raw
 *   unfiltered analog values. The returned humidity value is calibrated for
 *   room temperatures, if you use the sensor in extreme cold or extreme
 *   warm environments, you might want to calculate the humidity from
 *   the analog value yourself. See the `HIH 5030 datasheet
 *   <https://github.com/Tinkerforge/humidity-bricklet/raw/master/datasheets/hih-5030.pdf>`__.
 * 
 * If you want the analog value periodically, it is recommended to use the 
 * callback {@link HUMIDITY_CALLBACK_ANALOG_VALUE} and set the period with 
 * {@link humidity_set_analog_value_callback_period}.
 */
int humidity_get_analog_value(Humidity *humidity, uint16_t *ret_value);

/**
 * \ingroup BrickletHumidity
 *
 * Sets the period in ms with which the {@link HUMIDITY_CALLBACK_HUMIDITY} callback is triggered
 * periodically. A value of 0 turns the callback off.
 * 
 * {@link HUMIDITY_CALLBACK_HUMIDITY} is only triggered if the humidity has changed since the
 * last triggering.
 * 
 * The default value is 0.
 */
int humidity_set_humidity_callback_period(Humidity *humidity, uint32_t period);

/**
 * \ingroup BrickletHumidity
 *
 * Returns the period as set by {@link humidity_set_humidity_callback_period}.
 */
int humidity_get_humidity_callback_period(Humidity *humidity, uint32_t *ret_period);

/**
 * \ingroup BrickletHumidity
 *
 * Sets the period in ms with which the {@link HUMIDITY_CALLBACK_ANALOG_VALUE} callback is triggered
 * periodically. A value of 0 turns the callback off.
 * 
 * {@link HUMIDITY_CALLBACK_ANALOG_VALUE} is only triggered if the analog value has changed since the
 * last triggering.
 * 
 * The default value is 0.
 */
int humidity_set_analog_value_callback_period(Humidity *humidity, uint32_t period);

/**
 * \ingroup BrickletHumidity
 *
 * Returns the period as set by {@link humidity_set_analog_value_callback_period}.
 */
int humidity_get_analog_value_callback_period(Humidity *humidity, uint32_t *ret_period);

/**
 * \ingroup BrickletHumidity
 *
 * Sets the thresholds for the {@link HUMIDITY_CALLBACK_HUMIDITY_REACHED} callback. 
 * 
 * The following options are possible:
 * 
 * \verbatim
 *  :header: "Option", "Description"
 *  :widths: 10, 100
 *  "'x'", "Callback is turned off."
 *  "'o'", "Callback is triggered when the humidity is *outside* the min and max values"
 *  "'i'", "Callback is triggered when the humidity is *inside* the min and max values"
 *  "'<'", "Callback is triggered when the humidity is smaller than the min value (max is ignored)"
 *  "'>'", "Callback is triggered when the humidity is greater than the min value (max is ignored)"
 * \endverbatim
 * 
 * The default value is ('x', 0, 0).
 */
int humidity_set_humidity_callback_threshold(Humidity *humidity, char option, int16_t min, int16_t max);

/**
 * \ingroup BrickletHumidity
 *
 * Returns the threshold as set by {@link humidity_set_humidity_callback_threshold}.
 */
int humidity_get_humidity_callback_threshold(Humidity *humidity, char *ret_option, int16_t *ret_min, int16_t *ret_max);

/**
 * \ingroup BrickletHumidity
 *
 * Sets the thresholds for the {@link HUMIDITY_CALLBACK_ANALOG_VALUE_REACHED} callback. 
 * 
 * The following options are possible:
 * 
 * \verbatim
 *  :header: "Option", "Description"
 *  :widths: 10, 100
 *  "'x'", "Callback is turned off."
 *  "'o'", "Callback is triggered when the humidity is *outside* the min and max values"
 *  "'i'", "Callback is triggered when the humidity is *inside* the min and max values"
 *  "'<'", "Callback is triggered when the humidity is smaller than the min value (max is ignored)"
 *  "'>'", "Callback is triggered when the humidity is greater than the min value (max is ignored)"
 * \endverbatim
 * 
 * The default value is ('x', 0, 0).
 */
int humidity_set_analog_value_callback_threshold(Humidity *humidity, char option, uint16_t min, uint16_t max);

/**
 * \ingroup BrickletHumidity
 *
 * Returns the threshold as set by {@link humidity_set_analog_value_callback_threshold}.
 */
int humidity_get_analog_value_callback_threshold(Humidity *humidity, char *ret_option, uint16_t *ret_min, uint16_t *ret_max);

/**
 * \ingroup BrickletHumidity
 *
 * Sets the period in ms with which the threshold callbacks
 * 
 *  {@link HUMIDITY_CALLBACK_HUMIDITY_REACHED}, {@link HUMIDITY_CALLBACK_ANALOG_VALUE_REACHED}
 * 
 * are triggered, if the thresholds
 * 
 *  {@link humidity_set_humidity_callback_threshold}, {@link humidity_set_analog_value_callback_threshold}
 * 
 * keep being reached.
 * 
 * The default value is 100.
 */
int humidity_set_debounce_period(Humidity *humidity, uint32_t debounce);

/**
 * \ingroup BrickletHumidity
 *
 * Returns the debounce period as set by {@link humidity_set_debounce_period}.
 */
int humidity_get_debounce_period(Humidity *humidity, uint32_t *ret_debounce);

/**
 * \ingroup BrickletHumidity
 *
 * Returns the name (including the hardware version), the firmware version
 * and the binding version of the device. The firmware and binding versions are
 * given in arrays of size 3 with the syntax [major, minor, revision].
 */
int humidity_get_version(Humidity *humidity, char ret_name[40], uint8_t ret_firmware_version[3], uint8_t ret_binding_version[3]);

/**
 * \ingroup BrickletHumidity
 *
 * Registers a callback with ID \c cb to the function \c func.
 */
void humidity_register_callback(Humidity *humidity, uint8_t cb, void *func);

#endif
