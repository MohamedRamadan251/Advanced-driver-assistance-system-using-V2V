/*
 * GPIO_prog.c
 *
 *  Created on: Sep 6, 2022
 *      Author: Mohammed Ramadan
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../RCC/RCC_int.h"

#include "GPIO_init.h"
#include "GPIO_register.h"
#include "GPIO_private.h"



void MGPIO_voidSetPinMode (u8 A_u8PortId , u8 A_u8PinNumber , u8 A_u8Mode)
{
	if (A_u8PinNumber <= 15)
	{
		switch (A_u8PortId)
		{
		case GPIO_PORTA :
			/*PA13 , PA14 , PA15 are forbiden pins*/
			if (A_u8PinNumber < GPIO_PIN13)
			{
				GPIOA->MODER &= ~(MASK_TWO_BITS<<(A_u8PinNumber*2));
				GPIOA->MODER |=  (A_u8Mode<<(A_u8PinNumber*2));
			}
			break ;

		case GPIO_PORTB :
			/*PB2 , PB3 , PB4 are forbiden pins*/
			if (A_u8PinNumber != GPIO_PIN2 &&
				A_u8PinNumber != GPIO_PIN3 &&
				A_u8PinNumber != GPIO_PIN4)
			{
				GPIOB->MODER &= ~(MASK_TWO_BITS<<(A_u8PinNumber*2));
				GPIOB->MODER |=  (A_u8Mode<<(A_u8PinNumber*2));
			}
			break ;

		case GPIO_PORTC :
			/*port c  has pins 13 , 14 , 15*/
			if (A_u8PinNumber >= GPIO_PIN13)
			{
				GPIOC->MODER &= ~(MASK_TWO_BITS<<(A_u8PinNumber*2));
				GPIOC->MODER |=  (A_u8Mode<<(A_u8PinNumber*2));
			}
			break ;

		default :
		    /*incorreect port id*/
			break ;
		}
	}
}

void MGPIO_voidSetPinOutputType (u8 A_u8PortId , u8 A_u8PinNumber , u8 A_u8OutputType)
{
	if (A_u8PinNumber <= 15)
	{
		if (A_u8OutputType == GPIO_OTYPE_PUSHPULL)
		{
			switch (A_u8PortId)
			{
			case GPIO_PORTA :
				/*PA13 , PA14 , PA15 are forbiden pins*/
				if (A_u8PinNumber < GPIO_PIN13)
				{
					CLR_BIT(GPIOA->OTYPER, A_u8PinNumber);
				}
				break ;

			case GPIO_PORTB :
				/*PB2 , PB3 , PB4 are forbiden pins*/
				if (A_u8PinNumber != GPIO_PIN2 &&
					A_u8PinNumber != GPIO_PIN3 &&
					A_u8PinNumber != GPIO_PIN4)
				{
					CLR_BIT(GPIOB->OTYPER, A_u8PinNumber);
				}
				break ;

			case GPIO_PORTC :
				/*port c  has pins 13 , 14 , 15*/
				if (A_u8PinNumber >= GPIO_PIN13)
				{
					CLR_BIT(GPIOC->OTYPER, A_u8PinNumber);
				}
				break ;

			default :
			    /*incorreect port id*/
				break ;
			}
		}
		else if (A_u8OutputType == GPIO_OTYPE_OPENDRAIN)
		{
			switch (A_u8PortId)
			{
			case GPIO_PORTA :
				/*PA13 , PA14 , PA15 are forbiden pins*/
				if (A_u8PinNumber < GPIO_PIN13)
				{
					SET_BIT(GPIOA->OTYPER, A_u8PinNumber);
				}
				break ;

			case GPIO_PORTB :
				/*PB2 , PB3 , PB4 are forbiden pins*/
				if (A_u8PinNumber != GPIO_PIN2 &&
					A_u8PinNumber != GPIO_PIN3 &&
					A_u8PinNumber != GPIO_PIN4)
				{
					SET_BIT(GPIOB->OTYPER, A_u8PinNumber);
				}
				break ;

			case GPIO_PORTC :
				/*port c  has pins 13 , 14 , 15*/
				if (A_u8PinNumber >= GPIO_PIN13)
				{
					SET_BIT(GPIOC->OTYPER, A_u8PinNumber);
				}
				break ;

			default :
			    /*incorreect port id*/
				break ;
			}
		}
	}
}

