/*
 * UART_interface.h
 *
 *  Created on: Oct 15, 2022
 *      Author: Mohammed Ramadan
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_


/**********************************************/
/* 			USART Register Structure 		  */
/**********************************************/
typedef struct{
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 BRR;
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 CR3;
	volatile u32 GTPR;
}USART_t;

/**********************************************/
/* 		The USART Structure Pointer 		  */
/**********************************************/
#define 	UART1 		((USART_t *)0x40011000)
#define 	UART2 		((USART_t *)0x40014400)
#define 	UART6 		((USART_t *)0x40011400)

typedef struct
{
	u32 BaudRate;
	u8 DataWidth;
	u8 StopBits;
	u8 Parity_Enable;
	u8 Parity_Selection;
	u8 TransferDirection; // TX_ONLY  RX_ONLY  TX_RX
	u8 HardwareFlowControl;
	u8 Oversampling;
}USART_InitType;

typedef struct
{
	u8 ClockOutput;
	u8 ClockPolarity;
	u8 ClockPhase;
	u8 LastBitClockPulse;
}USART_ClockInitTypeDef;

#define OVER_SAMPLING_16	0
#define OVER_SAMPLING_8 	1

#define TX_ONLY             0
#define RX_ONLY             1
#define TX_RX               2

#define EVEN_PARITY         0
#define ODD_PARITY          1

#define MODE_8BIT			0
#define MODE_9BIT			1

#define STOP_BIT_1			0
#define STOP_BIT_0_5		1
#define STOP_BIT_2			2
#define STOP_BIT_1_5		3

#define ENABLE				1
#define DISABLE				0

/**
	Function Name        : MUART_voidInit
	Function Returns     : void
	Function Arguments   : USART_InitType         *A_InitStruct      ,
	                       USART_ClockInitTypeDef *A_ClockInitStruct ,
	                       USART_t                *USARTx
	Function Description : initialize regusters of UART
*/
void MUART_voidInit(USART_InitType         *A_InitStruct      ,
		            USART_ClockInitTypeDef *A_ClockInitStruct ,
		            USART_t                *USARTx
					);

/**
	Function Name        : MUART_voidEnable
	Function Returns     : void
	Function Arguments   : USART_t *USARTx
	Function Description : Enable UART
*/
void MUART_voidEnable(USART_t *USARTx);

/**
	Function Name        : MUART_voidTransmitByte
	Function Returns     : void
	Function Arguments   : USART_t *USARTx,u8 A_u8Byte
	Function Description : Transmit one byte Synchronous
*/
void MUART_voidTransmitByte (USART_t *USARTx,u8 A_u8Byte);

/**
	Function Name        : MUART_voidTransmitString
	Function Returns     : void
	Function Arguments   : USART_t *USARTx, u8 * A_ptru8String
	Function Description : Transmit string Synchronous
*/
void MUART_voidTransmitString (USART_t *USARTx, u8 * A_ptru8String );

/**
	Function Name        : MUART_u8ReceiveByteSynchNonBlocking
	Function Returns     : u8
	Function Arguments   : USART_t *USARTx
	Function Description : recive one byte Synchronous non blocking
*/
u8 MUART_u8ReceiveByteSynchNonBlocking ( USART_t *USARTx );

/**
	Function Name        : MUART_ptrReceiveStringSynchNonBlocking
	Function Returns     : pointer to u8
	Function Arguments   : USART_t *USARTx
	Function Description : recive string Synchronous non blocking
*/
u8 * MUART_ptrReceiveStringSynchNonBlocking ( USART_t *USARTx );

/**
	Function Name        : MUART_RxIntSetStatus
	Function Returns     : void
	Function Arguments   : USART_t *USARTx, u8 A_u8Status
	Function Description : choose to enable RX interrupt or disable
*/
void MUART_RxIntSetStatus(USART_t *USARTx, u8 A_u8Status) ;

/**
	Function Name        : MUART_voidClearFlags
	Function Returns     : void
	Function Arguments   : USART_t *USARTx
	Function Description : clear all flags after RX interrupted
*/
void MUART_voidClearFlags(USART_t *USARTx) ;

/**
	Function Name        : MUART_u8ReadDataRegister
	Function Returns     : u8
	Function Arguments   : USART_t *USARTx
	Function Description : recive one byte Asynchronous
*/
u8 MUART_u8ReadDataRegister(USART_t *USARTx) ;

/**
	Function Name        : MUART1_voidSetCallBack
	Function Returns     : void
	Function Arguments   : void (*ptr) (void)
	Function Description : set call back function for UART1
*/
void MUART1_voidSetCallBack( void (*ptr) (void) ) ;

/**
	Function Name        : MUART2_voidSetCallBack
	Function Returns     : void
	Function Arguments   : void (*ptr) (void)
	Function Description : set call back function for UART2
*/
void MUART2_voidSetCallBack( void (*ptr) (void) ) ;

/**
	Function Name        : MUART6_voidSetCallBack
	Function Returns     : void
	Function Arguments   : void (*ptr) (void)
	Function Description : set call back function for UART6
*/
void MUART6_voidSetCallBack( void (*ptr) (void) ) ;

#endif /* UART_INTERFACE_H_ */
