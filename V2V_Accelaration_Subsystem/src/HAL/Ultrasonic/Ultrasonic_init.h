/*
 * Ultrasonic_init.h
 *
 *  Created on: Apr 13, 2023
 *      Author: Mohammed Ramadan
 */

#ifndef HAL_ULTRASONIC_ULTRASONIC_INIT_H_
#define HAL_ULTRASONIC_ULTRASONIC_INIT_H_

typedef struct
{
	u8 TrigPort ;
	u8 TrigPin  ;
	u8 EchoPort ;
	u8 EchoPin  ;
}Ultrasonic_t;
void HUltrasonic_voidInit (Ultrasonic_t* Ultrasonic_Conf) ;

f32 HUltrasonic_f32CalcDistance (Ultrasonic_t* Ultrasonic_Conf) ;

#endif /* HAL_ULTRASONIC_ULTRASONIC_INIT_H_ */
