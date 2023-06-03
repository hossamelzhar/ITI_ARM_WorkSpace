/*********************************************
 * Author:          Hossam M. Elzhar
 * Creation Data:   12 MAY, 2023
 * Version:         v1.0
 * Compiler:        GNU ARM GCC
 ********************************************/
#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

typedef struct
{
	u8  Port;
	u8  Common_Type;

}SSD_t;

//Common Type:
#define COMMON_ANODE 0
#define COMMON_CATHODE 1


void SSD_voidInit(const SSD_t * Copy_SevenSeg);
void SSD_voidDisplayData(const SSD_t * Copy_SevenSeg, u8 Copy_u8Data);
void SSD_voidOFF(const SSD_t * Copy_SevenSeg);
u8 SSD_u8CommonAnodeDecoder(u8 Copy_u8Data);
u8 SSD_u8CommonCathodeDecoder(u8 Copy_u8Data);

#endif
