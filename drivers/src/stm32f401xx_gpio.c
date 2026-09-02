/*
 * stm32f401xx_gpio.c
 *
 *  Created on: Jun 22, 2026
 *      Author: deepu
 */
#include "stm32f401xx_gpio.h"

/*
 * Enables or disables peripheral clock for GPIO port
 */
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx,uint8_t EnorDi){

	 if (EnorDi == ENABLE)
	    {
	        if (pGPIOx == GPIOA)
	        {
	            GPIOA_PCLK_EN();
	        }
	        else if (pGPIOx == GPIOB)
	        {
	            GPIOB_PCLK_EN();
	        }
	        else if (pGPIOx == GPIOC)
	        {
	            GPIOC_PCLK_EN();
	        }
	        else if (pGPIOx == GPIOD)
	        {
	            GPIOD_PCLK_EN();
	        }
	        else if (pGPIOx == GPIOE)
	        {
	            GPIOE_PCLK_EN();
	        }
	        else if (pGPIOx == GPIOH)
	        {
	            GPIOH_PCLK_EN();
	        }
	    }
	    else
	    {

	        if (pGPIOx == GPIOA)
	        {
	            GPIOA_PCLK_DI();
	        }else if (pGPIOx == GPIOB)
	        {
	            GPIOB_PCLK_DI();
	        }
	        else if (pGPIOx == GPIOC)
	        {
	            GPIOC_PCLK_DI();
	        }
	        else if (pGPIOx == GPIOD)
	        {
	            GPIOD_PCLK_DI();
	        }
	        else if (pGPIOx == GPIOE)
	        {
	            GPIOE_PCLK_DI();
	        }
	        else if (pGPIOx == GPIOH)
	        {
	            GPIOH_PCLK_DI();
	        }


	    }

}


/*
 * Comfiguration mode
 */
void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{
    uint32_t temp = 0;

    // 1. Configure the mode of GPIO pin
    if (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ANALOG)
    {
        // Non-interrupt mode
        temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode
                << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));

        // Clear the 2 bits first
        pGPIOHandle->pGPIOx->MODER &= ~(0x3
                << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));

        // Set the new value
        pGPIOHandle->pGPIOx->MODER |= temp;
    }
    else
    {
        // Interrupt mode - we'll cover this later
    }
    temp = 0;

    // 2. Configure the speed
        temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed
                << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));

        pGPIOHandle->pGPIOx->OSPEEDR &= ~(0x3
                << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
        pGPIOHandle->pGPIOx->OSPEEDR |= temp;
        temp = 0;

        // 3. Configure the pull-up/pull-down settings
            temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl
                    << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));

            pGPIOHandle->pGPIOx->PUPDR &= ~(0x3
                    << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
            pGPIOHandle->pGPIOx->PUPDR |= temp;
            temp = 0;

            // 4. Configure the output type (only 1 bit per pin)
                temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType
                        << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);

                pGPIOHandle->pGPIOx->OTYPER &= ~(0x1
                        << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
                pGPIOHandle->pGPIOx->OTYPER |= temp;
                temp = 0;

/*
 * This function de-initializes the given GPIO port
 */

void GPIO_DeInit(GPIO_RegDef_t *pGPIOx){

	if (pGPIOx == GPIOA)
	    {
	        GPIOA_REG_RESET();
	    }
	    else if (pGPIOx == GPIOB)
	    {
	        GPIOB_REG_RESET();
	    }
	    else if (pGPIOx == GPIOC)
	    {
	        GPIOC_REG_RESET();
	    }
	    else if (pGPIOx == GPIOD)
	    {
	        GPIOD_REG_RESET();
	    }
	    else if (pGPIOx == GPIOE)
	    {
	        GPIOE_REG_RESET();
	    }
	    else if (pGPIOx == GPIOH)
	    {
	        GPIOH_REG_RESET();
	    }
}

/*
 * Reads from a specific GPIO pin
 */
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber){
	uint8_t value;

	    value = (uint8_t)((pGPIOx->IDR >> PinNumber) & 0x00000001);

	    return value;
}

}
uint8_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx){

	uint16_t value;

	    value = (uint16_t)pGPIOx->IDR;

	    return value;

}

void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber,uint8_t value){

	if (value == GPIO_PIN_SET)
	    {
	        // Write 1 to the output data register at the bit field corresponding to the pin number
	        pGPIOx->ODR |= (1 << PinNumber);
	    }
	    else
	    {
	        // Write 0
	        pGPIOx->ODR &= ~(1 << PinNumber);
	    }
}

void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx,uint16_t value){

	pPIOx->ODR = Value;

}
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber){

	pGPIOx->ODR ^= (1 << PinNumber);
}
