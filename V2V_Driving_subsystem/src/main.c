#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "MCAL/SYSTIC/SYSTIC_init.h"
#include "MCAL/SPI/SPI_init.h"

#include "HAL/NRF24L01/NRF_init.h"
#include "HAL/Joystick/Joystick_init.h"
#include "HAL/TFT/TFT_init.h"
#include "HAL/LED/LED_int.h"

#include "car_image.h"
extern NRF24_t    NRF24_conf ;
extern JoyStick_t JoystickConf ;
void main (void)
{
	u8 R_u8TxAddress [] = {0xEE , 0xDD , 0xCC , 0xBB , 0xAA} ;
	u8 L_u8DirectionTransmit = 0 ;
	u8 L_u8VelocityTransmit ;
	/*local staruct to store position of toystick*/
	X_Y_Zposition L_xXYZ ;

	/*initialization LEDs*/
	HLED_voidLedInitial(LED1_ID) ; /* Green */
	HLED_voidLedInitial(LED2_ID) ; /*  Red  */
	HLED_voidLedInitial(LED3_ID) ; /* Yellow*/

	/*initialization NRF_TX*/
	HNRF_voidInit (SPI2_Type , & NRF24_conf) ;
    HNRF_voidTxMode (SPI2_Type , & NRF24_conf , R_u8TxAddress , 10) ;

    /*initialization Jotstick*/
    HJoystick_voidInit(&JoystickConf) ;

    /*initialization TFT*/
    HTFT_voidInit(SPI1_Type) ;

    HTFT_voidDisplayImage(SPI1_Type , car , sizeof (car) / sizeof (car [0])) ;
    HTFT_voidDisplayString(SPI1_Type , 1 , 3 , (u8*)"Direction =inittial" , YELLOW) ;
    HTFT_voidDisplayString(SPI1_Type , 1 , 4 , (u8*)"Speed     =  " , YELLOW) ;

    while (1)
	{
		L_xXYZ = HJoystick_xMappedXandY(&JoystickConf) ;
		if (L_xXYZ.X <= 5 && L_xXYZ.Y <= 5)
		{
			L_u8DirectionTransmit = 3 ;
			HTFT_voidDisplayString(SPI1_Type , 12 , 3 , (u8*)"F_Left  " , YELLOW) ;
		}
		else if (L_xXYZ.X <= 180 && L_xXYZ.X >= 175 && L_xXYZ.Y <= 180 && L_xXYZ.Y >= 175)
		{
			L_u8DirectionTransmit = 4 ;
			HTFT_voidDisplayString(SPI1_Type , 12 , 3 , (u8*)"B_Write " , YELLOW) ;
		}
		else if (L_xXYZ.X <= 180 && L_xXYZ.X >= 170 && L_xXYZ.Y <= 5)
		{
			L_u8DirectionTransmit = 1 ;
			HTFT_voidDisplayString(SPI1_Type , 12 , 3 , (u8*)"F_Write " , YELLOW) ;
		}
		else if (L_xXYZ.X <= 5 && L_xXYZ.Y <= 180 && L_xXYZ.Y >= 175)
		{
			L_u8DirectionTransmit = 2 ;
			HTFT_voidDisplayString(SPI1_Type , 12 , 3 , (u8*)"B_Left  " , YELLOW) ;
		}
		else if (L_xXYZ.X <= 90 && L_xXYZ.X >= 85 && L_xXYZ.Y <= 5)
		{
			L_u8DirectionTransmit = 'F' ;
			HTFT_voidDisplayString(SPI1_Type , 12 , 3 , (u8*)"Forward " , YELLOW) ;
		}
		else if (L_xXYZ.X <= 90 && L_xXYZ.X >= 85 && L_xXYZ.Y <= 180 && L_xXYZ.Y >= 175)
		{
			L_u8DirectionTransmit = 'B' ;
			HTFT_voidDisplayString(SPI1_Type , 12 , 3 , (u8*)"Back    " , YELLOW) ;
		}
		else if (L_xXYZ.X <= 180 && L_xXYZ.X >= 175 && L_xXYZ.Y <= 90 && L_xXYZ.Y >= 85)
		{
			L_u8DirectionTransmit = 'W' ;
			HTFT_voidDisplayString(SPI1_Type , 12 , 3 , (u8*)"Write   " , YELLOW) ;
		}
		else if (L_xXYZ.X <= 5 && L_xXYZ.Y <= 90 && L_xXYZ.Y >= 85)
		{
			L_u8DirectionTransmit = 'L' ;
			HTFT_voidDisplayString(SPI1_Type , 12 , 3 , (u8*)"Left    " , YELLOW) ;
		}
		L_u8VelocityTransmit = L_xXYZ.Z ;

		if (L_u8VelocityTransmit == 0)
		{
			HLED_voidLedOn(LED2_ID) ;
			HLED_voidLedOff(LED1_ID) ;
			HLED_voidLedOff(LED3_ID) ;
			HTFT_voidDisplayString(SPI1_Type , 12 , 4 , (u8*)"Zero  " , YELLOW) ;
		}
		else if (L_u8VelocityTransmit == 2)
		{
			HLED_voidLedOn(LED3_ID) ;
			HLED_voidLedOff(LED2_ID) ;
			HLED_voidLedOff(LED1_ID) ;
			HTFT_voidDisplayString(SPI1_Type , 12 , 4 , (u8*)"First " , YELLOW) ;
		}
		else if (L_u8VelocityTransmit == 4)
		{
			HLED_voidLedOn(LED3_ID) ;
			HLED_voidLedOff(LED2_ID) ;
			HLED_voidLedOff(LED1_ID) ;
			HTFT_voidDisplayString(SPI1_Type , 12 , 4 , (u8*)"Second" , YELLOW) ;
		}
		else if (L_u8VelocityTransmit == 6)
		{
			HLED_voidLedOn(LED1_ID) ;
			HLED_voidLedOff(LED2_ID) ;
			HLED_voidLedOff(LED3_ID) ;
			HTFT_voidDisplayString(SPI1_Type , 12 , 4 , (u8*)"Third " , YELLOW) ;
		}
		else if (L_u8VelocityTransmit == 8)
		{
			HLED_voidLedOn(LED1_ID) ;
			HLED_voidLedOff(LED2_ID) ;
			HLED_voidLedOff(LED3_ID) ;
			HTFT_voidDisplayString(SPI1_Type , 12 , 4 , (u8*)"Fourth" , YELLOW) ;
		}
		else if (L_u8VelocityTransmit == 10)
		{
			HLED_voidLedOn(LED1_ID) ;
			HLED_voidLedOff(LED2_ID) ;
			HLED_voidLedOff(LED3_ID) ;
			HTFT_voidDisplayString(SPI1_Type , 12 , 4 , (u8*)"Fifth " , YELLOW) ;
		}
//		/*send direction and velocity*/
//		HNRF_u8Transmit(SPI2_Type , & NRF24_conf , L_u8DirectionTransmit) ;
//		MSTK_voidSetBusyWait(150) ;
//		HNRF_u8Transmit(SPI2_Type , & NRF24_conf , L_u8VelocityTransmit) ;
//		MSTK_voidSetBusyWait(150) ;
	}
}
