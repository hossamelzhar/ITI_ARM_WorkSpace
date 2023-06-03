/**********************************************************************************************
 * Author:          Hossam M. Elzhar
 * Creation Data:   06 MAY, 2023
 * Version:         v1.0
 * Compiler:        GNU ARM-GCC
 *********************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"



void MGPIO_voidSetPortMode(u8 Copy_u8Port, u8 Copy_u8Mode)
{
    s8 Local_s8PinNumber = 0;
    if(Copy_u8Port == GPIOA || Copy_u8Port == GPIOB)
    {
        Local_s8PinNumber = GPIOA_GPIOB_PINS_NUMBER;
    }
    else if(Copy_u8Port == GPIOC)
    {
        //Port C has only 3 PINs
        Local_s8PinNumber = GPIOC_PINS_NUMBER;
    }else{}
    
    while (Local_s8PinNumber >= 0)
    {
        MGPIO_voidSetPinMode(Copy_u8Port, Local_s8PinNumber, Copy_u8Mode);
        Local_s8PinNumber--;
    }
    
}

void MGPIO_voidSetPinMode(u8 Copy_u8Port, u8 Copy_u8PinNumber, u8 Copy_u8Mode)
{
    /* Check which port to set. */
    switch (Copy_u8Port)
    {
    /* Set the 2 Bits corresponding to the pin in the MODER register to be as the desired direction. */
    case GPIOA:
        GPIOA_REG->GPIOx_MODER &= ~(TWO_BITS_MSK<<(Copy_u8PinNumber*2));
        GPIOA_REG->GPIOx_MODER |= (Copy_u8Mode<<(Copy_u8PinNumber*2));
        break;

    case GPIOB:
        GPIOB_REG->GPIOx_MODER &= ~(TWO_BITS_MSK<<(Copy_u8PinNumber*2));
        GPIOB_REG->GPIOx_MODER |= (Copy_u8Mode<<(Copy_u8PinNumber*2));
        break;

    case GPIOC:
        GPIOC_REG->GPIOx_MODER &= ~(TWO_BITS_MSK<<(Copy_u8PinNumber*2));
        GPIOC_REG->GPIOx_MODER |= (Copy_u8Mode<<(Copy_u8PinNumber*2));
        break;

    default:
        /* ERROR */
        break;
    }
}

