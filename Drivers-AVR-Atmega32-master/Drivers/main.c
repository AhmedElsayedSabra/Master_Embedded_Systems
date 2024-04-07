/*
 * main.c
 *
 *  Created on: Jan 4, 2024
 *      Author: Ahmed Elsayed 
 */
#include "LCD.h"
#include "Keypad.h"
#include "ADC.h"
#include "SPI.h"
#include "EEPROM.h"

int main(void)
{
	uint8 LED = 0;
	DDRD = 0xFF;
	PORTD = 0x00;
	EEPROM_Init();
	EEPROM_WriteByte(0x0311,0x2F);
	_delay_ms(10);
	EEPROM_ReadByte(0x0311,&LED);
	while (1)
	{
		PORTD = LED;
	}
	return 0;
}


