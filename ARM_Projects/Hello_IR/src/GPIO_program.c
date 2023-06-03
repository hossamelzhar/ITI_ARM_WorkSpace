/*****************************************************************************************
 * Author:				Abdullah M. Abdullah
 * Creation Data:		06 May, 2023
 * Version:				v1.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM32F401CCU6 (32-bit Architecture)
 * Processor:			Cortex M4 (32-bit Architecture)
 * Layer:				MCAL
 *****************************************************************************************/
/*****************************************************************************************
 * Version	  Date				  Author				  Description
 * v1.0		  06 May, 2023	Abdullah M. Abdullah		  Initial Creation
 *****************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"


/**
 * @brief A Link-Time configuration function that configure the pin using the public MGPIO_Pin_t sturct definition
 *
 * @param Parameter GPIO_Pin: Pointer to object of struct MGPIO_Pin_t created
 *
 * @note  None
 *
 * @return void
 */
void MGPIO_voidConfigurePin(MGPIO_Pin_t *GPIO_Pin)
{
    /*Checking The PortName*/
    switch (GPIO_Pin->PortName)
    {
    case MGPIO_PORTA:
        /*Checking For Pin Mode*/
        switch (GPIO_Pin->Mode)
        {
        case MGPIO_INPUT:
            /*Set The Pin To Be Input Pin*/
            GPIOA->MODER |= (0b00 << (GPIO_Pin->PinNumber * PIN_BITS_OFFSET));
            /*Checking For The Pull Up/Down Resistor*/
            switch (GPIO_Pin->PullUpDown)
            {
            case MGPIO_FLOAT:
                /*Disbale The Pull Up/Down Resistor*/
                GPIOA->PUPDR |= (0b00 << (GPIO_Pin->PinNumber * PIN_BITS_OFFSET));
                break;
            case MGPIO_PULLUP:
                /*Enable The Pull Up Resistor*/
                GPIOA->PUPDR |= (0b01 << (GPIO_Pin->PinNumber * PIN_BITS_OFFSET));
                break;
            case MGPIO_PULLDOWN:
                /*Enable The Pull Down Resistor*/
                GPIOA->PUPDR |= (0b10 << (GPIO_Pin->PinNumber * PIN_BITS_OFFSET));
                break;
            default:

                break;
            }
            break;
        case MGPIO_OUTPUT:
            /*Set The Pin To Be Output Pin*/
            GPIOA->MODER |= (0b01 << (GPIO_Pin->PinNumber * PIN_BITS_OFFSET));
            /*Checking For The Output Type*/
            switch (GPIO_Pin->OutputType)
            {
            case MGPIO_OUTPUT_OD:
                /*Set The Pin Output Type To Be Open Drain Pin*/
                SET_BIT(GPIOA->OTYPER, GPIO_Pin->PinNumber);
                break;
            case MGPIO_OUTPUT_PP:
                /*Set The Pin Output Type To Be PushPull Pin*/
                CLR_BIT(GPIOA->OTYPER, GPIO_Pin->PinNumber);
                break;
            }
            switch (GPIO_Pin->OutputSpeed)
            {
            case MGPIO_LOW_SPEED:
                /*Set the speed of the pin to low speed*/
                GPIOA->OSPEEDR |= (0b00 << (GPIO_Pin->PinNumber * PIN_BITS_OFFSET));
                break;
            case MGPIO_MEDIUM_SPEED:
                /*Set the speed of the pin to medium speed*/
                GPIOA->OSPEEDR |= (0b01 << (GPIO_Pin->PinNumber * PIN_BITS_OFFSET));
                break;
            case MGPIO_HIGH_SPEED:
                /*Set the speed of the pin to high speed*/
                GPIOA->OSPEEDR |= (0b10 << (GPIO_Pin->PinNumber * PIN_BITS_OFFSET));
                break;
            case MGPIO_VHIGH_SPEED:
                /*Set the speed of the pin to very high speed*/
                GPIOA->OSPEEDR |= (0b11 << (GPIO_Pin->PinNumber * PIN_BITS_OFFSET));
                break;
            }
            /*Check For The Pin Initial Value*/
            switch (GPIO_Pin->InitialState)
            {
            case MGPIO_OUTPUT_LOW:
                /*Set Pin Low, Atomic Reset*/
                GPIOA->BSRR = 1 << (GPIO_Pin->PinNumber + BSRR_PIN_OFFSET);
                break;
            case MGPIO_OUTPUT_HIGH:
                /*Set Pin High, Atomic Set*/
                GPIOA->BSRR = 1 << (GPIO_Pin->PinNumber);
                break;
            }
            break;
        case MGPIO_AF:
            /*Set The Pin To Be Alternative Function Pin*/
            GPIOA->MODER |= (0b10 << (GPIO_Pin->PinNumber * PIN_BITS_OFFSET));
            break;
        case MGPIO_ANALOG:
            /*Set The Pin To Be Analog Pin*/
            GPIOA->MODER |= (0b11 << (GPIO_Pin->PinNumber * PIN_BITS_OFFSET));
            break;
        }
        break;

    case MGPIO_PORTB:
        /*Checking For Pin Mode*/
        switch (GPIO_Pin->Mode)
        {
        case MGPIO_INPUT:
            /*Set The Pin To Be Input Pin*/
            GPIOB->MODER |= (0b00 << (GPIO_Pin->PinNumber * PIN_BITS_OFFSET));
            /*Checking For The Pull Up/Down Resistor*/
            switch (GPIO_Pin->PullUpDown)
            {
            case MGPIO_FLOAT:
                /*Disbale The Pull Up/Down Resistor*/
                GPIOB->PUPDR |= (0b00 << (GPIO_Pin->PinNumber * PIN_BITS_OFFSET));
                break;
            case MGPIO_PULLUP:
                /*Enable The Pull Up Resistor*/
                GPIOB->PUPDR |= (0b01 << (GPIO_Pin->PinNumber * PIN_BITS_OFFSET));
                break;
            case MGPIO_PULLDOWN:
                /*Enable The Pull Down Resistor*/
                GPIOB->PUPDR |= (0b10 << (GPIO_Pin->PinNumber * PIN_BITS_OFFSET));
                break;
            default:

                break;
            }
            break;
        case MGPIO_OUTPUT:
            /*Set The Pin To Be Output Pin*/
            GPIOB->MODER |= (0b01 << (GPIO_Pin->PinNumber * PIN_BITS_OFFSET));
            /*Checking For The Output Type*/
            switch (GPIO_Pin->OutputType)
            {
            case MGPIO_OUTPUT_OD:
                /*Set The Pin Output Type To Be Open Drain Pin*/
                SET_BIT(GPIOB->OTYPER, GPIO_Pin->PinNumber);
                break;
            case MGPIO_OUTPUT_PP:
                /*Set The Pin Output Type To Be PushPull Pin*/
                CLR_BIT(GPIOB->OTYPER, GPIO_Pin->PinNumber);
                break;
            }
            /*Check For The Pin Initial Value*/
            switch (GPIO_Pin->InitialState)
            {
            case MGPIO_OUTPUT_LOW:
                /*Set Pin Low, Atomic Reset*/
                GPIOB->BSRR = 1 << (GPIO_Pin->PinNumber + BSRR_PIN_OFFSET);
                break;
            case MGPIO_OUTPUT_HIGH:
                /*Set Pin High, Atomic Set*/
                GPIOB->BSRR = 1 << (GPIO_Pin->PinNumber);
                break;
            }
            break;
        case MGPIO_AF:
            /*Set The Pin To Be Alternative Function Pin*/
            GPIOB->MODER |= (0b10 << (GPIO_Pin->PinNumber * PIN_BITS_OFFSET));
            break;
        case MGPIO_ANALOG:
            /*Set The Pin To Be Analog Pin*/
            GPIOB->MODER |= (0b11 << (GPIO_Pin->PinNumber * PIN_BITS_OFFSET));
            break;
        }
        break;

    case MGPIO_PORTC:
        /*Checking For Pin Mode*/
        switch (GPIO_Pin->Mode)
        {
        case MGPIO_INPUT:
            /*Set The Pin To Be Input Pin*/
            GPIOC->MODER |= (0b00 << (GPIO_Pin->PinNumber * PIN_BITS_OFFSET));
            /*Checking For The Pull Up/Down Resistor*/
            switch (GPIO_Pin->PullUpDown)
            {
            case MGPIO_FLOAT:
                /*Disbale The Pull Up/Down Resistor*/
                GPIOC->PUPDR |= (0b00 << (GPIO_Pin->PinNumber * PIN_BITS_OFFSET));
                break;
            case MGPIO_PULLUP:
                /*Enable The Pull Up Resistor*/
                GPIOC->PUPDR |= (0b01 << (GPIO_Pin->PinNumber * PIN_BITS_OFFSET));
                break;
            case MGPIO_PULLDOWN:
                /*Enable The Pull Down Resistor*/
                GPIOC->PUPDR |= (0b10 << (GPIO_Pin->PinNumber * PIN_BITS_OFFSET));
                break;
            default:

                break;
            }
            break;
        case MGPIO_OUTPUT:
            /*Set The Pin To Be Output Pin*/
            GPIOC->MODER |= (0b01 << (GPIO_Pin->PinNumber * PIN_BITS_OFFSET));
            /*Checking For The Output Type*/
            switch (GPIO_Pin->OutputType)
            {
            case MGPIO_OUTPUT_OD:
                /*Set The Pin Output Type To Be Open Drain Pin*/
                SET_BIT(GPIOC->OTYPER, GPIO_Pin->PinNumber);
                break;
            case MGPIO_OUTPUT_PP:
                /*Set The Pin Output Type To Be PushPull Pin*/
                CLR_BIT(GPIOC->OTYPER, GPIO_Pin->PinNumber);
                break;
            }
            /*Check For The Pin Initial Value*/
            switch (GPIO_Pin->InitialState)
            {
            case MGPIO_OUTPUT_LOW:
                /*Set Pin Low, Atomic Reset*/
                GPIOC->BSRR = 1 << (GPIO_Pin->PinNumber + BSRR_PIN_OFFSET);
                break;
            case MGPIO_OUTPUT_HIGH:
                /*Set Pin High, Atomic Set*/
                GPIOC->BSRR = 1 << (GPIO_Pin->PinNumber);
                break;
            }
            break;
        case MGPIO_AF:
            /*Set The Pin To Be Alternative Function Pin*/
            GPIOC->MODER |= (0b10 << (GPIO_Pin->PinNumber * PIN_BITS_OFFSET));
            break;
        case MGPIO_ANALOG:
            /*Set The Pin To Be Analog Pin*/
            GPIOC->MODER |= (0b11 << (GPIO_Pin->PinNumber * PIN_BITS_OFFSET));
            break;
        }
        break;

    default:
        // Error
        break;
    }
}