void MGPIO_voidSetPinOutputSpeed (u8 A_u8PortId , u8 A_u8PinNumber , u8 A_u8OutputSpeed)
{
	if (A_u8PinNumber <= 15)
	{
		switch (A_u8PortId)
		{
		case GPIO_PORTA :
			/*PA13 , PA14 , PA15 are forbiden pins*/
			if (A_u8PinNumber < GPIO_PIN13)
			{
				GPIOA->OSPEEDR &= ~(MASK_TWO_BITS  <<(A_u8PinNumber*2));
				GPIOA->OSPEEDR |=  (A_u8OutputSpeed<<(A_u8PinNumber*2));
			}
			break ;

		case GPIO_PORTB :
			/*PB2 , PB3 , PB4 are forbiden pins*/
			if (A_u8PinNumber != GPIO_PIN2 &&
				A_u8PinNumber != GPIO_PIN3 &&
				A_u8PinNumber != GPIO_PIN4)
			{
				GPIOB->OSPEEDR &= ~(MASK_TWO_BITS  <<(A_u8PinNumber*2));
				GPIOB->OSPEEDR |=  (A_u8OutputSpeed<<(A_u8PinNumber*2));
			}
			break ;

		case GPIO_PORTC :
			/*port c  has pins 13 , 14 , 15*/
			if (A_u8PinNumber >= GPIO_PIN13)
			{
				GPIOC->OSPEEDR &= ~(MASK_TWO_BITS  <<(A_u8PinNumber*2));
				GPIOC->OSPEEDR |=  (A_u8OutputSpeed<<(A_u8PinNumber*2));
			}
			break ;

		default :
		    /*incorreect port id*/
			break ;
		}
	}
}

void MGPIO_voidSetPinInputPull (u8 A_u8PortId , u8 A_u8PinNumber , u8 A_u8InputPull)
{
	if (A_u8PinNumber <= 15)
	{
		switch (A_u8PortId)
		{
		case GPIO_PORTA :
			/*PA13 , PA14 , PA15 are forbiden pins*/
			if (A_u8PinNumber < GPIO_PIN13)
			{
				GPIOA->PUPDR &= ~(MASK_TWO_BITS<<(A_u8PinNumber*2));
				GPIOA->PUPDR |=  (A_u8InputPull<<(A_u8PinNumber*2));
			}
			break ;

		case GPIO_PORTB :
			/*PB2 , PB3 , PB4 are forbiden pins*/
			if (A_u8PinNumber != GPIO_PIN2 &&
				A_u8PinNumber != GPIO_PIN3 &&
				A_u8PinNumber != GPIO_PIN4)
			{
				GPIOB->PUPDR &= ~(MASK_TWO_BITS<<(A_u8PinNumber*2));
				GPIOB->PUPDR |=  (A_u8InputPull<<(A_u8PinNumber*2));
			}
			break ;

		case GPIO_PORTC :
			/*port c  has pins 13 , 14 , 15*/
			if (A_u8PinNumber >= GPIO_PIN13)
			{
				GPIOC->PUPDR &= ~(MASK_TWO_BITS<<(A_u8PinNumber*2));
				GPIOC->PUPDR |=  (A_u8InputPull<<(A_u8PinNumber*2));
			}
			break ;

		default :
		    /*incorreect port id*/
			break ;
		}
	}
}

