/*
 * Ultrasonic_prog.c
 *
 *  Created on: Apr 13, 2023
 *      Author: Mohammed Ramadan
 */


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/STK/STK_int.h"
#include "../../MCAL/GPIO/GPIO_init.h"

#include "Ultrasonic_private.h"
#include "Ultrasonic_init.h"

extern MGPIO_Config_t config_output_pin_push_pull ;
extern MGPIO_Config_t config_input_pin_pull_down ;
void HUltrasonic_voidInit (Ultrasonic_t* Ultrasonic_Conf)
{
	/*initialize Trig pin from GPIO*/
	MGPIO_voidInit(&config_output_pin_push_pull ,
			        Ultrasonic_Conf->TrigPort    ,
			        Ultrasonic_Conf->TrigPin   ) ;

	/*initialize Echo pin from GPIO*/
	MGPIO_voidInit(&config_input_pin_pull_down ,
			        Ultrasonic_Conf->EchoPort    ,
			        Ultrasonic_Conf->EchoPin   ) ;

	/*initialize systick timer*/
	MSTK_vInit() ;
}

f32 HUltrasonic_f32CalcDistance (Ultrasonic_t* Ultrasonic_Conf)
{
	u32 L_u32TicksNumber = 0   ;
	f32 L_f32Distance    = 0.0 ;
	/*trig pulse to trigger pin
	 * 3us low
	 * 10us high
	 * then low
	 */
	MGPIO_voidSetPinValue (Ultrasonic_Conf->TrigPort , Ultrasonic_Conf->TrigPin , GPIO_LOW ) ;
	MSTK_vSetBusyWait(TIME_FOR_LOW_PULSE) ;
	MGPIO_voidSetPinValue (Ultrasonic_Conf->TrigPort , Ultrasonic_Conf->TrigPin , GPIO_HIGH) ;
	MSTK_vSetBusyWait(TIME_FOR_HIGH_PULSE) ;
	MGPIO_voidSetPinValue (Ultrasonic_Conf->TrigPort , Ultrasonic_Conf->TrigPin , GPIO_LOW ) ;

	/*wait for generate 8 pulses (40KHZ)*/
	MSTK_vSetBusyWait(TIME_FOR_EIGHT_PULSES) ;

	/*wait until generating rising edge for echo pin*/
	while (MGPIO_voidGetPinValue( Ultrasonic_Conf->EchoPort , Ultrasonic_Conf->EchoPin) == GPIO_LOW) ;

	while (MGPIO_voidGetPinValue( Ultrasonic_Conf->EchoPort , Ultrasonic_Conf->EchoPin) == GPIO_HIGH)
	{
		/*each iteration take 4.9 us*/
		L_u32TicksNumber ++ ;
		MSTK_vSetBusyWait(2) ;
	}
	L_f32Distance = (L_u32TicksNumber + 0.0f)*TIME_OF_EACH_ITERATION_IN_MICRO*SPEED_OF_SIGNAL_CM_PER_U ;
	L_f32Distance = L_f32Distance / 2 ;

	/*initialize L_u32TicksNumber for next read*/
	L_u32TicksNumber = 0 ;
	return L_f32Distance ;
}
