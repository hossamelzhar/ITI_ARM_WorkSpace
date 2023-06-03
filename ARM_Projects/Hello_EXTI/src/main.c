#include "BIT_MATH.h"
#include "STD_Types.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"

void EXTI0_Func();

void main(void)
{
	MRCC_voidInit();
	MRCC_voidEnablePeripheralClock(RCC_AHB1, GPIOA_ID);

	//For Switch Interrupt
	MGPIO_voidSetPinMode(GPIOA, PIN0, INPUT);
	MGPIO_voidSetInputConnectionType(GPIOA, PIN0, PULLUP);

	//For LED
	MGPIO_voidSetPinMode(GPIOA, PIN1, OUTPUT);
	MGPIO_voidSetOutputType(GPIOA, PIN1, PUSH_PULL);
	MGPIO_voidSetOutputSpeed(GPIOA, PIN1, LOW_SPEED);
	MGPIO_voidSetPinValue(GPIOA, PIN1, HIGH);

	MNVIC_voidInit();
	MNVIC_voidEnablePeripheralInterrupt(MNVIC_EXTI0);

	MEXTI_voidChangeSenseMode(MEXTI_LINE_0, MEXTI_FALLING_EDGE);
	MEXTI_voidSetCallBack(MEXTI_LINE_0, EXTI0_Func);
	MEXTI_voidEnableInterrupt(MEXTI_LINE_0);

	while(1)
	{

	}
}

void EXTI0_Func()
{
	static u8 flag = 0;
	flag++;
	if(flag == 2)
	{
		flag = 0;
	}

	if(flag == 1)
	{
		MGPIO_voidSetPinValue(GPIOA, PIN1, LOW);
	}
	else if(flag == 0)
	{
		MGPIO_voidSetPinValue(GPIOA, PIN1, HIGH);
	}

}
