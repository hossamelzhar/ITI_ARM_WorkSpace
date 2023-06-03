/*****************************************************************************************
 * Author:				Abdullah M. Abdullah
 * Creation Data:		08 May, 2023
 * Version:				v1.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM32F401CCU6 (32-bit Architecture)
 * Processor:			Cortex M4 (32-bit Architecture)
 * Layer:				MCAL Layer
 *****************************************************************************************/
/*****************************************************************************************
 * Version	  Date				  Author				  Description
 * v1.0		  08 May, 2023	Abdullah M. Abdullah		  Initial Creation
*****************************************************************************************/
#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H

#define AHB             0
#define AHB_DIV_BY_8    1

#define DISABLE         0
#define ENABLE          1

typedef struct
{
    volatile u32 CTRL;
    volatile u32 LOAD;
    volatile u32 VAL;
    volatile u32 CALIB;
}STK_t;

#define     STK     ((volatile STK_t *)0xE000E010)

#define     SINGLE_INTERVAL         0
#define     PERIODIC_INTERVAL       1


#endif 
