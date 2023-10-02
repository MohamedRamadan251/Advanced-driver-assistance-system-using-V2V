/*
 * TFT_prog.c
 *
 *  Created on: Sep 30, 2022
 *      Author: Mohammed Ramadan
 */




#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/GPIO/GPIO_init.h"
#include "../../MCAL/SYSTIC/SYSTIC_init.h"
#include "../../MCAL/SPI/SPI_init.h"

#include "TFT_conf.h"
#include "TFT_private.h"
#include "TFT_init.h"

#include "math.h"

/*declaration config_TFT_pins*/
extern HTFT_Config_t config_TFT_pins ;
/*declaration config_output_pin_push_pull*/
extern MGPIO_Config_t config_output_pin_push_pull ;

static void HTFT_voidWriteCmd (u8 A_u8SpiType , u16 A_u16Cmd)
{
	/*set control pin to zero*/
	MGPIO_voidSetPinValue(config_TFT_pins.A0_PORT , config_TFT_pins.A0_PIN , GPIO_LOW) ;
	/*send command*/
	MSPI_voidTransmite(A_u8SpiType , A_u16Cmd) ;
}

static void HTFT_voidWriteData (u8 A_u8SpiType , u16 A_u16Data)
{
	/*set control pin to one*/
	MGPIO_voidSetPinValue(config_TFT_pins.A0_PORT , config_TFT_pins.A0_PIN , GPIO_HIGH) ;
	/*send data*/
	MSPI_voidTransmite(A_u8SpiType , A_u16Data) ;
}

static void HTFT_voidReset (void)
{
	/*reser pin high to 6.3ms*/
	MGPIO_voidSetPinValue(config_TFT_pins.RESET_PORT , config_TFT_pins.RESET_PIN , GPIO_HIGH) ;
	MSTK_voidSetBusyWait(6300) ;

	/*reser pin high to 65us*/
	MGPIO_voidSetPinValue(config_TFT_pins.RESET_PORT , config_TFT_pins.RESET_PIN , GPIO_LOW ) ;
	MSTK_voidSetBusyWait(65) ;

	/*reser pin high to 6.3ms*/
	MGPIO_voidSetPinValue(config_TFT_pins.RESET_PORT , config_TFT_pins.RESET_PIN , GPIO_HIGH) ;
	MSTK_voidSetBusyWait(6300) ;

	/*reser pin high to 6.3ms*/
	MGPIO_voidSetPinValue(config_TFT_pins.RESET_PORT , config_TFT_pins.RESET_PIN , GPIO_LOW ) ;
	MSTK_voidSetBusyWait(6300) ;

	/*reser pin high to 160ms*/
	MGPIO_voidSetPinValue(config_TFT_pins.RESET_PORT , config_TFT_pins.RESET_PIN , GPIO_HIGH) ;
	MSTK_voidSetBusyWait(160000) ;
}

void HTFT_voidInit (u8 A_u8SpiType)
{
    /*Initialize RESET_PORT and control pin as an output*/
	MGPIO_voidInit(&config_output_pin_push_pull ,
			        config_TFT_pins.RESET_PORT  ,
					config_TFT_pins.RESET_PIN ) ;
	MGPIO_voidInit(&config_output_pin_push_pull ,
				    config_TFT_pins.A0_PORT  ,
					config_TFT_pins.A0_PIN ) ;

	/*Initialize Systic timer*/
	MSTK_voidInit() ;

	/*Initialize SPI1*/
	MSPI_voidInit(A_u8SpiType) ;

    /*reset sequance*/
	HTFT_voidReset () ;

	/*send sleep output command*/
	HTFT_voidWriteCmd(A_u8SpiType , SLPOUT_CMD) ;
	/*wait 98.65 ms*/
	MSTK_voidSetBusyWait(986500) ;
	/*send color mode and its id*/
	HTFT_voidWriteCmd (A_u8SpiType , COLOR_MODE_CMD) ;
	HTFT_voidWriteData(A_u8SpiType , COLOR_MODE_ID)  ;
	/*send display on mode*/
	HTFT_voidWriteCmd (A_u8SpiType , DISPLAY_ON_CMD) ;
}

