/*
 * PWM_DCmotor_conf.c
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


DCmotor_Type M1 =
{
		.FirstTimerType      = TIM2_TYPE     ,
		.SecondTimerType     = TIM2_TYPE     ,
		.FirstChannelNumber  = TIM_CHANNEL_1 ,
		.SecondChannelNumber = TIM_CHANNEL_2
};

DCmotor_Type M2 =
{
		.FirstTimerType      = TIM2_TYPE     ,
		.SecondTimerType     = TIM2_TYPE     ,
		.FirstChannelNumber  = TIM_CHANNEL_3 ,
		.SecondChannelNumber = TIM_CHANNEL_4
};

DCmotor_Type M3 =
{
		.FirstTimerType      = TIM3_TYPE     ,
		.SecondTimerType     = TIM3_TYPE     ,
		.FirstChannelNumber  = TIM_CHANNEL_1 ,
		.SecondChannelNumber = TIM_CHANNEL_2
};

DCmotor_Type M4 =
{
		.FirstTimerType      = TIM3_TYPE     ,
		.SecondTimerType     = TIM3_TYPE     ,
		.FirstChannelNumber  = TIM_CHANNEL_3 ,
		.SecondChannelNumber = TIM_CHANNEL_4
};