/**
 * @brief A Function to set a specific pin mode on specific port
 *
 * @param   PortName    :   A macro for Port Name <MGPIO_PORTA, MGPIO_PORTB, MGPIO_PORTC>
 *          PinNumber   :   A macro for Pin Number <MGPIO_PIN0, MGPIO_PIN1, ..., MGPIO_PIN15>
 *          PinMode     :   A macro for Pin Mode <MGPIO_INPUT, MGPIO_OUTPUT, MGPIO_AF, MGPIO_ANALOG>
 *
 * @note  None
 *
 * @return void
 */
void MGPIO_voidSetPinMode(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinMode)
{
    /*Checking The PortName*/
    switch (Copy_u8PortName)
    {
    case MGPIO_PORTA:
        /*Checking For Pin Mode*/
        switch (Copy_u8PinMode)
        {
        case MGPIO_INPUT:
            /*Set The Pin To Be Input Pin*/
            GPIOA->MODER |= (0b00 << (Copy_u8PinNumber * PIN_BITS_OFFSET));
            break;
        case MGPIO_OUTPUT:
            /*Set The Pin To Be Output Pin*/
            GPIOA->MODER |= (0b01 << (Copy_u8PinNumber * PIN_BITS_OFFSET));
            break;
        case MGPIO_AF:
            /*Set The Pin To Be Alternative Function Pin*/
            GPIOA->MODER |= (0b10 << (Copy_u8PinNumber * PIN_BITS_OFFSET));
            break;
        case MGPIO_ANALOG:
            /*Set The Pin To Be Analog Pin*/
            GPIOA->MODER |= (0b11 << (Copy_u8PinNumber * PIN_BITS_OFFSET));
            break;
        }
        break;

    case MGPIO_PORTB:
        /*Checking For Pin Mode*/
        switch (Copy_u8PinMode)
        {
        case MGPIO_INPUT:
            /*Set The Pin To Be Input Pin*/
            GPIOB->MODER |= (0b00 << (Copy_u8PinNumber * PIN_BITS_OFFSET));
            break;
        case MGPIO_OUTPUT:
            /*Set The Pin To Be Output Pin*/
            GPIOB->MODER |= (0b01 << (Copy_u8PinNumber * PIN_BITS_OFFSET));
            break;
        case MGPIO_AF:
            /*Set The Pin To Be Alternative Function Pin*/
            GPIOB->MODER |= (0b10 << (Copy_u8PinNumber * PIN_BITS_OFFSET));
            break;
        case MGPIO_ANALOG:
            /*Set The Pin To Be Analog Pin*/
            GPIOB->MODER |= (0b11 << (Copy_u8PinNumber * PIN_BITS_OFFSET));
            break;
        }
        break;

    case MGPIO_PORTC:
        /*Checking For Pin Mode*/
        switch (Copy_u8PinMode)
        {
        case MGPIO_INPUT:
            /*Set The Pin To Be Input Pin*/
            GPIOC->MODER |= (0b00 << (Copy_u8PinNumber * PIN_BITS_OFFSET));
            break;
        case MGPIO_OUTPUT:
            /*Set The Pin To Be Output Pin*/
            GPIOC->MODER |= (0b01 << (Copy_u8PinNumber * PIN_BITS_OFFSET));
            break;
        case MGPIO_AF:
            /*Set The Pin To Be Alternative Function Pin*/
            GPIOC->MODER |= (0b10 << (Copy_u8PinNumber * PIN_BITS_OFFSET));
            break;
        case MGPIO_ANALOG:
            /*Set The Pin To Be Analog Pin*/
            GPIOC->MODER |= (0b11 << (Copy_u8PinNumber * PIN_BITS_OFFSET));
            break;
        }
        break;

    default:
        // Error
        break;
    }
}


