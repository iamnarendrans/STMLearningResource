/*
 * mpu6050.h
 *
 *  Created on: Dec 10, 2023
 *      Author: Narendran Srinivasan
 */

#ifndef INC_MPU6050_H_
#define INC_MPU6050_H_

#include "stdint.h"


// MPU6050 used base register address macros
#define RAD_TO_DEG	57.295779513082320876798154814105

#define WHO_AM_I_REG		0x75
#define PWR_MGMT_1_REG		0x6B
#define SMPLRT_DIV_REG		0x19
#define ACCEL_CFG_REG		0x1C
#define ACCEL_XOUT_H_REG	0x3B
#define TEMP_OUT_H_REG		0x41
#define GYRO_CFG_REG		0x1B
#define GYRO_XOUT_H_REG		0x43

// Setup MPU6050
#define MPU6050_SENSOR_ADDR	0x68
#define MPU6050_ADDR    	0x68 << 1

// Power Management macros
#define PWR_MGMR_SENSOR_WP	0

// Data rate definition macros
#define DATA_RATE_1KHZ		0x07	/* 8/(1+7)*/
#define DATA_RATE_2KHZ		0x03	/* 8/(1+3)*/
#define DATA_RATE_4KHZ		0x01	/* 8/(1+1)*/
#define DATA_RATE_8KHZ		0x00	/* 8/(1+0)*/

// Accelerometer Full Scale Range macros
#define ACCEL_FSR_2G		0
#define ACCEL_FSR_4G		1
#define ACCEL_FSR_8G		2
#define ACCEL_FSR_16G		3

// Gyroscope FSR Range macros
#define GYRO_FSR_250D		0
#define GYRO_FSR_500D		1
#define GYRO_FSR_1000D		2
#define GYRO_FSR_2000D		3

// MPU6050 Structure
typedef struct
{
	uint16_t Accel_X_RAW;
	uint16_t Accel_Y_RAW;
	uint16_t Accel_Z_RAW;
	double Ax;
	double Ay;
	double Az;

	uint16_t Gyro_X_RAW;
	uint16_t Gyro_Y_RAW;
	uint16_t Gyro_Z_RAW;
	double Gx;
	double Gy;
	double Gz;

	float temperature;

	double KalmanAngleX;
	double KalmanAngleY;

}MPU6050_t;


// Kalman Filter Structure
typedef struct
{
	double QAngle;
	double QBias;
	double RMeasure;
	double angle;
	double bias;
	double P[2][2];
}Kalman_t;


uint8_t MPU6050_Init(I2C_HandleTypeDef *I2Cx);

void MPU6050_Read_Accel(I2C_HandleTypeDef *I2Cx, MPU6050_t *DataStruct);

void MPU6050_Read_Gyro(I2C_HandleTypeDef *I2Cx, MPU6050_t *DataStruct);

void MPU6050_Read_Temp(I2C_HandleTypeDef *I2Cx, MPU6050_t *DataStruct);

void MPU6050_Read_All(I2C_HandleTypeDef *I2Cx, MPU6050_t *DataStruct);

double Kalman_getAngle(Kalman_t *kalman, double newAngle, double newRate, double dt);

#endif /* INC_MPU6050_H_ */
