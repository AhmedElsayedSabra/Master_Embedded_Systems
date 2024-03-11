/*===============================================
 *                   " Includes "
 *=============================================== */
#include "Stm32_F103c6_USART_Driver.h"
/*====================================================
 * 					" Generic Variable "
 * ==================================================== */
USART_Config_Typedef* Global_USART_Config[3] ={ NULL , NULL , NULL } ;
uint8_t USART_Index = 0 ;
/*====================================================
 * 			APIs Supported by " MCAL USART DRIVER "
 * ==================================================== */


/* ================================================================
 * @Fn			- MCAL_GPIO_WritePort
 * @brief 		- Write the specific Port
 * @param [in] 	- GPIOx : where x can be (A,B,C...E)
 * @retval 		- void
 * @Note		- None
 * ================================================================== */
void MCAL_USART_Init(USART_TypeDef* USARTx , USART_Config_Typedef* USART_Config)
{
	uint32_t PCLK , BRR ;
	// Global_USART_Config = USART_Config ;
	// 1. Enable the clock
	if (USARTx == USART1)
	{
		RCC_USART1_CLK_EN();
		USART_Index = 0 ;
		Global_USART_Config[USART_Index] = USART_Config ;
	}
	else if (USARTx == USART2)
	{
		RCC_USART2_CLK_EN() ;
		USART_Index = 1 ;
		Global_USART_Config[USART_Index] = USART_Config ;
	}
	else if (USARTx == USART3)
	{
		RCC_USART3_CLK_EN() ;
		USART_Index = 2 ;
		Global_USART_Config[USART_Index] = USART_Config ;
	}
	// 2. enable usart Modules // Bit:13 UE
	USARTx->CR1 |=1<<13 ;
	// Enable the Tx And RX
	USARTx->CR1 |= USART_Config->USART_Mode ;
	// Payload Width , Bit 12 M: Word length
	USARTx->CR1 |= USART_Config->PayLoad_Length ;
	// Parity Selection Bits 9 : PS
	USARTx->CR1 |= USART_Config->Parity ;
	// Stop Bits
	USARTx->CR2 |= USART_Config->Stop_Bit;
	// Flow Controls
	USARTx->CR3 |= USART_Config->HW_Flow_Ctl ;
	// Configuration of BRR (Baudrate)
	//PCLK1 == USART2,USART3
	//PCLK2 == USART1
	if (USARTx == USART1)
		PCLK = MCAL_RCC_GetPCLK2Freq();
	else
		PCLK = MCAL_RCC_GetPCLK1Freq();
	BRR = UART_BRR_Register(PCLK , USART_Config->USART_Baudrate);
	USARTx->BRR = BRR;
	//Enable / Disable Interrupt
	//USART_CR1
	if(USART_Config->IRQ_Enalbe != USART_IRQ_Enable_NONE)
	{
		USARTx->CR1 |= USART_Config->IRQ_Enalbe;
		//Enble NVIC for USARTx_IRQ
		if(USARTx == USART1)
			NVIC_IRQ37_USART1_ENABLE ;
		else if(USARTx == USART2)
			NVIC_IRQ38_USART2_ENABLE ;
		else if(USARTx == USART3)
			NVIC_IRQ39_USART3_ENABLE ;
	}
}
/**================================================================
 * @Fn				  - MCAL_UART_DeInit
 * @brief			  - DeInitialization UART (Supported feature Asynch. Only).
 * @param[in]		  - USARTx: where x can be (1..3 depending on device used).
 * @retval			  - NONE
 * @Note		      - Reset the model by RCC.
 *==================================================================*/
void MCAL_USART_DeInit(USART_TypeDef* USARTx)
{
	if (USARTx == USART1)
	{
		RCC_USART1_CLK_RESET();
		NVIC_IRQ37_USART1_DISABLE;
	}
	else if (USARTx == USART2)
	{
		RCC_USART2_CLK_RESET();
		NVIC_IRQ38_USART2_DISABLE;
	}
	else if (USARTx == USART3)
	{
		RCC_USART3_CLK_RESET();
		NVIC_IRQ39_USART3_DISABLE;
	}
}
/**================================================================
 * @Fn							- MCAL_UART_GPIO_Set_Pins
 * @brief						- Initialization GPIO Pins for UART (Supported feature Asynch. Only).
 * @param[in]					- USARTx: where x can be (1..3 depending on device used).
 * @retval						- NONE
 * Note							- Sould Enable the corresponding AFIO & GPIO in RCC clock also called after MCAL_UART_Init()
 *==================================================================*/
