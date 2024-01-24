#include "Pressure_Sensor_Driver.h"
uint32_t Pressure_Sensor_Value ;
void (* P_Func_Pressure_Sensor)();
/* Implement The Pressure sensor init */
void Pressure_Sensor_Init(void)
{
	/* Driver Init */
	GPIO_INITIALIZATION();
}
/*	Implement the State function */
STATE_Define(Pressure_Sensor_Reading)
{
	// State Name
	Pressure_Sensor_State = Pressure_Sensor_Reading ;
	// State Action
	// reading from Sensor
	Pressure_Sensor_Value = getPressureVal();
	// send Signal to Main Block
	Set_Pressure_Val(Pressure_Sensor_Value);
	// Set delay
	Delay(100) ;
	/** Set Next State**/
	P_Func_Pressure_Sensor = STATE(Pressure_Sensor_Waiting);
}
STATE_Define(Pressure_Sensor_Waiting)
{
	Pressure_Sensor_State = Pressure_Sensor_Waiting ;
	P_Func_Pressure_Sensor =STATE(Pressure_Sensor_Reading);
}
