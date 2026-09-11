/*
 * Usart_tx_test.c
 *
 *  Created on: Sep 10, 2026
 *      Author: deepu
 */


#include "stm32f401_GpioDriver.h"
#include "stm32f401_UsartDriver.h"
#include <string.h>

USART_Handle_t USART2Handle;

/*
 * USART2 GPIO Pins (connected to ST-Link):
 * PA2 -> TX (AF7)
 * PA3 -> RX (AF7)
 */
void USART2_GPIOInit(void)
{
    GPIO_Handle_t USARTPins;

    USARTPins.pGPIOx = GPIOA;
    USARTPins.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFN;
    USARTPins.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
    USARTPins.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
    USARTPins.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
    USARTPins.GPIO_PinConfig.GPIO_PinAltFunMode = 7;  // AF7 for USART2

    GPIO_PeriClockControl(GPIOA, ENABLE);

    // TX
    USARTPins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_2;
    GPIO_Init(&USARTPins);

    // RX
    USARTPins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_3;
    GPIO_Init(&USARTPins);
}

void USART2_Init(void)
{
    USART2Handle.pUSARTx = USART2;
    USART2Handle.USART_Config.USART_Baud = USART_STD_BAUD_115200;
    USART2Handle.USART_Config.USART_HWFlowControl = USART_HW_FLOW_CTRL_NONE;
    USART2Handle.USART_Config.USART_Mode = USART_MODE_TXRX;
    USART2Handle.USART_Config.USART_NoOfStopBits = USART_STOPBITS_1;
    USART2Handle.USART_Config.USART_WordLength = USART_WORDLEN_8BITS;
    USART2Handle.USART_Config.USART_ParityControl = USART_PARITY_DISABLE;

    USART_Init(&USART2Handle);
}

int main(void)
{
    char msg[] = "Hello from STM32!\r\n";

    // Initialize GPIO pins for USART2
    USART2_GPIOInit();

    // Initialize USART2
    USART2_Init();

    // Enable USART2 peripheral
    USART_PeripheralControl(USART2, ENABLE);

    while (1)
    {
        // Send message
        USART_SendData(&USART2Handle, (uint8_t*)msg, strlen(msg));

        // Delay
        for (uint32_t i = 0; i < 500000; i++);
    }

    return 0;
}
