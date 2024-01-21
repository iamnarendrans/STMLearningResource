/*
 * stm32f70xx_i2c_driver.h
 *
 *  Created on: Nov 26, 2023
 *      Author: Narendran Srinivasan
 */

#ifndef INC_STM32F70XX_I2C_DRIVER_H_
#define INC_STM32F70XX_I2C_DRIVER_H_

#include "stm32f070xx.h"				/*! System Driver header inclusion*/

/*
 * Configuration structure for I2Cx peripheral
 */

typedef struct
{
	uint32_t I2C_SCLSpeed;
	uint8_t  I2C_DeviceAddr;
	uint8_t  I2C_AckCtrl;
	uint8_t  I2C_FMDutyCycle;
}I2C_Config_t;

/*
 * Handle structure for I2Cx peripheral
 */

typedef struct
{
	I2C_RegDef_t *pI2Cx;
	I2C_Config_t I2C_Config;
}I2C_Handle_t;


/*
 * @I2C_SCLSpeed
 */

#define I2C_SCL_SPEED_SM		100000
#define I2C_SCL_SPEED_FM2K		200000
#define I2C_SCL_SPEED_FM4K		400000

/*
 *@I2C_DeviceAddr - Given by the user only, don't have initializations
 */


/*
 * @I2C_AckCtrl
 */


#define I2C_ACK_EN
#define I2C_ACK_DI

/*
 * @I2C_FMDutyCycle
 */

#define I2C_FM_DUTY_
#endif /* INC_STM32F70XX_I2C_DRIVER_H_ */
