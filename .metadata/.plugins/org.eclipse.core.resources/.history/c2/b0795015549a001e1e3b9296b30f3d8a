/*
 * FIR.h
 *
 *  Created on: Dec 11, 2023
 *      Author: Narendran Srinivasan
 */

/*
 * Finite Impulse Response (FIR) Filter
 *
 * Implements a discrete-time FIR filter using a set of coefficients and a circular buffer
 * Transfer-funtion in z-domain as follows F(z) = C_0 + C_1 * Z^-1 + ........ + C_(N-1)*Z^(N-1)
 * Where C_n is the n-th coefficients and N is the filter order
 */


#ifndef FIR_H_
#define FIR_H_

#include <stdint.h>

typedef struct
{
	float out;
	float *coeff;
	float *buf;
	uint8_t order;
	uint8_t putIndex;

}FIRFilter;

void FIRFilter_Init(FIRFilter *filt, float *coeff, float *buf, const uint8_t order);

void FIRFilter_update(FIRFilter *filt, float In);


#endif /* FIR_H_ */
