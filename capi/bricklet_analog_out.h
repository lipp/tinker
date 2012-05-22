/* ***********************************************************
 * This file was automatically generated on 2012-05-21.      *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generator git on tinkerforge.com                   *
 *************************************************************/

#ifndef BRICKLET_ANALOG_OUT_H
#define BRICKLET_ANALOG_OUT_H

#include "ip_connection.h"

/**
 * \defgroup BrickletAnalogOut AnalogOut Bricklet
 */

/**
 * \ingroup BrickletAnalogOut
 *
 * Device for output of voltage between 0 and 5V
 */
typedef Device AnalogOut;

/**
 * \ingroup BrickletAnalogOut
 *
 * Creates an object with the unique device ID \c uid. This object can then be
 * added to the IP connection.
 */
void analog_out_create(AnalogOut *analog_out, const char *uid);

/**
 * \ingroup BrickletAnalogOut
 *
 * Sets the voltage in mV. The possible range is 0V to 5V (0-5000).
 * Calling this function will set the mode to 0 (see `:func:SetMode`).
 * 
 * The default value is 0 (with mode 1).
 */
int analog_out_set_voltage(AnalogOut *analog_out, uint16_t voltage);

/**
 * \ingroup BrickletAnalogOut
 *
 * Returns the voltage as set by {@link analog_out_set_voltage}.
 */
int analog_out_get_voltage(AnalogOut *analog_out, uint16_t *ret_voltage);

/**
 * \ingroup BrickletAnalogOut
 *
 * Sets the mode of the analog value. Possible modes:
 * 
 * * 0: Normal Mode (Analog value as set by {@link analog_out_set_voltage} is applied
 * * 1: 1k Ohm resistor to ground
 * * 2: 100k Ohm resistor to ground
 * * 3: 500k Ohm resistor to ground
 * 
 * Setting the mode to 0 will result in an output voltage of 0. You can jump
 * to a higher output voltage directly by calling {@link analog_out_set_voltage}.
 * 
 * The default mode is 1.
 */
int analog_out_set_mode(AnalogOut *analog_out, uint8_t mode);

/**
 * \ingroup BrickletAnalogOut
 *
 * Returns the mode as set by {@link analog_out_set_mode}.
 */
int analog_out_get_mode(AnalogOut *analog_out, uint8_t *ret_mode);

/**
 * \ingroup BrickletAnalogOut
 *
 * Returns the name (including the hardware version), the firmware version
 * and the binding version of the device. The firmware and binding versions are
 * given in arrays of size 3 with the syntax [major, minor, revision].
 */
int analog_out_get_version(AnalogOut *analog_out, char ret_name[40], uint8_t ret_firmware_version[3], uint8_t ret_binding_version[3]);


#endif
