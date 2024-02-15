#include"Platform_Type.h"
#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#define Toggle_Bit(Register_Name,Number_Of_Bit) 		Register_Name^=(1<<Number_Of_Bit)
#define Set_Bit_By_One(Register_Name,Number_Of_Bit) 	Register_Name|=(1<<Number_Of_Bit)
#define Reset_Bit_By_Zero(Register_Name,Number_Of_Bit) 	Register_Name&=~(1<<Number_Of_Bit)

#define RCC_BASE 			0x40021000
#define RCC_APB2ENR 		*(vuint32_t *)(RCC_BASE + 0x18) // Enable Clock To APB2Bus

#define NVIC_BASE           0xE000E100
#define NVIC_ISER0			*(vuint32_t *)(NVIC_BASE + 0x00) // Enable Interrupt Register

#define EXTI_BASE 			0x40010400
#define EXTI_IMR			*(vuint32_t *)(EXTI_BASE + 0x00)
#define EXTI_RTSR			*(vuint32_t *)(EXTI_BASE + 0x08)
#define EXTI_PR				*(vuint32_t *)(EXTI_BASE + 0x14)

#define AFIO_BASE 			0x40010000
#define AFIO_EXTICR1		*(vuint32_t *)(AFIO_BASE + 0x08)

#define GPIO_PORTA_BASE		0x40010800
#define GPIO_CRH 			*(vuint32_t *)(GPIO_PORTA_BASE + 0x04) // port Configuration Register High
#define GPIO_CRL 			*(vuint32_t *)(GPIO_PORTA_BASE + 0x00) // port Configuration Register low
#define GPIO_ODR 			*(vuint32_t *)(GPIO_PORTA_BASE + 0x0c) // port output data register

void Init_Clock(void)
{
	// Set GPIOA Clock
	Set_Bit_By_One(RCC_APB2ENR,2);
	// Set Clock to AFIo Circuit = Bit 0 AFIOEN : Alternate function IO Clock Enable
	Set_Bit_By_One(RCC_APB2ENR,0);
}
void Init_GPIOA(void)
{
	// Set Pin A13 As output;
	GPIO_CRH &= 0xff0fffff;
	GPIO_CRH |= 0x00200000;
	//Set Pin A0 =  Bit 2:3 >> 0b01 input Floating point
	GPIO_CRL |=(0b01<<2);
}
void Init_Interrupt(void)
{
	// Bits 3 : 0 EXTI0[3:0]: EXTI 0 configuration (x= 0 to 3)
	AFIO_EXTICR1 |=(0b0000<<0);
	// set EXTI Line 0 (mask 1) //Enable interrupt mask register
	Set_Bit_By_One(EXTI_IMR,0);
	// Set interrupt when rising edge
	Set_Bit_By_One(EXTI_RTSR,0);
	//Enable global Nested Vectored Interrupt Controller line 0 in EXTI map to line 6 in NVIC
	Set_Bit_By_One(NVIC_ISER0,6);
}
int main(void)
{
	Init_Clock();
	Init_GPIOA();
	Init_Interrupt();
	while(1);
}
void EXTI0_IRQHandler(void)
{
	Toggle_Bit(GPIO_ODR,13);  // toggle led PinA13
	Set_Bit_By_One(EXTI_PR,0); 		  // Write one to clear pending register
}
