/* ***********************************************************
 * This file was automatically generated on 2012-05-21.      *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generator git on tinkerforge.com                   *
 *************************************************************/

#ifndef BRICK_STEPPER_H
#define BRICK_STEPPER_H

#include "ip_connection.h"

/**
 * \defgroup BrickStepper Stepper Brick
 */

/**
 * \ingroup BrickStepper
 *
 * Device for controlling stepper motors
 */
typedef Device Stepper;

/**
 * \ingroup BrickStepper
 *
 * This callback is triggered when the input voltage drops below the value set by
 * {@link stepper_set_minimum_voltage}. The parameter is the current voltage given
 * in mV.
 */
#define STEPPER_CALLBACK_UNDER_VOLTAGE 31

/**
 * \ingroup BrickStepper
 *
 * This callback is triggered when a position set by {@link stepper_set_steps} or
 * {@link stepper_set_target_position} is reached.
 * 
 * \note
 *  Since we can't get any feedback from the stepper motor, this only works if the
 *  acceleration (see {@link stepper_set_speed_ramping}) is set smaller or equal to the
 *  maximum acceleration of the motor. Otherwise the motor will lag behind the
 *  control value and the callback will be triggered too early.
 */
#define STEPPER_CALLBACK_POSITION_REACHED 32

/**
 * \ingroup BrickStepper
 *
 * Creates an object with the unique device ID \c uid. This object can then be
 * added to the IP connection.
 */
void stepper_create(Stepper *stepper, const char *uid);

/**
 * \ingroup BrickStepper
 *
 * Sets the maximum velocity of the stepper motor in steps per second.
 * This function does *not* start the motor, it merely sets the maximum
 * velocity the stepper motor is accelerated to. To get the motor running use
 * either {@link stepper_set_target_position}, {@link stepper_set_steps}, {@link stepper_drive_forward} or
 * {@link stepper_drive_backward}.
 */
int stepper_set_max_velocity(Stepper *stepper, uint16_t velocity);

/**
 * \ingroup BrickStepper
 *
 * Returns the velocity as set by {@link stepper_set_max_velocity}.
 */
int stepper_get_max_velocity(Stepper *stepper, uint16_t *ret_velocity);

/**
 * \ingroup BrickStepper
 *
 * Returns the *current* velocity of the stepper motor in steps per second.
 */
int stepper_get_current_velocity(Stepper *stepper, uint16_t *ret_velocity);

/**
 * \ingroup BrickStepper
 *
 * Sets the acceleration and deacceleration of the stepper motor. The values
 * are given in *steps/s²*. An acceleration of 1000 means, that
 * every second the velocity is increased by 1000 *steps/s*.
 * 
 * For example: If the current velocity is 0 and you want to accelerate to a
 * velocity of 8000 *steps/s* in 10 seconds, you should set an acceleration
 * of 800 *steps/s²*.
 * 
 * An acceleration/deacceleration of 0 means instantaneous 
 * acceleration/deacceleration (not recommended)
 * 
 * The default value is 1000 for both
 */
int stepper_set_speed_ramping(Stepper *stepper, uint16_t acceleration, uint16_t deacceleration);

/**
 * \ingroup BrickStepper
 *
 * Returns the acceleration and deacceleration as set by 
 * {@link stepper_set_speed_ramping}.
 */
int stepper_get_speed_ramping(Stepper *stepper, uint16_t *ret_acceleration, uint16_t *ret_deacceleration);

/**
 * \ingroup BrickStepper
 *
 * Executes an active full brake. 
 *  
 *  \warning
 *   This function is for emergency purposes,
 *   where an immediate brake is necessary. Depending on the current velocity and
 *   the strength of the motor, a full brake can be quite violent.
 * 
 * Call {@link stepper_stop} if you just want to stop the motor.
 */
int stepper_full_brake(Stepper *stepper);

/**
 * \ingroup BrickStepper
 *
 * Sets the current steps of the internal step counter. This can be used to
 * set the current position to 0 when some kind of starting position
 * is reached (e.g. when a CNC machine reaches a corner).
 */
int stepper_set_current_position(Stepper *stepper, int32_t position);

/**
 * \ingroup BrickStepper
 *
 * Returns the current position of the stepper motor in steps. On startup
 * the position is 0. The steps are counted with all possible driving
 * functions ({@link stepper_set_target_position}, {@link stepper_set_steps}, {@link stepper_drive_forward} or
 * {@link stepper_drive_backward}). It also is possible to reset the steps to 0 or
 * set them to any other desired value with {@link stepper_set_current_position}.
 */
int stepper_get_current_position(Stepper *stepper, int32_t *ret_position);

