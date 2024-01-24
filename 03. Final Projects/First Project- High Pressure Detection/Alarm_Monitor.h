#ifndef Alarm_Monitor_H_
#define Alarm_Monitor_H_
#include "State.h"
#include "driver.h"
#include "Led_Driver.h"
// State definfe
enum
{
	Alarm_Monitor_On,
	Alarm_Monitor_Off,
	Alarm_Monitor_Waiting
}Alarm_Monitor_State;

//define init function
void Alarm_Monitor_init(void);
// define State FUnction
STATE_Define(Alarm_Monitor_On);
STATE_Define(Alarm_Monitor_Off);
STATE_Define(Alarm_Monitor_Waiting);

extern void (* P_Func_Alarm_Monitor)();
#endif
