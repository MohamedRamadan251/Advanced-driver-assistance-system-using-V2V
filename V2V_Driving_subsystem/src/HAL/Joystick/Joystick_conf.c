/*
 * Joystick_conf.c
 *
 *  Created on: Apr 8, 2023
 *      Author: Mohammed Ramadan
 */


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/GPIO/GPIO_init.h"
#include "../../MCAL/EXTI/EXTI_init.h"
#include "../../MCAL/ADC/ADC_init.h"

#include "Joystick_private.h"
#include "Joystick_conf.h"
#include "Joystick_init.h"

JoyStick_t JoystickConf =
{
		.ChannelX    = ADC_CHANNEL_0 ,
		.ChannelY    = ADC_CHANNEL_1 ,
		.SwitchZPort = GPIO_PORTB    ,
		.SwitchZLine = EXTI_LINE_5
};
