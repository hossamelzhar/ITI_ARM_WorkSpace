#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SevenSeg_interface.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"


void main(void)
{
    SevenSeg_t seg1 = {.Port = GPIOA, .Common_Type = COMMON_CATHODE};
    SevenSeg_t seg2 = {.Port = GPIOB, .Common_Type = COMMON_CATHODE};

    SevenSeg_voidInit(&seg1);
    SevenSeg_voidInit(&seg2);
    
    SevenSeg_voidDisplayData(&seg1, 7);
    SevenSeg_voidDisplayData(&seg2, 7);
    while (1)
    {

    }
    
}
