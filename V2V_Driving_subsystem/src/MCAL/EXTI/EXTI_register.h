/*
 * EXTI_register.h
 *
 *  Created on: Sep 11, 2022
 *      Author: Mohammed Ramadan
 */

#ifndef MCAL_EXTI_EXTI_REGISTER_H_
#define MCAL_EXTI_EXTI_REGISTER_H_

/*define base address of EXTI*/
#define EXTI_BASS_ADDRESS   0x40013C00

/*define base address of SYSCFG*/
#define SYSCFG_BASS_ADDRESS   0x40013800

/*define registers of EXTI*/
typedef struct
{
	u32 IMR   ;
	u32 EMR   ;
	u32 RTSR  ;
	u32 FTSR  ;
	u32 SWIER ;
	u32 PR    ;

}EXTI_MemortMapType;

/*define registers of SYSCFG*/
typedef struct
{
	u32 MEMRMP     ;
	u32 PMC        ;
	u32 EXTICR [4] ;
	u32 CMPCR      ;

}SYSCFG_MemortMapType;

/*define EXTI*/
#define EXTI  ((volatile EXTI_MemortMapType *)(EXTI_BASS_ADDRESS))

/*define SYSCFG*/
#define SYSCFG  ((volatile SYSCFG_MemortMapType *)(SYSCFG_BASS_ADDRESS))

#endif /* MCAL_EXTI_EXTI_REGISTER_H_ */
