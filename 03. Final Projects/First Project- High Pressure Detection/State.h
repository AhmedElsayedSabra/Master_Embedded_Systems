/*
 * State.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: A7MED
 */

#ifndef STATE_H_
#define STATE_H_
#include<stdio.h>
#include <stdlib.h>
#include "Platform_Type.h"
// Automatic State Function
#define STATE_Define(_StateFun_) void ST_##_StateFun_()
// Automatic Pointer to function
#define STATE(_StateFun_) ST_##_StateFun_


// Connection
void Set_Pressure_Val(int P_Val);
void High_Pressure_Detected(void);
void Start_Alarm(void);
void Stop_Alarm(void);

#endif /* STATE_H_ */
