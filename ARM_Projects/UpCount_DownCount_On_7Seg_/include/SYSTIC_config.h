/**********************************************************************************************
 * Author:          Hossam M. Elzhar
 * Creation Data:   07 MAY, 2023
 * Version:         v1.0
 * Compiler:        GNU ARM-GCC
 *********************************************************************************************/

#ifndef SYSTIC_CONFIG_H
#define SYSTIC_CONFIG_H

/*Options:
        ENABLE
        DISABLE
*/
#define SYS_TICK_STATUS     ENABLE

/*Options:
        AHB
        AHB_8
*/
#define SYSTICK_CLOCK_SOURCE    AHB_8

/*Options:
        ENABLE
        DISABLE
*/
#define SYSTICK_INTERRUPT_STATUS    DISABLE


#endif