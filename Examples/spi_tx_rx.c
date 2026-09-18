

/*
 * spi_tx_rx.c  (corrected)
 *
 *  Created on: Sep 17, 2026
 *      Author: vidhya
 */

#include "stm32f401xe_gpio.h"
#include "stm32f401xe_spi.h"
#include <string.h>

/*
 * SPI2 Pins:
 * PB12 - NSS  (unused here; SSM software slave management is enabled instead)
 * PB13 - SCK
 * PB14 - MISO
 * PB15 - MOSI
 * Alternate Function: AF5
 *
 * Loopback test: physically short MOSI (PB15) to MISO (PB14) on the board.
 */

void SPI2_GPIOInit(void)
{
    GPIO_Handle_t SPIPins;

    SPIPins.pGPIOx = GPIOB;
    SPIPins.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFN;
    SPIPins.GPIO_PinConfig.GPIO_PinAltFunMode = 5;
    SPIPins.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
    SPIPins.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
    SPIPins.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;

    GPIO_PeriClockControl(GPIOB, ENABLE);

    // SCK
    SPIPins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
    GPIO_Init(&SPIPins);

    // MOSI
    SPIPins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_15;
    GPIO_Init(&SPIPins);

    // MISO
    SPIPins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_14;
    GPIO_Init(&SPIPins);
}

/*
 * Configure PA5 (Nucleo-F401RE onboard LED, LD2) as a push-pull output.
 * This was previously missing entirely.
 */
void LED_GPIOInit(void)
{
    GPIO_Handle_t LedPin;

    GPIO_PeriClockControl(GPIOA, ENABLE);

    LedPin.pGPIOx = GPIOA;
    LedPin.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_5;
    LedPin.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
    LedPin.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
    LedPin.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
    LedPin.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

    GPIO_Init(&LedPin);
}

void SPI2_Init(void)
{
    SPI_Handle_t SPI2Handle;

    SPI2Handle.pSPIx = SPI2;
    SPI2Handle.SPIConfig.SPI_BusConfig = SPI_BUS_CONFIG_FD;
    SPI2Handle.SPIConfig.SPI_DeviceMode = SPI_DEVICE_MODE_MASTER;
    SPI2Handle.SPIConfig.SPI_SclkSpeed = SPI_SCLK_SPEED_DIV8;
    SPI2Handle.SPIConfig.SPI_DFF = SPI_DFF_8BITS;
    SPI2Handle.SPIConfig.SPI_CPOL = SPI_CPOL_LOW;
    SPI2Handle.SPIConfig.SPI_CPHA = SPI_CPHA_LOW;
    SPI2Handle.SPIConfig.SPI_SSM = SPI_SSM_EN;  // Software slave mgmt

    SPI_Init(&SPI2Handle);
}

/*
 * Simple busy-wait delay
 *
 */
void delay(volatile uint32_t count)
{
    while (count--);
}

int main(void)
{
    // Initialize GPIO pins for SPI2
    SPI2_GPIOInit();

    // Initialize the onboard LED pin (was missing)
    LED_GPIOInit();

    // Initialize SPI2 peripheral
    SPI2_Init();

    // Set SSI to avoid MODF error (software slave management is enabled)
    SPI_SSIConfig(SPI2, ENABLE);

    // Enable SPI2 peripheral
    SPI_PeripheralControl(SPI2, ENABLE);

    uint8_t tx_buff = 0xFF;
    uint8_t rx_buff = 0;

    while (1)
    {
        SPI_SendData(SPI2, &tx_buff, 1);          // Transmit byte on SPI2
        SPI_ReceiveData(SPI2, &rx_buff, 1);        // Receive byte on SPI2 (verify exact name in your header)

        if (rx_buff == tx_buff)                    // Check sent byte == received byte
        {
            GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_NO_5, GPIO_PIN_SET);
        }
        else
        {
            GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_NO_5, GPIO_PIN_RESET);
        }

        delay(5000000);
    }
}
