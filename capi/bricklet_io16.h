/* ***********************************************************
 * This file was automatically generated on 2012-05-21.      *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generator git on tinkerforge.com                   *
 *************************************************************/

#ifndef BRICKLET_IO16_H
#define BRICKLET_IO16_H

#include "ip_connection.h"

/**
 * \defgroup BrickletIO16 IO16 Bricklet
 */

/**
 * \ingroup BrickletIO16
 *
 * Device for controlling up to 16 general purpose input/output pins
 */
typedef Device IO16;

/**
 * \ingroup BrickletIO16
 *
 * This callback is triggered whenever a change of the voltage level is detected
 * on pins where the interrupt was activated with {@link io16_set_port_interrupt}.
 * 
 * The values are the port, a bit mask that specifies which interrupts occurred
 * and the current value bit mask of the port.
 * 
 * For example:
 * 
 *  * ("a", 1, 1) means that on port a an interrupt on pin 0 occurred and
 *    currently pin 0 is high and pins 1-7 are low.
 *  * ("b", 128, 254) means that on port b an interrupt on pins 0 and 7
 *    occurred and currently pin 0 is low and pins 1-7 are high.
 */
#define IO16_CALLBACK_INTERRUPT 9

/**
 * \ingroup BrickletIO16
 *
 * Creates an object with the unique device ID \c uid. This object can then be
 * added to the IP connection.
 */
void io16_create(IO16 *io16, const char *uid);

/**
 * \ingroup BrickletIO16
 *
 * Sets the output value (high or low) for a port ("a" or "b") with a bit mask. 
 * The bit mask is 8 bit long, "true" refers to high and "false" refers to low.
 * 
 * For example: The bitstring "11110000" will turn the pins 0-3 high and the
 * pins 4-7 low for the specified port.
 * 
 *  \note
 *   This function does nothing for pins that are configured as input.
 *   Pull up resistors can be switched on with {@link io16_set_port_configuration}.
 */
int io16_set_port(IO16 *io16, char port, uint8_t value_mask);

/**
 * \ingroup BrickletIO16
 *
 * Returns a bit mask of the values that are currently measured on the
 * specified port. This function works if the pin is configured to input
 * as well as if it is configured to output.
 */
int io16_get_port(IO16 *io16, char port, uint8_t *ret_value_mask);

/**
 * \ingroup BrickletIO16
 *
 * Configures the value and direction of a specified port. Possible directions
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
 *  * ("a", 0xFF, 'i', true) will set all pins of port a as input pull up. 
 *  * ("a", 128, 'i', false) will set pin 7 of port a as input default (floating if nothing is connected). 
 *  * ("b", 3, 'o', false) will set pins 0 and 1 of port b as output low.
 *  * ("b", 4, 'o', true) will set pin 2 of port b as output high.
 */
int io16_set_port_configuration(IO16 *io16, char port, uint8_t port_mask, char direction, bool value);

/**
 * \ingroup BrickletIO16
 *
 * Returns a value bit mask and a direction bit mask for the specified port.
 * 
 * For example: A return value of the bitstrings "11110000" and "11001100" for
 * direction and value means that:
 * 
 *  * pins 0 and 1 are configured as input pull up, 
 *  * pins 2 and 3 are configured as input default,
 *  * pins 4 and 5 are configured as output high
 *  * and pins 6 and 7 are configured as output low.
 */
int io16_get_port_configuration(IO16 *io16, char port, uint8_t *ret_direction_mask, uint8_t *ret_value_mask);

/**
 * \ingroup BrickletIO16
 *
 * Sets the debounce period of the {@link IO16_CALLBACK_INTERRUPT} callback in ms.
 * 
 * For example: If you set this value to 100, you will get the interrupt
 * maximal every 100ms. This is necessary if something that bounces is
 * connected to the IO-16 Bricklet, such as a button.
 * 
 * The default value is 100.
 */
int io16_set_debounce_period(IO16 *io16, uint32_t debounce);

/**
 * \ingroup BrickletIO16
 *
 * Returns the debounce period as set by {@link io16_set_debounce_period}.
 */
int io16_get_debounce_period(IO16 *io16, uint32_t *ret_debounce);

/**
 * \ingroup BrickletIO16
 *
 * Sets the pins on which an interrupt is activated with a bit mask. 
 * Interrupts are triggered on changes of the voltage level of the pin,
 * i.e. changes from high to low and low to high.
 * 
 * For example: ('a', 129) will enable the interrupt for pins 0 and 7 of
 * port a.
 * 
 * The interrupt is delivered with the callback {@link IO16_CALLBACK_INTERRUPT}.
 */
int io16_set_port_interrupt(IO16 *io16, char port, uint8_t interrupt_mask);

/**
 * \ingroup BrickletIO16
 *
 * Returns the interrupt bit mask for the specified port as set by
 * {@link io16_set_port_interrupt}.
 */
int io16_get_port_interrupt(IO16 *io16, char port, uint8_t *ret_interrupt_mask);

/**
 * \ingroup BrickletIO16
 *
 * Returns the name (including the hardware version), the firmware version
 * and the binding version of the device. The firmware and binding versions are
 * given in arrays of size 3 with the syntax [major, minor, revision].
 */
int io16_get_version(IO16 *io16, char ret_name[40], uint8_t ret_firmware_version[3], uint8_t ret_binding_version[3]);

/**
 * \ingroup BrickletIO16
 *
 * Registers a callback with ID \c cb to the function \c func.
 */
void io16_register_callback(IO16 *io16, uint8_t cb, void *func);

#endif
