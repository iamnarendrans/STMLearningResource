/*
 * FIR.c
 *
 *  Created on: Dec 11, 2023
 *      Author: Narendran Srinivasan
 */

#include "FIR.h"

void FIRFilter_Init(FIRFilter *filt, float *coeff, float *buf, const uint8_t order)
{
	filt->out = 0.0f;
	filt->coeff = coeff;
	filt->buf = buf;
	filt->order = order;
	filt->putIndex = 0;

	for(uint8_t n = 0; n < order; n++)
	{
		filt->buf[n] = 0.0f;
	}
}

void FIRFilter_update(FIRFilter *filt, float In);
