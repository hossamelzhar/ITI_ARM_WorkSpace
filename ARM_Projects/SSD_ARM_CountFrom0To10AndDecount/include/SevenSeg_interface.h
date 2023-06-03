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
#ifndef SEVEN_SEG_INTERFACE_H_
#define SEVEN_SEG_INTERFACE_H_

typedef struct
{
	u8  Port;
	u8  Common_Type;

}SevenSeg_t;

//Common Type:
#define COMMON_ANODE 0
#define COMMON_CATHODE 1


void SevenSeg_voidInit(const SevenSeg_t * Copy_SevenSeg);
void SevenSeg_voidDisplayData(const SevenSeg_t * Copy_SevenSeg, u8 Copy_u8Data);
void SevenSeg_voidOFF(const SevenSeg_t * Copy_SevenSeg);

#endif /* LED_H_ */
