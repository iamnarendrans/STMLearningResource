/*
 * PID_Test.c
 *
 *  Created on: Dec 8, 2023
 *      Author: Narendran Srinivasan
 */

#include <stdio.h>
#include <stdlib.h>

#include "PID.h"

/* Controller parameters */
#define PID_KP	2.0f
#define PID_KI	0.5f
#define PID_KD	0.25f

#define PID_TAU	0.02f

#define PID_LIM_MIN	-10.0f
#define PID_LIM_MAX	 10.0f

#define PID_LIM_MIN_INT -5.0f
#define PID_LIM_MAX_INT  5.0f

#define PID_SAMPLE_T_IN_S	0.01f

/* Maximum run-time of calculation */
#define SIMULATION_MAX_TIME	4.0f

/* Simulated dynamic system (first order) */
float TestSystemUpdateFirstOrder(float input);

float TestSystemUpdateFirstOrder(float input)
{
	static float output = 0.0f;
	static const float alpha = 0.02f;

	output = (PID_SAMPLE_T_IN_S * input + output) / (1.0f + alpha * PID_SAMPLE_T_IN_S);

	return output;
}

int main()
{
	/* Initialize the PID controller */
	PIDController pid = {PID_KP, PID_KI, PID_KD, PID_TAU,
						 PID_LIM_MIN, PID_LIM_MAX, PID_LIM_MIN_INT, PID_LIM_MAX_INT, PID_SAMPLE_T_IN_S};

	PIDControllerInit(&pid);

	/* Simulate the response using test system function */
	printf("Time(s)\tSystem Output\tController Output\r\n");
	for(float t = 0.0f; t <= SIMULATION_MAX_TIME; t += PID_SAMPLE_T_IN_S)
	{
		/* Getting the measurement from the predefine system */
		float measurement = TestSystemUpdateFirstOrder(pid.out);

		/* Compute new control signal */
		float setpoint = 10.0f;
		PIDControllerUpdate(&pid, setpoint, measurement);

		printf("%f\t%f\t%f\r\n", t, measurement, pid.out);

	}

	return 0;
}

