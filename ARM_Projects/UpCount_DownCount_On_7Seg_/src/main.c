#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SevenSeg_interface.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "SYSTIC_interface.h"

SevenSeg_t Seg1 = {.Port = GPIOA,
					.A = PIN0,
					.B = PIN1,
					.C = PIN2,
					.D = PIN3,
					.E = PIN4,
					.F = PIN5,
					.G = PIN6,
					.DOT = NC,
					.Common_Type = COMMON_CATHODE};
SevenSeg_t Seg2 = {.Port = GPIOA,
					.A = PIN7,
					.B = PIN8,
					.C = PIN9,
					.D = PIN10,
					.E = PIN11,
					.F = PIN12,
					.G = PIN13,
					.DOT = NC,
					.Common_Type = COMMON_CATHODE};

void main ()
{
	s8 Local_s8TimeCounter;

	MRCC_voidInit();
	MRCC_voidEnablePeripheralClock(RCC_AHB1, GPIOA_ID);

	SevenSeg_voidInit(&Seg1);
	SevenSeg_voidInit(&Seg2);


	MSYSTICK_voidInit();

	while(1)
	{
		for(Local_s8TimeCounter = 0; Local_s8TimeCounter < 20; Local_s8TimeCounter++)
		{
			SevenSeg_voidDisplayData(&Seg1, Local_s8TimeCounter%10);
			SevenSeg_voidDisplayData(&Seg2, Local_s8TimeCounter/10);

			MSYSTICK_voidSetBusyWaitus(1000000);
		}

		for(Local_s8TimeCounter = 19; Local_s8TimeCounter >= 0; Local_s8TimeCounter--)
		{
			SevenSeg_voidDisplayData(&Seg1, Local_s8TimeCounter%10);
			SevenSeg_voidDisplayData(&Seg2, Local_s8TimeCounter/10);
			MSYSTICK_voidSetBusyWaitus(1000000);
		}
	}


}
