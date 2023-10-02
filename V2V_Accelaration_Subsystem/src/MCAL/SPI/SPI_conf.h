/*
 * SPI_conf.h
 *
 *  Created on: Sep 29, 2022
 *      Author: Mohammed Ramadan
 */

#ifndef MCAL_SPI_SPI_CONF_H_
#define MCAL_SPI_SPI_CONF_H_

/**********************************************************************/
/*                      SPI1                                          */
/**********************************************************************/

/*select when setup and when sample
 *Options
 **SAMPLE_RISING_SETUP_FALING
 **SETUP_RISING_SAMPLE_FALING
 **SAMPLE_FALING_SETUP_RISING
 **SETUP_FALING_SAMPLE_RISING
 */
#define SPI1_SETUP_SAMPLE_SELECTION   SETUP_FALING_SAMPLE_RISING

/*select mode of SPI1
 *Options
 **MASTER
 **SLAVE
 */
#define SPI1_MODE  MASTER

/*select SPI1_FIRST_BIT
 *Options
 **MSB
 **LSB
 */
#define SPI1_FIRST_BIT MSB

/*select SPI1_DATA_FORMATE
 *Options
 **_8BITS
 **_16BITS
 */
#define SPI1_DATA_FORMATE  _8BITS

/*select SPI1_BAUDRATE
 *Options
 **Fclk_DIV_2
 **Fclk_DIV_4
 **Fclk_DIV_8
 **Fclk_DIV_16
 **Fclk_DIV_32
 **Fclk_DIV_64
 **Fclk_DIV_128
 **Fclk_DIV_256
 */
#define SPI1_BAUDRATE    Fclk_DIV_64


/**********************************************************************/
/*                      SPI2                                          */
/**********************************************************************/

/*select when setup and when sample
 *Options
 **SAMPLE_RISING_SETUP_FALING
 **SETUP_RISING_SAMPLE_FALING
 **SAMPLE_FALING_SETUP_RISING
 **SETUP_FALING_SAMPLE_RISING
 */
#define SPI2_SETUP_SAMPLE_SELECTION   SETUP_FALING_SAMPLE_RISING

/*select mode of SPI2
 *Options
 **MASTER
 **SLAVE
 */
#define SPI2_MODE  MASTER

/*select SPI2_FIRST_BIT
 *Options
 **MSB
 **LSB
 */
#define SPI2_FIRST_BIT MSB

/*select SPI2_DATA_FORMATE
 *Options
 **_8BITS
 **_16BITS
 */
#define SPI2_DATA_FORMATE  _8BITS

/*select SPI2_BAUDRATE
 *Options
 **Fclk_DIV_2
 **Fclk_DIV_4
 **Fclk_DIV_8
 **Fclk_DIV_16
 **Fclk_DIV_32
 **Fclk_DIV_64
 **Fclk_DIV_128
 **Fclk_DIV_256
 */
#define SPI2_BAUDRATE    Fclk_DIV_64


/**********************************************************************/
/*                      SPI3                                          */
/**********************************************************************/

/*select when setup and when sample
 *Options
 **SAMPLE_RISING_SETUP_FALING
 **SETUP_RISING_SAMPLE_FALING
 **SAMPLE_FALING_SETUP_RISING
 **SETUP_FALING_SAMPLE_RISING
 */
#define SPI3_SETUP_SAMPLE_SELECTION   SETUP_FALING_SAMPLE_RISING

/*select mode of SPI3
 *Options
 **MASTER
 **SLAVE
 */
#define SPI3_MODE  MASTER

/*select SPI3_FIRST_BIT
 *Options
 **MSB
 **LSB
 */
#define SPI3_FIRST_BIT MSB

/*select SPI3_DATA_FORMATE
 *Options
 **_8BITS
 **_16BITS
 */
#define SPI3_DATA_FORMATE  _8BITS

/*select SPI3_BAUDRATE
 *Options
 **Fclk_DIV_2
 **Fclk_DIV_4
 **Fclk_DIV_8
 **Fclk_DIV_16
 **Fclk_DIV_32
 **Fclk_DIV_64
 **Fclk_DIV_128
 **Fclk_DIV_256
 */
#define SPI3_BAUDRATE    Fclk_DIV_64
#endif /* MCAL_SPI_SPI_CONF_H_ */




