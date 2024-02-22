#include <util/delay.h>
#include "ATmega32_Register.h"
#include "Utilites.h"
void GPIO_Init(void)
{
	//Set PIND0 As Input Pull Down
	CLEAR_BIT(DDRD,0);
	// Set PinD4 As Output
	SET_BIT(DDRD,4);
}
enum 
{
	Low ,
	High
}Button_Status;
int main(void)
{
    GPIO_Init();
    while (1) 
    {
		if (GET_BIT(PIND,0) == High)
		{
			SET_BIT(PORTD,4);
			while(GET_BIT(PIND,0) == High);// Single press
			_delay_ms(1000);
		}
		else
		{
			CLEAR_BIT(PORTD,4);
		}	
    }
}