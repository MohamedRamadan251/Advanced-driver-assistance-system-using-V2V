/*
 * GPIO_init.h
 *
 *  Created on: Sep 6, 2022
 *      Author: Mohammed Ramadan
 */

#ifndef MCAL_GPIO_GPIO_INIT_H_
#define MCAL_GPIO_GPIO_INIT_H_

typedef struct
{
	u8 Mode       ;
	u8 OutputType ;
	u8 OutputSpeed;
	u8 InputPull  ;
	u8 AltFunc    ;
}MGPIO_Config_t   ;

/*define ports*/
#define GPIO_PORTA                  1
#define GPIO_PORTB                  2
#define GPIO_PORTC                  3

/*define pins*/
#define GPIO_PIN0                   0
#define GPIO_PIN1                   1
#define GPIO_PIN2                   2
#define GPIO_PIN3                   3
#define GPIO_PIN4                   4
#define GPIO_PIN5                   5
#define GPIO_PIN6                   6
#define GPIO_PIN7                   7
#define GPIO_PIN8                   8
#define GPIO_PIN9                   9
#define GPIO_PIN10                  10
#define GPIO_PIN11                  11
#define GPIO_PIN12                  12
#define GPIO_PIN13                  13
#define GPIO_PIN14                  14
#define GPIO_PIN15                  15

/*define modes*/
#define GPIO_MODE_INPUT		        0b00
#define GPIO_MODE_OUTPUT	        0b01
#define GPIO_MODE_ALTFUN	        0b10
#define GPIO_MODE_ANALOG	        0b11

/*define type of output*/
#define GPIO_OTYPE_PUSHPULL         0
#define GPIO_OTYPE_OPENDRAIN		1

/*define speed*/
#define GPIO_SPEED_LOW              0b00
#define GPIO_SPEED_MED		        0b01
#define GPIO_SPEED_HIGH		        0b10
#define GPIO_SPEED_VHIGH	        0b11

/*define input type*/
#define GPIO_INPUT_NO_PULL		    0b00
#define GPIO_INPUT_PULL_UP		    0b01
#define GPIO_INPUT_PULL_DOWN	    0b10

/*define outputs*/
#define GPIO_LOW	            	0
#define GPIO_HIGH		            1

/*define AltFun*/
#define ALT_FUN_0                   0
#define ALT_FUN_1                   1
#define ALT_FUN_2                   2
#define ALT_FUN_3                   3
#define ALT_FUN_4                   4
#define ALT_FUN_5                   5
#define ALT_FUN_6                   6
#define ALT_FUN_7                   7
#define ALT_FUN_8                   8
#define ALT_FUN_9                   9
#define ALT_FUN_10                  10
#define ALT_FUN_11                  11
#define ALT_FUN_12                  12
#define ALT_FUN_13                  13
#define ALT_FUN_14                  14
#define ALT_FUN_15                  15

/**
	Function Name        : MRCC_voidInit
	Function Returns     : void
	Function Arguments   : u8 A_u8PortId , u8 A_u8PinNumber , u8 A_u8Mode
	Function Description : select mode of pin ( output or input or analog or AF)
*/
void MGPIO_voidSetPinMode (u8 A_u8PortId , u8 A_u8PinNumber , u8 A_u8Mode) ;

/**
	Function Name        : MGPIO_voidSetPinOutputType
	Function Returns     : void
	Function Arguments   : u8 A_u8PortId , u8 A_u8PinNumber , u8 A_u8OutputType
	Function Description : select the pin is pushpull or opendrain
*/
void MGPIO_voidSetPinOutputType (u8 A_u8PortId , u8 A_u8PinNumber , u8 A_u8OutputType) ;

/**
	Function Name        : MGPIO_voidSetPinOutputSpeed
	Function Returns     : void
	Function Arguments   : u8 A_u8PortId , u8 A_u8PinNumber , u8 A_u8OutputSpeed
	Function Description : select speed of mc
*/
void MGPIO_voidSetPinOutputSpeed (u8 A_u8PortId , u8 A_u8PinNumber , u8 A_u8OutputSpeed) ;

/**
	Function Name        : MGPIO_voidSetPinInputPull
	Function Returns     : void
	Function Arguments   : u8 A_u8PortId , u8 A_u8PinNumber , u8 A_u8InputPull
	Function Description : select input pullup or pulldown or non pullup
*/
void MGPIO_voidSetPinInputPull (u8 A_u8PortId , u8 A_u8PinNumber , u8 A_u8InputPull) ;

/**
	Function Name        : MGPIO_voidSetPinValue
	Function Returns     : void
	Function Arguments   : u8 A_u8PortId , u8 A_u8PinNumber , u8 A_u8PinValue
	Function Description : set pin to low or high
*/
void MGPIO_voidSetPinValue (u8 A_u8PortId , u8 A_u8PinNumber , u8 A_u8PinValue) ;

/**
	Function Name        : MGPIO_voidSetPinValue
	Function Returns     : void
	Function Arguments   : u8 A_u8PortId , u8 A_u8PinNumber , u8 A_u8PinValue
	Function Description : tog pin statues
*/
void MGPIO_voidTogPinValue (u8 A_u8PortId , u8 A_u8PinNumber) ;

/**
	Function Name        : MGPIO_voidGetPinValue
	Function Returns     : u8
	Function Arguments   : u8 A_u8PortId , u8 A_u8PinNumber
	Function Description : read the statues of pin
*/
u8   MGPIO_voidGetPinValue (u8 A_u8PortId , u8 A_u8PinNumber) ;

/**
	Function Name        : MGPIO_voidSetAltFun
	Function Returns     : void
	Function Arguments   : u8 A_u8PortId , u8 A_u8PinNumber , u8 A_u8AltFun
	Function Description : initialize the  GPIO pin as altirnative function
*/
void MGPIO_voidSetAltFun (u8 A_u8PortId , u8 A_u8PinNumber , u8 A_u8AltFun) ;

/**
	Function Name        : MGPIO_voidInit
	Function Returns     : void
	Function Arguments   : MGPIO_Config_t * A_PstructPinConfig
	Function Description : initialize the  GPIO Peripheral
*/
void MGPIO_voidInit (MGPIO_Config_t * A_PstructPinConfig , u8 A_u8Port , u8 A_u8Pin) ;

#endif /* MCAL_GPIO_GPIO_INIT_H_ */
