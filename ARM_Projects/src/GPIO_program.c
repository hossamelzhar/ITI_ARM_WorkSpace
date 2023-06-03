/*********************************************
 * Author:          Moaz Mohamed Romih
 * Creation Data:   02 MAY, 2023
 * Version:         v1.0
 * Compiler:        GNU ARM-GCC
 ********************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

void MGPIO_voidSetPinDirection(u8 Copy_u8Port, u8 Copy_u8PinNumber, u8 Copy_u8Direction)
{
    /* Check which port to set. */
    switch (Copy_u8Port)
    {
    /* Set the 2 Bits corresponding to the pin in the MODER register to be as the desired direction. */
    case GPIOA:
        GPIOA_REG->GPIOx_MODER &= ~(TWO_BITS_MSK<<(Copy_u8PinNumber*2));
        GPIOA_REG->GPIOx_MODER |= (Copy_u8Direction<<(Copy_u8PinNumber*2));
        break;

    case GPIOB:
        GPIOB_REG->GPIOx_MODER &= ~(TWO_BITS_MSK<<(Copy_u8PinNumber*2));
        GPIOB_REG->GPIOx_MODER |= (Copy_u8Direction<<(Copy_u8PinNumber*2));
        break;

    case GPIOC:
        GPIOC_REG->GPIOx_MODER &= ~(TWO_BITS_MSK<<(Copy_u8PinNumber*2));
        GPIOC_REG->GPIOx_MODER |= (Copy_u8Direction<<(Copy_u8PinNumber*2));
        break;

    default:
        /* ERROR */
        break;
    }
}

void MGPIO_voidSetOutputType(u8 Copy_u8Port, u8 Copy_u8PinNumber, u8 Copy_u8OutputType)
{
    /* Check which port to set. */
    switch (Copy_u8Port)
    {
    /* Set the  bit corresponding to the intended pin in the OTYPER register to be as the desired value */
    case GPIOA:
        if (Copy_u8OutputType == OPEN_DRAIN)
        {
            SET_BIT(GPIOA_REG->GPIOx_OTYPER,Copy_u8PinNumber);
        }
        else if (Copy_u8OutputType == PUSH_PULL)
        {
            CLEAR_BIT(GPIOA_REG->GPIOx_OTYPER,Copy_u8PinNumber);
        }
        else
        {
            /* ERROR */
        }
        break;

    case GPIOB:
        if (Copy_u8OutputType == OPEN_DRAIN)
        {
            SET_BIT(GPIOB_REG->GPIOx_OTYPER,Copy_u8PinNumber);
        }
        else if (Copy_u8OutputType == PUSH_PULL)
        {
            CLEAR_BIT(GPIOB_REG->GPIOx_OTYPER,Copy_u8PinNumber);
        }
        else
        {
            /* ERROR */
        }
        break;

    case GPIOC:
        if (Copy_u8OutputType == OPEN_DRAIN)
        {
            SET_BIT(GPIOC_REG->GPIOx_OTYPER,Copy_u8PinNumber);
        }
        else if (Copy_u8OutputType == PUSH_PULL)
        {
            CLEAR_BIT(GPIOC_REG->GPIOx_OTYPER,Copy_u8PinNumber);
        }
        else
        {
            /* ERROR */
        }
        break;

    default:
        /* ERROR */
        break;
    }
}

void MGPIO_voidSetOutputSpeed(u8 Copy_u8Port, u8 Copy_u8PinNumber, u8 Copy_u8OutputSpeed)
{
    /* Check which port to set. */
    switch (Copy_u8Port)
    {
    /* Set the 2 Bits corresponding to the pin in hte OSPEEDR register to be as the desired speed. */
    case GPIOA:
        GPIOA_REG->GPIOx_OSPEEDR &= ~(TWO_BITS_MSK<<(Copy_u8PinNumber*2));
        GPIOA_REG->GPIOx_OSPEEDR |= (Copy_u8OutputSpeed<<(Copy_u8PinNumber*2));
        break;

    case GPIOB:
        GPIOB_REG->GPIOx_OSPEEDR &= ~(TWO_BITS_MSK<<(Copy_u8PinNumber*2));
        GPIOB_REG->GPIOx_OSPEEDR |= (Copy_u8OutputSpeed<<(Copy_u8PinNumber*2));
        break;

    case GPIOC:
        GPIOC_REG->GPIOx_OSPEEDR &= ~(TWO_BITS_MSK<<(Copy_u8PinNumber*2));
        GPIOC_REG->GPIOx_OSPEEDR |= (Copy_u8OutputSpeed<<(Copy_u8PinNumber*2));
        break;

    default:
        /* ERROR */
        break;
    }
}

