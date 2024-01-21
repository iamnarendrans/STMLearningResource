/*
 * IIR.c
 *
 *  Created on: Dec 22, 2023
 *      Author: Narendran Srinivasan
 */

#include "IIR.h"


void IIRFirstOrder_Init(IIRFirstOrder *filt, float alpha)
{
	filt->alpha = alpha;
	filt->out = 0.0f;
}

float IIRFirstOrder_Update(IIRFirstOrder *filt, float in)
{
	filt->out = filt->alpha * filt->out + (1 - filt->alpha)*in;

	return filt->out;
}
