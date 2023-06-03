#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SevenSeg_interface.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "SYSTIC_interface.h"


void main(void)
{
    SevenSeg_t seg1 = {.Port = GPIOB, .Common_Type = COMMON_CATHODE};
    SevenSeg_t seg2 = {.Port = GPIOA, .Common_Type = COMMON_CATHODE};

    u8 Local_u8Counter = 0;

    SevenSeg_voidInit(&seg1);
    SevenSeg_voidInit(&seg2);

    MRCC_voidInit();
    MSYSTICK_voidInit();


    while (1)
    {
    	for(Local_u8Counter=0; Local_u8Counter<11; Local_u8Counter++)
    	{
    		SevenSeg_voidDisplayData(&seg1, Local_u8Counter%10);
    		SevenSeg_voidDisplayData(&seg2, Local_u8Counter/10);
    		MSYSTICK_voidSetBusyWaitus(500000);
    	}
    	for(Local_u8Counter=9; Local_u8Counter>0; Local_u8Counter--)
		{
			SevenSeg_voidDisplayData(&seg1, Local_u8Counter%10);
			SevenSeg_voidDisplayData(&seg2, Local_u8Counter/10);
			MSYSTICK_voidSetBusyWaitus(500000);
		}
    }
    
}
