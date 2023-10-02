/*
 * ADC_init.h
 *
 *  Created on: Feb 24, 2023
 *      Author: Mohammed Ramadan
 */

#ifndef MCAL_ADC_ADC_INIT_H_
#define MCAL_ADC_ADC_INIT_H_
/*
 * Define Channel Numbers
 */
#define ADC_CHANNEL_0   0
#define ADC_CHANNEL_1   1
#define ADC_CHANNEL_2   2
#define ADC_CHANNEL_3   3
#define ADC_CHANNEL_4   4
#define ADC_CHANNEL_5   5
#define ADC_CHANNEL_6   6
#define ADC_CHANNEL_7   7
#define ADC_CHANNEL_8   8
#define ADC_CHANNEL_9   9

/*
 * Define Sample Time
 */
#define ADC_SAMPLE_3_CYCLES     0
#define ADC_SAMPLE_15_CYCLES    1
#define ADC_SAMPLE_28_CYCLES    2
#define ADC_SAMPLE_56_CYCLES    3
#define ADC_SAMPLE_84_CYCLES    4
#define ADC_SAMPLE_112_CYCLES   5
#define ADC_SAMPLE_144_CYCLES   6
#define ADC_SAMPLE_480_CYCLES   7

/**
	Function Name        : MADC_voidInit
	Function Returns     : void
	Function Arguments   : void
	Function Description : initialization ADC
*/
void MADC_voidInit (void) ;

/**
	Function Name        : MADC_voidConfigChannel
	Function Returns     : void
	Function Arguments   : u8 A_u8ChannelNum , u8 A_u8SampleTime
	Function Description : condigurations channel sellected with sample time selected
	Options              : A_u8ChannelNum -> ADC_CHANNEL_0
                                             ADC_CHANNEL_1
                                             ADC_CHANNEL_2
                                             ADC_CHANNEL_3
                                             ADC_CHANNEL_4
                                             ADC_CHANNEL_5
                                             ADC_CHANNEL_6
                                             ADC_CHANNEL_7
                                             ADC_CHANNEL_8
                                             ADC_CHANNEL_9

                          A_u8SampleTime -> ADC_SAMPLE_3_CYCLES
                                            ADC_SAMPLE_15_CYCLES
                                            ADC_SAMPLE_28_CYCLES
                                            ADC_SAMPLE_56_CYCLES
                                            ADC_SAMPLE_84_CYCLES
                                            ADC_SAMPLE_112_CYCLES
                                            ADC_SAMPLE_144_CYCLES
                                            ADC_SAMPLE_480_CYCLES
*/
void MADC_voidConfigChannel (u8 A_u8ChannelNum , u8 A_u8SampleTime) ;

/**
	Function Name        : MADC_voidStartConversion
	Function Returns     : void
	Function Arguments   : u8 A_u8ChannelNum
	Function Description : start conversion with selected channel
	Options              : A_u8ChannelNum -> ADC_CHANNEL_0
                                             ADC_CHANNEL_1
                                             ADC_CHANNEL_2
                                             ADC_CHANNEL_3
                                             ADC_CHANNEL_4
                                             ADC_CHANNEL_5
                                             ADC_CHANNEL_6
                                             ADC_CHANNEL_7
                                             ADC_CHANNEL_8
                                             ADC_CHANNEL_9
*/
void MADC_voidStartConversion (u8 A_u8ChannelNum) ;

/**
	Function Name        : MADC_u32GetValue
	Function Returns     : u32
	Function Arguments   : void
	Function Description : read data converted from ADC
	                       note that: this function used with interrupt and you must enable interrupt
*/
u32 MADC_u32GetValue (void) ;

/**
	Function Name        : MADC_u32PollingToGetValue
	Function Returns     : u32
	Function Arguments   : u8 A_u8ChannelNum
	Function Description : polling to end of conversion then read data converted from ADC
	Options              : A_u8ChannelNum -> ADC_CHANNEL_0
                                             ADC_CHANNEL_1
                                             ADC_CHANNEL_2
                                             ADC_CHANNEL_3
                                             ADC_CHANNEL_4
                                             ADC_CHANNEL_5
                                             ADC_CHANNEL_6
                                             ADC_CHANNEL_7
                                             ADC_CHANNEL_8
                                             ADC_CHANNEL_9
*/
u32 MADC_u32PollingToGetValue (u8 A_u8ChannelNum) ;

/**
	Function Name        : MADC_voidSetCallback
	Function Returns     : void
	Function Arguments   : void (*A_fptr)(void)
	Function Description : set the call back function of ADC at finished the conversion
*/
void MADC_voidSetCallback( void (*A_fptr)(void)  ) ;

#endif /* MCAL_ADC_ADC_INIT_H_ */
