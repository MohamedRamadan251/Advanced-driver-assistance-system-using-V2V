/*
 * Timer_init.h
 *
 *  Created on: Feb 28, 2023
 *      Author: Mohammed Ramadan
 */

#ifndef MCAL_TIMER_TIMER_INIT_H_
#define MCAL_TIMER_TIMER_INIT_H_

/*
 * define A_u8TimerSelected
 */
#define TIM1_TYPE     1
#define TIM2_TYPE     2
#define TIM3_TYPE     3
#define TIM4_TYPE     4
#define TIM5_TYPE     5

/*
 * define A_u8Channel
 *
 * note that for TIM1 to TIM5 there are 4 channels
 */
#define TIM_CHANNEL_1  1
#define TIM_CHANNEL_2  2
#define TIM_CHANNEL_3  3
#define TIM_CHANNEL_4  4


void MTimer_voidInit (u8 A_u8TimerSelected) ;

void MTimer_voidPWM (u8 A_u8TimerSelected , u8 A_u8Channel , u16 A_u16CompareValue) ;
#endif /* MCAL_TIMER_TIMER_INIT_H_ */


