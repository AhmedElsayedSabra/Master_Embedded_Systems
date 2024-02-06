#include"Platform_Type.h"
#define RCC_BASE 			0x40021000
#define GPIO_PORTA_BASE		0x40010800
#define RCC_APB2ENR 		*(vuint32_t *)(RCC_BASE + 0x18)
#define GPIO_CRH 			*(vuint32_t *)(GPIO_PORTA_BASE + 0x04)
#define GPIO_ODR 			*(vuint32_t *)(GPIO_PORTA_BASE + 0x0c)
#define RCC_CFGR 			*(vuint32_t *)(RCC_BASE + 0x04)
void Clock_Init()
{
	RCC_CFGR    |= (0b101<<11); // APB2 Prescaler
	RCC_CFGR    |= (0b100<<8) ; // APB1 Prescaler
	RCC_APB2ENR |= (1<<2); 		// Enable Clcok GPIOPA
	RCC_CFGR    |= (0b0 <<7) ;	// AHB Prescaler
	RCC_CFGR    |= (0b00 << 0) ;// Select HSI As A System Clcok
}
int main(void)
{
	Clock_Init();
	GPIO_CRH &= 0xff0fffff ;
	GPIO_CRH |= 0x00200000 ;
	while (1)
	{
		GPIO_ODR |= 1<<13 ;  // set specific bit bit 13
		for (int i = 0 ; i <5000 ; i++ ) ;
		GPIO_ODR &=~(1<<13) ; // clear specific bit 13
		for (int i = 0 ; i <5000 ; i++ );
	}
	return 0 ;
}
