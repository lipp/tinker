/* ***********************************************************
 * This file was automatically generated on 2012-05-21.      *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generator git on tinkerforge.com                   *
 *************************************************************/

#ifndef BRICKLET_VOLTAGE_H
#define BRICKLET_VOLTAGE_H

#include "ip_connection.h"

/**
 * \defgroup BrickletVoltage Voltage Bricklet
 */

/**
 * \ingroup BrickletVoltage
 *
 * Device for sensing Voltages between 0 and 50V
 */
typedef Device Voltage;

/**
 * \ingroup BrickletVoltage
 *
 * This callback is triggered periodically with the period that is set by
 * {@link voltage_set_voltage_callback_period}. The parameter is the voltage of the
 * sensor.
 * 
 * {@link VOLTAGE_CALLBACK_VOLTAGE} is only triggered if the voltage has changed since the
 * last triggering.
 */
#define VOLTAGE_CALLBACK_VOLTAGE 13

/**
 * \ingroup BrickletVoltage
 *
 * This callback is triggered periodically with the period that is set by
 * {@link voltage_set_analog_value_callback_period}. The parameter is the analog value of the
 * sensor.
 * 
 * {@link VOLTAGE_CALLBACK_ANALOG_VALUE} is only triggered if the voltage has changed since the
 * last triggering.
 */
#define VOLTAGE_CALLBACK_ANALOG_VALUE 14

/**
 * \ingroup BrickletVoltage
 *
 * This callback is triggered when the threshold as set by
 * {@link voltage_set_voltage_callback_threshold} is reached.
 * The parameter is the voltage of the sensor.
 * 
 * If the threshold keeps being reached, the callback is triggered periodically
 * with the period as set by {@link voltage_set_debounce_period}.
 */
#define VOLTAGE_CALLBACK_VOLTAGE_REACHED 15

/**
 * \ingroup BrickletVoltage
 *
 * This callback is triggered when the threshold as set by
 * {@link voltage_set_analog_value_callback_threshold} is reached.
 * The parameter is the analog value of the sensor.
 * 
 * If the threshold keeps being reached, the callback is triggered periodically
 * with the period as set by {@link voltage_set_debounce_period}.
 */
#define VOLTAGE_CALLBACK_ANALOG_VALUE_REACHED 16

/**
 * \ingroup BrickletVoltage
 *
 * Creates an object with the unique device ID \c uid. This object can then be
 * added to the IP connection.
 */
void voltage_create(Voltage *voltage, const char *uid);

/**
 * \ingroup BrickletVoltage
 *
 * Returns the voltage of the sensor. The value is in mV and
 * between 0mV and 50000mV.
 * 
 * If you want to get the voltage periodically, it is recommended to use the
 * callback {@link VOLTAGE_CALLBACK_VOLTAGE} and set the period with 
 * {@link voltage_set_voltage_callback_period}.
 */
int voltage_get_voltage(Voltage *voltage, uint16_t *ret_voltage);

/**
 * \ingroup BrickletVoltage
 *
 * Returns the value as read by a 12 bit analog to digital converter.
 * The value is between 0 and 4095.
 * 
 *  \note
 *   The value returned by {@link voltage_get_voltage} is averaged over several samples
 *   to yield less noise, while {@link voltage_get_analog_value} gives back raw
 *   unfiltered analog values. The only reason to use {@link voltage_get_analog_value} is,
 *   if you need the full resolution of the analog to digital converter.
 * 
 * If you want the analog value periodically, it is recommended to use the 
 * callback {@link VOLTAGE_CALLBACK_ANALOG_VALUE} and set the period with 
 * {@link voltage_set_analog_value_callback_period}.
 */
int voltage_get_analog_value(Voltage *voltage, uint16_t *ret_value);

