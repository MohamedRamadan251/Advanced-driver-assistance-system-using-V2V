/*
 * SYSTIC_prog.c
 *
 *  Created on: Sep 14, 2022
 *      Author: Mohammed Ramadan
 */



#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "SYSTIC_init.h"
#include "SYSTIC_register.h"
#include "SYSTIC_private.h"
#include "SYSTIC_conf.h"

/*pointer to fonction to set call back of sys tick*/
static void (*G_u32SysTickSetCallBack)(void) ;

/*flag to differ from single interval and periodic interval*/
static u8 GS_u8SingleFlag = 0;

/*store number of over flows from 2^24 to 0*/
static u32 GS_u32FullOverFlowCounts ;

/*store again number of over flows from 2^24 to 0*/
static u32 GS_u32ResumeFullOverFlowCounts ;

/*store number of counts from value to 0*/
static u32 GS_u32PartOverFlowCounts ;

void MSTK_voidInit (void)
{
	/*clock source*/
    #if   STK_CLOCK_SOURCE == STK_AHB
	      SET_BIT (SYSTIC -> CTRL , CLK_SOURCE) ;

    #elif STK_CLOCK_SOURCE == STK_AHB_DIV_8
	      CLR_BIT (SYSTIC -> CTRL , CLK_SOURCE) ;

    #else
          #error "select correct option of STK_CLOCK_SOURCE"
    #endif

	/*interrupt enable or disable*/
    #if   STK_INTERRUPT_EN == ENABLE
          SET_BIT (SYSTIC -> CTRL , TICK_INT) ;

    #elif STK_INTERRUPT_EN == DISABLE
          CLR_BIT (SYSTIC -> CTRL , TICK_INT) ;

    #else
          #error "select correct option of STK_INTERRUPT_EN"
    #endif
}

void MSTK_voidStopTimer (void)
{
	/*stop the timer*/
	CLR_BIT (SYSTIC -> CTRL , STK_ENABLE) ;
}

void MSTK_voidSetBusyWait (u32 A_u32TimeInMicro)
{
    #if   STK_CLOCK_SOURCE == STK_AHB_DIV_8
	      f32 L_f32TickTimeInMicro = 1.0 / (CLOCK_IN_MHZ / 8.0);

    #elif STK_CLOCK_SOURCE == STK_AHB
	      f32 L_f32TickTimeInMicro = 1.0 / CLOCK_IN_MHZ;
    #endif

	u32 L_u32NoOfTicks = A_u32TimeInMicro / L_f32TickTimeInMicro ;

	if (L_u32NoOfTicks <= MAX_NO_OF_TICKS)
	{
		/*reset timer value*/
		SYSTIC -> VAL = 0 ;

		/*load timer with value*/
		SYSTIC -> LOAD = L_u32NoOfTicks ;

		/*start the timer*/
		SET_BIT (SYSTIC -> CTRL , STK_ENABLE) ;

		/*wait for the timer flag to be rasied*/
		while (READ_BIT (SYSTIC -> CTRL , COUNT_FLAG) != 1) ;

		/*stop the timer*/
		CLR_BIT (SYSTIC -> CTRL , STK_ENABLE) ;
	}
	else
	{
		while (L_u32NoOfTicks > 0)
		{
			if (L_u32NoOfTicks > MAX_NO_OF_TICKS)
			{
				L_u32NoOfTicks -= MAX_NO_OF_TICKS ;

				/*reset timer value*/
				SYSTIC -> VAL = 0 ;

				/*load timer with value*/
				SYSTIC -> LOAD = MAX_NO_OF_TICKS ;

				/*start the timer*/
				SET_BIT (SYSTIC -> CTRL , STK_ENABLE) ;

				/*wait for the timer flag to be rasied*/
				while (READ_BIT (SYSTIC -> CTRL , COUNT_FLAG) != 1) ;

				/*stop the timer*/
				CLR_BIT (SYSTIC -> CTRL , STK_ENABLE) ;
			}
			else
			{
				/*reset timer value*/
				SYSTIC -> VAL = 0 ;

				/*load timer with value*/
				SYSTIC -> LOAD = MAX_NO_OF_TICKS ;

				/*start the timer*/
				SET_BIT (SYSTIC -> CTRL , STK_ENABLE) ;

				/*wait for the timer flag to be rasied*/
				while (READ_BIT (SYSTIC -> CTRL , COUNT_FLAG) != 1) ;

				/*stop the timer*/
				CLR_BIT (SYSTIC -> CTRL , STK_ENABLE) ;
			}
		}
	}
}

