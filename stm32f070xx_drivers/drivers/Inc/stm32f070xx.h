/*
 * stm32f070xx.h
 *
 *  Created on: Nov 5, 2023
 *      Author: Narendran Srinivasan
 */

#ifndef INC_STM32F070XX_H_
#define INC_STM32F070XX_H_

#include <stdint.h>

#define __vo volatile

/**********************************************START: PROCESSOR SPECIFIC DETAILS***********************************************************
 * 									   ARM Cortex Mx Processor NVIC register Addresses
 ******************************************************************************************************************************************/

#define NVIC_ISER			((__vo uint32_t*)0xE000E100)		/*!Interrupt Set-enable Register*/
#define NVIC_ICER			((__vo uint32_t*)0xE000E180)		/*!Interrupt Clear-enable Register*/
#define NVIC_ISPR			((__vo uint32_t*)0xE000E200)		/*!Interrupt Set-pending Register*/
#define NVIC_ICPR			((__vo uint32_t*)0xE000E280)		/*!Interrupt Clear-pending Register*/

#define NVIC_PR_BASEADDR		((__vo uint32_t*)0xE000E400)		/*!Interrupt Priority Registers 0*/

#define NO_PR_BITS_IMPLEMENTED		4					/*! Number of priority bits implemented in STM, will differ for other MCUs*/


/**********************************************END: PROCESSOR SPECIFIC DETAILS*************************************************************/

/**********************************************START: BASE ADDRESS OF THE PERI*************************************************************
 *									   BASE ADDRESS OF THE FLASH, SRAM & PERIPHERALS
 ******************************************************************************************************************************************/

/*
 * Base address of the flash and SRAM memories
 */

#define FLASH_BASEADDR				0x08000000U 			/*! Base address of the flash memory*/
#define SRAM_BASEADDR				0x20000000U 			/*! Base address of the SRAM memory*/
#define ROM_BASEADDR				0x1FFFC800U 			/*! Base address of the System memory*/
#define SRAM					SRAM_BASEADDR		 	/*! Base address of the SRAM memory*/

/*
 * AHBx and APBx Bus peripheral base address
 */

#define PERIPH_BASEADDR				0x40000000U 		 /*! Base address of the Peripheral*/
#define	APBPERIPH_BASEADDR			PERIPH_BASEADDR		 /*! Base address of the APB bus*/
#define	AHB1PERIPH_BASEADDR			0x40020000U 		 /*! Base address of the AHB1 bus*/
#define	AHB2PERIPH_BASEADDR			0x48000000U		 /*! Base address of the AHB2 bus*/

/*
 * Base addresses of peripherals which are hanging on AHB1 bus
 */

#define DMA_BASEADDR				(AHB1PERIPH_BASEADDR + 0x0000) /*! Base address of the DMA controller*/
#define RCC_BASEADDR				(AHB1PERIPH_BASEADDR + 0x1000) /*! Base address of the RCC peripheral*/
#define FLASH_INTER_BASEADDR			(AHB1PERIPH_BASEADDR + 0x2000) /*! Base address of the Flash Interface*/
#define CRC_BASEADDR				(AHB1PERIPH_BASEADDR + 0x3000) /*! Base address of the CRC*/

/*
 * Base addresses of peripherals which are hanging on AHB2 bus
 */

/************************************************GPIO BASE ADDRESSES***********************************************************************/
#define GPIOA_BASEADDR				(AHB2PERIPH_BASEADDR + 0x0000) /*! Base address of the GPIOA PORT*/
#define GPIOB_BASEADDR				(AHB2PERIPH_BASEADDR + 0x0400) /*! Base address of the GPIOB PORT*/
#define GPIOC_BASEADDR				(AHB2PERIPH_BASEADDR + 0x0800) /*! Base address of the GPIOC PORT*/
#define GPIOD_BASEADDR				(AHB2PERIPH_BASEADDR + 0x0C00) /*! Base address of the GPIOD PORT*/
#define GPIOF_BASEADDR				(AHB2PERIPH_BASEADDR + 0x1400) /*! Base address of the GPIOF PORT*/
/******************************************************************************************************************************************/

/*
 * Base addresses of peripherals which are hanging on APB bus
 */

