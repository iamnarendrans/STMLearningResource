/*
 * PID.h
 *
 *  Created on: Dec 8, 2023
 *      Author: Narendran Srinivasan
 */

#ifndef PID_H_
#define PID_H_


typedef struct
{
	//Controller gains
	float Kp;
	float Ki;
	float Kd;


	// Derivative low-pass filter timer constant
	float tau;


	// Output limits
	float limMin;
	float limMax;

	// Integrator limits
	float limMinInt;
	float limMaxInt;

	// Sample time in Seconds
	float Ts;

	// Controller memory
	float integrator;		/* Required for integrator*/
	float differentiator;	/* Required for differentiator*/
	float prevError;
	float prevMeasurement;


	// Controller output
	float out;

}PIDController;


void PIDControllerInit(PIDController *pid);

float PIDControllerUpdate(PIDController *pid, float setpoint, float measurement);

#endif /* PID_H_ */
