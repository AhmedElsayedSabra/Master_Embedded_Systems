#ifndef Led_Driver_H_
#define Led_Driver_H_
#include "driver.h"
#include "State.h"

enum
{
	Led_Driver_On,
	Led_Driver_Off,
	Led_Driver_Waiting
}Led_Driver_State;

void Led_Driver_init();
void Start_Alarm();
void Stop_Alarm();
STATE_Define(Led_Driver_Waiting);

/* Pointer to Led Driver Functiion */

extern void (* P_Func_Led_Driver)();

#endif
