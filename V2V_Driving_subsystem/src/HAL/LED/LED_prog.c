/*
 * LED_prog.c
 *
 *  Created on: May 18, 2022
 *      Author: Mohammed Ramadan
 */
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/GPIO/GPIO_init.h"
#include "LED_int.h"
#include "LED_private.h"
#include "LED_conf.h"

#if LED_PORT == GPIO_PORTA
    #if LED_PIN > GPIO_PIN12
        #error  "for LED_PIN PA13 , PA14 , PA15 are forbidden pins"
    #endif
#endif

#if LED_PORT == GPIO_PORTB
    #if LED_PIN >= GPIO_PIN2 && LED_PIN <= GPIO_PIN4
        #error  "for LED_PIN PB2 , PB3 , PB4 are forbidden pins"
    #endif
#endif

#if LED_PORT == GPIO_PORTC
    #if LED_PIN < GPIO_PIN13
        #error  "for LED_PIN PC13 , PC14 , PC15 are only allowed pins"
    #endif
#endif


extern MGPIO_Config_t config_output_pin_push_pull ;

void HLED_voidLedInitial (u8 A_u8LED_ID)
{
	switch (A_u8LED_ID)
	{                  /**make direction of LED_1 is output*/
		case LED1_ID : MGPIO_voidInit(&config_output_pin_push_pull ,
				                       LED1_PORT                   ,
									   LED1_PIN                  ) ;
		break ;
		
		               /**make direction of LED_2 is output*/
		case LED2_ID : MGPIO_voidInit(&config_output_pin_push_pull ,
				                       LED2_PORT                   ,
									   LED2_PIN                  ) ;
		break ;
		
		               /**make direction of LED_3 is output*/
		case LED3_ID : MGPIO_voidInit(&config_output_pin_push_pull ,
				                       LED3_PORT                   ,
									   LED3_PIN) ;
		break ;
		
		               /**make direction of LED_4 is output*/
		case LED4_ID : MGPIO_voidInit(&config_output_pin_push_pull ,
				                       LED4_PORT                   ,
									   LED4_PIN) ;
		break ;
		
		               /**make direction of LED_5 is output*/
		case LED5_ID : MGPIO_voidInit(&config_output_pin_push_pull ,
				                       LED5_PORT                   ,
									   LED5_PIN) ;
		break ;
		
		               /**make direction of LED_6 is output*/
		case LED6_ID : MGPIO_voidInit(&config_output_pin_push_pull ,
				                       LED6_PORT                   ,
									   LED6_PIN) ;
		break ;
		
		               /**make direction of LED_7 is output*/
		case LED7_ID : MGPIO_voidInit(&config_output_pin_push_pull ,
				                       LED7_PORT                   ,
									   LED7_PIN) ;
		break ;
		
		               /**make direction of LED_8 is output*/
		case LED8_ID : MGPIO_voidInit(&config_output_pin_push_pull ,
				                       LED8_PORT                   ,
									   LED8_PIN) ;
		break ;
		default      :
			           /** Error */
		break ;
	}
}

void HLED_voidLedOn (u8 A_u8LED_ID)
{
	switch (A_u8LED_ID)
	{
		               /**turn on LED_1*/
		case LED1_ID : MGPIO_voidSetPinValue(LED1_PORT , LED1_PIN , GPIO_HIGH) ; break ;
		
		               /**turn on LED_2*/
		case LED2_ID : MGPIO_voidSetPinValue(LED2_PORT , LED2_PIN, GPIO_HIGH) ; break ;
		
		               /**turn on LED_3*/
		case LED3_ID : MGPIO_voidSetPinValue(LED3_PORT , LED3_PIN, GPIO_HIGH) ; break ;
		
		               /**turn on LED_4*/
		case LED4_ID : MGPIO_voidSetPinValue(LED4_PORT , LED4_PIN, GPIO_HIGH) ; break ;
		
		               /**turn on LED_5*/
		case LED5_ID : MGPIO_voidSetPinValue(LED5_PORT , LED5_PIN, GPIO_HIGH) ; break ;
		
		               /**turn on LED_6*/
		case LED6_ID : MGPIO_voidSetPinValue(LED6_PORT , LED6_PIN, GPIO_HIGH) ; break ;
		
		               /**turn on LED_7*/
		case LED7_ID : MGPIO_voidSetPinValue(LED7_PORT , LED7_PIN, GPIO_HIGH) ; break ;
		
		               /**turn on LED_8*/
		case LED8_ID : MGPIO_voidSetPinValue(LED8_PORT , LED8_PIN, GPIO_HIGH) ; break ;
		default      : /** Error */                                             break ;
	}
}

void HLED_voidLedOff (u8 A_u8LED_ID)
{
	switch (A_u8LED_ID)
    {
    	               /**turn on LED_1*/
    	case LED1_ID : MGPIO_voidSetPinValue(LED1_PORT , LED1_PIN , GPIO_LOW) ; break ;

    	               /**turn on LED_2*/
    	case LED2_ID : MGPIO_voidSetPinValue(LED2_PORT , LED2_PIN, GPIO_LOW) ; break ;

    	               /**turn on LED_3*/
    	case LED3_ID : MGPIO_voidSetPinValue(LED3_PORT , LED3_PIN, GPIO_LOW) ; break ;

    	               /**turn on LED_4*/
    	case LED4_ID : MGPIO_voidSetPinValue(LED4_PORT , LED4_PIN, GPIO_LOW) ; break ;

    	               /**turn on LED_5*/
    	case LED5_ID : MGPIO_voidSetPinValue(LED5_PORT , LED5_PIN, GPIO_LOW) ; break ;

    	               /**turn on LED_6*/
    	case LED6_ID : MGPIO_voidSetPinValue(LED6_PORT , LED6_PIN, GPIO_LOW) ; break ;

    	               /**turn on LED_7*/
    	case LED7_ID : MGPIO_voidSetPinValue(LED7_PORT , LED7_PIN, GPIO_LOW) ; break ;

    	               /**turn on LED_8*/
    	case LED8_ID : MGPIO_voidSetPinValue(LED8_PORT , LED8_PIN, GPIO_LOW) ; break ;
    	default      : /** Error */                                           break ;
    }
}

void HLED_voidLedToggle (u8 A_u8LED_ID)
{
	switch (A_u8LED_ID)
	{
		               /**inverse status of LED_1*/
		case LED1_ID : MGPIO_voidTogPinValue(LED1_PORT , LED1_PIN) ; break ;
		
		               /**inverse status of LED_2*/
		case LED2_ID : MGPIO_voidTogPinValue(LED2_PORT , LED2_PIN) ; break ;
		
		               /**inverse status of LED_3*/
		case LED3_ID : MGPIO_voidTogPinValue(LED3_PORT , LED3_PIN) ; break ;
		
		               /**inverse status of LED_4*/
		case LED4_ID : MGPIO_voidTogPinValue(LED4_PORT , LED4_PIN) ; break ;
		
		               /**inverse status of LED_5*/
		case LED5_ID : MGPIO_voidTogPinValue(LED5_PORT , LED5_PIN) ; break ;
		
		               /**inverse status of LED_6*/
		case LED6_ID : MGPIO_voidTogPinValue(LED6_PORT , LED6_PIN) ; break ;
		
		               /**inverse status of LED_7*/
		case LED7_ID : MGPIO_voidTogPinValue(LED7_PORT , LED7_PIN) ; break ;
		
		               /**inverse status of LED_8*/
		case LED8_ID : MGPIO_voidTogPinValue(LED8_PORT , LED8_PIN) ; break ;
		default      : /** Error */                                  break ;
	}
}
