/* ***********************************************************
 * This file was automatically generated on 2012-05-21.      *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generator git on tinkerforge.com                   *
 *************************************************************/

#ifndef BRICKLET_ANALOG_IN_H
#define BRICKLET_ANALOG_IN_H

#include "ip_connection.h"

/**
 * \defgroup BrickletAnalogIn AnalogIn Bricklet
 */

/**
 * \ingroup BrickletAnalogIn
 *
 * Device for sensing Voltages between 0 and 45V
 */
typedef Device AnalogIn;

/**
 * \ingroup BrickletAnalogIn
 *
 * This callback is triggered periodically with the period that is set by
 * {@link analog_in_set_voltage_callback_period}. The parameter is the voltage of the
 * sensor.
 * 
 * {@link ANALOG_IN_CALLBACK_VOLTAGE} is only triggered if the voltage has changed since the
 * last triggering.
 */
#define ANALOG_IN_CALLBACK_VOLTAGE 13

/**
 * \ingroup BrickletAnalogIn
 *
 * This callback is triggered periodically with the period that is set by
 * {@link analog_in_set_analog_value_callback_period}. The parameter is the analog value of the
 * sensor.
 * 
 * {@link ANALOG_IN_CALLBACK_ANALOG_VALUE} is only triggered if the voltage has changed since the
 * last triggering.
 */
#define ANALOG_IN_CALLBACK_ANALOG_VALUE 14

/**
 * \ingroup BrickletAnalogIn
 *
 * This callback is triggered when the threshold as set by
 * {@link analog_in_set_voltage_callback_threshold} is reached.
 * The parameter is the voltage of the sensor.
 * 
 * If the threshold keeps being reached, the callback is triggered periodically
 * with the period as set by {@link analog_in_set_debounce_period}.
 */
#define ANALOG_IN_CALLBACK_VOLTAGE_REACHED 15

/**
 * \ingroup BrickletAnalogIn
 *
 * This callback is triggered when the threshold as set by
 * {@link analog_in_set_analog_value_callback_threshold} is reached.
 * The parameter is the analog value of the sensor.
 * 
 * If the threshold keeps being reached, the callback is triggered periodically
 * with the period as set by {@link analog_in_set_debounce_period}.
 */
#define ANALOG_IN_CALLBACK_ANALOG_VALUE_REACHED 16

/**
 * \ingroup BrickletAnalogIn
 *
 * Creates an object with the unique device ID \c uid. This object can then be
 * added to the IP connection.
 */
void analog_in_create(AnalogIn *analog_in, const char *uid);

/**
 * \ingroup BrickletAnalogIn
 *
 * Returns the voltage of the sensor. The value is in mV and
 * between 0V and 45V. The resolution between 0 and 6V is about 2mV.
 * Between 6 and 45V the resolution is about 10mV.
 * 
 * If you want to get the voltage periodically, it is recommended to use the
 * callback {@link ANALOG_IN_CALLBACK_VOLTAGE} and set the period with 
 * {@link analog_in_set_voltage_callback_period}.
 */
int analog_in_get_voltage(AnalogIn *analog_in, uint16_t *ret_voltage);

/**
 * \ingroup BrickletAnalogIn
 *
 * Returns the value as read by a 12 bit analog to digital converter.
 * The value is between 0 and 4095.
 * 
 *  \note
 *   The value returned by {@link analog_in_get_voltage} is averaged over several samples
 *   to yield less noise, while {@link analog_in_get_analog_value} gives back raw
 *   unfiltered analog values. The only reason to use {@link analog_in_get_analog_value} is,
 *   if you need the full resolution of the analog to digital converter.
 * 
 * If you want the analog value periodically, it is recommended to use the 
 * callback {@link ANALOG_IN_CALLBACK_ANALOG_VALUE} and set the period with 
 * {@link analog_in_set_analog_value_callback_period}.
 */
int analog_in_get_analog_value(AnalogIn *analog_in, uint16_t *ret_value);

/**
 * \ingroup BrickletAnalogIn
 *
 * Sets the period in ms with which the {@link ANALOG_IN_CALLBACK_VOLTAGE} callback is triggered
 * periodically. A value of 0 turns the callback off.
 * 
 * {@link ANALOG_IN_CALLBACK_VOLTAGE} is only triggered if the voltage has changed since the
 * last triggering.
 * 
 * The default value is 0.
 */
int analog_in_set_voltage_callback_period(AnalogIn *analog_in, uint32_t period);

/**
 * \ingroup BrickletAnalogIn
 *
 * Returns the period as set by {@link analog_in_set_voltage_callback_period}.
 */
int analog_in_get_voltage_callback_period(AnalogIn *analog_in, uint32_t *ret_period);

