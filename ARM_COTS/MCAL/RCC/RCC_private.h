/**********************************************************************************************
 * Author:          Hossam M. Elzhar
 * Creation Data:   04 MAY, 2023
 * Version:         v1.0
 * Compiler:        GNU ARM-GCC
 *********************************************************************************************/

#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H



typedef struct 
{
    volatile u32 CR;
    volatile u32 PLLCFGR;
    volatile u32 CFGR;
    volatile u32 CIR;
    volatile u32 AHB1RSTR;
    volatile u32 AHB2RSTR;
    volatile u32 Reserved[2];
    volatile u32 APB1RSTR;
    volatile u32 APB2RSTR;
    volatile u32 Reserved2[2];
    volatile u32 AHB1ENR;
    volatile u32 AHB2ENR;
    volatile u32 Reserved3[2];
    volatile u32 APB1ENR;
    volatile u32 APB2ENR;
    volatile u32 Reserved4[2];
    volatile u32 AHB1LPENR;
    volatile u32 AHB2LPENR;
    volatile u32 Reserved5[2];
    volatile u32 APB1LPENR;
    volatile u32 APB2LPENR;
    volatile u32 Reserved6[2];
    volatile u32 BDCR;
    volatile u32 CSR;
    volatile u32 Reserved7[2];
    volatile u32 SSCGR;
    volatile u32 PLLI2SCFGR;
    volatile u32 Resrved8;
    volatile u32 DCKCFGR;
}RCC_t;

/************************************************************************************************************************************************************/
/* RCC_CR Register */
#define CR_PLLI2SRDY            27  // PLLI2S clock ready flag
#define CR_PLLI2SON             26  // PLLI2S enable
#define CR_PLLRDY               25  // Main PLL (PLL) clock ready flag
#define CR_PLLON                24  // Main PLL (PLL) enable
#define CR_CSSON                19  // Clock security system enable
#define CR_HSEBYP               18  // HSE clock bypass
#define CR_HSERDY               17  // HSE clock ready flag
#define CR_HSEON                16  // HSE clock enable
#define CR_HSICAL               8   // Internal high-speed clock calibration, 8 Bits
#define CR_HSITRIM              3   // Internal high-speed clock trimming, 5 Bits
#define CR_HSIRDY               1   // Internal high-speed clock ready flag
#define CR_HSION                0   // Internal high-speed clock enable

/************************************************************************************************************************************************************/
/* RCC_PLLCFGR Register */
#define PLLCFGR_PLLQ            24  // Main PLL (PLL) division factor for USB OTG FS, SDIO and random number generator clocks, 4 Bits            
#define PLLCFGR_PLLSRC          22  // Main PLL(PLL) and audio PLL (PLLI2S) entry clock source
#define PLLCFGR_PLLP            16  // Main PLL (PLL) division factor for main system clock, 2 Bits
#define PLLCFGR_PLLN            6   // Main PLL (PLL) multiplication factor for VCO, 9 Bits
#define PLLCFGR_PLLM            0   // Division factor for the main PLL (PLL) and audio PLL (PLLI2S) input clock


#define PLL_SCR_SEL_MSK         0xFF9FFFFF
#define PLL_SCR_HSI             0
#define PLL_SCR_HSE             1

#define PLL_DIV_FACTOR_MSK      0xFFFCFFFF
#define PLL_DIV_2               0            
#define PLL_DIV_4               1
#define PLL_DIV_6               2
#define PLL_DIV_8               3




#define PLL_MULT_FACTOR_MSK     0xFFFF803F

/************************************************************************************************************************************************************/
/* RCC_CFGR Register */
#define CFGR_MCO2               30  // Microcontroller clock output 2, 2 Bits
#define CFGR_MCO2PRE            27  // MCO2 prescaler , 3 Bits
#define CFGR_MCO1PRE            24  // MCO1 prescaler , 3 Bits
#define CFGR_I2SSRC             23  // I2S clock selection
#define CFGR_MCO1               21  // Microcontroller clock output 1, 2 Bits
#define CFGR_RTCPRE             16  // HSE division factor for RTC clock, 5 Bits
#define CFGR_PPRE2              13  // APB high-speed prescaler (APB2), 3 Bits
#define CFGR_PPRE1              10  // APB Low speed prescaler (APB1), 3 Bits
#define CFGR_HPRE               4   // AHB prescaler, 4 Bits
#define CFGR_SWS                2   // System clock switch status, 2 Bits
#define CFGR_SW                 0   // System clock switch, 2 Bits

#define CFGR_SYS_CLK_SEL_MSK    0xFFFFFFFC
#define CFGR_SYS_CLK_HSI        0   // HSI oscillator selected as system clock
#define CFGR_SYS_CLK_HSE        1   // HSE oscillator selected as system clock
#define CFGR_SYS_CLK_PLL        2   // PLL selected as system clock


#define HPRE_SEL_MSK                    0xFFFFFF0F
#define HPRE_NO_PRESCALER               0
#define HPRE_SYS_CLK_DIVIDED_BY_2       8
#define HPRE_SYS_CLK_DIVIDED_BY_4       9
#define HPRE_SYS_CLK_DIVIDED_BY_8       10
#define HPRE_SYS_CLK_DIVIDED_BY_16      11
#define HPRE_SYS_CLK_DIVIDED_BY_64      12
#define HPRE_SYS_CLK_DIVIDED_BY_128     13
#define HPRE_SYS_CLK_DIVIDED_BY_256     14
#define HPRE_SYS_CLK_DIVIDED_BY_512     15

#define PPRE1_SEL_MSK           0xFFFFE3FF
#define PPRE2_SEL_MSK           0xFFFF1FFF
#define PPRE_NOPRESCALER        0
#define PPRE_AHB_DIVIDED_BY_2   4
#define PPRE_AHB_DIVIDED_BY_4   5
#define PPRE_AHB_DIVIDED_BY_8   6
#define PPRE_AHB_DIVIDED_BY_16  7




/************************************************************************************************************************************************************/
/* RCC_AHB1ENR Register */

/************************************************************************************************************************************************************/
/* RCC_AHB2ENR Register */

/************************************************************************************************************************************************************/
/* RCC_APB1ENR Register */


/************************************************************************************************************************************************************/
/* RCC_APB2ENR Register */


/************************************************************************************************************************************************************/





#define HSI                     0   
#define HSE                     1
#define PLL                     2


#define RCC         ((volatile RCC_t *)0x40023800)
/************************************************************************************************************************************************************/

// #define RCC_BASE_ADDRESS        0x4002 3800


// #define RCC_CR                  *((volatile u32 *) (RCC_BASE_ADDRESS + 0x00))
// #define RCC_CR_PLLI2SRDY        27
// #define RCC_CR_PLLI2SON         26



// #define RCC_PLLCFGR             *((volatile u32 *) (RCC_BASE_ADDRESS + 0x04))



#endif