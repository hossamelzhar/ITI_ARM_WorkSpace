/**********************************************************************************************
 * Author:          Hossam M. Elzhar
 * Creation Data:   21 MAY, 2023
 * Version:         v1.0
 * Compiler:        GNU ARM-GCC
 *********************************************************************************************/

#ifndef PRIVATE_H
#define PRIVATE_H

typedef struct
{
    volatile u32 ISER[8];
    volatile u32 Reserved0[24];
    volatile u32 ICER[8];
    volatile u32 Reserved1[24];
    volatile u32 ISPR[8];
    volatile u32 Reserved2[24];
    volatile u32 ICPR[8];
    volatile u32 Reserved3[24];
    volatile u32 IABR[8];
    volatile u32 Reserved4[56];
    volatile u8  IPR[240];
    volatile u32 Reserved5[580];
    volatile u32 STIR;
}NVIC_t;




#define     MNVIC       ((volatile NVIC_t*)0xE000E100)


#define     SCB_AIRCR   *((volatile u32*)0xE000ED0C)


#define         GRP_4_SUB_0_BITS        0b000
#define         GRP_3_SUB_1_BITS        0b100
#define         GRP_2_SUB_2_BITS        0b101
#define         GRP_1_SUB_3_BITS        0b110
#define         GRP_0_SUB_4_BITS        0b111

#define         AIRCR_PRIKY             0x05FA





#endif
