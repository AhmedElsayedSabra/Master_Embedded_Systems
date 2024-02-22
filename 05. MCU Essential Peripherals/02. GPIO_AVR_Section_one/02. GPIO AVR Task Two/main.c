#include "ATmega32_Register.h"
#include "Utilites.h"
#include <util/delay.h>
enum 
{
	Low ,
	High
}Button_Status;
void GPIO_Init(void)
{
	CLEAR_BIT(DDRD,0);
	SET_BIT(DDRD,5);
	SET_BIT(DDRD,6);
	SET_BIT(DDRD,7);
}

int main(void)
{
	GPIO_Init();
	vuint8_t Count = 5;
	while (1) 
	{
		if (GET_BIT(PIND,0) == High && Count <=8 )
		{
			
			if (Count == 8)
			{
				CLEAR_BIT(PORTD,7);
				CLEAR_BIT(PORTD,6);
				CLEAR_BIT(PORTD,5);
				while(GET_BIT(PIND,0) == High && Count ==8 );
				_delay_ms(1000);
				Count = 5 ;
			}
			else
			{
				SET_BIT(PORTD,Count);
				while(GET_BIT(PIND,0) == High && Count <=7); // Single Pressing
				_delay_ms(1000);
				Count++;
			}
		}
	}
	return 0 ;
}
