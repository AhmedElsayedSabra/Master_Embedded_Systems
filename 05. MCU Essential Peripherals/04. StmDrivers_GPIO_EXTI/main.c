
#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif
#include "Stm32_F103c6_EXTI_Driver.h"
#include "STM32F103x6_LCD_Driver.h"

unsigned int   IRQ_Flag = 0 ;

void wait_msFunc(uint32_t time )
{
	uint32_t i,j;
	for(i=0 ; i<time ; i++)
		for(j=0 ; j<255 ; j++);
}
void EXTI9_CallBack (void)
{
	IRQ_Flag = 1 ;
	uint8_t Str[] ="Ahmed Elsayed" ;
	HAL_LCD_WRITE_STRING((char* )Str);
	wait_msFunc(1000) ;
}
int main(void)
{
	// Enable The Clock
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
	RCC_AFIO_CLK_EN();
	HAL_LCD_INIT();
	HAL_LCD_CLEAR_SCREEN();
	EXTI_PinConfig_t EXTI_CFG;
	EXTI_CFG.EXTI_Pin =EXTI9PB9;
	EXTI_CFG.Trigger_case = EXTI_Trigger_Rising;
	EXTI_CFG.P_IRQ_CallBack = EXTI9_CallBack ;
	EXTI_CFG.IRQ_EN = EXTI_IRQ_ENABLE;
	MCAL_EXTI_GPIO_Init(&EXTI_CFG);
	IRQ_Flag = 1 ;
	while (1)
	{
		if (IRQ_Flag)
		{
			HAL_LCD_CLEAR_SCREEN();
			IRQ_Flag = 0 ;
		}
	}
}
