#include "Alarm_Monitor.h"
#include "Platform_Type.h"
uint32_t alarm_Period = 60 ;
void (* P_Func_Alarm_Monitor)();
void Alarm_Monitor_init(void)
{
	/* Driver Init */
	GPIO_INITIALIZATION();
}
void High_Pressure_Detected(void)
{
	// Set the Next Step
	P_Func_Alarm_Monitor = STATE(Alarm_Monitor_On);
}
STATE_Define(Alarm_Monitor_On)
{
	// State Name
	Alarm_Monitor_State = Alarm_Monitor_On ;
	//Action
	Start_Alarm();
	Delay(alarm_Period);
	// next step
	P_Func_Alarm_Monitor =STATE(Alarm_Monitor_Waiting);
}
STATE_Define(Alarm_Monitor_Off)
{
	// Statem Name
	Alarm_Monitor_State = Alarm_Monitor_Off ;
	// No Action

}
STATE_Define(Alarm_Monitor_Waiting)
{
	// State Name
	Alarm_Monitor_State = Alarm_Monitor_Waiting  ;
	//Action
	Stop_Alarm();
	// next
	P_Func_Alarm_Monitor = STATE(Alarm_Monitor_Off);
}

