#include"Platform_Type.h"
#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#define Toggle_Bit(Register_Name,Number_Of_Bit) 		Register_Name^=(1<<Number_Of_Bit)
#define Set_Bit_By_One(Register_Name,Number_Of_Bit) 	Register_Name|=(1<<Number_Of_Bit)
#define Reset_Bit_By_Zero(Register_Name,Number_Of_Bit) 	Register_Name&=~(1<<Number_Of_Bit)
#define Read_Bit(Register_Name,Number_Of_Bit)			((Register_Name&(1<<Number_Of_Bit))>>Number_Of_Bit)

#define RCC_BASE 			0x40021000
#define RCC_APB2ENR 		*(vuint32_t *)(RCC_BASE + 0x18) // Enable Clock To APB2Bus

#define GPIO_PORTA_BASE		0x40010800
#define GPIOA_CRH 			*(vuint32_t *)(GPIO_PORTA_BASE + 0x04) // port Configuration Register High
#define GPIOA_CRL 			*(vuint32_t *)(GPIO_PORTA_BASE + 0x00) // port Configuration Register low
#define GPIOA_ODR 			*(vuint32_t *)(GPIO_PORTA_BASE + 0x0c) // port output data register
#define GPIOA_IDR 			*(vuint32_t *)(GPIO_PORTA_BASE + 0x08) // port Input data register

#define GPIO_PORTB_BASE		0x40010C00
#define GPIOB_CRH 			*(vuint32_t *)(GPIO_PORTB_BASE + 0x04) // port Configuration Register High
#define GPIOB_CRL 			*(vuint32_t *)(GPIO_PORTB_BASE + 0x00) // port Configuration Register low
#define GPIOB_ODR 			*(vuint32_t *)(GPIO_PORTB_BASE + 0x0c) // port output data register
#define GPIOB_IDR 			*(vuint32_t *)(GPIO_PORTA_BASE + 0x08) // port Input data register
enum Status
{
	Low ,
	High
}Button_Status;
void Init_Clock(void)
{
	// Set GPIOA Clock
	Set_Bit_By_One(RCC_APB2ENR,2);
	// Set GPIOB Clock
	Set_Bit_By_One(RCC_APB2ENR,3);
}
void Init_GPIOA(void)
{
	// PA1 Input High Z
	Reset_Bit_By_Zero(GPIOA_CRL,6); 		// Reset Bit Number 6 Before any thing
	GPIOA_CRL &=~(0b11<<4); 					// Bits Mode 4,5 As Input mode
	GPIOA_CRL |=(0b01 <<6); 					// Bits 6,7 Floating

	// PA13 Input High Z
	Reset_Bit_By_Zero(GPIOA_CRH,22); 		// Reset Bit Number 22 Before any thing
	GPIOA_CRH &=~(0b11<<20); 				// Bits Mode 20,21 As Input mode
	GPIOA_CRH |=(0b01<<22);					// Bits 22,23 Floating

	// PB1 As output Push pull Mode
	Reset_Bit_By_Zero(GPIOB_CRL,6);			// Reset Bit Number 6 Before any thing
	GPIOB_CRL |=(0b01 << 4); 				// Bits Mode 4,5 As Output mode
	GPIOB_CRL &=~(0b11  << 6);				// CNF Bit 6,7 to GP Output push pull

	// PB13 As output Push pull Mode
	Reset_Bit_By_Zero(GPIOB_CRH,22); 	    // Reset Bit Number 22 Before any thing
	GPIOB_CRH |=(0b01<<20); 			    // Bits Mode 4,5 As Output mode[0,0]
	GPIOB_CRH &=~(0b11<<22);				    // CNF Bit 22,23 to GP Output push pull[0,0]
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
		if (Read_Bit(GPIOA_IDR,1) == Low)
		{
			Toggle_Bit(GPIOB_ODR,1);
			while(Read_Bit(GPIOA_IDR,1) == Low); // Single Pressing
		}
		// Check the PA13 >> External PDR >> Default By Zero
		if (Read_Bit(GPIOA_IDR,13) == High)
		{
			// Multi Press
			Toggle_Bit(GPIOB_ODR,13);
		}
		Wait_Function(1);
	}
}