void MSTK_voidSetIntervalSingle (u32 A_u32TimeInMicro , void (*fptr)(void))
{
	/*set call back*/
	G_u32SysTickSetCallBack = fptr ;

	/*set single flag for single interval*/
	GS_u8SingleFlag = 1 ;

    #if   STK_CLOCK_SOURCE == STK_AHB_DIV_8
	      f32 L_f32TickTimeInMicro = 1.0 / (CLOCK_IN_MHZ / 8.0);

    #elif STK_CLOCK_SOURCE == STK_AHB
	      f32 L_f32TickTimeInMicro = 1.0 / CLOCK_IN_MHZ;
    #endif

	u32 L_u32NoOfTicks = A_u32TimeInMicro / L_f32TickTimeInMicro ;

	GS_u32FullOverFlowCounts       = ( L_u32NoOfTicks / MAX_NO_OF_TICKS ) + 1;
	GS_u32PartOverFlowCounts       = L_u32NoOfTicks % MAX_NO_OF_TICKS ;
	GS_u32ResumeFullOverFlowCounts = GS_u32FullOverFlowCounts ;

	/*reset timer value*/
	SYSTIC -> VAL = 0 ;
	/*load timer with value*/
	if (GS_u32FullOverFlowCounts > 1)
	{
		SYSTIC -> LOAD = MAX_NO_OF_TICKS ;
	}
	else
	{
		GS_u32FullOverFlowCounts = 0 ;
		SYSTIC -> LOAD = L_u32NoOfTicks ;
	}
	/*start the timer*/
	SET_BIT (SYSTIC -> CTRL , STK_ENABLE) ;
}

void MSTK_voidSetIntervalPeriodic (u32 A_u32TimeInMicro , void (*fptr)(void))
{
	/*set call back*/
	G_u32SysTickSetCallBack = fptr ;

	/*clear single flag for periodic interval*/
	GS_u8SingleFlag = 0 ;

    #if   STK_CLOCK_SOURCE == STK_AHB_DIV_8
	      f32 L_f32TickTimeInMicro = 1.0 / (CLOCK_IN_MHZ / 8.0);

    #elif STK_CLOCK_SOURCE == STK_AHB
	      f32 L_f32TickTimeInMicro = 1.0 / CLOCK_IN_MHZ;
    #endif

	u32 L_u32NoOfTicks = A_u32TimeInMicro / L_f32TickTimeInMicro ;

	GS_u32FullOverFlowCounts       = ( L_u32NoOfTicks / MAX_NO_OF_TICKS ) + 1;
	GS_u32PartOverFlowCounts       = L_u32NoOfTicks % MAX_NO_OF_TICKS ;
	GS_u32ResumeFullOverFlowCounts = GS_u32FullOverFlowCounts ;

	/*reset timer value*/
	SYSTIC -> VAL = 0 ;
	/*load timer with value*/
	if (GS_u32FullOverFlowCounts > 1)
	{
		SYSTIC -> LOAD = MAX_NO_OF_TICKS ;
	}
	else
	{
		GS_u32FullOverFlowCounts = 0 ;
		SYSTIC -> LOAD = L_u32NoOfTicks ;
	}
	/*start the timer*/
	SET_BIT (SYSTIC -> CTRL , STK_ENABLE) ;
}

u32  MSTK_u32GetElapsedTime (void)
{
	/*return differance between load register and value register*/
	return ((SYSTIC -> LOAD) - (SYSTIC -> VAL)) ;
}

u32  MSTK_u32GetRemaningTime (void)
{
	/*return value register*/
	return (SYSTIC -> VAL) ;
}

/*IRQ Handler of Sys tick*/
void SysTick_Handler (void)
{
	if (GS_u32FullOverFlowCounts > 1)
	{
		GS_u32FullOverFlowCounts -- ;
	}
	else if (GS_u32FullOverFlowCounts > 0 )
	{
		GS_u32FullOverFlowCounts -- ;
		/*reset timer value*/
		SYSTIC -> VAL = 0 ;
		/*load timer with value*/
		SYSTIC -> LOAD = GS_u32PartOverFlowCounts ;
		/*start the timer*/
		SET_BIT (SYSTIC -> CTRL , STK_ENABLE) ;
	}
	else
	{
		if (G_u32SysTickSetCallBack != NULL)
		{
			GS_u32FullOverFlowCounts = GS_u32ResumeFullOverFlowCounts ;
			G_u32SysTickSetCallBack () ;
		}

		/*check for interrupt occures from single interval or periodic interval*/
		if (GS_u8SingleFlag)
		{
			/*clear flag*/
			GS_u8SingleFlag = 0 ;

			/*stop the timer*/
			CLR_BIT (SYSTIC -> CTRL , STK_ENABLE) ;
		}
	}
}
