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


void PIDControllerUpdate(PIDController *pid, float setpoint, float measurement)
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




}
