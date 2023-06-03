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
#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H
/*****************************************************************************************
*                             Public Data Type Definitions
*****************************************************************************************/
typedef struct
{
    u8 PortName;
    u8 PinNumber;
    u8 Mode;
    u8 OutputType;
    u8 OutputSpeed;
    u8 PullUpDown;
    u8 InitialState;
} MGPIO_Pin_t;
/*****************************************************************************************
*                                   Public Macros
*****************************************************************************************/
/*Port Name Macros*/
#define MGPIO_PORTA             0
#define MGPIO_PORTB             1
#define MGPIO_PORTC             2
#define MGPIO_PORTD             3
/*Pin Number Macros*/
#define MGPIO_PIN0              0
#define MGPIO_PIN1              1
#define MGPIO_PIN2              2
#define MGPIO_PIN3              3
#define MGPIO_PIN4              4
#define MGPIO_PIN5              5
#define MGPIO_PIN6              6
#define MGPIO_PIN7              7
#define MGPIO_PIN8              8 
#define MGPIO_PIN9              9 
#define MGPIO_PIN10             10
#define MGPIO_PIN11             11
#define MGPIO_PIN12             12
#define MGPIO_PIN13             13
#define MGPIO_PIN14             14
#define MGPIO_PIN15             15
/*Pin Mode Macros*/
#define MGPIO_INPUT             0
#define MGPIO_OUTPUT            1
#define MGPIO_AF                2
#define MGPIO_ANALOG            3
/*Macros For Pin Output Type*/
#define MGPIO_OUTPUT_OD         0
#define MGPIO_OUTPUT_PP         1
/*Macros For Output Speed*/
#define MGPIO_LOW_SPEED         0
#define MGPIO_MEDIUM_SPEED      1
#define MGPIO_HIGH_SPEED        2
#define MGPIO_VHIGH_SPEED       3
/*Macros For Pull Up/Down Resistor*/
#define MGPIO_FLOAT             0
#define MGPIO_PULLUP            1
#define MGPIO_PULLDOWN          2
/*Macros For Output Pin State*/
#define MGPIO_OUTPUT_LOW        0
#define MGPIO_OUTPUT_HIGH       1
/*****************************************************************************************
*                                   Public APIs Prototype
*****************************************************************************************/
/**
 * @brief A Link-Time configuration function that configure the pin using the public GPIO_Pin_t sturct definition
 *
 * @param Parameter GPIO_Pin: Pointer to object of struct GPIO_Pin_t created
 *
 * @note  None
 *
 * @return void
 */
void    MGPIO_voidConfigurePin          (MGPIO_Pin_t * GPIO_Pin);

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
void    MGPIO_voidSetPinMode            (u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinMode);

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
void    MGPIO_voidSetPinOutputType      (u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinMode);

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
void    MGPIO_voidSetPinSpeed           (u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinSpeed);

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
void    MGPIO_voidSetPinPullUPDown      (u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PullUpDownState);

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
void    MGPIO_voidSetPinValue           (u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinValue);

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
u8      MGPIO_u8GetPinValue             (u8 Copy_u8PortName, u8 Copy_u8PinNumber);

/**
 * @brief A Function that set a specific mode for a whole port
 *
 * @param   PortName        :   A macro for Port Name <MGPIO_PORTA, MGPIO_PORTB, MGPIO_PORTC>
 *          PortModeValue   :   Mode value to be set for a port, value in range 0:65535
 *
 * @note  None
 *
 * @return void
 */
void    MGPIO_voidSetPortSpecificMode   (u8 Copy_u8PortName, u32 Copy_u32PortModeValue);

/**
 * @brief A Function that set a specific output value for a whole port
 *
 * @param   PortName                :   A macro for Port Name <MGPIO_PORTA, MGPIO_PORTB, MGPIO_PORTC>
 *          PortValue               :   Output value to be set for a port, value in range 0:65535
 * @note  None
 *
 * @return void
 */
void    MGPIO_voidSetPortSpecificValue  (u8 Copy_u8PortName, u32 Copy_u32PortValue);


#endif