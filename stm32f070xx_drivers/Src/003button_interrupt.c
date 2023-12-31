/*
 * 001led_toggle.c
 *
 *  Created on: Nov 16, 2023
 *      Author: Narendran Srinivasan
 */

#include "stm32f070xx.h"
#include <string.h>

#define HIGH	1
#define LOW		0
#define BTN_PRESSED	LOW

void delay()
{
	for (uint32_t i; i <= 500000; i++);
}


int main(void)
{
	GPIO_Handle_t GpioLed, GPIOBtn;
	memset(&GpioLed, 0, sizeof(GpioLed));
	memset(&GPIOBtn, 0, sizeof(GPIOBtn));

	GpioLed.pGPIOx = GPIOA;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NUM_5;
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioLed.GPIO_PinConfig.GPIO_PinOType = GPIO_OP_TYPE_PP;
	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOA, ENABLE);

	GPIO_Init(&GpioLed);

	GPIOBtn.pGPIOx = GPIOC;
	GPIOBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NUM_13;
	GPIOBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IT_FT;
	GPIOBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GPIOBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU;

	GPIO_PeriClockControl(GPIOC, ENABLE);

	GPIO_Init(&GPIOBtn);

	GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_NUM_5, GPIO_PIN_RESET);
	// IRQ Configurations
	GPIO_IRQPriorityConfig(IRQ_NO_EXTI4_15, NVIC_IRQ_PRI15);
	GPIO_IRQInterruptConfig(IRQ_NO_EXTI4_15, ENABLE);

	while(1);

	return 0;
}


void EXTI4_15_IRQHandler(void)
{
	GPIO_IRQHandling(GPIO_PIN_NUM_13);
	GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_NUM_5);
}
