
#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif
#include "Stm32_F103c6_EXTI_Driver.h"
#include "STM32F103x6_LCD_Driver.h"
#include "Stm32_F103c6_USART_Driver.h"

unsigned char ch ;
void USART_IRQ_CallBack(void)
{
	MCAL_USART_RecrviedData(USART1, &ch, USART_disable);
	MCAL_USART_SendData    (USART1, &ch, USART_enable);
}
int main(void)
{
	// Enable The Clock
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
	RCC_AFIO_CLK_EN();
	USART_Config_Typedef USART_Config;
	USART_Config.USART_Baudrate = USART_BaudRate_115200 ;
	USART_Config.HW_Flow_Ctl = USART_HW_FLOW_CTL_NONE ;
	USART_Config.Parity = USART_PARITY_NONE ;
	USART_Config.PayLoad_Length = USART_PAYLOAD_LENGTH_8B ;
	USART_Config.Stop_Bit = USART_STOP_BIT_1 ;
	USART_Config.USART_Mode = USART_MODE_RX_TX ;
	USART_Config.IRQ_Enalbe = USART_IRQ_Enable_RXNEIE;
	USART_Config.P_IRQ_CallBack = USART_IRQ_CallBack ;
	MCAL_USART_Init(USART1, &USART_Config) ;
	MCAL_USART_GPIO_Set_Pins(USART1) ;
	while (1)
	{
	}
}
