#include"Platform_Type.h"
#define RCC_BASE 			0x40021000
#define GPIO_PORTA_BASE		0x40010800
#define RCC_APB2ENR 		*(vuint32_t *)(RCC_BASE + 0x18)
#define GPIO_CRH 			*(vuint32_t *)(GPIO_PORTA_BASE + 0x04)
#define GPIO_ODR 			*(vuint32_t *)(GPIO_PORTA_BASE + 0x0c)
#define RCC_CFGR 			*(vuint32_t *)(RCC_BASE + 0x04)
#define RCC_CR				*(vuint32_t *)(RCC_BASE + 0x00)
void Clock_Init()
{
	// Enable Clock GPIOPA
	RCC_APB2ENR |= (1<<2);
	// Bits 21:18 PLLMUL: PLL multiplication factor
	// 0110: PLL input clock x 8
	RCC_CFGR |= (0b0110 << 18) ;
	// Bits 1:0 SW: System clock switch
	// 10: PLL selected as system clock
	RCC_CFGR |= (0b10 << 0) ;
	// Bits 13:11 PPRE2: APB high-speed prescaler (APB2)
	// 101: HCLK divided by 4
	RCC_CFGR |= (0b101 << 11) ;
	// Bits 10:8 PPRE1: APB low-speed prescaler (APB1)
	// 100: HCLK divided by 2
	RCC_CFGR |= (0b100 << 8) ;
	// Bit 24 PLLON: PLL enable
	// 1: PLL ON
	RCC_CR |= (1<< 24) ;
	//  Bit 0 HSION: Internal high-speed clock enable
	//	1: internal 8 MHz RC oscillator ON
	RCC_CR |= (1<< 0) ;
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
