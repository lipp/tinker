/* ***********************************************************
 * This file was automatically generated on 2012-05-21.      *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generator git on tinkerforge.com                   *
 *************************************************************/

#include "brick_dc.h"

#include <string.h>

#define FUNCTION_SET_VELOCITY 1
#define FUNCTION_GET_VELOCITY 2
#define FUNCTION_GET_CURRENT_VELOCITY 3
#define FUNCTION_SET_ACCELERATION 4
#define FUNCTION_GET_ACCELERATION 5
#define FUNCTION_SET_PWM_FREQUENCY 6
#define FUNCTION_GET_PWM_FREQUENCY 7
#define FUNCTION_FULL_BRAKE 8
#define FUNCTION_GET_STACK_INPUT_VOLTAGE 9
#define FUNCTION_GET_EXTERNAL_INPUT_VOLTAGE 10
#define FUNCTION_GET_CURRENT_CONSUMPTION 11
#define FUNCTION_ENABLE 12
#define FUNCTION_DISABLE 13
#define FUNCTION_IS_ENABLED 14
#define FUNCTION_SET_MINIMUM_VOLTAGE 15
#define FUNCTION_GET_MINIMUM_VOLTAGE 16
#define FUNCTION_SET_DRIVE_MODE 17
#define FUNCTION_GET_DRIVE_MODE 18
#define FUNCTION_SET_CURRENT_VELOCITY_PERIOD 19
#define FUNCTION_GET_CURRENT_VELOCITY_PERIOD 20


typedef void (*under_voltage_func_t)(uint16_t);

typedef void (*emergency_shutdown_func_t)();

typedef void (*velocity_reached_func_t)(int16_t);

typedef void (*current_velocity_func_t)(int16_t);

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
	int16_t velocity;
} ATTRIBUTE_PACKED SetVelocity_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED GetVelocity_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	int16_t velocity;
} ATTRIBUTE_PACKED GetVelocityReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED GetCurrentVelocity_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	int16_t velocity;
} ATTRIBUTE_PACKED GetCurrentVelocityReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint16_t acceleration;
} ATTRIBUTE_PACKED SetAcceleration_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
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
	uint16_t frequency;
} ATTRIBUTE_PACKED SetPWMFrequency_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED GetPWMFrequency_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint16_t frequency;
} ATTRIBUTE_PACKED GetPWMFrequencyReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED FullBrake_;

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
} ATTRIBUTE_PACKED GetCurrentConsumption_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint16_t voltage;
} ATTRIBUTE_PACKED GetCurrentConsumptionReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED Enable_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED Disable_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
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
	uint8_t mode;
} ATTRIBUTE_PACKED SetDriveMode_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED GetDriveMode_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint8_t mode;
} ATTRIBUTE_PACKED GetDriveModeReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint16_t period;
} ATTRIBUTE_PACKED SetCurrentVelocityPeriod_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED GetCurrentVelocityPeriod_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint16_t period;
} ATTRIBUTE_PACKED GetCurrentVelocityPeriodReturn_;

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
} ATTRIBUTE_PACKED EmergencyShutdownCallback_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	int16_t velocity;
} ATTRIBUTE_PACKED VelocityReachedCallback_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	int16_t velocity;
} ATTRIBUTE_PACKED CurrentVelocityCallback_;

#if defined _MSC_VER || defined __BORLANDC__
	#pragma pack(pop)
#endif
#undef ATTRIBUTE_PACKED

