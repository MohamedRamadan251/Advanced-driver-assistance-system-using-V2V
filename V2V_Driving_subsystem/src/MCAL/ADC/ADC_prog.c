/*
 * ADC_prog.c
 *
 *  Created on: Feb 24, 2023
 *      Author: Mohammed Ramadan
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../RCC/RCC_int.h"
#include "../GPIO/GPIO_init.h"
#include "../NVIC/NVIC_int.h"

#include "ADC_private.h"
#include "ADC_register.h"
#include "ADC_conf.h"
#include "ADC_init.h"

extern MGPIO_Config_t config_input_pin_analog ;

/**pointer to function to set call back of ADC*/
void (*ADC_Callback) (void) ;

void MADC_voidInit (void)
{
	/* initialization RCC */
	MRCC_voidInit() ;

	/* Enable pinout of ADC (PortA , PORTB) from RCC */
	MRCC_voidEnablePerephiralClock(RCC_AHB1 , RCC_EN_GPIOA) ;
	MRCC_voidEnablePerephiralClock(RCC_AHB1 , RCC_EN_GPIOB) ;

	/* Enable of ADC1 from RCC */
	MRCC_voidEnablePerephiralClock(RCC_APB2 , RCC_EN_ADC1) ;

	/* Enable of ADC1 from NVIC */
	MNVIC_voidEnablePeripheral (ADC) ;

	/* Enable/Disable the Interrept for End of conversion */
    #if ADC_INTERRUPT == ENABLE_INTERRUPT
    	SET_BIT(ADC1->CR1 , ADC_CR1_EOCIE_BIT) ;
    #elif ADC_INTERRUPT == DISABLE_INTERRUPT
    	CLR_BIT(ADC1->CR1 , ADC_CR1_EOCIE_BIT) ;
    #else
        #error "invalid chooice of ADC_INTERRUPT"
    #endif

	/* Set the ADC clock prescaler */
    #if   ADC_PRESCALLER == ADC_PRESCALLER_BY_2
	      CLR_BIT (ADC1->CCR , ADC_CR2_ADCPRE_BIT0) ;
	      CLR_BIT (ADC1->CCR , ADC_CR2_ADCPRE_BIT1) ;
    #elif ADC_PRESCALLER == ADC_PRESCALLER_BY_4
	      SET_BIT (ADC1->CCR , ADC_CR2_ADCPRE_BIT0) ;
	      CLR_BIT (ADC1->CCR , ADC_CR2_ADCPRE_BIT1) ;
    #elif ADC_PRESCALLER == ADC_PRESCALLER_BY_6
	      CLR_BIT (ADC1->CCR , ADC_CR2_ADCPRE_BIT0) ;
	      SET_BIT (ADC1->CCR , ADC_CR2_ADCPRE_BIT1) ;
    #elif ADC_PRESCALLER == ADC_PRESCALLER_BY_8
	      SET_BIT (ADC1->CCR , ADC_CR2_ADCPRE_BIT0) ;
	      SET_BIT (ADC1->CCR , ADC_CR2_ADCPRE_BIT1) ;
    #else
          #error "invalid choise of ADC_PRESCALLER"
    #endif

	/* Set ADC scan mode */
	SET_BIT (ADC1->CR1 , ADC_CR1_SCAN_BIT) ;

	/* Set ADC resolution */
    #if   ADC_RESOLUTION == ADC_RESOLUTION_12_BIT
	      CLR_BIT (ADC1->CR1 , ADC_CR1_RES_BIT0) ;
	      CLR_BIT (ADC1->CR1 , ADC_CR1_RES_BIT1) ;
    #elif ADC_RESOLUTION == ADC_RESOLUTION_10_BIT
	      SET_BIT (ADC1->CR1 , ADC_CR1_RES_BIT0) ;
	      CLR_BIT (ADC1->CR1 , ADC_CR1_RES_BIT1) ;
    #elif ADC_RESOLUTION == ADC_RESOLUTION_8_BIT
	      CLR_BIT (ADC1->CR1 , ADC_CR1_RES_BIT0) ;
	      SET_BIT (ADC1->CR1 , ADC_CR1_RES_BIT1) ;
    #elif ADC_RESOLUTION == ADC_RESOLUTION_6_BIT
	      SET_BIT (ADC1->CR1 , ADC_CR1_RES_BIT0) ;
	      SET_BIT (ADC1->CR1 , ADC_CR1_RES_BIT1) ;
    #else
    #error "invalid choise of ADC_RESOLUTION"
    #endif

	/*Data alignment (right) */
	CLR_BIT (ADC1->CR2 , ADC_CR2_ALIGN_BIT) ;

	/* Reset the external trigger */
	CLR_BIT(ADC1->CR2 , ADC_CR2_EXTEN_BIT0) ;
	CLR_BIT(ADC1->CR2 , ADC_CR2_EXTEN_BIT1) ;

	/* Enable ADC continuous conversion mode */
	CLR_BIT(ADC1->CR2 , ADC_CR2_CONT_BIT) ;

	/* Enable the selected ADC regular discontinuous mode */
	SET_BIT(ADC1->CR1 , ADC_CR1_DISCEN_BIT) ;

	/* Set the number of channels to be converted in discontinuous mode */
	ADC1->CR1 &= ~(ALL_NUMBER_OF_CHANNEL_TO_BE_CONVERTED << ADC_CR1_DISCNUM_BIT0) ;
    #if   NUMBER_OF_CHANNEL_TO_BE_CONVERTED == 1
	      CLR_BIT(ADC1->CR1 , ADC_CR1_DISCNUM_BIT0) ;
	      CLR_BIT(ADC1->CR1 , ADC_CR1_DISCNUM_BIT1) ;
	      CLR_BIT(ADC1->CR1 , ADC_CR1_DISCNUM_BIT2) ;
    #elif NUMBER_OF_CHANNEL_TO_BE_CONVERTED == 2
	      SET_BIT(ADC1->CR1 , ADC_CR1_DISCNUM_BIT0) ;
	      CLR_BIT(ADC1->CR1 , ADC_CR1_DISCNUM_BIT1) ;
	      CLR_BIT(ADC1->CR1 , ADC_CR1_DISCNUM_BIT2) ;
    #elif NUMBER_OF_CHANNEL_TO_BE_CONVERTED == 3
	      CLR_BIT(ADC1->CR1 , ADC_CR1_DISCNUM_BIT0) ;
	      SET_BIT(ADC1->CR1 , ADC_CR1_DISCNUM_BIT1) ;
	      CLR_BIT(ADC1->CR1 , ADC_CR1_DISCNUM_BIT2) ;
    #elif NUMBER_OF_CHANNEL_TO_BE_CONVERTED == 4
	      SET_BIT(ADC1->CR1 , ADC_CR1_DISCNUM_BIT0) ;
	      SET_BIT(ADC1->CR1 , ADC_CR1_DISCNUM_BIT1) ;
	      CLR_BIT(ADC1->CR1 , ADC_CR1_DISCNUM_BIT2) ;
    #elif NUMBER_OF_CHANNEL_TO_BE_CONVERTED == 5
	      CLR_BIT(ADC1->CR1 , ADC_CR1_DISCNUM_BIT0) ;
	      CLR_BIT(ADC1->CR1 , ADC_CR1_DISCNUM_BIT1) ;
	      SET_BIT(ADC1->CR1 , ADC_CR1_DISCNUM_BIT2) ;
    #elif NUMBER_OF_CHANNEL_TO_BE_CONVERTED == 6
	      SET_BIT(ADC1->CR1 , ADC_CR1_DISCNUM_BIT0) ;
	      CLR_BIT(ADC1->CR1 , ADC_CR1_DISCNUM_BIT1) ;
	      SET_BIT(ADC1->CR1 , ADC_CR1_DISCNUM_BIT2) ;
    #elif NUMBER_OF_CHANNEL_TO_BE_CONVERTED == 7
	      CLR_BIT(ADC1->CR1 , ADC_CR1_DISCNUM_BIT0) ;
	      SET_BIT(ADC1->CR1 , ADC_CR1_DISCNUM_BIT1) ;
	      SET_BIT(ADC1->CR1 , ADC_CR1_DISCNUM_BIT2) ;
    #elif NUMBER_OF_CHANNEL_TO_BE_CONVERTED == 8
	      SET_BIT(ADC1->CR1 , ADC_CR1_DISCNUM_BIT0) ;
	      SET_BIT(ADC1->CR1 , ADC_CR1_DISCNUM_BIT1) ;
	      SET_BIT(ADC1->CR1 , ADC_CR1_DISCNUM_BIT2) ;
    #else
          #error "invalid choise of NUMBER_OF_CHANNEL_TO_BE_CONVERTED"
    #endif

	/* Set ADC number of conversion */
	ADC1->SQR1 &= ~(REGULAR_CHANNEL_SEQUENCE_LENGTH << ADC_SQR1_L_BIT0);

	/* Enable the ADC peripheral */
	SET_BIT(ADC1->CR2 , ADC_CR2_ADON_BIT) ;

}

