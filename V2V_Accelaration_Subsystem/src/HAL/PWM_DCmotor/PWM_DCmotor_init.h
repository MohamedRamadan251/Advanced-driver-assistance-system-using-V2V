/*
 * PWM_DCmotor_init.h
 *
 *  Created on: Mar 8, 2023
 *      Author: Mohammed Ramadan
 */

#ifndef HAL_PWM_DCMOTOR_PWM_DCMOTOR_INIT_H_
#define HAL_PWM_DCMOTOR_PWM_DCMOTOR_INIT_H_

#include "PWM_DCmotor_private.h"
#include "PWM_DCmotor_conf.h"
#include "PWM_DCmotor_init.h"

void HDC_init (DCmotor_Type MotorConf) ;

void HDC_CounterClockWise  (DCmotor_Type MotorConf , u16 A_u8CaptureValue) ;

void HDC_ClockWise  (DCmotor_Type MotorConf , u16 A_u8CaptureValue) ;

void HDC_Stop  (DCmotor_Type MotorConf) ;
#endif /* HAL_PWM_DCMOTOR_PWM_DCMOTOR_INIT_H_ */
