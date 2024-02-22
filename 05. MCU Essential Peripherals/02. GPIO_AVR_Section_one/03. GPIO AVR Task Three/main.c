/*
 * AVR_GPIO_Task_Three_7Seg_Clock.c
 * Created: 22/02/2024 12:50:54 
 * Author : A7MED
 */
#include <util/delay.h>
#include "ATmega32_Register.h"
#include "Utilites.h"
#define SSeg_Second_Port	PORTC    // PC4 : :  PC7
#define Count_Of_Second		10
#define Initial_State		(char)0
unsigned char Second_Counter_Ones  = Initial_State ,
			  Second_Counter_Tens  = Initial_State ;
unsigned char SSeg_Dispaly[10]={0b0000,0b0001,0b0010,0b0011,0b0100,0b0101,0b0110,0b0111,0b01000,0b1001};
void GPIO_Init (void)
{
	DDRC =0xff ;	// Make the PORTC As Output. 
}

int main(void)
{
	GPIO_Init();
	PORTC=0x00 ;
    while (1) 
    {
		for (Second_Counter_Tens = Initial_State ; Second_Counter_Tens <10 ; Second_Counter_Tens++)
		{
			for (Second_Counter_Ones = Initial_State ; Second_Counter_Ones <10 ; Second_Counter_Ones++)
			{
				SSeg_Second_Port = 0b0111 |(SSeg_Dispaly[Second_Counter_Ones]<<4);
				_delay_ms(1000);
			}
			SSeg_Second_Port = 0b1011 | (SSeg_Dispaly[Second_Counter_Tens]<<4);
			_delay_ms(1000);
		}
    }
	return 0 ;
}