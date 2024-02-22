
/* File Guards to protect from recursive inclusion.*/
#ifndef ATMEGA32_REGISTER_H_
#define ATMEGA32_REGISTER_H_

#include "Platform_Data_Types.h"

/* Definition for PORTA Registers */
#define PORTA	(*(volatile uint8_t * const)0x003B)
#define DDRA	(*(volatile uint8_t * const)0x003A)
#define PINA 	(*(volatile const uint8_t * const)0x0039)

/* Definition for PORTB Registers */
#define PORTB	(*(volatile uint8_t * const)0x0038)
#define DDRB	(*(volatile uint8_t * const)0x0037)
#define PINB 	(*(volatile const uint8_t * const)0x0036)

/* Definition for PORTC Registers */
#define PORTC	(*(volatile uint8_t * const)0x0035)
#define DDRC	(*(volatile uint8_t * const)0x0034)
#define PINC 	(*(volatile const uint8_t * const)0x0033)

/* Definition for PORTD Registers */
#define PORTD	(*(volatile uint8_t * const)0x0032)
#define DDRD	(*(volatile uint8_t * const)0x0031)
#define PIND	(*(volatile const uint8_t * const)0x0030)

#endif /* ATMEGA32_REGISTER_H_ */
