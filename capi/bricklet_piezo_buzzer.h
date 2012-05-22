/* ***********************************************************
 * This file was automatically generated on 2012-05-21.      *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generator git on tinkerforge.com                   *
 *************************************************************/

#ifndef BRICKLET_PIEZO_BUZZER_H
#define BRICKLET_PIEZO_BUZZER_H

#include "ip_connection.h"

/**
 * \defgroup BrickletPiezoBuzzer PiezoBuzzer Bricklet
 */

/**
 * \ingroup BrickletPiezoBuzzer
 *
 * Device for controlling a piezo buzzer
 */
typedef Device PiezoBuzzer;

/**
 * \ingroup BrickletPiezoBuzzer
 *
 * This callback is triggered if a beep set by {@link piezo_buzzer_beep} is finished
 */
#define PIEZO_BUZZER_CALLBACK_BEEP_FINISHED 3

/**
 * \ingroup BrickletPiezoBuzzer
 *
 * This callback is triggered if the playback of the morse code set by
 * {@link piezo_buzzer_morse_code} is finished.
 */
#define PIEZO_BUZZER_CALLBACK_MORSE_CODE_FINISHED 4

/**
 * \ingroup BrickletPiezoBuzzer
 *
 * Creates an object with the unique device ID \c uid. This object can then be
 * added to the IP connection.
 */
void piezo_buzzer_create(PiezoBuzzer *piezo_buzzer, const char *uid);

/**
 * \ingroup BrickletPiezoBuzzer
 *
 * Beeps with the duration in ms. For example: If you set a value of 1000,
 * the piezo buzzer will beep for one second.
 */
int piezo_buzzer_beep(PiezoBuzzer *piezo_buzzer, uint32_t duration);

/**
 * \ingroup BrickletPiezoBuzzer
 *
 * Sets morse code that will be played by the piezo buzzer. The morse code
 * is given as a string consisting of "." (dot), "-" (minus) and " " (space)
 * for *dits*, *dahs* and *pauses*. Every other character is ignored.
 * 
 * For example: If you set the string "...---...", the piezo buzzer will beep
 * nine times with the durations "short short short long long long short 
 * short short".
 * 
 * The maximum string size is 60.
 */
int piezo_buzzer_morse_code(PiezoBuzzer *piezo_buzzer, char morse[60]);

/**
 * \ingroup BrickletPiezoBuzzer
 *
 * Returns the name (including the hardware version), the firmware version
 * and the binding version of the device. The firmware and binding versions are
 * given in arrays of size 3 with the syntax [major, minor, revision].
 */
int piezo_buzzer_get_version(PiezoBuzzer *piezo_buzzer, char ret_name[40], uint8_t ret_firmware_version[3], uint8_t ret_binding_version[3]);

/**
 * \ingroup BrickletPiezoBuzzer
 *
 * Registers a callback with ID \c cb to the function \c func.
 */
void piezo_buzzer_register_callback(PiezoBuzzer *piezo_buzzer, uint8_t cb, void *func);

#endif
