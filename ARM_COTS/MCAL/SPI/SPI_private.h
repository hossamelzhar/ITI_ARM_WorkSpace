/**********************************************************************************************
 * Author:          Hossam M. Elzhar
 * Creation Data:   30 MAY, 2023
 * Version:         v1.0
 * Compiler:        GNU ARM-GCC
 *********************************************************************************************/

#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H


typedef struct {
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 CRCPR;
	volatile u32 RXCRCR;
	volatile u32 TXCRCR;
	volatile u32 I2SCFGR;
	volatile u32 I2SPR;
}SPI_REG_t;


#define     SPI1_BASE_ADDRESS   0x40013000
#define     SPI2_BASE_ADDRESS   0x40003800
#define     SPI3_BASE_ADDRESS   0x40003C00
#define     SPI4_BASE_ADDRESS   0x40013400



#define     SPI1                ((volatile SPI_REG_t*)SPI1_BASE_ADDRESS)
#define     SPI2                ((volatile SPI_REG_t*)SPI2_BASE_ADDRESS)
#define     SPI3                ((volatile SPI_REG_t*)SPI3_BASE_ADDRESS)
#define     SPI4                ((volatile SPI_REG_t*)SPI4_BASE_ADDRESS)



#define     CR1_CPHA            0
#define     CR1_CPOL            1
#define     CR1_MSTR            2
#define     CR1_BR              3
#define     CR1_SPE             6
#define     CR1_LSB_FIRST       7
#define     CR1_SSI             8
#define     CR1_SSM             9
#define     CR1_RX_ONLY         10
#define     CR1_DFF             11
#define     CR1_CRC_NEXT        12
#define     CR1_CRC_EN          13
#define     CR1_BIDI_OE         14
#define     CR1_BIDI_MODE       15


#define     CR1_BR_MSK          0xFFFFFFC7
#define     CR1_BR_2            0
#define     CR1_BR_4            1
#define     CR1_BR_8            2
#define     CR1_BR_16           3
#define     CR1_BR_32           4
#define     CR1_BR_64           5
#define     CR1_BR_128          6
#define     CR1_BR_256          7


#define     CR2_RXDMAEN         0
#define     CR2_TXDMAEN         1
#define     CR2_SSOE            2
#define     CR2_FRF             4
#define     CR2_ERRIE           5
#define     CR2_RXNEIE          6
#define     CR2_TXEIE           7

#define     SR_RXNE             0
#define     SR_TXE              1
#define     SR_CHSIDE           2
#define     SR_UDR              3
#define     SR_CRC_ERR          4
#define     SR_MODF             5
#define     SR_OVR              6
#define     SR_BSY              7
#define     SR_FRE              8


#define		CLOCK_SCALER_CLR_BIT_MASK		0xFFC7
#define    CLOCK_SCALER_BITS_SHIFT      	3




#endif

