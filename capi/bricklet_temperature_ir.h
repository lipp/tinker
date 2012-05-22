/* ***********************************************************
 * This file was automatically generated on 2012-05-21.      *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generator git on tinkerforge.com                   *
 *************************************************************/

#ifndef BRICKLET_TEMPERATURE_IR_H
#define BRICKLET_TEMPERATURE_IR_H

#include "ip_connection.h"

/**
 * \defgroup BrickletTemperatureIR TemperatureIR Bricklet
 */

/**
 * \ingroup BrickletTemperatureIR
 *
 * Device for non-contact temperature sensing
 */
typedef Device TemperatureIR;

/**
 * \ingroup BrickletTemperatureIR
 *
 * This callback is triggered periodically with the period that is set by
 * {@link temperature_ir_set_ambient_temperature_callback_period}. The parameter is the ambient
 * temperature of the sensor.
 * 
 * {@link TEMPERATURE_IR_CALLBACK_AMBIENT_TEMPERATURE} is only triggered if the ambient temperature
 * has changed since the last triggering.
 */
#define TEMPERATURE_IR_CALLBACK_AMBIENT_TEMPERATURE 15

/**
 * \ingroup BrickletTemperatureIR
 *
 * This callback is triggered periodically with the period that is set by
 * {@link temperature_ir_set_object_temperature_callback_period}. The parameter is the object
 * temperature of the sensor.
 * 
 * {@link TEMPERATURE_IR_CALLBACK_AMBIENT_TEMPERATURE} is only triggered if the object temperature
 * has changed since the last triggering.
 */
#define TEMPERATURE_IR_CALLBACK_OBJECT_TEMPERATURE 16

/**
 * \ingroup BrickletTemperatureIR
 *
 * This callback is triggered when the threshold as set by
 * {@link temperature_ir_set_ambient_temperature_callback_threshold} is reached.
 * The parameter is the ambient temperature of the sensor.
 * 
 * If the threshold keeps being reached, the callback is triggered periodically
 * with the period as set by {@link temperature_ir_set_debounce_period}.
 */
#define TEMPERATURE_IR_CALLBACK_AMBIENT_TEMPERATURE_REACHED 17

/**
 * \ingroup BrickletTemperatureIR
 *
 * This callback is triggered when the threshold as set by
 * {@link temperature_ir_set_object_temperature_callback_threshold} is reached.
 * The parameter is the object temperature of the sensor.
 * 
 * If the threshold keeps being reached, the callback is triggered periodically
 * with the period as set by {@link temperature_ir_set_debounce_period}.
 */
#define TEMPERATURE_IR_CALLBACK_OBJECT_TEMPERATURE_REACHED 18

/**
 * \ingroup BrickletTemperatureIR
 *
 * Creates an object with the unique device ID \c uid. This object can then be
 * added to the IP connection.
 */
void temperature_ir_create(TemperatureIR *temperature_ir, const char *uid);

/**
 * \ingroup BrickletTemperatureIR
 *
 * Returns the ambient temperature of the sensor. The value
 * has a range of -400 to 1250 and is given in °C/10,
 * e.g. a value of 423 means that an ambient temperature of 42.3 °C is 
 * measured.
 * 
 * If you want to get the ambient temperature periodically, it is recommended 
 * to use the callback {@link TEMPERATURE_IR_CALLBACK_AMBIENT_TEMPERATURE} and set the period with 
 * {@link temperature_ir_set_ambient_temperature_callback_period}.
 */
int temperature_ir_get_ambient_temperature(TemperatureIR *temperature_ir, int16_t *ret_temperature);

/**
 * \ingroup BrickletTemperatureIR
 *
 * Returns the object temperature of the sensor, i.e. the temperature
 * of the surface of the object the sensor is aimed at. The value
 * has a range of -700 to 3800 and is given in °C/10,
 * e.g. a value of 30001 means that a temperature of 300.01 °C is measured
 * on the surface of the object.
 * 
 * The temperature of different materials is dependent on their `emissivity 
 * <http://en.wikipedia.org/wiki/Emissivity>`_. The emissivity of the material
 * can be set with {@link temperature_ir_set_emissivity}.
 * 
 * If you want to get the object temperature periodically, it is recommended 
 * to use the callback {@link TEMPERATURE_IR_CALLBACK_OBJECT_TEMPERATURE} and set the period with 
 * {@link temperature_ir_set_object_temperature_callback_period}.
 */
int temperature_ir_get_object_temperature(TemperatureIR *temperature_ir, int16_t *ret_temperature);

/**
 * \ingroup BrickletTemperatureIR
 *
 * Sets the `emissivity <http://en.wikipedia.org/wiki/Emissivity>`_ that is 
 * used to calculate the surface temperature as returned by 
 * {@link temperature_ir_get_object_temperature}. 
 * 
 * The emissivity is usually given as a value between 0.0 and 1.0. A list of
 * emissivities of different materials can be found 
 * `here <http://www.infrared-thermography.com/material.htm>`_.
 * 
 * The parameter of {@link temperature_ir_set_emissivity} has to be given with a factor of
 * 65535 (16 bit). For example: An emissivity of 0.1 can be set with the 
 * value 6553, an emissivity of 0.5 with the value 32767 and so on.
 * 
 *  \note
 *   If you need a precise measurement for the object temperature, it is
 *   absolutely crucial that you also provide a precise emissivity.
 * 
 * The default emissivity is 1.0 (value of 65535) and the minimum emissivity the
 * sensor can handle is 0.1 (value of 6553).
 */
