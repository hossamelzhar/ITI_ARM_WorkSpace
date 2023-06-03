/**********************************************************************************************
 * Author:          Hossam M. Elzhar
 * Creation Data:   21 MAY, 2023
 * Version:         v1.0
 * Compiler:        GNU ARM-GCC
 *********************************************************************************************/

#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

#define     MNVIC_EXTI0                 6
#define     MNVIC_EXTI1                 7
#define     MNVIC_EXTI2                 8
#define     MNVIC_EXTI3                 9
#define     MNVIC_EXTI4                 10

#define     MNVIC_PRIORITY_G00S00       0b0000
#define     MNVIC_PRIORITY_G00S01       0b0001
#define     MNVIC_PRIORITY_G00S10       0b0010
#define     MNVIC_PRIORITY_G00S11       0b0011
#define     MNVIC_PRIORITY_G01S00       0b0100
#define     MNVIC_PRIORITY_G01S01       0b0101
#define     MNVIC_PRIORITY_G01S10       0b0110
#define     MNVIC_PRIORITY_G01S11       0b0111
#define     MNVIC_PRIORITY_G10S00       0b1000
#define     MNVIC_PRIORITY_G10S01       0b1001
#define     MNVIC_PRIORITY_G10S10       0b1010
#define     MNVIC_PRIORITY_G10S11       0b1011
#define     MNVIC_PRIORITY_G11S00       0b1100
#define     MNVIC_PRIORITY_G11S01       0b1101
#define     MNVIC_PRIORITY_G11S10       0b1110
#define     MNVIC_PRIORITY_G11S11       0b1111


void MNVIC_voidInit(void);
void MNVIC_voidEnablePeripheralInterrupt(u8 Copy_u8PeripheralID);
void MNVIC_voidDisablePeripheralInterrupt(u8 Copy_u8PeripheralID);
void MNVIC_voidSetPendingFlag(u8 Copy_u8PeripheralID);
void MNVIC_voidClearPendingFlag(u8 Copy_u8PeripheralID);
u8 MNVIC_u8GetActiveFlag(u8 Copy_u8PeripheralID);
void MNVIC_voidSetPeripheralPriority(u8 Copy_u8PeripheralID, u8 Copy_u8Priority);

#endif
