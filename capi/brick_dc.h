/* ***********************************************************
 * This file was automatically generated on 2012-05-21.      *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generator git on tinkerforge.com                   *
 *************************************************************/

#ifndef BRICK_DC_H
#define BRICK_DC_H

#include "ip_connection.h"

/**
 * \defgroup BrickDC DC Brick
 */

/**
 * \ingroup BrickDC
 *
 * Device for controlling DC motors
 */
typedef Device DC;

/**
 * \ingroup BrickDC
 *
 * This callback is triggered when the input voltage drops below the value set by
 * {@link dc_set_minimum_voltage}. The parameter is the current voltage given
 * in mV.
 */
#define DC_CALLBACK_UNDER_VOLTAGE 21

/**
 * \ingroup BrickDC
 *
 * This callback is triggered if either the current consumption
 * is too high (above 5A) or the temperature of the driver is too high 
 * (above 175°C). These two possibilities are essentially the same, since the
 * temperature will reach this threshold immediately if the motor draws too
 * much current. In case of a voltage below 3.3V (external or stack) this
 * callback is triggered as well.
 * 
 * If this callback is triggered, the driver gets disabled at the same time.
 * That means, {@link dc_enable} has to be called to drive the motor again.
 * 
 * \note
 *  This callback only works in Drive/Brake mode (see {@link dc_set_drive_mode}). In 
 *  Drive/Coast mode it is unfortunately impossible to reliably read the 
 *  over current/over temperature signal from the driver chip.
 */
#define DC_CALLBACK_EMERGENCY_SHUTDOWN 22

/**
 * \ingroup BrickDC
 *
 * This callback is triggered whenever a set velocity is reached. For example:
 * If a velocity of 0 is present, acceleration is set to 5000 and velocity
 * to 10000, {@link DC_CALLBACK_VELOCITY_REACHED} will be triggered after about 2 seconds, when
 * the set velocity is actually reached.
 * 
 * \note
 *  Since we can't get any feedback from the DC motor, this only works if the
 *  acceleration (see {@link dc_set_acceleration}) is set smaller or equal to the
 *  maximum acceleration of the motor. Otherwise the motor will lag behind the
 *  control value and the callback will be triggered too early.
 */
#define DC_CALLBACK_VELOCITY_REACHED 23

/**
 * \ingroup BrickDC
 *
 * This callback is triggered with the period that is set by
 * {@link dc_set_current_velocity_period}. The parameter is the *current* velocity
 * used by the motor.
 * 
 * {@link DC_CALLBACK_CURRENT_VELOCITY} is only triggered after the set period if there is
 * a change in the velocity.
 */
#define DC_CALLBACK_CURRENT_VELOCITY 24

/**
 * \ingroup BrickDC
 *
 * Creates an object with the unique device ID \c uid. This object can then be
 * added to the IP connection.
 */
void dc_create(DC *dc, const char *uid);

/**
 * \ingroup BrickDC
 *
 * Sets the velocity of the motor. Whereas -32767 is full speed backward,
 * 0 is stop and 32767 is full speed forward. Depending on the 
 * acceleration (see {@link dc_set_acceleration}), the motor is not immediately 
 * brought to the velocity but smoothly accelerated.
 * 
 * The velocity describes the duty cycle of the PWM with which the motor is
 * controlled, e.g. a velocity of 3277 sets a PWM with a 10% duty cycle.
 * You can not only control the duty cycle of the PWM but also the frequency,
 * see {@link dc_set_pwm_frequency}.
 * 
 * The default velocity is 0.
 */
int dc_set_velocity(DC *dc, int16_t velocity);

/**
 * \ingroup BrickDC
 *
 * Returns the velocity as set by {@link dc_set_velocity}.
 */
int dc_get_velocity(DC *dc, int16_t *ret_velocity);

/**
 * \ingroup BrickDC
 *
 * Returns the *current* velocity of the motor. This value is different
 * from {@link dc_get_velocity} whenever the motor is currently accelerating
 * to a goal set by {@link dc_set_velocity}.
 */
int dc_get_current_velocity(DC *dc, int16_t *ret_velocity);

/**
 * \ingroup BrickDC
 *
 * Sets the acceleration of the motor. It is given in *velocity/s*. An
 * acceleration of 10000 means, that every second the velocity is increased
 * by 10000 (or about 30% duty cycle).
 * 
 * For example: If the current velocity is 0 and you want to accelerate to a
 * velocity of 16000 (about 50% duty cycle) in 10 seconds, you should set
 * an acceleration of 1600.
 * 
 * If acceleration is set to 0, there is no speed ramping, i.e. a new velocity
 * is immediately given to the motor.
 * 
 * The default acceleration is 10000.
 */
int dc_set_acceleration(DC *dc, uint16_t acceleration);

/**
 * \ingroup BrickDC
 *
 * Returns the acceleration as set by {@link dc_set_acceleration}.
 */
int dc_get_acceleration(DC *dc, uint16_t *ret_acceleration);

/**
 * \ingroup BrickDC
 *
 * Sets the frequency (in Hz) of the PWM with which the motor is driven.
 * The possible range of the frequency is 1-20000Hz. Often a high frequency
 * is less noisy and the motor runs smoother. However, with a low frequency
 * there are less switches and therefore fewer switching losses. Also with
 * most motors lower frequencies enable higher torque.
 * 
 * If you have no idea what all this means, just ignore this function and use
 * the default frequency, it will very likely work fine.
 * 
 * The default frequency is 15 kHz.
 */