/**
 * \ingroup BrickletVoltage
 *
 * Sets the period in ms with which the {@link VOLTAGE_CALLBACK_VOLTAGE} callback is triggered
 * periodically. A value of 0 turns the callback off.
 * 
 * {@link VOLTAGE_CALLBACK_VOLTAGE} is only triggered if the voltage has changed since the
 * last triggering.
 * 
 * The default value is 0.
 */
int voltage_set_voltage_callback_period(Voltage *voltage, uint32_t period);

/**
 * \ingroup BrickletVoltage
 *
 * Returns the period as set by {@link voltage_set_voltage_callback_period}.
 */
int voltage_get_voltage_callback_period(Voltage *voltage, uint32_t *ret_period);

/**
 * \ingroup BrickletVoltage
 *
 * Sets the period in ms with which the {@link VOLTAGE_CALLBACK_ANALOG_VALUE} callback is triggered
 * periodically. A value of 0 turns the callback off.
 * 
 * {@link VOLTAGE_CALLBACK_ANALOG_VALUE} is only triggered if the analog value has changed since the
 * last triggering.
 * 
 * The default value is 0.
 */
int voltage_set_analog_value_callback_period(Voltage *voltage, uint32_t period);

/**
 * \ingroup BrickletVoltage
 *
 * Returns the period as set by {@link voltage_set_analog_value_callback_period}.
 */
int voltage_get_analog_value_callback_period(Voltage *voltage, uint32_t *ret_period);

/**
 * \ingroup BrickletVoltage
 *
 * Sets the thresholds for the {@link VOLTAGE_CALLBACK_VOLTAGE_REACHED} callback. 
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
int voltage_set_voltage_callback_threshold(Voltage *voltage, char option, int16_t min, int16_t max);

/**
 * \ingroup BrickletVoltage
 *
 * Returns the threshold as set by {@link voltage_set_voltage_callback_threshold}.
 */
int voltage_get_voltage_callback_threshold(Voltage *voltage, char *ret_option, int16_t *ret_min, int16_t *ret_max);

/**
 * \ingroup BrickletVoltage
 *
 * Sets the thresholds for the {@link VOLTAGE_CALLBACK_ANALOG_VALUE_REACHED} callback. 
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
int voltage_set_analog_value_callback_threshold(Voltage *voltage, char option, uint16_t min, uint16_t max);

/**
 * \ingroup BrickletVoltage
 *
 * Returns the threshold as set by {@link voltage_set_analog_value_callback_threshold}.
 */
int voltage_get_analog_value_callback_threshold(Voltage *voltage, char *ret_option, uint16_t *ret_min, uint16_t *ret_max);

/**
 * \ingroup BrickletVoltage
 *
 * Sets the period in ms with which the threshold callbacks
 * 
 *  {@link VOLTAGE_CALLBACK_VOLTAGE_REACHED}, {@link VOLTAGE_CALLBACK_ANALOG_VALUE_REACHED}
 * 
 * are triggered, if the thresholds
 * 
 *  {@link voltage_set_voltage_callback_threshold}, {@link voltage_set_analog_value_callback_threshold}
 * 
 * keep being reached.
 * 
 * The default value is 100.
 */
int voltage_set_debounce_period(Voltage *voltage, uint32_t debounce);

/**
 * \ingroup BrickletVoltage
 *
 * Returns the debounce period as set by {@link voltage_set_debounce_period}.
 */
int voltage_get_debounce_period(Voltage *voltage, uint32_t *ret_debounce);

/**
 * \ingroup BrickletVoltage
 *
 * Returns the name (including the hardware version), the firmware version
 * and the binding version of the device. The firmware and binding versions are
 * given in arrays of size 3 with the syntax [major, minor, revision].
 */
int voltage_get_version(Voltage *voltage, char ret_name[40], uint8_t ret_firmware_version[3], uint8_t ret_binding_version[3]);

/**
 * \ingroup BrickletVoltage
 *
 * Registers a callback with ID \c cb to the function \c func.
 */
void voltage_register_callback(Voltage *voltage, uint8_t cb, void *func);

#endif
