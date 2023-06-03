/**********************************************************************************************
 * Author:          Hossam M. Elzhar
 * Creation Data:   22 MAY, 2023
 * Version:         v1.0
 * Compiler:        GNU ARM-GCC
 *********************************************************************************************/

#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

typedef struct
{
    volatile u32 IMR; //Interrupt mask register
    volatile u32 EMR; //Event mask register
    volatile u32 RTSR; //Rising trigger selection register
    volatile u32 FTSR; //Falling trigger selection register
    volatile u32 SWIER; //Software interrupt event register
    volatile u32 PR; //Pending register OR PIF, Interrupt Flag
}EXTI_t;


#define     EXTI       ((volatile EXTI_t*)0x40013C00)


#define     SYSCFG_EXTICR1      *((volatile u32*)0x40013808)

#define 	NULL		((void*)0)

static void (*CallBackFun[16])(void) = {NULL};


#endif
