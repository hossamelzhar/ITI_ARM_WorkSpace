/**********************************************************************************************
 * Author:          Hossam M. Elzhar
 * Creation Data:   06 MAY, 2023
 * Version:         v1.0
 * Compiler:        GNU ARM-GCC
 *********************************************************************************************/

#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

typedef struct 
{
    u8 Port;
    u8 PinNunmber;
    u8 Mode;
    u8 OutputType;
    u8 OutputSpeed;
    u8 InputConnectionType;
    u8 Value;
}MGPIO_Pin_t;



#define GPIOA                           0
#define GPIOB                           1
#define GPIOC                           2

#define PIN0                            0
#define PIN1                            1
#define PIN2                            2
#define PIN3                            3
#define PIN4                            4
#define PIN5                            5
#define PIN6                            6
#define PIN7                            7
#define PIN8                            8
#define PIN9                            9
#define PIN10                           10
#define PIN11                           11
#define PIN12                           12
#define PIN13                           13
#define PIN14                           14
#define PIN15                           15

#define INPUT                           0     
#define OUTPUT                          1     
#define AF                              2     
#define ANALOG                          3    


#define PUSH_PULL                       0
#define OPEN_DRAIN                      1

#define LOW_SPEED                       0
#define MED_SPEED                       1
#define HIGH_SPEED                      2
#define VERY_HIGH_SPEED                 3


#define NOPULL                          0
#define PULLUP                          1
#define PULLDOWN                        2

#define HIGH                            1
#define LOW                             0

/*  Port Options:
        GPIOA
        GPIOB
        GPIOC
************************************************************************************************
Mode Options:
        INPUT 
        OUTPUT
        AF    
        ANALOG
*/
void MGPIO_voidSetPortMode(u8 Copy_u8Port, u8 Copy_u8Mode);

/*  Port Options:
        GPIOA
        GPIOB
        GPIOC
************************************************************************************************
    Pins Options:
        PIN0 
        PIN1 
        PIN2 
        PIN3 
        PIN4 
        PIN5 
        PIN6 
        PIN7 
        PIN8 
        PIN9 
        PIN10
        PIN11
        PIN12
        PIN13
        PIN14
        PIN15
************************************************************************************************
    Mode Options:
        INPUT 
        OUTPUT
        AF    
        ANALOG
*/
void MGPIO_voidSetPinMode(u8 Copy_u8Port, u8 Copy_u8PinNumber, u8 Copy_u8Mode);

void MGPIO_voidSetPortOutputType(u8 Copy_u8Port, u8 Copy_u8OutputType);

/*  Port Options:
        GPIOA
        GPIOB
        GPIOC
************************************************************************************************
    Pins Options:
        PIN0 
        PIN1 
        PIN2 
        PIN3 
        PIN4 
        PIN5 
        PIN6 
        PIN7 
        PIN8 
        PIN9 
        PIN10
        PIN11
        PIN12
        PIN13
        PIN14
        PIN15
************************************************************************************************
    Output Type Options:
        PUSH_PULL 
        OPEN_DRAIN
*/
void MGPIO_voidSetOutputType(u8 Copy_u8Port, u8 Copy_u8PinNumber, u8 Copy_u8OutputType);

void MGPIO_voidSetPortOutputSpeed(u8 Copy_u8Port, u8 Copy_u8OutputSpeed);

/*  Port Options:
        GPIOA
        GPIOB
        GPIOC
************************************************************************************************
    Pins Options:
        PIN0 
        PIN1 
        PIN2 
        PIN3 
        PIN4 
        PIN5 
        PIN6 
        PIN7 
        PIN8 
        PIN9 
        PIN10
        PIN11
        PIN12
        PIN13
        PIN14
        PIN15
************************************************************************************************
    Output Speed Options:
        LOW_SPEED      
        MED_SPEED      
        HIGH_SPEED     
        VERY_HIGH_SPEED
*/
void MGPIO_voidSetOutputSpeed(u8 Copy_u8Port, u8 Copy_u8PinNumber, u8 Copy_u8OutputSpeed);

