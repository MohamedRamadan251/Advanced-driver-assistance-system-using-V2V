/*
 * Joystick_prog.c
 *
 *  Created on: Apr 8, 2023
 *      Author: Mohammed Ramadan
 */


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/GPIO/GPIO_init.h"
#include "../../MCAL/EXTI/EXTI_init.h"
#include "../../MCAL/ADC/ADC_init.h"
#include "../../MCAL/SYSTIC/SYSTIC_init.h"

#include "Joystick_private.h"
#include "Joystick_conf.h"
#include "Joystick_init.h"

X_Y_Zposition L_xPosition ;
void CountingZ (void)
{
	L_xPosition.Z ++ ;
	if (L_xPosition.Z == 12)
	{
		L_xPosition.Z = 0 ;
	}
	MSTK_voidSetBusyWait(300) ;
}

void HJoystick_voidInit (JoyStick_t *JoystickConf)
{
	/*initialize systic timer*/
	MSTK_voidInit() ;

	/*initialize exterbal interrupt with selected port and line*/
	MEXTI_voidInit(JoystickConf->SwitchZPort , JoystickConf->SwitchZLine , GPIO_INPUT_PULL_UP) ;

	/*Enable selected line with rising edge*/
	MEXTI_voidEnableLine(EXTI_RISING , JoystickConf->SwitchZLine) ;

	MEXTI_voidSetCallBack(JoystickConf->SwitchZLine , CountingZ) ;
	/*initialze ADC*/
	MADC_voidInit() ;

	/*configuaration channel x & y with selected sample time*/
	MADC_voidConfigChannel(JoystickConf->ChannelX , SAMPLE_TIME) ;
	MADC_voidConfigChannel(JoystickConf->ChannelY , SAMPLE_TIME) ;
}

X_Y_Zposition HJoystick_xMappedXandY (JoyStick_t *JoystickConf)
{
	L_xPosition.X = MADC_u32PollingToGetValue(JoystickConf->ChannelX) ;
	L_xPosition.Y = MADC_u32PollingToGetValue(JoystickConf->ChannelY) ;
	if (L_xPosition.X <= 3230)/*mapped x reading for zero position to center*/
	{
		/*
		 ************************************
		 0 -----------------> 3230  (range from zero position to center)
		 0 -----------------> 90    (angle from zero position to center)
		 to mapping values: divide the output by 35.8 ---> (3230/90)
		 ************************************
		*/
		L_xPosition.X = L_xPosition.X / 35.8 ;
	}
	else/*mapped x reading from center position to end*/
	{
		/*
		 ************************************
		 3230 -----------------> 4095  (range from center position to end)
		 91 -----------------> 180    (angle from zero position to center)
		 to mapping values: divide the output by 9.6 ---> ((4095 - 3230 + 1)/(180 - 91 + 1))
		 ************************************
		*/
		L_xPosition.X = L_xPosition.X - 3230 ;
		L_xPosition.X = (L_xPosition.X / 9.6) + 90 ;
	}
	if (L_xPosition.Y <= 3230)/*mapped y reading for zero position to center*/
	{
		/*
		 ************************************
		 0 -----------------> 3230  (range from zero position to center)
		 0 -----------------> 90    (angle from zero position to center)
		 to mapping values: divide the output by 35.8 ---> (3230/90)
		 ************************************
		 */
		L_xPosition.Y = L_xPosition.Y / 35.8 ;
	}
	else/*mapped y reading for center position to end*/
	{
		/*
		 ************************************
		 3230 -----------------> 4095  (range from center position to end)
		 91 -----------------> 180    (angle from zero position to center)
		 to mapping values: divide the output by 9.6 ---> ((4095 - 3230 + 1)/(180 - 91 + 1))
		 ************************************
		*/
		L_xPosition.Y = L_xPosition.Y - 3230 ;
		L_xPosition.Y = (L_xPosition.Y / 9.6) + 90 ;
	}
	return L_xPosition ;
}

