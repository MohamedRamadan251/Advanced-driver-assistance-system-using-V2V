/*
 * SPI_register.h
 *
 *  Created on: Sep 29, 2022
 *      Author: Mohammed Ramadan
 */

#ifndef MCAL_SPI_SPI_REGISTER_H_
#define MCAL_SPI_SPI_REGISTER_H_

/*define base address of SPI1*/
#define SPI1_BASE_ADDRESS  0x40013000

/*define base address of SPI2*/
#define SPI2_BASE_ADDRESS  0x40003800

/*define base address of SPI3*/
#define SPI3_BASE_ADDRESS  0x40003C00

/*define MSPI_MemMap_t*/
typedef struct
{
	volatile u32 CR1      ;
	volatile u32 CR2      ;
	volatile u32 SR       ;
	volatile u8  DR       ;
	volatile u8  REVERSE1 ;
	volatile u8  REVERSE2 ;
	volatile u8  REVERSE3 ;
	volatile u32 CRCPR    ;
	volatile u32 RXCRCR   ;
	volatile u32 TXCRCR   ;
	volatile u32 I2SCFGR  ;
	volatile u32 I2SPR    ;
}MSPI_MemMap_t;

/*define SPI1*/
#define SPI1 ((volatile MSPI_MemMap_t *)(SPI1_BASE_ADDRESS))

/*define SPI2*/
#define SPI2 ((volatile MSPI_MemMap_t *)(SPI2_BASE_ADDRESS))

/*define SPI3*/
#define SPI3 ((volatile MSPI_MemMap_t *)(SPI3_BASE_ADDRESS))

#endif /* MCAL_SPI_SPI_REGISTER_H_ */
