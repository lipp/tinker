/* ***********************************************************
 * This file was automatically generated on 2012-05-21.      *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generator git on tinkerforge.com                   *
 *************************************************************/

#include "brick_imu.h"

#include <string.h>

#define FUNCTION_GET_ACCELERATION 1
#define FUNCTION_GET_MAGNETIC_FIELD 2
#define FUNCTION_GET_ANGULAR_VELOCITY 3
#define FUNCTION_GET_ALL_DATA 4
#define FUNCTION_GET_ORIENTATION 5
#define FUNCTION_GET_QUATERNION 6
#define FUNCTION_GET_IMU_TEMPERATURE 7
#define FUNCTION_LEDS_ON 8
#define FUNCTION_LEDS_OFF 9
#define FUNCTION_ARE_LEDS_ON 10
#define FUNCTION_SET_ACCELERATION_RANGE 11
#define FUNCTION_GET_ACCELERATION_RANGE 12
#define FUNCTION_SET_MAGNETOMETER_RANGE 13
#define FUNCTION_GET_MAGNETOMETER_RANGE 14
#define FUNCTION_SET_CONVERGENCE_SPEED 15
#define FUNCTION_GET_CONVERGENCE_SPEED 16
#define FUNCTION_SET_CALIBRATION 17
#define FUNCTION_GET_CALIBRATION 18
#define FUNCTION_SET_ACCELERATION_PERIOD 19
#define FUNCTION_GET_ACCELERATION_PERIOD 20
#define FUNCTION_SET_MAGNETIC_FIELD_PERIOD 21
#define FUNCTION_GET_MAGNETIC_FIELD_PERIOD 22
#define FUNCTION_SET_ANGULAR_VELOCITY_PERIOD 23
#define FUNCTION_GET_ANGULAR_VELOCITY_PERIOD 24
#define FUNCTION_SET_ALL_DATA_PERIOD 25
#define FUNCTION_GET_ALL_DATA_PERIOD 26
#define FUNCTION_SET_ORIENTATION_PERIOD 27
#define FUNCTION_GET_ORIENTATION_PERIOD 28
#define FUNCTION_SET_QUATERNION_PERIOD 29
#define FUNCTION_GET_QUATERNION_PERIOD 30


typedef void (*acceleration_func_t)(int16_t, int16_t, int16_t);

typedef void (*magnetic_field_func_t)(int16_t, int16_t, int16_t);

typedef void (*angular_velocity_func_t)(int16_t, int16_t, int16_t);

typedef void (*all_data_func_t)(int16_t, int16_t, int16_t, int16_t, int16_t, int16_t, int16_t, int16_t, int16_t, int16_t);

typedef void (*orientation_func_t)(int16_t, int16_t, int16_t);

