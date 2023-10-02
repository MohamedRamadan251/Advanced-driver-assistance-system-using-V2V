/*
 * TFT_init.h
 *
 *  Created on: Sep 30, 2022
 *      Author: Mohammed Ramadan
 */

#ifndef HAL_TFT_TFT_INIT_H_
#define HAL_TFT_TFT_INIT_H_

/* Color constants */
#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x0400
#define LIME    0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

/**
	Function Name        : HTFT_voidInit
	Function Returns     : void
	Function Arguments   : void
	Function Description : initialize tft
*/
void HTFT_voidInit (u8 A_u8SpiType) ;

/**
	Function Name        : HTFT_voidDisplayImage
	Function Returns     : void
	Function Arguments   : const u16 AR_u16ImageArray []
	Function Description : diaplay image
*/
void HTFT_voidDisplayImage (u8 A_u8SpiType , const u16 AR_u16ImageArray []  , u32 A_u32ArraySize) ;

/**
	Function Name        : HTFT_voidFillRectangle
	Function Returns     : void
	Function Arguments   : u16 A_u16XStart ,
                           u16 A_u16XEnd   ,
                           u16 A_u16YStart ,
                           u16 A_u16YEnd   ,
                           u16 A_u16Color
	Function Description : drow rectangle with selection x,y with selection color
*/
void HTFT_voidFillRectangle (u8 A_u8SpiType  ,
		                     u16 A_u16XStart ,
		                     u16 A_u16XEnd   ,
							 u16 A_u16YStart ,
							 u16 A_u16YEnd   ,
							 u16 A_u16Color) ;
/**
	Function Name        : HTFT_voidFillBackGround
	Function Returns     : void
	Function Arguments   : u16 A_u16Color
	Function Description : set back ground of screen with selection color
*/
void HTFT_voidFillBackGround (u8 A_u8SpiType , u16 A_u16Color) ;

/**
	Function Name        : HTFT_voidFillRectangle
	Function Returns     : void
	Function Arguments   : u16 A_u16X1     ,
                           u16 A_u16Y1     ,
		                   u16 A_u16X2     ,
	                       u16 A_u16Y2     ,
						   u16 A_u16Color
	Function Description : drow line with selection x1,y1 , x2,y2 with selection color
*/
void HTFT_voidDrowLine (u16 A_u16X1     ,
                        u16 A_u16Y1     ,
		                u16 A_u16X2     ,
	                    u16 A_u16Y2     ,
						u16 A_u16Color) ;

/**
	Function Name        : HTFT_voidDrowVertcalLine
	Function Returns     : void
	Function Arguments   : u16 A_u16X      ,
                           u16 A_u16Y1     ,
	                       u16 A_u16Y2     ,
						   u16 A_u16Color
	Function Description : drow verical line with selection x , y1,y2 with selection color
*/
void HTFT_voidDrowVertcalLine (u16 A_u16X      ,
                               u16 A_u16Y1     ,
	                           u16 A_u16Y2     ,
						       u16 A_u16Color) ;

/**
	Function Name        : HTFT_voidDrowHorizontalLine
	Function Returns     : void
	Function Arguments   : u16 A_u16X      ,
                           u16 A_u16Y1     ,
	                       u16 A_u16Y2     ,
						   u16 A_u16Color
	Function Description : drow horizontal line with selection y , x1,x2 with selection color
*/
void HTFT_voidDrowHorizontalLine (u16 A_u16Y      ,
                                  u16 A_u16X1     ,
	                              u16 A_u16X2     ,
						          u16 A_u16Color) ;

/**
	Function Name        : HTFT_voidDisplayChar
	Function Returns     : void
	Function Arguments   : s8  A_s8Row       ,
                           s8  A_s8Col           ,
		                   s8  A_s8Char          ,
		                   u16 A_u16Foreground
	Function Description : drow char at row and col selected
*/
void HTFT_voidDisplayChar (u8 A_u8SpiType ,
		                   s8  A_s8Row         ,
		                   s8  A_s8Col         ,
						   s8  A_s8Char        ,
						   u16 A_u16Foreground);

/**
	Function Name        : HTFT_voidDisplayString
	Function Returns     : void
	Function Arguments   : s8  A_s8L_u8Row       ,
                           s8  A_s8Col           ,
		                   u8  A_s8String []     ,
		                   u16 A_u16Foreground
	Function Description : drow string started from row and col selected
*/
void HTFT_voidDisplayString (u8 A_u8SpiType ,
		                     s8  A_s8L_u8Row       ,
                             s8  A_s8Col           ,
		                     u8  A_s8String []     ,
		                     u16 A_u16Foreground ) ;
#endif /* HAL_TFT_TFT_INIT_H_ */