/**
 * \ingroup BrickletAnalogIn
 *
 * Sets the period in ms with which the {@link ANALOG_IN_CALLBACK_ANALOG_VALUE} callback is triggered
 * periodically. A value of 0 turns the callback off.
 * 
 * {@link ANALOG_IN_CALLBACK_ANALOG_VALUE} is only triggered if the analog value has changed since the
 * last triggering.
 * 
 * The default value is 0.
 */
int analog_in_set_analog_value_callback_period(AnalogIn *analog_in, uint32_t period);

/**
 * \ingroup BrickletAnalogIn
 *
 * Returns the period as set by {@link analog_in_set_analog_value_callback_period}.
 */
int analog_in_get_analog_value_callback_period(AnalogIn *analog_in, uint32_t *ret_period);

/**
 * \ingroup BrickletAnalogIn
 *
 * Sets the thresholds for the {@link ANALOG_IN_CALLBACK_VOLTAGE_REACHED} callback. 
 * 
 * The following options are possible:
 * 
 * \verbatim
 *  :header: "Option", "Description"
 *  :widths: 10, 100
 *  "'x'", "Callback is turned off."
 *  "'o'", "Callback is triggered when the voltage is *outside* the min and max values"
 *  "'i'", "Callback is triggered when the voltage is *inside* the min and max values"
 *  "'<'", "Callback is triggered when the voltage is smaller than the min value (max is ignored)"
 *  "'>'", "Callback is triggered when the voltage is greater than the min value (max is ignored)"
 * \endverbatim
 * 
 * The default value is ('x', 0, 0).
 */
int analog_in_set_voltage_callback_threshold(AnalogIn *analog_in, char option, int16_t min, int16_t max);

/**
 * \ingroup BrickletAnalogIn
 *
 * Returns the threshold as set by {@link analog_in_set_voltage_callback_threshold}.
 */
int analog_in_get_voltage_callback_threshold(AnalogIn *analog_in, char *ret_option, int16_t *ret_min, int16_t *ret_max);

/**
 * \ingroup BrickletAnalogIn
 *
 * Sets the thresholds for the {@link ANALOG_IN_CALLBACK_ANALOG_VALUE_REACHED} callback. 
 * 
 * The following options are possible:
 * 
 * \verbatim
 *  :header: "Option", "Description"
 *  :widths: 10, 100
 *  "'x'", "Callback is turned off."
 *  "'o'", "Callback is triggered when the voltage is *outside* the min and max values"
 *  "'i'", "Callback is triggered when the voltage is *inside* the min and max values"
 *  "'<'", "Callback is triggered when the voltage is smaller than the min value (max is ignored)"
 *  "'>'", "Callback is triggered when the voltage is greater than the min value (max is ignored)"
 * \endverbatim
 * 
 * The default value is ('x', 0, 0).
 */
int analog_in_set_analog_value_callback_threshold(AnalogIn *analog_in, char option, uint16_t min, uint16_t max);

/**
 * \ingroup BrickletAnalogIn
 *
 * Returns the threshold as set by {@link analog_in_set_analog_value_callback_threshold}.
 */
int analog_in_get_analog_value_callback_threshold(AnalogIn *analog_in, char *ret_option, uint16_t *ret_min, uint16_t *ret_max);

/**
 * \ingroup BrickletAnalogIn
 *
 * Sets the period in ms with which the threshold callbacks
 * 
 *  {@link ANALOG_IN_CALLBACK_VOLTAGE_REACHED}, {@link ANALOG_IN_CALLBACK_ANALOG_VALUE_REACHED}
 * 
 * are triggered, if the thresholds
 * 
 *  {@link analog_in_set_voltage_callback_threshold}, {@link analog_in_set_analog_value_callback_threshold}
 * 
 * keep being reached.
 * 
 * The default value is 100.
 */
int analog_in_set_debounce_period(AnalogIn *analog_in, uint32_t debounce);

/**
 * \ingroup BrickletAnalogIn
 *
 * Returns the debounce period as set by {@link analog_in_set_debounce_period}.
 */
int analog_in_get_debounce_period(AnalogIn *analog_in, uint32_t *ret_debounce);

/**
 * \ingroup BrickletAnalogIn
 *
 * Returns the name (including the hardware version), the firmware version
 * and the binding version of the device. The firmware and binding versions are
 * given in arrays of size 3 with the syntax [major, minor, revision].
 */
int analog_in_get_version(AnalogIn *analog_in, char ret_name[40], uint8_t ret_firmware_version[3], uint8_t ret_binding_version[3]);

/**
 * \ingroup BrickletAnalogIn
 *
 * Registers a callback with ID \c cb to the function \c func.
 */
void analog_in_register_callback(AnalogIn *analog_in, uint8_t cb, void *func);

#endif
