/*
 * NVIC_int.h
 *
 *  Created on: Sep 10, 2022
 *      Author: Mohammed Ramadan
 */

#ifndef MCAL_NVIC_NVIC_INT_H_
#define MCAL_NVIC_NVIC_INT_H_

/*define group and subgroup periority*/
#define GROUP_4BITS   0b011 /*16 Group priorities , 0  Sub priorities*/
#define GROUP_3BITS   0b100 /*8  Group priorities , 2  Sub priorities*/
#define GROUP_2BITS   0b101 /*4  Group priorities , 4  Sub priorities*/
#define GROUP_1BITS   0b110 /*2  Group priorities , 8  Sub priorities*/
#define GROUP_0BITS   0b111 /*0  Group priorities , 16 Sub priorities*/

/*define system handelerd periority*/
#define MEMORY_MANAGE  -6
#define BUS_FAULT      -5
#define USAGE_FAULT    -4
#define SV_CALL        -3
#define PEND_SV        -2
#define SYSTICK        -1

/*define positions of peripheral at NVIC*/
#define WWDG               0
#define EXTI16             1
#define EXTI21             2
#define EXTI22             3
#define FLASH              4
#define RCC                5
#define EXTI0              6
#define EXTI1              7
#define EXTI2              8
#define EXTI3              9
#define EXTI4              10
#define DMA1_STREAM0       11
#define DMA1_STREAM1       12
#define DMA1_STREAM2       13
#define DMA1_STREAM3       14
#define DMA1_STREAM4       15
#define DMA1_STREAM5       16
#define DMA1_STREAM6       17
#define ADC                18
#define EXTI5              23
#define EXTI6              23
#define EXTI7              23
#define EXTI8              23
#define EXTI9              23
#define TIM1_BRK_TIM9      24
#define TIM1_UP_TIM10      25
#define TIM1_TRG_COM_TIM11 26
#define TIM1_CC            27
#define TIM2               28
#define TIM3               29
#define TIM4               30
#define I2C1_EV            31
#define I2C1_ER            32
#define I2C2_EV            33
#define I2C2_ER            34
#define SPI1               35
#define SPI2               36
#define USART1             37
#define USART2             38
#define EXTI10             40
#define EXTI11             40
#define EXTI12             40
#define EXTI13             40
#define EXTI14             40
#define EXTI15             40
#define EXTI17             41
#define EXTI18             42
#define DMA1_STREAM7       47
#define SDIO               49
#define TIM5               50
#define SPI3               51
#define DMA2_STREAM0       56
#define DMA2_STREAM1       57
#define DMA2_STREAM2       58
#define DMA2_STREAM3       59
#define DMA2_STREAM4       60
#define OTG_FS             67
#define DMA2_STREAM5       68
#define DMA2_STREAM6       69
#define DMA2_STREAM7       70
#define USART6             71
#define I2C3_EV            72
#define I2C3_ER            73
#define FPU                81
#define SPI4               84

/*define group periority*/
#define NO_GROUP_PRIORITY 0
#define GROUP_PRIORITY_0  0
#define GROUP_PRIORITY_1  1
#define GROUP_PRIORITY_2  2
#define GROUP_PRIORITY_3  3
#define GROUP_PRIORITY_4  4
#define GROUP_PRIORITY_5  5
#define GROUP_PRIORITY_6  6
#define GROUP_PRIORITY_7  7
#define GROUP_PRIORITY_8  8
#define GROUP_PRIORITY_9  9
#define GROUP_PRIORITY_10 10
#define GROUP_PRIORITY_11 11
#define GROUP_PRIORITY_12 12
#define GROUP_PRIORITY_13 13
#define GROUP_PRIORITY_14 14
#define GROUP_PRIORITY_15 15

/*define sub periority*/
#define NO_SUB_PRIORITY   0
#define SUB_PRIORITY_0    0
#define SUB_PRIORITY_1    1
#define SUB_PRIORITY_2    2
#define SUB_PRIORITY_3    3
#define SUB_PRIORITY_4    4
#define SUB_PRIORITY_5    5
#define SUB_PRIORITY_6    6
#define SUB_PRIORITY_7    7
#define SUB_PRIORITY_8    8
#define SUB_PRIORITY_9    9
#define SUB_PRIORITY_10   10
#define SUB_PRIORITY_11   11
#define SUB_PRIORITY_12   12
#define SUB_PRIORITY_13   13
#define SUB_PRIORITY_14   14
#define SUB_PRIORITY_15   15

/**
	Function Name        : MNVIC_voidEnablePeripheral
	Function Returns     : void
	Function Arguments   : u8 A_u8InterruptId
	Function Description : enable PIE of peripheral
*/
void MNVIC_voidEnablePeripheral (u8 A_u8InterruptId) ;

/**
	Function Name        : MNVIC_voidDisablePeripheral
	Function Returns     : void
	Function Arguments   : u8 A_u8InterruptId
	Function Description : disable PIE of peripheral
*/
void MNVIC_voidDisablePeripheral (u8 A_u8InterruptId) ;

/**
	Function Name        : MNVIC_voidSetPendingFlag
	Function Returns     : void
	Function Arguments   : u8 A_u8InterruptId
	Function Description : enable pending flag
*/
void MNVIC_voidSetPendingFlag (u8 A_u8InterruptId) ;

/**
	Function Name        : MNVIC_voidClrPendingFlag
	Function Returns     : void
	Function Arguments   : u8 A_u8InterruptId
	Function Description : disable pending flag
*/
void MNVIC_voidClrPendingFlag (u8 A_u8InterruptId) ;

/**
	Function Name        : MVNIC_u8GetActiveFlagStatues
	Function Returns     : u8
	Function Arguments   : u8 A_u8InterruptId
	Function Description : read statues of active flag
*/
u8   MVNIC_u8GetActiveFlagStatues (u8 A_u8InterruptId) ;

/**
	Function Name        : MNVIC_voidSetPriorityConfig
	Function Returns     : void
	Function Arguments   : u8 A_u8InterruptId
	Function Description : set the groubs and sub periority config
	Options              : GROUP_4BITS , GROUP_3BITS , GROUP_2BITS , GROUP_1BITS , GROUP_0BITS
*/
void MNVIC_voidSetPriorityConfig(u8 A_u8PriorityOption) ;

/**
	Function Name        : MNVIC_voidSetPriority
	Function Returns     : void
	Function Arguments   : u8 A_u8InterruptId, u8 A_u8GroupPriority, u8 A_u8SubPriority
	Function Description : set the groubs and sub periority for required interrupt
	Options for Copy_u8GroupPriority:- GROUP_PRIORITY_0 ... GROUP_PRIORITY_15
    Options for Copy_u8SubPriority  :- SUB_PRIORITY_0   ... SUB_PRIORITY_15
*/
void MNVIC_voidSetPriority(s8 A_s8InterruptId, u8 A_u8GroupPriority, u8 A_u8SubPriority) ;

#endif /* MCAL_NVIC_NVIC_INT_H_ */
