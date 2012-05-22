/* ***********************************************************
 * This file was automatically generated on 2012-05-21.      *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generator git on tinkerforge.com                   *
 *************************************************************/

#ifndef BRICKLET_LINEAR_POTI_H
#define BRICKLET_LINEAR_POTI_H

#include "ip_connection.h"

/**
 * \defgroup BrickletLinearPoti LinearPoti Bricklet
 */

/**
 * \ingroup BrickletLinearPoti
 *
 * Device for sensing Linear Potentiometer input
 */
typedef Device LinearPoti;

/**
 * \ingroup BrickletLinearPoti
 *
 * This callback is triggered periodically with the period that is set by
 * {@link linear_poti_set_position_callback_period}. The parameter is the position of the
 * Linear Potentiometer.
 * 
 * {@link LINEAR_POTI_CALLBACK_POSITION} is only triggered if the position has changed since the
 * last triggering.
 */
#define LINEAR_POTI_CALLBACK_POSITION 13

/**
 * \ingroup BrickletLinearPoti
 *
 * This callback is triggered periodically with the period that is set by
 * {@link linear_poti_set_analog_value_callback_period}. The parameter is the analog value of the
 * Linear Potentiometer.
 * 
 * {@link LINEAR_POTI_CALLBACK_ANALOG_VALUE} is only triggered if the position has changed since the
 * last triggering.
 */
#define LINEAR_POTI_CALLBACK_ANALOG_VALUE 14

/**
 * \ingroup BrickletLinearPoti
 *
 * This callback is triggered when the threshold as set by
 * {@link linear_poti_set_position_callback_threshold} is reached.
 * The parameter is the position of the Linear Potentiometer.
 * 
 * If the threshold keeps being reached, the callback is triggered periodically
 * with the period as set by {@link linear_poti_set_debounce_period}.
 */
#define LINEAR_POTI_CALLBACK_POSITION_REACHED 15

/**
 * \ingroup BrickletLinearPoti
 *
 * This callback is triggered when the threshold as set by
 * {@link linear_poti_set_analog_value_callback_threshold} is reached.
 * The parameter is the analog value of the Linear Potentiometer.
 * 
 * If the threshold keeps being reached, the callback is triggered periodically
 * with the period as set by {@link linear_poti_set_debounce_period}.
 */
#define LINEAR_POTI_CALLBACK_ANALOG_VALUE_REACHED 16

/**
 * \ingroup BrickletLinearPoti
 *
 * Creates an object with the unique device ID \c uid. This object can then be
 * added to the IP connection.
 */
void linear_poti_create(LinearPoti *linear_poti, const char *uid);

/**
 * \ingroup BrickletLinearPoti
 *
 * Returns the position of the Linear Potentiometer. The value is  
 * between 0 (slider down) and 100 (slider up).
 * 
 * If you want to get the position periodically, it is recommended to use the
 * callback {@link LINEAR_POTI_CALLBACK_POSITION} and set the period with 
 * {@link linear_poti_set_position_callback_period}.
 */
int linear_poti_get_position(LinearPoti *linear_poti, uint16_t *ret_position);

/**
 * \ingroup BrickletLinearPoti
 *
 * Returns the value as read by a 12 bit analog to digital converter.
 * The value is between 0 and 4095.
 * 
 *  \note
 *   The value returned by {@link linear_poti_get_position} is averaged over several samples
 *   to yield less noise, while {@link linear_poti_get_analog_value} gives back raw
 *   unfiltered analog values. The only reason to use {@link linear_poti_get_analog_value} is,
 *   if you need the full resolution of the analog to digital converter.
 * 
 * If you want the analog value periodically, it is recommended to use the 
 * callback {@link LINEAR_POTI_CALLBACK_ANALOG_VALUE} and set the period with 
 * {@link linear_poti_set_analog_value_callback_period}.
 */
int linear_poti_get_analog_value(LinearPoti *linear_poti, uint16_t *ret_value);

