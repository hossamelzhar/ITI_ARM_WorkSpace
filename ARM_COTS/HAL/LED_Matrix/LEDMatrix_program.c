/**********************************************************************************************
 * Author:          Hossam M. Elzhar
 * Creation Data:   14 MAY, 2023
 * Version:         v1.0
 * Compiler:        GNU ARM-GCC
 *********************************************************************************************/


#include "BIT_MATH.h"
#include "STD_Types.h"

#include "GPIO_interface.h"
#include "SYSTIC_interface.h"
#include "RCC_interface.h"

#include "LEDMatrix_interface.h"
#include "LEDMatrix_private.h"
#include "LEDMatrix_config.h"


void HLEDMAT_voidInit(void)
{
    //Set Rows Pins Output mode
    MGPIO_voidSetPinMode(HLEDMAT_ROWS_PORT, HLEDMAT_R0_PIN, OUTPUT);
    MGPIO_voidSetPinMode(HLEDMAT_ROWS_PORT, HLEDMAT_R1_PIN, OUTPUT);
    MGPIO_voidSetPinMode(HLEDMAT_ROWS_PORT, HLEDMAT_R2_PIN, OUTPUT);
    MGPIO_voidSetPinMode(HLEDMAT_ROWS_PORT, HLEDMAT_R3_PIN, OUTPUT);
    MGPIO_voidSetPinMode(HLEDMAT_ROWS_PORT, HLEDMAT_R4_PIN, OUTPUT);
    MGPIO_voidSetPinMode(HLEDMAT_ROWS_PORT, HLEDMAT_R5_PIN, OUTPUT);
    MGPIO_voidSetPinMode(HLEDMAT_ROWS_PORT, HLEDMAT_R6_PIN, OUTPUT);
    MGPIO_voidSetPinMode(HLEDMAT_ROWS_PORT, HLEDMAT_R7_PIN, OUTPUT);
    //Set Columns Pins Output mode
    MGPIO_voidSetPinMode(HLEDMAT_COLUMNS_PORT, HLEDMAT_C0_PIN, OUTPUT);
    MGPIO_voidSetPinMode(HLEDMAT_COLUMNS_PORT, HLEDMAT_C1_PIN, OUTPUT);
    MGPIO_voidSetPinMode(HLEDMAT_COLUMNS_PORT, HLEDMAT_C2_PIN, OUTPUT);
    MGPIO_voidSetPinMode(HLEDMAT_COLUMNS_PORT, HLEDMAT_C3_PIN, OUTPUT);
    MGPIO_voidSetPinMode(HLEDMAT_COLUMNS_PORT, HLEDMAT_C4_PIN, OUTPUT);
    MGPIO_voidSetPinMode(HLEDMAT_COLUMNS_PORT, HLEDMAT_C5_PIN, OUTPUT);
    MGPIO_voidSetPinMode(HLEDMAT_COLUMNS_PORT, HLEDMAT_C6_PIN, OUTPUT);
    MGPIO_voidSetPinMode(HLEDMAT_COLUMNS_PORT, HLEDMAT_C7_PIN, OUTPUT);

    DisableAllColumns();
}

void HLEDMAT_voidDisplay(u8 * Copy_pu8ArrayData)
{
    static u8 RowsArray[]   = {HLEDMAT_R0_PIN, HLEDMAT_R1_PIN, HLEDMAT_R2_PIN, HLEDMAT_R3_PIN,
                               HLEDMAT_R4_PIN, HLEDMAT_R5_PIN, HLEDMAT_R6_PIN, HLEDMAT_R7_PIN};
    static u8 ColumnsArray[] = {HLEDMAT_C0_PIN, HLEDMAT_C1_PIN, HLEDMAT_C2_PIN, HLEDMAT_C3_PIN,
                                HLEDMAT_C4_PIN, HLEDMAT_C5_PIN, HLEDMAT_C6_PIN, HLEDMAT_C7_PIN};
    u8 Local_u8RowsCounter = 0;
    u8 Local_u8ColumnsCounter = 0;
    u8 Local_u8Bit = 0;

    for(Local_u8ColumnsCounter=0; Local_u8ColumnsCounter<8; Local_u8ColumnsCounter++)
    {
        DisableAllColumns();
        for(Local_u8RowsCounter=0; Local_u8RowsCounter<8; Local_u8RowsCounter++)
        {
            Local_u8Bit = GET_BIT(Copy_pu8ArrayData[Local_u8ColumnsCounter], Local_u8RowsCounter);
            MGPIO_voidSetPinValue(HLEDMAT_ROWS_PORT, RowsArray[Local_u8RowsCounter], Local_u8Bit);
        }
        MGPIO_voidSetPinValue(HLEDMAT_COLUMNS_PORT, ColumnsArray[Local_u8ColumnsCounter], LOW);
        MSYSTICK_voidSetBusyWaitus(1700);
    }

}

static void DisableAllColumns(void)
{
    MGPIO_voidSetPinValue(HLEDMAT_COLUMNS_PORT, HLEDMAT_C0_PIN, HIGH);
    MGPIO_voidSetPinValue(HLEDMAT_COLUMNS_PORT, HLEDMAT_C1_PIN, HIGH);
    MGPIO_voidSetPinValue(HLEDMAT_COLUMNS_PORT, HLEDMAT_C2_PIN, HIGH);
    MGPIO_voidSetPinValue(HLEDMAT_COLUMNS_PORT, HLEDMAT_C4_PIN, HIGH);
    MGPIO_voidSetPinValue(HLEDMAT_COLUMNS_PORT, HLEDMAT_C5_PIN, HIGH);
    MGPIO_voidSetPinValue(HLEDMAT_COLUMNS_PORT, HLEDMAT_C6_PIN, HIGH);
    MGPIO_voidSetPinValue(HLEDMAT_COLUMNS_PORT, HLEDMAT_C7_PIN, HIGH);
}