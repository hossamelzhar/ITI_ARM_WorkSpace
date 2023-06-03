/**********************************************************************************************
 * Author:          Hossam M. Elzhar
 * Creation Data:   30 MAY, 2023
 * Version:         v1.0
 * Compiler:        GNU ARM-GCC
 *********************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "NVIC_interface.h"


#include "SPI_private.h"
#include "SPI_interface.h"
#include "SPI_config.h"


void MSPI_voidInit(SPI_t * Copy_pSPI_tObj)
{
    //Enable RCC Clock For SPI
    MRCC_voidInit();
    if(Copy_pSPI_tObj->SPI_Num == SPI1)
    {
        MRCC_voidEnablePeripheralClock(RCC_APB2, SPI1_ID);   
    }
    else if(Copy_pSPI_tObj->SPI_Num == SPI2)
    {
        MRCC_voidEnablePeripheralClock(RCC_APB1, SPI2_ID);
    }
    else if(Copy_pSPI_tObj->SPI_Num == SPI3)
    {
        MRCC_voidEnablePeripheralClock(RCC_APB1, SPI3_ID);
    }
    else if(Copy_pSPI_tObj->SPI_Num == SPI4)
    {
        MRCC_voidEnablePeripheralClock(RCC_APB2, SPI1_ID);
    }
    else{}

    //Set SPI Master/Slave
    if(Copy_pSPI_tObj->SPI_Master == SPI_MASTER_ENABLE)
    {
        SET_BIT(Copy_pSPI_tObj->SPI_Num->CR1, CR1_MSTR);
    }
    else if(Copy_pSPI_tObj->SPI_Master == SPI_MASTER_DISABLE)
    {
        CLEAR_BIT(Copy_pSPI_tObj->SPI_Num->CR1, CR1_MSTR);
    }else{}

    //Set SPI Clock Prescaler
    //Clear Prescaler Bits
    Copy_pSPI_tObj->SPI_Num->CR1 &= CLOCK_SCALER_CLR_BIT_MASK;
    //Assign Prescaler Bits
    Copy_pSPI_tObj->SPI_Num->CR1 |= (Copy_pSPI_tObj->Clock_Scaler<<CLOCK_SCALER_BITS_SHIFT);

     //Set SPI Clock Polarity 
    if(Copy_pSPI_tObj->Clock_Polarity == SPI_CLOCK_POL_IDLE_HIGH)
    {
        SET_BIT(Copy_pSPI_tObj->SPI_Num->CR1, CR1_CPOL);
    }
    else if(Copy_pSPI_tObj->Clock_Polarity == SPI_CLOCK_POL_IDLE_LOW)
    {
        CLEAR_BIT(Copy_pSPI_tObj->SPI_Num->CR1, CR1_CPOL);
    }else{}    

     //Set SPI Clock Phase
    if(Copy_pSPI_tObj->Clock_Phase == SPI_CLOCK_PHA_TRAILING_CAPTURE)
    {
        SET_BIT(Copy_pSPI_tObj->SPI_Num->CR1, CR1_CPHA);
    }
    else if(Copy_pSPI_tObj->Clock_Phase == SPI_CLOCK_PHA_LEADING_CAPTURE)
    {
        CLEAR_BIT(Copy_pSPI_tObj->SPI_Num->CR1, CR1_CPHA);
    }else{}    

     //Set SPI LSB Enable/Disable
    if(Copy_pSPI_tObj->LSB_First == SPI_LSB_FIRST_ENABLE)
    {
        SET_BIT(Copy_pSPI_tObj->SPI_Num->CR1, CR1_LSB_FIRST);
    }
    else if(Copy_pSPI_tObj->LSB_First == SPI_LSB_FIRST_DISABLE)
    {
        CLEAR_BIT(Copy_pSPI_tObj->SPI_Num->CR1, CR1_LSB_FIRST);
    }else{}  

     //Set SPI Data Frame 8/16 Bits
    if(Copy_pSPI_tObj->Data_Frame_8Bit_16Bit == SPI_DATA_FRAME_16_BIT)
    {
        SET_BIT(Copy_pSPI_tObj->SPI_Num->CR1, CR1_DFF);
    }
    else if(Copy_pSPI_tObj->Data_Frame_8Bit_16Bit == SPI_DATA_FRAME_8_BIT)
    {
        CLEAR_BIT(Copy_pSPI_tObj->SPI_Num->CR1, CR1_DFF);
    }else{}  

     //Set SPI Transmision Complete Interrupt Enable/Disable
    if(Copy_pSPI_tObj->SPI_TX_Interrupt == SPI_TX_INTERRUPT_ENABLE)
    {
        SET_BIT(Copy_pSPI_tObj->SPI_Num->CR2, CR2_TXEIE);
    }
    else if(Copy_pSPI_tObj->SPI_TX_Interrupt == SPI_TX_INTERRUPT_DISABLE)
    {
        CLEAR_BIT(Copy_pSPI_tObj->SPI_Num->CR2, CR2_TXEIE);
    }else{}  

     //Set SPI Receiption Complete Interrupt Enable/Disable
    if(Copy_pSPI_tObj->SPI_RX_Interrupt == SPI_RX_INTERRUPT_ENABLE)
    {
        SET_BIT(Copy_pSPI_tObj->SPI_Num->CR2, CR2_RXNEIE);
    }
    else if(Copy_pSPI_tObj->SPI_RX_Interrupt == SPI_RX_INTERRUPT_DISABLE)
    {
        CLEAR_BIT(Copy_pSPI_tObj->SPI_Num->CR2, CR2_RXNEIE);
    }else{}  
}


void MSPI_voidSendu8Data(SPI_t * Copy_pSPI_tObj, u8 Copy_u8Data)
{
    while(GET_BIT(Copy_pSPI_tObj->SPI_Num->SR, SR_BSY) == 1);
    Copy_pSPI_tObj->SPI_Num->DR = Copy_u8Data;
}

void MSPI_voidSendu16Data(SPI_t * Copy_pSPI_tObj, u16 Copy_u16Data)
{
    while(GET_BIT(Copy_pSPI_tObj->SPI_Num->SR, SR_BSY) == 1);
    Copy_pSPI_tObj->SPI_Num->DR = Copy_u16Data;
}

u8 MSPI_u8GetReceivedDataSynchronous(SPI_t * Copy_pSPI_tObj)
{
    while(GET_BIT(Copy_pSPI_tObj->SPI_Num->SR, SR_BSY) == 1);
    return (u8)(Copy_pSPI_tObj->SPI_Num->DR);
}

u16 MSPI_u16GetReceivedDataSynchronous(SPI_t * Copy_pSPI_tObj)
{
    while(GET_BIT(Copy_pSPI_tObj->SPI_Num->SR, SR_BSY) == 1);
    return (Copy_pSPI_tObj->SPI_Num->DR);
}