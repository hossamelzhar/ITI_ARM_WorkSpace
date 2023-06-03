/**********************************************************************************************
 * Author:          Hossam M. Elzhar
 * Creation Data:   07 MAY, 2023
 * Version:         v1.0
 * Compiler:        GNU ARM-GCC
 *********************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SYSTIC_interface.h"
#include "SYSTIC_private.h"
#include "SYSTIC_config.h"



void MSYSTICK_voidInit(void)
{
    #if     SYSTICK_CLOCK_SOURCE == AHB
            SET_BIT(STK_CTRL, STK_CLK_SOURCE);
    #elif   SYSTICK_CLOCK_SOURCE == AHB_8
            CLEAR_BIT(STK_CTRL, STK_CLK_SOURCE);
    #else
    #error "SYSTICK_CLOCK_SOURCE Configrations Error "
    #endif
    
    #if     SYSTICK_INTERRUPT_STATUS == ENABLE
            SET_BIT(STK_CTRL, STK_TICK_INT);
    #elif   SYSTICK_INTERRUPT_STATUS == DISABLE
            CLEAR_BIT(STK_CTRL, STK_TICK_INT);
    #else
    #error "SYSTICK_INTERRUPT_STATUS Configrations Error "
    #endif
    
    #if     SYS_TICK_STATUS == ENABLE
            SET_BIT(STK_CTRL, STK_ENABLE);
    #elif   SYS_TICK_STATUS == DISABLE
            CLEAR_BIT(STK_CTRL, STK_ENABLE);
    #else
    #error "SYS_TICK_STATUS Configrations Error "
    #endif
}


void MSYSTICK_voidSetBusyWaitus(u32 Copy_u32TimeDelay)
{
    if(Copy_u32TimeDelay > MAX_DELAY_VALUE)
    {
        u32 Local_u32Counter;
        u32 Local_u32Reminder;
        Local_u32Counter = Copy_u32TimeDelay / MAX_DELAY_VALUE;
        Local_u32Reminder = Copy_u32TimeDelay % MAX_DELAY_VALUE;

        STK_LOAD = Local_u32Reminder;
        while(GET_BIT(STK_CTRL, STK_COUNT_FLAG) == ZERO);
        
        STK_LOAD = MAX_DELAY_VALUE;

        while (Local_u32Counter--)
        {
            while(GET_BIT(STK_CTRL, STK_COUNT_FLAG) == ZERO);
        }

        STK_VAL = ZERO;
    }
    else
    {
        STK_LOAD = Copy_u32TimeDelay;
        while(GET_BIT(STK_CTRL, STK_COUNT_FLAG) == ZERO);
        STK_VAL = ZERO;
    }
  
}
void MSYSTICK_voidInterruptEnable(void);
void MSYSTICK_voidInterruptDisnable(void);
u32  MSYSTICK_u32GetElpasedTime(void);
u32  MSYSTICK_u32GetRemainingTime(void);