/**
 * \ingroup BrickletLinearPoti
 *
 * Sets the period in ms with which the {@link LINEAR_POTI_CALLBACK_POSITION} callback is triggered
 * periodically. A value of 0 turns the callback off.
 * 
 * {@link LINEAR_POTI_CALLBACK_POSITION} is only triggered if the position has changed since the
 * last triggering.
 * 
 * The default value is 0.
 */
int linear_poti_set_position_callback_period(LinearPoti *linear_poti, uint32_t period);

/**
 * \ingroup BrickletLinearPoti
 *
 * Returns the period as set by {@link linear_poti_set_position_callback_period}.
 */
int linear_poti_get_position_callback_period(LinearPoti *linear_poti, uint32_t *ret_period);

/**
 * \ingroup BrickletLinearPoti
 *
 * Sets the period in ms with which the {@link LINEAR_POTI_CALLBACK_ANALOG_VALUE} callback is triggered
 * periodically. A value of 0 turns the callback off.
 * 
 * {@link LINEAR_POTI_CALLBACK_ANALOG_VALUE} is only triggered if the analog value has changed since the
 * last triggering.
 * 
 * The default value is 0.
 */
int linear_poti_set_analog_value_callback_period(LinearPoti *linear_poti, uint32_t period);

/**
 * \ingroup BrickletLinearPoti
 *
 * Returns the period as set by {@link linear_poti_set_analog_value_callback_period}.
 */
int linear_poti_get_analog_value_callback_period(LinearPoti *linear_poti, uint32_t *ret_period);

/**
 * \ingroup BrickletLinearPoti
 *
 * Sets the thresholds for the {@link LINEAR_POTI_CALLBACK_POSITION_REACHED} callback. 
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
int linear_poti_set_position_callback_threshold(LinearPoti *linear_poti, char option, int16_t min, int16_t max);

/**
 * \ingroup BrickletLinearPoti
 *
 * Returns the threshold as set by {@link linear_poti_set_position_callback_threshold}.
 */
int linear_poti_get_position_callback_threshold(LinearPoti *linear_poti, char *ret_option, int16_t *ret_min, int16_t *ret_max);

/**
 * \ingroup BrickletLinearPoti
 *
 * Sets the thresholds for the {@link LINEAR_POTI_CALLBACK_ANALOG_VALUE_REACHED} callback. 
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
int linear_poti_set_analog_value_callback_threshold(LinearPoti *linear_poti, char option, uint16_t min, uint16_t max);

/**
 * \ingroup BrickletLinearPoti
 *
 * Returns the threshold as set by {@link linear_poti_set_analog_value_callback_threshold}.
 */
int linear_poti_get_analog_value_callback_threshold(LinearPoti *linear_poti, char *ret_option, uint16_t *ret_min, uint16_t *ret_max);

/**
 * \ingroup BrickletLinearPoti
 *
 * Sets the period in ms with which the threshold callbacks
 * 
 *  {@link LINEAR_POTI_CALLBACK_POSITION_REACHED}, {@link LINEAR_POTI_CALLBACK_ANALOG_VALUE_REACHED}
 * 
 * are triggered, if the thresholds
 * 
 *  {@link linear_poti_set_position_callback_threshold}, {@link linear_poti_set_analog_value_callback_threshold}
 * 
 * keep being reached.
 * 
 * The default value is 100.
 */
int linear_poti_set_debounce_period(LinearPoti *linear_poti, uint32_t debounce);

/**
 * \ingroup BrickletLinearPoti
 *
 * Returns the debounce period as set by {@link linear_poti_set_debounce_period}.
 */
int linear_poti_get_debounce_period(LinearPoti *linear_poti, uint32_t *ret_debounce);

/**
 * \ingroup BrickletLinearPoti
 *
 * Returns the name (including the hardware version), the firmware version
 * and the binding version of the device. The firmware and binding versions are
 * given in arrays of size 3 with the syntax [major, minor, revision].
 */
int linear_poti_get_version(LinearPoti *linear_poti, char ret_name[40], uint8_t ret_firmware_version[3], uint8_t ret_binding_version[3]);

/**
 * \ingroup BrickletLinearPoti
 *
 * Registers a callback with ID \c cb to the function \c func.
 */
void linear_poti_register_callback(LinearPoti *linear_poti, uint8_t cb, void *func);

#endif