int dc_set_pwm_frequency(DC *dc, uint16_t frequency);

/**
 * \ingroup BrickDC
 *
 * Returns the PWM frequency (in Hz) as set by {@link dc_set_pwm_frequency}.
 */
int dc_get_pwm_frequency(DC *dc, uint16_t *ret_frequency);

/**
 * \ingroup BrickDC
 *
 * Executes an active full brake. 
 *  
 *  \warning
 *   This function is for emergency purposes,
 *   where an immediate brake is necessary. Depending on the current velocity and
 *   the strength of the motor, a full brake can be quite violent.
 * 
 * Call {@link dc_set_velocity} with 0 if you just want to stop the motor.
 */
int dc_full_brake(DC *dc);

/**
 * \ingroup BrickDC
 *
 * Returns the stack input voltage in mV. The stack input voltage is the
 * voltage that is supplied via the stack, i.e. it is given by a 
 * Step-Down or Step-Up Power Supply.
 */
int dc_get_stack_input_voltage(DC *dc, uint16_t *ret_voltage);

/**
 * \ingroup BrickDC
 *
 * Returns the external input voltage in mV. The external input voltage is
 * given via the black power input connector on the DC Brick. 
 *  
 * If there is an external input voltage and a stack input voltage, the motor
 * will be driven by the external input voltage. If there is only a stack 
 * voltage present, the motor will be driven by this voltage.
 * 
 *  \warning 
 *   This means, if you have a high stack voltage and a low external voltage,
 *   the motor will be driven with the low external voltage. If you then remove
 *   the external connection, it will immediately be driven by the high
 *   stack voltage.
 */
int dc_get_external_input_voltage(DC *dc, uint16_t *ret_voltage);

/**
 * \ingroup BrickDC
 *
 * Returns the current consumption of the motor in mA.
 */
int dc_get_current_consumption(DC *dc, uint16_t *ret_voltage);

/**
 * \ingroup BrickDC
 *
 * Enables the motor. The motor can be configured (velocity, 
 * acceleration, etc) before it is enabled.
 */
int dc_enable(DC *dc);

/**
 * \ingroup BrickDC
 *
 * Disables the motor. The configurations are kept (velocity, 
 * acceleration, etc) but the motor is not driven until it is enabled again.
 */
int dc_disable(DC *dc);

/**
 * \ingroup BrickDC
 *
 * Returns true if the motor is enabled, false otherwise.
 */
int dc_is_enabled(DC *dc, bool *ret_enabled);

/**
 * \ingroup BrickDC
 *
 * Sets the minimum voltage in mV, below which the {@link DC_CALLBACK_UNDER_VOLTAGE} callback
 * is triggered. The minimum possible value that works with the DC Brick is 5V.
 * You can use this function to detect the discharge of a battery that is used
 * to drive the motor. If you have a fixed power supply, you likely do not need 
 * this functionality.
 * 
 * The default value is 5V.
 */
int dc_set_minimum_voltage(DC *dc, uint16_t voltage);

/**
 * \ingroup BrickDC
 *
 * Returns the minimum voltage as set by {@link dc_set_minimum_voltage}
 */
int dc_get_minimum_voltage(DC *dc, uint16_t *ret_voltage);

/**
 * \ingroup BrickDC
 *
 * Sets the drive mode. Possible modes are:
 *  * 0 = Drive/Brake
 *  * 1 = Drive/Coast
 *  
 * These modes are different kinds of motor controls.
 * 
 * In Drive/Brake mode, the motor is always either driving or braking. There
 * is no freewheeling. Advantages are: A more linear correlation between
 * PWM and velocity, more exact accelerations and the possibility to drive
 * with slower velocities.
 * 
 * In Drive/Coast mode, the motor is always either driving or freewheeling.
 * Advantages are: Less current consumption and less demands on the motor/driver.
 * 
 * The default value is 0 = Drive/Brake.
 */
int dc_set_drive_mode(DC *dc, uint8_t mode);

/**
 * \ingroup BrickDC
 *
 * Returns the drive mode, as set by {@link dc_set_drive_mode}.
 */
int dc_get_drive_mode(DC *dc, uint8_t *ret_mode);

/**
 * \ingroup BrickDC
 *
 * Sets a period in ms with which the {@link DC_CALLBACK_CURRENT_VELOCITY} callback is triggered.
 * A period of 0 turns the callback off.
 * 
 * The default value is 0.
 */
int dc_set_current_velocity_period(DC *dc, uint16_t period);

/**
 * \ingroup BrickDC
 *
 * Returns the period as set by {@link dc_set_current_velocity_period}.
 */
int dc_get_current_velocity_period(DC *dc, uint16_t *ret_period);

/**
 * \ingroup BrickDC
 *
 * Returns the name (including the hardware version), the firmware version
 * and the binding version of the device. The firmware and binding versions are
 * given in arrays of size 3 with the syntax [major, minor, revision].
 */
int dc_get_version(DC *dc, char ret_name[40], uint8_t ret_firmware_version[3], uint8_t ret_binding_version[3]);

/**
 * \ingroup BrickDC
 *
 * Registers a callback with ID \c cb to the function \c func.
 */
void dc_register_callback(DC *dc, uint8_t cb, void *func);

#endif