int dc_set_velocity(DC *dc, int16_t velocity) {
	if(dc->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(dc);

	SetVelocity_ sv;
	sv.stack_id = dc->stack_id;
	sv.function_id = FUNCTION_SET_VELOCITY;
	sv.length = sizeof(SetVelocity_);
	sv.velocity = velocity;

	ipcon_device_write(dc, (char *)&sv, sizeof(SetVelocity_));

	ipcon_sem_post_write(dc);

	return E_OK;
}

int dc_get_velocity(DC *dc, int16_t *ret_velocity) {
	if(dc->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(dc);

	dc->answer.function_id = FUNCTION_GET_VELOCITY;
	dc->answer.length = sizeof(GetVelocityReturn_);
	GetVelocity_ gv;
	gv.stack_id = dc->stack_id;
	gv.function_id = FUNCTION_GET_VELOCITY;
	gv.length = sizeof(GetVelocity_);

	ipcon_device_write(dc, (char *)&gv, sizeof(GetVelocity_));

	if(ipcon_answer_sem_wait_timeout(dc) != 0) {
		ipcon_sem_post_write(dc);
		return E_TIMEOUT;
	}

	GetVelocityReturn_ *gvr = (GetVelocityReturn_ *)dc->answer.buffer;
	*ret_velocity = gvr->velocity;

	ipcon_sem_post_write(dc);

	return E_OK;
}

int dc_get_current_velocity(DC *dc, int16_t *ret_velocity) {
	if(dc->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(dc);

	dc->answer.function_id = FUNCTION_GET_CURRENT_VELOCITY;
	dc->answer.length = sizeof(GetCurrentVelocityReturn_);
	GetCurrentVelocity_ gcv;
	gcv.stack_id = dc->stack_id;
	gcv.function_id = FUNCTION_GET_CURRENT_VELOCITY;
	gcv.length = sizeof(GetCurrentVelocity_);

	ipcon_device_write(dc, (char *)&gcv, sizeof(GetCurrentVelocity_));

	if(ipcon_answer_sem_wait_timeout(dc) != 0) {
		ipcon_sem_post_write(dc);
		return E_TIMEOUT;
	}

	GetCurrentVelocityReturn_ *gcvr = (GetCurrentVelocityReturn_ *)dc->answer.buffer;
	*ret_velocity = gcvr->velocity;

	ipcon_sem_post_write(dc);

	return E_OK;
}

int dc_set_acceleration(DC *dc, uint16_t acceleration) {
	if(dc->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(dc);

	SetAcceleration_ sa;
	sa.stack_id = dc->stack_id;
	sa.function_id = FUNCTION_SET_ACCELERATION;
	sa.length = sizeof(SetAcceleration_);
	sa.acceleration = acceleration;

	ipcon_device_write(dc, (char *)&sa, sizeof(SetAcceleration_));

	ipcon_sem_post_write(dc);

	return E_OK;
}

int dc_get_acceleration(DC *dc, uint16_t *ret_acceleration) {
	if(dc->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(dc);

	dc->answer.function_id = FUNCTION_GET_ACCELERATION;
	dc->answer.length = sizeof(GetAccelerationReturn_);
	GetAcceleration_ ga;
	ga.stack_id = dc->stack_id;
	ga.function_id = FUNCTION_GET_ACCELERATION;
	ga.length = sizeof(GetAcceleration_);

	ipcon_device_write(dc, (char *)&ga, sizeof(GetAcceleration_));

	if(ipcon_answer_sem_wait_timeout(dc) != 0) {
		ipcon_sem_post_write(dc);
		return E_TIMEOUT;
	}

	GetAccelerationReturn_ *gar = (GetAccelerationReturn_ *)dc->answer.buffer;
	*ret_acceleration = gar->acceleration;

	ipcon_sem_post_write(dc);

	return E_OK;
}

int dc_set_pwm_frequency(DC *dc, uint16_t frequency) {
	if(dc->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(dc);

	SetPWMFrequency_ spf;
	spf.stack_id = dc->stack_id;
	spf.function_id = FUNCTION_SET_PWM_FREQUENCY;
	spf.length = sizeof(SetPWMFrequency_);
	spf.frequency = frequency;

	ipcon_device_write(dc, (char *)&spf, sizeof(SetPWMFrequency_));

	ipcon_sem_post_write(dc);

	return E_OK;
}

int dc_get_pwm_frequency(DC *dc, uint16_t *ret_frequency) {
	if(dc->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(dc);

	dc->answer.function_id = FUNCTION_GET_PWM_FREQUENCY;
	dc->answer.length = sizeof(GetPWMFrequencyReturn_);
	GetPWMFrequency_ gpf;
	gpf.stack_id = dc->stack_id;
	gpf.function_id = FUNCTION_GET_PWM_FREQUENCY;
	gpf.length = sizeof(GetPWMFrequency_);

	ipcon_device_write(dc, (char *)&gpf, sizeof(GetPWMFrequency_));

	if(ipcon_answer_sem_wait_timeout(dc) != 0) {
		ipcon_sem_post_write(dc);
		return E_TIMEOUT;
	}

	GetPWMFrequencyReturn_ *gpfr = (GetPWMFrequencyReturn_ *)dc->answer.buffer;
	*ret_frequency = gpfr->frequency;

	ipcon_sem_post_write(dc);

	return E_OK;
}

int dc_full_brake(DC *dc) {
	if(dc->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(dc);

	FullBrake_ fb;
	fb.stack_id = dc->stack_id;
	fb.function_id = FUNCTION_FULL_BRAKE;
	fb.length = sizeof(FullBrake_);

	ipcon_device_write(dc, (char *)&fb, sizeof(FullBrake_));

	ipcon_sem_post_write(dc);

	return E_OK;
}

int dc_get_stack_input_voltage(DC *dc, uint16_t *ret_voltage) {
	if(dc->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(dc);

	dc->answer.function_id = FUNCTION_GET_STACK_INPUT_VOLTAGE;
	dc->answer.length = sizeof(GetStackInputVoltageReturn_);
	GetStackInputVoltage_ gsiv;
	gsiv.stack_id = dc->stack_id;
	gsiv.function_id = FUNCTION_GET_STACK_INPUT_VOLTAGE;
	gsiv.length = sizeof(GetStackInputVoltage_);

	ipcon_device_write(dc, (char *)&gsiv, sizeof(GetStackInputVoltage_));

	if(ipcon_answer_sem_wait_timeout(dc) != 0) {
		ipcon_sem_post_write(dc);
		return E_TIMEOUT;
	}

	GetStackInputVoltageReturn_ *gsivr = (GetStackInputVoltageReturn_ *)dc->answer.buffer;
	*ret_voltage = gsivr->voltage;

	ipcon_sem_post_write(dc);

	return E_OK;
}

int dc_get_external_input_voltage(DC *dc, uint16_t *ret_voltage) {
	if(dc->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(dc);

	dc->answer.function_id = FUNCTION_GET_EXTERNAL_INPUT_VOLTAGE;
	dc->answer.length = sizeof(GetExternalInputVoltageReturn_);
	GetExternalInputVoltage_ geiv;
	geiv.stack_id = dc->stack_id;
	geiv.function_id = FUNCTION_GET_EXTERNAL_INPUT_VOLTAGE;
	geiv.length = sizeof(GetExternalInputVoltage_);

	ipcon_device_write(dc, (char *)&geiv, sizeof(GetExternalInputVoltage_));

	if(ipcon_answer_sem_wait_timeout(dc) != 0) {
		ipcon_sem_post_write(dc);
		return E_TIMEOUT;
	}

	GetExternalInputVoltageReturn_ *geivr = (GetExternalInputVoltageReturn_ *)dc->answer.buffer;
	*ret_voltage = geivr->voltage;

	ipcon_sem_post_write(dc);

	return E_OK;
}

int dc_get_current_consumption(DC *dc, uint16_t *ret_voltage) {
	if(dc->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(dc);

	dc->answer.function_id = FUNCTION_GET_CURRENT_CONSUMPTION;
	dc->answer.length = sizeof(GetCurrentConsumptionReturn_);
	GetCurrentConsumption_ gcc;
	gcc.stack_id = dc->stack_id;
	gcc.function_id = FUNCTION_GET_CURRENT_CONSUMPTION;
	gcc.length = sizeof(GetCurrentConsumption_);

	ipcon_device_write(dc, (char *)&gcc, sizeof(GetCurrentConsumption_));

	if(ipcon_answer_sem_wait_timeout(dc) != 0) {
		ipcon_sem_post_write(dc);
		return E_TIMEOUT;
	}

	GetCurrentConsumptionReturn_ *gccr = (GetCurrentConsumptionReturn_ *)dc->answer.buffer;
	*ret_voltage = gccr->voltage;

	ipcon_sem_post_write(dc);

	return E_OK;
}

int dc_enable(DC *dc) {
	if(dc->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(dc);

	Enable_ e;
	e.stack_id = dc->stack_id;
	e.function_id = FUNCTION_ENABLE;
	e.length = sizeof(Enable_);

	ipcon_device_write(dc, (char *)&e, sizeof(Enable_));

	ipcon_sem_post_write(dc);

	return E_OK;
}

int dc_disable(DC *dc) {
	if(dc->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(dc);

	Disable_ d;
	d.stack_id = dc->stack_id;
	d.function_id = FUNCTION_DISABLE;
	d.length = sizeof(Disable_);

	ipcon_device_write(dc, (char *)&d, sizeof(Disable_));

	ipcon_sem_post_write(dc);

	return E_OK;
}

int dc_is_enabled(DC *dc, bool *ret_enabled) {
	if(dc->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(dc);

	dc->answer.function_id = FUNCTION_IS_ENABLED;
	dc->answer.length = sizeof(IsEnabledReturn_);
	IsEnabled_ ie;
	ie.stack_id = dc->stack_id;
	ie.function_id = FUNCTION_IS_ENABLED;
	ie.length = sizeof(IsEnabled_);

	ipcon_device_write(dc, (char *)&ie, sizeof(IsEnabled_));

	if(ipcon_answer_sem_wait_timeout(dc) != 0) {
		ipcon_sem_post_write(dc);
		return E_TIMEOUT;
	}

	IsEnabledReturn_ *ier = (IsEnabledReturn_ *)dc->answer.buffer;
	*ret_enabled = ier->enabled;

	ipcon_sem_post_write(dc);

	return E_OK;
}

int dc_set_minimum_voltage(DC *dc, uint16_t voltage) {
	if(dc->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(dc);

	SetMinimumVoltage_ smv;
	smv.stack_id = dc->stack_id;
	smv.function_id = FUNCTION_SET_MINIMUM_VOLTAGE;
	smv.length = sizeof(SetMinimumVoltage_);
	smv.voltage = voltage;

	ipcon_device_write(dc, (char *)&smv, sizeof(SetMinimumVoltage_));

	ipcon_sem_post_write(dc);

	return E_OK;
}

int dc_get_minimum_voltage(DC *dc, uint16_t *ret_voltage) {
	if(dc->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(dc);

	dc->answer.function_id = FUNCTION_GET_MINIMUM_VOLTAGE;
	dc->answer.length = sizeof(GetMinimumVoltageReturn_);
	GetMinimumVoltage_ gmv;
	gmv.stack_id = dc->stack_id;
	gmv.function_id = FUNCTION_GET_MINIMUM_VOLTAGE;
	gmv.length = sizeof(GetMinimumVoltage_);

	ipcon_device_write(dc, (char *)&gmv, sizeof(GetMinimumVoltage_));

	if(ipcon_answer_sem_wait_timeout(dc) != 0) {
		ipcon_sem_post_write(dc);
		return E_TIMEOUT;
	}

	GetMinimumVoltageReturn_ *gmvr = (GetMinimumVoltageReturn_ *)dc->answer.buffer;
	*ret_voltage = gmvr->voltage;

	ipcon_sem_post_write(dc);

	return E_OK;
}

int dc_set_drive_mode(DC *dc, uint8_t mode) {
	if(dc->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(dc);

	SetDriveMode_ sdm;
	sdm.stack_id = dc->stack_id;
	sdm.function_id = FUNCTION_SET_DRIVE_MODE;
	sdm.length = sizeof(SetDriveMode_);
	sdm.mode = mode;

	ipcon_device_write(dc, (char *)&sdm, sizeof(SetDriveMode_));

	ipcon_sem_post_write(dc);

	return E_OK;
}

int dc_get_drive_mode(DC *dc, uint8_t *ret_mode) {
	if(dc->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(dc);

	dc->answer.function_id = FUNCTION_GET_DRIVE_MODE;
	dc->answer.length = sizeof(GetDriveModeReturn_);
	GetDriveMode_ gdm;
	gdm.stack_id = dc->stack_id;
	gdm.function_id = FUNCTION_GET_DRIVE_MODE;
	gdm.length = sizeof(GetDriveMode_);

	ipcon_device_write(dc, (char *)&gdm, sizeof(GetDriveMode_));

	if(ipcon_answer_sem_wait_timeout(dc) != 0) {
		ipcon_sem_post_write(dc);
		return E_TIMEOUT;
	}

	GetDriveModeReturn_ *gdmr = (GetDriveModeReturn_ *)dc->answer.buffer;
	*ret_mode = gdmr->mode;

	ipcon_sem_post_write(dc);

	return E_OK;
}

int dc_set_current_velocity_period(DC *dc, uint16_t period) {
	if(dc->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(dc);

	SetCurrentVelocityPeriod_ scvp;
	scvp.stack_id = dc->stack_id;
	scvp.function_id = FUNCTION_SET_CURRENT_VELOCITY_PERIOD;
	scvp.length = sizeof(SetCurrentVelocityPeriod_);
	scvp.period = period;

	ipcon_device_write(dc, (char *)&scvp, sizeof(SetCurrentVelocityPeriod_));

	ipcon_sem_post_write(dc);

	return E_OK;
}

int dc_get_current_velocity_period(DC *dc, uint16_t *ret_period) {
	if(dc->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(dc);

	dc->answer.function_id = FUNCTION_GET_CURRENT_VELOCITY_PERIOD;
	dc->answer.length = sizeof(GetCurrentVelocityPeriodReturn_);
	GetCurrentVelocityPeriod_ gcvp;
	gcvp.stack_id = dc->stack_id;
	gcvp.function_id = FUNCTION_GET_CURRENT_VELOCITY_PERIOD;
	gcvp.length = sizeof(GetCurrentVelocityPeriod_);

	ipcon_device_write(dc, (char *)&gcvp, sizeof(GetCurrentVelocityPeriod_));

	if(ipcon_answer_sem_wait_timeout(dc) != 0) {
		ipcon_sem_post_write(dc);
		return E_TIMEOUT;
	}

	GetCurrentVelocityPeriodReturn_ *gcvpr = (GetCurrentVelocityPeriodReturn_ *)dc->answer.buffer;
	*ret_period = gcvpr->period;

	ipcon_sem_post_write(dc);

	return E_OK;
}

int dc_get_version(DC *dc, char ret_name[40], uint8_t ret_firmware_version[3], uint8_t ret_binding_version[3]) {
	strncpy(ret_name, dc->name, 40);

	ret_firmware_version[0] = dc->firmware_version[0];
	ret_firmware_version[1] = dc->firmware_version[1];
	ret_firmware_version[2] = dc->firmware_version[2];

	ret_binding_version[0] = dc->binding_version[0];
	ret_binding_version[1] = dc->binding_version[1];
	ret_binding_version[2] = dc->binding_version[2];

	return E_OK;
}

static int dc_callback_under_voltage(DC *dc, const unsigned char *buffer) {
	UnderVoltageCallback_ *uvc = (UnderVoltageCallback_ *)buffer;
	((under_voltage_func_t)dc->callbacks[uvc->function_id])(uvc->voltage);
	return sizeof(UnderVoltageCallback_);
}

static int dc_callback_emergency_shutdown(DC *dc, const unsigned char *buffer) {
	EmergencyShutdownCallback_ *esc = (EmergencyShutdownCallback_ *)buffer;
	((emergency_shutdown_func_t)dc->callbacks[esc->function_id])();
	return sizeof(EmergencyShutdownCallback_);
}

static int dc_callback_velocity_reached(DC *dc, const unsigned char *buffer) {
	VelocityReachedCallback_ *vrc = (VelocityReachedCallback_ *)buffer;
	((velocity_reached_func_t)dc->callbacks[vrc->function_id])(vrc->velocity);
	return sizeof(VelocityReachedCallback_);
}

static int dc_callback_current_velocity(DC *dc, const unsigned char *buffer) {
	CurrentVelocityCallback_ *cvc = (CurrentVelocityCallback_ *)buffer;
	((current_velocity_func_t)dc->callbacks[cvc->function_id])(cvc->velocity);
	return sizeof(CurrentVelocityCallback_);
}

void dc_register_callback(DC *dc, uint8_t cb, void *func) {
    dc->callbacks[cb] = func;
}

void dc_create(DC *dc, const char *uid) {
	ipcon_device_create(dc, uid);

	dc->expected_name = "DC Brick";

	dc->binding_version[0] = 1;
	dc->binding_version[1] = 0;
	dc->binding_version[2] = 0;

	dc->device_callbacks[DC_CALLBACK_UNDER_VOLTAGE] = dc_callback_under_voltage;
	dc->device_callbacks[DC_CALLBACK_EMERGENCY_SHUTDOWN] = dc_callback_emergency_shutdown;
	dc->device_callbacks[DC_CALLBACK_VELOCITY_REACHED] = dc_callback_velocity_reached;
	dc->device_callbacks[DC_CALLBACK_CURRENT_VELOCITY] = dc_callback_current_velocity;
}
