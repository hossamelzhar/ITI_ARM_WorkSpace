/*****************************************************************************************
 * Author:				Abdullah M. Abdullah
 * Creation Data:		22 May, 2023
 * Version:				v1.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM32F401CCU6 (32-bit Architecture)
 * Processor:			Cortex M4 (32-bit Architecture)
 * Layer:				MCAL Layer
 *****************************************************************************************/
/*****************************************************************************************
 * Version	  Date				  Author				  Description
 * v1.0		  22 May, 2023	Abdullah M. Abdullah		  Initial Creation
 *****************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

static void (*pvCallBack[16])(void) = {NULL};

void MEXTI_voidInit(void)
{
}

void MEXTI_voidEnableInterrupt(u8 Copy_u8EXTILine)
{
    if (Copy_u8EXTILine > 15)
    {
        return;
    }
    SET_BIT(MEXTI->IMR, Copy_u8EXTILine);
}

void MEXTI_voidDisableInterrupt(u8 Copy_u8EXTILine)
{
    if (Copy_u8EXTILine > 15)
    {
        return;
    }
    CLR_BIT(MEXTI->IMR, Copy_u8EXTILine);
}

void MEXTI_voidChangeSenseMode(u8 Copy_u8EXTILine, u8 Copy_u8SenseSignal)
{
    switch (Copy_u8SenseSignal)
    {
    case MEXTI_RISING_EDGE:
        CLR_BIT(MEXTI->FTSR, Copy_u8EXTILine); // Clear The Falling Edge Sense Mode
        SET_BIT(MEXTI->RTSR, Copy_u8EXTILine); // Set The Rising Edge Sense Mode
        break;
    case MEXTI_FALLING_EDGE:
        CLR_BIT(MEXTI->RTSR, Copy_u8EXTILine); // Clear The Rising Edge Sense Mode
        SET_BIT(MEXTI->FTSR, Copy_u8EXTILine); // Set The Falling Edge Sense Mode
        break;
    case MEXTI_ON_CHANGE:
        SET_BIT(MEXTI->RTSR, Copy_u8EXTILine); // Set The Rising Edge Sense Mode
        SET_BIT(MEXTI->FTSR, Copy_u8EXTILine); // Set The Falling Edge Sense Mode
        break;
    }
}

void MEXTI_voidSetCallBack(u8 Copy_u8EXTILine, void (*pvNotificationFunction)(void))
{
    pvCallBack[Copy_u8EXTILine] = pvNotificationFunction;
}

void EXTI0_IRQHandler(void)
{
    if(pvCallBack[0] != NULL)
    {
        pvCallBack[0]();
    }
    SET_BIT(MEXTI -> PR, 0);
}




