/* ***********************************************************
 * This file was automatically generated on 2012-05-21.      *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generator git on tinkerforge.com                   *
 *************************************************************/

#ifndef BRICKLET_AMBIENT_LIGHT_H
#define BRICKLET_AMBIENT_LIGHT_H

#include "ip_connection.h"

/**
 * \defgroup BrickletAmbientLight AmbientLight Bricklet
 */

/**
 * \ingroup BrickletAmbientLight
 *
 * Device for sensing Ambient Light
 */
typedef Device AmbientLight;

/**
 * \ingroup BrickletAmbientLight
 *
 * This callback is triggered periodically with the period that is set by
 * {@link ambient_light_set_illuminance_callback_period}. The parameter is the illuminance of the
 * ambient light sensor.
 * 
 * {@link AMBIENT_LIGHT_CALLBACK_ILLUMINANCE} is only triggered if the illuminance has changed since the
 * last triggering.
 */
#define AMBIENT_LIGHT_CALLBACK_ILLUMINANCE 13

/**
 * \ingroup BrickletAmbientLight
 *
 * This callback is triggered periodically with the period that is set by
 * {@link ambient_light_set_analog_value_callback_period}. The parameter is the analog value of the
 * ambient light sensor.
 * 
 * {@link AMBIENT_LIGHT_CALLBACK_ANALOG_VALUE} is only triggered if the illuminance has changed since the
 * last triggering.
 */
#define AMBIENT_LIGHT_CALLBACK_ANALOG_VALUE 14

/**
 * \ingroup BrickletAmbientLight
 *
 * This callback is triggered when the threshold as set by
 * {@link ambient_light_set_illuminance_callback_threshold} is reached.
 * The parameter is the illuminance of the ambient light sensor.
 * 
 * If the threshold keeps being reached, the callback is triggered periodically
 * with the period as set by {@link ambient_light_set_debounce_period}.
 */
#define AMBIENT_LIGHT_CALLBACK_ILLUMINANCE_REACHED 15

/**
 * \ingroup BrickletAmbientLight
 *
 * This callback is triggered when the threshold as set by
 * {@link ambient_light_set_analog_value_callback_threshold} is reached.
 * The parameter is the analog value of the ambient light sensor.
 * 
 * If the threshold keeps being reached, the callback is triggered periodically
 * with the period as set by {@link ambient_light_set_debounce_period}.
 */
#define AMBIENT_LIGHT_CALLBACK_ANALOG_VALUE_REACHED 16

/**
 * \ingroup BrickletAmbientLight
 *
 * Creates an object with the unique device ID \c uid. This object can then be
 * added to the IP connection.
 */
void ambient_light_create(AmbientLight *ambient_light, const char *uid);

/**
 * \ingroup BrickletAmbientLight
 *
 * Returns the illuminance of the ambient light sensor. The value
 * has a range of 0 to 9000 and is given in Lux/10, i.e. a value
 * of 4500 means that an illuminance of 450 Lux is measured.
 * 
 * If you want to get the illuminance periodically, it is recommended to use the
 * callback {@link AMBIENT_LIGHT_CALLBACK_ILLUMINANCE} and set the period with 
 * {@link ambient_light_set_illuminance_callback_period}.
 */
int ambient_light_get_illuminance(AmbientLight *ambient_light, uint16_t *ret_illuminance);

/**
 * \ingroup BrickletAmbientLight
 *
 * Returns the value as read by a 12 bit analog to digital converter.
 * The value is between 0 and 4095.
 * 
 *  \note
 *   The value returned by {@link ambient_light_get_illuminance} is averaged over several samples
 *   to yield less noise, while {@link ambient_light_get_analog_value} gives back raw
 *   unfiltered analog values. The only reason to use {@link ambient_light_get_analog_value} is,
 *   if you need the full resolution of the analog to digital converter.
 * 
 *   Also, the analog to digital converter covers three different ranges that are
 *   set dynamically depending on the light intensity. It is impossible to
 *   distinguish between these ranges with the analog value.
 * 
 * If you want the analog value periodically, it is recommended to use the 
 * callback {@link AMBIENT_LIGHT_CALLBACK_ANALOG_VALUE} and set the period with 
 * {@link ambient_light_set_analog_value_callback_period}.
 */
int ambient_light_get_analog_value(AmbientLight *ambient_light, uint16_t *ret_value);

/**
 * \ingroup BrickletAmbientLight
 *
 * Sets the period in ms with which the {@link AMBIENT_LIGHT_CALLBACK_ILLUMINANCE} callback is triggered
 * periodically. A value of 0 turns the callback off.
 * 
 * {@link AMBIENT_LIGHT_CALLBACK_ILLUMINANCE} is only triggered if the illuminance has changed since the
 * last triggering.
 * 
 * The default value is 0.
 */
int ambient_light_set_illuminance_callback_period(AmbientLight *ambient_light, uint32_t period);

/**
 * \ingroup BrickletAmbientLight
 *
 * Returns the period as set by {@link ambient_light_set_illuminance_callback_period}.
 */
