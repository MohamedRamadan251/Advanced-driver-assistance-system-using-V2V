/*
 * ADC_private.h
 *
 *  Created on: Feb 24, 2023
 *      Author: Mohammed Ramadan
 */

#ifndef MCAL_ADC_ADC_PRIVATE_H_
#define MCAL_ADC_ADC_PRIVATE_H_

/*********************************************************/
/* 				SR BITS Mapping 			             */
/*********************************************************/
/* Analog watchdog flag                                  */
#define ADC_SR_AWD_BIT      0
/* Regular channel end of conversion                     */
#define ADC_SR_EOC_BIT      1
/* Injected channel end of conversion                    */
#define ADC_SR_JEOC_BIT     2
/* Injected channel start flag                           */
#define ADC_SR_JSTRT_BIT    3
/* Regular channel start flag                            */
#define ADC_SR_STRT_BIT     4
/* Overrun                                               */
#define ADC_SR_OVR_BIT      5

/*********************************************************/
/* 				CR1 BITS Mapping 			             */
/*********************************************************/
/* Analog watchdog channel select bits                   */
#define ADC_CR1_AWDCH_BIT0      0
#define ADC_CR1_AWDCH_BIT1      1
#define ADC_CR1_AWDCH_BIT2      2
#define ADC_CR1_AWDCH_BIT3      3
#define ADC_CR1_AWDCH_BIT4      4
/* Interrupt enable for EOC                              */
#define ADC_CR1_EOCIE_BIT       5
/* Analog watchdog interrupt enable                      */
#define ADC_CR1_AWDIE_BIT       6
/* Interrupt enable for injected channels                */
#define ADC_CR1_JEOCIE_BIT      7
/* Scan mode                                             */
#define ADC_CR1_SCAN_BIT        8
/* Enable the watchdog on a single channel in scan mode  */
#define ADC_CR1_AWDSGL_BIT      9
/* Automatic injected group conversion                   */
#define ADC_CR1_JAUTO_BIT       10
/* Discontinuous mode on regular channels                */
#define ADC_CR1_DISCEN_BIT      11
/* Discontinuous mode on injected channels               */
#define ADC_CR1_JDISCEN_BIT     12
/* Discontinuous mode channel count                      */
#define ADC_CR1_DISCNUM_BIT0    13
#define ADC_CR1_DISCNUM_BIT1    14
#define ADC_CR1_DISCNUM_BIT2    15
/* Analog watchdog enable on injected channels           */
#define ADC_CR1_JAWDEN_BIT      22
/* Analog watchdog enable on regular channels            */
#define ADC_CR1_AWDEN_BIT       23
/* Resolution                                            */
#define ADC_CR1_RES_BIT0        24
#define ADC_CR1_RES_BIT1        25
/* Overrun interrupt enable                              */
#define ADC_CR1_OVRIE_BIT       26

/*********************************************************/
/* 				CR2 BITS Mapping 			             */
/*********************************************************/
/* A/D Converter ON / OFF                                */
#define ADC_CR2_ADON_BIT      0
/* Continuous conversion                                 */
#define ADC_CR2_CONT_BIT      1
/* Direct memory access mode                             */
#define ADC_CR2_DMA_BIT       8
/* DMA disable selection                                 */
#define ADC_CR2_DDS_BIT       9
/* End of conversion selection                           */
#define ADC_CR2_EOCS_BIT      10
/* Data alignment                                        */
#define ADC_CR2_ALIGN_BIT     11
/* External event select for injected group              */
#define ADC_CR2_JEXTSEL_BIT0  16
#define ADC_CR2_JEXTSEL_BIT1  17
#define ADC_CR2_JEXTSEL_BIT2  18
#define ADC_CR2_JEXTSEL_BIT3  19
/* External trigger enable for injected channels         */
#define ADC_CR2_JEXTEN_BIT0   20
#define ADC_CR2_JEXTEN_BIT1   21
/* Start conversion of injected channels                 */
#define ADC_CR2_JSWSTART_BIT  22
/* External event select for regular group               */
#define ADC_CR2_EXTSEL_BIT0   24
#define ADC_CR2_EXTSEL_BIT1   25
#define ADC_CR2_EXTSEL_BIT2   26
#define ADC_CR2_EXTSEL_BIT3   27
/* External trigger enable for regular channels          */
#define ADC_CR2_EXTEN_BIT0    28
#define ADC_CR2_EXTEN_BIT1    29
/* Start conversion of regular channels                  */
#define ADC_CR2_SWSTART_BIT   30

/*********************************************************/
/* 				CCR BITS Mapping 			             */
/*********************************************************/
/* ADC prescaler                                         */
#define ADC_CR2_ADCPRE_BIT0   16
#define ADC_CR2_ADCPRE_BIT1   17
/* VBAT enable                                           */
#define ADC_CR2_VBATE_BIT     22
/* Temperature sensor and VREFINT enable                 */
#define ADC_CR2_TSVREFE_BIT   23

/*********************************************************/
/* 				SQR1 BITS Mapping 			             */
/*********************************************************/
/*ADC Regular channel sequence length                    */
#define ADC_SQR1_L_BIT0       20


/*
 * Define ADC prescallers
 */
#define ADC_PRESCALLER_BY_2   0
#define ADC_PRESCALLER_BY_4   1
#define ADC_PRESCALLER_BY_6   2
#define ADC_PRESCALLER_BY_8   3

/*
 * Define ADC resolution
 */
#define ADC_RESOLUTION_12_BIT   0
#define ADC_RESOLUTION_10_BIT   1
#define ADC_RESOLUTION_8_BIT    2
#define ADC_RESOLUTION_6_BIT    3

/*
 * Define All Number of channels to be converted
 */
#define ALL_NUMBER_OF_CHANNEL_TO_BE_CONVERTED  8

/*
 * Define Regular channel sequence length[0 ... 15]
 */
#define REGULAR_CHANNEL_SEQUENCE_LENGTH   15

/*
 * Define Stablization delay of ADC
 */
#define ADC_STABLEZATION_DELAY  48
/*
 * Define ADC_INTERRUPT (ENABLE_INTERRUPT/DISABLE_INTERRUPT)
 */
#define ENABLE_INTERRUPT   1
#define DISABLE_INTERRUPT  2

/*
 * Define Null address
 */
#define Null (void*)(0)
#endif /* MCAL_ADC_ADC_PRIVATE_H_ */
