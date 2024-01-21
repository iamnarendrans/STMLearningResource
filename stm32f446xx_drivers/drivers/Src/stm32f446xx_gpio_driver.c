/*
 * stm32f446xx_gpio_driver.c
 *
 *  Created on: Nov 6, 2023
 *      Author: Narendran Srinivasan
 */

#include "stm32f446xx_gpio_driver.h"

/********************************************Peripheral Clock Control**********************************************/
/******************************************************************************************************************
 * @fn									- GPIO_PeriClockControl
 *
 * @brief								- This function enables or disables peripheral clock for the given GPIO Port
 *
 * @param[GPIO_RegDef_t *pGPIOx]		- Base Address of the GPIO Peripheral
 * @param[uint8_t EnorDi]				- Enabling/Disabling Clock of the peripheral
 *
 * @return								- None
 *
 * @note								- None
 *****************************************************************************************************************/
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi)
{
	if(EnorDi == ENABLE)
	{
		if(pGPIOx == GPIOA)
		{
			GPIOA_PCLK_EN();
		}
		else if(pGPIOx == GPIOB)
		{
			GPIOB_PCLK_EN();
		}
		else if(pGPIOx == GPIOC)
		{
			GPIOC_PCLK_EN();
		}
		else if(pGPIOx == GPIOD)
		{
			GPIOD_PCLK_EN();
		}else if(pGPIOx == GPIOE)
		{
			GPIOE_PCLK_EN();
		}
		else if(pGPIOx == GPIOF)
		{
			GPIOF_PCLK_EN();
		}
		else if(pGPIOx == GPIOG)
		{
			GPIOG_PCLK_EN();
		}
		else if(pGPIOx == GPIOH)
		{
			GPIOH_PCLK_EN();
		}
	}
	else
	{
		if(pGPIOx == GPIOA)
		{
			GPIOA_PCLK_DI();
		}
		else if(pGPIOx == GPIOB)
		{
			GPIOB_PCLK_DI();
		}
		else if(pGPIOx == GPIOC)
		{
			GPIOC_PCLK_DI();
		}
		else if(pGPIOx == GPIOD)
		{
			GPIOD_PCLK_DI();
		}else if(pGPIOx == GPIOE)
		{
			GPIOE_PCLK_DI();
		}
		else if(pGPIOx == GPIOF)
		{
			GPIOF_PCLK_EN();
		}
		else if(pGPIOx == GPIOG)
		{
			GPIOG_PCLK_DI();
		}
		else if(pGPIOx == GPIOH)
		{
			GPIOH_PCLK_DI();
		}
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/******************************************************************************************************************/

/*************************************************Init and DeInit**************************************************/
/******************************************************************************************************************
 * @fn									- GPIO_Init
 *
 * @brief								- This function will Initalize the GPIO Peripheral
 *
 * @param[GPIO_Handle_t *pGPIOHandle]	- Pointer to the Handle structure
 *
 * @return								- None
 *
 * @note								- None
 *****************************************************************************************************************/
void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{
	uint32_t temp = 0; // Temp register

	// Enable the peripheral clock
	GPIO_PeriClockControl(pGPIOHandle->pGPIOx, ENABLE);

	//1. Configure the mode of GPIO PIN
	if(pGPIOHandle -> GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ANALOG)
	{
		// Non interrupt mode
		temp = (pGPIOHandle -> GPIO_PinConfig.GPIO_PinMode << (2 * pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber));
		pGPIOHandle -> pGPIOx -> MODER &= ~(0x3 << pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber);	// Clearing
		pGPIOHandle -> pGPIOx -> MODER |= temp;	// Setting
	}
	else
	{
		// this part will code later (interrupt mode)
		if(pGPIOHandle -> GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_FT)
		{
			//1. Configure the FTSR
			EXTI ->FTSR |= (1 << pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber);
			// Clear the corresponding RTSR bit
			EXTI ->RTSR &= ~(1 << pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber);
		}
		else if(pGPIOHandle -> GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_RT)
		{
			//1. Configure the RTSR
			EXTI ->RTSR |= (1 << pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber);
			// Clear the corresponding FTSR bit
			EXTI ->FTSR &= ~(1 << pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber);
		}
		else if(pGPIOHandle -> GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_RFT)
		{
			//1. Configure both FTSR and RTSR
			EXTI ->RTSR |= (1 << pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber);

			EXTI ->FTSR |= (1 << pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber);
		}

		//2. Configure the GPIO port selection in SYSCFG_EXTICR
		uint8_t temp1 = pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber / 4;
		uint8_t temp2 = pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber % 4;
		uint8_t portcode = GPIO_BASEADDR_TO_CODE(pGPIOHandle ->pGPIOx);
		SYSCFG_PCLK_EN();
		SYSGFG -> EXTICR[temp1] = portcode << (temp2 * 4);

		//3. Enable the EXTI interrupt delivery using IMR
		EXTI->IMR |= (1 << pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber);

	}

	temp = 0;
	//2. Configure the Speed
	temp = (pGPIOHandle -> GPIO_PinConfig.GPIO_PinSpeed << (2 * pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle -> pGPIOx -> OSPEEDR &= ~(0x3 << pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber);	// clearing
	pGPIOHandle -> pGPIOx -> OSPEEDR |= temp;	// Setting

	temp = 0;
	//3. Configure the Push-pull settings
	temp = (pGPIOHandle -> GPIO_PinConfig.GPIO_PinPuPdControl << (2 * pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle -> pGPIOx -> PUPDR &= ~(0x3 << pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHandle -> pGPIOx -> PUPDR |= temp;

	temp = 0;
	//4. Configure the Output Type
	if(pGPIOHandle -> GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_OUT){
		temp = (pGPIOHandle -> GPIO_PinConfig.GPIO_PinOType << pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber);
		pGPIOHandle -> pGPIOx -> OTYPER &= ~(0x3 << pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber);
		pGPIOHandle -> pGPIOx -> OTYPER |= temp;
	}
	//5. Configure the Alternate functionality, if required
	if(pGPIOHandle -> GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_ALTFN)
	{
		// Configure the alternate function here
		uint8_t temp1, temp2;

		temp1 = pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber / 8;
		temp2 = pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber % 8;

		pGPIOHandle -> pGPIOx -> AFR[temp1] &= ~(0xF << (4 * temp2));
		pGPIOHandle -> pGPIOx -> AFR[temp1] |= pGPIOHandle -> GPIO_PinConfig.GPIO_PinAltFunMode << (4 * temp2);

	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/******************************************************************************************************************
 * @fn									- GPIO_DeInit
 *
 * @brief								- This function will DeInitalize the GPIO Peripheral
 *
 * @param[GPIO_RegDef_t *pGPIOx]		- Base Address of the GPIO Peripheral
 *
 * @return								- None
 *
 * @note								- None
 *****************************************************************************************************************/
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx)
{

	if(pGPIOx == GPIOA)
	{
		GPIOA_REG_RESET();
	}
	else if(pGPIOx == GPIOB)
	{
		GPIOB_REG_RESET();
	}
	else if(pGPIOx == GPIOC)
	{
		GPIOC_REG_RESET();
	}
	else if(pGPIOx == GPIOD)
	{
		GPIOD_REG_RESET();
	}
	else if(pGPIOx == GPIOE)
	{
		GPIOE_REG_RESET();
	}
	else if(pGPIOx == GPIOF)
	{
		GPIOF_REG_RESET();
	}
	else if(pGPIOx == GPIOG)
	{
		GPIOG_REG_RESET();
	}
	else if(pGPIOx == GPIOH)
	{
		GPIOH_REG_RESET();
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/******************************************************************************************************************/

/************************************************Data Read/Write APIs**********************************************/
/******************************************************************************************************************
 * @fn									- GPIO_ReadFromInputPin
 *
 * @brief								- This function will Read from particular GPIO Pin
 *
 * @param[GPIO_RegDef_t *pGPIOx]		- Base Address of the GPIO Peripheral
 * @param[uint8_t PinNumber]			- Pin Number to be selected
 *
 * @return								- Integer Either 0 or 1 [8 bit is enough]
 *
 * @note								- None
 *****************************************************************************************************************/
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	uint8_t value;

	value = (uint8_t)((pGPIOx -> IDR >> PinNumber) & 0x00000001);

	return value;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/******************************************************************************************************************
 * @fn									- GPIO_ReadFromInputPort
 *
 * @brief								- This function will Read from particular GPIO Port
 *
 * @param[GPIO_RegDef_t *pGPIOx]		- Base Address of the GPIO Peripheral
 *
 * @return								- Integer Either 0 or 1 [16 bit for 16 pins from a port]
 *
 * @note								- None
 *****************************************************************************************************************/
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx){

	uint16_t value;

	value = (uint16_t)pGPIOx -> IDR;

	return value;

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/******************************************************************************************************************
 * @fn									- GPIO_WriteToOutputPin
 *
 * @brief								- This function will write data into particular GPIO Pin
 *
 * @param[GPIO_RegDef_t *pGPIOx]		- Base Address of the GPIO Peripheral
 * @param[uint8_t PinNumber]			- Pin Number to be selected
 * @param[uint8_t Value]				- Pin set or Reset
 * @return								- None
 *
 * @note								- None
 *****************************************************************************************************************/
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value)
{

	if(Value == GPIO_PIN_SET)
	{
		// Write 1 to the output data register at the bit field corresponding to the pin number
		pGPIOx -> ODR |= (1 << PinNumber);
	}
	else
	{
		// Write 0 to the output data register at the bit field corresponding to the pin number
		pGPIOx -> ODR &= ~(1 << PinNumber);
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/******************************************************************************************************************
 * @fn									- GPIO_WriteToOutputPort
 *
 * @brief								- This function will write data into GPIO Port
 *
 * @param[GPIO_RegDef_t *pGPIOx]		- Base Address of the GPIO Peripheral
 * @param[uint16_t Value]				- Pin set or Reset
 * @return								- None
 *
 * @note								- None
 *****************************************************************************************************************/
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value)
{
	pGPIOx -> ODR |= Value;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/******************************************************************************************************************
 * @fn									- GPIO_ToggleOutputPin
 *
 * @brief								- This function will Toggle the GPIO Pin
 *
 * @param[GPIO_RegDef_t *pGPIOx]		- Base Address of the GPIO Peripheral
 * @param[uint8_t PinNumber]			- Pin Number to be selected
 * @return								- None
 *
 * @note								- None
 *****************************************************************************************************************/
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	pGPIOx -> ODR ^= (1 << PinNumber);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/******************************************************************************************************************/


/********************************************IRQ Configuration and ISR Handler*************************************/
/******************************************************************************************************************
 * @fn									- GPIO_IRQInterruptConfig
 *
 * @brief								- This function will config the Interrupt IRQ Number
 *
 * @param[uint8_t IRQNumber]			- Interrupt handler number
 * @param[uint8_t IRQPriority]			- Priority of the interrupt execution
 * @param[uint8_t EnorDi]				- Enabling/Disabling Clock of the peripheral
 * @return								- None
 *
 * @note								- None
 *****************************************************************************************************************/
void GPIO_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi)
{
	if(EnorDi == ENABLE){
		if(IRQNumber <= 31)
		{
			// Program ISER Register (bewteen 0 - 31)
			*NVIC_ISER0 |= (1 << IRQNumber);
		}

		else if(IRQNumber >= 31 && IRQNumber < 64)
		{
			// Program ISER1 Register (bewteen 32 - 63)
			 * NVIC_ISER1 |= (1 << (IRQNumber % 32));
		}
		else if(IRQNumber >= 64 && IRQNumber < 96)
		{
			// Program ISER2 Register (bewteen 64 - 95)
			 * NVIC_ISER2 |= (1 << (IRQNumber % 64));
		}

	}
	else
	{
		if(IRQNumber <= 31)
		{
			// Program ICER Register (bewteen 0 - 31)
			*NVIC_ICER0 |= (1 << IRQNumber);
		}

		else if(IRQNumber >= 31 && IRQNumber < 64)
		{
			// Program ICER1 Register (bewteen 32 - 63)
			 * NVIC_ICER1 |= (1 << (IRQNumber % 32));
		}
		else if(IRQNumber >= 64 && IRQNumber < 96)
		{
			// Program ISER2 Register (bewteen 64 - 95)
			 * NVIC_ICER2 |= (1 << (IRQNumber % 64));
		}
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/******************************************************************************************************************
 * @fn									- GPIO_IRQPriorityConfig
 *
 * @brief								- This function will configure the IRQ/Interrupt Priority Number
 *
 * @param[uint8_t IRQNumber]			- IRQ Number from the NVIC table
 * @param[uint32_t IRQPriority]			- Interrupt priority from the NVIC table
 *
 * @return								- None
 *
 * @note								- None
 *****************************************************************************************************************/
void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority)
{
	//1. First lets findout the IPR Register
	uint8_t iprx = IRQNumber / 4;
	uint8_t iprx_section = IRQNumber % 4;

	uint8_t shift_amount = (8 * iprx_section) + (8 - NO_PR_BITS_IMPLEMENTED);
	*(NVIC_PR_BASEADDR + iprx) |= (IRQPriority << shift_amount);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/******************************************************************************************************************
 * @fn									- GPIO_IRQHandling
 *
 * @brief								- This function will handle the IQR/ISR Interrupts
 *
 * @param[uint8_t PinNumber]			- Pin Number to be selected
 * @return								- None
 *
 * @note								- None
 *****************************************************************************************************************/
void GPIO_IRQHandling(uint8_t PinNumber)
{
	// Clear the EXTI PR register
	if(EXTI -> PR & (1 << PinNumber))
	{
		EXTI -> PR |= (1 << PinNumber);
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/******************************************************************************************************************/
