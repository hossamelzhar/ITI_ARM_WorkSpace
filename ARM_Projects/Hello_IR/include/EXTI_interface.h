/*****************************************************************************************
 * Author:				Abdullah M. Abdullah
 * Creation Data:		22 May, 2023
 * Version:				v1.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM32F401CCU6 (32-bit Architecture)
 * Processor:			Cortex M4 (32-bit Architecture)
 * Layer:				MCAL Layer
 *****************************************************************************************/
/*****************************************************************************************
 * Version	  Date				  Author				  Description
 * v1.0		  22 May, 2023	Abdullah M. Abdullah		  Initial Creation
 * v1.1		  22 May, 2023	Abdullah M. Abdullah		  Adding A New Definition
*****************************************************************************************/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

#define MEXTI_LINE0			0
#define MEXTI_LINE1			1

#define MEXTI_RISING_EDGE   0
#define MEXTI_FALLING_EDGE  1
#define MEXTI_ON_CHANGE     2

void MEXTI_voidInit(void);
void MEXTI_voidEnableInterrupt(u8 Copy_u8EXTILine);
void MEXTI_voidDisableInterrupt(u8 Copy_u8EXTILine);
void MEXTI_voidChangeSenseMode(u8 Copy_u8EXTILine, u8 Copy_u8SenseSignal);
void MEXTI_voidSetCallBack(u8 Copy_u8EXTILine, void (*pvNotificationFunction)(void));

#endif
