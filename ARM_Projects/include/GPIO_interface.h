/*********************************************
 * Author:          Moaz Mohamed Romih
 * Creation Data:   02 MAY, 2023
 * Version:         v1.0
 * Compiler:        GNU ARM-GCC
 ********************************************/

#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H


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


#define NOPULL         0
#define PULLUP         1
#define PULLDOWN       2

#define HIGH                            1
#define LOW                             0


void MGPIO_voidSetPinDirection(u8 Copy_u8Port, u8 Copy_u8PinNumber, u8 Copy_u8Direction);


void MGPIO_voidSetOutputType(u8 Copy_u8Port, u8 Copy_u8PinNumber, u8 Copy_u8OutputType);


void MGPIO_voidSetOutputSpeed(u8 Copy_u8Port, u8 Copy_u8PinNumber, u8 Copy_u8OutputSpeed);


void MGPIO_voidSetConnectionType(u8 Copy_u8Port, u8 Copy_u8PinNumber, u8 Copy_u8ConnectionType);


u8 MGPIO_voidGetPinValue(u8 Copy_u8Port, u8 Copy_u8PinNumber);


void MGPIO_voidSetPinValueODR(u8 Copy_u8Port, u8 Copy_u8PinNumber, u8 Copy_u8PinValue);


void MGPIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8PinNumber, u8 Copy_u8PinValue);


#endif