typedef void (*quaternion_func_t)(float, float, float, float);

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
} ATTRIBUTE_PACKED GetAcceleration_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	int16_t x;
	int16_t y;
	int16_t z;
} ATTRIBUTE_PACKED GetAccelerationReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED GetMagneticField_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	int16_t x;
	int16_t y;
	int16_t z;
} ATTRIBUTE_PACKED GetMagneticFieldReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED GetAngularVelocity_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	int16_t x;
	int16_t y;
	int16_t z;
} ATTRIBUTE_PACKED GetAngularVelocityReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED GetAllData_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	int16_t acc_x;
	int16_t acc_y;
	int16_t acc_z;
	int16_t mag_x;
	int16_t mag_y;
	int16_t mag_z;
	int16_t ang_x;
	int16_t ang_y;
	int16_t ang_z;
	int16_t temperature;
} ATTRIBUTE_PACKED GetAllDataReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED GetOrientation_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	int16_t roll;
	int16_t pitch;
	int16_t yaw;
} ATTRIBUTE_PACKED GetOrientationReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED GetQuaternion_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	float x;
	float y;
	float z;
	float w;
} ATTRIBUTE_PACKED GetQuaternionReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED GetIMUTemperature_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	int16_t temperature;
} ATTRIBUTE_PACKED GetIMUTemperatureReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED LedsOn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED LedsOff_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED AreLedsOn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	bool leds;
} ATTRIBUTE_PACKED AreLedsOnReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint8_t range;
} ATTRIBUTE_PACKED SetAccelerationRange_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED GetAccelerationRange_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint8_t range;
} ATTRIBUTE_PACKED GetAccelerationRangeReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint8_t range;
} ATTRIBUTE_PACKED SetMagnetometerRange_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED GetMagnetometerRange_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint8_t range;
} ATTRIBUTE_PACKED GetMagnetometerRangeReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint16_t speed;
} ATTRIBUTE_PACKED SetConvergenceSpeed_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED GetConvergenceSpeed_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint16_t speed;
} ATTRIBUTE_PACKED GetConvergenceSpeedReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint8_t typ;
	int16_t data[10];
} ATTRIBUTE_PACKED SetCalibration_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint8_t typ;
} ATTRIBUTE_PACKED GetCalibration_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	int16_t data[10];
} ATTRIBUTE_PACKED GetCalibrationReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint32_t period;
} ATTRIBUTE_PACKED SetAccelerationPeriod_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED GetAccelerationPeriod_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint32_t period;
} ATTRIBUTE_PACKED GetAccelerationPeriodReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint32_t period;
} ATTRIBUTE_PACKED SetMagneticFieldPeriod_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED GetMagneticFieldPeriod_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint32_t period;
} ATTRIBUTE_PACKED GetMagneticFieldPeriodReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint32_t period;
} ATTRIBUTE_PACKED SetAngularVelocityPeriod_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED GetAngularVelocityPeriod_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint32_t period;
} ATTRIBUTE_PACKED GetAngularVelocityPeriodReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint32_t period;
} ATTRIBUTE_PACKED SetAllDataPeriod_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED GetAllDataPeriod_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint32_t period;
} ATTRIBUTE_PACKED GetAllDataPeriodReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint32_t period;
} ATTRIBUTE_PACKED SetOrientationPeriod_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED GetOrientationPeriod_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint32_t period;
} ATTRIBUTE_PACKED GetOrientationPeriodReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint32_t period;
} ATTRIBUTE_PACKED SetQuaternionPeriod_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED GetQuaternionPeriod_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint32_t period;
} ATTRIBUTE_PACKED GetQuaternionPeriodReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	int16_t x;
	int16_t y;
	int16_t z;
} ATTRIBUTE_PACKED AccelerationCallback_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	int16_t x;
	int16_t y;
	int16_t z;
} ATTRIBUTE_PACKED MagneticFieldCallback_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	int16_t x;
	int16_t y;
	int16_t z;
} ATTRIBUTE_PACKED AngularVelocityCallback_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	int16_t acc_x;
	int16_t acc_y;
	int16_t acc_z;
	int16_t mag_x;
	int16_t mag_y;
	int16_t mag_z;
	int16_t ang_x;
	int16_t ang_y;
	int16_t ang_z;
	int16_t temperature;
} ATTRIBUTE_PACKED AllDataCallback_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	int16_t roll;
	int16_t pitch;
	int16_t yaw;
} ATTRIBUTE_PACKED OrientationCallback_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	float x;
	float y;
	float z;
	float w;
} ATTRIBUTE_PACKED QuaternionCallback_;

#if defined _MSC_VER || defined __BORLANDC__
	#pragma pack(pop)
#endif
#undef ATTRIBUTE_PACKED

