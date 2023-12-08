/*
 * PID.c
 *
 *  Created on: Dec 8, 2023
 *      Author: Narendran Srinivasan
 */
#include "PID.h"
#include "stdio.h"

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



}