void MADC_voidConfigChannel (u8 A_u8ChannelNum , u8 A_u8SampleTime)
{
	if (A_u8ChannelNum < 10)/* ADC_Channel include in ADC_Channel_[0..9] */
	{
		if (A_u8SampleTime < 8)
		{
			/*configer ADC pin out as analog mode */
			switch (A_u8ChannelNum)
			{
			case ADC_CHANNEL_0 :
				MGPIO_voidInit(&config_input_pin_analog , GPIO_PORTA , GPIO_PIN0) ;
				break ;
			case ADC_CHANNEL_1 :
				MGPIO_voidInit(&config_input_pin_analog , GPIO_PORTA , GPIO_PIN1) ;
				break ;
			case ADC_CHANNEL_2 :
				MGPIO_voidInit(&config_input_pin_analog , GPIO_PORTA , GPIO_PIN2) ;
				break ;
			case ADC_CHANNEL_3 :
				MGPIO_voidInit(&config_input_pin_analog , GPIO_PORTA , GPIO_PIN3) ;
				break ;
			case ADC_CHANNEL_4 :
				MGPIO_voidInit(&config_input_pin_analog , GPIO_PORTA , GPIO_PIN4) ;
				break ;
			case ADC_CHANNEL_5 :
				MGPIO_voidInit(&config_input_pin_analog , GPIO_PORTA , GPIO_PIN5) ;
				break ;
			case ADC_CHANNEL_6 :
				MGPIO_voidInit(&config_input_pin_analog , GPIO_PORTA , GPIO_PIN6) ;
				break ;
			case ADC_CHANNEL_7 :
				MGPIO_voidInit(&config_input_pin_analog , GPIO_PORTA , GPIO_PIN7) ;
				break ;
			case ADC_CHANNEL_8 :
				MGPIO_voidInit(&config_input_pin_analog , GPIO_PORTB , GPIO_PIN0) ;
				break ;
			case ADC_CHANNEL_9 :
				MGPIO_voidInit(&config_input_pin_analog , GPIO_PORTB , GPIO_PIN1) ;
				break ;
			default :
				/*Error case*/
				break ;
			}

			/* Clear the old sample time */
			ADC1 ->SMPR2 &= ~(0x7U << (A_u8ChannelNum * 3U)) ;

			/* Set the new sample time */
			ADC1 ->SMPR2 &= ~(A_u8SampleTime << (A_u8ChannelNum * 3U)) ;

			/* set regular sequence for selected channel */
			ADC1 ->SQR3 = A_u8ChannelNum ;
		}
	}
}

