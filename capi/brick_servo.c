/* ***********************************************************
 * This file was automatically generated on 2012-05-21.      *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generator git on tinkerforge.com                   *
 *************************************************************/

#include "brick_servo.h"

#include <string.h>

#define FUNCTION_ENABLE 1
#define FUNCTION_DISABLE 2
#define FUNCTION_IS_ENABLED 3
#define FUNCTION_SET_POSITION 4
#define FUNCTION_GET_POSITION 5
#define FUNCTION_GET_CURRENT_POSITION 6
#define FUNCTION_SET_VELOCITY 7
#define FUNCTION_GET_VELOCITY 8
#define FUNCTION_GET_CURRENT_VELOCITY 9
#define FUNCTION_SET_ACCELERATION 10
#define FUNCTION_GET_ACCELERATION 11
#define FUNCTION_SET_OUTPUT_VOLTAGE 12
#define FUNCTION_GET_OUTPUT_VOLTAGE 13
#define FUNCTION_SET_PULSE_WIDTH 14
#define FUNCTION_GET_PULSE_WIDTH 15
#define FUNCTION_SET_DEGREE 16
#define FUNCTION_GET_DEGREE 17
#define FUNCTION_SET_PERIOD 18
#define FUNCTION_GET_PERIOD 19
#define FUNCTION_GET_SERVO_CURRENT 20
#define FUNCTION_GET_OVERALL_CURRENT 21
#define FUNCTION_GET_STACK_INPUT_VOLTAGE 22
#define FUNCTION_GET_EXTERNAL_INPUT_VOLTAGE 23
#define FUNCTION_SET_MINIMUM_VOLTAGE 24
#define FUNCTION_GET_MINIMUM_VOLTAGE 25


typedef void (*under_voltage_func_t)(uint16_t);

typedef void (*position_reached_func_t)(uint8_t, int16_t);

typedef void (*velocity_reached_func_t)(uint8_t, int16_t);

#if defined _MSC_VER || defined __BORLANDC__
	#pragma pack(push)
	#pragma pack(1)
	#define ATTRIBUTE_PACKED
#elif defined __GNUC__
	#define ATTRIBUTE_PACKED __attribute__((packed))
#else
	#error unknown compiler, do not know how to enable struct packing
#endif

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint8_t servo_num;
} ATTRIBUTE_PACKED Enable_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint8_t servo_num;
} ATTRIBUTE_PACKED Disable_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint8_t servo_num;
} ATTRIBUTE_PACKED IsEnabled_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	bool enabled;
} ATTRIBUTE_PACKED IsEnabledReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint8_t servo_num;
	int16_t position;
} ATTRIBUTE_PACKED SetPosition_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint8_t servo_num;
} ATTRIBUTE_PACKED GetPosition_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	int16_t position;
} ATTRIBUTE_PACKED GetPositionReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint8_t servo_num;
} ATTRIBUTE_PACKED GetCurrentPosition_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	int16_t position;
} ATTRIBUTE_PACKED GetCurrentPositionReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint8_t servo_num;
	uint16_t velocity;
} ATTRIBUTE_PACKED SetVelocity_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint8_t servo_num;
} ATTRIBUTE_PACKED GetVelocity_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint16_t velocity;
} ATTRIBUTE_PACKED GetVelocityReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint8_t servo_num;
} ATTRIBUTE_PACKED GetCurrentVelocity_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint16_t velocity;
} ATTRIBUTE_PACKED GetCurrentVelocityReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint8_t servo_num;
	uint16_t acceleration;
} ATTRIBUTE_PACKED SetAcceleration_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint8_t servo_num;
} ATTRIBUTE_PACKED GetAcceleration_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint16_t acceleration;
} ATTRIBUTE_PACKED GetAccelerationReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint16_t voltage;
} ATTRIBUTE_PACKED SetOutputVoltage_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED GetOutputVoltage_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint16_t voltage;
} ATTRIBUTE_PACKED GetOutputVoltageReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint8_t servo_num;
	uint16_t min;
	uint16_t max;
} ATTRIBUTE_PACKED SetPulseWidth_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint8_t servo_num;
} ATTRIBUTE_PACKED GetPulseWidth_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint16_t min;
	uint16_t max;
} ATTRIBUTE_PACKED GetPulseWidthReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint8_t servo_num;
	int16_t min;
	int16_t max;
} ATTRIBUTE_PACKED SetDegree_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint8_t servo_num;
} ATTRIBUTE_PACKED GetDegree_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	int16_t min;
	int16_t max;
} ATTRIBUTE_PACKED GetDegreeReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint8_t servo_num;
	uint16_t period;
} ATTRIBUTE_PACKED SetPeriod_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint8_t servo_num;
} ATTRIBUTE_PACKED GetPeriod_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint16_t period;
} ATTRIBUTE_PACKED GetPeriodReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint8_t servo_num;
} ATTRIBUTE_PACKED GetServoCurrent_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint16_t current;
} ATTRIBUTE_PACKED GetServoCurrentReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED GetOverallCurrent_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint16_t current;
} ATTRIBUTE_PACKED GetOverallCurrentReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED GetStackInputVoltage_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint16_t voltage;
} ATTRIBUTE_PACKED GetStackInputVoltageReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED GetExternalInputVoltage_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint16_t voltage;
} ATTRIBUTE_PACKED GetExternalInputVoltageReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint16_t voltage;
} ATTRIBUTE_PACKED SetMinimumVoltage_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED GetMinimumVoltage_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint16_t voltage;
} ATTRIBUTE_PACKED GetMinimumVoltageReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint16_t voltage;
} ATTRIBUTE_PACKED UnderVoltageCallback_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint8_t servo_num;
	int16_t position;
} ATTRIBUTE_PACKED PositionReachedCallback_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint8_t servo_num;
	int16_t velocity;
} ATTRIBUTE_PACKED VelocityReachedCallback_;