/**
 * @brief A Function To Set The Pin Output Type
 *
 * @param   PortName    :   A macro for Port Name <MGPIO_PORTA, MGPIO_PORTB, MGPIO_PORTC>
 *          PinNumber   :   A macro for Pin Number <MGPIO_PIN0, MGPIO_PIN1, ..., MGPIO_PIN15>
 *          OutputType  :   A macro for Pin Output Type <MGPIO_OUTPUT_OD, MGPIO_OUTPUT_PP>
 *
 * @note  None
 *
 * @return void
 */
void MGPIO_voidSetPinOutputType(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8OutputType)
{
    switch (Copy_u8PortName)
    {
    case MGPIO_PORTA:
        switch (Copy_u8OutputType)
        {
        case MGPIO_OUTPUT_OD:
            /*Set The Pin Output Type To Be Open Drain Pin*/
            SET_BIT(GPIOA->OTYPER, Copy_u8PinNumber);
            break;
        case MGPIO_OUTPUT_PP:
            /*Set The Pin Output Type To Be PushPull Pin*/
            CLR_BIT(GPIOA->OTYPER, Copy_u8PinNumber);
            break;
        }
        break;

    case MGPIO_PORTB:
        switch (Copy_u8OutputType)
        {
        case MGPIO_OUTPUT_OD:
            /*Set The Pin Output Type To Be Open Drain Pin*/
            SET_BIT(GPIOB->OTYPER, Copy_u8PinNumber);
            break;
        case MGPIO_OUTPUT_PP:
            /*Set The Pin Output Type To Be PushPull Pin*/
            CLR_BIT(GPIOB->OTYPER, Copy_u8PinNumber);
            break;
        }
        break;
    case MGPIO_PORTC:
        switch (Copy_u8OutputType)
        {
        case MGPIO_OUTPUT_OD:
            /*Set The Pin Output Type To Be Open Drain Pin*/
            SET_BIT(GPIOC->OTYPER, Copy_u8PinNumber);
            break;
        case MGPIO_OUTPUT_PP:
            /*Set The Pin Output Type To Be PushPull Pin*/
            CLR_BIT(GPIOC->OTYPER, Copy_u8PinNumber);
            break;
        }
        break;
    }
}
/**
 * @brief A Function to set the output pin speed 
 *
 * @param   PortName    :   A macro for Port Name <MGPIO_PORTA, MGPIO_PORTB, MGPIO_PORTC>
 *          PinNumber   :   A macro for Pin Number <MGPIO_PIN0, MGPIO_PIN1, ..., MGPIO_PIN15>
 *          PinSpeed    :   A macro for Pin Output Speed <MGPIO_LOW_SPEED, MGPIO_MEDIUM_SPEED, MGPIO_HIGH_SPEED, MGPIO_VHIGH_SPEED>
 *
 * @note  None
 *
 * @return void
 */
