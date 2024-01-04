#include"Platform_Type.h"
#define RCC_BASE 			0x4002100
#define GPIO_PORTA_BASE		0x40010800
#define RCC_APB2ENR 		*(vuint32_t *)(RCC_BASE + 0x18)
#define GPIO_CRH 			*(vuint32_t *)(GPIO_PORTA_BASE + 0x04)
#define GPIO_ODR 			*(vuint32_t *)(GPIO_PORTA_BASE + 0x0c)
/* We Can Override on weak Symbol in main.c */
extern void NMI_Handler(void) {}
extern void Usage_fault_Handler(void) {}
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
unsigned char var_one[3] = {1,2,3};
unsigned char const var_two_const[3] = {1,2,3};
unsigned char var_three_bss ;
int main(void)
{
	/************************** first way *********************
	RCC_APB2ENR |= 1<<2 ;
	GPIO_CRH &= 0xff0fffff ;
	GPIO_CRH |= 0x00200000 ;
	while (1)
	{
		GPIO_ODR |= 1<<13 ;  // set specific bit bit 13
		for (int i = 0 ; i <50000 ; i++ ) ;
		GPIO_ODR &=~(1<<13) ; // clear specific bit 13
		for (int i = 0 ; i <50000 ; i++ );
	}
	 ************************** End of first way ************ */

	//******************** Another way ************************
	while (1)
	{
		R_ODR->pin.pin13 = 1;
		for ( int i = 0 ; i <5000 ; i++ ) ;
		R_ODR->pin.pin13 = 0 ;
		for (int i = 0 ; i <5000 ; i++ ) ;
	}
	// ******************** End of Another way ******************/
	return 0 ;
}
