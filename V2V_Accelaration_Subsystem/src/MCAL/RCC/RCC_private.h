/*
 * RCC_private.h
 *
 *  Created on: Sep 2, 2022
 *      Author: Mohammed Ramadan
 */

#ifndef MCAL_RCC_RCC_PRIVATE_H_
#define MCAL_RCC_RCC_PRIVATE_H_
#include "RCC_conf.h"

/*Bits of RCC clock control register (RCC_CR)*/
#define HSION    16
#define HSEON    0
#define HSEBYP   18
#define CSSON    19
#define PLLON    24

/*Bits of RCC configuration register (RCC_CFGR)*/
#define SW0      0
#define SW1      1
#define HPRE_0   4
#define HPRE_1   5
#define HPRE_2   6
#define HPRE_3   7
#define PPRE1_0  10
#define PPRE1_1  11
#define PPRE1_2  12
#define PPRE2_0  13
#define PPRE2_1  14
#define PPRE2_2  15

/*Bits of RCC PLL configuration register (RCC_PLLCFGR)*/
#define PLLSRC   22

/*define ENABLE and DISABLE macro */
#define ENABLE  1
#define DISABLE 2

/*Define Options of System Clock */
#define HSI    1
#define HSE    2
#define PLL    3

/*define Division of clock */
#define NOT_DIVISION  1
#define DIVISION_2    2
#define DIVISION_4    3
#define DIVISION_8    4
#define DIVISION_16   5
#define DIVISION_64   6
#define DIVISION_128  7
#define DIVISION_256  8
#define DIVISION_512  9

/*define frequancy of HSI is 16 MHZ*/
#define F_HSI 16000000UL

/*define frequancy of HSE is 25 MHZ*/
#define F_HSE 25000000UL

#if   PLL_INPUT == HSI
      #define F_SYSTEM F_HSI
#elif PLL_INPUT == HSE
      #define F_SYSTEM F_HSE
#endif

#endif /* MCAL_RCC_RCC_PRIVATE_H_ */



