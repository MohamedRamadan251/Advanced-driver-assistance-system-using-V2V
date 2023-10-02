/*
 * SPI_prog.c
 *
 *  Created on: Sep 29, 2022
 *      Author: Mohammed Ramadan
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/RCC/RCC_int.h"
#include "../../MCAL/GPIO/GPIO_init.h"
#include "SPI_conf.h"
#include "SPI_private.h"
#include "SPI_register.h"
#include "SPI_init.h"

extern MGPIO_Config_t config_pin_Alt_fun ;
extern MGPIO_Config_t config_input_pin_pull_up ;
void MSPI_voidInit (u8 A_u8SpiType)
{
	/*initial RCC*/
	MRCC_voidInit ( );
	/*Enable GPIOA from RCC*/
	MRCC_voidEnablePerephiralClock(RCC_AHB1 , RCC_EN_GPIOA) ;
	/*Enable GPIOB from RCC*/
	MRCC_voidEnablePerephiralClock(RCC_AHB1 , RCC_EN_GPIOB) ;
	switch (A_u8SpiType)
	{
	case SPI1_Type :
		/*Enable RCC for SPI1*/
		MRCC_voidEnablePerephiralClock (RCC_APB2, RCC_EN_SPI1);

		/*configer MOSI1 as alt fun*/
		MGPIO_voidInit(&config_pin_Alt_fun , GPIO_PORTA , GPIO_PIN7) ;
		MGPIO_voidSetAltFun (GPIO_PORTA , GPIO_PIN7 , ALT_FUN_5) ;

		/*configer MISO1 as alt fun*/
		MGPIO_voidInit(&config_pin_Alt_fun , GPIO_PORTA , GPIO_PIN6) ;
		MGPIO_voidSetAltFun (GPIO_PORTA , GPIO_PIN6 , ALT_FUN_5) ;

		/*configer Sck1 as alt fun*/
		MGPIO_voidInit(&config_pin_Alt_fun , GPIO_PORTA , GPIO_PIN5) ;
		MGPIO_voidSetAltFun (GPIO_PORTA , GPIO_PIN5 , ALT_FUN_5) ;

        #if   SPI1_MODE == SLAVE
              MGPIO_voidInit(&config_input_pin_pull_up , GPIO_PORTA , GPIO_PIN4) ;
        #endif

		/* SPI Mode: CPHA and CPOL */
        #if   SPI1_SETUP_SAMPLE_SELECTION == SAMPLE_RISING_SETUP_FALING
	          CLR_BIT(SPI1->CR1, CPHA);
	          CLR_BIT(SPI1->CR1, CPOL);
        #elif SPI1_SETUP_SAMPLE_SELECTION == SETUP_RISING_SAMPLE_FALING
		      SET_BIT(SPI1->CR1, CPHA);
	          CLR_BIT(SPI1->CR1, CPOL);
        #elif SPI1_SETUP_SAMPLE_SELECTION == SAMPLE_FALING_SETUP_RISING
	          CLR_BIT(SPI1->CR1, CPHA);
			  SET_BIT(SPI1->CR1, CPOL);
        #elif SPI1_SETUP_SAMPLE_SELECTION == SETUP_FALING_SAMPLE_RISING
			  SET_BIT(SPI1->CR1, CPHA);
			  SET_BIT(SPI1->CR1, CPOL);
        #else
              #error "select correct option of SETUP_SELECTION"
        #endif

	    /* Select Master/Slave Mode */
		#if   SPI1_MODE == MASTER
		      SET_BIT(SPI1->CR1, MSTR);
		      SET_BIT(SPI1->CR1, SSM);
		#elif SPI1_MODE == SLAVE
		      CLR_BIT(SPI1->CR1, MSTR);
		      CLR_BIT(SPI1->CR1, SSM);
		#else
		      #error "select correct option of SPI1_MODE"
		#endif

		/* Select Baud Rate Prescaler */
	    SPI1->CR1 = (SPI1->CR1 &~(0b111<<3)) | (SPI1_BAUDRATE<<3) ;

	    /* MSB/LSB first */
        #if   SPI1_FIRST_BIT == MSB
			  CLR_BIT(SPI1->CR1, LSBFIRST);
        #elif SPI1_FIRST_BIT == LSB
			  SET_BIT(SPI1->CR1, LSBFIRST);
        #else
              #error "select correct option of SPI1_FIRST_BIT"
        #endif

   	 	SET_BIT(SPI1->CR1, SSI);

   	    /* Data Format */
        #if   SPI1_DATA_FORMATE == _8BITS
   	          CLR_BIT(SPI1->CR1, DFF);
        #elif SPI1_DATA_FORMATE == _16BITS
   	          SET_BIT(SPI1->CR1, DFF);
        #else
              #error "select correct option of SPI1_DATA_FORMATE"
        #endif

   	    /* un using DMA or Interrupt*/
   	    SPI1->CR2 = 0 ;

   	    /* ENABLE SPI1 PERIPHERAL */
     	SET_BIT(SPI1->CR1, SPE);
		break ;
	case SPI2_Type :
		/*Enable RCC for SPI2*/
		MRCC_voidEnablePerephiralClock (RCC_APB1, RCC_EN_SPI2);

		/*configer MOSI2 as alt fun*/
		MGPIO_voidInit(&config_pin_Alt_fun , GPIO_PORTB , GPIO_PIN15) ;
		MGPIO_voidSetAltFun (GPIO_PORTB , GPIO_PIN15 , ALT_FUN_5) ;

		/*configer MISO2 as alt fun*/
		MGPIO_voidInit(&config_pin_Alt_fun , GPIO_PORTB , GPIO_PIN14) ;
		MGPIO_voidSetAltFun (GPIO_PORTB , GPIO_PIN14 , ALT_FUN_5) ;

		/*configer Sck2 as alt fun*/
		MGPIO_voidInit(&config_pin_Alt_fun , GPIO_PORTB , GPIO_PIN13) ;
		MGPIO_voidSetAltFun (GPIO_PORTB , GPIO_PIN13 , ALT_FUN_5) ;

        #if   SPI2_MODE == SLAVE
		      MGPIO_voidInit(&config_input_pin_pull_up , GPIO_PORTB , GPIO_PIN12) ;
        #endif

		/* SPI Mode: CPHA and CPOL */
		#if   SPI2_SETUP_SAMPLE_SELECTION == SAMPLE_RISING_SETUP_FALING
		      CLR_BIT(SPI2->CR1, CPHA);
		      CLR_BIT(SPI2->CR1, CPOL);
		#elif SPI2_SETUP_SAMPLE_SELECTION == SETUP_RISING_SAMPLE_FALING
		      SET_BIT(SPI2->CR1, CPHA);
		      CLR_BIT(SPI2->CR1, CPOL);
		#elif SPI2_SETUP_SAMPLE_SELECTION == SAMPLE_FALING_SETUP_RISING
		      CLR_BIT(SPI2->CR1, CPHA);
		      SET_BIT(SPI2->CR1, CPOL);
	    #elif SPI2_SETUP_SAMPLE_SELECTION == SETUP_FALING_SAMPLE_RISING
		      SET_BIT(SPI2->CR1, CPHA);
		      SET_BIT(SPI2->CR1, CPOL);
		#else
		    #error "select correct option of SETUP_SELECTION"
		#endif

		/* Select Master/Slave Mode */
		#if   SPI2_MODE == MASTER
		      SET_BIT(SPI2->CR1, MSTR);
		      SET_BIT(SPI2->CR1, SSM);
		#elif SPI2_MODE == SLAVE
		      CLR_BIT(SPI2->CR1, MSTR);
		      CLR_BIT(SPI2->CR1, SSM);
		#else
		      #error "select correct option of SPI2_MODE"
		#endif

		/* Select Baud Rate Prescaler */
	    SPI2->CR1 = (SPI2->CR1 &~(0b111<<3)) | (SPI2_BAUDRATE<<3) ;

	    /* MSB/LSB first */
        #if   SPI2_FIRST_BIT == MSB
			  CLR_BIT(SPI2->CR1, LSBFIRST);
        #elif SPI2_FIRST_BIT == LSB
			  SET_BIT(SPI2->CR1, LSBFIRST);
        #else
              #error "select correct option of SPI2_FIRST_BIT"
        #endif

   	 	SET_BIT(SPI2->CR1, SSI);

   	    /* Data Format */
        #if   SPI2_DATA_FORMATE == _8BITS
   	          CLR_BIT(SPI2->CR1, DFF);
        #elif SPI2_DATA_FORMATE == _16BITS
   	          SET_BIT(SPI2->CR1, DFF);
        #else
              #error "select correct option of SPI2_DATA_FORMATE"
        #endif

   	    /* ENABLE SPI2 PERIPHERAL */
     	SET_BIT(SPI2->CR1, SPE);
		break ;
	case SPI3_Type :
		/*Enable RCC for SPI3*/
		MRCC_voidEnablePerephiralClock (RCC_APB1, RCC_EN_SPI3);

		/*configer MOSI3 as alt fun*/
		MGPIO_voidInit(&config_pin_Alt_fun , GPIO_PORTB , GPIO_PIN5) ;
		MGPIO_voidSetAltFun (GPIO_PORTB , GPIO_PIN5 , ALT_FUN_6) ;

		/*configer MISO3 as alt fun*/
		MGPIO_voidInit(&config_pin_Alt_fun , GPIO_PORTB , GPIO_PIN4) ;
		MGPIO_voidSetAltFun (GPIO_PORTB , GPIO_PIN4 , ALT_FUN_6) ;

		/*configer Sck3 as alt fun*/
		MGPIO_voidInit(&config_pin_Alt_fun , GPIO_PORTB , GPIO_PIN3) ;
		MGPIO_voidSetAltFun (GPIO_PORTB , GPIO_PIN3 , ALT_FUN_6) ;

        #if   SPI3_MODE == SLAVE
              MGPIO_voidInit(&config_input_pin_pull_up , GPIO_PORTA , GPIO_PIN15) ;
        #endif

		/* SPI Mode: CPHA and CPOL */
		#if   SPI3_SETUP_SAMPLE_SELECTION == SAMPLE_RISING_SETUP_FALING
		      CLR_BIT(SPI3->CR1, CPHA);
		      CLR_BIT(SPI3->CR1, CPOL);
		#elif SPI3_SETUP_SAMPLE_SELECTION == SETUP_RISING_SAMPLE_FALING
		      SET_BIT(SPI3->CR1, CPHA);
		      CLR_BIT(SPI3->CR1, CPOL);
		#elif SPI3_SETUP_SAMPLE_SELECTION == SAMPLE_FALING_SETUP_RISING
		      CLR_BIT(SPI3->CR1, CPHA);
		      SET_BIT(SPI3->CR1, CPOL);
	    #elif SPI3_SETUP_SAMPLE_SELECTION == SETUP_FALING_SAMPLE_RISING
		      SET_BIT(SPI3->CR1, CPHA);
		      SET_BIT(SPI3->CR1, CPOL);
		#else
		    #error "select correct option of SETUP_SELECTION"
		#endif

		/* Select Master/Slave Mode */
		#if   SPI3_MODE == MASTER
		      SET_BIT(SPI3->CR1, MSTR);
		      SET_BIT(SPI3->CR1, SSM);
		#elif SPI3_MODE == SLAVE
		      CLR_BIT(SPI3->CR1, MSTR);
		      CLR_BIT(SPI3->CR1, SSM);
		#else
		      #error "select correct option of SPI3_MODE"
		#endif

		/* Select Baud Rate Prescaler */
		SPI3->CR1 = (SPI3->CR1 &~(0b111<<3)) | (SPI3_BAUDRATE<<3) ;

	    /* MSB/LSB first */
        #if   SPI3_FIRST_BIT == MSB
			  CLR_BIT(SPI3->CR1, LSBFIRST);
        #elif SPI3_FIRST_BIT == LSB
			  SET_BIT(SPI3->CR1, LSBFIRST);
        #else
              #error "select correct option of SPI3_FIRST_BIT"
        #endif

   	 	SET_BIT(SPI3->CR1, SSI);

   	    /* Data Format */
        #if   SPI3_DATA_FORMATE == _8BITS
   	          CLR_BIT(SPI3->CR1, DFF);
        #elif SPI3_DATA_FORMATE == _16BITS
   	          SET_BIT(SPI3->CR1, DFF);
        #else
              #error "select correct option of SPI3_DATA_FORMATE"
        #endif

   	    /* ENABLE SPI3 PERIPHERAL */
     	SET_BIT(SPI3->CR1, SPE);
		break ;
	default :
		break ;
		/*Error case of A_u8SpiType*/
	}
}

