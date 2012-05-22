/* ***********************************************************
 * This file was automatically generated on 2012-05-21.      *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generator git on tinkerforge.com                   *
 *************************************************************/

#ifndef BRICKLET_DISTANCE_IR_H
#define BRICKLET_DISTANCE_IR_H

#include "ip_connection.h"

/**
 * \defgroup BrickletDistanceIR DistanceIR Bricklet
 */

/**
 * \ingroup BrickletDistanceIR
 *
 * Device for sensing distance via infrared
 */
typedef Device DistanceIR;

/**
 * \ingroup BrickletDistanceIR
 *
 * This callback is triggered periodically with the period that is set by
 * {@link distance_ir_set_distance_callback_period}. The parameter is the distance of the
 * sensor.
 * 
 * {@link DISTANCE_IR_CALLBACK_DISTANCE} is only triggered if the distance has changed since the
 * last triggering.
 */
#define DISTANCE_IR_CALLBACK_DISTANCE 15

/**
 * \ingroup BrickletDistanceIR
 *
 * This callback is triggered periodically with the period that is set by
 * {@link distance_ir_set_analog_value_callback_period}. The parameter is the analog value of the
 * sensor.
 * 
 * {@link DISTANCE_IR_CALLBACK_ANALOG_VALUE} is only triggered if the distance has changed since the
 * last triggering.
 */
#define DISTANCE_IR_CALLBACK_ANALOG_VALUE 16

/**
 * \ingroup BrickletDistanceIR
 *
 * This callback is triggered when the threshold as set by
 * {@link distance_ir_set_distance_callback_threshold} is reached.
 * The parameter is the distance of the sensor.
 * 
 * If the threshold keeps being reached, the callback is triggered periodically
 * with the period as set by {@link distance_ir_set_debounce_period}.
 */
#define DISTANCE_IR_CALLBACK_DISTANCE_REACHED 17

/**
 * \ingroup BrickletDistanceIR
 *
 * This callback is triggered when the threshold as set by
 * {@link distance_ir_set_analog_value_callback_threshold} is reached.
 * The parameter is the analog value of the sensor.
 * 
 * If the threshold keeps being reached, the callback is triggered periodically
 * with the period as set by {@link distance_ir_set_debounce_period}.
 */
#define DISTANCE_IR_CALLBACK_ANALOG_VALUE_REACHED 18

/**
 * \ingroup BrickletDistanceIR
 *
 * Creates an object with the unique device ID \c uid. This object can then be
 * added to the IP connection.
 */
void distance_ir_create(DistanceIR *distance_ir, const char *uid);

/**
 * \ingroup BrickletDistanceIR
 *
 * Returns the distance measured by the sensor. The value is in mm and possible
 * distance ranges are 40 to 300, 100 to 800 and 200 to 1500, depending on the
 * selected IR sensor.
 * 
 * If you want to get the distance periodically, it is recommended to use the
 * callback {@link DISTANCE_IR_CALLBACK_DISTANCE} and set the period with 
 * {@link distance_ir_set_distance_callback_period}.
 */
int distance_ir_get_distance(DistanceIR *distance_ir, uint16_t *ret_distance);

/**
 * \ingroup BrickletDistanceIR
 *
 * Returns the value as read by a 12 bit analog to digital converter.
 * The value is between 0 and 4095.
 * 
 *  \note
 *   The value returned by {@link distance_ir_get_distance} is averaged over several samples
 *   to yield less noise, while {@link distance_ir_get_analog_value} gives back raw
 *   unfiltered analog values. The only reason to use {@link distance_ir_get_analog_value} is,
 *   if you need the full resolution of the analog to digital converter.
 * 
 * If you want the analog value periodically, it is recommended to use the 
 * callback {@link DISTANCE_IR_CALLBACK_ANALOG_VALUE} and set the period with 
 * {@link distance_ir_set_analog_value_callback_period}.
 */
int distance_ir_get_analog_value(DistanceIR *distance_ir, uint16_t *ret_value);

/**
 * \ingroup BrickletDistanceIR
 *
 * Sets a sampling point value to a specific position of the lookup table.
 * The lookup table is comprised of 128 equidistant analog values with
 * corresponding distances.
 * 
 * If you measure a distance of 50cm at the analog value 2048, you
 * should call this function with (64, 5000). The utilized analog to digital
 * converter has a resolution of 12 bit. With 128 sampling points on the
 * whole range, this means that every sampling point has a size of 32
 * analog values. Thus the analog value 2048 has the corresponding sampling
 * point 64 = 2048/32.
 * 
 * Sampling points are saved on the EEPROM of the Distance-IR Bricklet and
 * loaded again on startup.
 * 
 *  \note
 *   An easy way to calibrate the sampling points of the Distace-IR Bricklet is
 *   implemented in brickv. If you want to calibrate your Bricklet it is
 *   highly recommended to use this implementation.
 */
int distance_ir_set_sampling_point(DistanceIR *distance_ir, uint8_t position, uint16_t distance);

/**
 * \ingroup BrickletDistanceIR
 *
 * Returns the distance to a sampling point position as set by
 * {@link distance_ir_set_sampling_point}.
 */
int distance_ir_get_sampling_point(DistanceIR *distance_ir, uint8_t position, uint16_t *ret_distance);

