/* ***********************************************************
 * This file was automatically generated on 2012-05-21.      *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generator git on tinkerforge.com                   *
 *************************************************************/

#ifndef BRICKLET_TEMPERATURE_H
#define BRICKLET_TEMPERATURE_H

#include "ip_connection.h"

/**
 * \defgroup BrickletTemperature Temperature Bricklet
 */

/**
 * \ingroup BrickletTemperature
 *
 * Device for sensing Temperature
 */
typedef Device Temperature;

/**
 * \ingroup BrickletTemperature
 *
 * This callback is triggered periodically with the period that is set by
 * {@link temperature_set_temperature_callback_period}. The parameter is the temperature
 * of the sensor.
 * 
 * {@link TEMPERATURE_CALLBACK_TEMPERATURE} is only triggered if the temperature has changed since the
 * last triggering.
 */
#define TEMPERATURE_CALLBACK_TEMPERATURE 8

/**
 * \ingroup BrickletTemperature
 *
 * This callback is triggered when the threshold as set by
 * {@link temperature_set_temperature_callback_threshold} is reached.
 * The parameter is the temperature of the sensor.
 * 
 * If the threshold keeps being reached, the callback is triggered periodically
 * with the period as set by {@link temperature_set_debounce_period}.
 */
#define TEMPERATURE_CALLBACK_TEMPERATURE_REACHED 9

/**
 * \ingroup BrickletTemperature
 *
 * Creates an object with the unique device ID \c uid. This object can then be
 * added to the IP connection.
 */
void temperature_create(Temperature *temperature, const char *uid);

/**
 * \ingroup BrickletTemperature
 *
 * Returns the temperature of the sensor. The value
 * has a range of -2500 to 8500 and is given in °C/100,
 * e.g. a value of 4223 means that a temperature of 42.23 °C is measured.
 * 
 * If you want to get the temperature periodically, it is recommended 
 * to use the callback {@link TEMPERATURE_CALLBACK_TEMPERATURE} and set the period with 
 * {@link temperature_set_temperature_callback_period}.
 */
int temperature_get_temperature(Temperature *temperature, int16_t *ret_temperature);

/**
 * \ingroup BrickletTemperature
 *
 * Sets the period in ms with which the {@link TEMPERATURE_CALLBACK_TEMPERATURE} callback is triggered
 * periodically. A value of 0 turns the callback off.
 * 
 * {@link TEMPERATURE_CALLBACK_TEMPERATURE} is only triggered if the temperature has changed since the
 * last triggering.
 * 
 * The default value is 0.
 */
int temperature_set_temperature_callback_period(Temperature *temperature, uint32_t period);

/**
 * \ingroup BrickletTemperature
 *
 * Returns the period as set by {@link temperature_set_temperature_callback_period}.
 */
int temperature_get_temperature_callback_period(Temperature *temperature, uint32_t *ret_period);

/**
 * \ingroup BrickletTemperature
 *
 * Sets the thresholds for the {@link TEMPERATURE_CALLBACK_TEMPERATURE_REACHED} callback. 
 * 
 * The following options are possible:
 * 
 * \verbatim
 *  :header: "Option", "Description"
 *  :widths: 10, 100
 *  "'x'", "Callback is turned off."
 *  "'o'", "Callback is triggered when the temperature is *outside* the min and max values"
 *  "'i'", "Callback is triggered when the temperature is *inside* the min and max values"
 *  "'<'", "Callback is triggered when the temperature is smaller than the min value (max is ignored)"
 *  "'>'", "Callback is triggered when the temperature is greater than the min value (max is ignored)"
 * \endverbatim
 * 
 * The default value is ('x', 0, 0).
 */
int temperature_set_temperature_callback_threshold(Temperature *temperature, char option, int16_t min, int16_t max);

/**
 * \ingroup BrickletTemperature
 *
 * Returns the threshold as set by {@link temperature_set_temperature_callback_threshold}.
 */
int temperature_get_temperature_callback_threshold(Temperature *temperature, char *ret_option, int16_t *ret_min, int16_t *ret_max);

/**
 * \ingroup BrickletTemperature
 *
 * Sets the period in ms with which the threshold callback
 * 
 *  {@link TEMPERATURE_CALLBACK_TEMPERATURE_REACHED}
 * 
 * is triggered, if the threshold
 * 
 *  {@link temperature_set_temperature_callback_threshold}
 * 
 * keeps being reached.
 * 
 * The default value is 100.
 */
int temperature_set_debounce_period(Temperature *temperature, uint32_t debounce);

/**
 * \ingroup BrickletTemperature
 *
 * Returns the debounce period as set by {@link temperature_set_debounce_period}.
 */
int temperature_get_debounce_period(Temperature *temperature, uint32_t *ret_debounce);

/**
 * \ingroup BrickletTemperature
 *
 * Returns the name (including the hardware version), the firmware version
 * and the binding version of the device. The firmware and binding versions are
 * given in arrays of size 3 with the syntax [major, minor, revision].
 */
int temperature_get_version(Temperature *temperature, char ret_name[40], uint8_t ret_firmware_version[3], uint8_t ret_binding_version[3]);

/**
 * \ingroup BrickletTemperature
 *
 * Registers a callback with ID \c cb to the function \c func.
 */
void temperature_register_callback(Temperature *temperature, uint8_t cb, void *func);

#endif
