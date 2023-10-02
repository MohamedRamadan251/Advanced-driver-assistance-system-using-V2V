/*
 * Ultrasonic_conf.c
 *
 *  Created on: Apr 13, 2023
 *      Author: Mohammed Ramadan
 */


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/GPIO/GPIO_init.h"

#include "Ultrasonic_private.h"
#include "Ultrasonic_init.h"

Ultrasonic_t Ultrasonic1_Conf =
{
		.TrigPort = GPIO_PORTA ,
		.TrigPin  = GPIO_PIN0  ,
		.EchoPort = GPIO_PORTA ,
		.EchoPin  = GPIO_PIN1
};

Ultrasonic_t Ultrasonic2_Conf =
{
		.TrigPort = GPIO_PORTA ,
		.TrigPin  = GPIO_PIN2  ,
		.EchoPort = GPIO_PORTA ,
		.EchoPin  = GPIO_PIN4
};

Ultrasonic_t Ultrasonic3_Conf =
{
		.TrigPort = GPIO_PORTA ,
		.TrigPin  = GPIO_PIN6  ,
		.EchoPort = GPIO_PORTA ,
		.EchoPin  = GPIO_PIN7
};

Ultrasonic_t Ultrasonic4_Conf =
{
		.TrigPort = GPIO_PORTB ,
		.TrigPin  = GPIO_PIN8  ,
		.EchoPort = GPIO_PORTB ,
		.EchoPin  = GPIO_PIN9
};


