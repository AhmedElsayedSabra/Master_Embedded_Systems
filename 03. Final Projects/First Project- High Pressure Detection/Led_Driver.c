#include "Led_Driver.h"
void (* P_Func_Led_Driver)();
void Led_Driver_init()
{
	GPIO_INITIALIZATION();
}


void Start_Alarm()
{
	// State Name
	Led_Driver_State = Led_Driver_On ;
	//Action
	Set_Alarm_actuator(0);
	// Next Step
	P_Func_Led_Driver = STATE(Led_Driver_Waiting) ;
}
void Stop_Alarm()
{
	// State Name
	Led_Driver_State = Led_Driver_Off ;
	// Action
	Set_Alarm_actuator(1);
	// Next
	P_Func_Led_Driver = STATE(Led_Driver_Waiting) ;
}

STATE_Define(Led_Driver_Waiting)
{
	Led_Driver_State = Led_Driver_Waiting ;
	// No Action
}
