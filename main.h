#ifndef __MAIN_H__
#define __MAIN_H__

#include "stm32f4xx.h"
#include "delay.h"
#include "chassis.h"
#include "can.h"
#include "PID.h"
#include "base.h"
#include "stdio.h"
#include "timer.h"
#include "GAIT.h"

//float FootWai(float foot,u8 mode,float i);
//float FootNei(float foot,u8 mode,float i);
void SameTimeZheng(void);
void StandUp(void);
#define MyAbs(x) ((x > 0) ? (x) : (-x))


#endif
