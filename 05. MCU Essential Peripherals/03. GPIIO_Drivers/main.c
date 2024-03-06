#include"Platform_Type.h"
#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "Stm32f103x6.h"
#include "Stm32_F103c6_GPIO_Driver.h"

enum Status
{
	Low ,
	High
}Button_Status;
void Init_Clock(void)
{
	// Set GPIOA,GPIOB Clock
	RCC_GPIOA_CLK_EN() ;
	RCC_GPIOB_CLK_EN();
}
void Init_GPIOA(void)
{
	GPIO_PinConfig_TypeDef PinCFG ;
	// PA1 Input High Z
	PinCFG.GPIO_PinNumber =GPIO_PIN_1 ;
	PinCFG.GPIO_MODE = GPIO_MODE_INPUT_FLO ;
	MCAL_GPIO_INIT(GPIOA, &PinCFG);
	// PA13 Input High Z
	PinCFG.GPIO_PinNumber =GPIO_PIN_13 ;
	PinCFG.GPIO_MODE = GPIO_MODE_INPUT_FLO ;
	MCAL_GPIO_INIT(GPIOA, &PinCFG);
	// PB1 As output Push pull Mode
	PinCFG.GPIO_PinNumber =GPIO_PIN_1 ;
	PinCFG.GPIO_MODE = GPIO_MODE_OUTPUT_PP ;
	PinCFG.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M ;
	MCAL_GPIO_INIT(GPIOB, &PinCFG);
	// PB13 As output Push pull Mode
	PinCFG.GPIO_PinNumber =GPIO_PIN_13 ;
	PinCFG.GPIO_MODE = GPIO_MODE_OUTPUT_PP ;
	PinCFG.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M ;
	MCAL_GPIO_INIT(GPIOB, &PinCFG);
}
void Wait_Function (int x)
{
	uint32_t i , j ;
	for (i = 0 ; i <x ; i++)
		for (j= 0 ; j <255 ; j++);
}
int main(void)
{
	Init_Clock();
	Init_GPIOA();
	while(1)
	{
		// Check the PA1 >> External PUR >> Default By One
		if (MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == Low)
		{
			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_1) ;
			while(MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == Low); // Single Pressing
		}
		// Check the PA13 >> External PDR >> Default By Zero
		if (MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_13) == High)
		{
			// Multi Press
			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_13) ;
		}
		Wait_Function(1);
	}
}