/**
 * \ingroup BrickStepper
 *
 * Sets the target position of the stepper motor in steps. For example,
 * if the current position of the motor is 500 and {@link stepper_set_target_position} is
 * called with 1000, the stepper motor will drive 500 steps forward. It will
 * use the velocity, acceleration and deacceleration as set by
 * {@link stepper_set_max_velocity} and {@link stepper_set_speed_ramping}.
 * 
 * A call of {@link stepper_set_target_position} with the parameter *x* is equivalent to
 * a call of {@link stepper_set_steps} with the parameter 
 * (*x* - {@link stepper_get_current_position}).
 */
int stepper_set_target_position(Stepper *stepper, int32_t position);

/**
 * \ingroup BrickStepper
 *
 * Returns the last target position as set by {@link stepper_set_target_position}.
 */
int stepper_get_target_position(Stepper *stepper, int32_t *ret_position);

/**
 * \ingroup BrickStepper
 *
 * Sets the number of steps the stepper motor should run. Positive values
 * will drive the motor forward and negative values backward. 
 * The velocity, acceleration and deacceleration as set by
 * {@link stepper_set_max_velocity} and {@link stepper_set_speed_ramping} will be used.
 */
int stepper_set_steps(Stepper *stepper, int32_t steps);

/**
 * \ingroup BrickStepper
 *
 * Returns the last steps as set by {@link stepper_set_steps}.
 */
int stepper_get_steps(Stepper *stepper, int32_t *ret_steps);

/**
 * \ingroup BrickStepper
 *
 * Returns the remaining steps of the last call of {@link stepper_set_steps}.
 * For example, if {@link stepper_set_steps} is called with 2000 and 
 * {@link stepper_get_remaining_steps} is called after the motor has run for 500 steps,
 * it will return 1500.
 */
int stepper_get_remaining_steps(Stepper *stepper, int32_t *ret_steps);

/**
 * \ingroup BrickStepper
 *
 * Sets the step mode of the stepper motor. Possible values are:
 * 
 * * Full Step = 1
 * * Half Step = 2
 * * Quarter Step = 4
 * * Eighth Step = 8
 * 
 * A higher value will increase the resolution and
 * decrease the torque of the stepper motor.
 * 
 * The default value is 8 (Eighth Step).
 */
int stepper_set_step_mode(Stepper *stepper, uint8_t mode);

/**
 * \ingroup BrickStepper
 *
 * Returns the step mode as set by {@link stepper_set_step_mode}.
 */
int stepper_get_step_mode(Stepper *stepper, uint8_t *ret_mode);

/**
 * \ingroup BrickStepper
 *
 * Drives the stepper motor forward until {@link stepper_drive_backward} or
 * {@link stepper_stop} is called. The velocity, acceleration and deacceleration as 
 * set by {@link stepper_set_max_velocity} and {@link stepper_set_speed_ramping} will be used.
 */
int stepper_drive_forward(Stepper *stepper);

/**
 * \ingroup BrickStepper
 *
 * Drives the stepper motor backward until {@link stepper_drive_forward} or
 * {@link stepper_stop} is triggered. The velocity, acceleration and deacceleration as
 * set by {@link stepper_set_max_velocity} and {@link stepper_set_speed_ramping} will be used.
 */
int stepper_drive_backward(Stepper *stepper);

/**
 * \ingroup BrickStepper
 *
 * Stops the stepper motor with the deacceleration as set by 
 * {@link stepper_set_speed_ramping}.
 */
int stepper_stop(Stepper *stepper);

/**
 * \ingroup BrickStepper
 *
 * Returns the stack input voltage in mV. The stack input voltage is the
 * voltage that is supplied via the stack, i.e. it is given by a 
 * Step-Down or Step-Up Power Supply.
 */
int stepper_get_stack_input_voltage(Stepper *stepper, uint16_t *ret_voltage);

/**
 * \ingroup BrickStepper
 *
 * Returns the external input voltage in mV. The external input voltage is
 * given via the black power input connector on the Stepper Brick. 
 *  
 * If there is an external input voltage and a stack input voltage, the motor
 * will be driven by the external input voltage. If there is only a stack 
 * voltage present, the motor will be driven by this voltage.
 * 
 *  \warning 
 *   This means, if you have a high stack voltage and a low external voltage,
 *   the motor will be driven with the low external voltage. If you then remove
 *   the external connection, it will immediately be driven by the high
 *   stack voltage
 */
int stepper_get_external_input_voltage(Stepper *stepper, uint16_t *ret_voltage);

/**
 * \ingroup BrickStepper
 *
 * Returns the current consumption of the motor in mA.
 */
int stepper_get_current_consumption(Stepper *stepper, uint16_t *ret_current);

/**
 * \ingroup BrickStepper
 *
 * Sets the current in mA with which the motor will be driven.
 * The minimum value is 100mA, the maximum value 2291mA and the 
 * default value is 800mA.
 * 
 *  \warning
 *   Do not set this value above the specifications of your stepper motor.
 *   Otherwise it may damage your motor.
 */
