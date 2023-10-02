/*
 * Joystick_init.h
 *
 *  Created on: Apr 8, 2023
 *      Author: Mohammed Ramadan
 */

#ifndef HAL_JOYSTICK_JOYSTICK_INIT_H_
#define HAL_JOYSTICK_JOYSTICK_INIT_H_

/*
 * Define JoyStick_t to used in Joystick_conf.c file
 */
typedef struct
{
	u8 ChannelX    ;
	u8 ChannelY    ;
	u8 SwitchZPort ;
	u8 SwitchZLine  ;
}JoyStick_t;

/*
 *
 */
typedef struct
{
	u32 X ;
	u32 Y ;
	u8  Z ;
}X_Y_Zposition;

/*
	Function Name        : HJoystick_voidInit
	Function Returns     : void
	Function Arguments   : JoyStick_t *JoystickConf (pointer to struct)
	Function Description : initialization channels and SW of Joystick
*/
void HJoystick_voidInit (JoyStick_t *JoystickConf) ;

/*
	Function Name        : HJoystick_xMappedXandY
	Function Returns     : X_Y_Zposition (struct)
	Function Arguments   : JoyStick_t *JoystickConf (pointer to struct)
	Function Description : mapped positions of X , Y and Z
	                       note for Z : it is counting from 0 to 5
*/
X_Y_Zposition HJoystick_xMappedXandY (JoyStick_t *JoystickConf) ;

#endif /* HAL_JOYSTICK_JOYSTICK_INIT_H_ */