void MCAL_USART_GPIO_Set_Pins(USART_TypeDef* USARTx)
{
	GPIO_PinConfig_TypeDef USART_PinConfig ;
	if(USARTx == USART1)
	{
		//" PA9->TX " ,, " PA10->RX " ,," PA11 -> CTS " ,, " PA12 -> RTS "
		//PA9  >>	TX
		USART_PinConfig.GPIO_PinNumber = GPIO_PIN_9 ;
		USART_PinConfig.GPIO_MODE =	GPIO_MODE_OUTPUT_AF_PP ;
		USART_PinConfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M ;
		MCAL_GPIO_INIT(GPIOA, &USART_PinConfig);
		//PA10 >> RX
		USART_PinConfig.GPIO_PinNumber = GPIO_PIN_10 ;
		USART_PinConfig.GPIO_MODE =	GPIO_MODE_AF_INPUT;
		MCAL_GPIO_INIT(GPIOA, &USART_PinConfig);
		//PA11 >> CTS
		if(Global_USART_Config[0]->HW_Flow_Ctl == USART_HW_FLOW_CTL_CTS	 || Global_USART_Config[0]->HW_Flow_Ctl == USART_HW_FLOW_CTL_RTS_CTS)
		{
			USART_PinConfig.GPIO_PinNumber = GPIO_PIN_11 ;
			USART_PinConfig.GPIO_MODE =	GPIO_MODE_AF_INPUT ;
			MCAL_GPIO_INIT(GPIOA, &USART_PinConfig);
		}
		if(Global_USART_Config[0]->HW_Flow_Ctl == USART_HW_FLOW_CTL_RTS	 || Global_USART_Config[0]->HW_Flow_Ctl == USART_HW_FLOW_CTL_RTS_CTS)
		{
			USART_PinConfig.GPIO_PinNumber = GPIO_PIN_12 ;
			USART_PinConfig.GPIO_MODE =	GPIO_MODE_AF_INPUT ;
			MCAL_GPIO_INIT(GPIOA, &USART_PinConfig);
		}
	}
	else if(USARTx == USART2)
	{
		//" PA2->TX " ,, " PA3->RX " ,," PA0 -> CTS " ,, " PA1 -> RTS "
		//PA2  >>	TX
		USART_PinConfig.GPIO_PinNumber = GPIO_PIN_2 ;
		USART_PinConfig.GPIO_MODE =	GPIO_MODE_OUTPUT_AF_PP ;
		USART_PinConfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M ;
		MCAL_GPIO_INIT(GPIOA, &USART_PinConfig);
		//PA3 >> RX
		USART_PinConfig.GPIO_PinNumber = GPIO_PIN_3 ;
		USART_PinConfig.GPIO_MODE =	GPIO_MODE_AF_INPUT;
		MCAL_GPIO_INIT(GPIOA, &USART_PinConfig);
		//PA0 >> CTS
		if(Global_USART_Config[1]->HW_Flow_Ctl == USART_HW_FLOW_CTL_CTS	 || Global_USART_Config[1]->HW_Flow_Ctl == USART_HW_FLOW_CTL_RTS_CTS)
		{
			USART_PinConfig.GPIO_PinNumber = GPIO_PIN_0 ;
			USART_PinConfig.GPIO_MODE =	GPIO_MODE_AF_INPUT ;
			MCAL_GPIO_INIT(GPIOA, &USART_PinConfig);
		}
		if(Global_USART_Config[1]->HW_Flow_Ctl == USART_HW_FLOW_CTL_RTS	 || Global_USART_Config[1]->HW_Flow_Ctl == USART_HW_FLOW_CTL_RTS_CTS)
		{
			USART_PinConfig.GPIO_PinNumber = GPIO_PIN_1 ;
			USART_PinConfig.GPIO_MODE =	GPIO_MODE_AF_INPUT ;
			MCAL_GPIO_INIT(GPIOA, &USART_PinConfig);
		}
	}
	else if(USARTx == USART3)
	{
		//" PB10->TX " ,, " PB11->RX " ,," PB13 -> CTS " ,, " PB14 -> RTS "
		//PB10  >>	TX
		USART_PinConfig.GPIO_PinNumber = GPIO_PIN_10 ;
		USART_PinConfig.GPIO_MODE =	GPIO_MODE_OUTPUT_AF_PP ;
		USART_PinConfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M ;
		MCAL_GPIO_INIT(GPIOB, &USART_PinConfig);
		//PB11 >> RX
		USART_PinConfig.GPIO_PinNumber = GPIO_PIN_11 ;
		USART_PinConfig.GPIO_MODE =	GPIO_MODE_AF_INPUT;
		MCAL_GPIO_INIT(GPIOB, &USART_PinConfig);
		//PB13 >> CTS
		if(Global_USART_Config[2]->HW_Flow_Ctl == USART_HW_FLOW_CTL_CTS	 || Global_USART_Config[2]->HW_Flow_Ctl == USART_HW_FLOW_CTL_RTS_CTS)
		{
			USART_PinConfig.GPIO_PinNumber = GPIO_PIN_13 ;
			USART_PinConfig.GPIO_MODE =	GPIO_MODE_AF_INPUT ;
			MCAL_GPIO_INIT(GPIOB, &USART_PinConfig);
		}
		if(Global_USART_Config[2]->HW_Flow_Ctl == USART_HW_FLOW_CTL_RTS	 || Global_USART_Config[2]->HW_Flow_Ctl == USART_HW_FLOW_CTL_RTS_CTS)
		{
			USART_PinConfig.GPIO_PinNumber = GPIO_PIN_14 ;
			USART_PinConfig.GPIO_MODE =	GPIO_MODE_AF_INPUT ;
			MCAL_GPIO_INIT(GPIOB, &USART_PinConfig);
		}
	}
}
/**================================================================
 * @Fn               - MCAL_UART_SendData
 * @brief            - send buffer on UART
 * @param[in]        - USARTX :where x can be 1,2,3 depending on device used
 * @param[in]        - PtxBuffer: the buffer that will be transmitted
 * @param[in]        - PollingEn enable or disable the polling
 * @retval           - none
 * @Note             - Should initialize UART First
 * 					   When transmitting with the parity enabled (PCE bit set to 1 in the USART_CR1 register),
 *					   the value written in the MSB (bit 7 or bit 8 depending on the data length) has no effect
 *					   because it is replaced by the parity.
 *  				   When receiving with the parity enabled, the value read in the MSB bit is the received parity
 *==================================================================*/