/**********************************************TIMER BASE ADDRESSES************************************************************************/
#define TIM1_BASEADDR				(APBPERIPH_BASEADDR + 0x12C00)  /*! Base address of the TIMER1 */
#define TIM3_BASEADDR				(APBPERIPH_BASEADDR + 0x0400)   /*! Base address of the TIMER3 */
#define TIM6_BASEADDR				(APBPERIPH_BASEADDR + 0x1000)   /*! Base address of the TIMER6 */
#define TIM7_BASEADDR				(APBPERIPH_BASEADDR + 0x1400)   /*! Base address of the TIMER7 */
#define TIM14_BASEADDR				(APBPERIPH_BASEADDR + 0x2000)   /*! Base address of the TIMER14 */
#define TIM15_BASEADDR				(APBPERIPH_BASEADDR + 0x14000)  /*! Base address of the TIMER15 */
#define TIM16_BASEADDR				(APBPERIPH_BASEADDR + 0x14400)  /*! Base address of the TIMER16 */
#define TIM17_BASEADDR				(APBPERIPH_BASEADDR + 0x14800)  /*! Base address of the TIMER17 */
#define RTC_BASEADDR				(APBPERIPH_BASEADDR + 0x2800)   /*! Base address of the RTC TIMER */
/******************************************************************************************************************************************/

/**********************************************SPI BUS ADDRESSES***************************************************************************/
#define SPI1_BASEADDR				(APBPERIPH_BASEADDR + 0x13000)   /*! Base address of the SPI1 BUS */
#define SPI2_BASEADDR				(APBPERIPH_BASEADDR + 0x3800)    /*! Base address of the SPI2 BUS */
/******************************************************************************************************************************************/

/**********************************************I2C BUS ADDRESSES***************************************************************************/
#define I2C1_BASEADDR				(APBPERIPH_BASEADDR + 0x5400)    /*! Base address of the I2C1 BUS */
#define I2C2_BASEADDR				(APBPERIPH_BASEADDR + 0x5800)    /*! Base address of the I2C2 BUS */
/******************************************************************************************************************************************/

/*************************************************ADC ADDRESSES****************************************************************************/
#define ADC_BASEADDR				(APBPERIPH_BASEADDR + 0x12400)   /*! Base address of the ADC */
/******************************************************************************************************************************************/

/**********************************************USART ADDRESSES*****************************************************************************/
#define USART1_BASEADDR				(APBPERIPH_BASEADDR + 0x13800)   /*! Base address of the USART1 */
#define USART2_BASEADDR				(APBPERIPH_BASEADDR + 0x4400)    /*! Base address of the USART2 */
#define USART3_BASEADDR				(APBPERIPH_BASEADDR + 0x4800)    /*! Base address of the USART3 */
#define USART4_BASEADDR				(APBPERIPH_BASEADDR + 0x4C00)    /*! Base address of the USART4 */
#define USART5_BASEADDR				(APBPERIPH_BASEADDR + 0x5000)    /*! Base address of the USART5 */
#define USART6_BASEADDR				(APBPERIPH_BASEADDR + 0x11400)   /*! Base address of the USART6 */
/******************************************************************************************************************************************/

/**********************************************OTHER INTERRUPT ADDRESSES*******************************************************************/
#define WWDG_BASEADDR				(APBPERIPH_BASEADDR + 0x2C00)    /*! Base address of the WATCHDOG */
#define IWDG_BASEADDR				(APBPERIPH_BASEADDR + 0x3000)    /*! Base address of the IWDG */
#define USB_BASEADDR				(APBPERIPH_BASEADDR + 0x5C00)    /*! Base address of the USB */
#define USBANDSRAM_BASEADDR			(APBPERIPH_BASEADDR + 0x6000)    /*! Base address of the USBORSRAM */
#define PWR_BASEADDR				(APBPERIPH_BASEADDR + 0x7000)    /*! Base address of the PWR */
#define SYSCFG_BASEADDR				(APBPERIPH_BASEADDR + 0x10000)   /*! Base address of the SYSTEMCONFIG */
#define EXTI_BASEADDR				(APBPERIPH_BASEADDR + 0x10400)   /*! Base address of the EXTERNAL INTERRUPT HANDLERS */
#define DBGMCU_BASEADDR				(APBPERIPH_BASEADDR + 0x15800)   /*! Base address of the DBGMCU */
/******************************************************************************************************************************************/
/**********************************************END: BASE ADDRESS OF THE PERI***************************************************************/

