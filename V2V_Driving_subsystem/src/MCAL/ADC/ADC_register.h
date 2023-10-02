/*
 * ADC_register.h
 *
 *  Created on: Feb 24, 2023
 *      Author: Mohammed Ramadan
 */

#ifndef MCAL_ADC_ADC_REGISTER_H_
#define MCAL_ADC_ADC_REGISTER_H_

/*define base address of ADC1*/
#define ADC1_BASE_ADDRESS  0x40012000

/*define MADC1_MemMap_t*/
typedef struct
{
	volatile u32 SR              ;
	volatile u32 CR1             ;
	volatile u32 CR2             ;
	volatile u32 SMPR1           ;
	volatile u32 SMPR2           ;
	volatile u32 JOFR1           ;
	volatile u32 JOFR2           ;
	volatile u32 JOFR3           ;
	volatile u32 JOFR4           ;
	volatile u32 HTR             ;
	volatile u32 LTR             ;
	volatile u32 SQR1            ;
	volatile u32 SQR2            ;
	volatile u32 SQR3            ;
	volatile u32 JSQR            ;
	volatile u32 JDR1            ;
	volatile u32 JDR2            ;
	volatile u32 JDR3            ;
	volatile u32 JDR4            ;
	volatile u32 DR              ;
	volatile u32 REVERSE [55]    ;/*due to offset address of CCR is relative to ADC1 base address + 0x300*/
	volatile u32 CCR             ;
}MADC1_MemMap_t;

/*define ADC1*/
#define ADC1 ((volatile MADC1_MemMap_t *)(ADC1_BASE_ADDRESS))

#endif /* MCAL_ADC_ADC_REGISTER_H_ */
