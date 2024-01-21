/*
 * 004spi_tx_testing.c
 *
 *  Created on: Nov 21, 2023
 *      Author: Narendran Srinivasan
 */

#include "stm32f070xx.h"
#include <string.h>

/*
 * PB4-->SPI1_NSS
 * PB5-->SPI1_SCK
 * PB6-->SPI1_MISO
 * PB7-->SPI1_MOSI
 * AF MODE : 0
 * @Note - this pin mode is only available for STM32f070xB devices only
 */


void SPI1_GPIOInits(void){
	GPIO_Handle_t SPIPins;
	SPIPins.pGPIOx = GPIOA;
	SPIPins.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFN;
	SPIPins.GPIO_PinConfig.GPIO_PinAltFunMode = 0;
	SPIPins.GPIO_PinConfig.GPIO_PinOType = GPIO_OP_TYPE_PP;
	SPIPins.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	SPIPins.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;

	// SCK
	SPIPins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NUM_5;
	GPIO_Init(&SPIPins);

	// MOSI
	SPIPins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NUM_7;
	GPIO_Init(&SPIPins);

	// MISO
	// SPIPins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NUM_6;
	// GPIO_Init(&SPIPins);

	// NSS
	// SPIPins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NUM_4;
	// GPIO_Init(&SPIPins);
}

void SPI1_Inits(void){
	SPI_Handle_t SPI1Handle;
	SPI1Handle.pSPIx = SPI1;
	SPI1Handle.SPIConfig.SPI_BusConfig = SPI_BUS_CONFIG_FD;
	SPI1Handle.SPIConfig.SPI_DeviceMode = SPI_DEVICE_MODE_MASTER;
	SPI1Handle.SPIConfig.SPI_ClkSpeed = SPI_CLK_SPEED_DIV2; // Generates the SCLK of 2Mhz
	SPI1Handle.SPIConfig.SPI_DFF = SPI_DFF_16BITS;
	SPI1Handle.SPIConfig.SPI_CPOL = SPI_CPOL_LOW;
	SPI1Handle.SPIConfig.SPI_CPHA = SPI_CPHA_LOW;
	SPI1Handle.SPIConfig.SPI_SSM = SPI_SSM_EN; // Software slave management enabled for NSS pin

	SPI_Init(&SPI1Handle);

}


int main(void)
{
	char user_data[] = "N";
	//This function is used to initialize the GPIO pins to behave as SPI2 pins
	SPI1_GPIOInits();

	// This function is used to initialize the SPI2 peripheral parameters
	SPI1_Inits();

	// This makes NSS signal internally high and avoids MODF Error
	SPI_SSIConfig(SPI1, ENABLE);

	// Enable the SPI2 peripheral
	SPI_PeripheralControl(SPI1, ENABLE);

	// This function is used to send the data over SPI2 peripheral
	SPI_SendData(SPI1, (uint8_t*)user_data, strlen(user_data));

	// Lets confirm SPI is not busy
	while(SPI_GetFlagStatus(SPI1, SPI_BUSY_FLAG));

	// Disable the SPI2 peripheral
	SPI_PeripheralControl(SPI1, DISABLE);

	while(1);
	return 0;
}
