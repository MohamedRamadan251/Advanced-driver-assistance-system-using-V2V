/*
 * SYSTIC_conf.h
 *
 *  Created on: Sep 14, 2022
 *      Author: Mohammed Ramadan
 */

#ifndef MCAL_SYSTIC_SYSTIC_CONF_H_
#define MCAL_SYSTIC_SYSTIC_CONF_H_

/*select clock source of STK
 *Options
 **STK_AHB
 **STK_AHB_DIV_8
 */
#define STK_CLOCK_SOURCE  STK_AHB

/*select enable or disable interrupt of STK
 *Options
 **ENABLE
 **DISABLE
 */
#define STK_INTERRUPT_EN  ENABLE

#endif /* MCAL_SYSTIC_SYSTIC_CONF_H_ */
