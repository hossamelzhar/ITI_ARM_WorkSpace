/**********************************************************************************************
 * Author:          Hossam M. Elzhar
 * Creation Data:   07 MAY, 2023
 * Version:         v1.0
 * Compiler:        GNU ARM-GCC
 *********************************************************************************************/

#ifndef SYSTIC_INTERFACE_H
#define SYSTIC_INTERFACE_H



void MSYSTICK_voidInit(void);
void MSYSTICK_voidSetBusyWaitus(u32 Copy_u32TimeDelay);
void MSYSTICK_voidSetPreloadValue(u32 Copy_u32PreloadValue);
void MSYSTICK_voidStop(void);
void MSYSTICK_voidInterruptEnable(void);
void MSYSTICK_voidInterruptDisnable(void);
void MSYSTICK_voidSetCallBack(void (*NotificationFun)(void));
u32  MSYSTICK_u32GetElpasedTime(void);
u32  MSYSTICK_u32GetRemainingTime(void);


#endif