void MADC_voidStartConversion (u8 A_u8ChannelNum)
{
	u8 L_u8StableDelay = ADC_STABLEZATION_DELAY ;

	/*Select Channel*/
	ADC1 ->SQR3 = A_u8ChannelNum ;

	/* Delay for ADC stabilization time */
	while (L_u8StableDelay != 0)
	{
		L_u8StableDelay -- ;
	}

	/* Enable the selected ADC software conversion for regular group */
	SET_BIT(ADC1->CR2 , ADC_CR2_SWSTART_BIT) ;
}

u32 MADC_u32GetValue (void)
{
	/* return ADC Data  */
	return ADC1->DR ;
}

u32 MADC_u32PollingToGetValue (u8 A_u8ChannelNum)
{
	/*start conversion and sslect channel*/
	MADC_voidStartConversion (A_u8ChannelNum) ;

	/*wait to end of conversion*/
	while(READ_BIT(ADC1->SR,ADC_SR_EOC_BIT)==0 );

	/*clear end of conversion flag*/
	CLR_BIT(ADC1->SR,ADC_SR_EOC_BIT) ;

	/* return ADC Data  */
	return ADC1->DR ;
}

void MADC_voidSetCallback( void (*A_fptr)(void)  )
{
	ADC_Callback = A_fptr;
}

/* IRQHandler for ADC */
void ADC_IRQHandler(void)
{
	if (ADC_Callback != Null)
	{
		ADC_Callback () ;

		/* Clear Regular channel start flag */
		CLR_BIT(ADC1->SR , ADC_SR_STRT_BIT) ;

		/* Clear Regular channel end of conversion */
		CLR_BIT(ADC1->SR , ADC_SR_EOC_BIT) ;
	}
}