void MGPIO_voidSetPortOutputType(u8 Copy_u8Port, u8 Copy_u8OutputType)
{
    s8 Local_s8PinNumber = 0;
    if(Copy_u8Port == GPIOA || Copy_u8Port == GPIOB)
    {
        Local_s8PinNumber = GPIOA_GPIOB_PINS_NUMBER;
    }
    else if(Copy_u8Port == GPIOC)
    {
        //Port C has only 3 PINs
        Local_s8PinNumber = GPIOC_PINS_NUMBER;
    }else{}
    
    while (Local_s8PinNumber >= 0)
    {
        MGPIO_voidSetOutputType(Copy_u8Port, Local_s8PinNumber, Copy_u8OutputType);
        Local_s8PinNumber--;
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

void MGPIO_voidSetPortOutputSpeed(u8 Copy_u8Port, u8 Copy_u8OutputSpeed)
{
    s8 Local_s8PinNumber = 0;
    if(Copy_u8Port == GPIOA || Copy_u8Port == GPIOB)
    {
        Local_s8PinNumber = GPIOA_GPIOB_PINS_NUMBER;
    }
    else if(Copy_u8Port == GPIOC)
    {
        //Port C has only 3 PINs
        Local_s8PinNumber = GPIOC_PINS_NUMBER;
    }else{}
    
    while (Local_s8PinNumber >= 0)
    {
        MGPIO_voidSetOutputSpeed(Copy_u8Port, Local_s8PinNumber, Copy_u8OutputSpeed);
        Local_s8PinNumber--;
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

void MGPIO_voidSetInputConnectionType(u8 Copy_u8Port, u8 Copy_u8PinNumber, u8 Copy_u8ConnectionType)
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
    u8 Local_u8ReturnValue = 0;
    /* Check which port to set. */
    switch (Copy_u8Port)
    {
    /* Set the Bit corresponding to the pin to be as the desired connection. */
    case GPIOA:
        Local_u8ReturnValue = GET_BIT(GPIOA_REG->GPIOx_IDR,Copy_u8PinNumber);
        break;

    case GPIOB:
        Local_u8ReturnValue = GET_BIT(GPIOB_REG->GPIOx_IDR,Copy_u8PinNumber);
        break;

    case GPIOC:
        Local_u8ReturnValue = GET_BIT(GPIOC_REG->GPIOx_IDR,Copy_u8PinNumber);
        break;

    default:
        /* ERROR */
        break;
    }
    return Local_u8ReturnValue;

}

void MGPIO_voidSetPortValue(u8 Copy_u8Port, u16 Copy_u16PortValue)
{
    s8 Local_s8PinNumber = 0;
    if(Copy_u8Port == GPIOA || Copy_u8Port == GPIOB)
    {
        //16 PINS
        Local_s8PinNumber = GPIOA_GPIOB_PINS_NUMBER;
    }
    else if(Copy_u8Port == GPIOC)
    {
        //Port C has only 3 PINs
        Local_s8PinNumber = GPIOC_PINS_NUMBER;
    }else{}
    
    while (Local_s8PinNumber >= 0)
    {
        MGPIO_voidSetPinValue(Copy_u8Port, Local_s8PinNumber, GET_BIT(Copy_u16PortValue, Local_s8PinNumber));
        Local_s8PinNumber--;
    }
}

void MGPIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8PinNumber, u8 Copy_u8PinValue)
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

void MGPIO_voidSetAtomicPinValue(u8 Copy_u8Port, u8 Copy_u8PinNumber, u8 Copy_u8PinValue)
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


void MGPIO_voidConfigurePinMode(MGPIO_Pin_t* pPin, u8 Copy_u8Mode)
{
    pPin->Mode = Copy_u8Mode;
    MGPIO_voidSetPinMode(pPin->Port,pPin->PinNunmber,pPin->Mode);
}

void MGPIO_voidConfigurePinOutputType(MGPIO_Pin_t* pPin, u8 Copy_u8OutputType)
{
    pPin->OutputType = Copy_u8OutputType;
    MGPIO_voidSetOutputType(pPin->Port,pPin->PinNunmber,pPin->OutputType);
}

void MGPIO_voidConfigureOutputSpeed(MGPIO_Pin_t* pPin, u8 Copy_u8OutputSpeed)
{
    pPin->OutputSpeed = Copy_u8OutputSpeed;
    MGPIO_voidSetOutputSpeed(pPin->Port,pPin->PinNunmber,pPin->OutputSpeed);
}

void MGPIO_voidConfigureInputConnectionType(MGPIO_Pin_t* pPin,u8 Copy_u8ConnectionType)
{
    pPin->InputConnectionType = Copy_u8ConnectionType;
    MGPIO_voidSetInputConnectionType(pPin->Port,pPin->PinNunmber,pPin->InputConnectionType);
}

u8 MGPIO_voidUpdatePinValue(MGPIO_Pin_t* pPin)
{
    pPin->Value = MGPIO_voidGetPinValue(pPin->Port,pPin->PinNunmber);
    return pPin->Value;
}

void MGPIO_voidSetConfiguredPinValue(MGPIO_Pin_t* pPin, u8 Copy_u8Value)
{
    pPin->Value = Copy_u8Value;
    MGPIO_voidSetPinValue(pPin->Port,pPin->PinNunmber,pPin->Value);
}

void MGPIO_voidSetConfiguredAtomicPinValue(MGPIO_Pin_t* pPin, u8 Copy_u8Value)
{
    pPin->Value = Copy_u8Value;
    MGPIO_voidSetAtomicPinValue(pPin->Port,pPin->PinNunmber,pPin->Value);
}

void MGPIO_voidConfigurePin(MGPIO_Pin_t* pPin)
{
    MGPIO_voidSetPinMode(pPin->Port,pPin->PinNunmber,pPin->Mode);
    switch (pPin->Mode)
    {
    case OUTPUT:
        MGPIO_voidSetOutputType(pPin->Port,pPin->PinNunmber,pPin->OutputType);
        MGPIO_voidSetOutputSpeed(pPin->Port,pPin->PinNunmber,pPin->OutputSpeed);
        MGPIO_voidSetPinValue(pPin->Port,pPin->PinNunmber,pPin->Value);
        break;
    case INPUT:
        MGPIO_voidSetInputConnectionType(pPin->Port,pPin->PinNunmber,pPin->InputConnectionType);
        break;
    default:
        /* Do Nothing */
        break;
    }
}
