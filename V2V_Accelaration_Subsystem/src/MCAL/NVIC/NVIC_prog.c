/*
 * NVIC_prog.c
 *
 *  Created on: Sep 10, 2022
 *      Author: Mohammed Ramadan
 */



#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "NVIC_int.h"
#include "NVIC_private.h"
#include "NVIC_register.h"

u32 GS_u32GroupConf ;

void MNVIC_voidEnablePeripheral (u8 A_u8InterruptId)
{
	/*write one to ISER at spacific chosing bit to enable interrupt of this perepheral*/
	NVIC ->ISER [A_u8InterruptId / 32] = 1 << (A_u8InterruptId % 32) ;
}

void MNVIC_voidDisablePeripheral (u8 A_u8InterruptId)
{
	/*write one to ICER at spacific chosing bit to desable interrupt of this perepheral*/
	NVIC ->ICER [A_u8InterruptId / 32] = 1 << (A_u8InterruptId % 32) ;
}

void MNVIC_voidSetPendingFlag (u8 A_u8InterruptId)
{
	/*write one to ISPR at spacific chosing bit to set its pending flag*/
	NVIC ->ISPR [A_u8InterruptId / 32] = 1 << (A_u8InterruptId % 32) ;
}

void MNVIC_voidClrPendingFlag (u8 A_u8InterruptId)
{
	/*write one to ICPR at spacific chosing bit to clear its pending flag*/
	NVIC ->ICPR [A_u8InterruptId / 32] = 1 << (A_u8InterruptId % 32) ;
}

u8   MVNIC_u8GetActiveFlagStatues (u8 A_u8InterruptId)
{
	u8 L_ActiveStatues ;
	/*read active flag*/
	L_ActiveStatues = READ_BIT (NVIC ->IABR [A_u8InterruptId / 32] , (A_u8InterruptId % 32)) ;
	return L_ActiveStatues ;
}

void MNVIC_voidSetPriorityConfig(u8 A_u8PriorityOption)
{
	/*configure the number of bits for group periority and number of bits for sub periority*/
	GS_u32GroupConf = PASSWORT_TOWRITE_TO_AIRCR | (A_u8PriorityOption << 8 ) ;
	SCB ->AIRCR = GS_u32GroupConf ;
}

void MNVIC_voidSetPriority(s8 A_s8InterruptId, u8 A_u8GroupPriority, u8 A_u8SubPriority)
{
	u8 L_u8Periority ;
	/*configure software periority of Group Priority and Sub Priority*/
	L_u8Periority = A_u8SubPriority | (A_u8GroupPriority << ((GS_u32GroupConf - BASE_ADDRESS_OF_GROUP_PERIORITY) >> 8)) ;
	/*interrupts of core peripheral*/
	if (A_s8InterruptId < 0)
	{
		if (A_s8InterruptId == MEMORY_MANAGE ||
			A_s8InterruptId == BUS_FAULT     ||
			A_s8InterruptId == USAGE_FAULT
		   )
		{
			A_s8InterruptId += 3;
			SCB->SHPR1 &= ~((0b1111)        << ((8 * A_s8InterruptId) + 4));
			SCB->SHPR1 |=  ((L_u8Periority) << ((8 * A_s8InterruptId) + 4));
		}
		else if (A_s8InterruptId == SV_CALL)
		{
			A_s8InterruptId += 7;
			SCB->SHPR2 &= ~((0b1111)        << ((8 * A_s8InterruptId) + 4));
			SCB->SHPR2 |=  ((L_u8Periority) << ((8 * A_s8InterruptId) + 4));
		}
		else if (A_s8InterruptId == PEND_SV || A_s8InterruptId == SYSTICK)
		{
			A_s8InterruptId += 8;
			SCB->SHPR3 &= ~((0b1111)        << ((8 * A_s8InterruptId) + 4));
			SCB->SHPR3 |=  ((L_u8Periority) << ((8 * A_s8InterruptId) + 4));
		}
	}
	/*interrupts of vendor peripheral*/
	else if (A_s8InterruptId >= 0)
	{
		NVIC -> IPR [A_s8InterruptId] = L_u8Periority << 4 ;
	}
}

