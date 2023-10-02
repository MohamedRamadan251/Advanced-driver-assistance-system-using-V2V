/*
 * UART_conf.c
 *
 *  Created on: Oct 15, 2022
 *      Author: Mohammed Ramadan
 */



#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "UART_private.h"
#include "UART_configuration.h"
#include "UART_interface.h"

/* Configuration of MUART_Init */
USART_InitType MUART_Init =
{
		.BaudRate            = __BAUDRATE__     ,
		.DataWidth           = MODE_8BIT        ,
		.StopBits            = STOP_BIT_1       ,
		.Parity_Enable       = DISABLE          ,
		.Parity_Selection    = EVEN_PARITY      ,
		.TransferDirection   = TX_RX            ,
		.HardwareFlowControl = DISABLE          ,
		.Oversampling        = OVER_SAMPLING_16
} ;

/* Configuration of MUART_clock */
USART_ClockInitTypeDef MUART_clock =
{
		.ClockOutput       = DISABLE ,
		.ClockPolarity     = 0       ,
		.ClockPhase        = 0       ,
		.LastBitClockPulse = 0
};