/**********************************************START: PERIPHERAL STRUCTURES****************************************************************
 *											PERIPHERAL DEFINITION STRUCTURES
 ******************************************************************************************************************************************/

/*
 * Note: Registers of peripherals are specific to MCU
 * e.g: Number of registers of SPI peripheral of STM32F070xx family of MCUs may be different(more or less)
 * Compared to number of registers of SPI peripheral of STM32Lx or STM32F4x family of MCUs
 * Please check your device RM
 */

/*
 * Peripheral Register definition structure for GPIO
 */
typedef struct{
	__vo uint32_t MODER;		/*!< GPIO Port Mode Register> 				Address offset: 0x00*/
	__vo uint32_t OTYPER;		/*!< GPIO Port Output Type > 				Address offset: 0x04*/
	__vo uint32_t OSPEEDR;		/*!< GPIO Port Speed Register> 				Address offset: 0x08*/
	__vo uint32_t PUPDR;		/*!< GPIO Port Pull-up/Pull-Down Register> 		Address offset: 0x0C*/
	__vo uint32_t IDR;		/*!< GPIO Port Input Data Register> 			Address offset: 0x10*/
	__vo uint32_t ODR;		/*!< GPIO Port Output Data Register> 			Address offset: 0x14*/
	__vo uint32_t BSRR;		/*!< GPIO Port Bit-Set/Reset Register> 			Address offset: 0x18*/
	__vo uint32_t LCKR;		/*!< GPIO Port Lock Config Register> 			Address offset: 0x1C*/
	__vo uint32_t AFR[2];		/*!< AFR[0] is AFRL | AFR[1] is AFRH			Address offset: 0x20 - 0x24*/
//	__vo uint32_t AFRL;		/*!< GPIO AF Low Register> 				Address offset: 0x20*/
//	__vo uint32_t AFRH;		/*!< GPIO AF High Register> 				Address offset: 0x24*/
	__vo uint32_t BRR;		/*!< GPIO Bit Reset Register> 				Address offset: 0x28*/

}GPIO_RegDef_t;

/*
 * Peripheral Register definition structure for RCC
 */
typedef struct{
	__vo uint32_t CR;		/*!< RCC Clock Control REG>					Address offset: 0x00*/
	__vo uint32_t CFGR;		/*!< RCC Clock CONGIG REG>					Address offset: 0x04*/
	__vo uint32_t CIR;		/*!< RCC Clock INTERRUPT REG>					Address offset: 0x08*/
	__vo uint32_t APB2RSTR;		/*!< RCC APB Reset REG2>					Address offset: 0x0C*/
	__vo uint32_t APB1RSTR;		/*!< RCC APB Reset REG1>					Address offset: 0x10*/
	__vo uint32_t AHBENR;		/*!< RCC AHB CLK EN REG>					Address offset: 0x14*/
	__vo uint32_t APB2ENR;		/*!< RCC APB CLK EN REG2>					Address offset: 0x18*/
	__vo uint32_t APB1ENR;		/*!< RCC APB CLK EN REG1>					Address offset: 0x1C*/
	__vo uint32_t BDCR;		/*!< RTC Domain Control REG>					Address offset: 0x20*/
	__vo uint32_t CSR;		/*!< Control/Status REG>					Address offset: 0x24*/
	__vo uint32_t AHBRSTR;		/*!< RCC AHB Rest REG>						Address offset: 0x28*/
	__vo uint32_t CFGR2;		/*!< RCC CLK CFG REG2>						Address offset: 0x2C*/
	__vo uint32_t CFGR3;		/*!< RCC CLK CFG REG3>						Address offset: 0x30*/
	__vo uint32_t CR2;		/*!< RCC CLK Control REG>					Address offset: 0x34*/

}RCC_RegDef_t;


/*
 * Peripheral Register definition structure for EXTI
 */
typedef struct{
	__vo uint32_t IMR;			/*!< EXTI Interrupt Mask Register>			Address offset: 0x00*/
	__vo uint32_t EMR;			/*!< EXTI Event Mask Register>				Address offset: 0x04*/
	__vo uint32_t RTSR;			/*!< EXTI Rising Trigger Selection Reg.,>		Address offset: 0x08*/
	__vo uint32_t FTSR;			/*!< EXTI Falling Trigger Selection Reg.,>		Address offset: 0x0C*/
	__vo uint32_t SWIER;			/*!< EXTI SW interrupt EVent Register>			Address offset: 0x10*/
	__vo uint32_t PR;			/*!< EXTI Pending Register>				Address offset: 0x14*/

}EXTI_RegDef_t;


