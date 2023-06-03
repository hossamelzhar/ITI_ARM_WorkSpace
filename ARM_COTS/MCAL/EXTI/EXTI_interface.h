/**********************************************************************************************
 * Author:          Hossam M. Elzhar
 * Creation Data:   22 MAY, 2023
 * Version:         v1.0
 * Compiler:        GNU ARM-GCC
 *********************************************************************************************/

#ifndef     EXTI_INTERFACE_H
#define     EXTI_INTERFACE_H

#define     MEXTI_LINE_0                0
#define     MEXTI_LINE_1                1
#define     MEXTI_LINE_2                2
#define     MEXTI_LINE_3                3
#define     MEXTI_LINE_4                4
#define     MEXTI_LINE_5                5
#define     MEXTI_LINE_6                6
#define     MEXTI_LINE_7                7
#define     MEXTI_LINE_8                8
#define     MEXTI_LINE_9                9
#define     MEXTI_LINE_10               10
#define     MEXTI_LINE_11               11
#define     MEXTI_LINE_12               12
#define     MEXTI_LINE_13               13
#define     MEXTI_LINE_14               14
#define     MEXTI_LINE_15               15

#define     MEXTI_RISING_EDGE           0
#define     MEXTI_FALLING_EDGE          1
#define     MEXTI_ANY_CHANGE_EDGE       2


void MEXTI_voidInit(void);
void MEXTI_voidEnableInterrupt(u8 Copy_u8EXTI_Line);
void MEXTI_voidDisableInterrupt(u8 Copy_u8EXTI_Line);
void MEXTI_voidChangeSenseMode(u8 Copy_u8EXTI_Line, u8 Copu_u8SenseEdge);
void MEXTI_voidSetCallBack(u8 Copy_u8EXTI_Line, void (*pvNotificationFun)(void));



#endif
