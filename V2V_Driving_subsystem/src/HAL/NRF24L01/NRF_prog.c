/*
 * NRF_prog.c
 *
 *  Created on: Apr 13, 2023
 *      Author: Mohammed Ramadan
 */


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/GPIO/GPIO_init.h"
#include "../../MCAL/SPI/SPI_init.h"
#include "../../MCAL/SYSTIC/SYSTIC_init.h"

#include "NRF_private.h"
#include "NRF_conf.h"
#include "NRF_init.h"

extern MGPIO_Config_t config_output_pin_push_pull ;

static void HNRF_voidCsSelect      (NRF24_t* A_xNRF24_conf) ;

static void HNRF_voidCsUnSelect    (NRF24_t* A_xNRF24_conf) ;

static void HNRF_voidCeEnable      (NRF24_t* A_xNRF24_conf) ;

static void HNRF_voidCeDisable     (NRF24_t* A_xNRF24_conf) ;

static void HNRF_voidSendCmd       (u8       A_u8SpiType    ,
		                            NRF24_t* A_xNRF24_conf  ,
		                            u8       A_u8Cmd      ) ;

static void HNRF_voidWriteReg      (u8       A_u8SpiType    ,
		                            NRF24_t* A_xNRF24_conf  ,
		                            u8       A_u8Reg        ,
		                            u8       A_u8Data     ) ;

static void HNRF_voidWriteRegMulti (u8       A_u8SpiType    ,
		                            NRF24_t* A_xNRF24_conf  ,
		                            u8       A_u8Reg        ,
							        u8       A_u8Data []    ,
		                            u8       A_u8Size     ) ;

static u8 HNRF_u8ReadReg           (u8       A_u8SpiType    ,
		                            NRF24_t* A_xNRF24_conf  ,
		                            u8       A_u8Reg      ) ;

static void HNRF_voidReadRegMulti  (u8       A_u8SpiType    ,
		                            NRF24_t* A_xNRF24_conf  ,
		                            u8       A_u8Reg        ,
		                            u8       A_u8Data []    ,
		                            u8       A_u8Size     ) ;



void HNRF_voidInit (u8 A_u8SpiType , NRF24_t* A_xNRF24_conf)
{
	/*initialize CE & CSN pins as output push pull*/
	MGPIO_voidInit(&config_output_pin_push_pull , A_xNRF24_conf->CE_PORT , A_xNRF24_conf->CE_PIN) ;
	MGPIO_voidInit(&config_output_pin_push_pull , A_xNRF24_conf->CSN_PORT , A_xNRF24_conf->CSN_PIN ) ;

	/*initialize systic timer*/
	MSTK_voidInit() ;

	/*initialize selected SPI*/
	MSPI_voidInit(A_u8SpiType) ;

	/*Disable CE before configurations*/
	HNRF_voidCeDisable  (A_xNRF24_conf) ;

	/*will be configured later*/
	HNRF_voidWriteReg (A_u8SpiType , A_xNRF24_conf , CONFIG     ,   0 ) ;
	/*NO Auto Ack*/
	HNRF_voidWriteReg (A_u8SpiType , A_xNRF24_conf , EN_AA      ,   0 ) ;
	/*Not Enabling nay data pipe right now*/
	HNRF_voidWriteReg (A_u8SpiType , A_xNRF24_conf , EN_RXADDR  ,   0 ) ;
	/*5 Bytes for the TX/RX address*/
	HNRF_voidWriteReg (A_u8SpiType , A_xNRF24_conf , SETUP_AW   , 0x03) ;
	/*No retransmition*/
	HNRF_voidWriteReg (A_u8SpiType , A_xNRF24_conf , SETUP_RETR ,   0 ) ;
	/*will be setup during TX or RX*/
	HNRF_voidWriteReg (A_u8SpiType , A_xNRF24_conf , RF_CH      ,   0 ) ;
	/*power = 0db , data rate = 2Mbps*/
	HNRF_voidWriteReg (A_u8SpiType , A_xNRF24_conf , RF_SETUP   , 0x0E) ;

	/*Enable CE after configurations*/
	HNRF_voidCeEnable  (A_xNRF24_conf) ;
}

void HNRF_voidTxMode (u8 A_u8SpiType , NRF24_t* A_xNRF24_conf , u8* A_u8Address , u8 A_u8Channel)
{
	u8 L_u8Config ;
	/*Disable CE before configurations*/
	HNRF_voidCeDisable  (A_xNRF24_conf) ;

	HNRF_voidWriteReg (A_u8SpiType , A_xNRF24_conf , RF_CH , A_u8Channel) ;
	HNRF_voidWriteRegMulti(A_u8SpiType , A_xNRF24_conf , TX_ADDR , A_u8Address , 5) ;

	/*power up the device*/
	L_u8Config = HNRF_u8ReadReg(A_u8SpiType , A_xNRF24_conf , CONFIG) ;
	L_u8Config = L_u8Config | (1<<1) ;
	HNRF_voidWriteReg (A_u8SpiType , A_xNRF24_conf , CONFIG , L_u8Config) ;

	/*Enable CE after configurations*/
	HNRF_voidCeEnable  (A_xNRF24_conf) ;
}