/*
 * Peripheral Register definition structure for SYSCFG
 */

typedef struct{
	__vo uint32_t CFGR1;		/*!<SYSCFG Configuration Register1>			Address offset: 0x00*/
	__vo uint32_t EXTICR[4];	/*!<SYSCFG External IRQ CFG Register>			Address offset: 0x08-0x14*/
	__vo uint32_t CFGR2;		/*!<SYSCFG Configuration Register2>			Address offset: 0x00*/
}SYSCFG_RegDef_t;


/*
 * Peripheral definitions (Peripheral base addresses type casted to xxx_RegDef_t)
 */

#define GPIOA				((GPIO_RegDef_t*)GPIOA_BASEADDR)		/*! Defining GPIOA peripheral as typecasting base address*/
#define GPIOB				((GPIO_RegDef_t*)GPIOB_BASEADDR)		/*! Defining GPIOB peripheral as typecasting base address*/
#define GPIOC				((GPIO_RegDef_t*)GPIOC_BASEADDR)		/*! Defining GPIOC peripheral as typecasting base address*/
#define GPIOD				((GPIO_RegDef_t*)GPIOD_BASEADDR)		/*! Defining GPIOD peripheral as typecasting base address*/
#define GPIOF				((GPIO_RegDef_t*)GPIOF_BASEADDR)		/*! Defining GPIOF peripheral as typecasting base address*/

#define RCC				((RCC_RegDef_t*)RCC_BASEADDR)			/*! Defining RCC peripheral as typecasting base address*/
#define EXTI				((EXTI_RegDef_t*)EXTI_BASEADDR)			/*! Defining EXTI peripheral as typecasting base address*/
#define SYSGFG				((SYSCFG_RegDef_t*)SYSCFG_BASEADDR)		/*! Defining SYSCFG peripheral as typecasting base address*/

/**********************************************END: PERIPHERAL STRUCTURES******************************************************************

*****************************************START:IMPORTANT MACRO DEFINITIONS ****************************************************************/
// 									 CLOCK DISABLE/ENABLE MACRO FOR ALL PERIPHERALS
/*******************************************************************************************************************************************/

/*
 * Clock Enable Macros for GPIOx Peripherals
 */

#define GPIOA_PCLK_EN()			RCC->AHBENR |= (1 << 17)			/*! Enabling GPIOA peripheral clock from AHB bus 17th bit*/
#define GPIOB_PCLK_EN()			RCC->AHBENR |= (1 << 18)			/*! Enabling GPIOB peripheral clock from AHB bus 18th bit*/
#define GPIOC_PCLK_EN()			RCC->AHBENR |= (1 << 19)			/*! Enabling GPIOC peripheral clock from AHB bus 19th bit*/
#define GPIOD_PCLK_EN()			RCC->AHBENR |= (1 << 20)			/*! Enabling GPIOD peripheral clock from AHB bus 20th bit*/
#define GPIOF_PCLK_EN()			RCC->AHBENR |= (1 << 22)			/*! Enabling GPIOF peripheral clock from AHB bus 22th bit*/

/*
 * Clock Disable Macros for GPIOx Peripherals
 */

#define GPIOA_PCLK_DI()			RCC->AHBENR &= ~(1 << 17)			/*! Disabling GPIOA peripheral clock from AHB bus 17th bit*/
#define GPIOB_PCLK_DI()			RCC->AHBENR &= ~(1 << 18)			/*! Disabling GPIOB peripheral clock from AHB bus 18th bit*/
#define GPIOC_PCLK_DI()			RCC->AHBENR &= ~(1 << 19)			/*! Disabling GPIOC peripheral clock from AHB bus 19th bit*/
#define GPIOD_PCLK_DI()			RCC->AHBENR &= ~(1 << 20)			/*! Disabling GPIOD peripheral clock from AHB bus 20th bit*/
#define GPIOF_PCLK_DI()			RCC->AHBENR &= ~(1 << 22)			/*! Disabling GPIOF peripheral clock from AHB bus 22th bit*/

/******************************************************************************************************************************************/


/****************************************TIMER CLOCK ENABLE/DISABLE MACROS ****************************************************************/
/*
 * Clock Enable Macros for TIMx Peripherals
 */
