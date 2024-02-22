#include <util/delay.h>

#include "ATmega32_Register.h"
#include "Utilites.h"

#define F_CPU 8000000UL
#include "ATmega32_Register.h"
#include "Utilites.h"

void clock_Init(void){};
void GPIO_Init(void)
{
	// Set PortA As output, 8 Pins from 0 >> 7.
	DDRD=0xff;
}

int main(void)
{
	GPIO_Init();
	while (1)
	{
		for(vuint8_t i = 5;  i <= 7;i++ )
		{
			SET_BIT(PORTD,i);
			_delay_ms(500);
		}
		for(vuint8_t i = 7;  i >= 5;i-- )
		{
			CLEAR_BIT(PORTD,i);
			_delay_ms(500);
		}
	}
	return 0 ;
}
