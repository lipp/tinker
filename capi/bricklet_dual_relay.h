/* ***********************************************************
 * This file was automatically generated on 2012-05-21.      *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generator git on tinkerforge.com                   *
 *************************************************************/

#ifndef BRICKLET_DUAL_RELAY_H
#define BRICKLET_DUAL_RELAY_H

#include "ip_connection.h"

/**
 * \defgroup BrickletDualRelay DualRelay Bricklet
 */

/**
 * \ingroup BrickletDualRelay
 *
 * Device for controlling two relays
 */
typedef Device DualRelay;

/**
 * \ingroup BrickletDualRelay
 *
 * Creates an object with the unique device ID \c uid. This object can then be
 * added to the IP connection.
 */
void dual_relay_create(DualRelay *dual_relay, const char *uid);

/**
 * \ingroup BrickletDualRelay
 *
 * Sets the state of the relays, *true* means on and *false* means off. 
 * For example: (true, false) turns relay 1 on and relay 2 off.
 * 
 * If you just want to set one of the relays and don't know the current state
 * of the other relay, you can get the state with {@link dual_relay_get_state}.
 * 
 * The default value is (false, false).
 */
int dual_relay_set_state(DualRelay *dual_relay, bool relay1, bool relay2);

/**
 * \ingroup BrickletDualRelay
 *
 * Returns the state of the relays, *true* means on and *false* means off.
 */
int dual_relay_get_state(DualRelay *dual_relay, bool *ret_relay1, bool *ret_relay2);

/**
 * \ingroup BrickletDualRelay
 *
 * Returns the name (including the hardware version), the firmware version
 * and the binding version of the device. The firmware and binding versions are
 * given in arrays of size 3 with the syntax [major, minor, revision].
 */
int dual_relay_get_version(DualRelay *dual_relay, char ret_name[40], uint8_t ret_firmware_version[3], uint8_t ret_binding_version[3]);


#endif
