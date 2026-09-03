/*
 * gpio_led_on_off.c
 *LED ON & OFF example
 *  Created on: Sep 3, 2026
 *      Author: vidhya
 */

#include "stm32f401xe_gpio.h"
#include <stdio.h>

void delay(uint32_t j)
{
	for( uint32_t i=0;i<j;i++);
}

int main(void)
{
	GPIO_Handle_t GPIOLed;

	GPIOLed.pGPIOx = GPIOA;
	GPIOLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_5;
	GPIOLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
    GPIOLed.GPIO_PinConfig.GPIO_PinSpeed =GPIO_SPEED_FAST;
    GPIOLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GPIOLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOA,ENABLE);
	GPIO_Init(&GPIOLed);

	while(1)
	{
		GPIO_WriteToOutputPin(GPIOA,GPIO_PIN_NO_5,GPIO_PIN_SET);
		delay(5000000);
		GPIO_WriteToOutputPin(GPIOA,GPIO_PIN_NO_5,GPIO_PIN_RESET);
		delay(5000000);
	}
}
