#include<stdio.h>
#include"can.h"
int main (void)
{
	printf("Hello in main ya can\n");
	can_init();
	can_send();
	can_finish();
	return 0 ;
}