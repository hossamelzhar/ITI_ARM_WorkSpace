/**********************************************************************************************
 * Author:          Hossam M. Elzhar
 * Creation Data:   25 MAY, 2023
 * Version:         v1.0
 * Compiler:        GNU ARM-GCC
 *********************************************************************************************/

#ifndef IR_RECIEVER_PRIVATE_H
#define IR_RECIEVER_PRIVATE_H

#define     BAD_ADDRESS         0
#define     BAD_FRAME           1
#define     GOOD_FRAME          2
#define     NO_PRESSED_KEY      255

#define     START_BIT_TIME      120000
#define     FRAME_BITS_TIME     50000

#define     FLAG_NOT_ACTIVE        0
#define     FLAG_ACTIVE            1
#define     RESET                  0

#define     FRAME_START_BIT                     0
#define     ADDRESS_START_BIT                   1
#define     ADDRESS_END_BIT                     8
#define     INVERTED_ADDRESS_START_BIT          9
#define     INVERTED_ADDRESS_END_BIT            16
#define     DATA_START_BIT                      17
#define     DATA_END_BIT                        24
#define     INVERTED_DATA_START_BIT             25
#define     INVERTED_DATA_END_BIT               32

#define     START_BIT_TIME_RANGE_BEGIN          12000
#define     START_BIT_TIME_RANGE_END            15000
#define     ZERO_BIT_TIME_BEGIN                 1000
#define     ZERO_BIT_TIME_END                   1500
#define     ONE_BIT_TIME_BEGIN                  2000
#define     ONE_BIT_TIME_END                    2500

static void HIRReciever_voidRecieveData(void);
static void Frame_Completed(void);

#endif