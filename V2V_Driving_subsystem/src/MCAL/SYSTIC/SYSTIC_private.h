/*
 * SYSTIC_private.h
 *
 *  Created on: Sep 14, 2022
 *      Author: Mohammed Ramadan
 */

#ifndef MCAL_SYSTIC_SYSTIC_PRIVATE_H_
#define MCAL_SYSTIC_SYSTIC_PRIVATE_H_

/*SysTick control and status register (STK_CTRL)*/
#define COUNT_FLAG     16
#define CLK_SOURCE     2
#define TICK_INT       1
#define STK_ENABLE     0

/*define options of cloock source of STK*/
#define STK_AHB        1
#define STK_AHB_DIV_8  2

/*define enable or disable interrupt*/
#define ENABLE         1
#define DISABLE        2

/*Null address*/
#define NULL ((void *)0)

/*define clock source*/
#define CLOCK_IN_MHZ 16

/*maximum number of ticks (2^24) - 1*/
#define MAX_NO_OF_TICKS 16777215
#endif /* MCAL_SYSTIC_SYSTIC_PRIVATE_H_ */
