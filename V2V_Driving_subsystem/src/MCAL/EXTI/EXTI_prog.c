/*
 * EXTI_prog.c
 *
 *  Created on: Sep 11, 2022
 *      Author: Mohammed Ramadan
 */


#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../RCC/RCC_int.h"
#include "../NVIC/NVIC_int.h"
#include "../GPIO/GPIO_init.h"

#include "EXTI_init.h"
#include "EXTI_private.h"
#include "EXTI_register.h"
#include "EXTI_conf.h"

/*pointer to function to set call back of EXTI0*/
static void (*EXTI_LINE_0_CallBack) (void) ;

/*pointer to function to set call back of EXTI1*/
static void (*EXTI_LINE_1_CallBack) (void) ;

/*pointer to function to set call back of EXTI2*/
static void (*EXTI_LINE_2_CallBack) (void) ;

/*pointer to function to set call back of EXTI3*/
static void (*EXTI_LINE_3_CallBack) (void) ;

/*pointer to function to set call back of EXTI4*/
static void (*EXTI_LINE_4_CallBack) (void) ;

/*pointer to function to set call back of EXTI5*/
static void (*EXTI_LINE_5_CallBack) (void) ;

/*pointer to function to set call back of EXTI6*/
static void (*EXTI_LINE_6_CallBack) (void) ;

/*pointer to function to set call back of EXTI7*/
static void (*EXTI_LINE_7_CallBack) (void) ;

/*pointer to function to set call back of EXTI8*/
static void (*EXTI_LINE_8_CallBack) (void) ;

/*pointer to function to set call back of EXTI9*/
static void (*EXTI_LINE_9_CallBack) (void) ;

/*pointer to function to set call back of EXTI10*/
static void (*EXTI_LINE_10_CallBack)(void) ;

/*pointer to function to set call back of EXTI11*/
static void (*EXTI_LINE_11_CallBack)(void) ;

/*pointer to function to set call back of EXTI12*/
static void (*EXTI_LINE_12_CallBack)(void) ;

/*pointer to function to set call back of EXTI13*/
static void (*EXTI_LINE_13_CallBack)(void) ;

/*pointer to function to set call back of EXTI14*/
static void (*EXTI_LINE_14_CallBack)(void) ;

/*pointer to function to set call back of EXTI15*/
static void (*EXTI_LINE_15_CallBack)(void) ;

