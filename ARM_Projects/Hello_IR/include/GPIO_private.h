/*****************************************************************************************
 * Author:				Abdullah M. Abdullah
 * Creation Data:		06 May, 2023
 * Version:				v1.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM32F401CCU6 (32-bit Architecture)
 * Processor:			Cortex M4 (32-bit Architecture)
 * Layer:				MCAL
 *****************************************************************************************/
/*****************************************************************************************
 * Version	  Date				  Author				  Description
 * v1.0		  06 May, 2023	Abdullah M. Abdullah		  Initial Creation
*****************************************************************************************/
#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

typedef struct
{
    volatile u32 MODER;
    volatile u32 OTYPER;
    volatile u32 OSPEEDR;
    volatile u32 PUPDR;
    volatile u32 IDR;
    volatile u32 ODR;
    volatile u32 BSRR;
    volatile u32 LCKR;
    volatile u32 AFRL;
    volatile u32 AFRH;

} GPIO_t;


#define GPIOA ((volatile GPIO_t *)0x40020000)       // Base Address For GPIOA
#define GPIOB ((volatile GPIO_t *)0x40020400)       // Base Address For GPIOB
#define GPIOC ((volatile GPIO_t *)0x40020800)       // Base Address For GPIOC


#define PIN_BITS_OFFSET 2
#define BSRR_PIN_OFFSET 16

#endif