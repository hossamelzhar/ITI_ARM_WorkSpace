/*********************************************
 * Author:				Abdullah M. Abdullah
 * Creation Data:		02 May, 2023
 * Version:				v1.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM32F401CCU6
 * Layer:				MCAL
 ********************************************/
/*********************************************
 * Version	  Date				  Author				  Description
 * v1.0		  02 May, 2023	Abdullah M. Abdullah		  Initial Creation
*********************************************/
#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

// #define RCC_BASE_ADDRESS    0x40023800

// #define RCC_CR          *((volatile u32 *)(RCC_BASE_ADDRESS+0x00))  // RCC Control Register


typedef struct
{
    volatile u32 CR;
    volatile u32 PLLCFGR;
    volatile u32 CFGR;
    volatile u32 CIR;
    volatile u32 AHB1RSTR;
    volatile u32 AHB2RSTR;
    volatile u32 Reserved1[2];
    volatile u32 APB1RSTR;
    volatile u32 APB2RSTR;
    volatile u32 Reserved2[2];
    volatile u32 AHB1ENR;
    volatile u32 AHB2ENR;
    volatile u32 Reserved3[2];
    volatile u32 APB1ENR;
    volatile u32 APB2ENR;
    volatile u32 Reserved4[2];
    volatile u32 AHB1LPENR;
    volatile u32 AHB2LPENR;
    volatile u32 Reserved5[2];
    volatile u32 APB1LPENR;
    volatile u32 APB2LPENR;
    volatile u32 Reserved6[2];
    volatile u32 BDCR;
    volatile u32 CSR;
    volatile u32 Reserved7[2];
    volatile u32 SSCGR;
    volatile u32 PLLI2SCFGR;
    volatile u32 Reserved8;
    volatile u32 DCKCFGR;
}RCC_t;


#define     RCC         ((volatile RCC_t *)0x40023800)

#define     SYSTEM_CLK_DIV_BY_2        0b1000



#endif