void  HTFT_voidDisplayImage (u8 A_u8SpiType , const u16 AR_u16ImageArray [] , u32 A_u32ArraySize)
{
	/*counter for for loop*/
	u32 L_u32Counter ;

	/*comand to set x position*/
	HTFT_voidWriteCmd(A_u8SpiType , SET_X_POS_CMD) ;
	HTFT_voidWriteData(A_u8SpiType , 0) ;
	HTFT_voidWriteData(A_u8SpiType , 0) ;
	HTFT_voidWriteData(A_u8SpiType , 0) ;
	HTFT_voidWriteData(A_u8SpiType , 127) ;

	/*comand to set y position*/
	HTFT_voidWriteCmd(A_u8SpiType , SET_Y_POS_CMD) ;
	HTFT_voidWriteData(A_u8SpiType , 0) ;
	HTFT_voidWriteData(A_u8SpiType , 0) ;
	HTFT_voidWriteData(A_u8SpiType , 0) ;
	HTFT_voidWriteData(A_u8SpiType , 159) ;

	/*comand to send image*/
	HTFT_voidWriteCmd(A_u8SpiType , SET_SEND_IMAGE_CMD) ;

	/*loop to display imaage*/
	for (L_u32Counter = 0 ; L_u32Counter < A_u32ArraySize - 1 ; L_u32Counter ++)
	{
		u8 L_u8LowPart  = (u8)(AR_u16ImageArray [L_u32Counter] );
		u8 L_u8HighPart = (u8)(AR_u16ImageArray [L_u32Counter] >> 8) ;
		/*send high part*/
		HTFT_voidWriteData(A_u8SpiType , L_u8HighPart) ;
		/*send low part*/
		HTFT_voidWriteData(A_u8SpiType , L_u8LowPart) ;
	}
}


void HTFT_voidFillRectangle (u8 A_u8SpiType  ,
		                     u16 A_u16XStart ,
		                     u16 A_u16XEnd   ,
		                     u16 A_u16YStart ,
		                     u16 A_u16YEnd   ,
		                     u16 A_u16Color  )
{
	/*comand to set x position*/
	HTFT_voidWriteCmd(A_u8SpiType , SET_X_POS_CMD) ;
	HTFT_voidWriteData(A_u8SpiType , 0) ;
	HTFT_voidWriteData(A_u8SpiType , A_u16XStart) ;
	HTFT_voidWriteData(A_u8SpiType , 0) ;
	HTFT_voidWriteData(A_u8SpiType , A_u16XEnd) ;

	/*comand to set y position*/
	HTFT_voidWriteCmd(A_u8SpiType , SET_Y_POS_CMD) ;
	HTFT_voidWriteData(A_u8SpiType , 0) ;
	HTFT_voidWriteData(A_u8SpiType , A_u16YStart) ;
	HTFT_voidWriteData(A_u8SpiType , 0) ;
	HTFT_voidWriteData(A_u8SpiType , A_u16YEnd) ;

	/*counter for for loop*/
	u32 L_u32Counter ;
	/*calculate number of pixcels */
    u32 L_u32RectangleArea = (A_u16XEnd - A_u16XStart) * (A_u16YEnd - A_u16YStart) + 1 ;
	/*comand to send image*/
	HTFT_voidWriteCmd(A_u8SpiType , SET_SEND_IMAGE_CMD) ;

	/*loop to display imaage*/
	for (L_u32Counter = 0 ; L_u32Counter <= L_u32RectangleArea ; L_u32Counter ++)
	{
		u8 L_u8LowPart  = (u8)(A_u16Color );
		u8 L_u8HighPart = (u8)(A_u16Color >> 8) ;
		/*send high part*/
		HTFT_voidWriteData(A_u8SpiType , L_u8HighPart) ;
		/*send low part*/
		HTFT_voidWriteData(A_u8SpiType , L_u8LowPart) ;
	}
}

void HTFT_voidFillBackGround (u8 A_u8SpiType , u16 A_u16Color)
{
	/*counter for for loop*/
	u32 L_u32Counter ;

	/*comand to set x position*/
	HTFT_voidWriteCmd(A_u8SpiType , SET_X_POS_CMD) ;
	HTFT_voidWriteData(A_u8SpiType , 0) ;
	HTFT_voidWriteData(A_u8SpiType , 0) ;
	HTFT_voidWriteData(A_u8SpiType , 0) ;
	HTFT_voidWriteData(A_u8SpiType , 127) ;

	/*comand to set y position*/
	HTFT_voidWriteCmd(A_u8SpiType , SET_Y_POS_CMD) ;
	HTFT_voidWriteData(A_u8SpiType , 0) ;
	HTFT_voidWriteData(A_u8SpiType , 0) ;
	HTFT_voidWriteData(A_u8SpiType , 0) ;
	HTFT_voidWriteData(A_u8SpiType , 159) ;

	/*comand to send image*/
	HTFT_voidWriteCmd(A_u8SpiType , SET_SEND_IMAGE_CMD) ;

	/*loop to display imaage*/
	for (L_u32Counter = 0 ; L_u32Counter <= SIZE_OF_IMAGE ; L_u32Counter ++)
	{
		u8 L_u8LowPart  = (u8)(A_u16Color);
		u8 L_u8HighPart = (u8)(A_u16Color >> 8) ;
		/*send high part*/
		HTFT_voidWriteData(A_u8SpiType , L_u8HighPart) ;
		/*send low part*/
		HTFT_voidWriteData(A_u8SpiType , L_u8LowPart) ;
	}
}

