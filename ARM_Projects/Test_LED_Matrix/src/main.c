#include "BIT_MATH.h"
#include "STD_Types.h"
#include <stdlib.h>

#include "LEDMatrix_interface.h"

#include "GPIO_interface.h"
#include "RCC_interface.h"
#include "SYSTIC_interface.h"



void main(void)
{
	u8 Local_u8ArrHossam[] = {0x7F,0x08,0x08,0x7F,0x00,0x38,0x44,0x44};
	MRCC_voidInit();
	MRCC_voidEnablePeripheralClock(RCC_AHB1, GPIOA_ID);
	MRCC_voidEnablePeripheralClock(RCC_AHB1, GPIOB_ID);
	MSYSTICK_voidInit();

	HLEDMAT_voidInit();


    while (1)
    {
    	HLEDMAT_voidDisplay(Local_u8ArrHossam);

    }
}
