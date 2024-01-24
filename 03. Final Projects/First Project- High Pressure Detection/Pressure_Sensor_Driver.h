#ifndef Pressure_Sensor_Driver_H_
#define Pressure_Sensor_Driver_H_
#include "State.h"
#include "driver.h"

// define State of Pressure Sensor
enum
{
	Pressure_Sensor_Reading,
	Pressure_Sensor_Waiting
}Pressure_Sensor_State;
// define Init Sensor Function
void Pressure_Sensor_Init(void);
// define State of Sensor
STATE_Define(Pressure_Sensor_Reading);
STATE_Define(Pressure_Sensor_Waiting);

extern void (* P_Func_Pressure_Sensor)();
#endif