void MGPIO_voidSetPinValue (u8 A_u8PortId , u8 A_u8PinNumber , u8 A_u8PinValue)
{
	if (A_u8PinNumber <= 15)
	{
		if (A_u8PinValue == GPIO_LOW)
		{
			switch (A_u8PortId)
			{
			case GPIO_PORTA :
				/*PA13 , PA14 , PA15 are forbiden pins*/
				if (A_u8PinNumber < GPIO_PIN13)
				{
					CLR_BIT(GPIOA->ODR, A_u8PinNumber);
				}
				break ;

			case GPIO_PORTB :
				/*PB2 , PB3 , PB4 are forbiden pins*/
				if (A_u8PinNumber != GPIO_PIN2 &&
					A_u8PinNumber != GPIO_PIN3 &&
					A_u8PinNumber != GPIO_PIN4)
				{
					CLR_BIT(GPIOB->ODR, A_u8PinNumber);
				}
				break ;

			case GPIO_PORTC :
				/*port c  has pins 13 , 14 , 15*/
				if (A_u8PinNumber >= GPIO_PIN13)
				{
					CLR_BIT(GPIOC->ODR, A_u8PinNumber);
				}
				break ;

			default :
			    /*incorreect port id*/
				break ;
			}
		}
		else if (A_u8PinValue == GPIO_HIGH)
		{
			switch (A_u8PortId)
			{
			case GPIO_PORTA :
				/*PA13 , PA14 , PA15 are forbiden pins*/
				if (A_u8PinNumber < GPIO_PIN13)
				{
					SET_BIT(GPIOA->ODR, A_u8PinNumber);
				}
				break ;

			case GPIO_PORTB :
				/*PB2 , PB3 , PB4 are forbiden pins*/
				if (A_u8PinNumber != GPIO_PIN2 &&
					A_u8PinNumber != GPIO_PIN3 &&
					A_u8PinNumber != GPIO_PIN4)
				{
					SET_BIT(GPIOB->ODR, A_u8PinNumber);
				}
				break ;

			case GPIO_PORTC :
				/*port c  has pins 13 , 14 , 15*/
				if (A_u8PinNumber >= GPIO_PIN13)
				{
					SET_BIT(GPIOC->ODR, A_u8PinNumber);
				}
				break ;

			default :
			    /*incorreect port id*/
				break ;
			}
		}
	}
}

void MGPIO_voidTogPinValue (u8 A_u8PortId , u8 A_u8PinNumber)
{
	if (A_u8PinNumber <= 15)
	{
	    switch (A_u8PortId)
	    {
	    case GPIO_PORTA :
	    	/*PA13 , PA14 , PA15 are forbiden pins*/
	    	if (A_u8PinNumber < GPIO_PIN13)
	    	{
	    		TOG_BIT(GPIOA->ODR, A_u8PinNumber);
	    	}
	    	break ;

	    case GPIO_PORTB :
	    	/*PB2 , PB3 , PB4 are forbiden pins*/
	    	if (A_u8PinNumber != GPIO_PIN2 &&
	    		A_u8PinNumber != GPIO_PIN3 &&
	    		A_u8PinNumber != GPIO_PIN4)
	    	{
	    		TOG_BIT(GPIOB->ODR, A_u8PinNumber);
	    	}
	    	break ;

	    case GPIO_PORTC :
	    	/*port c  has pins 13 , 14 , 15*/
	    	if (A_u8PinNumber >= GPIO_PIN13)
	    	{
	    		TOG_BIT(GPIOC->ODR, A_u8PinNumber);
	    	}
	    	break ;

	    default :
	        /*incorreect port id*/
	    	break ;
	    }
	}
}

u8 MGPIO_voidGetPinValue (u8 A_u8PortId , u8 A_u8PinNumber)
{
	u8 L_u8PinValue = 0 ;
	if (A_u8PinNumber <= 15)
	{
	   switch (A_u8PortId)
	   {
	   case GPIO_PORTA :
	   	/*PA13 , PA14 , PA15 are forbiden pins*/
	   	if (A_u8PinNumber < GPIO_PIN13)
	   	{
	   		L_u8PinValue = READ_BIT(GPIOA->IDR, A_u8PinNumber);
	   	}
	   	break ;

	   case GPIO_PORTB :
	   	/*PB2 , PB3 , PB4 are forbiden pins*/
	   	if (A_u8PinNumber != GPIO_PIN2 &&
	   		A_u8PinNumber != GPIO_PIN3 &&
	   		A_u8PinNumber != GPIO_PIN4)
	   	{
	   		L_u8PinValue = READ_BIT(GPIOB->IDR, A_u8PinNumber);
	   	}
	   	break ;

	   case GPIO_PORTC :
	   	/*port c  has pins 13 , 14 , 15*/
	   	if (A_u8PinNumber >= GPIO_PIN13)
	   	{
	   		L_u8PinValue = READ_BIT(GPIOC->IDR, A_u8PinNumber);
	   	}
	   	break ;

	   default :
	       /*incorreect port id*/
	   	break ;
	   }
	}
	return L_u8PinValue ;
}