void HTFT_voidDL_u8RowLine (u8 A_u8SpiType ,
		                u16 A_u16X1     ,
                        u16 A_u16Y1     ,
		                u16 A_u16X2     ,
	                    u16 A_u16Y2     ,
						u16 A_u16Color)
{
	/*counter for for loop*/
	u16 L_u16Counter  ;
	/*slope of line*/
	f32 L_f32Slop     ;
	/*y for current point*/
	u16 L_u16CurrentY ;
	/*calc slope of line*/
	L_f32Slop = (A_u16Y2 - A_u16Y1)/(f32)(A_u16X2 - A_u16X1) ;
	for (L_u16Counter = A_u16X1 ; L_u16Counter <= A_u16X2 ; L_u16Counter ++)
	{
		/*calc current y depend to current x*/
		L_u16CurrentY = (L_f32Slop * (L_u16Counter - A_u16X1)) + A_u16Y1 ;
		/*display current point of line*/
		HTFT_voidFillRectangle (A_u8SpiType , L_u16Counter , L_u16Counter + 1 , L_u16CurrentY , L_u16CurrentY + 1 , A_u16Color) ;
	}
}

void HTFT_voidDL_u8RowVertcalLine (u8 A_u8SpiType ,
		                       u16 A_u16X  ,
                               u16 A_u16Y1     ,
	                           u16 A_u16Y2     ,
						       u16 A_u16Color)
{
	HTFT_voidFillRectangle (A_u8SpiType , A_u16X , A_u16X + 1 , A_u16Y1 , A_u16Y2 , A_u16Color) ;
}

void HTFT_voidDL_u8RowHorizontalLine (u8 A_u8SpiType ,
		                          u16 A_u16Y      ,
                                  u16 A_u16X1     ,
	                              u16 A_u16X2     ,
						          u16 A_u16Color)
{
	HTFT_voidFillRectangle (A_u8SpiType , A_u16X1 , A_u16X2 , A_u16Y , A_u16Y + 1 , A_u16Color) ;
}

void HTFT_voidDisplayChar (u8 A_u8SpiType ,
		                   s8  A_s8Row         ,
		                   s8  A_s8Col         ,
						   s8  A_s8Char        ,
						   u16 A_u16Foreground )
{
	if (A_s8Row <= 20 && A_s8Col <= 19)
	{
		s8 L_s8Row   ;
		s8 L_s8Pixel ;
		A_s8Row = 20 - A_s8Row ;
		A_s8Col = 19 - A_s8Col ;
		A_s8Row *= 6 ;
		A_s8Col *= 8 ;
		/*comand to set x position*/
		HTFT_voidWriteCmd(A_u8SpiType , SET_X_POS_CMD) ;
		HTFT_voidWriteData(A_u8SpiType , 0) ;
		HTFT_voidWriteData(A_u8SpiType , A_s8Row) ;
		HTFT_voidWriteData(A_u8SpiType , 0) ;
		HTFT_voidWriteData(A_u8SpiType , A_s8Row + 7) ;

		/*comand to set y position*/
		HTFT_voidWriteCmd(A_u8SpiType , SET_Y_POS_CMD) ;
		HTFT_voidWriteData(A_u8SpiType , 0) ;
		HTFT_voidWriteData(A_u8SpiType , A_s8Col) ;
		HTFT_voidWriteData(A_u8SpiType , 0) ;
		HTFT_voidWriteData(A_u8SpiType , A_s8Col + 8) ;

		/*comand to send image*/
		HTFT_voidWriteCmd(A_u8SpiType , SET_SEND_IMAGE_CMD) ;
		/*loop to each row*/
		for (L_s8Row = 6 ; L_s8Row >= 0 ; L_s8Row --)
		{
			/*at every row print pixels*/
			for (L_s8Pixel = 7 ; L_s8Pixel >= 0 ; L_s8Pixel --)
			{
				if (READ_BIT (FONT_CHARS[A_s8Char-32][L_s8Row] , L_s8Pixel) == 1)
				{
					u8 L_u8LowPart  = (u8)(A_u16Foreground);
					u8 L_u8HighPart = (u8)(A_u16Foreground >> 8) ;
					/*send high part*/
					HTFT_voidWriteData(A_u8SpiType , L_u8HighPart) ;
					/*send low part*/
					HTFT_voidWriteData(A_u8SpiType , L_u8LowPart) ;
				}
				else
				{
					u8 L_u8LowPart  = (u8)(BLACK);
					u8 L_u8HighPart = (u8)(BLACK >> 8) ;
					/*send high part*/
					HTFT_voidWriteData(A_u8SpiType , L_u8HighPart) ;
					/*send low part*/
					HTFT_voidWriteData(A_u8SpiType , L_u8LowPart) ;
				}
			}
		}
	}
}

void HTFT_voidDisplayString (u8 A_u8SpiType      ,
		                     s8  A_s8L_u8Row     ,
                             s8  A_s8Col         ,
		                     u8  A_s8String []   ,
		                     u16 A_u16Foreground )
{
	s8 L_s8Row = 0 ;
	while (A_s8String [L_s8Row] != '\0' )
	{
		HTFT_voidDisplayChar (A_u8SpiType , A_s8L_u8Row , A_s8Col , A_s8String [L_s8Row] , A_u16Foreground) ;
		A_s8L_u8Row ++ ;
		L_s8Row     ++ ;
	}
}