void MCAL_USART_SendData (USART_TypeDef* USARTx, uint16_t* pTx_BUffer,USART_Polling_Mechanism PollingEn)
{

	//wait until TXE flag is set in SR
	if(PollingEn == USART_enable)
		while(! (USARTx->SR & 1<<7) );
	// Which USART Will Be Used
	if (USARTx == USART1)
		USART_Index = 0 ;
	else if (USARTx == USART2)
		USART_Index = 1 ;
	else if (USARTx == USART3)
		USART_Index = 2 ;
	/*When transmitting with the parity enabled (PCE bit set to 1 in the USART_CR1 register),
	  the value written in the MSB (bit 7 or bit 8 depending on the data length) has no effect
	  because it is replaced by the parity.
	  When receiving with the parity enabled, the value read in the MSB bit is the received parity bit.*/
	if (Global_USART_Config[USART_Index]->PayLoad_Length == USART_PAYLOAD_LENGTH_9B)
		USARTx->DR = (*pTx_BUffer & (uint16_t)0x01FF);
	else
		USARTx->DR = (*pTx_BUffer & (uint16_t)0xFF);
}
/**================================================================
 * @Fn            - MCAL_USAET_RecieveData
 * @brief         - receive buffer from UART
 * @param[in]     - USARTX :where x can be 1,2,3 depending on device used
 * @param[in]     - PtxBuffer: the recieved buffer
 * @param[in]     - PollingEn enable or disable the polling
 * @retval        - none
 * @Note          - none																										*
 *==================================================================*/
void MCAL_USART_RecrviedData(USART_TypeDef* USARTx, uint16_t* pTx_BUffer,USART_Polling_Mechanism PollingEn)
{
	// RXNE recieve not empty
	if (PollingEn == USART_enable)
		while(!(USARTx->SR & (1<<5))) ;
	// Which USART Will Be Used
		if (USARTx == USART1)
			USART_Index = 0 ;
		else if (USARTx == USART2)
			USART_Index = 1 ;
		else if (USARTx == USART3)
			USART_Index = 2 ;
	// check the word length
	if (Global_USART_Config[USART_Index]->PayLoad_Length == USART_PAYLOAD_LENGTH_9B)
	{
		if (Global_USART_Config[USART_Index]->Parity == USART_PARITY_NONE)
			*((uint16_t*)pTx_BUffer) = USARTx->DR ;
		else
			*((uint16_t*)pTx_BUffer) = (USARTx->DR & ((uint8_t)0xFF));
	}
	else
	{
		if (Global_USART_Config[USART_Index]->Parity == USART_PARITY_NONE)
			*((uint16_t*)pTx_BUffer) = (USARTx->DR & ((uint8_t)0xFF));
		else
			*((uint16_t*)pTx_BUffer) = (USARTx->DR & ((uint8_t)0x7F));
	}
}

void MCAL_USART_Wait_TC(USART_TypeDef* USARTx)
{
	while (! (USARTx->SR & (1<<6) ));
}

/*
 * =====================================================================================
 * 							ISR Functions
 * =====================================================================================
 */
void USART1_IRQHandler (void)
{
	Global_USART_Config[0]->P_IRQ_CallBack();
}
void USART2_IRQHandler (void)
{
	Global_USART_Config[1]->P_IRQ_CallBack();
}
void USART3_IRQHandler (void)
{
	Global_USART_Config[2]->P_IRQ_CallBack();
}