void MGPIO_voidSetPinSpeed(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinSpeed)
{
    switch (Copy_u8PortName)
    {
    case MGPIO_PORTA:
        switch (Copy_u8PinSpeed)
        {
        case MGPIO_LOW_SPEED:
            GPIOA->OSPEEDR |= (0b00 << (Copy_u8PinNumber * PIN_BITS_OFFSET));
            break;
        case MGPIO_MEDIUM_SPEED:
            GPIOA->OSPEEDR |= (0b01 << (Copy_u8PinNumber * PIN_BITS_OFFSET));
            break;
        case MGPIO_HIGH_SPEED:
            GPIOA->OSPEEDR |= (0b10 << (Copy_u8PinNumber * PIN_BITS_OFFSET));
            break;
        case MGPIO_VHIGH_SPEED:
            GPIOA->OSPEEDR |= (0b11 << (Copy_u8PinNumber * PIN_BITS_OFFSET));
            break;
        }
        break;

    case MGPIO_PORTB:
        switch (Copy_u8PinSpeed)
        {
        case MGPIO_LOW_SPEED:
            GPIOB->OSPEEDR |= (0b00 << (Copy_u8PinNumber * PIN_BITS_OFFSET));
            break;
        case MGPIO_MEDIUM_SPEED:
            GPIOB->OSPEEDR |= (0b01 << (Copy_u8PinNumber * PIN_BITS_OFFSET));
            break;
        case MGPIO_HIGH_SPEED:
            GPIOB->OSPEEDR |= (0b10 << (Copy_u8PinNumber * PIN_BITS_OFFSET));
            break;
        case MGPIO_VHIGH_SPEED:
            GPIOB->OSPEEDR |= (0b11 << (Copy_u8PinNumber * PIN_BITS_OFFSET));
            break;
        }
        break;

    case MGPIO_PORTC:
        switch (Copy_u8PinSpeed)
        {
        case MGPIO_LOW_SPEED:
            GPIOC->OSPEEDR |= (0b00 << (Copy_u8PinNumber * PIN_BITS_OFFSET));
            break;
        case MGPIO_MEDIUM_SPEED:
            GPIOC->OSPEEDR |= (0b01 << (Copy_u8PinNumber * PIN_BITS_OFFSET));
            break;
        case MGPIO_HIGH_SPEED:
            GPIOC->OSPEEDR |= (0b10 << (Copy_u8PinNumber * PIN_BITS_OFFSET));
            break;
        case MGPIO_VHIGH_SPEED:
            GPIOC->OSPEEDR |= (0b11 << (Copy_u8PinNumber * PIN_BITS_OFFSET));
            break;
        }
        break;
    }
}
/**
 * @brief A Function to set the pull up/down resistor for an input pin
 *
 * @param   PortName    :   A macro for Port Name <MGPIO_PORTA, MGPIO_PORTB, MGPIO_PORTC>
 *          PinNumber   :   A macro for Pin Number <MGPIO_PIN0, MGPIO_PIN1, ..., MGPIO_PIN15>
 *          PullUpDownState:A macro for Pull Up/Down Resistor State <MGPIO_FLOAT, MGPIO_PULLUP, MGPIO_PULLDOWN>
 *
 *
 * @note  None
 *
 * @return void
 */
