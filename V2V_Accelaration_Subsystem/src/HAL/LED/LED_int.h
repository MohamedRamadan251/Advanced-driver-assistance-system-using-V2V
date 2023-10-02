/*
 * LED_int.h
 *
 *  Created on: May 18, 2022
 *      Author: Mohammed Ramadan
 */

#ifndef HAL_LED_LED_INT_H_
#define HAL_LED_LED_INT_H_

#include "LED_private.h"
#include "LED_conf.h"

/*
	Function Name        : HLED_voidLedInitial
	Function Returns     : void
	Function Arguments   : u8 A_u8LED_ID
	Function Description : Define the led as OUTPUT
*/
void HLED_voidLedInitial (u8 A_u8LED_ID) ;

/*
	Function Name        : HLED_voidLedOn
	Function Returns     : void
	Function Arguments   : u8 A_u8LED_ID
	Function Description : Turn on LED
*/
void HLED_voidLedOn (u8 A_u8LED_ID) ;

/*
	Function Name        : HLED_voidLedOff
	Function Returns     : void
	Function Arguments   : u8 A_u8LED_ID
	Function Description : Turn off LED
*/
void HLED_voidLedOff (u8 A_u8LED_ID) ;

/*
	Function Name        : HLED_voidLedToggle
	Function Returns     : void
	Function Arguments   : u8 A_u8LED_ID
	Function Description : Reverse the status of LED
*/
void HLED_voidLedToggle (u8 A_u8LED_ID) ;

#endif /* HAL_LED_LED_INT_H_ */