#if defined _MSC_VER || defined __BORLANDC__
	#pragma pack(pop)
#endif
#undef ATTRIBUTE_PACKED

int servo_enable(Servo *servo, uint8_t servo_num) {
	if(servo->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(servo);

	Enable_ e;
	e.stack_id = servo->stack_id;
	e.function_id = FUNCTION_ENABLE;
	e.length = sizeof(Enable_);
	e.servo_num = servo_num;

	ipcon_device_write(servo, (char *)&e, sizeof(Enable_));

	ipcon_sem_post_write(servo);

	return E_OK;
}

int servo_disable(Servo *servo, uint8_t servo_num) {
	if(servo->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(servo);

	Disable_ d;
	d.stack_id = servo->stack_id;
	d.function_id = FUNCTION_DISABLE;
	d.length = sizeof(Disable_);
	d.servo_num = servo_num;

	ipcon_device_write(servo, (char *)&d, sizeof(Disable_));

	ipcon_sem_post_write(servo);

	return E_OK;
}

int servo_is_enabled(Servo *servo, uint8_t servo_num, bool *ret_enabled) {
	if(servo->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(servo);

	servo->answer.function_id = FUNCTION_IS_ENABLED;
	servo->answer.length = sizeof(IsEnabledReturn_);
	IsEnabled_ ie;
	ie.stack_id = servo->stack_id;
	ie.function_id = FUNCTION_IS_ENABLED;
	ie.length = sizeof(IsEnabled_);
	ie.servo_num = servo_num;

	ipcon_device_write(servo, (char *)&ie, sizeof(IsEnabled_));

	if(ipcon_answer_sem_wait_timeout(servo) != 0) {
		ipcon_sem_post_write(servo);
		return E_TIMEOUT;
	}

	IsEnabledReturn_ *ier = (IsEnabledReturn_ *)servo->answer.buffer;
	*ret_enabled = ier->enabled;

	ipcon_sem_post_write(servo);

	return E_OK;
}

int servo_set_position(Servo *servo, uint8_t servo_num, int16_t position) {
	if(servo->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(servo);

	SetPosition_ sp;
	sp.stack_id = servo->stack_id;
	sp.function_id = FUNCTION_SET_POSITION;
	sp.length = sizeof(SetPosition_);
	sp.servo_num = servo_num;
	sp.position = position;

	ipcon_device_write(servo, (char *)&sp, sizeof(SetPosition_));

	ipcon_sem_post_write(servo);

	return E_OK;
}

int servo_get_position(Servo *servo, uint8_t servo_num, int16_t *ret_position) {
	if(servo->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(servo);

	servo->answer.function_id = FUNCTION_GET_POSITION;
	servo->answer.length = sizeof(GetPositionReturn_);
	GetPosition_ gp;
	gp.stack_id = servo->stack_id;
	gp.function_id = FUNCTION_GET_POSITION;
	gp.length = sizeof(GetPosition_);
	gp.servo_num = servo_num;

	ipcon_device_write(servo, (char *)&gp, sizeof(GetPosition_));

	if(ipcon_answer_sem_wait_timeout(servo) != 0) {
		ipcon_sem_post_write(servo);
		return E_TIMEOUT;
	}

	GetPositionReturn_ *gpr = (GetPositionReturn_ *)servo->answer.buffer;
	*ret_position = gpr->position;

	ipcon_sem_post_write(servo);

	return E_OK;
}

int servo_get_current_position(Servo *servo, uint8_t servo_num, int16_t *ret_position) {
	if(servo->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(servo);

	servo->answer.function_id = FUNCTION_GET_CURRENT_POSITION;
	servo->answer.length = sizeof(GetCurrentPositionReturn_);
	GetCurrentPosition_ gcp;
	gcp.stack_id = servo->stack_id;
	gcp.function_id = FUNCTION_GET_CURRENT_POSITION;
	gcp.length = sizeof(GetCurrentPosition_);
	gcp.servo_num = servo_num;

	ipcon_device_write(servo, (char *)&gcp, sizeof(GetCurrentPosition_));

	if(ipcon_answer_sem_wait_timeout(servo) != 0) {
		ipcon_sem_post_write(servo);
		return E_TIMEOUT;
	}

	GetCurrentPositionReturn_ *gcpr = (GetCurrentPositionReturn_ *)servo->answer.buffer;
	*ret_position = gcpr->position;

	ipcon_sem_post_write(servo);

	return E_OK;
}

int servo_set_velocity(Servo *servo, uint8_t servo_num, uint16_t velocity) {
	if(servo->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(servo);

	SetVelocity_ sv;
	sv.stack_id = servo->stack_id;
	sv.function_id = FUNCTION_SET_VELOCITY;
	sv.length = sizeof(SetVelocity_);
	sv.servo_num = servo_num;
	sv.velocity = velocity;

	ipcon_device_write(servo, (char *)&sv, sizeof(SetVelocity_));

	ipcon_sem_post_write(servo);

	return E_OK;
}

int servo_get_velocity(Servo *servo, uint8_t servo_num, uint16_t *ret_velocity) {
	if(servo->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(servo);

	servo->answer.function_id = FUNCTION_GET_VELOCITY;
	servo->answer.length = sizeof(GetVelocityReturn_);
	GetVelocity_ gv;
	gv.stack_id = servo->stack_id;
	gv.function_id = FUNCTION_GET_VELOCITY;
	gv.length = sizeof(GetVelocity_);
	gv.servo_num = servo_num;

	ipcon_device_write(servo, (char *)&gv, sizeof(GetVelocity_));

	if(ipcon_answer_sem_wait_timeout(servo) != 0) {
		ipcon_sem_post_write(servo);
		return E_TIMEOUT;
	}

	GetVelocityReturn_ *gvr = (GetVelocityReturn_ *)servo->answer.buffer;
	*ret_velocity = gvr->velocity;

	ipcon_sem_post_write(servo);

	return E_OK;
}

int servo_get_current_velocity(Servo *servo, uint8_t servo_num, uint16_t *ret_velocity) {
	if(servo->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(servo);

	servo->answer.function_id = FUNCTION_GET_CURRENT_VELOCITY;
	servo->answer.length = sizeof(GetCurrentVelocityReturn_);
	GetCurrentVelocity_ gcv;
	gcv.stack_id = servo->stack_id;
	gcv.function_id = FUNCTION_GET_CURRENT_VELOCITY;
	gcv.length = sizeof(GetCurrentVelocity_);
	gcv.servo_num = servo_num;

	ipcon_device_write(servo, (char *)&gcv, sizeof(GetCurrentVelocity_));

	if(ipcon_answer_sem_wait_timeout(servo) != 0) {
		ipcon_sem_post_write(servo);
		return E_TIMEOUT;
	}

	GetCurrentVelocityReturn_ *gcvr = (GetCurrentVelocityReturn_ *)servo->answer.buffer;
	*ret_velocity = gcvr->velocity;

	ipcon_sem_post_write(servo);

	return E_OK;
}

int servo_set_acceleration(Servo *servo, uint8_t servo_num, uint16_t acceleration) {
	if(servo->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(servo);

	SetAcceleration_ sa;
	sa.stack_id = servo->stack_id;
	sa.function_id = FUNCTION_SET_ACCELERATION;
	sa.length = sizeof(SetAcceleration_);
	sa.servo_num = servo_num;
	sa.acceleration = acceleration;

	ipcon_device_write(servo, (char *)&sa, sizeof(SetAcceleration_));

	ipcon_sem_post_write(servo);

	return E_OK;
}

int servo_get_acceleration(Servo *servo, uint8_t servo_num, uint16_t *ret_acceleration) {
	if(servo->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(servo);

	servo->answer.function_id = FUNCTION_GET_ACCELERATION;
	servo->answer.length = sizeof(GetAccelerationReturn_);
	GetAcceleration_ ga;
	ga.stack_id = servo->stack_id;
	ga.function_id = FUNCTION_GET_ACCELERATION;
	ga.length = sizeof(GetAcceleration_);
	ga.servo_num = servo_num;

	ipcon_device_write(servo, (char *)&ga, sizeof(GetAcceleration_));

	if(ipcon_answer_sem_wait_timeout(servo) != 0) {
		ipcon_sem_post_write(servo);
		return E_TIMEOUT;
	}

	GetAccelerationReturn_ *gar = (GetAccelerationReturn_ *)servo->answer.buffer;
	*ret_acceleration = gar->acceleration;

	ipcon_sem_post_write(servo);

	return E_OK;
}

int servo_set_output_voltage(Servo *servo, uint16_t voltage) {
	if(servo->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(servo);

	SetOutputVoltage_ sov;
	sov.stack_id = servo->stack_id;
	sov.function_id = FUNCTION_SET_OUTPUT_VOLTAGE;
	sov.length = sizeof(SetOutputVoltage_);
	sov.voltage = voltage;

	ipcon_device_write(servo, (char *)&sov, sizeof(SetOutputVoltage_));

	ipcon_sem_post_write(servo);

	return E_OK;
}

int servo_get_output_voltage(Servo *servo, uint16_t *ret_voltage) {
	if(servo->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(servo);

	servo->answer.function_id = FUNCTION_GET_OUTPUT_VOLTAGE;
	servo->answer.length = sizeof(GetOutputVoltageReturn_);
	GetOutputVoltage_ gov;
	gov.stack_id = servo->stack_id;
	gov.function_id = FUNCTION_GET_OUTPUT_VOLTAGE;
	gov.length = sizeof(GetOutputVoltage_);

	ipcon_device_write(servo, (char *)&gov, sizeof(GetOutputVoltage_));

	if(ipcon_answer_sem_wait_timeout(servo) != 0) {
		ipcon_sem_post_write(servo);
		return E_TIMEOUT;
	}

	GetOutputVoltageReturn_ *govr = (GetOutputVoltageReturn_ *)servo->answer.buffer;
	*ret_voltage = govr->voltage;

	ipcon_sem_post_write(servo);

	return E_OK;
}

int servo_set_pulse_width(Servo *servo, uint8_t servo_num, uint16_t min, uint16_t max) {
	if(servo->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(servo);

	SetPulseWidth_ spw;
	spw.stack_id = servo->stack_id;
	spw.function_id = FUNCTION_SET_PULSE_WIDTH;
	spw.length = sizeof(SetPulseWidth_);
	spw.servo_num = servo_num;
	spw.min = min;
	spw.max = max;

	ipcon_device_write(servo, (char *)&spw, sizeof(SetPulseWidth_));

	ipcon_sem_post_write(servo);

	return E_OK;
}

int servo_get_pulse_width(Servo *servo, uint8_t servo_num, uint16_t *ret_min, uint16_t *ret_max) {
	if(servo->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(servo);

	servo->answer.function_id = FUNCTION_GET_PULSE_WIDTH;
	servo->answer.length = sizeof(GetPulseWidthReturn_);
	GetPulseWidth_ gpw;
	gpw.stack_id = servo->stack_id;
	gpw.function_id = FUNCTION_GET_PULSE_WIDTH;
	gpw.length = sizeof(GetPulseWidth_);
	gpw.servo_num = servo_num;

	ipcon_device_write(servo, (char *)&gpw, sizeof(GetPulseWidth_));

	if(ipcon_answer_sem_wait_timeout(servo) != 0) {
		ipcon_sem_post_write(servo);
		return E_TIMEOUT;
	}

	GetPulseWidthReturn_ *gpwr = (GetPulseWidthReturn_ *)servo->answer.buffer;
	*ret_min = gpwr->min;
	*ret_max = gpwr->max;

	ipcon_sem_post_write(servo);

	return E_OK;
}

int servo_set_degree(Servo *servo, uint8_t servo_num, int16_t min, int16_t max) {
	if(servo->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(servo);

	SetDegree_ sd;
	sd.stack_id = servo->stack_id;
	sd.function_id = FUNCTION_SET_DEGREE;
	sd.length = sizeof(SetDegree_);
	sd.servo_num = servo_num;
	sd.min = min;
	sd.max = max;

	ipcon_device_write(servo, (char *)&sd, sizeof(SetDegree_));

	ipcon_sem_post_write(servo);

	return E_OK;
}

int servo_get_degree(Servo *servo, uint8_t servo_num, int16_t *ret_min, int16_t *ret_max) {
	if(servo->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(servo);

	servo->answer.function_id = FUNCTION_GET_DEGREE;
	servo->answer.length = sizeof(GetDegreeReturn_);
	GetDegree_ gd;
	gd.stack_id = servo->stack_id;
	gd.function_id = FUNCTION_GET_DEGREE;
	gd.length = sizeof(GetDegree_);
	gd.servo_num = servo_num;

	ipcon_device_write(servo, (char *)&gd, sizeof(GetDegree_));

	if(ipcon_answer_sem_wait_timeout(servo) != 0) {
		ipcon_sem_post_write(servo);
		return E_TIMEOUT;
	}

	GetDegreeReturn_ *gdr = (GetDegreeReturn_ *)servo->answer.buffer;
	*ret_min = gdr->min;
	*ret_max = gdr->max;

	ipcon_sem_post_write(servo);

	return E_OK;
}

int servo_set_period(Servo *servo, uint8_t servo_num, uint16_t period) {
	if(servo->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(servo);

	SetPeriod_ sp;
	sp.stack_id = servo->stack_id;
	sp.function_id = FUNCTION_SET_PERIOD;
	sp.length = sizeof(SetPeriod_);
	sp.servo_num = servo_num;
	sp.period = period;

	ipcon_device_write(servo, (char *)&sp, sizeof(SetPeriod_));

	ipcon_sem_post_write(servo);

	return E_OK;
}

int servo_get_period(Servo *servo, uint8_t servo_num, uint16_t *ret_period) {
	if(servo->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(servo);

	servo->answer.function_id = FUNCTION_GET_PERIOD;
	servo->answer.length = sizeof(GetPeriodReturn_);
	GetPeriod_ gp;
	gp.stack_id = servo->stack_id;
	gp.function_id = FUNCTION_GET_PERIOD;
	gp.length = sizeof(GetPeriod_);
	gp.servo_num = servo_num;

	ipcon_device_write(servo, (char *)&gp, sizeof(GetPeriod_));

	if(ipcon_answer_sem_wait_timeout(servo) != 0) {
		ipcon_sem_post_write(servo);
		return E_TIMEOUT;
	}

	GetPeriodReturn_ *gpr = (GetPeriodReturn_ *)servo->answer.buffer;
	*ret_period = gpr->period;

	ipcon_sem_post_write(servo);

	return E_OK;
}

int servo_get_servo_current(Servo *servo, uint8_t servo_num, uint16_t *ret_current) {
	if(servo->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(servo);

	servo->answer.function_id = FUNCTION_GET_SERVO_CURRENT;
	servo->answer.length = sizeof(GetServoCurrentReturn_);
	GetServoCurrent_ gsc;
	gsc.stack_id = servo->stack_id;
	gsc.function_id = FUNCTION_GET_SERVO_CURRENT;
	gsc.length = sizeof(GetServoCurrent_);
	gsc.servo_num = servo_num;

	ipcon_device_write(servo, (char *)&gsc, sizeof(GetServoCurrent_));

	if(ipcon_answer_sem_wait_timeout(servo) != 0) {
		ipcon_sem_post_write(servo);
		return E_TIMEOUT;
	}

	GetServoCurrentReturn_ *gscr = (GetServoCurrentReturn_ *)servo->answer.buffer;
	*ret_current = gscr->current;

	ipcon_sem_post_write(servo);

	return E_OK;
}

int servo_get_overall_current(Servo *servo, uint16_t *ret_current) {
	if(servo->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(servo);

	servo->answer.function_id = FUNCTION_GET_OVERALL_CURRENT;
	servo->answer.length = sizeof(GetOverallCurrentReturn_);
	GetOverallCurrent_ goc;
	goc.stack_id = servo->stack_id;
	goc.function_id = FUNCTION_GET_OVERALL_CURRENT;
	goc.length = sizeof(GetOverallCurrent_);

	ipcon_device_write(servo, (char *)&goc, sizeof(GetOverallCurrent_));

	if(ipcon_answer_sem_wait_timeout(servo) != 0) {
		ipcon_sem_post_write(servo);
		return E_TIMEOUT;
	}

	GetOverallCurrentReturn_ *gocr = (GetOverallCurrentReturn_ *)servo->answer.buffer;
	*ret_current = gocr->current;

	ipcon_sem_post_write(servo);

	return E_OK;
}

int servo_get_stack_input_voltage(Servo *servo, uint16_t *ret_voltage) {
	if(servo->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(servo);

	servo->answer.function_id = FUNCTION_GET_STACK_INPUT_VOLTAGE;
	servo->answer.length = sizeof(GetStackInputVoltageReturn_);
	GetStackInputVoltage_ gsiv;
	gsiv.stack_id = servo->stack_id;
	gsiv.function_id = FUNCTION_GET_STACK_INPUT_VOLTAGE;
	gsiv.length = sizeof(GetStackInputVoltage_);

	ipcon_device_write(servo, (char *)&gsiv, sizeof(GetStackInputVoltage_));

	if(ipcon_answer_sem_wait_timeout(servo) != 0) {
		ipcon_sem_post_write(servo);
		return E_TIMEOUT;
	}

	GetStackInputVoltageReturn_ *gsivr = (GetStackInputVoltageReturn_ *)servo->answer.buffer;
	*ret_voltage = gsivr->voltage;

	ipcon_sem_post_write(servo);

	return E_OK;
}

int servo_get_external_input_voltage(Servo *servo, uint16_t *ret_voltage) {
	if(servo->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(servo);

	servo->answer.function_id = FUNCTION_GET_EXTERNAL_INPUT_VOLTAGE;
	servo->answer.length = sizeof(GetExternalInputVoltageReturn_);
	GetExternalInputVoltage_ geiv;
	geiv.stack_id = servo->stack_id;
	geiv.function_id = FUNCTION_GET_EXTERNAL_INPUT_VOLTAGE;
	geiv.length = sizeof(GetExternalInputVoltage_);

	ipcon_device_write(servo, (char *)&geiv, sizeof(GetExternalInputVoltage_));

	if(ipcon_answer_sem_wait_timeout(servo) != 0) {
		ipcon_sem_post_write(servo);
		return E_TIMEOUT;
	}

	GetExternalInputVoltageReturn_ *geivr = (GetExternalInputVoltageReturn_ *)servo->answer.buffer;
	*ret_voltage = geivr->voltage;

	ipcon_sem_post_write(servo);

	return E_OK;
}

int servo_set_minimum_voltage(Servo *servo, uint16_t voltage) {
	if(servo->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(servo);

	SetMinimumVoltage_ smv;
	smv.stack_id = servo->stack_id;
	smv.function_id = FUNCTION_SET_MINIMUM_VOLTAGE;
	smv.length = sizeof(SetMinimumVoltage_);
	smv.voltage = voltage;

	ipcon_device_write(servo, (char *)&smv, sizeof(SetMinimumVoltage_));

	ipcon_sem_post_write(servo);

	return E_OK;
}

int servo_get_minimum_voltage(Servo *servo, uint16_t *ret_voltage) {
	if(servo->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(servo);

	servo->answer.function_id = FUNCTION_GET_MINIMUM_VOLTAGE;
	servo->answer.length = sizeof(GetMinimumVoltageReturn_);
	GetMinimumVoltage_ gmv;
	gmv.stack_id = servo->stack_id;
	gmv.function_id = FUNCTION_GET_MINIMUM_VOLTAGE;
	gmv.length = sizeof(GetMinimumVoltage_);

	ipcon_device_write(servo, (char *)&gmv, sizeof(GetMinimumVoltage_));

	if(ipcon_answer_sem_wait_timeout(servo) != 0) {
		ipcon_sem_post_write(servo);
		return E_TIMEOUT;
	}

	GetMinimumVoltageReturn_ *gmvr = (GetMinimumVoltageReturn_ *)servo->answer.buffer;
	*ret_voltage = gmvr->voltage;

	ipcon_sem_post_write(servo);

	return E_OK;
}

int servo_get_version(Servo *servo, char ret_name[40], uint8_t ret_firmware_version[3], uint8_t ret_binding_version[3]) {
	strncpy(ret_name, servo->name, 40);

	ret_firmware_version[0] = servo->firmware_version[0];
	ret_firmware_version[1] = servo->firmware_version[1];
	ret_firmware_version[2] = servo->firmware_version[2];

	ret_binding_version[0] = servo->binding_version[0];
	ret_binding_version[1] = servo->binding_version[1];
	ret_binding_version[2] = servo->binding_version[2];

	return E_OK;
}

static int servo_callback_under_voltage(Servo *servo, const unsigned char *buffer) {
	UnderVoltageCallback_ *uvc = (UnderVoltageCallback_ *)buffer;
	((under_voltage_func_t)servo->callbacks[uvc->function_id])(uvc->voltage);
	return sizeof(UnderVoltageCallback_);
}

static int servo_callback_position_reached(Servo *servo, const unsigned char *buffer) {
	PositionReachedCallback_ *prc = (PositionReachedCallback_ *)buffer;
	((position_reached_func_t)servo->callbacks[prc->function_id])(prc->servo_num, prc->position);
	return sizeof(PositionReachedCallback_);
}

static int servo_callback_velocity_reached(Servo *servo, const unsigned char *buffer) {
	VelocityReachedCallback_ *vrc = (VelocityReachedCallback_ *)buffer;
	((velocity_reached_func_t)servo->callbacks[vrc->function_id])(vrc->servo_num, vrc->velocity);
	return sizeof(VelocityReachedCallback_);
}

void servo_register_callback(Servo *servo, uint8_t cb, void *func) {
    servo->callbacks[cb] = func;
}

void servo_create(Servo *servo, const char *uid) {
	ipcon_device_create(servo, uid);

	servo->expected_name = "Servo Brick";

	servo->binding_version[0] = 1;
	servo->binding_version[1] = 0;
	servo->binding_version[2] = 0;

	servo->device_callbacks[SERVO_CALLBACK_UNDER_VOLTAGE] = servo_callback_under_voltage;
	servo->device_callbacks[SERVO_CALLBACK_POSITION_REACHED] = servo_callback_position_reached;
	servo->device_callbacks[SERVO_CALLBACK_VELOCITY_REACHED] = servo_callback_velocity_reached;
}
