/*
 * stm32f401_RccDriver.h
 *
 *  Created on: Sep 9, 2026
 *      Author: deepu
 */

#ifndef INC_STM32F401_RCCDRIVER_H_
#define INC_STM32F401_RCCDRIVER_H_

#include <inc/stm32f401.h>

/*
 * Returns the APB1 peripheral clock value
 */
uint32_t RCC_GetPCLK1Value(void);

/*
 * Returns the APB2 peripheral clock value
 */
uint32_t RCC_GetPCLK2Value(void);

/*
 * Returns the PLL output clock value
 */
uint32_t RCC_GetPLLOutputClock(void);

#endif /* INC_STM32F401_RCCDRIVER_H_ */
