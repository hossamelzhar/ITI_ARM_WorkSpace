/*********************************************
 * Author:          Hossam M. Elzhar
 * Creation Data:   02 MAY, 2023
 * Version:         v1.0
 * Compiler:        GNU ARM-GCC
 ********************************************/

#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H


/* RCC Clock Source Select
    Options:
        HSI
        HSE
        PLL
*/
#define CPU_CLK_SRC         HSI

/* PLL Source Select
    Options:
        HSI
        HSE
*/
#define PLL_SRC             HSI

/* HSE Source Select
    Options:
        RC
        OSCI
*/
#define HSE_CLK_SRC         OSCI

/* PLL Division Factor Select
    Options
        PLL_DIV_2
        PLL_DIV_4
        PLL_DIV_6
        PLL_DIV_8
*/
#define PLL_DIV_FACTOR      PLL_DIV_2

/* PLL Multiplication Factor Select
    Options
    192 - 432 
*/
#define PLL_MULT_FACTOR     192    

#endif