void MGPIO_voidSetPinPullUPDown(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PullUpDownState)
{
    /*Check For The Port Name*/
    switch (Copy_u8PortName)
    {
    case MGPIO_PORTA:
        /*Check For The State Of Pull Up/Down Resistor*/
        switch (Copy_u8PullUpDownState)
        {
        case MGPIO_FLOAT:
            /*Set The Input Pin To Be Float Pin*/
            GPIOA->PUPDR |= (0b00 << (Copy_u8PinNumber * PIN_BITS_OFFSET));
            break;
        case MGPIO_PULLUP:
            /*Set The Input Pin To Be Pulled Up Pin*/
            GPIOA->PUPDR |= (0b01 << (Copy_u8PinNumber * PIN_BITS_OFFSET));
            break;
        case MGPIO_PULLDOWN:
            /*Set The Input Pin To Be Pulled Down Pin*/
            GPIOA->PUPDR |= (0b10 << (Copy_u8PinNumber * PIN_BITS_OFFSET));
            break;
        }
        break;

    case MGPIO_PORTB:
        /*Check For The State Of Pull Up/Down Resistor*/
        switch (Copy_u8PullUpDownState)
        {
        case MGPIO_FLOAT:
            /*Set The Input Pin To Be Float Pin*/
            GPIOB->PUPDR |= (0b00 << (Copy_u8PinNumber * PIN_BITS_OFFSET));
            break;
        case MGPIO_PULLUP:
            /*Set The Input Pin To Be Pulled Up Pin*/
            GPIOB->PUPDR |= (0b01 << (Copy_u8PinNumber * PIN_BITS_OFFSET));
            break;
        case MGPIO_PULLDOWN:
            /*Set The Input Pin To Be Pulled Down Pin*/
            GPIOB->PUPDR |= (0b10 << (Copy_u8PinNumber * PIN_BITS_OFFSET));
            break;
        }
        break;
    case MGPIO_PORTC:
        /*Check For The State Of Pull Up/Down Resistor*/
        switch (Copy_u8PullUpDownState)
        {
        case MGPIO_FLOAT:
            /*Set The Input Pin To Be Float Pin*/
            GPIOC->PUPDR |= (0b00 << (Copy_u8PinNumber * PIN_BITS_OFFSET));
            break;
        case MGPIO_PULLUP:
            /*Set The Input Pin To Be Pulled Up Pin*/
            GPIOC->PUPDR |= (0b01 << (Copy_u8PinNumber * PIN_BITS_OFFSET));
            break;
        case MGPIO_PULLDOWN:
            /*Set The Input Pin To Be Pulled Down Pin*/
            GPIOC->PUPDR |= (0b10 << (Copy_u8PinNumber * PIN_BITS_OFFSET));
            break;
        }
        break;
    }
}
/**
 * @brief A Function to set the value for output pin
 *
 * @param   PortName    :   A macro for Port Name <MGPIO_PORTA, MGPIO_PORTB, MGPIO_PORTC>
 *          PinNumber   :   A macro for Pin Number <MGPIO_PIN0, MGPIO_PIN1, ..., MGPIO_PIN15>
 *          PinValue    :   A macro for Pin Output Value <MGPIO_OUTPUT_LOW, MGPIO_OUTPUT_HIGH>
 *
 * @note  None
 *
 * @return void
 */
