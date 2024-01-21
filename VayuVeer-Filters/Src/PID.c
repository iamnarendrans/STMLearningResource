/*
 * PID.c
 *
 *  Created on: Dec 8, 2023
 *      Author: Narendran Srinivasan
 */
#include "PID.h"
#include <stdio.h>

void PIDControllerInit(PIDController *pid)
{

	// Clearing the controller variables

	pid->differentiator = 0.0f;
	pid->integrator = 0.0f;

	pid->prevError = 0.0f;
	pid->prevMeasurement = 0.0f;

	pid->out = 0.0f;

}


float PIDControllerUpdate(PIDController *pid, float setpoint, float measurement)
{

	/* Error Signal */
	float error = setpoint - measurement;

	/* Propotional Gain */
	float propotional = pid->Kp * error;

	/* Integrator Gain */
	pid->integrator = pid->integrator + 0.5f * pid->Ki * pid->Ts * (error + pid->prevError);

	/* Anti-windup clamping */
	if(pid->integrator > pid->limMaxInt)
	{
		pid->integrator = pid->limMaxInt;
	}
	else if(pid->integrator < pid->limMinInt)
	{
		pid->integrator = pid->limMinInt;
	}

	/* Derivative Gain with (band-limited differentiator) */

	/* Note: Derivative on measurement, therefore -ve sign in front of the below equation */
	pid->differentiator = -(2.0f * pid->Kd * (measurement - pid->prevMeasurement)
						+ (2.0f * pid->tau - pid->Ts) * pid->differentiator)
						/(2.0f * pid->tau - pid->Ts);

	/* Compute the output and apply limits */
	pid->out = propotional + pid->integrator + pid->differentiator;

	// Chec the output limits
	if(pid->out > pid->limMax)
	{
		pid->out = pid->limMax;
	}
	else if(pid->out < pid->limMin)
	{
		pid->out = pid->limMin;
	}

	/* Store the error and measurement for next update */
	pid->prevError = error;
	pid->prevMeasurement = measurement;

	/* Return the controller output */
	return pid->out;


}
