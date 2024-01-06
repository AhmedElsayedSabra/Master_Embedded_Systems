#include"Platform_Type.h"
			/* First Approch to access absolute address*/
#define SYSCTL 0x400FE000
#define GPIOF 0x40025000
#define  SYSCTL_RCCG2R 			(*((vuint32_t*)(SYSCTL + 0x108  )))	//Enable the port f
#define  GPIO_PORTF_DEN_R 		(*((vuint32_t*)(GPIOF  + 0x51C )))	// enable the pin of port f 
#define  GPIO_PORTF_DIR_R 		(*((vuint32_t*)(GPIOF  + 0x400 )))	// set the direction of pin 
#define  GPIO_PORTF_DATA_R 		(*((vuint32_t*)(GPIOF  + 0X3FC )))	// write your data on register
			/* second Approch to access absolute address*/
			
/* We Can Override on weak Symbol in main.c because it is weak symbol and alias on startup.c */
extern void NMI_Handler(void) {}
extern void Usage_fault_Handler(void) {}
// .data & .rodata & .bss Variable 
unsigned char var_one[3] = {1,2,3};
unsigned char const var_two_const[3] = {1,2,3};
unsigned char var_three_bss ;
int main(void)
{
	vuint32_t delay_counter ;
	SYSCTL_RCCG2R = 0x20 ;
	// delay for affect the system
	for(delay_counter = 0 ; delay_counter < 200000 ; delay_counter++);
	GPIO_PORTF_DEN_R |= (1<<3) ;
	GPIO_PORTF_DIR_R |= (1<<3) ;
	while(1)
	{
		GPIO_PORTF_DATA_R |= (1<<3) ;
		for(delay_counter = 0 ; delay_counter<200000 ; delay_counter++);
		GPIO_PORTF_DATA_R &=~(1<<3) ;
		for(delay_counter = 0 ; delay_counter<200000 ; delay_counter++);
	} 
	return 0 ;
}