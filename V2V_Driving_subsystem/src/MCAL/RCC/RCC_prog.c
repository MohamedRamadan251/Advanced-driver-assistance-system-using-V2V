/*
 * RCC_prog.c
 *
 *  Created on: Sep 2, 2022
 *      Author: Mohammed Ramadan
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "RCC_int.h"
#include "RCC_register.h"
#include "RCC_private.h"
#include "RCC_conf.h"

void MRCC_voidInit (void)
{
   /*select CSS on or off*/
   #if   RCC_CSS_ENABLE == ENABLE
         SET_BIT (RCC->CR , CSSON) ;
   #elif RCC_CSS_ENABLE == DISABLE
         CLR_BIT (RCC->CR , CSSON) ;
   #else
         #error "wrong configuration for CSS"
   #endif

   /*disable bypass for HSE */
   CLR_BIT (RCC->CR , HSEBYP) ;

   /*select clock switch (HSI/HSE/PLL) */
   #if   SYSTEM_CLOCK == HSI
         CLR_BIT (RCC->CFGR , SW0) ;
         CLR_BIT (RCC->CFGR , SW1) ;
   #elif SYSTEM_CLOCK == HSE
         SET_BIT (RCC->CFGR , SW0) ;
         CLR_BIT (RCC->CFGR , SW1) ;
   #elif SYSTEM_CLOCK == PLL
         CLR_BIT (RCC->CFGR , SW0) ;
         SET_BIT (RCC->CFGR , SW1) ;
   #else
         #error "select correct choice for SYSTEM_CLOCK"
   #endif

   /*AHB Bus prescalers   */
   #if   AHB_PRESCALER == NOT_DIVISION
         CLR_BIT (RCC->CFGR , HPRE_0) ;
         CLR_BIT (RCC->CFGR , HPRE_1) ;
         CLR_BIT (RCC->CFGR , HPRE_2) ;
         CLR_BIT (RCC->CFGR , HPRE_3) ;
   #elif AHB_PRESCALER == DIVISION_2
         CLR_BIT (RCC->CFGR , HPRE_0) ;
         CLR_BIT (RCC->CFGR , HPRE_1) ;
         CLR_BIT (RCC->CFGR , HPRE_2) ;
         SET_BIT (RCC->CFGR , HPRE_3) ;
   #elif AHB_PRESCALER == DIVISION_4
         SET_BIT (RCC->CFGR , HPRE_0) ;
         CLR_BIT (RCC->CFGR , HPRE_1) ;
         CLR_BIT (RCC->CFGR , HPRE_2) ;
         SET_BIT (RCC->CFGR , HPRE_3) ;
   #elif AHB_PRESCALER == DIVISION_8
         CLR_BIT (RCC->CFGR , HPRE_0) ;
         SET_BIT (RCC->CFGR , HPRE_1) ;
         CLR_BIT (RCC->CFGR , HPRE_2) ;
         SET_BIT (RCC->CFGR , HPRE_3) ;
   #elif AHB_PRESCALER == DIVISION_16
         SET_BIT (RCC->CFGR , HPRE_0) ;
         SET_BIT (RCC->CFGR , HPRE_1) ;
         CLR_BIT (RCC->CFGR , HPRE_2) ;
         SET_BIT (RCC->CFGR , HPRE_3) ;
   #elif AHB_PRESCALER == DIVISION_64
         CLR_BIT (RCC->CFGR , HPRE_0) ;
         CLR_BIT (RCC->CFGR , HPRE_1) ;
         SET_BIT (RCC->CFGR , HPRE_2) ;
         SET_BIT (RCC->CFGR , HPRE_3) ;
   #elif AHB_PRESCALER == DIVISION_128
         SET_BIT (RCC->CFGR , HPRE_0) ;
         CLR_BIT (RCC->CFGR , HPRE_1) ;
         SET_BIT (RCC->CFGR , HPRE_2) ;
         SET_BIT (RCC->CFGR , HPRE_3) ;
   #elif AHB_PRESCALER == DIVISION_256
         CLR_BIT (RCC->CFGR , HPRE_0) ;
         SET_BIT (RCC->CFGR , HPRE_1) ;
         SET_BIT (RCC->CFGR , HPRE_2) ;
         SET_BIT (RCC->CFGR , HPRE_3) ;
   #elif AHB_PRESCALER == DIVISION_512
         SET_BIT (RCC->CFGR , HPRE_0) ;
         SET_BIT (RCC->CFGR , HPRE_1) ;
         SET_BIT (RCC->CFGR , HPRE_2) ;
         SET_BIT (RCC->CFGR , HPRE_3) ;
   #else
         #error "select correct choice for AHB_PRESCALER"
   #endif

   /*APB1 Bus prescalers   */
   #if   APB1_PRESCALER == NOT_DIVISION
         CLR_BIT (RCC->CFGR , PPRE1_0) ;
         CLR_BIT (RCC->CFGR , PPRE1_1) ;
         CLR_BIT (RCC->CFGR , PPRE1_2) ;
   #elif APB1_PRESCALER == DIVISION_2
         CLR_BIT (RCC->CFGR , PPRE1_0) ;
         CLR_BIT (RCC->CFGR , PPRE1_1) ;
         SET_BIT (RCC->CFGR , PPRE1_2) ;
   #elif APB1_PRESCALER == DIVISION_4
         SET_BIT (RCC->CFGR , PPRE1_0) ;
         CLR_BIT (RCC->CFGR , PPRE1_1) ;
         CLR_BIT (RCC->CFGR , PPRE1_2) ;
   #elif APB1_PRESCALER == DIVISION_8
         CLR_BIT (RCC->CFGR , PPRE1_0) ;
         SET_BIT (RCC->CFGR , PPRE1_1) ;
         CLR_BIT (RCC->CFGR , PPRE1_2) ;
   #elif APB1_PRESCALER == DIVISION_16
         SET_BIT (RCC->CFGR , PPRE1_0) ;
         SET_BIT (RCC->CFGR , PPRE1_1) ;
         CLR_BIT (RCC->CFGR , PPRE1_2) ;
   #else
         #error "select correct choice for APB1_PRESCALER"
   #endif

   /*APB2 Bus prescalers   */
   #if   APB2_PRESCALER == NOT_DIVISION
         CLR_BIT (RCC->CFGR , PPRE2_0) ;
         CLR_BIT (RCC->CFGR , PPRE2_1) ;
         CLR_BIT (RCC->CFGR , PPRE2_2) ;
   #elif APB2_PRESCALER == DIVISION_2
         CLR_BIT (RCC->CFGR , PPRE2_0) ;
         CLR_BIT (RCC->CFGR , PPRE2_1) ;
         SET_BIT (RCC->CFGR , PPRE2_2) ;
   #elif APB2_PRESCALER == DIVISION_4
         SET_BIT (RCC->CFGR , PPRE2_0) ;
         CLR_BIT (RCC->CFGR , PPRE2_1) ;
         CLR_BIT (RCC->CFGR , PPRE2_2) ;
   #elif APB2_PRESCALER == DIVISION_8
         CLR_BIT (RCC->CFGR , PPRE2_0) ;
         SET_BIT (RCC->CFGR , PPRE2_1) ;
         CLR_BIT (RCC->CFGR , PPRE2_2) ;
   #elif APB2_PRESCALER == DIVISION_16
         SET_BIT (RCC->CFGR , PPRE2_0) ;
         SET_BIT (RCC->CFGR , PPRE2_1) ;
         CLR_BIT (RCC->CFGR , PPRE2_2) ;
   #else
         #error "select correct choice for APB1_PRESCALER"
   #endif

   /*PLL configurations*/
   #if PLLM >= 2 && PLLM <= 63    && \
	   PLLN >= 192 && PLLN <= 432 && \
	   ( PLLP == 2 || PLLP == 4 || PLLP == 6 || PLLP == 8)

       #define  F_PLL  (((F_SYSTEM * PLLN) / PLLM) / PLLP)
       #if F_PLL > 84000000UL
           #error "wrong configration of F_PLL (the frequancy must be <= 84 MHZ)"
       #else
         (RCC -> PLLCFGR) = ((PLLM) | (PLLN << 6) | (PLLP << 16)) ;
       #endif

   #else
         #error "PLLM or PLLN or PLLP out of range"
   #endif

   /*select input clock of pll */
   #if   PLL_INPUT == HSI
         CLR_BIT (RCC->PLLCFGR , PLLSRC) ;
   #elif PLL_INPUT == HSE
         SET_BIT (RCC->PLLCFGR , PLLSRC) ;
   #else
         #error "select correct choice of PLL_INPUT"
   #endif

   /*Enable the selected clock (HSE ON)*/
   #if RCC_HSE_ENABLE == ENABLE
       SET_BIT(RCC->CR, HSEON);
   #endif
   /*Enable the selected clock (HSI ON)*/
   #if RCC_HSI_ENABLE == ENABLE
       SET_BIT(RCC->CR, HSION);
   #endif
   /*Enable the selected clock (PLL ON)*/
   #if RCC_PLL_ENABLE == ENABLE
       SET_BIT(RCC->CR, PLLON);
   #endif
}

