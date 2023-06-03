/**********************************************************************************************
 * Author:          Hossam M. Elzhar
 * Creation Data:   30 MAY, 2023
 * Version:         v1.0
 * Compiler:        GNU ARM-GCC
 *********************************************************************************************/

#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

typedef struct
{
    volatile SPI_REG_t* SPI_Num;
    u8 SPI_Master;
    u8 Clock_Scaler;
    u8 Clock_Polarity;
    u8 Clock_Phase;
    u8 LSB_First;
    u8 Data_Frame_8Bit_16Bit;
    u8 SPI_TX_Interrupt;
    u8 SPI_RX_Interrupt;
}SPI_t;

#define     SPI_1                               SPI1
#define     SPI_2                               SPI2
#define     SPI_3                               SPI3

#define     SPI_MASTER_DISABLE                  0
#define     SPI_MASTER_ENABLE                   1

#define     SPI_CLOCK_SCALER_FCPU_2             0
#define     SPI_CLOCK_SCALER_FCPU_4             1
#define     SPI_CLOCK_SCALER_FCPU_8             2
#define     SPI_CLOCK_SCALER_FCPU_16            3
#define     SPI_CLOCK_SCALER_FCPU_32            4
#define     SPI_CLOCK_SCALER_FCPU_64            5
#define     SPI_CLOCK_SCALER_FCPU_128           6
#define     SPI_CLOCK_SCALER_FCPU_256           7

#define     SPI_CLOCK_POL_IDLE_LOW              0
#define     SPI_CLOCK_POL_IDLE_HIGH             1

#define     SPI_CLOCK_PHA_LEADING_CAPTURE       0
#define     SPI_CLOCK_PHA_TRAILING_CAPTURE      1

#define     SPI_LSB_FIRST_DISABLE               0
#define     SPI_LSB_FIRST_ENABLE                1

#define     SPI_DATA_FRAME_8_BIT                0
#define     SPI_DATA_FRAME_16_BIT               1

#define     SPI_TX_INTERRUPT_DISABLE            0
#define     SPI_TX_INTERRUPT_ENABLE             1

#define     SPI_RX_INTERRUPT_DISABLE            0
#define     SPI_RX_INTERRUPT_ENABLE             1

void MSPI_voidInit(SPI_t * Copy_pSPI_tObj);
void MSPI_voidSendu8Data(SPI_t * Copy_pSPI_tObj, u8 Copy_u8Data);
void MSPI_voidSendu16Data(SPI_t * Copy_pSPI_tObj, u16 Copy_u16Data);
u8 MSPI_u8GetReceivedDataSynchronous(SPI_t * Copy_pSPI_tObj);
u16 MSPI_u16GetReceivedDataSynchronous(SPI_t * Copy_pSPI_tObj);


#endif