#include"Platform_Type.h"
#define RCC_BASE 			0x4002100
#define GPIO_PORTA_BASE		0x40010800
#define RCC_APB2ENR 		*(vuint32_t *)(RCC_BASE + 0x18)
#define GPIO_CRH 			*(vuint32_t *)(GPIO_PORTA_BASE + 0x04)
#define GPIO_ODR 			*(vuint32_t *)(GPIO_PORTA_BASE + 0x0c)
typedef union
{
	vuint32_t all_field ;
	struct
	{
		vuint32_t reserved:13 ;
		vuint32_t pin13:1 ;
	}pin ;
}R_ODR_t;
volatile R_ODR_t* R_ODR = (volatile R_ODR_t *)(GPIO_PORTA_BASE +0x0c );

int main(void)
{
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
