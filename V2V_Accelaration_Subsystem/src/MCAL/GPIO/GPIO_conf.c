/*
 * GPIO_conf.c
 *
 *  Created on: Sep 8, 2022
 *      Author: Mohammed Ramadan
 */




#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "GPIO_init.h"
#include "GPIO_register.h"
#include "GPIO_private.h"

MGPIO_Config_t config_output_pin_push_pull = {
				.Mode        = GPIO_MODE_OUTPUT   ,
				.OutputSpeed = GPIO_SPEED_LOW     ,
				.OutputType  = GPIO_OTYPE_PUSHPULL,
				.InputPull   = GPIO_INPUT_NO_PULL ,
		};

MGPIO_Config_t config_output_pin_open_drain = {
				.Mode        = GPIO_MODE_OUTPUT   ,
				.OutputSpeed = GPIO_SPEED_LOW     ,
				.OutputType  = GPIO_OTYPE_OPENDRAIN,
				.InputPull   = GPIO_INPUT_NO_PULL ,
		};

MGPIO_Config_t config_input_pin_no_pull = {
				.Mode        = GPIO_MODE_INPUT   ,
				.OutputSpeed = GPIO_SPEED_LOW     ,
				.OutputType  = GPIO_OTYPE_PUSHPULL,
				.InputPull   = GPIO_INPUT_NO_PULL ,
		};

MGPIO_Config_t config_input_pin_pull_up = {
				.Mode        = GPIO_MODE_INPUT   ,
				.OutputSpeed = GPIO_SPEED_LOW     ,
				.OutputType  = GPIO_OTYPE_PUSHPULL,
				.InputPull   = GPIO_INPUT_PULL_UP ,
		};

MGPIO_Config_t config_input_pin_pull_down = {
				.Mode        = GPIO_MODE_INPUT   ,
				.OutputSpeed = GPIO_SPEED_LOW     ,
				.OutputType  = GPIO_OTYPE_PUSHPULL,
				.InputPull   = GPIO_INPUT_PULL_DOWN ,
		};

MGPIO_Config_t config_input_pin_analog = {
				.Mode        = GPIO_MODE_ANALOG   ,
				.OutputSpeed = GPIO_SPEED_LOW     ,
				.OutputType  = GPIO_OTYPE_PUSHPULL,
				.InputPull   = GPIO_INPUT_PULL_DOWN ,
		};

MGPIO_Config_t config_pin_Alt_fun = {
				.Mode        = GPIO_MODE_ALTFUN   ,
				.OutputSpeed = GPIO_SPEED_LOW     ,
				.OutputType  = GPIO_OTYPE_PUSHPULL,
				.InputPull   = GPIO_INPUT_NO_PULL ,
		};
