/*
 * Main_Algorithm.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: A7MED
 */
#include "Main_Algorithm.h"
#include "State.h"
uint32_t  main_Pressure_Sensor_Value = 0 ;
const uint32_t Threshold = 20 ;
void (* P_Func_Main_Algorithm_State)();
void Set_Pressure_Val(int P_Val)
{
	// Action
	main_Pressure_Sensor_Value = P_Val ;
	// Setting Next Step
	P_Func_Main_Algorithm_State = STATE(Main_High_Pressure_Detected);
}
STATE_Define(Main_High_Pressure_Detected)
{
	// State Name
	Main_Algorithm_State = Main_High_Pressure_Detected ;
	// Action
	if (main_Pressure_Sensor_Value <=  Threshold)
		P_Func_Main_Algorithm_State = STATE(Main_High_Pressure_Detected);
	else
	{
		High_Pressure_Detected();
		P_Func_Main_Algorithm_State =STATE(Main_High_Pressure_Detected);
	}
}
