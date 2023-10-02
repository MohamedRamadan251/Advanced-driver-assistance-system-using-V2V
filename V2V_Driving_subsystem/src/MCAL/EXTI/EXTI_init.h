/*
 * EXTI_init.h
 *
 *  Created on: Sep 11, 2022
 *      Author: Mohammed Ramadan
 */

#ifndef MCAL_EXTI_EXTI_INIT_H_
#define MCAL_EXTI_EXTI_INIT_H_

/*defines lines of EXTI*/
#define EXTI_LINE_0    0
#define EXTI_LINE_1    1
#define EXTI_LINE_2    2
#define EXTI_LINE_3    3
#define EXTI_LINE_4    4
#define EXTI_LINE_5    5
#define EXTI_LINE_6    6
#define EXTI_LINE_7    7
#define EXTI_LINE_8    8
#define EXTI_LINE_9    9
#define EXTI_LINE_10   10
#define EXTI_LINE_11   11
#define EXTI_LINE_12   12
#define EXTI_LINE_13   13
#define EXTI_LINE_14   14
#define EXTI_LINE_15   15

/*define triggering*/
#define EXTI_RISING   1
#define EXTI_FALING   2
#define ON_CHANGE     3

/*
	Function Name        : MEXTI_voidInit
	Function Returns     : void
	Function Arguments   : u8 A_u8PortId , u8 A_u8LineNum , u8 A_u8InputPull
	Function Description : initialize RCC , GPIO , EXTI
*/
void MEXTI_voidInit (u8 A_u8PortId , u8 A_u8LineNum , u8 A_u8InputPull) ;

/*
	Function Name        : MEXTI_voidEnableLine
	Function Returns     : void
	Function Arguments   : u8 A_u8Trigger , u8 A_u8LineNum
	Function Description : enable line with selected trigger
*/
void MEXTI_voidEnableLine (u8 A_u8Trigger , u8 A_u8LineNum) ;

/*
	Function Name        : MEXTI_voidDisableLine
	Function Returns     : void
	Function Arguments   : u8 A_u8LineNum
	Function Description : disable line
*/
void MEXTI_voidDisableLine (u8 A_u8LineNum) ;

/*
	Function Name        : MEXTI_voidSoftWareTrigger
	Function Returns     : void
	Function Arguments   : u8 A_u8LineNum
	Function Description : enable sofrt ware trigger for testing
*/
void MEXTI_voidSoftWareTrigger (u8 A_u8LineNum) ;

/*
	Function Name        : MEXTI_voidSetTrigger
	Function Returns     : void
	Function Arguments   : u8 A_u8Trigger , u8 A_u8LineNum
	Function Description : selected trigger
*/
void MEXTI_voidSetTrigger (u8 A_u8Trigger , u8 A_u8LineNum) ;

/*
	Function Name        : MSYSCFG_voidExtiPort
	Function Returns     : void
	Function Arguments   : u8 A_u8LineNum , u8 A_u8PortNum
	Function Description : select port of EXTI
*/
void MSYSCFG_voidExtiPort (u8 A_u8LineNum , u8 A_u8PortNum) ;

/*
	Function Name        : MEXTI_voidSetCallBack
	Function Returns     : void
	Function Arguments   : u8 A_u8LineNum , void (*A_fptr)(void)
	Function Description : set call back function of EXTI of selected line
*/
void MEXTI_voidSetCallBack (u8 A_u8LineNum , void (*A_fptr)(void)) ;

#endif /* MCAL_EXTI_EXTI_INIT_H_ */