/**
 * \ingroup BrickletDistanceIR
 *
 * Sets the period in ms with which the {@link DISTANCE_IR_CALLBACK_DISTANCE} callback is triggered
 * periodically. A value of 0 turns the callback off.
 * 
 * {@link DISTANCE_IR_CALLBACK_DISTANCE} is only triggered if the distance has changed since the
 * last triggering.
 * 
 * The default value is 0.
 */
int distance_ir_set_distance_callback_period(DistanceIR *distance_ir, uint32_t period);

/**
 * \ingroup BrickletDistanceIR
 *
 * Returns the period as set by {@link distance_ir_set_distance_callback_period}.
 */
int distance_ir_get_distance_callback_period(DistanceIR *distance_ir, uint32_t *ret_period);

/**
 * \ingroup BrickletDistanceIR
 *
 * Sets the period in ms with which the {@link DISTANCE_IR_CALLBACK_ANALOG_VALUE} callback is triggered
 * periodically. A value of 0 turns the callback off.
 * 
 * {@link DISTANCE_IR_CALLBACK_ANALOG_VALUE} is only triggered if the analog value has changed since the
 * last triggering.
 * 
 * The default value is 0.
 */
int distance_ir_set_analog_value_callback_period(DistanceIR *distance_ir, uint32_t period);

/**
 * \ingroup BrickletDistanceIR
 *
 * Returns the period as set by {@link distance_ir_set_analog_value_callback_period}.
 */
int distance_ir_get_analog_value_callback_period(DistanceIR *distance_ir, uint32_t *ret_period);

/**
 * \ingroup BrickletDistanceIR
 *
 * Sets the thresholds for the {@link DISTANCE_IR_CALLBACK_DISTANCE_REACHED} callback. 
 * 
 * The following options are possible:
 * 
 * \verbatim
 *  :header: "Option", "Description"
 *  :widths: 10, 100
 *  "'x'", "Callback is turned off."
 *  "'o'", "Callback is triggered when the distance is *outside* the min and max values"
 *  "'i'", "Callback is triggered when the distance is *inside* the min and max values"
 *  "'<'", "Callback is triggered when the distance is smaller than the min value (max is ignored)"
 *  "'>'", "Callback is triggered when the distance is greater than the min value (max is ignored)"
 * \endverbatim
 * 
 * The default value is ('x', 0, 0).
 */
int distance_ir_set_distance_callback_threshold(DistanceIR *distance_ir, char option, int16_t min, int16_t max);

/**
 * \ingroup BrickletDistanceIR
 *
 * Returns the threshold as set by {@link distance_ir_set_distance_callback_threshold}.
 */
int distance_ir_get_distance_callback_threshold(DistanceIR *distance_ir, char *ret_option, int16_t *ret_min, int16_t *ret_max);

/**
 * \ingroup BrickletDistanceIR
 *
 * Sets the thresholds for the {@link DISTANCE_IR_CALLBACK_ANALOG_VALUE_REACHED} callback. 
 * 
 * The following options are possible:
 * 
 * \verbatim
 *  :header: "Option", "Description"
 *  :widths: 10, 100
 *  "'x'", "Callback is turned off."
 *  "'o'", "Callback is triggered when the distance is *outside* the min and max values"
 *  "'i'", "Callback is triggered when the distance is *inside* the min and max values"
 *  "'<'", "Callback is triggered when the distance is smaller than the min value (max is ignored)"
 *  "'>'", "Callback is triggered when the distance is greater than the min value (max is ignored)"
 * \endverbatim
 * 
 * The default value is ('x', 0, 0).
 */
int distance_ir_set_analog_value_callback_threshold(DistanceIR *distance_ir, char option, uint16_t min, uint16_t max);

/**
 * \ingroup BrickletDistanceIR
 *
 * Returns the threshold as set by {@link distance_ir_set_analog_value_callback_threshold}.
 */
int distance_ir_get_analog_value_callback_threshold(DistanceIR *distance_ir, char *ret_option, uint16_t *ret_min, uint16_t *ret_max);

/**
 * \ingroup BrickletDistanceIR
 *
 * Sets the period in ms with which the threshold callbacks
 * 
 *  {@link DISTANCE_IR_CALLBACK_DISTANCE_REACHED}, {@link DISTANCE_IR_CALLBACK_ANALOG_VALUE_REACHED}
 * 
 * are triggered, if the thresholds
 * 
 *  {@link distance_ir_set_distance_callback_threshold}, {@link distance_ir_set_analog_value_callback_threshold}
 * 
 * keep being reached.
 * 
 * The default value is 100.
 */
int distance_ir_set_debounce_period(DistanceIR *distance_ir, uint32_t debounce);

/**
 * \ingroup BrickletDistanceIR
 *
 * Returns the debounce period as set by {@link distance_ir_set_debounce_period}.
 */
int distance_ir_get_debounce_period(DistanceIR *distance_ir, uint32_t *ret_debounce);

/**
 * \ingroup BrickletDistanceIR
 *
 * Returns the name (including the hardware version), the firmware version
 * and the binding version of the device. The firmware and binding versions are
 * given in arrays of size 3 with the syntax [major, minor, revision].
 */
int distance_ir_get_version(DistanceIR *distance_ir, char ret_name[40], uint8_t ret_firmware_version[3], uint8_t ret_binding_version[3]);

/**
 * \ingroup BrickletDistanceIR
 *
 * Registers a callback with ID \c cb to the function \c func.
 */
void distance_ir_register_callback(DistanceIR *distance_ir, uint8_t cb, void *func);

#endif
