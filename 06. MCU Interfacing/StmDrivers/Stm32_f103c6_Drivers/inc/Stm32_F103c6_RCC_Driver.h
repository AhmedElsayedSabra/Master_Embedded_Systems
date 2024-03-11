/*
 * Stm32_F103c6_GPIO_Driver.h
 *
 *  Created on: Feb 26, 2024
 *      Author: A7MED
 */

#ifndef INC_STM32_F103C6_RCC_DRIVER_H_
#define INC_STM32_F103C6_RCC_DRIVER_H_

#include "Stm32f103x6.h"
#include "Stm32_F103c6_GPIO_Driver.h"

#define HSI_CLOCK (uint32_t)8000000
#define HSE_CLOCK (uint32_t)16000000

uint32_t MCAL_RCC_GetSYS_CLKFreq(void);
uint32_t MCAL_RCC_GetHCLKFreq(void);
uint32_t MCAL_RCC_GetPCLK1Freq(void);
uint32_t MCAL_RCC_GetPCLK2Freq(void);

#endif /* INC_STM32_F103C6_RCC_DRIVER_H_ */
