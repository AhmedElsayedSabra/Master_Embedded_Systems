/*
 * Stm32_F103c6_GPIO_Driver.h
 *
 *  Created on: Feb 26, 2024
 *      Author: A7MED
 */
#ifndef INC_STM32_F103C6_GPIO_DRIVER_H_
#define INC_STM32_F103C6_GPIO_DRIVER_H_
//*************************************
// 				Include Header
//*************************************
#include "Stm32f103x6.h"
#include "Platform_Type.h"
//************@ref GPIO_PINS_Define *******************************************************
#define GPIO_PIN_0 		((uint16_t)0x0001)	/* Pin 0 Selected  (1 << 0) */
#define GPIO_PIN_1		((uint16_t)0x0002)	/* Pin 1 Selected  (1 << 1) */
#define GPIO_PIN_2		((uint16_t)0x0004)	/* Pin 2 Selected  (1 << 2) */
#define GPIO_PIN_3		((uint16_t)0x0008)	/* Pin 3 Selected  (1 << 3) */
#define GPIO_PIN_4		((uint16_t)0x0010)	/* Pin 4 Selected  (1 << 4) */
#define GPIO_PIN_5		((uint16_t)0x0020)	/* Pin 5 Selected  (1 << 5) */
#define GPIO_PIN_6		((uint16_t)0x0040)	/* Pin 6 Selected  (1 << 6) */
#define GPIO_PIN_7		((uint16_t)0x0080)	/* Pin 7 Selected  (1 << 7) */
#define GPIO_PIN_8		((uint16_t)0x0100)	/* Pin 8 Selected  (1 << 8) */
#define GPIO_PIN_9		((uint16_t)0x0200)	/* Pin 9 Selected  (1 << 9) */
#define GPIO_PIN_10		((uint16_t)0x0400)	/* Pin 10 Selected (1 << 10)*/
#define GPIO_PIN_11		((uint16_t)0x0800)	/* Pin 11 Selected (1 << 11)*/
#define GPIO_PIN_12		((uint16_t)0x1000)	/* Pin 12 Selected (1 << 12)*/
#define GPIO_PIN_13		((uint16_t)0x2000)	/* Pin 13 Selected (1 << 13)*/
#define GPIO_PIN_14		((uint16_t)0x4000)	/* Pin 14 Selected (1 << 14)*/
#define GPIO_PIN_15		((uint16_t)0x8000)	/* Pin 15 Selected (1 << 15)*/
//********@ref GPIO_PIN_MODE_define ******************************************************************
#define GPIO_MODE_Analog				0x00000000u			// 00: Analog mode
#define GPIO_MODE_INPUT_FLO				0x00000001u			// 01: Floating input (reset state)
#define GPIO_MODE_INPUT_PU				0x00000002u			// 10: Input with pull-up
#define GPIO_MODE_INPUT_PD				0x00000003u			// 10: Input with pull-down
#define GPIO_MODE_OUTPUT_PP				0x00000004u			// 00: General purpose output push-pull
#define GPIO_MODE_OUTPUT_OD				0x00000005u			// 01: General purpose output Open-drain
#define GPIO_MODE_OUTPUT_AF_PP			0x00000006u			// 10: Alternate function output Push-pull
#define GPIO_MODE_OUTPUT_AF_OD			0x00000007u			// 11: Alternate function output Open-drain
#define GPIO_MODE_AF_INPUT				0x00000008u			// 01: Floating input
//**********@ref GPIO_PIN_SPEED_define*****************************************************************
#define GPIO_SPEED_10M					0x00000001u			// 01: Output mode, max speed 10 MHz.
#define GPIO_SPEED_2M					0x00000002u			// 10: Output mode, max speed 2 MHz.
#define GPIO_SPEED_50M					0x00000003u			// 11: Output mode, max speed 50 MHz
//**********@ref GPIO_Pin_Status**********************************************************************
#define GPIO_PIN_LOW    0
#define GPIO_PIN_HIGH   1
//***********@ref GPIO_Return_Lock *******************************************************************
#define GPIO_LCk_Error 	0
#define GPIO_LCK_Success	1
//****************************************************************************************************
// 				Config Sturctures
//**************************************************************************************************
typedef struct
{
	uint16_t GPIO_PinNumber   ;  	// Select PinNumber from @ref GPIO_PINS_Define
	uint8_t GPIO_MODE		  ;     // Select PinModer from  @ref GPIO_PIN_MODE_define
	uint8_t GPIO_OUTPUT_SPEED ;	    // Select PinModer from  @ref GPIO_PIN_SPEED_define
}GPIO_PinConfig_TypeDef;
//*****************************************************************
// 				API_Supported By "MCAL_GPIO_Driver"
//*****************************************************************