void MGPIO_voidSetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinValue)
{
    /*Check For The Port Name*/
    switch (Copy_u8PortName)
    {
    case MGPIO_PORTA:
        /*Check For The Value Of The Pin*/
        switch (Copy_u8PinValue)
        {
        case MGPIO_OUTPUT_LOW:
            /*Set The Output Pin To Be Low, Atomic Reset*/
            GPIOA->BSRR = 1 << (Copy_u8PinNumber + 16);
            break;
        case MGPIO_OUTPUT_HIGH:
            /*Set The Output Pin To Be High, Atomic Set*/
            GPIOA->BSRR = 1 << (Copy_u8PinNumber);
            break;
        }
        break;

    case MGPIO_PORTB:
        /*Check For The Value Of The Pin*/
        switch (Copy_u8PinValue)
        {
        case MGPIO_OUTPUT_LOW:
            /*Set The Output Pin To Be Low, Atomic Reset*/
            GPIOB->BSRR = 1 << (Copy_u8PinNumber + 16);
            break;
        case MGPIO_OUTPUT_HIGH:
            /*Set The Output Pin To Be High, Atomic Set*/
            GPIOB->BSRR = 1 << (Copy_u8PinNumber);
            break;
        }
        break;

    case MGPIO_PORTC:
        /*Check For The Value Of The Pin*/
        switch (Copy_u8PinValue)
        {
        case MGPIO_OUTPUT_LOW:
            /*Set The Output Pin To Be Low, Atomic Reset*/
            GPIOC->BSRR = 1 << (Copy_u8PinNumber + 16);
            break;
        case MGPIO_OUTPUT_HIGH:
            /*Set The Output Pin To Be High, Atomic Set*/
            GPIOC->BSRR = 1 << (Copy_u8PinNumber);
            break;
        }
        break;
    }
}
/**
 * @brief A Function that read a signal from an input pin
 *
 * @param   PortName    :   A macro for Port Name <MGPIO_PORTA, MGPIO_PORTB, MGPIO_PORTC>
 *          PinNumber   :   A macro for Pin Number <MGPIO_PIN0, MGPIO_PIN1, ..., MGPIO_PIN15>
 *
 * @note  None
 *
 * @return u8: The value of the input signal
 */
