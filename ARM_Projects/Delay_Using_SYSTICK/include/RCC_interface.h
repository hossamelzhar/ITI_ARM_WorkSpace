/**********************************************************************************************
 * Author:          Hossam M. Elzhar
 * Creation Data:   04 MAY, 2023
 * Version:         v1.0
 * Compiler:        GNU ARM-GCC
 *********************************************************************************************/

#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

#define RCC_AHB1                0
#define RCC_AHB2                1
#define RCC_APB1                2
#define RCC_APB2                3


/* AHB1 Peripherals */
#define DMA2_ID                  22  // DMA2 clock enable
#define DMA1_ID                  21  // DMA1 clock enable
#define CRC_ID                   12  // CRC clock enable
// #define RCC_GPIOH_ID                 7   // IO port H clock enable
// #define RCC_GPIOE_ID                 4   // IO port E clock enable
// #define RCC_GPIOD_ID                 3   // IO port D clock enable    
#define GPIOC_ID                 2   // IO port C clock enable
#define GPIOB_ID                 1   // IO port B clock enable
#define GPIOA_ID                 0   // IO port A clock enable


/***************************************************************************************************/
/* AHB2 Peripherals */
#define OTGFSEN                 7   // USB OTG FS clock enable

/***************************************************************************************************/
/* APB1 Peripherals */
#define PWR_ID                  28  // Power interface clock enable
#define I2C3_ID                 23  // I2C3 clock enable
#define I2C2_ID                 22  // I2C2 clock enable
#define I2C1_ID                 21  // I2C1 clock enable
#define USART2_ID               17  // USART2 clock enable
#define SPI3_ID                 15  // SPI3 clock enable
#define SPI2_ID                 14  // SPI2 clock enable
#define WWDG_ID                 11  // Window watchdog clock enable
#define TIM5_ID                 3   // TIM5 clock enable
#define TIM4_ID                 2   // TIM4 clock enable
#define TIM3_ID                 1   // TIM3 clock enable
#define TIM2_ID                 0   // TIM2 clock enable


/***************************************************************************************************/
/* APB2 Peripherals */
#define TIM11_ID                18  // TIM11 clock enable
#define TIM10_ID                17  // TIM10 clock enable
#define TIM9_ID                 16  // TIM9 clock enable
#define SYSCFG_ID               14  // System configuration controller clock enable
#define SPI4_ID                 13  // SPI4 clock enable
#define SPI1_ID                 12  // SPI1 clock enable
#define SDIO_ID                 11  // SDIO clock enable
#define ADC1_ID                 8   // ADC1 clock enable
#define USART6_ID               5   // USART6 clock enable
#define USART1_ID               4   // USART1 clock enable
#define TIM1_ID                 0   // TIM1 clock enable


void MRCC_voidInit(void);
void MRCC_voidEnablePeripheralClock(u8 Copy_u8PeripheralBus,u8 Copy_PeripheralID);
void MRCC_voidDisablePeripheralClock(u8 Copy_u8PeripheralBus,u8 Copy_PeripheralID);

#endif