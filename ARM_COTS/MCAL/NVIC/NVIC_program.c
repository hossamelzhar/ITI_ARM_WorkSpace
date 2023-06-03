/**********************************************************************************************
 * Author:          Hossam M. Elzhar
 * Creation Data:   21 MAY, 2023
 * Version:         v1.0
 * Compiler:        GNU ARM-GCC
 *********************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"


void MNVIC_voidInit(void)
{
    //Set The Group and Sub Priorities Distribution
    SCB_AIRCR |= (AIRCR_PRIKY << 16) | (MNVIC_GRP_SUB_DISTRIBUTION << 8);

}

void MNVIC_voidEnablePeripheralInterrupt(u8 Copy_u8PeripheralID)
{
    u8 Local_u8ISERIndex = Copy_u8PeripheralID / 32;
    MNVIC->ISER[Local_u8ISERIndex] = (1 << (Copy_u8PeripheralID%32));
}

void MNVIC_voidDisablePeripheralInterrupt(u8 Copy_u8PeripheralID)
{
    u8 Local_u8ICERIndex = Copy_u8PeripheralID / 32;
    MNVIC->ICER[Local_u8ICERIndex] = (1 << (Copy_u8PeripheralID%32));
}

void MNVIC_voidSetPendingFlag(u8 Copy_u8PeripheralID)
{
    u8 Local_u8ISPRIndex = Copy_u8PeripheralID / 32;
    MNVIC->ISPR[Local_u8ISPRIndex] = (1 << (Copy_u8PeripheralID%32));
}

void MNVIC_voidClearPendingFlag(u8 Copy_u8PeripheralID)
{
    u8 Local_u8ICPRIndex = Copy_u8PeripheralID / 32;
    MNVIC->ICPR[Local_u8ICPRIndex] = (1 << (Copy_u8PeripheralID%32));
}

u8 MNVIC_u8GetActiveFlag(u8 Copy_u8PeripheralID)
{
    u8 Local_u8ICERIndex = Copy_u8PeripheralID / 32;
    return    GET_BIT(MNVIC->ICER[Local_u8ICERIndex] , ((Copy_u8PeripheralID%32)));
}

void MNVIC_voidSetPeripheralPriority(u8 Copy_u8PeripheralID, u8 Copy_u8Priority)
{
    u8 Local_u8IPRIndex = Copy_u8PeripheralID;
    MNVIC->IPR[Local_u8IPRIndex] = (Copy_u8Priority << 4);
}

