/*
 * NVIC_register.h
 *
 *  Created on: Sep 10, 2022
 *      Author: Mohammed Ramadan
 */

#ifndef MCAL_NVIC_NVIC_REGISTER_H_
#define MCAL_NVIC_NVIC_REGISTER_H_

/*define base address of NVIC*/
#define NVIC_BASE_ADDRESS 0xE000E100
#define RCB_BASE_ADDRESS  0xE000ED00

/*registers of NVIC*/
typedef struct
{
	u32 ISER      [32 ] ;
	u32 ICER      [32 ] ;
	u32 ISPR      [32 ] ;
	u32 ICPR      [32 ] ;
	u32 IABR      [32 ] ;
	u32 RESERVED  [32 ] ;
    u8  IPR       [128] ;
}NVIC_MemoryMapType;

/*registers of SCB*/
typedef struct
{
	u32 CPUIDR   ;
	u32 ICSR     ;
	u32 VTOR     ;
	u32 AIRCR    ;
	u32 SCR      ;
	u32 CCR      ;
    u32 SHPR1    ;
    u32 SHPR2    ;
    u32 SHPR3    ;
    u32 SHCSR    ;
    u32 CFSR     ;
    u32 HFSR     ;
    u32 RESERVED ;
    u32 MMAR     ;
    u32 BFAR     ;
    u32 AFSR     ;
}SCBMemoryMapType;

/*define NVIC*/
#define NVIC  ((volatile NVIC_MemoryMapType *)(NVIC_BASE_ADDRESS))

/*define SCB*/
#define SCB   ((volatile SCBMemoryMapType   *)(RCB_BASE_ADDRESS))

#endif /* MCAL_NVIC_NVIC_REGISTER_H_ */
