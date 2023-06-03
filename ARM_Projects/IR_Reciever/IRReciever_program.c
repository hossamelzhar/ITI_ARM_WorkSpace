/**********************************************************************************************
 * Author:          Hossam M. Elzhar
 * Creation Data:   25 MAY, 2023
 * Version:         v1.0
 * Compiler:        GNU ARM-GCC
 *********************************************************************************************/


#include "BIT_MATH.h"
#include "STD_Types.h"

#include "GPIO_interface.h"
#include "SYSTIC_interface.h"
#include "RCC_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"

#include "IRReciever_interface.h"
#include "IRReciever_private.h"
#include "IRReciever_config.h"

volatile u8 IRReciever_u8FrameArray[40];
volatile u8 IRReciever_u8ButtonCode;
volatile u8 IRReciever_u8InvertedButtonCode;
volatile u8 IRReciever_u8RecieveCompleteFlag;
volatile u8 IRReciever_u8StartOfFrameFlag;
volatile u8 IRReciever_u8ArrayCounter;
volatile u8 IRReciever_u8Address = 0;
volatile u8 IRReciever_u8InvertedAddress = 0;
volatile u8 IRReciever_u8RecievingDoneFlag;


void HIRReciever_voidInit(void)
{
    MRCC_voidInit();
    MRCC_voidEnablePeripheralClock(RCC_AHB1, GPIOA_ID);

    MGPIO_voidSetPinMode(GPIOA, PIN0, INPUT);
    MGPIO_voidSetInputConnectionType(GPIOA, PIN0, PULLUP);

    MNVIC_voidInit();
    MNVIC_voidEnablePeripheralInterrupt(MNVIC_EXTI0);

    MEXTI_voidInit();
    MEXTI_voidChangeSenseMode(MEXTI_LINE_0, MEXTI_FALLING_EDGE);
    MEXTI_voidSetCallBack(MNVIC_EXTI0, &HIRReciever_voidRecieveData);
    MEXTI_voidEnableInterrupt(MNVIC_EXTI0);

    MSYSTICK_voidInit();
    MSYSTICK_voidSetCallBack(&Frame_Completed);
    MSYSTICK_voidInterruptEnable();

}


static void HIRReciever_voidRecieveData(void)
{
    if(IRReciever_u8StartOfFrameFlag == FLAG_NOT_ACTIVE)//First Falling Edge//First Interrupt Enterance
    {
        MSYSTICK_voidSetPreloadValue(START_BIT_TIME);
        IRReciever_u8StartOfFrameFlag = FLAG_ACTIVE;
    }
    else
    {
        IRReciever_u8FrameArray[IRReciever_u8ArrayCounter] = MSYSTICK_u32GetElpasedTime();
        MSYSTICK_voidStop();
        MSYSTICK_voidSetPreloadValue(FRAME_BITS_TIME);        
        IRReciever_u8ArrayCounter++;
    }
}

static void Frame_Completed(void)
{
    IRReciever_u8RecievingDoneFlag = 1;
}

u8 HIRReciever_u8IsDataRecieved(void)
{
    u8 Local_u8RecievingStatus = NOT_RECIEVED_YET;

    if(IRReciever_u8RecievingDoneFlag)
    {
        Local_u8RecievingStatus = RECIEVED;
        IRReciever_u8RecievingDoneFlag = FLAG_NOT_ACTIVE;
    }else{}

    return Local_u8RecievingStatus;
}