#define TIM1_PCLK_EN()			RCC->APB2ENR |= (1 << 11)			/*! Enabling TIM1  peripheral clock from APB2 bus 11th bit*/
#define TIM3_PCLK_EN()			RCC->APB1ENR |= (1 << 1)			/*! Enabling TIM3  peripheral clock from APB1 bus 1st  bit*/
#define TIM6_PCLK_EN()			RCC->APB1ENR |= (1 << 4)			/*! Enabling TIM6  peripheral clock from APB1 bus 4th  bit*/
#define TIM7_PCLK_EN()			RCC->APB1ENR |= (1 << 5)			/*! Enabling TIM7  peripheral clock from APB1 bus 5th  bit*/
#define TIM14_PCLK_EN()			RCC->APB1ENR |= (1 << 8)			/*! Enabling TIM14 peripheral clock from APB1 bus 8th  bit*/
#define TIM15_PCLK_EN()			RCC->APB2ENR |= (1 << 16)			/*! Enabling TIM15 peripheral clock from APB2 bus 16th bit*/
#define TIM16_PCLK_EN()			RCC->APB2ENR |= (1 << 17)			/*! Enabling TIM16 peripheral clock from APB2 bus 17th bit*/
#define TIM17_PCLK_EN()			RCC->APB2ENR |= (1 << 18)			/*! Enabling TIM17 peripheral clock from APB2 bus 18th bit*/

/*
 * Clock Disable Macros for TIMx Peripherals
 */

#define TIM1_PCLK_DI()			RCC->APB2ENR &= ~(1 << 11)			/*! Disabling TIM1  peripheral clock from APB2 bus 11th bit*/
#define TIM3_PCLK_DI()			RCC->APB1ENR &= ~(1 << 1)			/*! Disabling TIM3  peripheral clock from APB1 bus 1st  bit*/
#define TIM6_PCLK_DI()			RCC->APB1ENR &= ~(1 << 4)			/*! Disabling TIM6  peripheral clock from APB1 bus 4th  bit*/
#define TIM7_PCLK_DI()			RCC->APB1ENR &= ~(1 << 5)			/*! Disabling TIM7  peripheral clock from APB1 bus 5th  bit*/
#define TIM14_PCLK_DI()			RCC->APB1ENR &= ~(1 << 8)			/*! Disabling TIM14 peripheral clock from APB1 bus 8th  bit*/
#define TIM15_PCLK_DI()			RCC->APB2ENR &= ~(1 << 16)			/*! Disabling TIM15 peripheral clock from APB2 bus 16th bit*/
#define TIM16_PCLK_DI()			RCC->APB2ENR &= ~(1 << 17)			/*! Disabling TIM16 peripheral clock from APB2 bus 17th bit*/
#define TIM17_PCLK_DI()			RCC->APB2ENR &= ~(1 << 18)			/*! Disabling TIM17 peripheral clock from APB2 bus 18th bit*/

/******************************************************************************************************************************************/

/******************************************SPI CLOCK ENABLE/DISABLE MACROS ****************************************************************/
/*
 * Clock Enable Macros for SPI Peripherals
 */

#define SPI1_PCLK_EN()			RCC->APB2ENR |= (1 << 12)			/*! Enabling SPI1 peripheral clock from APB2 bus 12th bit*/
#define SPI2_PCLK_EN()			RCC->APB1ENR |= (1 << 14)			/*! Enabling SPI2 peripheral clock from APB1 bus 14th bit*/

/*
 * Clock Disable Macros for SPI Peripherals
 */

#define SPI1_PCLK_DI()			RCC->APB2ENR &= ~(1 << 12)			/*! Disabling SPI1 peripheral clock from APB2 bus 12th bit*/
#define SPI2_PCLK_DI()			RCC->APB1ENR &= ~(1 << 14)			/*! Disabling SPI2 peripheral clock from APB1 bus 14th bit*/

/******************************************************************************************************************************************/

/******************************************I2C CLOCK ENABLE/DISABLE MACROS ****************************************************************/
/*
 * Clock Enable Macros for I2C Peripherals
 */

#define I2C1_PCLK_EN()			RCC->APB1ENR |= (1 << 21)			/*! Enabling I2C1 peripheral clock from APB1 bus 21st bit*/
#define I2C2_PCLK_EN()			RCC->APB1ENR |= (1 << 22)			/*! Enabling I2C2 peripheral clock from APB1 bus 22nd bit*/

