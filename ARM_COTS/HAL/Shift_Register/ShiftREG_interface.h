/**********************************************************************************************
 * Author:          Hossam M. Elzhar
 * Creation Data:   03 JUN, 2023
 * Version:         v1.0
 * Compiler:        GNU ARM-GCC
 *********************************************************************************************/
#ifndef SHIFT_REG_INTERFACE_H
#define SHIFT_REG_INTERFACE_H


typedef struct
{
    u8 Data_Port;
    u8 Data_Pin;
    u8 Clock_Port;
    u8 Clock_Pin;
    u8 Latch_Port;
    u8 Latch_Pin;
}ShiftREG_t;


void HShiftREG_voidInit(ShiftREG_t *ShiftREG);
void HShiftREG_voidSendDataOneShifREG(ShiftREG_t *ShiftREG, u8 Copy_u8Data);
void HShiftREG_voidSendDataTwoShifREGs(ShiftREG_t *ShiftREG, u16 Copy_u16Data);

#endif