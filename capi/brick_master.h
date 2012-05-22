/* ***********************************************************
 * This file was automatically generated on 2012-05-21.      *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generator git on tinkerforge.com                   *
 *************************************************************/

#ifndef BRICK_MASTER_H
#define BRICK_MASTER_H

#include "ip_connection.h"

/**
 * \defgroup BrickMaster Master Brick
 */

/**
 * \ingroup BrickMaster
 *
 * Device for controlling Stacks and four Bricklets
 */
typedef Device Master;

/**
 * \ingroup BrickMaster
 *
 * Creates an object with the unique device ID \c uid. This object can then be
 * added to the IP connection.
 */
void master_create(Master *master, const char *uid);

/**
 * \ingroup BrickMaster
 *
 * Returns the stack voltage in mV. The stack voltage is the
 * voltage that is supplied via the stack, i.e. it is given by a 
 * Step-Down or Step-Up Power Supply.
 */
int master_get_stack_voltage(Master *master, uint16_t *ret_voltage);

/**
 * \ingroup BrickMaster
 *
 * Returns the stack current in mA. The stack current is the
 * current that is drawn via the stack, i.e. it is given by a
 * Step-Down or Step-Up Power Supply.
 */
int master_get_stack_current(Master *master, uint16_t *ret_current);

/**
 * \ingroup BrickMaster
 *
 * Writes the extension type to the EEPROM of a specified extension. 
 * The extension is either 0 or 1 (0 is the on the bottom, 1 is the on on top, 
 * if only one extension is present use 0).
 * 
 * Possible extension types:
 * 
 * \verbatim
 *  :header: "Type", "Description"
 *  :widths: 10, 100
 *  "1", "Chibi"
 *  "2", "RS485"
 * \endverbatim
 * 
 * The extension type is already set when bought and it can be set with the 
 * Brick Viewer, it is unlikely that you need this function.
 * 
 * The value will be saved in the EEPROM of the Chibi Extension, it does not
 * have to be set on every startup.
 */
int master_set_extension_type(Master *master, uint8_t extension, uint32_t exttype);

/**
 * \ingroup BrickMaster
 *
 * Returns the extension type for a given extension as set by 
 * {@link master_set_extension_type}.
 */
int master_get_extension_type(Master *master, uint8_t extension, uint32_t *ret_exttype);

/**
 * \ingroup BrickMaster
 *
 * Returns true if a Chibi Extension is available to be used by the Master.
 */
int master_is_chibi_present(Master *master, bool *ret_present);

/**
 * \ingroup BrickMaster
 *
 * Sets the address (1-255) belonging to the Chibi Extension.
 * 
 * It is possible to set the address with the Brick Viewer and it will be 
 * saved in the EEPROM of the Chibi Extension, it does not
 * have to be set on every startup.
 */
int master_set_chibi_address(Master *master, uint8_t address);

/**
 * \ingroup BrickMaster
 *
 * Returns the address as set by {@link master_set_chibi_address}.
 */
int master_get_chibi_address(Master *master, uint8_t *ret_address);

/**
 * \ingroup BrickMaster
 *
 * Sets the address (1-255) of the Chibi Master. This address is used if the
 * Chibi Extension is used as slave (i.e. it does not have a USB connection).
 * 
 * It is possible to set the address with the Brick Viewer and it will be 
 * saved in the EEPROM of the Chibi Extension, it does not
 * have to be set on every startup.
 */
int master_set_chibi_master_address(Master *master, uint8_t address);

/**
 * \ingroup BrickMaster
 *
 * Returns the address as set by {@link master_set_chibi_master_address}.
 */
int master_get_chibi_master_address(Master *master, uint8_t *ret_address);

/**
 * \ingroup BrickMaster
 *
 * Sets up to 256 slave addresses. The address numeration has to be used 
 * ascending from 0. For example: If you use the Chibi Extension in Master mode
 * (i.e. the stack has an USB connection) and you want to talk to three other
 * Chibi stacks with the IDs 17, 23, and 42, you should call with "(0, 17),
 * (1, 23) and (2, 42)".
 * 
 * It is possible to set the addresses with the Brick Viewer and it will be 
 * saved in the EEPROM of the Chibi Extension, they don't
 * have to be set on every startup.
 */
int master_set_chibi_slave_address(Master *master, uint8_t num, uint8_t address);

/**
 * \ingroup BrickMaster
 *
 * Returns the slave address for a given num as set by 
 * {@link master_set_chibi_slave_address}.
 */
int master_get_chibi_slave_address(Master *master, uint8_t num, uint8_t *ret_address);

/**
 * \ingroup BrickMaster
 *
 * Returns the signal strength in dBm. The signal strength updates every time a
 * packet is received.
 */
int master_get_chibi_signal_strength(Master *master, uint8_t *ret_signal_strength);

/**
 * \ingroup BrickMaster
 *
 * Returns underrun, CRC error, no ACK and overflow error counts of the Chibi
 * communication. If these errors start rising, it is likely that either the
 * distance between two Chibi stacks is becoming too big or there are
 * interferences.
 */
int master_get_chibi_error_log(Master *master, uint16_t *ret_underrun, uint16_t *ret_crc_error, uint16_t *ret_no_ack, uint16_t *ret_overflow);

/**
 * \ingroup BrickMaster
 *
 * Sets the Chibi frequency range for the Chibi Extension. Possible values are:
 * 
 * \verbatim
 *  :header: "Type", "Description"
 *  :widths: 10, 100
 *  "0", "OQPSK 868Mhz (Europe)"
 *  "1", "OQPSK 915Mhz (US)"
 *  "2", "OQPSK 780Mhz (China)"
 *  "3", "BPSK40 915Mhz"
 * \endverbatim
 * 
 * It is possible to set the frequency with the Brick Viewer and it will be 
 * saved in the EEPROM of the Chibi Extension, it does not
 * have to be set on every startup.
 */
int master_set_chibi_frequency(Master *master, uint8_t frequency);

/**
 * \ingroup BrickMaster
 *
 * Returns the frequency value as set by {@link master_set_chibi_frequency}.
 */
int master_get_chibi_frequency(Master *master, uint8_t *ret_frequency);

/**
 * \ingroup BrickMaster
 *
 * Sets the channel used by the Chibi Extension. Possible channels are
 * different for different frequencies:
 * 
 * \verbatim
 *  :header: "Frequency", "Possible Channels"
 *  :widths: 40, 60
 *  "OQPSK 868Mhz (Europe)", "0"
 *  "OQPSK 915Mhz (US)", "1, 2, 3, 4, 5, 6, 7, 8, 9, 10"
 *  "OQPSK 780Mhz (China)", "0, 1, 2, 3"
 *  "BPSK40 915Mhz", "1, 2, 3, 4, 5, 6, 7, 8, 9, 10"
 * \endverbatim
 * 
 * It is possible to set the frequency with the Brick Viewer and it will be 
 * saved in the EEPROM of the Chibi Extension, it does not
 * have to be set on every startup.
 */
int master_set_chibi_channel(Master *master, uint8_t channel);

/**
 * \ingroup BrickMaster
 *
 * Returns the channel as set by {@link master_set_chibi_channel}.
 */
int master_get_chibi_channel(Master *master, uint8_t *ret_channel);

/**
 * \ingroup BrickMaster
 *
 * Returns the name (including the hardware version), the firmware version
 * and the binding version of the device. The firmware and binding versions are
 * given in arrays of size 3 with the syntax [major, minor, revision].
 */
int master_get_version(Master *master, char ret_name[40], uint8_t ret_firmware_version[3], uint8_t ret_binding_version[3]);


#endif
