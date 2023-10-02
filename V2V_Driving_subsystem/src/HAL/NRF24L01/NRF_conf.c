/*
 * NRF_conf.c
 *
 *  Created on: Apr 13, 2023
 *      Author: Mohammed Ramadan
 */


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/GPIO/GPIO_init.h"

#include "NRF_private.h"
#include "NRF_conf.h"
#include "NRF_init.h"

NRF24_t NRF24_conf =
{
		.CE_PORT  = GPIO_PORTA ,
		.CE_PIN   = GPIO_PIN2  ,
		.CSN_PORT = GPIO_PORTA ,
		.CSN_PIN  = GPIO_PIN3
};
