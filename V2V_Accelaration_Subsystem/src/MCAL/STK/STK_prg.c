/*
 * STK_prg.c
 *
 *  Created on: Sep 14, 2022
 *      Author: Mohammed Ramadan
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "STK_cfg.h"
#include "STK_int.h"
#include "STK_prv.h"

static void (*GS_STK_Callback)(void)= 0;
u8 G_u8IntervalType=0;
void MSTK_vInit(void){
	/* Clock Source */
	WRT_BIT(STK->CTRL,CLKSOURCE,STK_CLK_SOURCE);
	/* Interrupt Enable Or Disable*/
	WRT_BIT(STK->CTRL,TICKINT,STK_INTERRUPT_EN);
}

void MSTK_vStartTimer(u32 A_u32LoadVal){
	/* 1-reset timer value*/
	STK->VAL=0;
	/* 2-Load timer with value*/
	STK->LOAD=A_u32LoadVal;
	/* 3-Start the timer*/
	SET_BIT(STK->CTRL,ENABLE);
}

void MSTK_vStopTimer(void){
	/* Disable Timer */
	CLR_BIT(STK->CTRL,ENABLE);
	/* Clear Counting Registers */
	STK->LOAD  = 0;
	STK->VAL = 0;
	/* Disable Interrupt */
	CLR_BIT(STK->CTRL, 1);
}

void MSTK_vSetBusyWait(u32 A_u32Ticks){
	/* 1-reset timer value*/
	STK->VAL=0;
	/* 2-Load timer with value*/
	STK->LOAD=A_u32Ticks;
	/* 3-Start the timer*/
	SET_BIT(STK->CTRL,ENABLE);
	/* 4-Wait for timer flag*/
	while(READ_BIT(STK->CTRL,COUNTFLAG)!=1);
	/* 5-Close the timer*/
	CLR_BIT(STK->CTRL,ENABLE);
}

void MSTK_vSetInterval_Single(u32 A_u32Ticks,void (*CallBackFunction)(void)){
	/* 0-Set callback function*/
	GS_STK_Callback=CallBackFunction;
	G_u8IntervalType=STK_SINGLE;
	/* 1-Reset timer value*/
	STK->VAL=0;
	/* 2-Load timer with value*/
	STK->LOAD=A_u32Ticks;
	/* 3-Start the timer*/
	SET_BIT(STK->CTRL,ENABLE);
	/* Enable Exception Request */
	SET_BIT(STK->CTRL,TICKINT);
}

void MSTK_vSetInterval_Periodic(u32 A_u32Ticks,void (*CallBackFunction)(void)){
	/* 0-Set callback function*/
	GS_STK_Callback=CallBackFunction;
	G_u8IntervalType=STK_PERIODIC;
	/* 1-reset timer value*/
	STK->VAL=0;
	/* 2-Load timer with value*/
	STK->LOAD=A_u32Ticks;
	/* 3-Start the timer*/
	SET_BIT(STK->CTRL,ENABLE);
	/* Enable Exception Request */
	SET_BIT(STK->CTRL,TICKINT);
}

u32 MSTK_vGetElapsedTime(void){
	return (STK->LOAD-STK->VAL);
}

u32 MSTK_vGetRemainingTime(void){
	return STK->VAL;
}
//void SysTick_Handler(void){
//	if(GS_STK_Callback!=0){
//			GS_STK_Callback();
//	}
//	if(G_u8IntervalType==STK_SINGLE){
//		MSTK_vStopTimer();
//	}
//}