int imu_get_acceleration(IMU *imu, int16_t *ret_x, int16_t *ret_y, int16_t *ret_z) {
	if(imu->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(imu);

	imu->answer.function_id = FUNCTION_GET_ACCELERATION;
	imu->answer.length = sizeof(GetAccelerationReturn_);
	GetAcceleration_ ga;
	ga.stack_id = imu->stack_id;
	ga.function_id = FUNCTION_GET_ACCELERATION;
	ga.length = sizeof(GetAcceleration_);

	ipcon_device_write(imu, (char *)&ga, sizeof(GetAcceleration_));

	if(ipcon_answer_sem_wait_timeout(imu) != 0) {
		ipcon_sem_post_write(imu);
		return E_TIMEOUT;
	}

	GetAccelerationReturn_ *gar = (GetAccelerationReturn_ *)imu->answer.buffer;
	*ret_x = gar->x;
	*ret_y = gar->y;
	*ret_z = gar->z;

	ipcon_sem_post_write(imu);

	return E_OK;
}

int imu_get_magnetic_field(IMU *imu, int16_t *ret_x, int16_t *ret_y, int16_t *ret_z) {
	if(imu->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(imu);

	imu->answer.function_id = FUNCTION_GET_MAGNETIC_FIELD;
	imu->answer.length = sizeof(GetMagneticFieldReturn_);
	GetMagneticField_ gmf;
	gmf.stack_id = imu->stack_id;
	gmf.function_id = FUNCTION_GET_MAGNETIC_FIELD;
	gmf.length = sizeof(GetMagneticField_);

	ipcon_device_write(imu, (char *)&gmf, sizeof(GetMagneticField_));

	if(ipcon_answer_sem_wait_timeout(imu) != 0) {
		ipcon_sem_post_write(imu);
		return E_TIMEOUT;
	}

	GetMagneticFieldReturn_ *gmfr = (GetMagneticFieldReturn_ *)imu->answer.buffer;
	*ret_x = gmfr->x;
	*ret_y = gmfr->y;
	*ret_z = gmfr->z;

	ipcon_sem_post_write(imu);

	return E_OK;
}

int imu_get_angular_velocity(IMU *imu, int16_t *ret_x, int16_t *ret_y, int16_t *ret_z) {
	if(imu->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(imu);

	imu->answer.function_id = FUNCTION_GET_ANGULAR_VELOCITY;
	imu->answer.length = sizeof(GetAngularVelocityReturn_);
	GetAngularVelocity_ gav;
	gav.stack_id = imu->stack_id;
	gav.function_id = FUNCTION_GET_ANGULAR_VELOCITY;
	gav.length = sizeof(GetAngularVelocity_);

	ipcon_device_write(imu, (char *)&gav, sizeof(GetAngularVelocity_));

	if(ipcon_answer_sem_wait_timeout(imu) != 0) {
		ipcon_sem_post_write(imu);
		return E_TIMEOUT;
	}

	GetAngularVelocityReturn_ *gavr = (GetAngularVelocityReturn_ *)imu->answer.buffer;
	*ret_x = gavr->x;
	*ret_y = gavr->y;
	*ret_z = gavr->z;

	ipcon_sem_post_write(imu);

	return E_OK;
}

int imu_get_all_data(IMU *imu, int16_t *ret_acc_x, int16_t *ret_acc_y, int16_t *ret_acc_z, int16_t *ret_mag_x, int16_t *ret_mag_y, int16_t *ret_mag_z, int16_t *ret_ang_x, int16_t *ret_ang_y, int16_t *ret_ang_z, int16_t *ret_temperature) {
	if(imu->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(imu);

	imu->answer.function_id = FUNCTION_GET_ALL_DATA;
	imu->answer.length = sizeof(GetAllDataReturn_);
	GetAllData_ gad;
	gad.stack_id = imu->stack_id;
	gad.function_id = FUNCTION_GET_ALL_DATA;
	gad.length = sizeof(GetAllData_);

	ipcon_device_write(imu, (char *)&gad, sizeof(GetAllData_));

	if(ipcon_answer_sem_wait_timeout(imu) != 0) {
		ipcon_sem_post_write(imu);
		return E_TIMEOUT;
	}

	GetAllDataReturn_ *gadr = (GetAllDataReturn_ *)imu->answer.buffer;
	*ret_acc_x = gadr->acc_x;
	*ret_acc_y = gadr->acc_y;
	*ret_acc_z = gadr->acc_z;
	*ret_mag_x = gadr->mag_x;
	*ret_mag_y = gadr->mag_y;
	*ret_mag_z = gadr->mag_z;
	*ret_ang_x = gadr->ang_x;
	*ret_ang_y = gadr->ang_y;
	*ret_ang_z = gadr->ang_z;
	*ret_temperature = gadr->temperature;

	ipcon_sem_post_write(imu);

	return E_OK;
}

int imu_get_orientation(IMU *imu, int16_t *ret_roll, int16_t *ret_pitch, int16_t *ret_yaw) {
	if(imu->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(imu);

	imu->answer.function_id = FUNCTION_GET_ORIENTATION;
	imu->answer.length = sizeof(GetOrientationReturn_);
	GetOrientation_ go;
	go.stack_id = imu->stack_id;
	go.function_id = FUNCTION_GET_ORIENTATION;
	go.length = sizeof(GetOrientation_);

	ipcon_device_write(imu, (char *)&go, sizeof(GetOrientation_));

	if(ipcon_answer_sem_wait_timeout(imu) != 0) {
		ipcon_sem_post_write(imu);
		return E_TIMEOUT;
	}

	GetOrientationReturn_ *gor = (GetOrientationReturn_ *)imu->answer.buffer;
	*ret_roll = gor->roll;
	*ret_pitch = gor->pitch;
	*ret_yaw = gor->yaw;

	ipcon_sem_post_write(imu);

	return E_OK;
}

int imu_get_quaternion(IMU *imu, float *ret_x, float *ret_y, float *ret_z, float *ret_w) {
	if(imu->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(imu);

	imu->answer.function_id = FUNCTION_GET_QUATERNION;
	imu->answer.length = sizeof(GetQuaternionReturn_);
	GetQuaternion_ gq;
	gq.stack_id = imu->stack_id;
	gq.function_id = FUNCTION_GET_QUATERNION;
	gq.length = sizeof(GetQuaternion_);

	ipcon_device_write(imu, (char *)&gq, sizeof(GetQuaternion_));

	if(ipcon_answer_sem_wait_timeout(imu) != 0) {
		ipcon_sem_post_write(imu);
		return E_TIMEOUT;
	}

	GetQuaternionReturn_ *gqr = (GetQuaternionReturn_ *)imu->answer.buffer;
	*ret_x = gqr->x;
	*ret_y = gqr->y;
	*ret_z = gqr->z;
	*ret_w = gqr->w;

	ipcon_sem_post_write(imu);

	return E_OK;
}

int imu_get_imu_temperature(IMU *imu, int16_t *ret_temperature) {
	if(imu->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(imu);

	imu->answer.function_id = FUNCTION_GET_IMU_TEMPERATURE;
	imu->answer.length = sizeof(GetIMUTemperatureReturn_);
	GetIMUTemperature_ git;
	git.stack_id = imu->stack_id;
	git.function_id = FUNCTION_GET_IMU_TEMPERATURE;
	git.length = sizeof(GetIMUTemperature_);

	ipcon_device_write(imu, (char *)&git, sizeof(GetIMUTemperature_));

	if(ipcon_answer_sem_wait_timeout(imu) != 0) {
		ipcon_sem_post_write(imu);
		return E_TIMEOUT;
	}

	GetIMUTemperatureReturn_ *gitr = (GetIMUTemperatureReturn_ *)imu->answer.buffer;
	*ret_temperature = gitr->temperature;

	ipcon_sem_post_write(imu);

	return E_OK;
}

int imu_leds_on(IMU *imu) {
	if(imu->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(imu);

	LedsOn_ lo;
	lo.stack_id = imu->stack_id;
	lo.function_id = FUNCTION_LEDS_ON;
	lo.length = sizeof(LedsOn_);

	ipcon_device_write(imu, (char *)&lo, sizeof(LedsOn_));

	ipcon_sem_post_write(imu);

	return E_OK;
}

int imu_leds_off(IMU *imu) {
	if(imu->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(imu);

	LedsOff_ lo;
	lo.stack_id = imu->stack_id;
	lo.function_id = FUNCTION_LEDS_OFF;
	lo.length = sizeof(LedsOff_);

	ipcon_device_write(imu, (char *)&lo, sizeof(LedsOff_));

	ipcon_sem_post_write(imu);

	return E_OK;
}

int imu_are_leds_on(IMU *imu, bool *ret_leds) {
	if(imu->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(imu);

	imu->answer.function_id = FUNCTION_ARE_LEDS_ON;
	imu->answer.length = sizeof(AreLedsOnReturn_);
	AreLedsOn_ alo;
	alo.stack_id = imu->stack_id;
	alo.function_id = FUNCTION_ARE_LEDS_ON;
	alo.length = sizeof(AreLedsOn_);

	ipcon_device_write(imu, (char *)&alo, sizeof(AreLedsOn_));

	if(ipcon_answer_sem_wait_timeout(imu) != 0) {
		ipcon_sem_post_write(imu);
		return E_TIMEOUT;
	}

	AreLedsOnReturn_ *alor = (AreLedsOnReturn_ *)imu->answer.buffer;
	*ret_leds = alor->leds;

	ipcon_sem_post_write(imu);

	return E_OK;
}

int imu_set_acceleration_range(IMU *imu, uint8_t range) {
	if(imu->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(imu);

	SetAccelerationRange_ sar;
	sar.stack_id = imu->stack_id;
	sar.function_id = FUNCTION_SET_ACCELERATION_RANGE;
	sar.length = sizeof(SetAccelerationRange_);
	sar.range = range;

	ipcon_device_write(imu, (char *)&sar, sizeof(SetAccelerationRange_));

	ipcon_sem_post_write(imu);

	return E_OK;
}

int imu_get_acceleration_range(IMU *imu, uint8_t *ret_range) {
	if(imu->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(imu);

	imu->answer.function_id = FUNCTION_GET_ACCELERATION_RANGE;
	imu->answer.length = sizeof(GetAccelerationRangeReturn_);
	GetAccelerationRange_ gar;
	gar.stack_id = imu->stack_id;
	gar.function_id = FUNCTION_GET_ACCELERATION_RANGE;
	gar.length = sizeof(GetAccelerationRange_);

	ipcon_device_write(imu, (char *)&gar, sizeof(GetAccelerationRange_));

	if(ipcon_answer_sem_wait_timeout(imu) != 0) {
		ipcon_sem_post_write(imu);
		return E_TIMEOUT;
	}

	GetAccelerationRangeReturn_ *garr = (GetAccelerationRangeReturn_ *)imu->answer.buffer;
	*ret_range = garr->range;

	ipcon_sem_post_write(imu);

	return E_OK;
}

int imu_set_magnetometer_range(IMU *imu, uint8_t range) {
	if(imu->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(imu);

	SetMagnetometerRange_ smr;
	smr.stack_id = imu->stack_id;
	smr.function_id = FUNCTION_SET_MAGNETOMETER_RANGE;
	smr.length = sizeof(SetMagnetometerRange_);
	smr.range = range;

	ipcon_device_write(imu, (char *)&smr, sizeof(SetMagnetometerRange_));

	ipcon_sem_post_write(imu);

	return E_OK;
}

int imu_get_magnetometer_range(IMU *imu, uint8_t *ret_range) {
	if(imu->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(imu);

	imu->answer.function_id = FUNCTION_GET_MAGNETOMETER_RANGE;
	imu->answer.length = sizeof(GetMagnetometerRangeReturn_);
	GetMagnetometerRange_ gmr;
	gmr.stack_id = imu->stack_id;
	gmr.function_id = FUNCTION_GET_MAGNETOMETER_RANGE;
	gmr.length = sizeof(GetMagnetometerRange_);

	ipcon_device_write(imu, (char *)&gmr, sizeof(GetMagnetometerRange_));

	if(ipcon_answer_sem_wait_timeout(imu) != 0) {
		ipcon_sem_post_write(imu);
		return E_TIMEOUT;
	}

	GetMagnetometerRangeReturn_ *gmrr = (GetMagnetometerRangeReturn_ *)imu->answer.buffer;
	*ret_range = gmrr->range;

	ipcon_sem_post_write(imu);

	return E_OK;
}

int imu_set_convergence_speed(IMU *imu, uint16_t speed) {
	if(imu->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(imu);

	SetConvergenceSpeed_ scs;
	scs.stack_id = imu->stack_id;
	scs.function_id = FUNCTION_SET_CONVERGENCE_SPEED;
	scs.length = sizeof(SetConvergenceSpeed_);
	scs.speed = speed;

	ipcon_device_write(imu, (char *)&scs, sizeof(SetConvergenceSpeed_));

	ipcon_sem_post_write(imu);

	return E_OK;
}

int imu_get_convergence_speed(IMU *imu, uint16_t *ret_speed) {
	if(imu->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(imu);

	imu->answer.function_id = FUNCTION_GET_CONVERGENCE_SPEED;
	imu->answer.length = sizeof(GetConvergenceSpeedReturn_);
	GetConvergenceSpeed_ gcs;
	gcs.stack_id = imu->stack_id;
	gcs.function_id = FUNCTION_GET_CONVERGENCE_SPEED;
	gcs.length = sizeof(GetConvergenceSpeed_);

	ipcon_device_write(imu, (char *)&gcs, sizeof(GetConvergenceSpeed_));

	if(ipcon_answer_sem_wait_timeout(imu) != 0) {
		ipcon_sem_post_write(imu);
		return E_TIMEOUT;
	}

	GetConvergenceSpeedReturn_ *gcsr = (GetConvergenceSpeedReturn_ *)imu->answer.buffer;
	*ret_speed = gcsr->speed;

	ipcon_sem_post_write(imu);

	return E_OK;
}

int imu_set_calibration(IMU *imu, uint8_t typ, int16_t data[10]) {
	if(imu->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(imu);

	SetCalibration_ sc;
	sc.stack_id = imu->stack_id;
	sc.function_id = FUNCTION_SET_CALIBRATION;
	sc.length = sizeof(SetCalibration_);
	sc.typ = typ;
	memcpy(sc.data, data, 10*sizeof(int16_t));

	ipcon_device_write(imu, (char *)&sc, sizeof(SetCalibration_));

	ipcon_sem_post_write(imu);

	return E_OK;
}

int imu_get_calibration(IMU *imu, uint8_t typ, int16_t ret_data[10]) {
	if(imu->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(imu);

	imu->answer.function_id = FUNCTION_GET_CALIBRATION;
	imu->answer.length = sizeof(GetCalibrationReturn_);
	GetCalibration_ gc;
	gc.stack_id = imu->stack_id;
	gc.function_id = FUNCTION_GET_CALIBRATION;
	gc.length = sizeof(GetCalibration_);
	gc.typ = typ;

	ipcon_device_write(imu, (char *)&gc, sizeof(GetCalibration_));

	if(ipcon_answer_sem_wait_timeout(imu) != 0) {
		ipcon_sem_post_write(imu);
		return E_TIMEOUT;
	}

	GetCalibrationReturn_ *gcr = (GetCalibrationReturn_ *)imu->answer.buffer;
	memcpy(ret_data, gcr->data, 10*sizeof(int16_t));

	ipcon_sem_post_write(imu);

	return E_OK;
}

int imu_set_acceleration_period(IMU *imu, uint32_t period) {
	if(imu->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(imu);

	SetAccelerationPeriod_ sap;
	sap.stack_id = imu->stack_id;
	sap.function_id = FUNCTION_SET_ACCELERATION_PERIOD;
	sap.length = sizeof(SetAccelerationPeriod_);
	sap.period = period;

	ipcon_device_write(imu, (char *)&sap, sizeof(SetAccelerationPeriod_));

	ipcon_sem_post_write(imu);

	return E_OK;
}

int imu_get_acceleration_period(IMU *imu, uint32_t *ret_period) {
	if(imu->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(imu);

	imu->answer.function_id = FUNCTION_GET_ACCELERATION_PERIOD;
	imu->answer.length = sizeof(GetAccelerationPeriodReturn_);
	GetAccelerationPeriod_ gap;
	gap.stack_id = imu->stack_id;
	gap.function_id = FUNCTION_GET_ACCELERATION_PERIOD;
	gap.length = sizeof(GetAccelerationPeriod_);

	ipcon_device_write(imu, (char *)&gap, sizeof(GetAccelerationPeriod_));

	if(ipcon_answer_sem_wait_timeout(imu) != 0) {
		ipcon_sem_post_write(imu);
		return E_TIMEOUT;
	}

	GetAccelerationPeriodReturn_ *gapr = (GetAccelerationPeriodReturn_ *)imu->answer.buffer;
	*ret_period = gapr->period;

	ipcon_sem_post_write(imu);

	return E_OK;
}

int imu_set_magnetic_field_period(IMU *imu, uint32_t period) {
	if(imu->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(imu);

	SetMagneticFieldPeriod_ smfp;
	smfp.stack_id = imu->stack_id;
	smfp.function_id = FUNCTION_SET_MAGNETIC_FIELD_PERIOD;
	smfp.length = sizeof(SetMagneticFieldPeriod_);
	smfp.period = period;

	ipcon_device_write(imu, (char *)&smfp, sizeof(SetMagneticFieldPeriod_));

	ipcon_sem_post_write(imu);

	return E_OK;
}

int imu_get_magnetic_field_period(IMU *imu, uint32_t *ret_period) {
	if(imu->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(imu);

	imu->answer.function_id = FUNCTION_GET_MAGNETIC_FIELD_PERIOD;
	imu->answer.length = sizeof(GetMagneticFieldPeriodReturn_);
	GetMagneticFieldPeriod_ gmfp;
	gmfp.stack_id = imu->stack_id;
	gmfp.function_id = FUNCTION_GET_MAGNETIC_FIELD_PERIOD;
	gmfp.length = sizeof(GetMagneticFieldPeriod_);

	ipcon_device_write(imu, (char *)&gmfp, sizeof(GetMagneticFieldPeriod_));

	if(ipcon_answer_sem_wait_timeout(imu) != 0) {
		ipcon_sem_post_write(imu);
		return E_TIMEOUT;
	}

	GetMagneticFieldPeriodReturn_ *gmfpr = (GetMagneticFieldPeriodReturn_ *)imu->answer.buffer;
	*ret_period = gmfpr->period;

	ipcon_sem_post_write(imu);

	return E_OK;
}

int imu_set_angular_velocity_period(IMU *imu, uint32_t period) {
	if(imu->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(imu);

	SetAngularVelocityPeriod_ savp;
	savp.stack_id = imu->stack_id;
	savp.function_id = FUNCTION_SET_ANGULAR_VELOCITY_PERIOD;
	savp.length = sizeof(SetAngularVelocityPeriod_);
	savp.period = period;

	ipcon_device_write(imu, (char *)&savp, sizeof(SetAngularVelocityPeriod_));

	ipcon_sem_post_write(imu);

	return E_OK;
}

int imu_get_angular_velocity_period(IMU *imu, uint32_t *ret_period) {
	if(imu->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(imu);

	imu->answer.function_id = FUNCTION_GET_ANGULAR_VELOCITY_PERIOD;
	imu->answer.length = sizeof(GetAngularVelocityPeriodReturn_);
	GetAngularVelocityPeriod_ gavp;
	gavp.stack_id = imu->stack_id;
	gavp.function_id = FUNCTION_GET_ANGULAR_VELOCITY_PERIOD;
	gavp.length = sizeof(GetAngularVelocityPeriod_);

	ipcon_device_write(imu, (char *)&gavp, sizeof(GetAngularVelocityPeriod_));

	if(ipcon_answer_sem_wait_timeout(imu) != 0) {
		ipcon_sem_post_write(imu);
		return E_TIMEOUT;
	}

	GetAngularVelocityPeriodReturn_ *gavpr = (GetAngularVelocityPeriodReturn_ *)imu->answer.buffer;
	*ret_period = gavpr->period;

	ipcon_sem_post_write(imu);

	return E_OK;
}

int imu_set_all_data_period(IMU *imu, uint32_t period) {
	if(imu->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(imu);

	SetAllDataPeriod_ sadp;
	sadp.stack_id = imu->stack_id;
	sadp.function_id = FUNCTION_SET_ALL_DATA_PERIOD;
	sadp.length = sizeof(SetAllDataPeriod_);
	sadp.period = period;

	ipcon_device_write(imu, (char *)&sadp, sizeof(SetAllDataPeriod_));

	ipcon_sem_post_write(imu);

	return E_OK;
}

int imu_get_all_data_period(IMU *imu, uint32_t *ret_period) {
	if(imu->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(imu);

	imu->answer.function_id = FUNCTION_GET_ALL_DATA_PERIOD;
	imu->answer.length = sizeof(GetAllDataPeriodReturn_);
	GetAllDataPeriod_ gadp;
	gadp.stack_id = imu->stack_id;
	gadp.function_id = FUNCTION_GET_ALL_DATA_PERIOD;
	gadp.length = sizeof(GetAllDataPeriod_);

	ipcon_device_write(imu, (char *)&gadp, sizeof(GetAllDataPeriod_));

	if(ipcon_answer_sem_wait_timeout(imu) != 0) {
		ipcon_sem_post_write(imu);
		return E_TIMEOUT;
	}

	GetAllDataPeriodReturn_ *gadpr = (GetAllDataPeriodReturn_ *)imu->answer.buffer;
	*ret_period = gadpr->period;

	ipcon_sem_post_write(imu);

	return E_OK;
}

int imu_set_orientation_period(IMU *imu, uint32_t period) {
	if(imu->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(imu);

	SetOrientationPeriod_ sop;
	sop.stack_id = imu->stack_id;
	sop.function_id = FUNCTION_SET_ORIENTATION_PERIOD;
	sop.length = sizeof(SetOrientationPeriod_);
	sop.period = period;

	ipcon_device_write(imu, (char *)&sop, sizeof(SetOrientationPeriod_));

	ipcon_sem_post_write(imu);

	return E_OK;
}

int imu_get_orientation_period(IMU *imu, uint32_t *ret_period) {
	if(imu->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(imu);

	imu->answer.function_id = FUNCTION_GET_ORIENTATION_PERIOD;
	imu->answer.length = sizeof(GetOrientationPeriodReturn_);
	GetOrientationPeriod_ gop;
	gop.stack_id = imu->stack_id;
	gop.function_id = FUNCTION_GET_ORIENTATION_PERIOD;
	gop.length = sizeof(GetOrientationPeriod_);

	ipcon_device_write(imu, (char *)&gop, sizeof(GetOrientationPeriod_));

	if(ipcon_answer_sem_wait_timeout(imu) != 0) {
		ipcon_sem_post_write(imu);
		return E_TIMEOUT;
	}

	GetOrientationPeriodReturn_ *gopr = (GetOrientationPeriodReturn_ *)imu->answer.buffer;
	*ret_period = gopr->period;

	ipcon_sem_post_write(imu);

	return E_OK;
}

int imu_set_quaternion_period(IMU *imu, uint32_t period) {
	if(imu->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(imu);

	SetQuaternionPeriod_ sqp;
	sqp.stack_id = imu->stack_id;
	sqp.function_id = FUNCTION_SET_QUATERNION_PERIOD;
	sqp.length = sizeof(SetQuaternionPeriod_);
	sqp.period = period;

	ipcon_device_write(imu, (char *)&sqp, sizeof(SetQuaternionPeriod_));

	ipcon_sem_post_write(imu);

	return E_OK;
}

int imu_get_quaternion_period(IMU *imu, uint32_t *ret_period) {
	if(imu->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(imu);

	imu->answer.function_id = FUNCTION_GET_QUATERNION_PERIOD;
	imu->answer.length = sizeof(GetQuaternionPeriodReturn_);
	GetQuaternionPeriod_ gqp;
	gqp.stack_id = imu->stack_id;
	gqp.function_id = FUNCTION_GET_QUATERNION_PERIOD;
	gqp.length = sizeof(GetQuaternionPeriod_);

	ipcon_device_write(imu, (char *)&gqp, sizeof(GetQuaternionPeriod_));

	if(ipcon_answer_sem_wait_timeout(imu) != 0) {
		ipcon_sem_post_write(imu);
		return E_TIMEOUT;
	}

	GetQuaternionPeriodReturn_ *gqpr = (GetQuaternionPeriodReturn_ *)imu->answer.buffer;
	*ret_period = gqpr->period;

	ipcon_sem_post_write(imu);

	return E_OK;
}

int imu_get_version(IMU *imu, char ret_name[40], uint8_t ret_firmware_version[3], uint8_t ret_binding_version[3]) {
	strncpy(ret_name, imu->name, 40);

	ret_firmware_version[0] = imu->firmware_version[0];
	ret_firmware_version[1] = imu->firmware_version[1];
	ret_firmware_version[2] = imu->firmware_version[2];

	ret_binding_version[0] = imu->binding_version[0];
	ret_binding_version[1] = imu->binding_version[1];
	ret_binding_version[2] = imu->binding_version[2];

	return E_OK;
}

static int imu_callback_acceleration(IMU *imu, const unsigned char *buffer) {
	AccelerationCallback_ *ac = (AccelerationCallback_ *)buffer;
	((acceleration_func_t)imu->callbacks[ac->function_id])(ac->x, ac->y, ac->z);
	return sizeof(AccelerationCallback_);
}

static int imu_callback_magnetic_field(IMU *imu, const unsigned char *buffer) {
	MagneticFieldCallback_ *mfc = (MagneticFieldCallback_ *)buffer;
	((magnetic_field_func_t)imu->callbacks[mfc->function_id])(mfc->x, mfc->y, mfc->z);
	return sizeof(MagneticFieldCallback_);
}

static int imu_callback_angular_velocity(IMU *imu, const unsigned char *buffer) {
	AngularVelocityCallback_ *avc = (AngularVelocityCallback_ *)buffer;
	((angular_velocity_func_t)imu->callbacks[avc->function_id])(avc->x, avc->y, avc->z);
	return sizeof(AngularVelocityCallback_);
}

static int imu_callback_all_data(IMU *imu, const unsigned char *buffer) {
	AllDataCallback_ *adc = (AllDataCallback_ *)buffer;
	((all_data_func_t)imu->callbacks[adc->function_id])(adc->acc_x, adc->acc_y, adc->acc_z, adc->mag_x, adc->mag_y, adc->mag_z, adc->ang_x, adc->ang_y, adc->ang_z, adc->temperature);
	return sizeof(AllDataCallback_);
}

static int imu_callback_orientation(IMU *imu, const unsigned char *buffer) {
	OrientationCallback_ *oc = (OrientationCallback_ *)buffer;
	((orientation_func_t)imu->callbacks[oc->function_id])(oc->roll, oc->pitch, oc->yaw);
	return sizeof(OrientationCallback_);
}

static int imu_callback_quaternion(IMU *imu, const unsigned char *buffer) {
	QuaternionCallback_ *qc = (QuaternionCallback_ *)buffer;
	((quaternion_func_t)imu->callbacks[qc->function_id])(qc->x, qc->y, qc->z, qc->w);
	return sizeof(QuaternionCallback_);
}

void imu_register_callback(IMU *imu, uint8_t cb, void *func) {
    imu->callbacks[cb] = func;
}

void imu_create(IMU *imu, const char *uid) {
	ipcon_device_create(imu, uid);

	imu->expected_name = "IMU Brick";

	imu->binding_version[0] = 1;
	imu->binding_version[1] = 0;
	imu->binding_version[2] = 0;

	imu->device_callbacks[IMU_CALLBACK_ACCELERATION] = imu_callback_acceleration;
	imu->device_callbacks[IMU_CALLBACK_MAGNETIC_FIELD] = imu_callback_magnetic_field;
	imu->device_callbacks[IMU_CALLBACK_ANGULAR_VELOCITY] = imu_callback_angular_velocity;
	imu->device_callbacks[IMU_CALLBACK_ALL_DATA] = imu_callback_all_data;
	imu->device_callbacks[IMU_CALLBACK_ORIENTATION] = imu_callback_orientation;
	imu->device_callbacks[IMU_CALLBACK_QUATERNION] = imu_callback_quaternion;
}