void MGPIO_voidSetAltFun (u8 A_u8PortId , u8 A_u8PinNumber , u8 A_u8AltFun)
{
	if (A_u8PinNumber <= 15)
	{
		if (A_u8PinNumber < 8)
		{
			switch (A_u8PortId)
			{
			case GPIO_PORTA :
					GPIOA->AFRL &= ~(MASK_FOUR_BITS<<(A_u8PinNumber*4));
					GPIOA->AFRL |=  (A_u8AltFun<<(A_u8PinNumber*4));

				break ;

			case GPIO_PORTB :
					GPIOB->AFRL &= ~(MASK_FOUR_BITS<<(A_u8PinNumber*4));
					GPIOB->AFRL |=  (A_u8AltFun<<(A_u8PinNumber*4));
				break ;

			case GPIO_PORTC :
					GPIOC->AFRL &= ~(MASK_FOUR_BITS<<(A_u8PinNumber*4));
					GPIOC->AFRL |=  (A_u8AltFun<<(A_u8PinNumber*4));
				break ;

			default :
				/*incorreect port id*/
				break ;
			}
		}
		else if (A_u8PinNumber >= 8 && A_u8PinNumber < 16)
		{
			switch (A_u8PortId)
			{
			case GPIO_PORTA :
					GPIOA->AFRH &= ~(MASK_FOUR_BITS<<((A_u8PinNumber-8)*4));
					GPIOA->AFRH |=  (A_u8AltFun<<((A_u8PinNumber-8)*4));
				break ;

			case GPIO_PORTB :
					GPIOB->AFRH &= ~(MASK_FOUR_BITS<<((A_u8PinNumber-8)*4));
					GPIOB->AFRH |=  (A_u8AltFun<<((A_u8PinNumber-8)*4));
				break ;

			case GPIO_PORTC :
					GPIOC->AFRH &= ~(MASK_FOUR_BITS<<((A_u8PinNumber-8)*4));
					GPIOC->AFRH |=  (A_u8AltFun<<((A_u8PinNumber-8)*4));
				break ;

			default :
				/*incorreect port id*/
				break ;
			}
		}
	}
}

void MGPIO_voidInit (MGPIO_Config_t * A_PstructPinConfig , u8 A_u8Port , u8 A_u8Pin)
{
    MRCC_voidInit ( );
    if (A_u8Port == GPIO_PORTA)
    {
    	MRCC_voidEnablePerephiralClock (RCC_AHB1, RCC_EN_GPIOA     );
    }

    else if (A_u8Port == GPIO_PORTB)
    {
    	MRCC_voidEnablePerephiralClock (RCC_AHB1, RCC_EN_GPIOB     );
    }

    else if (A_u8Port == GPIO_PORTC)
    {
    	MRCC_voidEnablePerephiralClock (RCC_AHB1, RCC_EN_GPIOC     );
    }

	MGPIO_voidSetPinMode           (A_u8Port                       ,
			                        A_u8Pin                        ,
							        A_PstructPinConfig->Mode       );

    MGPIO_voidSetPinOutputType     (A_u8Port                       ,
    		                        A_u8Pin                        ,
							        A_PstructPinConfig->OutputType );

    MGPIO_voidSetPinOutputSpeed    (A_u8Port                       ,
    		                        A_u8Pin                        ,
							        A_PstructPinConfig->OutputSpeed);

    MGPIO_voidSetPinInputPull      (A_u8Port                       ,
    		                        A_u8Pin                        ,
							        A_PstructPinConfig->InputPull  );
}
