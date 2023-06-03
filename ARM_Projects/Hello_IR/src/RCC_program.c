/*********************************************
 * Author:				Abdullah M. Abdullah
 * Creation Data:		02 May, 2023
 * Version:				v1.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM32F401CCU6
 * Layer:				MCAL
 ********************************************/
/*********************************************
 * Version	  Date				  Author				  Description
 * v1.0		  02 May, 2023	Abdullah M. Abdullah		  Initial Creation
*********************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void MRCC_voidInit(void)
{
    #if     CPU_CLK_SOURCE == HSI
        /*Enable HSI*/
            SET_BIT(RCC -> CR,0);
        /*Select HSI As System Clock (CPU Clk Source)*/
            CLR_BIT(RCC -> CFGR, 0);
            CLR_BIT(RCC -> CFGR, 1);
    #elif   CPU_CLK_SOURCE == HSE
        /*Enable HSE*/
            SET_BIT(RCC->CR, 16);
        /*Select HSE As System Clock (CPU CLK Source)*/
            SET_BIT(RCC->CFGR, 0);
            CLR_BIT(RCC->CFGR, 1);
    #elif   CPU_CLK_SOURCE == PLL
        #if PLL_SOURCE == HSI
            /*Enable HSI*/
            /*Select HSI As PLL Source*/
            /*Enable PLL*/
            /*Select PLL As System Clock (CPU CLK Source)*/
        #elif PLL_SOURCE == HSE
            /*Enable HSE*/
            /*Select HSE As PLL Source*/
            /*Enable PLL*/
            /*Select PLL As System Clock (CPU CLK Source)*/
        #else
            #error "RCC PLL_SOURCE Configuration Error"
        #endif
    #else
        #error "RCC CPU_CLK_SOURCE Configuration Error"
    #endif

    #if RCC_AHB_PRESCALER > 15
        #error "RCC_AHB_PRESCALER Configuration Error"
    #else 
        RCC -> CFGR &= 0xFFFFFF0F;
        RCC -> CFGR |= RCC_AHB_PRESCALER << 4;
    #endif
}

void MRCC_voidEnablePeripheralClock(u8 Copy_u8PeripheralBus, u8 Copy_u8PeriperhalID)
{
    switch(Copy_u8PeripheralBus)
    {
        case MRCC_AHB1:
            SET_BIT(RCC->AHB1ENR, Copy_u8PeriperhalID);
        break;
        case MRCC_AHB2:
            SET_BIT(RCC->AHB2ENR, Copy_u8PeriperhalID);
        break;
        case MRCC_APB1:
            SET_BIT(RCC->APB1ENR, Copy_u8PeriperhalID);
        break;
        case MRCC_APB2:
            SET_BIT(RCC->APB2ENR, Copy_u8PeriperhalID);
        break;
        default:
            // return error
        break;
    }
}

void MRCC_voidDisablePeripheralClock(u8 Copy_u8PeripheralBus, u8 Copy_u8PeriperhalID)
{
    switch(Copy_u8PeripheralBus)
    {
        case MRCC_AHB1:
            CLR_BIT(RCC->AHB1ENR, Copy_u8PeriperhalID);
        break;
        case MRCC_AHB2:
            CLR_BIT(RCC->AHB2ENR, Copy_u8PeriperhalID);
        break;
        case MRCC_APB1:
            CLR_BIT(RCC->APB1ENR, Copy_u8PeriperhalID);
        break;
        case MRCC_APB2:
            CLR_BIT(RCC->APB2ENR, Copy_u8PeriperhalID);
        break;
        default:
            // return error
        break;
    }
}


