/*
 * spi_test.c
 *
 *  Created on: Sep 2, 2026
 *      Author: deepu
 */

#include "stm32f401xe_gpio.h"
#include "stm32f401xe_spi.h"
#include "itm.h"
#include <string.h>
#include <stdio.h>

/*
 * ---------------- SWV / ITM printf retarget ----------------
 * Routes printf() output to the SWV Data Console via ITM stimulus
 * port 0. Requires:
 *   1. SWV enabled in the debug configuration:
 *        Run -> Debug Configurations -> (your config) -> Debugger tab
 *        -> tick "Enable" under Serial Wire Viewer (SWV)
 *        -> set "Core Clock" to your ACTUAL SYSCLK frequency
 *           (e.g. 16000000 if you haven't set up the PLL)
 *   2. After starting a debug session:
 *        Window -> Show View -> SWV -> SWV ITM Data Console
 *        -> click the "Configure trace" (spanner) icon, tick ITM port 0
 *        -> click the red "Start Trace" button
 *   3. ITM_SendChar comes from CMSIS core_cm4.h, normally pulled in
 *      transitively via your MCU's device header.
 */
int _write(int fd, char *ptr, int len)
{
    for (int i = 0; i < len; i++)
    {
        ITM_SendChar((uint8_t)ptr[i]);
    }
    return len;
}

/*
 * ============================================================
 * WIRING REQUIRED FOR THIS TEST:
 *   Short (jumper wire) PB15 (MOSI) directly to PB14 (MISO)
 *   This creates a loopback so whatever the master sends,
 *   it also receives back on the same bus.
 * ============================================================
 *
 * SPI2 Pins:
 * PB12 - NSS
 * PB13 - SCK
 * PB14 - MISO
 * PB15 - MOSI
 * Alternate Function: AF5
 *
 * LED:
 * PA5  - Onboard LED (Nucleo-F401RE)
*/
#define LED_PORT   GPIOA
#define LED_PIN    GPIO_PIN_NO_5


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

/* Simple busy-wait delay (tune for your clock config) */
void delay(void)
{
    for (uint32_t i = 0; i < 500000; i++);
}


/* ---------------- SPI2 GPIO + Init ---------------- */

void SPI2_GPIOInit(void)
{
    GPIO_Handle_t SPIPins;

    SPIPins.pGPIOx = GPIOB;
    SPIPins.GPIO_PinConfig.GPIO_PinMode        = GPIO_MODE_ALTFN;
    SPIPins.GPIO_PinConfig.GPIO_PinAltFunMode  = 5;
    SPIPins.GPIO_PinConfig.GPIO_PinOPType      = GPIO_OP_TYPE_PP;
    SPIPins.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
    SPIPins.GPIO_PinConfig.GPIO_PinSpeed       = GPIO_SPEED_FAST;

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

    // NSS (not strictly needed with SSM, kept for completeness)
    SPIPins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;
    GPIO_Init(&SPIPins);
}

void SPI2_Init(void)
{
    SPI_Handle_t SPI2Handle;

    SPI2Handle.pSPIx = SPI2;
    SPI2Handle.SPIConfig.SPI_BusConfig   = SPI_BUS_CONFIG_FD;
    SPI2Handle.SPIConfig.SPI_DeviceMode  = SPI_DEVICE_MODE_MASTER;
    SPI2Handle.SPIConfig.SPI_SclkSpeed   = SPI_SCLK_SPEED_DIV8;
    SPI2Handle.SPIConfig.SPI_DFF         = SPI_DFF_8BITS;
    SPI2Handle.SPIConfig.SPI_CPOL        = SPI_CPOL_LOW;
    SPI2Handle.SPIConfig.SPI_CPHA        = SPI_CPHA_LOW;
    SPI2Handle.SPIConfig.SPI_SSM         = SPI_SSM_EN;  // Software slave mgmt

    SPI_Init(&SPI2Handle);
}

int main(void)
{
    char txData[] = "Hello SPI!";
    uint8_t rxData[sizeof(txData)] = {0};
    uint32_t dataLen = strlen(txData);

    // Initialize the onboard LED pin (was missing)
    LED_GPIOInit();

    SPI2_GPIOInit();
    SPI2_Init();

    SPI_SSIConfig(SPI2, ENABLE);
    SPI_PeripheralControl(SPI2, ENABLE);

    printf("SPI2 initialized. Starting loopback transfer...\r\n");

    // Full-duplex transfer: send AND receive one byte at a time.
    // Required for loopback — each byte must be clocked out and its
    // looped-back value read from DR before the next byte goes out,
    // otherwise the RX shift register overruns and gives stale data.
    for (uint32_t i = 0; i < dataLen; i++)
    {
        while (!(SPI2->SR & SPI_TXE_FLAG));   // wait TX buffer empty
        SPI2->DR = txData[i];                 // shift this byte out

        while (!(SPI2->SR & SPI_RXNE_FLAG));  // wait RX buffer full
        rxData[i] = (uint8_t)SPI2->DR;        // read looped-back byte
    }

    while (SPI_GetFlagStatus(SPI2, SPI_BUSY_FLAG));

    SPI_PeripheralControl(SPI2, DISABLE);

    // Print what was sent and what was received back
    printf("Sent:     %s\r\n", txData);
    printf("Received: %.*s\r\n", (int)dataLen, rxData);

    // Turn LED on only if reception completed and data matches what was sent
    if (memcmp(txData, rxData, dataLen) == 0)
    {
        printf("Loopback OK - data matches.\r\n");
        GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_NO_5, GPIO_PIN_SET);
    }
    else
    {
        printf("Loopback FAILED - mismatch.\r\n");
    }

    while (1);

    return 0;
}