void MEXTI_voidInit (u8 A_u8PortId , u8 A_u8LineNum , u8 A_u8InputPull)
{
	if (A_u8LineNum < 16)
	{
		/*selected un forbidden pin*/
		if ((A_u8PortId == GPIO_PORTC && A_u8LineNum > GPIO_PIN12) ||
			(A_u8PortId == GPIO_PORTA && A_u8LineNum < GPIO_PIN13) ||
			(A_u8PortId == GPIO_PORTB && A_u8LineNum != GPIO_PIN2 &&
					                     A_u8LineNum != GPIO_PIN3 &&
										 A_u8LineNum != GPIO_PIN4))
		{
		    /*initialize RCC with its configurations*/
		    MRCC_voidInit() ;

		    /*enable GPIO for selected PortId*/
		    switch (A_u8PortId)
		     {
		     case GPIO_PORTA:
		    	 MRCC_voidEnablePerephiralClock(RCC_AHB1 , RCC_EN_GPIOA) ;
		     	break ;
		     case GPIO_PORTB:
		    	 MRCC_voidEnablePerephiralClock(RCC_AHB1 , RCC_EN_GPIOB) ;
		     	break ;
		     case GPIO_PORTC:
		    	 MRCC_voidEnablePerephiralClock(RCC_AHB1 , RCC_EN_GPIOC) ;
		     	break ;
		     default :
		     	/*Error selection*/
		     	break ;
		     }

		    /*enable clock for EXTI*/
		    MRCC_voidEnablePerephiralClock(RCC_APB2 , RCC_EN_SYSCFG) ;

     	    /*configure A_u8LineNum as input*/
		    MGPIO_voidSetPinMode (A_u8PortId , A_u8LineNum , GPIO_MODE_INPUT) ;

		    /*configure type of input pull*/
		    MGPIO_voidSetPinInputPull(A_u8PortId , A_u8LineNum , A_u8InputPull) ;

		    /*enable NVIC for selected line*/
		    switch (A_u8LineNum)
		    {
		    case EXTI_LINE_0:
		    	MNVIC_voidEnablePeripheral(EXTI0) ;
		    	break ;
		    case EXTI_LINE_1:
		    	MNVIC_voidEnablePeripheral(EXTI1) ;
		    	break ;
		    case EXTI_LINE_2:
		    	MNVIC_voidEnablePeripheral(EXTI2) ;
		    	break ;
		    case EXTI_LINE_3:
		    	MNVIC_voidEnablePeripheral(EXTI3) ;
		    	break ;
		    case EXTI_LINE_4:
		    	MNVIC_voidEnablePeripheral(EXTI4) ;
		    	break ;
		    case EXTI_LINE_5:
		    	MNVIC_voidEnablePeripheral(EXTI5) ;
		    	break ;
		    case EXTI_LINE_6:
		    	MNVIC_voidEnablePeripheral(EXTI6) ;
		    	break ;
		    case EXTI_LINE_7:
		    	MNVIC_voidEnablePeripheral(EXTI7) ;
		    	break ;
		    case EXTI_LINE_8:
		    	MNVIC_voidEnablePeripheral(EXTI8) ;
		    	break ;
		    case EXTI_LINE_9:
		    	MNVIC_voidEnablePeripheral(EXTI9) ;
		    	break ;
		    case EXTI_LINE_10:
		    	MNVIC_voidEnablePeripheral(EXTI10) ;
		    	break ;
		    case EXTI_LINE_11:
		    	MNVIC_voidEnablePeripheral(EXTI11) ;
		    	break ;
		    case EXTI_LINE_12:
		    	MNVIC_voidEnablePeripheral(EXTI12) ;
		    	break ;
		    case EXTI_LINE_13:
		    	MNVIC_voidEnablePeripheral(EXTI13) ;
		    	break ;
		    case EXTI_LINE_14:
		    	MNVIC_voidEnablePeripheral(EXTI14) ;
		    	break ;
		    case EXTI_LINE_15:
		    	MNVIC_voidEnablePeripheral(EXTI15) ;
		    	break ;
		    default :
		    	/*Error selection*/
		    	break ;
		    }
		    /*select port and line number for EXTI*/
		    MSYSCFG_voidExtiPort (A_u8LineNum , A_u8PortId - 1) ;
		}
	}
}

void MEXTI_voidEnableLine (u8 A_u8Trigger , u8 A_u8LineNum)
{
	if (A_u8LineNum < 16)
	{
		/*enable sellected line*/
		SET_BIT (EXTI -> IMR , A_u8LineNum) ;
		switch (A_u8Trigger)
		{
		case EXTI_RISING:
			/*clear flaling trigger selected register and set rising trigger selected register*/
			CLR_BIT (EXTI -> FTSR , A_u8LineNum) ;
			SET_BIT (EXTI -> RTSR , A_u8LineNum) ;
			break ;
		case EXTI_FALING:
			/*set flaling trigger selected register and clear rising trigger selected register*/
			CLR_BIT (EXTI -> RTSR , A_u8LineNum) ;
			SET_BIT (EXTI -> FTSR , A_u8LineNum) ;
			break ;
		case ON_CHANGE:
			/*set flaling trigger selected register and set rising trigger selected register*/
			SET_BIT (EXTI -> RTSR , A_u8LineNum) ;
			SET_BIT (EXTI -> FTSR , A_u8LineNum) ;
			break ;
		default :
			/*Error selection*/
			break ;
		}
	}
}

void MEXTI_voidDisableLine (u8 A_u8LineNum)
{
	if (A_u8LineNum < 16)
    {
		/*desable selected line*/
    	CLR_BIT (EXTI -> IMR , A_u8LineNum) ;
    }
}

void MEXTI_voidSoftWareTrigger (u8 A_u8LineNum)
{
	if (A_u8LineNum < 16)
	{
		/*enable soft ware trigger for testing*/
    	SET_BIT (EXTI -> SWIER , A_u8LineNum) ;
    }
}

