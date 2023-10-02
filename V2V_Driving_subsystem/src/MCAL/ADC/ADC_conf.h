/*
 * ADC_conf.h
 *
 *  Created on: Feb 24, 2023
 *      Author: Mohammed Ramadan
 */

#ifndef MCAL_ADC_ADC_CONF_H_
#define MCAL_ADC_ADC_CONF_H_

/**set prescaller of ADC clk
   **Options
      *ADC_PRESCALLER_BY_2
      *ADC_PRESCALLER_BY_4
      *ADC_PRESCALLER_BY_6
      *ADC_PRESCALLER_BY_8
*/
#define ADC_PRESCALLER  ADC_PRESCALLER_BY_8

/**set resolution of ADC
   **Options
      *ADC_RESOLUTION_12_BIT
      *ADC_RESOLUTION_10_BIT
      *ADC_RESOLUTION_8_BIT
      *ADC_RESOLUTION_6_BIT
*/
#define ADC_RESOLUTION  ADC_RESOLUTION_12_BIT

/**set Number of channels to be converted
   **Options
      *1
      *2
      *3
      *4
      *5
      *6
      *7
      *8
*/
#define NUMBER_OF_CHANNEL_TO_BE_CONVERTED  2
/*
 * Define ADC_INTERRUPT
  ** Options :
      *ENABLE_INTERRUPT
      *DISABLE_INTERRUPT
 */
#define ADC_INTERRUPT  DISABLE_INTERRUPT
#endif /* MCAL_ADC_ADC_CONF_H_ */
