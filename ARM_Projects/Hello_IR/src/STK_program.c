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
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"


static void (*pvCallBackFunction)(void) = NULL;
static u8 u8IntervalFlag = SINGLE_INTERVAL;

void MSTK_voidInit(void)
{
#if MSTK_CLK_SOURCE == AHB
	SET_BIT(STK->CTRL, 2);

#elif MSTK_CLK_SOURCE == AHB_DIV_BY_8
	CLR_BIT(STK->CTRL, 2);

#else
#error "MSTK_CLK_SOURCE Configuration Error"
#endif

#if MSTK_INTERRUPT   == ENABLE
	SET_BIT(STK->CTRL, 1);
#elif MSTK_INTERRUPT   == DISABLE
	CLR_BIT(STK->CTRL, 1);
#else
#error "MSTK_INTERRUPT Configuration Error"
#endif

#if MSTK_ENABLE == ENABLE
	SET_BIT(STK->CTRL, 0);
#elif MSTK_ENABLE == DISABLE
	CLR_BIT(STK->CTRL, 0);
#else
#error "MSTK_ENABLE Configuration Error"
#endif

}


void MSTK_voidEnableSysTick(void)
{
	SET_BIT(STK->CTRL, 0);
}

void MSTK_voidDisableSysTick(void)
{
	CLR_BIT(STK->CTRL, 0);
}

void MSTK_voidSetClockSource(u8 Copy_u8ClockSource)
{
	switch(Copy_u8ClockSource)
	{
	case MSTK_CLK_AHB:
		SET_BIT(STK->CTRL, 2);
		break;

	case MSTK_CLK_AHB_DIV_BY_8:
		CLR_BIT(STK->CTRL, 2);
		break;

	default:
		break;
	}
	SET_BIT(STK->CTRL, 0);
}



void MSTK_voidEnableInterrupt(void)
{
	SET_BIT(STK->CTRL, 1);
}

void MSTK_voidDisableInterrupt(void)
{
	CLR_BIT(STK->CTRL, 1);
}

u32 MSTK_u32GetElapsedTime(void)
{
	u32 Local_u32ElapsedTime;
	Local_u32ElapsedTime = STK->LOAD - STK->VAL;
	return Local_u32ElapsedTime;
}

u32 MSTK_u32GetRemainingTime(void)
{
	u32 Local_u32RemainingTime;
	Local_u32RemainingTime = STK->VAL;
	return Local_u32RemainingTime;
}

void MSTK_voidSetBusyWait(u32 Copy_u32TicksToWait)
{
	STK -> LOAD = Copy_u32TicksToWait;
	while(GET_BIT(STK->CTRL, 16) == 0);
	STK -> VAL = 0;
}

void MSTK_voidSetPreLoadValue(u32 Copy_u8LoadValue)
{
	STK -> LOAD = Copy_u8LoadValue;
}

void MSTK_voidResetSysTick(void)
{
	STK -> VAL = 0;
}

void MSTK_voidSetSingleInterval(u32 Copy_u32Ticks, void (*NotificationFunction)(void))
{
	/*Disable STK*/
	CLR_BIT(STK -> CTRL, 0);
	/*Reset STK*/
	STK -> VAL = 0;

	/*Set PreLoad Value*/
	STK -> LOAD = Copy_u32Ticks;

	pvCallBackFunction = NotificationFunction;
	u8IntervalFlag = SINGLE_INTERVAL;

	/*Enable STK Interrupt*/
	SET_BIT(STK -> CTRL, 1);
	/*Enable STK*/
	SET_BIT(STK -> CTRL, 0);
}

void MSTK_voidSetPeriodicInterval(u32 Copy_u32Ticks, void (*NotificationFunction)(void))
{
	/*Set PreLoad Value*/
	STK -> LOAD = Copy_u32Ticks;

	pvCallBackFunction = NotificationFunction;
	u8IntervalFlag = PERIODIC_INTERVAL;

	/*Enable STK Interrupt*/
	SET_BIT(STK -> CTRL, 1);
	/*Enable STK*/
	SET_BIT(STK -> CTRL, 0);
}


void SysTick_Handler(void)
{
	u32 Local_u32TempVar;
	if(u8IntervalFlag == SINGLE_INTERVAL)
	{
		STK->LOAD = 0;
		STK->VAL = 0;
		CLR_BIT(STK->CTRL, 0);
	}
	if(pvCallBackFunction != NULL)
	{
		pvCallBackFunction();
	}
	Local_u32TempVar = GET_BIT(STK->CTRL, 16);
}
