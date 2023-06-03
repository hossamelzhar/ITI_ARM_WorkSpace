#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "SYSTIC_interface.h"

void main ()
{
	MRCC_voidInit();
	MRCC_voidEnablePeripheralClock(RCC_AHB1, GPIOA_ID);
	MGPIO_voidSetPinMode(GPIOA, PIN0, OUTPUT);
	MGPIO_voidSetOutputType(GPIOA, PIN0, PUSH_PULL);
	MGPIO_voidSetOutputSpeed(GPIOA, PIN0, LOW_SPEED);

	MSYSTICK_voidInit();

	while(1)
	{
		MGPIO_voidSetPinValue(GPIOA, PIN0, HIGH);
		MSYSTICK_voidSetBusyWaitus(1000000);
		MGPIO_voidSetPinValue(GPIOA, PIN0, LOW);
		MSYSTICK_voidSetBusyWaitus(1000000);
	}


}
