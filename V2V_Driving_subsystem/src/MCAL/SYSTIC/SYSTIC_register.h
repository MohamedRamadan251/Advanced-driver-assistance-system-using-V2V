/*
 * SYSTIC_register.h
 *
 *  Created on: Sep 14, 2022
 *      Author: Mohammed Ramadan
 */

#ifndef MCAL_SYSTIC_SYSTIC_REGISTER_H_
#define MCAL_SYSTIC_SYSTIC_REGISTER_H_

/*define base address of SysTic*/
#define SYSTIC_BASS_ADRRESS  0xE000E010

/*registers of SysTic*/
typedef struct
{
	u32 CTRL  ;
	u32 LOAD  ;
	u32 VAL   ;
	u32 CALIB ;
}SYSTIC_MemoryMapType;

/*define SysTic*/
#define SYSTIC  ((volatile SYSTIC_MemoryMapType *)(SYSTIC_BASS_ADRRESS))

#endif /* MCAL_SYSTIC_SYSTIC_REGISTER_H_ */