u8 HNRF_u8Transmit (u8 A_u8SpiType , NRF24_t* A_xNRF24_conf , u32 A_u32Data)
{
	u8 L_u8FifoStatus = 0 ;
	/*Disable CE before configurations*/
	HNRF_voidCeDisable  (A_xNRF24_conf) ;

	/*payload command*/
	MSPI_voidTransmite(A_u8SpiType , W_TX_PAYLOAD) ;
	/*send the payload*/
	MSPI_voidTransmite(A_u8SpiType , A_u32Data) ;

	/*Enable CE after configurations*/
	HNRF_voidCeEnable  (A_xNRF24_conf) ;

	MSTK_voidSetBusyWait(1) ;

	L_u8FifoStatus = HNRF_u8ReadReg(A_u8SpiType , A_xNRF24_conf , FIFO_STATUS) ;

	if ((L_u8FifoStatus & (1 << 4)) && (!(L_u8FifoStatus & (1 << 3))))
	{
		HNRF_voidSendCmd(A_u8SpiType , A_xNRF24_conf , FLUSH_TX) ;
		return 1 ;
	}
	return 0 ;
}

static void HNRF_voidCsSelect (NRF24_t* A_xNRF24_conf)
{
	MGPIO_voidSetPinValue(A_xNRF24_conf->CSN_PORT , A_xNRF24_conf->CSN_PIN , GPIO_LOW) ;
}

static void HNRF_voidCsUnSelect (NRF24_t* A_xNRF24_conf)
{
	MGPIO_voidSetPinValue(A_xNRF24_conf->CSN_PORT , A_xNRF24_conf->CSN_PIN , GPIO_HIGH) ;
}

static void HNRF_voidCeEnable (NRF24_t* A_xNRF24_conf)
{
	MGPIO_voidSetPinValue(A_xNRF24_conf->CE_PORT , A_xNRF24_conf->CE_PIN , GPIO_LOW) ;
}

static void HNRF_voidCeDisable (NRF24_t* A_xNRF24_conf)
{
	MGPIO_voidSetPinValue(A_xNRF24_conf->CE_PORT , A_xNRF24_conf->CE_PIN , GPIO_HIGH) ;
}

static void HNRF_voidSendCmd (u8 A_u8SpiType , NRF24_t* A_xNRF24_conf , u8 A_u8Cmd)
{
	/*low the CSN pin to select the device*/
	HNRF_voidCsSelect (A_xNRF24_conf) ;

	/*transmitting cmd*/
	MSPI_voidTransmite(A_u8SpiType , A_u8Cmd) ;

	/*pull the CSN pin high to release the device*/
	HNRF_voidCsUnSelect (A_xNRF24_conf) ;
}

static void HNRF_voidWriteReg (u8 A_u8SpiType , NRF24_t* A_xNRF24_conf , u8 A_u8Reg , u8 A_u8Data)
{
	u8 R_u8Buffer [SIZE_OF_BUFFER] ;
	R_u8Buffer [0] = A_u8Reg | (1 << 5) ;
	R_u8Buffer [1] = A_u8Data           ;

	/*low the CSN pin to select the device*/
	HNRF_voidCsSelect (A_xNRF24_conf) ;

	/*transmitting address of reg then data*/
	MSPI_voidTransmite(A_u8SpiType , R_u8Buffer [0]) ;
	MSPI_voidTransmite(A_u8SpiType , R_u8Buffer [1]) ;

	/*pull the CSN pin high to release the device*/
	HNRF_voidCsUnSelect (A_xNRF24_conf) ;
}

static void HNRF_voidWriteRegMulti (u8       A_u8SpiType ,
		                     NRF24_t* A_xNRF24_conf  ,
		                     u8       A_u8Reg     ,
							 u8       A_u8Data [] ,
		                     u8       A_u8Size
							 )
{
	u8 R_u8Buffer [SIZE_OF_BUFFER] ;
	R_u8Buffer [0] = A_u8Reg | (1 << 5) ;

	/*low the CSN pin to select the device*/
	HNRF_voidCsSelect (A_xNRF24_conf) ;

	/*transmitting address of reg then multi data*/
	MSPI_voidTransmite(A_u8SpiType , R_u8Buffer [0]) ;
	for (u8 L_u8Size = 0 ; L_u8Size < A_u8Size ; L_u8Size ++)
	{
		MSPI_voidTransmite(A_u8SpiType , A_u8Data [L_u8Size]) ;
	}

	/*pull the CSN pin high to release the device*/
	HNRF_voidCsUnSelect (A_xNRF24_conf) ;
}

static u8 HNRF_u8ReadReg (u8 A_u8SpiType , NRF24_t* A_xNRF24_conf , u8 A_u8Reg)
{
	u8 L_u8Data = 0 ;

	/*low the CSN pin to select the device*/
	HNRF_voidCsSelect (A_xNRF24_conf) ;

	/*transmitting address of reg then reciving data*/
	MSPI_voidTransmite(A_u8SpiType , A_u8Reg) ;
	L_u8Data = MSPI_32Recive(A_u8SpiType) ;

	/*pull the CSN pin high to release the device*/
	HNRF_voidCsUnSelect (A_xNRF24_conf) ;

	return L_u8Data ;
}

static void HNRF_voidReadRegMulti (u8       A_u8SpiType ,
		                    NRF24_t* A_xNRF24_conf  ,
		                    u8       A_u8Reg     ,
		                    u8       A_u8Data [] ,
		                    u8       A_u8Size
							)
{
    /*low the CSN pin to select the device*/
	HNRF_voidCsSelect (A_xNRF24_conf) ;

	/*transmitting address of reg then reciving multi data*/
	MSPI_voidTransmite(A_u8SpiType , A_u8Reg) ;

	for (u8 L_u8Size = 0 ; L_u8Size < A_u8Size ; L_u8Size ++)
	{
		A_u8Data [L_u8Size] = MSPI_32Recive(A_u8SpiType) ;
	}

	/*pull the CSN pin high to release the device*/
	HNRF_voidCsUnSelect (A_xNRF24_conf) ;
}