void  MSPI_voidTransmite (u8 A_u8SpiType , u8 A_u8Data)
{
	switch (A_u8SpiType)
	{
	case SPI1_Type :
		/*store data at data register to be sent*/
		SPI1->DR = A_u8Data ;
		/*wait till data be transmitted*/
		while(READ_BIT(SPI1->SR, BSY) == 1)
		{
			asm("NOP");
		}

		break ;

	case SPI2_Type :
		/*store data at data register to be sent*/
		SPI2->DR = A_u8Data ;
		/*wait till data be transmitted*/
		while(READ_BIT(SPI2->SR, BSY) == 1)
		{
			asm("NOP");
		}

		break ;

	case SPI3_Type :
		/*store data at data register to be sent*/
		SPI3->DR = A_u8Data ;
		/*wait till data be transmitted*/
		while(READ_BIT(SPI3->SR, BSY) == 1)
		{
			asm("NOP");
		}

		break ;

	default :
		/*ERROR Type of SPI*/
		break ;
	}
}

u8  MSPI_u8Recive (u8 A_u8SpiType)
{
	u8 L_u8DataReturned = 0 ;
	switch (A_u8SpiType)
	{
	case SPI1_Type :
		/*recive data from data register*/
		L_u8DataReturned = SPI1->DR ;
		break ;

	case SPI2_Type :
		/*recive data from data register*/
		L_u8DataReturned = SPI2->DR ;
		break ;

	case SPI3_Type :
		/*recive data from data register*/
		L_u8DataReturned = SPI3->DR ;
		break ;

	default :
		/*ERROR Type of SPI*/
		break ;
	}
	return L_u8DataReturned ;
}
