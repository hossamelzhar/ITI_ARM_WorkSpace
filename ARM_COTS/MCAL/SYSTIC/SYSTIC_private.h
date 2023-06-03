/**********************************************************************************************
 * Author:          Hossam M. Elzhar
 * Creation Data:   07 MAY, 2023
 * Version:         v1.0
 * Compiler:        GNU ARM-GCC
 *********************************************************************************************/

#ifndef SYSTIC_PRIVATE_H
#define SYSTIC_PRIVATE_H

#define     AHB         0
#define     AHB_8       1

#define  ENABLE         1
#define  DISABLE        0


#define     MAX_DELAY_VALUE     16777215
#define     ZERO                0

#define     STK_CTRL            (*(volatile u32 *)0xE000E010)
#define     STK_LOAD            (*(volatile u32 *)0xE000E014)
#define     STK_VAL             (*(volatile u32 *)0xE000E018)
#define     STK_CALIB           (*(volatile u32 *)0xE000E01C)


#define     STK_COUNT_FLAG      16
#define     STK_CLK_SOURCE      2
#define     STK_TICK_INT        1
#define     STK_ENABLE          0


#define     NULL        ((void*)0)
static void (*SYSTIC_CallBackFun)(void) = NULL;

#endif