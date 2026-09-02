/*
 * usart_test.c
 *
 *  Created on: Sep 1, 2026
 *      Author: deepu
 *      */
#include "stm32f401xe_usart.h"
#include "stm32f401xe_gpio.h"

void USART2_GPIOInits(void)
{
    GPIO_Handle_t USARTPins;

    GPIO_PeriClockControl(GPIOA, ENABLE);

    USARTPins.pGPIOx = GPIOA;

    USARTPins.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFN;
    USARTPins.GPIO_PinConfig.GPIO_PinAltFunMode = 7;
    USARTPins.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
    USARTPins.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
    USARTPins.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;

    /* PA2 - USART2 TX */
    USARTPins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_2;
    GPIO_Init(&USARTPins);

    /* PA3 - USART2 RX */
    USARTPins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_3;
    GPIO_Init(&USARTPins);
}


int main(void)
{
    USART_Handle_t USART2Handle;

    USART2_GPIOInits();

    /* Enable USART2 clock */
    USART_PeriClockControl(USART2, ENABLE);

    USART2Handle.pUSARTx = USART2;

    USART2Handle.USART_Config.USART_Baud = 115200;
    USART2Handle.USART_Config.USART_Mode = USART_MODE_TXRX;
    USART2Handle.USART_Config.USART_NoOfStopBits = USART_STOPBITS_1;
    USART2Handle.USART_Config.USART_WordLength = USART_WORDLEN_8BITS;
    USART2Handle.USART_Config.USART_ParityControl = USART_PARITY_DISABLE;
    USART2Handle.USART_Config.USART_HWFlowControl = USART_HW_FLOW_CTRL_NONE;

    USART_Init(&USART2Handle);

    USART_PeripheralControl(USART2, ENABLE);

    while(1)
    {
        uint8_t data = 'A';

        USART_SendData(&USART2Handle, &data, 1);

        for(volatile uint32_t i = 0; i < 1000000; i++);
    }
}