int temperature_ir_set_emissivity(TemperatureIR *temperature_ir, uint16_t emissivity);

/**
 * \ingroup BrickletTemperatureIR
 *
 * Returns the emissivity as set by {@link temperature_ir_set_emissivity}.
 */
int temperature_ir_get_emissivity(TemperatureIR *temperature_ir, uint16_t *ret_emissivity);

/**
 * \ingroup BrickletTemperatureIR
 *
 * Sets the period in ms with which the {@link TEMPERATURE_IR_CALLBACK_AMBIENT_TEMPERATURE} callback is triggered
 * periodically. A value of 0 turns the callback off.
 * 
 * {@link TEMPERATURE_IR_CALLBACK_AMBIENT_TEMPERATURE} is only triggered if the temperature has changed since the
 * last triggering.
 * 
 * The default value is 0.
 */
int temperature_ir_set_ambient_temperature_callback_period(TemperatureIR *temperature_ir, uint32_t period);

/**
 * \ingroup BrickletTemperatureIR
 *
 * Returns the period as set by {@link temperature_ir_set_ambient_temperature_callback_period}.
 */
int temperature_ir_get_ambient_temperature_callback_period(TemperatureIR *temperature_ir, uint32_t *ret_period);

/**
 * \ingroup BrickletTemperatureIR
 *
 * Sets the period in ms with which the {@link TEMPERATURE_IR_CALLBACK_OBJECT_TEMPERATURE} callback is triggered
 * periodically. A value of 0 turns the callback off.
 * 
 * {@link TEMPERATURE_IR_CALLBACK_OBJECT_TEMPERATURE} is only triggered if the temperature has changed since the
 * last triggering.
 * 
 * The default value is 0.
 */
int temperature_ir_set_object_temperature_callback_period(TemperatureIR *temperature_ir, uint32_t period);

/**
 * \ingroup BrickletTemperatureIR
 *
 * Returns the period as set by {@link temperature_ir_set_object_temperature_callback_period}.
 */
int temperature_ir_get_object_temperature_callback_period(TemperatureIR *temperature_ir, uint32_t *ret_period);

/**
 * \ingroup BrickletTemperatureIR
 *
 * Sets the thresholds for the {@link TEMPERATURE_IR_CALLBACK_AMBIENT_TEMPERATURE_REACHED} callback. 
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
int temperature_ir_set_ambient_temperature_callback_threshold(TemperatureIR *temperature_ir, char option, int16_t min, int16_t max);

/**
 * \ingroup BrickletTemperatureIR
 *
 * Returns the threshold as set by {@link temperature_ir_set_ambient_temperature_callback_threshold}.
 */
int temperature_ir_get_ambient_temperature_callback_threshold(TemperatureIR *temperature_ir, char *ret_option, int16_t *ret_min, int16_t *ret_max);

/**
 * \ingroup BrickletTemperatureIR
 *
 * Sets the thresholds for the {@link TEMPERATURE_IR_CALLBACK_OBJECT_TEMPERATURE_REACHED} callback. 
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
int temperature_ir_set_object_temperature_callback_threshold(TemperatureIR *temperature_ir, char option, int16_t min, int16_t max);

/**
 * \ingroup BrickletTemperatureIR
 *
 * Returns the threshold as set by {@link temperature_ir_set_ambient_temperature_callback_threshold}.
 */
int temperature_ir_get_object_temperature_callback_threshold(TemperatureIR *temperature_ir, char *ret_option, int16_t *ret_min, int16_t *ret_max);

/**
 * \ingroup BrickletTemperatureIR
 *
 * Sets the period in ms with which the threshold callbacks
 * 
 *  {@link TEMPERATURE_IR_CALLBACK_AMBIENT_TEMPERATURE_REACHED}, {@link TEMPERATURE_IR_CALLBACK_OBJECT_TEMPERATURE_REACHED}
 * 
 * are triggered, if the thresholds
 * 
 *  {@link temperature_ir_set_ambient_temperature_callback_threshold}, {@link temperature_ir_set_object_temperature_callback_threshold}
 * 
 * keep being reached.
 * 
 * The default value is 100.
 */
int temperature_ir_set_debounce_period(TemperatureIR *temperature_ir, uint32_t debounce);

/**
 * \ingroup BrickletTemperatureIR
 *
 * Returns the debounce period as set by {@link temperature_ir_set_debounce_period}.
 */
int temperature_ir_get_debounce_period(TemperatureIR *temperature_ir, uint32_t *ret_debounce);

/**
 * \ingroup BrickletTemperatureIR
 *
 * Returns the name (including the hardware version), the firmware version
 * and the binding version of the device. The firmware and binding versions are
 * given in arrays of size 3 with the syntax [major, minor, revision].
 */
int temperature_ir_get_version(TemperatureIR *temperature_ir, char ret_name[40], uint8_t ret_firmware_version[3], uint8_t ret_binding_version[3]);

/**
 * \ingroup BrickletTemperatureIR
 *
 * Registers a callback with ID \c cb to the function \c func.
 */
void temperature_ir_register_callback(TemperatureIR *temperature_ir, uint8_t cb, void *func);

#endif
