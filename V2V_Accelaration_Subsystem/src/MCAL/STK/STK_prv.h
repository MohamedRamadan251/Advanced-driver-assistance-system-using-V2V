/*
 * STK_prv.h
 *
 *  Created on: Sep 14, 2022
 *      Author: Mohammed Ramadan
 */

#ifndef MCAL_STK_STK_PRV_H_
#define MCAL_STK_STK_PRV_H_

#define STK_BASE_ADDR 0xE000E010
typedef struct{
	u32 CTRL;
	u32 LOAD;
	u32 VAL;
	u32 CALIB;
}STK_MemMap_t;

#define STK ((volatile STK_MemMap_t*)(STK_BASE_ADDR))

#define COUNTFLAG 16
#define CLKSOURCE 2
#define TICKINT 1
#define ENABLE 0

#define STK_AHB_DIV_8 	0
#define STK_AHB		  	1

#define STK_DISABLE 	  	0
#define STK_ENABLE 		  	1

#define STK_SINGLE  	  	0
#define STK_PERIODIC 		1
#endif /* MCAL_STK_STK_PRV_H_ */
