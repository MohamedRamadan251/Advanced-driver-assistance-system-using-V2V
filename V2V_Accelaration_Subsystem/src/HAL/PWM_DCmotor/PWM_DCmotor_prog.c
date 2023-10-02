/*
 * PWM_DCmotor_prog.c
 *
 *  Created on: Mar 8, 2023
 *      Author: Mohammed Ramadan
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/Timer/Timer_init.h"

#include "PWM_DCmotor_private.h"
#include "PWM_DCmotor_conf.h"
#include "PWM_DCmotor_init.h"


void HDC_init (DCmotor_Type MotorConf)
{
	MTimer_voidInit(MotorConf.FirstTimerType) ;
	if (MotorConf.FirstTimerType != MotorConf.SecondTimerType)
	{
		MTimer_voidInit(MotorConf.SecondTimerType) ;
	}
}

void HDC_CounterClockWise  (DCmotor_Type MotorConf , u16 A_u16CaptureValue )
{
	MTimer_voidPWM(MotorConf.FirstTimerType     ,
			       MotorConf.FirstChannelNumber ,
				   A_u16CaptureValue
				   )                     ;

	MTimer_voidPWM(MotorConf.SecondTimerType     ,
                   MotorConf.SecondChannelNumber ,
				   0
				   )                      ;
}

void HDC_ClockWise  (DCmotor_Type MotorConf , u16 A_u16CaptureValue)
{
	MTimer_voidPWM(MotorConf.FirstTimerType     ,
				   MotorConf.FirstChannelNumber ,
				   0
				   )                     ;

	MTimer_voidPWM(MotorConf.SecondTimerType     ,
	               MotorConf.SecondChannelNumber ,
				   A_u16CaptureValue
				   )                      ;
}

void HDC_Stop  (DCmotor_Type MotorConf)
{
	MTimer_voidPWM(MotorConf.FirstTimerType     ,
				   MotorConf.FirstChannelNumber ,
				   0
				   )                     ;

	MTimer_voidPWM(MotorConf.SecondTimerType     ,
	               MotorConf.SecondChannelNumber ,
				   0
				   )                      ;
}