u8 MGPIO_u8GetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber)
{
    u8 Local_u8PinValue;
    /*Check For The Port Name*/
    switch (Copy_u8PortName)
    {
    case MGPIO_PORTA:
        /*Assign The Pin Value For The Local_u8PinValue Variable*/
        Local_u8PinValue = GET_BIT(GPIOA->IDR, Copy_u8PinNumber);
        break;

    case MGPIO_PORTB:
        /*Assign The Pin Value For The Local_u8PinValue Variable*/
        Local_u8PinValue = GET_BIT(GPIOB->IDR, Copy_u8PinNumber);
        break;

    case MGPIO_PORTC:
        /*Assign The Pin Value For The Local_u8PinValue Variable*/
        Local_u8PinValue = GET_BIT(GPIOC->IDR, Copy_u8PinNumber);
        break;
    }
    /*Return The Pin Value*/
    return Local_u8PinValue;
}
/**
 * @brief A Function that set a specific mode for a whole port
 *
 * @param   PortName        :   A macro for Port Name <MGPIO_PORTA, MGPIO_PORTB, MGPIO_PORTC>
 *          PortModeValue   :   Mode value to be set for a port
 *
 * @note  None
 *
 * @return void
 */
void MGPIO_voidSetPortSpecificMode(u8 Copy_u8PortName, u32 Copy_u32PortModeValue)
{
    /*Check For The Port Name*/
    switch (Copy_u8PortName)
    {
    case MGPIO_PORTA:
        /*Set The Specific Mode Value To MODE Register*/
        GPIOA->MODER = Copy_u32PortModeValue;
        break;

    case MGPIO_PORTB:
        /*Set The Specific Mode Value To MODE Register*/
        GPIOB->MODER = Copy_u32PortModeValue;
        break;

    case MGPIO_PORTC:
        /*Set The Specific Mode Value To MODE Register*/
        GPIOC->MODER = Copy_u32PortModeValue;
        break;
    }
}
/**
 * @brief A Function that set a specific output value for a whole port
 *
 * @param   PortName                :   A macro for Port Name <MGPIO_PORTA, MGPIO_PORTB, MGPIO_PORTC>
 *          PortValue               :   Output value to be set for a port.
 * @note  None
 *
 * @return void
 */
void MGPIO_voidSetPortSpecificValue(u8 Copy_u8PortName, u32 Copy_u32PortValue)
{
    /*Check For The Port Name*/
    switch(Copy_u8PortName)
    {
        case MGPIO_PORTA:
        /*Set The Specific Value To ODR Register*/
            GPIOA->ODR=Copy_u32PortValue;
        break;

        case MGPIO_PORTB:
        /*Set The Specific Value To ODR Register*/
            GPIOB->ODR=Copy_u32PortValue;
        break;

        case MGPIO_PORTC:
        /*Set The Specific Value To ODR Register*/
            GPIOC->ODR=Copy_u32PortValue;
        break;
    }
}