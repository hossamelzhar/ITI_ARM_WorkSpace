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
#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H

#define MSTK_CLK_AHB            0
#define MSTK_CLK_AHB_DIV_BY_8   1

void MSTK_voidInit(void);
void MSTK_voidSetClockSource(u8 Copy_u8ClockSource);
void MSTK_voidEnableSysTick(void);
void MSTK_voidDisableSysTick(void);
void MSTK_voidSetClockSource(u8 Copy_u8ClockSource);
void MSTK_voidEnableInterrupt(void);
void MSTK_voidDisableInterrupt(void);
u32 MSTK_u32GetElapsedTime(void);
u32 MSTK_u32GetRemainingTime(void);
void MSTK_voidSetBusyWait(u32 Copy_u32TicksToWait);
void MSTK_voidSetPreLoadValue(u32 Copy_u8LoadValue);
void MSTK_voidResetSysTick(void);
void MSTK_voidSetSingleInterval(u32 Copy_u32Ticks, void (*NotificationFunction)(void));
void MSTK_voidSetPeriodicInterval(u32 Copy_u32Ticks, void (*NotificationFunction)(void));

#endif 