/*
 * Clock Disable Macros for I2C Peripherals
 */

#define I2C1_PCLK_DI()			RCC->APB1ENR &= ~(1 << 21)			/*! Disabling I2C1 peripheral clock from APB1 bus 21st bit*/
#define I2C2_PCLK_DI()			RCC->APB1ENR &= ~(1 << 22)			/*! Disabling I2C1 peripheral clock from APB1 bus 21st bit*/

/******************************************************************************************************************************************/


/******************************************USART CLOCK ENABLE/DISABLE MACROS **************************************************************/
/*
 * Clock Enable Macros for USART Peripherals
 */
#define USART1_PCLK_EN()		RCC->APB2ENR |= (1 << 14)			/*! Enabling USART1 peripheral clock from APB2 bus 14th bit*/
#define USART2_PCLK_EN()		RCC->APB1ENR |= (1 << 17)			/*! Enabling USART2 peripheral clock from APB1 bus 17th bit*/
#define USART3_PCLK_EN()		RCC->APB1ENR |= (1 << 18)			/*! Enabling USART3 peripheral clock from APB1 bus 18th bit*/
#define USART4_PCLK_EN()		RCC->APB1ENR |= (1 << 19)			/*! Enabling USART4 peripheral clock from APB1 bus 19th bit*/
#define USART5_PCLK_EN()		RCC->APB1ENR |= (1 << 20)			/*! Enabling USART5 peripheral clock from APB1 bus 20th bit*/
#define USART6_PCLK_EN()		RCC->APB2ENR |= (1 << 5)			/*! Enabling USART6 peripheral clock from APB2 bus 5th  bit*/

/*
 * Clock Disable Macros for USART Peripherals
 */

#define USART1_PCLK_DI()		RCC->APB2ENR &= ~(1 << 14)			/*! Disabling USART1 peripheral clock from APB2 bus 14th bit*/
#define USART2_PCLK_DI()		RCC->APB1ENR &= ~(1 << 17)			/*! Disabling USART2 peripheral clock from APB1 bus 17th bit*/
#define USART3_PCLK_DI()		RCC->APB1ENR &= ~(1 << 18)			/*! Disabling USART3 peripheral clock from APB1 bus 18th bit*/
#define USART4_PCLK_DI()		RCC->APB1ENR &= ~(1 << 19)			/*! Disabling USART4 peripheral clock from APB1 bus 19th bit*/
#define USART5_PCLK_DI()		RCC->APB1ENR &= ~(1 << 20)			/*! Disabling USART5 peripheral clock from APB1 bus 20th bit*/
#define USART6_PCLK_DI()		RCC->APB2ENR &= ~(1 << 5)			/*! Disabling USART6 peripheral clock from APB2 bus 5th  bit*/


/******************************************************************************************************************************************/


/****************************************************** ADC MACROS ************************************************************************/
/*
 * Clock Enable Macros for ADC
 */

#define ADC_PCLK_EN()		RCC->APB2ENR |= (1 << 9)			/*! Enabling ADC peripheral clock from APB2 bus 9th bit*/

/*
 * Clock Disable Macros for ADC
 */

#define ADC_PCLK_DI()		RCC->APB2ENR &= ~(1 << 9)			/*! Disabling ADC peripheral clock from APB2 bus 9th bit*/

/******************************************************************************************************************************************/

/********************************************* SYSTEM CONFIGURATION MACROS ****************************************************************/
/*
 * Clock Enable Macros for SYSCFG
 */

#define SYSCFG_PCLK_EN()		RCC->APB2ENR |= (1 << 0)		/*! Enabling SYSCFG peripheral clock from APB2 bus 0th bit*/

/*
 * Clock Disable Macros for SYSCFG
 */

#define SYSCFG_PCLK_DI()		RCC->APB2ENR &= ~(1 << 0)		/*! Disabling SYSCFG peripheral clock from APB2 bus 0th bit*/

/******************************************************************************************************************************************/

/************************************************** GPIOx RESET MACROS ********************************************************************/

/*
 * Macros to reset the GPIOx peripherals
 */