void MRCC_voidEnablePerephiralClock (u32 A_u32BusId, u32 A_u32PeripheralId)
{
	if (A_u32PeripheralId <= 31)
	{
	    switch (A_u32BusId)
	    {
	    case RCC_AHB1 :
	    	SET_BIT (RCC->AHB1ENR , A_u32PeripheralId) ;
	    	break ;
	    case RCC_AHB2:
	    	SET_BIT (RCC->AHB2ENR , A_u32PeripheralId) ;
	    	break ;
	    case RCC_APB1:
	    	SET_BIT (RCC->APB1ENR , A_u32PeripheralId) ;
	    	break ;
	    case RCC_APB2:
	    	SET_BIT (RCC->APB2ENR , A_u32PeripheralId) ;
	    	break ;
	    default :
	    	/* Error: Bus ID out of range */
	    	break ;
	    }
	}
}

void MRCC_voidDisablePerephiralClock (u32 A_u32BusId, u32 A_u32PeripheralId)
{
	if (A_u32PeripheralId <= 31)
	{
	    switch (A_u32BusId)
        {
        case RCC_AHB1 :
        	CLR_BIT (RCC->AHB1ENR , A_u32PeripheralId) ;
        	break ;
        case RCC_AHB2:
        	CLR_BIT (RCC->AHB2ENR , A_u32PeripheralId) ;
        	break ;
        case RCC_APB1:
        	CLR_BIT (RCC->APB1ENR , A_u32PeripheralId) ;
        	break ;
        case RCC_APB2:
        	CLR_BIT (RCC->APB2ENR , A_u32PeripheralId) ;
        	break ;
        default :
        	/* Error: Bus ID out of range */
        	break ;
        }
	}
}
