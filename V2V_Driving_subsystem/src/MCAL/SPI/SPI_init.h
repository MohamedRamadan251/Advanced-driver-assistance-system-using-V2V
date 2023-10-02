/*
 * SPI_init.h
 *
 *  Created on: Sep 29, 2022
 *      Author: Mohammed Ramadan
 */

#ifndef MCAL_SPI_SPI_INIT_H_
#define MCAL_SPI_SPI_INIT_H_

/*define type of SPI*/
#define SPI1_Type  1
#define SPI2_Type  2
#define SPI3_Type  3

/**
	Function Name        : MSPI_voidInit
	Function Returns     : void
	Function Arguments   : u8 A_u8SpiType
	Function Description : initialize the  selected SPI
*/
void MSPI_voidInit (u8 A_u8SpiType) ;

/**
	Function Name        : MSPI_voidTransmite
	Function Returns     : void
	Function Arguments   : u8 A_u8SpiType , u32 A_u32Data
	Function Description : send data
*/
void  MSPI_voidTransmite (u8 A_u8SpiType , u32 A_u32Data) ;

/**
	Function Name        : MSPI_voidRecive
	Function Returns     : u32
	Function Arguments   : u8 A_u8SpiType
	Function Description : recive data
*/
u32  MSPI_32Recive (u8 A_u8SpiType) ;
#endif /* MCAL_SPI_SPI_INIT_H_ */
