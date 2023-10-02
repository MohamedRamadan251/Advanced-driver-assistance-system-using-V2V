/*
 * TFT_conf.c
 *
 *  Created on: Sep 30, 2022
 *      Author: Mohammed Ramadan
 */



#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/GPIO/GPIO_init.h"

#include "TFT_conf.h"

HTFT_Config_t config_TFT_pins = {
    .RESET_PORT  = GPIO_PORTA ,
	.RESET_PIN   = GPIO_PIN8  ,
	.A0_PORT     = GPIO_PORTA ,
	.A0_PIN      = GPIO_PIN9
};
