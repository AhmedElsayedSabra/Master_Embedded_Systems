#include <util/delay.h>
#include <avr/io.h>
#include <avr/common.h>
#include <avr/interrupt.h>

#define Toggle_Bit(Register_Name,Number_Of_Bit) 		Register_Name^=(1<<Number_Of_Bit)
#define Set_Bit_By_One(Register_Name,Number_Of_Bit) 	Register_Name|=(1<<Number_Of_Bit)
#define Reset_Bit_By_Zero(Register_Name,Number_Of_Bit) 	Register_Name&=~(1<<Number_Of_Bit)
void Interrupt_Init()
{
	// Bit 7 – INT1: External Interrupt Request 1 Enable
	// 0: Disable external interrup  || 	1: Enable external interrupt
	Set_Bit_By_One(GICR,7);
	// Bit 6 – INT0: External Interrupt Request 0 Enable
	// 0: Disable external interrupt   ||   1: Enable external interrupt
	Set_Bit_By_One(GICR,6);
	// Set Sense Control To Interrupt 1 On Register "MCUCR" Bit 3, 2
	MCUCR |=(0b01 << 2);
	// Set Sense Control To Interrupt 1 On Register "MCUCR" Bit 1, 0
	MCUCR |=(0b01 << 0);
}
void GPIO_Init(void)
{
	// Set Pin D3 As Input
	Reset_Bit_By_Zero(DDRD,2) ;
	// Set Pin D4 As Input
	Reset_Bit_By_Zero(DDRD,3) ;
	//Set Pin D6 As Output
	Set_Bit_By_One(DDRD,5);
	//Set Pin D7 As Output
	Set_Bit_By_One(DDRD,6);
}

int main (void)
{
	// Clock_init();
	GPIO_Init();
	Interrupt_Init();
	while(1);
	return 0 ;
}

ISR(INT0_vect)
{
	//Toggle Pin D6
	Toggle_Bit(PORTD,5);
	//Delay For One Second
	_delay_ms(1000);
	Toggle_Bit(PORTD,5);
	// Bit 6 – INTF0: External Interrupt Flag 0
	Set_Bit_By_One(GIFR,6);			// Write One to Clear The Flags
}

ISR(INT1_vect)
{
	//Toggle Pin D7
	Toggle_Bit(PORTD,6);
	//Delay For One Second
	_delay_ms(1000);
	Toggle_Bit(PORTD,6);
	// Bit 7 – INTF0: External Interrupt Flag 1
	Set_Bit_By_One(GIFR,7);			// Write One to Clear The Flags
}