u8 HIRReciever_u8DecodeFrame(u8 * Copy_pu8RecievedData)
{
    u8 Local_u8Counter;
    u8 Local_u8FrameStatus = BAD_FRAME;
    (*Copy_pu8RecievedData) = 0;
    //Stop SYSTICK
    MSYSTICK_voidStop();
    // Reset The Start Of Frame Flag
    IRReciever_u8StartOfFrameFlag = FLAG_NOT_ACTIVE; 
    

    for(Local_u8Counter = FRAME_START_BIT; Local_u8Counter<IRReciever_u8ArrayCounter; Local_u8Counter++)
    {
        //Start Bit
        if(Local_u8Counter == FRAME_START_BIT)
        {
            if((IRReciever_u8FrameArray[Local_u8Counter] >= START_BIT_TIME_RANGE_BEGIN) && (IRReciever_u8FrameArray[Local_u8Counter] <= START_BIT_TIME_RANGE_END))
            {
                Local_u8FrameStatus = GOOD_FRAME;
            }
            else
            {
                Local_u8FrameStatus = BAD_FRAME;
                break;
            }
        }
        //Address
        else if((Local_u8Counter >= ADDRESS_START_BIT) && (Local_u8Counter <= ADDRESS_END_BIT))
        {
            if((IRReciever_u8FrameArray[Local_u8Counter] >= ZERO_BIT_TIME_BEGIN) && (IRReciever_u8FrameArray[Local_u8Counter] <= ZERO_BIT_TIME_END))
            {
                CLEAR_BIT(IRReciever_u8Address, Local_u8Counter - ADDRESS_START_BIT);
            }
            elseif((IRReciever_u8FrameArray[Local_u8Counter] >= ONE_BIT_TIME_BEGIN) && (IRReciever_u8FrameArray[Local_u8Counter] <= ONE_BIT_TIME_END))
            {
                SET_BIT(IRReciever_u8Address, Local_u8Counter - ADDRESS_START_BIT);
            }else{}
        }
        //Inverted Address
        else if((Local_u8Counter >= INVERTED_ADDRESS_START_BIT) && (Local_u8Counter <= INVERTED_ADDRESS_END_BIT))
        {
            if((IRReciever_u8FrameArray[Local_u8Counter] >= ZERO_BIT_TIME_BEGIN) && (IRReciever_u8FrameArray[Local_u8Counter] <= ZERO_BIT_TIME_END))
            {
                CLEAR_BIT(IRReciever_u8InvertedAddress, Local_u8Counter - INVERTED_ADDRESS_START_BIT);
            }
            elseif((IRReciever_u8FrameArray[Local_u8Counter] >= ONE_BIT_TIME_BEGIN) && (IRReciever_u8FrameArray[Local_u8Counter] <= ONE_BIT_TIME_END))
            {
                SET_BIT(IRReciever_u8InvertedAddress, Local_u8Counter - INVERTED_ADDRESS_START_BIT);
            }else{}
        }
        //Data
        else if((Local_u8Counter >= DATA_START_BIT) && (Local_u8Counter <= DATA_END_BIT))
        {
            if((IRReciever_u8FrameArray[Local_u8Counter] >= ZERO_BIT_TIME_BEGIN) && (IRReciever_u8FrameArray[Local_u8Counter] <= ZERO_BIT_TIME_END))
            {
                CLEAR_BIT((*Copy_pu8RecievedData), Local_u8Counter - DATA_START_BIT);
            }
            elseif((IRReciever_u8FrameArray[Local_u8Counter] >= ONE_BIT_TIME_BEGIN) && (IRReciever_u8FrameArray[Local_u8Counter] <= ONE_BIT_TIME_END))
            {
                SET_BIT((*Copy_pu8RecievedData), Local_u8Counter - DATA_START_BIT);
            }else{}
        }
        //Inverted Data
        else if((Local_u8Counter >= INVERTED_DATA_START_BIT) && (Local_u8Counter <= INVERTED_DATA_END_BIT))
        {
            if((IRReciever_u8FrameArray[Local_u8Counter] >= ZERO_BIT_TIME_BEGIN) && (IRReciever_u8FrameArray[Local_u8Counter] <= ZERO_BIT_TIME_END))
            {
                CLEAR_BIT(IRReciever_u8InvertedButtonCode, Local_u8Counter - INVERTED_DATA_START_BIT);
            }
            elseif((IRReciever_u8FrameArray[Local_u8Counter] >= ONE_BIT_TIME_BEGIN) && (IRReciever_u8FrameArray[Local_u8Counter] <= ONE_BIT_TIME_END))
            {
                SET_BIT(IRReciever_u8InvertedButtonCode, Local_u8Counter - INVERTED_DATA_START_BIT);
            }else{}
        }
        else{}
    }

    //Reset Array Counter
    IRReciever_u8ArrayCounter = RESET;
    
    IRReciever_u8RecieveCompleteFlag = FLAG_ACTIVE;

    return Local_u8FrameStatus;
}

u8 HIRReciever_voidGetPressedKey(u8 * Copy_pu8ButtonPressed)
{
    u8 Local_u8FrameStatus = BAD_FRAME;
    if(IRReciever_u8RecieveCompleteFlag == FLAG_ACTIVE)
    {
        if((IRReciever_u8Address == (~IRReciever_u8InvertedAddress)) && (IRReciever_u8Address == IR_REMOTE_ADDRESS))
        {
            if(IRReciever_u8ButtonCode == (~IRReciever_u8InvertedButtonCode))
            {
                Local_u8FrameStatus = GOOD_FRAME;
                switch(IRReciever_u8ButtonCode)
                {
                    case 12:
                        *Copy_pu8ButtonPressed = 1;
                        break;
                    case 13:
                        *Copy_pu8ButtonPressed = 2;
                        break;
                    case 14:
                        *Copy_pu8ButtonPressed = 3;
                        break;
                    case 15:
                        *Copy_pu8ButtonPressed = 4;
                        break;
                    case 16:
                        *Copy_pu8ButtonPressed = 5;
                        break;
                    case 17:
                        *Copy_pu8ButtonPressed = 6;
                        break;
                    case 18:
                        *Copy_pu8ButtonPressed = 7;
                        break;
                    case 19:
                        *Copy_pu8ButtonPressed = 8;
                        break;
                    case 20:
                        *Copy_pu8ButtonPressed = 9;
                        break;
                    case 21:
                        *Copy_pu8ButtonPressed = 10;
                        break;
                }
            }
            else{}
            
        }else{}
        IRReciever_u8RecieveCompleteFlag = FLAG_NOT_ACTIVE;
    }
    else
    {
        *Copy_pu8ButtonPressed = NO_PRESSED_KEY;
    }

    return Local_u8FrameStatus;
}