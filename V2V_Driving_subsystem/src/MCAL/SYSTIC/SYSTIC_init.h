/*
 * SYSTIC_init.h
 *
 *  Created on: Sep 14, 2022
 *      Author: Mohammed Ramadan
 */

#ifndef MCAL_SYSTIC_SYSTIC_INIT_H_
#define MCAL_SYSTIC_SYSTIC_INIT_H_

/**
	Function Name        : MSTK_voidInit
	Function Returns     : void
	Function Arguments   : void
	Function Description : initial the clock source of systick
*/
void MSTK_voidInit (void) ;

/**
	Function Name        : MSTK_voidStopTimer
	Function Returns     : void
	Function Arguments   : void
	Function Description : stop timer
*/
void MSTK_voidStopTimer (void) ;

/**
	Function Name        : MSTK_voidSetBusyWait
	Function Returns     : void
	Function Arguments   : u32 A_u32TimeInMicro
	Function Description : delay with selected time
*/
void MSTK_voidSetBusyWait (u32 A_u32TimeInMicro) ;

/**
	Function Name        : MSTK_voidSetIntervalSingle
	Function Returns     : void
	Function Arguments   : u32 A_u32TimeInMicro , void (*fptr)(void)
	Function Description : go to handler single time
*/
void MSTK_voidSetIntervalSingle (u32 A_u32TimeInMicro , void (*fptr)(void)) ;

/**
	Function Name        : MSTK_voidSetIntervalPeriodic
	Function Returns     : void
	Function Arguments   : u32 A_u32TimeInMicro , void (*fptr)(void)
	Function Description : go to handler previous time
*/
void MSTK_voidSetIntervalPeriodic (u32 A_u32TimeInMicro , void (*fptr)(void)) ;

/**
	Function Name        : MSTK_u32GetElapsedTicks
	Function Returns     : u32
	Function Arguments   : void
	Function Description : return number of elapced ticks
*/
u32  MSTK_u32GetElapsedTicks (void) ;

/**
	Function Name        : MSTK_u32GetRemaningTicks
	Function Returns     : u32
	Function Arguments   : void
	Function Description : return number of remaining ticks
*/
u32  MSTK_u32GetRemaningTicks (void) ;

#endif /*MCAL_SYSTIC_SYSTIC_INIT_H_*/
