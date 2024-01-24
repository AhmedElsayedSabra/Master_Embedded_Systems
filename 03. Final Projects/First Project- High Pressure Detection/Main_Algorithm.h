/*
 * Main_Algorithm.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: A7MED
 */

#ifndef MAIN_ALGORITHM_H_
#define MAIN_ALGORITHM_H_
#include "Platform_Type.h"
#include "State.h"
#include "driver.h"
// State ddefinition


enum
{
	Main_High_Pressure_Detected
}Main_Algorithm_State;
// Function Prototype

STATE_Define(Main_High_Pressure_Detected);

extern void (* P_Func_Main_Algorithm_State)();
#endif /* MAIN_ALGORITHM_H_ */
