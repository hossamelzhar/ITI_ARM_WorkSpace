/**********************************************************************************************
 * Author:          Hossam M. Elzhar
 * Creation Data:   25 MAY, 2023
 * Version:         v1.0
 * Compiler:        GNU ARM-GCC
 *********************************************************************************************/
#ifndef IR_RECIEVER_INTERFACE_H
#define IR_RECIEVER_INTERFACE_H

#define     NOT_RECIEVED_YET    0
#define     RECIEVED            1

void HIRReciever_voidInit(void);
u8 HIRReciever_u8IsDataRecieved(void);
void HIRReciever_u8DecodeFrame(u8 * Copy_pu8RecievedData);
void HIRReciever_voidGetPressedKey(u8 * Copy_pu8ButtonPressed);


#endif