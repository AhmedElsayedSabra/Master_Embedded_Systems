#include "uart.h"
#include<stdio.h>
unsigned char string_buffer[100] = "learn in depth:AHMED";
int  const ahmed = 10 ;
void main (void)
{
	uart_send_string(string_buffer);
}