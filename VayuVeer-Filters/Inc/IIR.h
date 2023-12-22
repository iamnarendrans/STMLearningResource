/*
 * IIR.h
 *
 *  Created on: Dec 22, 2023
 *      Author: Narendran Srinivasan
 */

#ifndef IIR_H_
#define IIR_H_

typedef struct
{
	float alpha;
	float out;
}IIRFirstOrder;

void IIRFirstOrder_Init(IIRFirstOrder *filt, float alpha);

float IIRFirstOrder_Update(IIRFirstOrder *filt, float in);

#endif /* IIR_H_ */
