/*
 * STK_int.h
 *
 *  Created on: Sep 14, 2022
 *      Author: Mohammed Ramadan
 */

#ifndef MCAL_STK_STK_INT_H_
#define MCAL_STK_STK_INT_H_


void MSTK_vInit(void);
void MSTK_vStartTimer(u32 A_u32LoadVal);
void MSTK_vStopTimer(void);

void MSTK_vSetBusyWait(u32 A_u32Ticks);

void MSTK_vSetInterval_Single(u32 A_u32Ticks,void (*CallBackFunction)(void));
void MSTK_vSetInterval_Periodic(u32 A_u32Ticks,void (*CallBackFunction)(void));

u32 MSTK_vGetElapsedTime(void);
u32 MSTK_vGetRemainingTime(void);

#endif /* MCAL_STK_STK_INT_H_ */
