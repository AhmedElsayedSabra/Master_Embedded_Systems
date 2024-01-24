#include "State.h"
#include "driver.h"
#include "Led_Driver.h"
#include "Pressure_Sensor_Driver.h"
#include "Platform_Type.h"
#include "Alarm_Monitor.h"
#include "Main_Algorithm.h"
void Set_Up(void)
{
	/* Init All the Driver*/
	Led_Driver_init();
	Pressure_Sensor_Init();
	Alarm_Monitor_init();
	/*Set all Entry Point to each block */
	P_Func_Pressure_Sensor =STATE(Pressure_Sensor_Reading);
	P_Func_Main_Algorithm_State = Set_Pressure_Val;
	P_Func_Alarm_Monitor = Stop_Alarm;
	P_Func_Led_Driver=STATE(Led_Driver_Waiting);
}

int main ()
{
	Set_Up();
	GPIO_INITIALIZATION();
	while (1)
	{
		P_Func_Pressure_Sensor();
		P_Func_Main_Algorithm_State();
		P_Func_Alarm_Monitor();
		P_Func_Led_Driver();
		//Implement your Design 
	}

}