#define GPIOA_REG_RESET()		do{ (RCC -> AHBRSTR |= (1 << 17));(RCC -> AHBRSTR &= ~(1 << 17)); }while(0)
#define GPIOB_REG_RESET()		do{ (RCC -> AHBRSTR |= (1 << 18));(RCC -> AHBRSTR &= ~(1 << 18)); }while(0)
#define GPIOC_REG_RESET()		do{ (RCC -> AHBRSTR |= (1 << 19));(RCC -> AHBRSTR &= ~(1 << 19)); }while(0)
#define GPIOD_REG_RESET()		do{ (RCC -> AHBRSTR |= (1 << 20));(RCC -> AHBRSTR &= ~(1 << 20)); }while(0)
#define GPIOF_REG_RESET()		do{ (RCC -> AHBRSTR |= (1 << 22));(RCC -> AHBRSTR &= ~(1 << 22)); }while(0)

/******************************************************************************************************************************************/

/*********************************************** GPIO_BASEADDR_TO_CODE ********************************************************************/
/*
 * This macro returns a code (between 0 to 4) for a given GPIO base Address(x)
 */
#define GPIO_BASEADDR_TO_CODE(x)	((x == GPIOA) ? 0:\
					(x == GPIOB) ? 1:\
					(x == GPIOC) ? 2:\
					(x == GPIOD) ? 3:\
					(x == GPIOF) ? 4:0 )

/******************************************************************************************************************************************/

/**************************************************** IRQ MACROS **************************************************************************/
/*
 * IRQ (Interrupt Requests) Numbers of STM32F070xx MCU
 * NOTE: update these macros with valid values according to your MCU
 * TO DO: You may complete this list for other peripherals
 */

#define IRQ_NO_EXTI0_1		5		/*!EXTI Line[1:0] interrupts*/
#define IRQ_NO_EXTI2_3		6		/*!EXTI Line[3:2] interrupts*/
#define IRQ_NO_EXTI4_15		7		/*!EXTI Line[15:4] interrupts*/

/*
 * Macros for all the priority levels
 */
#define NVIC_IRQ_PRI0		0		/*! NeNested Vectored Interrupt Controller Priority 0*/
#define NVIC_IRQ_PRI1		1		/*! NeNested Vectored Interrupt Controller Priority 1*/
#define NVIC_IRQ_PRI2		2		/*! NeNested Vectored Interrupt Controller Priority 2*/
#define NVIC_IRQ_PRI3		3		/*! NeNested Vectored Interrupt Controller Priority 3*/
#define NVIC_IRQ_PRI4		4		/*! NeNested Vectored Interrupt Controller Priority 4*/
#define NVIC_IRQ_PRI5		5		/*! NeNested Vectored Interrupt Controller Priority 5*/
#define NVIC_IRQ_PRI6		6		/*! NeNested Vectored Interrupt Controller Priority 6*/
#define NVIC_IRQ_PRI7		7		/*! NeNested Vectored Interrupt Controller Priority 7*/
#define NVIC_IRQ_PRI8		8		/*! NeNested Vectored Interrupt Controller Priority 8*/
#define NVIC_IRQ_PRI9		9		/*! NeNested Vectored Interrupt Controller Priority 9*/
#define NVIC_IRQ_PRI10		10		/*! NeNested Vectored Interrupt Controller Priority 10*/
#define NVIC_IRQ_PRI11		11		/*! NeNested Vectored Interrupt Controller Priority 11*/
#define NVIC_IRQ_PRI12		12		/*! NeNested Vectored Interrupt Controller Priority 12*/
#define NVIC_IRQ_PRI13		13		/*! NeNested Vectored Interrupt Controller Priority 13*/
#define NVIC_IRQ_PRI14		14		/*! NeNested Vectored Interrupt Controller Priority 14*/
#define NVIC_IRQ_PRI15		15		/*! NeNested Vectored Interrupt Controller Priority 15*/

/******************************************************************************************************************************************/


/************************************************* SOME GENERIC MACROS ********************************************************************/

#define ENABLE			1
#define DISABLE			0
#define SET				ENABLE
#define RESET			DISABLE
#define	GPIO_PIN_SET	SET
#define GPIO_PIN_RESET	RESET

/*****************************************************************************************************************************************/
/****************************************END:IMPORTANT MACRO DEFINITONS *******************************************************************/


/******************************************DRIVER FILES INCLUSION**************************************************************************/

#include "stm32f070xx_gpio_driver.h"

/******************************************************************************************************************************************/
#endif /* INC_STM32F070XX_H_ */