void MEXTI_voidSetTrigger (u8 A_u8Trigger , u8 A_u8LineNum)
{
	if (A_u8LineNum < 16)
    {
		/*selected trigger at run time*/
    	switch (A_u8Trigger)
    	{
    	case EXTI_RISING:
    		/*clear flaling trigger selected register and set rising trigger selected register*/
    		CLR_BIT (EXTI -> FTSR , A_u8LineNum) ;
    		SET_BIT (EXTI -> RTSR , A_u8LineNum) ;
    		break ;
    	case EXTI_FALING:
    		/*set flaling trigger selected register and clear rising trigger selected register*/
    		CLR_BIT (EXTI -> RTSR , A_u8LineNum) ;
    		SET_BIT (EXTI -> FTSR , A_u8LineNum) ;
    		break ;
    	case ON_CHANGE:
    		/*set flaling trigger selected register and set rising trigger selected register*/
    		SET_BIT (EXTI -> RTSR , A_u8LineNum) ;
    		SET_BIT (EXTI -> FTSR , A_u8LineNum) ;
    		break ;
    	default :
    		/*Error selection*/
    		break ;
    	}
    }
}

void MSYSCFG_voidExtiPort (u8 A_u8LineNum , u8 A_u8PortNum)
{
	u8 L_u8Index       = A_u8LineNum / 4 ;
	u8 L_u8ShiftAmount = (A_u8LineNum % 4 ) * 4;
	SYSCFG -> EXTICR [L_u8Index] &= ~((0b1111)      << (L_u8ShiftAmount)) ;
	SYSCFG -> EXTICR [L_u8Index] |=  ((A_u8PortNum) << (L_u8ShiftAmount)) ;
}

void MEXTI_voidSetCallBack (u8 A_u8LineNum , void (*A_fptr)(void))
{
    switch (A_u8LineNum)
    {
    case EXTI_LINE_0:
    	EXTI_LINE_0_CallBack = A_fptr ;
    	break ;
    case EXTI_LINE_1:
    	EXTI_LINE_1_CallBack = A_fptr ;
    	break ;
    case EXTI_LINE_2:
    	EXTI_LINE_2_CallBack = A_fptr ;
    	break ;
    case EXTI_LINE_3:
    	EXTI_LINE_3_CallBack = A_fptr ;
    	break ;
    case EXTI_LINE_4:
    	EXTI_LINE_4_CallBack = A_fptr ;
    	break ;
    case EXTI_LINE_5:
    	EXTI_LINE_5_CallBack = A_fptr ;
    	break ;
    case EXTI_LINE_6:
    	EXTI_LINE_6_CallBack = A_fptr ;
    	break ;
    case EXTI_LINE_7:
    	EXTI_LINE_7_CallBack = A_fptr ;
    	break ;
    case EXTI_LINE_8:
    	EXTI_LINE_8_CallBack = A_fptr ;
    	break ;
    case EXTI_LINE_9:
    	EXTI_LINE_9_CallBack = A_fptr ;
    	break ;
    case EXTI_LINE_10:
    	EXTI_LINE_10_CallBack = A_fptr ;
    	break ;
    case EXTI_LINE_11:
    	EXTI_LINE_11_CallBack = A_fptr ;
    	break ;
    case EXTI_LINE_12:
    	EXTI_LINE_12_CallBack = A_fptr ;
    	break ;
    case EXTI_LINE_13:
    	EXTI_LINE_13_CallBack = A_fptr ;
    	break ;
    case EXTI_LINE_14:
    	EXTI_LINE_14_CallBack = A_fptr ;
    	break ;
    case EXTI_LINE_15:
    	EXTI_LINE_15_CallBack = A_fptr ;
    	break ;
    default :
    	/*Error selection*/
    	break ;
    }
}

/*IRQHandler for EXTI0*/
void EXTI0_IRQHandler(void)
{
	if (EXTI_LINE_0_CallBack != NULL)
	{
		EXTI_LINE_0_CallBack () ;
	}
	/*desable pending flag of EXTI0*/
	SET_BIT (EXTI -> PR , EXTI_LINE_0) ;
}

/*IRQHandler for EXTI1*/
void EXTI1_IRQHandler(void)
{
	if (EXTI_LINE_1_CallBack != NULL)
	{
		EXTI_LINE_1_CallBack () ;
	}
	/*desable pending flag of EXTI1*/
	SET_BIT (EXTI -> PR , EXTI_LINE_1) ;
}

