/*
 * GPIO_register.h
 *
 *  Created on: Sep 6, 2022
 *      Author: Mohammed Ramadan
 */

#ifndef MCAL_GPIO_GPIO_REGISTER_H_
#define MCAL_GPIO_GPIO_REGISTER_H_

/*define base address of GPIOA*/
#define GPIOA_BASE_ADDRESS   0x40020000

/*define base address of GPIOB*/
#define GPIOB_BASE_ADDRESS   0x40020400

/*define base address of GPIOC*/
#define GPIOC_BASE_ADDRESS   0x40020800

/*registers of GPIOx*/
typedef struct
{
	u32 MODER  ;
    u32 OTYPER ;
    u32 OSPEEDR;
    u32 PUPDR  ;
    u32 IDR    ;
    u32 ODR    ;
    u32 BSRR   ;
    u32 LCKR   ;
    u32 AFRL   ;
    u32 AFRH   ;
}GPIO_MemoryMapType;

/*define GPIOA*/
#define GPIOA ((volatile GPIO_MemoryMapType *)(GPIOA_BASE_ADDRESS))

/*define GPIOB*/
#define GPIOB ((volatile GPIO_MemoryMapType *)(GPIOB_BASE_ADDRESS))

/*define GPIOC*/
#define GPIOC ((volatile GPIO_MemoryMapType *)(GPIOC_BASE_ADDRESS))

#endif /* MCAL_GPIO_GPIO_REGISTER_H_ */
