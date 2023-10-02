/*
 * SPI_private.h
 *
 *  Created on: Sep 29, 2022
 *      Author: Mohammed Ramadan
 */

#ifndef MCAL_SPI_SPI_PRIVATE_H_
#define MCAL_SPI_SPI_PRIVATE_H_

#define CPHA     0
#define CPOL     1
#define MSTR     2
#define SPE      6
#define LSBFIRST 7
#define SSI      8
#define SSM      9
#define DFF      11

#define BSY      7

/*define SETUP_SAMPLE_SELECTION*/
#define SAMPLE_RISING_SETUP_FALING  1
#define SETUP_RISING_SAMPLE_FALING  2
#define SAMPLE_FALING_SETUP_RISING  3
#define SETUP_FALING_SAMPLE_RISING  4

/*define Master/Slave mode*/
#define MASTER  1
#define SLAVE   2

/*define MSB and LSB to select SPI1_FIRST_BIT*/
#define MSB   1
#define LSB   2

/*define _8BITS and _16BITS to select SPI1_DATA_FORMATE*/
#define _8BITS  1
#define _16BITS 2

/*define boud rate of SPI*/
#define Fclk_DIV_2    0
#define Fclk_DIV_4    1
#define Fclk_DIV_8    2
#define Fclk_DIV_16   3
#define Fclk_DIV_32   4
#define Fclk_DIV_64   5
#define Fclk_DIV_128  6
#define Fclk_DIV_256  7

#endif /* MCAL_SPI_SPI_PRIVATE_H_ */