/*IRQHandler for EXTI2*/
void EXTI2_IRQHandler(void)
{
	if (EXTI_LINE_2_CallBack != NULL)
	{
		EXTI_LINE_2_CallBack () ;
	}
	/*desable pending flag of EXTI2*/
	SET_BIT (EXTI -> PR , EXTI_LINE_2) ;
}

/*IRQHandler for EXTI3*/
void EXTI3_IRQHandler(void)
{
	if (EXTI_LINE_3_CallBack != NULL)
	{
		EXTI_LINE_3_CallBack () ;
	}
	/*desable pending flag of EXTI3*/
	SET_BIT (EXTI -> PR , EXTI_LINE_3) ;
}

/*IRQHandler for EXTI4*/
void EXTI4_IRQHandler(void)
{
	if (EXTI_LINE_4_CallBack != NULL)
	{
		EXTI_LINE_4_CallBack () ;
	}
	/*desable pending flag of EXTI4*/
	SET_BIT (EXTI -> PR , EXTI_LINE_4) ;
}

/*IRQHandler for EXTI5 , EXTI6 , EXTI7 , EXTI8 , EXTI9*/
void EXTI9_5_IRQHandler(void)
{
	if (EXTI_LINE_5_CallBack != NULL)
	{
		EXTI_LINE_5_CallBack () ;
	}
	/*desable pending flag of EXTI5*/
	SET_BIT (EXTI -> PR , EXTI_LINE_5) ;

	if (EXTI_LINE_6_CallBack != NULL)
	{
		EXTI_LINE_6_CallBack () ;
	}
	/*desable pending flag of EXTI6*/
	SET_BIT (EXTI -> PR , EXTI_LINE_6) ;

	if (EXTI_LINE_7_CallBack != NULL)
	{
		EXTI_LINE_7_CallBack () ;
	}
	/*desable pending flag of EXTI7*/
	SET_BIT (EXTI -> PR , EXTI_LINE_7) ;

	if (EXTI_LINE_8_CallBack != NULL)
	{
		EXTI_LINE_8_CallBack () ;
	}
	/*desable pending flag of EXTI8*/
	SET_BIT (EXTI -> PR , EXTI_LINE_8) ;

	if (EXTI_LINE_9_CallBack != NULL)
	{
		EXTI_LINE_9_CallBack () ;
	}
	/*desable pending flag of EXTI9*/
	SET_BIT (EXTI -> PR , EXTI_LINE_9) ;
}

/*IRQHandler for EXTI10 , EXTI11 , EXTI12 , EXTI13 , EXTI14 , EXTI15*/
void EXTI15_10_IRQHandler(void)
{
	if (EXTI_LINE_10_CallBack != NULL)
	{
		EXTI_LINE_10_CallBack () ;
	}
	/*desable pending flag of EXTI10*/
	SET_BIT (EXTI -> PR , EXTI_LINE_10) ;

	if (EXTI_LINE_11_CallBack != NULL)
	{
		EXTI_LINE_11_CallBack () ;
	}
	/*desable pending flag of EXTI11*/
	SET_BIT (EXTI -> PR , EXTI_LINE_11) ;

	if (EXTI_LINE_12_CallBack != NULL)
	{
		EXTI_LINE_12_CallBack () ;
	}
	/*desable pending flag of EXTI12*/
	SET_BIT (EXTI -> PR , EXTI_LINE_12) ;

	if (EXTI_LINE_13_CallBack != NULL)
	{
		EXTI_LINE_13_CallBack () ;
	}
	/*desable pending flag of EXTI13*/
	SET_BIT (EXTI -> PR , EXTI_LINE_13) ;

	if (EXTI_LINE_14_CallBack != NULL)
	{
		EXTI_LINE_14_CallBack () ;
	}
	/*desable pending flag of EXTI14*/
	SET_BIT (EXTI -> PR , EXTI_LINE_14) ;

	if (EXTI_LINE_15_CallBack != NULL)
	{
		EXTI_LINE_15_CallBack () ;
	}
	/*desable pending flag of EXTI15*/
	SET_BIT (EXTI -> PR , EXTI_LINE_15) ;
}
