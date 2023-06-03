#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "SYSTIC_interface.h"


void main(void)
{

    u8 Local_u8ArrHossam[] = {0x00,0x00,0x00,0x00,
    							0x7F,0x08,0x08,0x7F,0x00,0x38,0x44,0x44, 0x38,0x00,0x46,0x49,0x31,0x00,0x46,0x49,
    							0x31,0x00,0x7E,0x09,0x09,0x7E,0x00,0x7F, 0x02,0x04,0x02,0x7F,0x00,0x00,0x00,0x00,
								0x00,0x00,0x00,0x00};
    MRCC_voidInit();
    MRCC_voidEnablePeripheralClock(RCC_AHB1, GPIOA_ID);
    MRCC_voidEnablePeripheralClock(RCC_AHB1, GPIOB_ID);
    MSYSTICK_voidInit();

    MGPIO_voidSetPortMode(GPIOA, OUTPUT);
    MGPIO_voidSetPortOutputType(GPIOA, PUSH_PULL);
    MGPIO_voidSetPortOutputSpeed(GPIOA, LOW_SPEED);

    MGPIO_voidSetPortMode(GPIOB, OUTPUT);
	MGPIO_voidSetPortOutputType(GPIOB, PUSH_PULL);
	MGPIO_voidSetPortOutputSpeed(GPIOB, LOW_SPEED);
	MGPIO_voidSetPortValue(GPIOB, 0xFFFF);

	u8 Local_u8Left  = 0;
	u8 Local_u8LastLeft  = Local_u8Left;
	u8 Local_u8Right = 8;
	u8 Local_u8LastRight = Local_u8Right;
	u16 Local_u16Timer = 0;
	u8 Local_u8Counter = 0;
	u8 Local_u8ActivePin = 0;

    while (1)
    {
    	while(Local_u16Timer < 15)
    	{
        	for(Local_u8Counter = Local_u8Left; Local_u8Counter<Local_u8Right; Local_u8Counter++)
        	{
        		MGPIO_voidSetPortValue(GPIOA, Local_u8ArrHossam[Local_u8Counter]);
    			MGPIO_voidSetPinValue(GPIOB, Local_u8ActivePin, LOW);
    			MSYSTICK_voidSetBusyWaitus(1700);
    			MGPIO_voidSetPinValue(GPIOB, Local_u8ActivePin, HIGH);
    			Local_u8ActivePin++;
        	}
        	Local_u8Left  = Local_u8LastLeft;
        	Local_u8Right = Local_u8LastRight;
        	Local_u16Timer++;
        	Local_u8ActivePin = 0;
    	}

    	Local_u8Left++;
    	Local_u8Right++;

    	Local_u16Timer = 0;

    	if(Local_u8Right == 40)
    	{
    		Local_u8Left = 0;
    		Local_u8Right = 8;
    	}

    	Local_u8LastLeft  = Local_u8Left;
    	Local_u8LastRight = Local_u8Right;

    }
    
}
