/*
 * RCC_conf.h
 *
 *  Created on: Sep 2, 2022
 *      Author: Mohammed Ramadan
 */

#ifndef MCAL_RCC_RCC_CONF_H_
#define MCAL_RCC_RCC_CONF_H_

/*PLL configurations
    *Range of PLLM    2   ---> 63
    *Range of PLLN    192 ---> 432
    *Range of PLLP    2 , 4 , 6 , 8
 *Fout = (Fin * PLLN)/(PLLM * PLLP)    up to 84 MHZ
 */
#define PLLM   32
#define PLLN   312
#define PLLP   4

/*Enable/Disable clock security system
 *Options
   **ENABLE
   **DISABLE
 */
#define RCC_CSS_ENABLE    DISABLE

/*System clock selection
 *Options
  **HSI  (High Speed Internal clock 16 MHZ)
  **HSE  (High Speed External clock 16 MHZ)
  **PLL  (Phase Locked Loop   up to 84 MHZ)
 */
#define SYSTEM_CLOCK  HSI

/*AHB Prescaler
 *Options
  **NOT_DIVISION
  **DIVISION_2
  **DIVISION_4
  **DIVISION_8
  **DIVISION_16
  **DIVISION_64
  **DIVISION_128
  **DIVISION_256
  **DIVISION_512
 **/
#define AHB_PRESCALER  DIVISION_2

/*APB1 Prescaler
 *Options
  **NOT_DIVISION
  **DIVISION_2
  **DIVISION_4
  **DIVISION_8
  **DIVISION_16
 */
#define APB1_PRESCALER NOT_DIVISION

/*APB2 Prescaler
 *Options
  **NOT_DIVISION
  **DIVISION_2
  **DIVISION_4
  **DIVISION_8
  **DIVISION_16
 */
#define APB2_PRESCALER NOT_DIVISION

#define PLL_INPUT  HSE

/*Enable / Disable the select clock source */
#define RCC_HSE_ENABLE		DISABLE
#define RCC_HSI_ENABLE		ENABLE
#define RCC_PLL_ENABLE		DISABLE


#endif /* MCAL_RCC_RCC_CONF_H_ */