/*================================================================
 * @Fn			- GPIO_Init
 * @brief 		- initialize the GPIOx PINy According to the specific parameters in the pinconfig
 * @param [in] 	- GPIOx: where x can be (A,B,C...E)
 * @param [in]  - PinConfig pointer to a gpio pinconfig structures
 * @retval 		- None
 * Note			- stm32f103c6 has GPIO A,B,C,D,E but LQFP48 Package Has Only GPIO A,B &Part of C/D
 *==================================================================*/
void MCAL_GPIO_INIT(GPIO_TypeDef* GPIOx ,GPIO_PinConfig_TypeDef* PinConfig);
/**================================================================
 * @Fn			- MCAL_GPIO_DEINIT
 * @brief 		- Reset the Peripherals
 * @param [in] 	- GPIOx : where x can be (A,B,C...E)
 * @retval 		- None
 * @Note		- None
 *==================================================================*/
void MCAL_GPIO_DEINIT(GPIO_TypeDef* GPIOx , uint8_t PinNumber);
/**================================================================
 * @Fn			- MCAL_GPIO_ReadPin
 * @brief 		- Read the specific Pin
 * @param [in] 	- GPIOx : where x can be (A,B,C...E)
 * @param [in] 	- PinNumber According the @ref GPIO_PINS_Define.
 * @retval 		- (The Value Of input Pin) According to the @ref GPIO_Pin_Status
 * @Note		- None
 *==================================================================*/
uint8_t MCAL_GPIO_ReadPin(GPIO_TypeDef* GPIOx , uint16_t PinNumber);
/**================================================================
 * @Fn			- MCAL_GPIO_ReadPort
 * @brief 		- Read the specific Port
 * @param [in] 	- GPIOx : where x can be (A,B,C...E)
 * @retval 		- The Value Of input Port
 * @Note		- None
 *==================================================================*/
uint16_t MCAL_GPIO_ReadPort(GPIO_TypeDef* GPIOx);
/**================================================================
 * @Fn			- MCAL_GPIO_WritePin
 * @brief 		- write the specific Port
 * @param [in] 	- GPIOx : where x can be (A,B,C...E)
 * @param [in] 	- PinNumber According to @ref Pin Number Define
 * @param [in]  - The Value
 * @retval 		- void
 * @Note		- None
 *==================================================================*/
void MCAL_GPIO_WritePin(GPIO_TypeDef* GPIOx , uint16_t PinNumber , uint8_t Value);
/**================================================================
 * @Fn			- MCAL_GPIO_WritePort
 * @brief 		- Write the specific Port
 * @param [in] 	- GPIOx : where x can be (A,B,C...E)
 * @retval 		- void
 * @Note		- None
 *==================================================================*/
void MCAL_GPIO_WritePort(GPIO_TypeDef* GPIOx ,uint16_t Value);
/**================================================================
 * @Fn			- MCAL_GPIO_TogglePin
 * @brief 		- Toggle the specific Pin
 * @param [in] 	- GPIOx : where x can be (A,B,C...E)
 * @param [in] 	- PinNumber According to @ref Pin Number Define
 * @retval 		- void
 * @Note		- None
 *==================================================================*/
void MCAL_GPIO_TogglePin(GPIO_TypeDef* GPIOx , uint16_t PinNumber) ;
/**================================================================
 * @Fn			- MCAL_GPIO_TooglePort
 * @brief 		- Toggle the specific Port
 * @param [in] 	- GPIOx : where x can be (A,B,C...E)
 * @retval 		- void
 * @Note		- None
 *==================================================================*/
void MCAL_GPIO_TooglePort(GPIO_TypeDef* GPIOx);
/**================================================================
 * @Fn			- MCAL_GPIO_LockPin
 * @brief 		- Lock the specific Port
 * @param [in] 	- GPIOx : where x can be (A,B,C...E)
 * @retval 		- ok if the lock success And Error if Not Success
 * @Note		- None
 *==================================================================*/
uint8_t MCAL_GPIO_LockPin(GPIO_TypeDef* GPIOx ,uint16_t PinNumber);

/**================================================================
 * @Fn			- MCAL_GPIO_LockPin
 * @brief 		- Lock the specific Port
 * @param [in] 	- GPIOx : where x can be (A,B,C...E)
 * @retval 		- ok if the lock success And Error if Not Success
 * @Note		- None
 *==================================================================*/
void  MCAL_GPIO_WritePartialPort(GPIO_TypeDef* GPIOx ,uint16_t startBit , uint16_t endBit, uint16_t portData);
#endif /* INC_STM32_F103C6_GPIO_DRIVER_H_ */
