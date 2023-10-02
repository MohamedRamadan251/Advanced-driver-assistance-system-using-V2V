/*
 * RCC_int.h
 *
 *  Created on: Sep 2, 2022
 *      Author: Mohammed Ramadan
 */

#ifndef MCAL_RCC_RCC_INT_H_
#define MCAL_RCC_RCC_INT_H_

/*define buses to used in MRCC_voidEnablePerephiralClock and MRCC_voidDisablePerephiralClock*/
#define RCC_AHB1       1
#define RCC_AHB2       2
#define RCC_APB1       3
#define RCC_APB2       4

/*define peripheral at AHB1 bus*/
#define RCC_EN_GPIOA   0
#define RCC_EN_GPIOB   1
#define RCC_EN_GPIOC   2
#define RCC_EN_GPIOD   3
#define RCC_EN_GPIOE   4
#define RCC_EN_GPIOH   7
#define RCC_EN_CRC     12
#define RCC_EN_FLITF   15
#define RCC_EN_SRAM1   16
#define RCC_EN_DMA1    21
#define RCC_EN_DMA2    22

/*define peripheral at AHB2 bus*/
#define RCC_EN_OTGFS   7

/*define peripheral at APB1 bus*/
#define RCC_EN_TIM2    0
#define RCC_EN_TIM3    1
#define RCC_EN_TIM4    2
#define RCC_EN_TIM5    3
#define RCC_EN_WWDG    11
#define RCC_EN_SPI2    14
#define RCC_EN_SPI3    15
#define RCC_EN_USART2  17
#define RCC_EN_I2C1    21
#define RCC_EN_I2C2    22
#define RCC_EN_I2C3    23
#define RCC_EN_PWR     28

/*define peripheral at APB2 bus*/
#define RCC_EN_TIM1    0
#define RCC_EN_USART1  4
#define RCC_EN_USART6  5
#define RCC_EN_ADC1    8
#define RCC_EN_SDIO    11
#define RCC_EN_SPI1    12
#define RCC_EN_SPI4    13
#define RCC_EN_SYSCFG  14
#define RCC_EN_TIM9    16
#define RCC_EN_TIM10   17
#define RCC_EN_TIM11   18

/**
	Function Name        : MRCC_voidInit
	Function Returns     : void
	Function Arguments   : void
	Function Description : initialize the  RCC Peripheral
*/
void MRCC_voidInit (void) ;

/**
	Function Name        : MRCC_voidEnablePerephiralClock
	Function Returns     : void
	Function Arguments   : u32 A_u32BusId, u32 A_u32Periph
	Function Description : enaple the selected Peripheral
*/
void MRCC_voidEnablePerephiralClock (u32 A_u32BusId, u32 A_u32PeripheralId) ;

/**
	Function Name        : MRCC_voidDisablePerephiralClock
	Function Returns     : void
	Function Arguments   : u32 A_u32BusId, u32 A_u32PeripheralId
	Function Description : disaple the selected Peripheral
*/
void MRCC_voidDisablePerephiralClock (u32 A_u32BusId, u32 A_u32PeripheralId) ;

#endif /* MCAL_RCC_RCC_INT_H_ */
