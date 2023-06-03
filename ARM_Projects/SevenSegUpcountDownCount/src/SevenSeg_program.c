/*********************************************
 * Author:          Hossam M. Elzhar
 * Creation Data:   29 MAR, 2023
 * Version:         v1.0
 * Compiler:        GNU GCC
 ********************************************/
/*********************************************
 * Version      Date                  Author                  Description
 * v1.0         29 MAR, 2023    Hossam M. Elzhar          Initial Creation
*********************************************/

/*******************************Includes Section *****************************************/
#include "STD_Types.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"

#include "SevenSeg_interface.h"
#include "SevenSeg_private.h"
#include "SevenSeg_config.h"
/*****************************************************************************************/



/************************************ Implementation Section ******************************/

void SevenSeg_voidInit(const SevenSeg_t * Copy_SevenSeg)
{
	MRCC_voidEnablePeripheralClock(RCC_AHB1, Copy_SevenSeg->Port);
	//Set Seven Segment Port As Output, Initially LOW 
	MGPIO_voidSetPortMode(Copy_SevenSeg->Port , OUTPUT);
	MGPIO_voidSetPortOutputSpeed(Copy_SevenSeg->Port , LOW_SPEED);
	MGPIO_voidSetPortOutputType(Copy_SevenSeg->Port , PUSH_PULL);
}

void SevenSeg_voidDisplayData(const SevenSeg_t * Copy_SevenSeg, u8 Copy_u8Data)
{

	if(Copy_SevenSeg->Common_Type == COMMON_ANODE)
	{
		MGPIO_voidSetPortValue(Copy_SevenSeg->Port , (u16)SevenSeg_u8CommonAnodeDecoder(Copy_u8Data));
	}
	else if(Copy_SevenSeg->Common_Type == COMMON_CATHODE)
	{
		MGPIO_voidSetPortValue(Copy_SevenSeg->Port , (u16)SevenSeg_u8CommonCathodeDecoder(Copy_u8Data));
	}
	else{}

}

void SevenSeg_voidOFF(const SevenSeg_t * Copy_SevenSeg)
{
	if(Copy_SevenSeg->Common_Type == COMMON_ANODE)
	{
		MGPIO_voidSetPortValue(Copy_SevenSeg->Port , 0xFF);
	}
	else if(Copy_SevenSeg->Common_Type == COMMON_CATHODE)
	{
		MGPIO_voidSetPortValue(Copy_SevenSeg->Port , 0x00);
	}
	else{}

}



static u8 SevenSeg_u8CommonAnodeDecoder(u8 Copy_u8Data)
{
    u8 Local_u8ReturnValue = 0;
    switch(Copy_u8Data)
    {
        case 0: //0b1000 0000
            Local_u8ReturnValue = 0x80; break;
        case 1: //0b1111 1001
            Local_u8ReturnValue = 0xF9; break;
        case 2: //0b1010 0100
            Local_u8ReturnValue = 0xA4; break;
        case 3: //0b1011 0000
            Local_u8ReturnValue = 0xB0; break;
        case 4: //0b1001 1001
            Local_u8ReturnValue = 0x99; break;
        case 5: //0b1001 0010
            Local_u8ReturnValue = 0x92; break;
        case 6: //0b1000 0010
            Local_u8ReturnValue = 0x82; break;
        case 7: //0b1111 1000
            Local_u8ReturnValue = 0xF8; break;
        case 8: //0b1000 0000
            Local_u8ReturnValue = 0x80; break;
        case 9: //0b1001 0000
            Local_u8ReturnValue = 0x90; break;
		case 'a':
		case 'A': //0b1000 1000
            Local_u8ReturnValue = 0x88; break;
		case 'b':
		case 'B': //0b1000 0011
            Local_u8ReturnValue = 0x83; break;
		case 'c':
		case 'C': //0b1100 0110
            Local_u8ReturnValue = 0xC6; break;
		case 'd':
		case 'D': //0b1010 0001
            Local_u8ReturnValue = 0xA1; break;
		case 'e':
		case 'E': //0b1000 0110
            Local_u8ReturnValue = 0x86; break;
		case 'f':
		case 'F': //0b1000 1110
            Local_u8ReturnValue = 0x8E; break;

        default:
            break;
    }

    return Local_u8ReturnValue;
}



static u8 SevenSeg_u8CommonCathodeDecoder(u8 Copy_u8Data)
{
    u8 Local_u8ReturnValue = 0;
    switch(Copy_u8Data)
    {
        case 0: //0b0011 1111
            Local_u8ReturnValue = 0x3F; break;
        case 1: //0b0000 0110
            Local_u8ReturnValue = 0x06; break;
        case 2: //0b0101 1011
            Local_u8ReturnValue = 0x5B; break;
        case 3: //0b0100 1111
            Local_u8ReturnValue = 0x4F; break;
        case 4: //0b0110 0110
            Local_u8ReturnValue = 0x66; break;
        case 5: //0b0110 1101
            Local_u8ReturnValue = 0x6D; break;
        case 6: //0b0111 1101
            Local_u8ReturnValue = 0x7D; break;
        case 7: //0b0000 0111
            Local_u8ReturnValue = 0x07; break;
        case 8: //0b0111 1111
            Local_u8ReturnValue = 0x7F; break;
        case 9: //0b0110 1111
            Local_u8ReturnValue = 0x6F; break;
		case 'a':
		case 'A': //0b0111 0111
            Local_u8ReturnValue = 0x77; break;
		case 'b':
		case 'B': //0b0111 1100
            Local_u8ReturnValue = 0x7C; break;
		case 'c':
		case 'C': //0b0011 1001
            Local_u8ReturnValue = 0x39; break;
		case 'd':
		case 'D': //0b0101 1110
            Local_u8ReturnValue = 0x5E; break;
		case 'e':
		case 'E': //0b0111 1001
            Local_u8ReturnValue = 0x79; break;
		case 'f':
		case 'F': //0b0111 0001
            Local_u8ReturnValue = 0x71; break;
		
        default:
            break;
    }
    
    return Local_u8ReturnValue;
}