int stepper_set_motor_current(Stepper *stepper, uint16_t current);

/**
 * \ingroup BrickStepper
 *
 * Returns the current as set by {@link stepper_set_motor_current}.
 */
int stepper_get_motor_current(Stepper *stepper, uint16_t *ret_current);

/**
 * \ingroup BrickStepper
 *
 * Enables the motor. The motor can be configured (maximum velocity, 
 * acceleration, etc) before it is enabled.
 */
int stepper_enable(Stepper *stepper);

/**
 * \ingroup BrickStepper
 *
 * Disables the motor. The configurations are kept (maximum velocity, 
 * acceleration, etc) but the motor is not driven until it is enabled again.
 */
int stepper_disable(Stepper *stepper);

/**
 * \ingroup BrickStepper
 *
 * Returns true if the motor is enabled, false otherwise.
 */
int stepper_is_enabled(Stepper *stepper, bool *ret_enabled);

/**
 * \ingroup BrickStepper
 *
 * Sets the decay mode of the stepper motor. The possible value range is
 * between 0 and 65535. A value of 0 sets the fast decay mode, a value of
 * 65535 sets the slow decay mode and a value in between sets the mixed
 * decay mode.
 * 
 * Changing the decay mode is only possible if synchronous rectification
 * is enabled (see {@link stepper_set_sync_rect}).
 * 
 * For a good explanation of the different decay modes see 
 * `this <http://robot.avayanex.com/?p=86/>`_ blog post by Avayan.
 * 
 * A good decay mode is unfortunately different for every motor. The best
 * way to work out a good decay mode for your stepper motor, if you can't
 * measure the current with an oscilloscope, is to listen to the sound of
 * the motor. If the value is too low, you often hear a high pitched 
 * sound and if it is too high you can often hear a humming sound.
 * 
 * Generally, fast decay mode (small value) will be noisier but also
 * allow higher motor speeds.
 * 
 * The default value is 10000.
 *  \note
 *   There is unfortunately no formula to calculate a perfect decay
 *   mode for a given stepper motor. If you have problems with loud noises
 *   or the maximum motor speed is too slow, you should try to tinker with
 *   the decay value
 */
int stepper_set_decay(Stepper *stepper, uint16_t decay);

/**
 * \ingroup BrickStepper
 *
 * Returns the decay mode as set by {@link stepper_set_decay}
 */
int stepper_get_decay(Stepper *stepper, uint16_t *ret_decay);

/**
 * \ingroup BrickStepper
 *
 * Sets the minimum voltage in mV, below which the {@link STEPPER_CALLBACK_UNDER_VOLTAGE} callback
 * is triggered. The minimum possible value that works with the Stepper Brick is 8V.
 * You can use this function to detect the discharge of a battery that is used
 * to drive the stepper motor. If you have a fixed power supply, you likely do 
 * not need this functionality.
 * 
 * The default value is 8V.
 */
int stepper_set_minimum_voltage(Stepper *stepper, uint16_t voltage);

/**
 * \ingroup BrickStepper
 *
 * Returns the minimum voltage as set by {@link stepper_set_minimum_voltage}.
 */
int stepper_get_minimum_voltage(Stepper *stepper, uint16_t *ret_voltage);

/**
 * \ingroup BrickStepper
 *
 * Turns synchronous rectification on or off (true/false).
 * 
 * With synchronous rectification on, the decay can be changed
 * (see {@link stepper_set_decay}). Without synchronous rectification fast
 * decay is used.
 * 
 * For an explanation of synchronous rectification see 
 * `here <http://en.wikipedia.org/wiki/Active_rectification>`__.
 * 
 * \warning
 *  If you want to use high speeds (> 10000 steps/s) for a large 
 *  stepper motor with a large inductivity we strongly
 *  suggest that you disable synchronous rectification. Otherwise the
 *  Brick may not be able to cope with the load and overheat.
 * 
 * The default value is false.
 */
int stepper_set_sync_rect(Stepper *stepper, bool sync_rect);

/**
 * \ingroup BrickStepper
 *
 * Returns true if synchronous rectification is enabled, false otherwise.
 */
int stepper_is_sync_rect(Stepper *stepper, bool *ret_sync_rect);

/**
 * \ingroup BrickStepper
 *
 * Returns the name (including the hardware version), the firmware version
 * and the binding version of the device. The firmware and binding versions are
 * given in arrays of size 3 with the syntax [major, minor, revision].
 */
int stepper_get_version(Stepper *stepper, char ret_name[40], uint8_t ret_firmware_version[3], uint8_t ret_binding_version[3]);

/**
 * \ingroup BrickStepper
 *
 * Registers a callback with ID \c cb to the function \c func.
 */
void stepper_register_callback(Stepper *stepper, uint8_t cb, void *func);

#endif
