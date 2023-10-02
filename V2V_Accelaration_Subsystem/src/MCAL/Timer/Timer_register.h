/*
 * Timer_register.h
 *
 *  Created on: Feb 28, 2023
 *      Author: Mohammed Ramadan
 */

#ifndef MCAL_TIMER_TIMER_REGISTER_H_
#define MCAL_TIMER_TIMER_REGISTER_H_

/****************************************************************/
/**            (Advanced-control timer)TIMER1                  **/
/****************************************************************/

/*base address of TIM1 Peripheral*/
#define TIM1_BASE_ADDRES  0x40010000

typedef struct
{
	u32 volatile CR1    ;
	u32 volatile CR2    ;
	u32 volatile SMCR   ;
	u32 volatile DIER   ;
	u32 volatile SR     ;
	u32 volatile EGR    ;
	u32 volatile CCMR1  ;
	u32 volatile CCMR2  ;
	u32 volatile CCER   ;
	u32 volatile CNT    ;
	u32 volatile PSC    ;
	u32 volatile ARR    ;
	u32 volatile RCR    ;
	u32 volatile CCR1   ;
	u32 volatile CCR2   ;
	u32 volatile CCR3   ;
	u32 volatile CCR4   ;
	u32 volatile BDTR   ;
	u32 volatile DCR    ;
	u32 volatile DMAR   ;
}TIM1_MemoryMapType;

/*define the TIM1 with its base address*/
#define TIM_1  ((volatile TIM1_MemoryMapType *)(TIM1_BASE_ADDRES))

/****************************************************************/
/**     (General-purpose timers)TIMER2 to TIMER5 register      **/
/****************************************************************/

/*base address of TIM2 Peripheral*/
#define TIM2_BASE_ADDRES  0x40000000
/*base address of TIM3 Peripheral*/
#define TIM3_BASE_ADDRES  0x40000400
/*base address of TIM4 Peripheral*/
#define TIM4_BASE_ADDRES  0x40000800
/*base address of TIM5 Peripheral*/
#define TIM5_BASE_ADDRES  0x40000C00

typedef struct
{
	u32 volatile CR1       ;
	u32 volatile CR2       ;
	u32 volatile SMCR      ;
	u32 volatile DIER      ;
	u32 volatile SR        ;
	u32 volatile EGR       ;
	u32 volatile CCMR1     ;
	u32 volatile CCMR2     ;
	u32 volatile CCER      ;
	u32 volatile CNT       ;
	u32 volatile PSC       ;
	u32 volatile ARR       ;
	u32 volatile RESERVED1 ;
	u32 volatile CCR1      ;
	u32 volatile CCR2      ;
	u32 volatile CCR3      ;
	u32 volatile CCR4      ;
	u32 volatile RESERVED2 ;
	u32 volatile DCR       ;
	u32 volatile DMAR      ;
	u32 volatile TIM2_5_OR ;
}TIM2_TO_TIM5_MemoryMapType;

/*define the TIM2 with its base address*/
#define TIM_2  ((volatile TIM2_TO_TIM5_MemoryMapType *)(TIM2_BASE_ADDRES))
/*define the TIM3 with its base address*/
#define TIM_3  ((volatile TIM2_TO_TIM5_MemoryMapType *)(TIM3_BASE_ADDRES))
/*define the TIM4 with its base address*/
#define TIM_4  ((volatile TIM2_TO_TIM5_MemoryMapType *)(TIM4_BASE_ADDRES))
/*define the TIM5 with its base address*/
#define TIM_5  ((volatile TIM2_TO_TIM5_MemoryMapType *)(TIM5_BASE_ADDRES))


#endif /* MCAL_TIMER_TIMER_REGISTER_H_ */
