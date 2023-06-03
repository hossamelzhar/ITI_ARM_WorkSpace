/**********************************************************************************************
 * Author:          Hossam M. Elzhar
 * Creation Data:   04 MAY, 2023
 * Version:         v1.0
 * Compiler:        GNU ARM-GCC
 *********************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void MRCC_voidInit(void)
{
    #if CPU_CLK_SRC == HSI
        /* Enable HSI */
        SET_BIT(RCC->CR,CR_HSION);
        /* Select HSI as System CLK SRC*/
        RCC->CFGR &= CFGR_SYS_CLK_SEL_MSK;
        RCC->CFGR |= (CFGR_SYS_CLK_HSI<<CFGR_SW);
    #elif CPU_CLK_SRC == HSE
        /* Set the Bypass Bit */
        #if HSE_CLK_SCR == OSCI
            CLEAR_BIT(RCC->CR,CR_HSEBYP);
        #elif HSE_CLK_SCR == RC
            SET_BIT(RCC->CR,CR_HSEBYP);
        #else
            #error "RCC HSE_CLK_SCR Configuration Error"
        #endif
        /* Enable HSE */
        SET_BIT(RCC->CR,CR_HSEON);
        /* Select HSE as System CLK SRC*/
        RCC->CFGR &= CFGR_SYS_CLK_SEL_MSK;
        RCC->CFGR |= (CFGR_SYS_CLK_HSE<<CFGR_SW);
    #elif CPU_CLK_SRC == PLL
        #if PLL_SRC == HSI
            /* Enable HSI */
            SET_BIT(RCC->CR,CR_HSION);
        #elif PLL_SRC == HSE
            /* Enable HSE */
            SET_BIT(RCC->CR,CR_HSEON);
        #else
            #error "RCC PLL_SRC Configuration Error"
        #endif
            /* Select HSI as PLL Source */
            RCC->PLLCFGR &= PLL_SCR_SEL_MSK;
            RCC->PLLCFGR |= (PLL_SCR_HSI<<PLLCFGR_PLLSRC);
            /* Set Division Factor */
            RCC->PLLCFGR &= PLL_DIV_FACTOR_MSK;
            RCC->PLLCFGR |= (PLL_DIV_FACTOR<<PLLCFGR_PLLP);
            /* Set Multiplication Factor */
            RCC->PLLCFGR &= PLL_MULT_FACTOR_MSK;
            RCC->PLLCFGR |= (PLL_MULT_FACTOR<<PLLCFGR_PLLN);
            /* Enable PLL */
            SET_BIT(RCC->CR,CR_PLLON);
            /* Select PLL as System Clock (CPU CLK SRC)*/
            RCC->CFGR &= CFGR_SYS_CLK_SEL_MSK;
            RCC->CFGR |= (CFGR_SYS_CLK_PLL<<CFGR_SW);
    #else
        #error "RCC CPU_CLK_SCR Configuration Error"
    #endif

    /* Set the AHB Prescaler */
    RCC->CFGR |= (AHB_PRESCALER<<CFGR_HPRE);

    /* Set the APB1 Prescaler */
    RCC->CFGR |= (APB1_PRESCALER<<CFGR_PPRE1);


    /* Set the APB2 Prescaler */
    RCC->CFGR |= (APB2_PRESCALER<<CFGR_PPRE2);

}


void MRCC_voidEnablePeripheralClock(u8 Copy_u8PeripheralBus,u8 Copy_PeripheralID)
{
    switch(Copy_u8PeripheralBus)
    {
        case RCC_AHB1:
            SET_BIT(RCC->AHB1ENR,Copy_PeripheralID);
            break;
        case RCC_AHB2:
            SET_BIT(RCC->AHB2ENR,Copy_PeripheralID);
            break;
        case RCC_APB1:
            SET_BIT(RCC->APB1ENR,Copy_PeripheralID);
            break;
        case RCC_APB2:
            SET_BIT(RCC->APB2ENR,Copy_PeripheralID);
            break;
        default:
            /* Do Nothing */
            break;
    }
}


void MRCC_voidDisablePeripheralClock(u8 Copy_u8PeripheralBus,u8 Copy_PeripheralID)
{
    switch(Copy_u8PeripheralBus)
    {
        case RCC_AHB1:
            CLEAR_BIT(RCC->AHB1ENR,Copy_PeripheralID);
            break;
        case RCC_AHB2:
            CLEAR_BIT(RCC->AHB2ENR,Copy_PeripheralID);
            break;
        case RCC_APB1:
            CLEAR_BIT(RCC->APB1ENR,Copy_PeripheralID);
            break;
        case RCC_APB2:
            CLEAR_BIT(RCC->APB2ENR,Copy_PeripheralID);
            break;
        default:
            /* Do Nothing */
            break;
    }
}
