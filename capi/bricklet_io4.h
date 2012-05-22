/* ***********************************************************
 * This file was automatically generated on 2012-05-21.      *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generator git on tinkerforge.com                   *
 *************************************************************/

#ifndef BRICKLET_IO4_H
#define BRICKLET_IO4_H

#include "ip_connection.h"

/**
 * \defgroup BrickletIO4 IO4 Bricklet
 */

/**
 * \ingroup BrickletIO4
 *
 * Device for controlling up to 4 general purpose input/output pins
 */
typedef Device IO4;

/**
 * \ingroup BrickletIO4
 *
 * This callback is triggered whenever a change of the voltage level is detected
 * on pins where the interrupt was activated with :func:`SetPortInterrupt`.
 * 
 * The values are a bit mask that specifies which interrupts occurred
 * and the current value bit mask of the port.
 * 
 * For example:
 * 
 *  * (1, 1) means that an interrupt on pin 0 occurred and
 *    currently pin 0 is high and pins 1-3 are low.
 *  * (9, 14) means that an interrupt on pins 0 and 3
 *    occurred and currently pin 0 is low and pins 1-3 are high.
 */
#define IO4_CALLBACK_INTERRUPT 9

/**
 * \ingroup BrickletIO4
 *
 * Creates an object with the unique device ID \c uid. This object can then be
 * added to the IP connection.
 */
void io4_create(IO4 *io4, const char *uid);

/**
 * \ingroup BrickletIO4
 *
 * Sets the output value (high or low) with a bit mask. The bit mask
 * is 4 bit long, "true" refers to high and "false" refers to low.
 * 
 * For example: The bitstring "1100" will turn the pins 0-1 high and the
 * pins 2-3 low.
 * 
 *  \note
 *   This function does nothing for pins that are configured as input.
 *   Pull up resistors can be switched on with :func:`SetPortConfiguration`.
 */
int io4_set_value(IO4 *io4, uint8_t value_mask);

/**
 * \ingroup BrickletIO4
 *
 * Returns a bit mask of the values that are currently measured.
 * This function works if the pin is configured to input
 * as well as if it is configured to output.
 */
int io4_get_value(IO4 *io4, uint8_t *ret_value_mask);

/**
 * \ingroup BrickletIO4
 *
 * Configures the value and direction of the specified pins. Possible directions
 * are "i" and "o" for input and output.
 * 
 * If the direction is configured as output, the value is either high or low
 * (set as true or false).
 * 
 * If the direction is configured as output, the value is either pull up or
 * default (set as true or false).
 * 
 * For example: 
 * 
 *  * (15, 'i', true) will set all pins of as input pull up. 
 *  * (8, 'i', false) will set pin 3 of as input default (floating if nothing is connected). 
 *  * (3, 'o', false) will set pins 0 and 1 as output low.
 *  * (4, 'o', true) will set pin 2 of as output high.
 */
int io4_set_configuration(IO4 *io4, uint8_t pin_mask, char direction, bool value);

/**
 * \ingroup BrickletIO4
 *
 * Returns a value bit mask and a direction bit mask.
 * 
 * For example: A return value of the bitstrings "1100" and "1010" for
 * direction and value means that:
 * 
 *  * pin 0 is configured as input pull up, 
 *  * pin 1 is configured as input default,
 *  * pin 2 is configured as output high
 *  * and pin 3 is are configured as output low.
 */
int io4_get_configuration(IO4 *io4, uint8_t *ret_direction_mask, uint8_t *ret_value_mask);

/**
 * \ingroup BrickletIO4
 *
 * Sets the debounce period of the {@link IO4_CALLBACK_INTERRUPT} callback in ms.
 * 
 * For example: If you set this value to 100, you will get the interrupt
 * maximal every 100ms. This is necessary if something that bounces is
 * connected to the IO-4 Bricklet, such as a button.
 * 
 * The default value is 100.
 */
int io4_set_debounce_period(IO4 *io4, uint32_t debounce);

/**
 * \ingroup BrickletIO4
 *
 * Returns the debounce period as set by {@link io4_set_debounce_period}.
 */
int io4_get_debounce_period(IO4 *io4, uint32_t *ret_debounce);

/**
 * \ingroup BrickletIO4
 *
 * Sets the pins on which an interrupt is activated with a bit mask. 
 * Interrupts are triggered on changes of the voltage level of the pin,
 * i.e. changes from high to low and low to high.
 * 
 * For example: An interrupt bit mask of 9 will enable the interrupt for 
 * pins 0 and 3.
 * 
 * The interrupt is delivered with the callback {@link IO4_CALLBACK_INTERRUPT}.
 */
int io4_set_interrupt(IO4 *io4, uint8_t interrupt_mask);

/**
 * \ingroup BrickletIO4
 *
 * Returns the interrupt bit mask as set by :func:`SetPortInterrupt`.
 */
int io4_get_interrupt(IO4 *io4, uint8_t *ret_interrupt_mask);

/**
 * \ingroup BrickletIO4
 *
 * Returns the name (including the hardware version), the firmware version
 * and the binding version of the device. The firmware and binding versions are
 * given in arrays of size 3 with the syntax [major, minor, revision].
 */
int io4_get_version(IO4 *io4, char ret_name[40], uint8_t ret_firmware_version[3], uint8_t ret_binding_version[3]);

/**
 * \ingroup BrickletIO4
 *
 * Registers a callback with ID \c cb to the function \c func.
 */
void io4_register_callback(IO4 *io4, uint8_t cb, void *func);

#endif
