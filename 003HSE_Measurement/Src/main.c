/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>

#define RCC_BASE_ADDR			0x40021000UL

#define RCC_CFGR_REG_OFFSET		0x04UL

#define RCC_CR_REG_OFFSET		0x00UL

#define RCC_CFGR_REG_ADDR		(RCC_BASE_ADDR + RCC_CFGR_REG_OFFSET)

#define RCC_CR_REG_ADDR			(RCC_BASE_ADDR + RCC_CR_REG_OFFSET)

#define GPIOA_BASE_ADDR 		0x48000000UL

int main(void)
{

	uint32_t *pRccCrReg = (uint32_t*)RCC_CR_REG_ADDR;
	uint32_t *pRccCfgrReg = (uint32_t*)RCC_CFGR_REG_ADDR;


	// 1. Enable the HSE clock using HSEBYP bit (RCC_CR)
	*pRccCrReg |= (1 << 18);

	*pRccCrReg |= (1 << 16); // Enable HSEON bit (RCC_CR)

	// 2. Wait until the HSE clock from the external ST-Link crystal stabilizes
	while(!(*pRccCrReg & (1 << 17)));

	// 3. Switch the system clock to HSE (RCC_CFGR)
	*pRccCfgrReg &= ~(0x3 << 0); // Clearing the bit position
	*pRccCfgrReg |= (1 << 0); // setting the system clock as HSE

/********************************************MCO AF Activate**********************************************/

	// 1. Configure the RCC_CFGR Register MCO bit fields to select HSE as clock source
	*pRccCfgrReg &= ~(0x0F << 24); // Clear 24, 25, 26 and 27 bit positions

	// 2. Configure the RCC_CFGR Register MCO bit fields to select HSE as clock source
	*pRccCfgrReg |= (0x6 << 24); // setting up the corresponding bits to select HSE as clock source 0110

	// 2a Configure the Pre-scaler for the RCC clock configuration
	*pRccCfgrReg &= ~(0x7 << 28); // Clearing the bit positions

	// 2b. Configure the Pre-scaler for the RCC clock configuration
	*pRccCfgrReg |= (0x2 << 28); // Setting the bit positions for converting the HSE clock to 8Mhz / 4 = 2MHz
	// 3. Configure PA8 to AF0 mode to behave as MCO signal

	// 3a. Enable the peripheral clock for GPIOA peripheral
	uint32_t *pRCCAhbEnr = (uint32_t*)(RCC_BASE_ADDR + 0x14);
	*pRCCAhbEnr |= (1 << 17); // Enable the GPIOA peripheral Clock

	// 3b. Configure the mode of GPIOA pin 8 as alternate function mode
	uint32_t *pGPIOAModeReg = (uint32_t*)(GPIOA_BASE_ADDR + 0x00);
	*pGPIOAModeReg &= ~(0x3 << 16); // Clearing the bit positions
	*pGPIOAModeReg |= (0x2 << 16); // Setting the bit positions for alternate function mode 10

	// 3c. Configure the alternate function register to set the mode 0 for PA8
	uint32_t *pGPIOAAltFunHigReg = (uint32_t*)(GPIOA_BASE_ADDR + 0x24);
	*pGPIOAAltFunHigReg &= ~(0xF << 0);

	for(;;);
}
