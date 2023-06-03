/**********************************************************************************************
 * Author:          Hossam M. Elzhar
 * Creation Data:   22 MAY, 2023
 * Version:         v1.0
 * Compiler:        GNU ARM-GCC
 *********************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"


void MEXTI_voidInit(void)
{
    
}
void MEXTI_voidEnableInterrupt(u8 Copy_u8EXTI_Line)
{
    if(Copy_u8EXTI_Line > 15)
    {
        return;
    }

    SET_BIT(EXTI->IMR, Copy_u8EXTI_Line);
}

void MEXTI_voidDisableInterrupt(u8 Copy_u8EXTI_Line)
{
    if(Copy_u8EXTI_Line > 15)
    {
        return;
    }
    
    CLEAR_BIT(EXTI->IMR, Copy_u8EXTI_Line);
}

void MEXTI_voidChangeSenseMode(u8 Copy_u8EXTI_Line, u8 Copu_u8SenseEdge)
{
    if(Copy_u8EXTI_Line > 15)
    {
        return;
    }
    
    switch (Copu_u8SenseEdge)
    {
        case MEXTI_RISING_EDGE:
            CLEAR_BIT(EXTI->FTSR, Copy_u8EXTI_Line);
            SET_BIT(EXTI->RTSR, Copy_u8EXTI_Line);
            break;
        case MEXTI_FALLING_EDGE:
            CLEAR_BIT(EXTI->RTSR, Copy_u8EXTI_Line);
            SET_BIT(EXTI->FTSR, Copy_u8EXTI_Line);
            break;
        case MEXTI_ANY_CHANGE_EDGE:
            SET_BIT(EXTI->RTSR, Copy_u8EXTI_Line);
            SET_BIT(EXTI->FTSR, Copy_u8EXTI_Line);
            break;
    
    default:
        break;
    }
}

void MEXTI_voidSetCallBack(u8 Copy_u8EXTI_Line, void (*pvNotificationFun)(void))
{
    if(Copy_u8EXTI_Line > 15)
    {
        return;
    }
    
    CallBackFun[Copy_u8EXTI_Line] = pvNotificationFun;
}

void MEXTI_voidClearInterruptFlag(u8 Copy_u8EXTI_Line)
{
    SET_BIT(EXTI->PR, Copy_u8EXTI_Line);
}


void EXTI0_IRQHandler(void)
{
    if(CallBackFun[0])
    {
        CallBackFun[0]();
    }
    MEXTI_voidClearInterruptFlag(MEXTI_LINE_0);
}

void EXTI1_IRQHandler(void)
{
    if(CallBackFun[1])
    {
        CallBackFun[1]();
    }
    MEXTI_voidClearInterruptFlag(MEXTI_LINE_1);
}

void EXTI2_IRQHandler(void)
{
    if(CallBackFun[2])
    {
        CallBackFun[2]();
    }
    MEXTI_voidClearInterruptFlag(MEXTI_LINE_2);
}

void EXTI3_IRQHandler(void)
{
    if(CallBackFun[3])
    {
        CallBackFun[3]();
    }
    MEXTI_voidClearInterruptFlag(MEXTI_LINE_3);
}

void EXTI4_IRQHandler(void)
{
    if(CallBackFun[4])
    {
        CallBackFun[4]();
    }
    MEXTI_voidClearInterruptFlag(MEXTI_LINE_4);
}

void EXTI5_IRQHandler(void)
{
    if(CallBackFun[5])
    {
        CallBackFun[5]();
    }
    MEXTI_voidClearInterruptFlag(MEXTI_LINE_5);
}

void EXTI6_IRQHandler(void)
{
    if(CallBackFun[6])
    {
        CallBackFun[6]();
    }
    MEXTI_voidClearInterruptFlag(MEXTI_LINE_6);
}

void EXTI7_IRQHandler(void)
{
    if(CallBackFun[7])
    {
        CallBackFun[7]();
    }
    MEXTI_voidClearInterruptFlag(MEXTI_LINE_7);
}

void EXTI8_IRQHandler(void)
{
    if(CallBackFun[8])
    {
        CallBackFun[8]();
    }
    MEXTI_voidClearInterruptFlag(MEXTI_LINE_8);
}

void EXTI9_IRQHandler(void)
{
    if(CallBackFun[9])
    {
        CallBackFun[9]();
    }
    MEXTI_voidClearInterruptFlag(MEXTI_LINE_9);
}

void EXTI10_IRQHandler(void)
{
    if(CallBackFun[10])
    {
        CallBackFun[10]();
    }
    MEXTI_voidClearInterruptFlag(MEXTI_LINE_10);
}

void EXTI11_IRQHandler(void)
{
    if(CallBackFun[11])
    {
        CallBackFun[11]();
    }
    MEXTI_voidClearInterruptFlag(MEXTI_LINE_11);
}

void EXTI12_IRQHandler(void)
{
    if(CallBackFun[12])
    {
        CallBackFun[12]();
    }
    MEXTI_voidClearInterruptFlag(MEXTI_LINE_12);
}

void EXTI13_IRQHandler(void)
{
    if(CallBackFun[13])
    {
        CallBackFun[13]();
    }
    MEXTI_voidClearInterruptFlag(MEXTI_LINE_13);
}

void EXTI14_IRQHandler(void)
{
    if(CallBackFun[14])
    {
        CallBackFun[14]();
    }
    MEXTI_voidClearInterruptFlag(MEXTI_LINE_14);
}

void EXTI15_IRQHandler(void)
{
    if(CallBackFun[15])
    {
        CallBackFun[15]();
    }
    MEXTI_voidClearInterruptFlag(MEXTI_LINE_15);
}
