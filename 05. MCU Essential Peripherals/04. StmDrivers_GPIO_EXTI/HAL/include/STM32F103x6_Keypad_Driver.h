
#ifndef STM32F103x6_Keypad_DRIVER_H_
#define STM32F103x6_Keypad_DRIVER_H_

//-----------------------------
//Includes
//-----------------------------

#include "Stm32f103x6.h"
#include "Stm32_F103c6_GPIO_Driver.h"
#include "Platform_Type.h"

/*===============================================
*                   Keypad Ports
*===============================================
*/
#define KEYPAD_DATA_PORT        GPIOB

/*
*===============================================
*                   KEYPAD PINS
*===============================================
*/
#define KEYPAD_ROW0     GPIO_PIN_0
#define KEYPAD_ROW1     GPIO_PIN_1
#define KEYPAD_ROW2     GPIO_PIN_3
#define KEYPAD_ROW3     GPIO_PIN_4

#define KEYPAD_COL0     GPIO_PIN_5
#define KEYPAD_COL1     GPIO_PIN_6
#define KEYPAD_COL2     GPIO_PIN_7
#define KEYPAD_COL3     GPIO_PIN_8

/*
*===============================================
*                   KEYPAD DIMENSION
*===============================================
*/
#define KEYPAD_ROW_SIZE 4
#define KEYPAD_COL_SIZE 4



/*
* ===============================================
* APIs Supported by "MCAL GPIO DRIVER"
* ===============================================
*/
volatile static unsigned char Keypad_Character[4][4] ={{'7','8','9','/'},
							  	  	  	  	  {'4','5','6','*'},
											  {'1','2','3','-'},
											  {'!','0','=','+'}};
void HAL_Keypad_INIT(void);
uint8_t HAL_Keypad_getCh(void);
#endif /* STM32F103x6_Keypad_DRIVER_H_ */
