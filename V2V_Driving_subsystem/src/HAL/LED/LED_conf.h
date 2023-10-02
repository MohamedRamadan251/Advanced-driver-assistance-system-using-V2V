/*
 * LED_conf.h
 *
 *  Created on: May 18, 2022
 *      Author: Mohamed Ramadan
 */

#ifndef HAL_LED_LED_CONF_H
#define HAL_LED_LED_CONF_H
/**
      ** Connections **
	  
 *Options of LEDx_PORT are :
            *GPIO_PORTA
			*GPIO_PORTB
			*GPIO_PORTC

 *Options of LEDx_PIN are :
            *GPIO_PIN0
			*GPIO_PIN1
			*GPIO_PIN2
			*GPIO_PIN3
			*GPIO_PIN4
			*GPIO_PIN5
			*GPIO_PIN6
			*GPIO_PIN7
			*GPIO_PIN8
			*GPIO_PIN9
			*GPIO_PIN10
			*GPIO_PIN12
			*GPIO_PIN13
			*GPIO_PIN14
			*GPIO_PIN15
			
	where x is the ID of led "x = 1 or 2 or 3 or 4 or 5 or 6 or 7 or 8"
*/

/*
 * "for LED_PIN PA13 , PA14 , PA15 are forbidden pins"
 * "for LED_PIN PB2 , PB3 , PB4 are forbidden pins"
 * "for LED_PIN PC13 , PC14 , PC15 are only allowed pins"
 */

/**
 * Options of A_u8LED_ID 
        *LED1_ID 
		*LED2_ID 
		*LED3_ID 
		*LED4_ID 
		*LED5_ID 
		*LED6_ID
		*LED7_ID
		*LED8_ID
*/

/**
 * connection of led 1
*/
#define LED1_PORT    GPIO_PORTC
#define LED1_PIN     GPIO_PIN13

/**
 * connection of led 2
*/
#define LED2_PORT    GPIO_PORTC
#define LED2_PIN     GPIO_PIN14

/**
 * connection of led 3
*/
#define LED3_PORT    GPIO_PORTC
#define LED3_PIN     GPIO_PIN15

/**
 * connection of led 4
*/
#define LED4_PORT    GPIO_PORTA
#define LED4_PIN     GPIO_PIN3
 
/**
 * connection of led 5
*/
#define LED5_PORT    GPIO_PORTA
#define LED5_PIN     GPIO_PIN4

/**
 * connection of led 6
*/
#define LED6_PORT    GPIO_PORTA
#define LED6_PIN     GPIO_PIN5

/**
 * connection of led 7
*/
#define LED7_PORT    GPIO_PORTA
#define LED7_PIN     GPIO_PIN6

/**
 * connection of led 8
*/
#define LED8_PORT    GPIO_PORTA
#define LED8_PIN     GPIO_PIN7


#endif /* HAL_LED_LED_CONF_H */
