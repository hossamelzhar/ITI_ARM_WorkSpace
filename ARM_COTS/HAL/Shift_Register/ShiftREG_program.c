/**********************************************************************************************
 * Author:          Hossam M. Elzhar
 * Creation Data:   03 JUN, 2023
 * Version:         v1.0
 * Compiler:        GNU ARM-GCC
 *********************************************************************************************/


#include "BIT_MATH.h"
#include "STD_Types.h"

#include "GPIO_interface.h"
#include "SYSTIC_interface.h"
#include "RCC_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"

#include "SHIFT_REG_interface.h"
#include "SHIFT_REG_private.h"
#include "SHIFT_REG_config.h"


void HShiftREG_voidInit(ShiftREG_t *ShiftREG)
{
    MRCC_voidInit();
    MSYSTICK_voidInit();
    MRCC_voidEnablePeripheralClock(RCC_AHB1, ShiftREG->Data_Port);
    MRCC_voidEnablePeripheralClock(RCC_AHB1, ShiftREG->Clock_Port);
    MRCC_voidEnablePeripheralClock(RCC_AHB1, ShiftREG->Latch_Port);
    MGPIO_voidSetPinMode(ShiftREG->Data_Port, ShiftREG->Data_Pin, OUTPUT);
    MGPIO_voidSetPinMode(ShiftREG->Clock_Port, ShiftREG->Clock_Pin, OUTPUT);
    MGPIO_voidSetPinMode(ShiftREG->Latch_Port, ShiftREG->Latch_Pin, OUTPUT);
}


void HShiftREG_voidSendDataOneShifREG(ShiftREG_t *ShiftREG, u8 Copy_u8Data)
{
    s8 Local_s8Counter;
    for(Local_s8Counter=7; Local_s8Counter<=0; Local_s8Counter--)
    {
        MGPIO_voidSetPinValue(ShiftREG->Clock_Port, ShiftREG->Clock_Pin, HIGH);
        MGPIO_voidSetPinValue(ShiftREG->Data_Port, ShiftREG->Data_Pin, GET_BIT(Copy_u8Data, Local_s8Counter));
        MSYSTICK_voidSetBusyWaitus(1);
        MGPIO_voidSetPinValue(ShiftREG->Clock_Port, ShiftREG->Clock_Pin, LOW);
        MSYSTICK_voidSetBusyWaitus(1);
    }
    MGPIO_voidSetPinValue(ShiftREG->Latch_Port, ShiftREG->Latch_Pin, HIGH);
    MSYSTICK_voidSetBusyWaitus(1);
    MGPIO_voidSetPinValue(ShiftREG->Latch_Port, ShiftREG->Latch_Pin, LOW);
}

void HShiftREG_voidSendDataTwoShifREGs(ShiftREG_t *ShiftREG, u16 Copy_u16Data)
{
    HShiftREG_voidSendDataOneShifREG(ShiftREG, ((u8)(Copy_u16Data>>8)));
    HShiftREG_voidSendDataOneShifREG(ShiftREG, ((u8)(Copy_u16Data)));
}