int ambient_light_get_illuminance_callback_period(AmbientLight *ambient_light, uint32_t *ret_period);

/**
 * \ingroup BrickletAmbientLight
 *
 * Sets the period in ms with which the {@link AMBIENT_LIGHT_CALLBACK_ANALOG_VALUE} callback is triggered
 * periodically. A value of 0 turns the callback off.
 * 
 * {@link AMBIENT_LIGHT_CALLBACK_ANALOG_VALUE} is only triggered if the analog value has changed since the
 * last triggering.
 * 
 * The default value is 0.
 */
int ambient_light_set_analog_value_callback_period(AmbientLight *ambient_light, uint32_t period);

/**
 * \ingroup BrickletAmbientLight
 *
 * Returns the period as set by {@link ambient_light_set_analog_value_callback_period}.
 */
int ambient_light_get_analog_value_callback_period(AmbientLight *ambient_light, uint32_t *ret_period);

/**
 * \ingroup BrickletAmbientLight
 *
 * Sets the thresholds for the {@link AMBIENT_LIGHT_CALLBACK_ILLUMINANCE_REACHED} callback. 
 * 
 * The following options are possible:
 * 
 * \verbatim
 *  :header: "Option", "Description"
 *  :widths: 10, 100
 *  "'x'", "Callback is turned off."
 *  "'o'", "Callback is triggered when the illuminance is *outside* the min and max values"
 *  "'i'", "Callback is triggered when the illuminance is *inside* the min and max values"
 *  "'<'", "Callback is triggered when the illuminance is smaller than the min value (max is ignored)"
 *  "'>'", "Callback is triggered when the illuminance is greater than the min value (max is ignored)"
 * \endverbatim
 * 
 * The default value is ('x', 0, 0).
 */
int ambient_light_set_illuminance_callback_threshold(AmbientLight *ambient_light, char option, int16_t min, int16_t max);

/**
 * \ingroup BrickletAmbientLight
 *
 * Returns the threshold as set by {@link ambient_light_set_illuminance_callback_threshold}.
 */
int ambient_light_get_illuminance_callback_threshold(AmbientLight *ambient_light, char *ret_option, int16_t *ret_min, int16_t *ret_max);

/**
 * \ingroup BrickletAmbientLight
 *
 * Sets the thresholds for the {@link AMBIENT_LIGHT_CALLBACK_ANALOG_VALUE_REACHED} callback. 
 * 
 * The following options are possible:
 * 
 * \verbatim
 *  :header: "Option", "Description"
 *  :widths: 10, 100
 *  "'x'", "Callback is turned off."
 *  "'o'", "Callback is triggered when the illuminance is *outside* the min and max values"
 *  "'i'", "Callback is triggered when the illuminance is *inside* the min and max values"
 *  "'<'", "Callback is triggered when the illuminance is smaller than the min value (max is ignored)"
 *  "'>'", "Callback is triggered when the illuminance is greater than the min value (max is ignored)"
 * \endverbatim
 * 
 * The default value is ('x', 0, 0).
 */
int ambient_light_set_analog_value_callback_threshold(AmbientLight *ambient_light, char option, uint16_t min, uint16_t max);

/**
 * \ingroup BrickletAmbientLight
 *
 * Returns the threshold as set by {@link ambient_light_set_analog_value_callback_threshold}.
 */
int ambient_light_get_analog_value_callback_threshold(AmbientLight *ambient_light, char *ret_option, uint16_t *ret_min, uint16_t *ret_max);

/**
 * \ingroup BrickletAmbientLight
 *
 * Sets the period in ms with which the threshold callbacks
 * 
 *  {@link AMBIENT_LIGHT_CALLBACK_ILLUMINANCE_REACHED}, {@link AMBIENT_LIGHT_CALLBACK_ANALOG_VALUE_REACHED}
 * 
 * are triggered, if the thresholds
 * 
 *  {@link ambient_light_set_illuminance_callback_threshold}, {@link ambient_light_set_analog_value_callback_threshold}
 * 
 * keep being reached.
 * 
 * The default value is 100.
 */
int ambient_light_set_debounce_period(AmbientLight *ambient_light, uint32_t debounce);

/**
 * \ingroup BrickletAmbientLight
 *
 * Returns the debounce period as set by {@link ambient_light_set_debounce_period}.
 */
int ambient_light_get_debounce_period(AmbientLight *ambient_light, uint32_t *ret_debounce);

/**
 * \ingroup BrickletAmbientLight
 *
 * Returns the name (including the hardware version), the firmware version
 * and the binding version of the device. The firmware and binding versions are
 * given in arrays of size 3 with the syntax [major, minor, revision].
 */
int ambient_light_get_version(AmbientLight *ambient_light, char ret_name[40], uint8_t ret_firmware_version[3], uint8_t ret_binding_version[3]);

/**
 * \ingroup BrickletAmbientLight
 *
 * Registers a callback with ID \c cb to the function \c func.
 */
void ambient_light_register_callback(AmbientLight *ambient_light, uint8_t cb, void *func);

#endif