void MGPIO_voidSetConnectionType(u8 Copy_u8Port, u8 Copy_u8PinNumber, u8 Copy_u8ConnectionType)
{
    /* Check which port to set. */
    switch (Copy_u8Port)
    {
    /* Set the 2 Bits corresponding to the pin in the PUPDR register to be as the desired connection. */
    case GPIOA:
        GPIOA_REG->GPIOx_PUPDR &= ~(TWO_BITS_MSK<<(Copy_u8PinNumber*2));
        GPIOA_REG->GPIOx_PUPDR |= (Copy_u8ConnectionType<<(Copy_u8PinNumber*2));
        break;

    case GPIOB:
        GPIOB_REG->GPIOx_PUPDR &= ~(TWO_BITS_MSK<<(Copy_u8PinNumber*2));
        GPIOB_REG->GPIOx_PUPDR |= (Copy_u8ConnectionType<<(Copy_u8PinNumber*2));
        break;

    case GPIOC:
        GPIOC_REG->GPIOx_PUPDR &= ~(TWO_BITS_MSK<<(Copy_u8PinNumber*2));
        GPIOC_REG->GPIOx_PUPDR |= (Copy_u8ConnectionType<<(Copy_u8PinNumber*2));
        break;

    default:
        /* ERROR */
        break;
    }
}

u8 MGPIO_voidGetPinValue(u8 Copy_u8Port, u8 Copy_u8PinNumber)
{
    /* Check which port to set. */
    switch (Copy_u8Port)
    {
    /* Set the Bit corresponding to the pin to be as the desired connection. */
    case GPIOA:
        return GET_BIT(GPIOA_REG->GPIOx_IDR,Copy_u8PinNumber);
        break;

    case GPIOB:
        return GET_BIT(GPIOB_REG->GPIOx_IDR,Copy_u8PinNumber);
        break;

    case GPIOC:
        return GET_BIT(GPIOC_REG->GPIOx_IDR,Copy_u8PinNumber);
        break;

    default:
        /* ERROR */
        break;
    }
}

void MGPIO_voidSetPinValueODR(u8 Copy_u8Port, u8 Copy_u8PinNumber, u8 Copy_u8PinValue)
{
    switch (Copy_u8Port)
    {
    /* Set the  bit corresponding to the intended pin in the ODR register to be as the desired value */
    case GPIOA:
        if (Copy_u8PinValue == HIGH)
        {
            SET_BIT(GPIOA_REG->GPIOx_ODR,Copy_u8PinNumber);
        }
        else if (Copy_u8PinValue == LOW)
        {
            CLEAR_BIT(GPIOA_REG->GPIOx_ODR,Copy_u8PinNumber);
        }
        else
        {
            /* ERROR */
        }
        break;

    case GPIOB:
        if (Copy_u8PinValue == HIGH)
        {
            SET_BIT(GPIOB_REG->GPIOx_ODR,Copy_u8PinNumber);
        }
        else if (Copy_u8PinValue == LOW)
        {
            CLEAR_BIT(GPIOB_REG->GPIOx_ODR,Copy_u8PinNumber);
        }
        else
        {
            /* ERROR */
        }
        break;

    case GPIOC:
        if (Copy_u8PinValue == HIGH)
        {
            SET_BIT(GPIOC_REG->GPIOx_ODR,Copy_u8PinNumber);
        }
        else if (Copy_u8PinValue == LOW)
        {
            CLEAR_BIT(GPIOC_REG->GPIOx_ODR,Copy_u8PinNumber);
        }
        else
        {
            /* ERROR */
        }
        break;

    default:
        /* ERROR */
        break;
    }

}

void MGPIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8PinNumber, u8 Copy_u8PinValue)
{
    switch (Copy_u8Port)
    {
    case GPIOA:
        if (Copy_u8PinValue == HIGH)
        {
            SET_BIT(GPIOA_REG->GPIOx_BSRR_SET,Copy_u8PinNumber);
            CLEAR_BIT(GPIOA_REG->GPIOx_BSRR_SET,Copy_u8PinNumber);
        }
        else if(Copy_u8PinValue == LOW)
        {
            SET_BIT(GPIOA_REG->GPIOx_BSRR_RESET,Copy_u8PinNumber);
            CLEAR_BIT(GPIOA_REG->GPIOx_BSRR_RESET,Copy_u8PinNumber);
        }
        else
        {
            /* ERROR */
        }
        break;
    
    case GPIOB:
        if (Copy_u8PinValue == HIGH)
        {
            SET_BIT(GPIOB_REG->GPIOx_BSRR_SET,Copy_u8PinNumber);
            CLEAR_BIT(GPIOB_REG->GPIOx_BSRR_SET,Copy_u8PinNumber);
        }
        else if(Copy_u8PinValue == LOW)
        {
            SET_BIT(GPIOB_REG->GPIOx_BSRR_RESET,Copy_u8PinNumber);
            CLEAR_BIT(GPIOB_REG->GPIOx_BSRR_RESET,Copy_u8PinNumber);
        }
        break;

    case GPIOC:
        if (Copy_u8PinValue == HIGH)
        {
            SET_BIT(GPIOC_REG->GPIOx_BSRR_SET,Copy_u8PinNumber);
            CLEAR_BIT(GPIOC_REG->GPIOx_BSRR_SET,Copy_u8PinNumber);
        }
        else if(Copy_u8PinValue == LOW)
        {
            SET_BIT(GPIOC_REG->GPIOx_BSRR_RESET,Copy_u8PinNumber);
            CLEAR_BIT(GPIOC_REG->GPIOx_BSRR_RESET,Copy_u8PinNumber);
        }
        break;
    default:
        /* ERROR */
        break;
    }
}

