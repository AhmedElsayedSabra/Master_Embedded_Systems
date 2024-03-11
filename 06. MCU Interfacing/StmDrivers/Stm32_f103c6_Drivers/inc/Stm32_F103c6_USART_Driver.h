/*
 * Stm32_F103c6_GPIO_Driver.h
 *
 *  Created on: Feb 26, 2024
 *      Author: A7MED
 */

#ifndef INC_STM32_F103C6_USART_DRIVER_H_
#define INC_STM32_F103C6_USART_DRIVER_H_
//*************************************
// 				Include Header
//*************************************

#include "Stm32f103x6.h"
#include "Stm32_F103c6_GPIO_Driver.h"
#include "Platform_Type.h"
#include "stdio.h"
#include "Stm32_F103c6_RCC_Driver.h"
//-----------------------------
// Macros Configuration References
//-----------------------------
#define USART_MODE_RX			(uint32_t)(1<<2)	// Bit2: RE
#define USART_MODE_TX			(uint32_t)(1<<3)	// Bit3: TE
#define USART_MODE_RX_TX		(uint32_t)(1<<2 | 1<<3)

/* ================================
 * 			USART BAUD RATE
 * ================================*/
#define USART_BaudRate_2400					2400
#define USART_BaudRate_9600					9600
#define USART_BaudRate_19200				19200
#define USART_BaudRate_57600				57600
#define USART_BaudRate_115200				115200
#define USART_BaudRate_230400				230400
#define USART_BaudRate_460800				460800
#define USART_BaudRate_921600				921600
#define USART_BaudRate_2250000				2250000
#define USART_BaudRate_4500000				4500000
/* ==================================================
 * 					USART word Length
 * ===================================================*/
#define USART_PAYLOAD_LENGTH_8B			(uint32_t)(0)
#define USART_PAYLOAD_LENGTH_9B			(uint32_t)(1<<12)
/* ======================================================
 * 					USART Parity Control
 * ======================================================*/
#define USART_PARITY_NONE			(uint32_t)(0)
#define USART_PARITY_EVEN			(uint32_t)(1<<10)
#define USART_PARITY_ODD		    (uint32_t)(1<<10 | 1<< 9)
/* ==============================================================
 * 						USART Stop Bits
 * =============================================================*/
#define USART_STOP_BIT_HALF                     (uint32_t)(1<<12)
#define USART_STOP_BIT_1                   		(uint32_t)(0)
#define USART_STOP_BIT_1_HALF                   (uint32_t)(3<<12)
#define USART_STOP_BIT_2                   		(uint32_t)(2<<12)
/* ==============================================================
 * 						USART Flow Controls
 * =============================================================*/
#define USART_HW_FLOW_CTL_NONE					(uint32_t)(0)
#define USART_HW_FLOW_CTL_RTS					(uint32_t)(1<<8)
#define USART_HW_FLOW_CTL_CTS					(uint32_t)(1<<9)
#define USART_HW_FLOW_CTL_RTS_CTS				(uint32_t)(1<<8 | 1<< 9)
/* =========================================================================
 * 									USART Interrupt
 * =========================================================================*/
#define USART_IRQ_Enable_NONE           (uint32_t)(0)
#define USART_IRQ_Enable_TXE            (uint32_t)(1<<7)
#define USART_IRQ_Enable_TC             (uint32_t)(1<<6)
#define USART_IRQ_Enable_RXNEIE         (uint32_t)(1<<5)
#define USART_IRQ_Enable_PE             (uint32_t)(1<<8)
// #define USART_IRQ_IDLE_ENABLE			(uint32_t)()

//BaudRate Calculation
//USARTDIV = fclk / (16 * Baudrate)
//USARTDIV_MUL100 =
//u32(100 * fclk) / (16 * Baudrate) = (25 * fclk) / (4* Baudrate)
//DIV_Mantissa_MUL100 = Integer Part (USARTDIV) * 100
//DIV_Mantissa = Integer part (USARTDIV)
//DIV_Fraction = (( USARTDIV_MUL100 - DIV_Mantissa_MUL100) * 16) / 100

#define USARTDIV(_PCLK_, _BAUD_)           (uint32_t)(_PCLK_/(16 * _BAUD_))
#define USARTDIV_MUL100(_PCLK_, _BAUD_)    (uint32_t)((25 * _PCLK_) / (4 * _BAUD_))
#define Mantissa_MUL100(_PCLK_, _BAUD_)    (uint32_t)(USARTDIV(_PCLK_, _BAUD_) * 100)
#define Mantissa(_PCLK_, _BAUD_)           (uint32_t)(USARTDIV(_PCLK_, _BAUD_))
#define DIV_Fraction(_PCLK_, _BAUD_)       (uint32_t)(((USARTDIV_MUL100(_PCLK_, _BAUD_) - Mantissa_MUL100(_PCLK_, _BAUD_)) * 16) / 100)
#define UART_BRR_Register(_PCLK_, _BAUD_)  ((Mantissa(_PCLK_, _BAUD_)) <<4 )|((DIV_Fraction(_PCLK_, _BAUD_)) & 0xF )


typedef struct
{
	uint8_t  USART_Mode ;
	uint32_t USART_Baudrate ;
	uint8_t  PayLoad_Length ;
	uint8_t  Parity ;
	uint8_t  Stop_Bit ;
	uint8_t  HW_Flow_Ctl ;
	uint8_t IRQ_Enalbe ;
	void(* P_IRQ_CallBack)(void) ;
}USART_Config_Typedef;

typedef enum
{
	USART_enable,
	USART_disable
}USART_Polling_Mechanism;
/*
 * ====================================================
 * 			APIs Supported by "MCAL USART DRIVER"
 * ====================================================
 */
void MCAL_USART_Init(USART_TypeDef* USARTx , USART_Config_Typedef* USART_Config);
void MCAL_USART_DeInit(USART_TypeDef* USARTx);
void MCAL_USART_GPIO_Set_Pins(USART_TypeDef* USARTx);
void MCAL_USART_SendData    (USART_TypeDef* USARTx, uint16_t* pTx_BUffer,USART_Polling_Mechanism PollingEn);
void MCAL_USART_RecrviedData(USART_TypeDef* USARTx, uint16_t* pTx_BUffer,USART_Polling_Mechanism PollingEn);
void MCAL_USART_Wait_TC(USART_TypeDef* USARTx);
#endif /* INC_STM32_F103C6_USART_DRIVER_H_ */
