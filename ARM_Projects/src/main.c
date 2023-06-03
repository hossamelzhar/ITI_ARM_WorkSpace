#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"



void main(void)
{
	MRCC_voidInit();
	MRCC_voidEnablePeripheralClock(RCC_AHB1, GPIOA_ID);

	MGPIO_voidSetPinDirection(GPIOA, PIN0, OUTPUT);
	MGPIO_voidSetOutputType(GPIOA, PIN0, PUSH_PULL);
	MGPIO_voidSetOutputSpeed(GPIOA, PIN0, LOW_SPEED);

	while(1)
	{
		MGPIO_voidSetPinValue(GPIOA, PIN0, HIGH);
		MGPIO_voidSetPinValue(GPIOA, PIN0, LOW);
	}
}