/*  Port Options:
        GPIOA
        GPIOB
        GPIOC
************************************************************************************************
    Pins Options:
        PIN0 
        PIN1 
        PIN2 
        PIN3 
        PIN4 
        PIN5 
        PIN6 
        PIN7 
        PIN8 
        PIN9 
        PIN10
        PIN11
        PIN12
        PIN13
        PIN14
        PIN15
************************************************************************************************
    Input Connection Type Options:
        NOPULL  
        PULLUP  
        PULLDOWN
*/
void MGPIO_voidSetInputConnectionType(u8 Copy_u8Port, u8 Copy_u8PinNumber, u8 Copy_u8ConnectionType);

/*  Port Options:
        GPIOA
        GPIOB
        GPIOC
************************************************************************************************
    Pins Options:
        PIN0 
        PIN1 
        PIN2 
        PIN3 
        PIN4 
        PIN5 
        PIN6 
        PIN7 
        PIN8 
        PIN9 
        PIN10
        PIN11
        PIN12
        PIN13
        PIN14
        PIN15
*/
u8 MGPIO_voidGetPinValue(u8 Copy_u8Port, u8 Copy_u8PinNumber);

/*  Port Options:
        GPIOA
        GPIOB
        GPIOC
************************************************************************************************
    Pins Options:
        PIN0 
        PIN1 
        PIN2 
        PIN3 
        PIN4 
        PIN5 
        PIN6 
        PIN7 
        PIN8 
        PIN9 
        PIN10
        PIN11
        PIN12
        PIN13
        PIN14
        PIN15
************************************************************************************************
    Pin Value Options:
        HIGH
        LOW 
*/
void MGPIO_voidSetPortValue(u8 Copy_u8Port, u16 Copy_u16PortValue);
void MGPIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8PinNumber, u8 Copy_u8PinValue);

/*  Port Options:
        GPIOA
        GPIOB
        GPIOC
************************************************************************************************
    Pins Options:
        PIN0 
        PIN1 
        PIN2 
        PIN3 
        PIN4 
        PIN5 
        PIN6 
        PIN7 
        PIN8 
        PIN9 
        PIN10
        PIN11
        PIN12
        PIN13
        PIN14
        PIN15
************************************************************************************************
    Pin Value Options:
        HIGH
        LOW 
*/
void MGPIO_voidSetAtomicPinValue(u8 Copy_u8Port, u8 Copy_u8PinNumber, u8 Copy_u8PinValue);

/* Mode Options:
        INPUT 
        OUTPUT
        AF    
        ANALOG
*/
void MGPIO_voidConfigurePinMode(MGPIO_Pin_t* pPin, u8 Copy_u8Mode);

/* Output Type Options:
        PUSH_PULL 
        OPEN_DRAIN
*/
void MGPIO_voidConfigurePinOutputType(MGPIO_Pin_t* pPin, u8 Copy_u8OutputType);

/* Output Speed Options:
        LOW_SPEED      
        MED_SPEED      
        HIGH_SPEED     
        VERY_HIGH_SPEED
*/
void MGPIO_voidConfigureOutputSpeed(MGPIO_Pin_t* pPin, u8 Copy_u8OutputSpeed);

/* Input Connection Type Options:
        NOPULL  
        PULLUP  
        PULLDOWN
*/
void MGPIO_voidConfigureInputConnectionType(MGPIO_Pin_t* pPin,u8 Copy_u8ConnectionType);

/* Returns u8 Type */
u8 MGPIO_voidUpdatePinValue(MGPIO_Pin_t* pPin);

/* Pin Value Options:
        HIGH
        LOW 
*/
void MGPIO_voidSetConfiguredPinValue(MGPIO_Pin_t* pPin, u8 Copy_u8Value);

/* Pin Value Options:
        HIGH
        LOW 
*/
void MGPIO_voidSetConfiguredAtomicPinValue(MGPIO_Pin_t* pPin, u8 Copy_u8Value);

/* Configure all the pin members before calling this funciton */
void MGPIO_voidConfigurePin(MGPIO_Pin_t* pPin);




#endif