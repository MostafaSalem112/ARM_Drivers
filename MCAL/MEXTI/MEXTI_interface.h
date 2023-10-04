/*
 * MEXI_interface.h
 *
 *  Created on: Aug 14, 2023
 *      Author: Mostafa_Salem
 */

#ifndef MCAL_MEXTI_MEXTI_INTERFACE_H_
#define MCAL_MEXTI_MEXTI_INTERFACE_H_

#define  NULL 0

typedef enum{
	EXTI_line_0,
	EXTI_line_1,
	EXTI_line_2,
	EXTI_line_3,
	EXTI_line_4,
	EXTI_line_5,
	EXTI_line_6,
	EXTI_line_7,
	EXTI_line_8,
	EXTI_line_9,
	EXTI_line_10,
	EXTI_line_11,
	EXTI_line_12,
	EXTI_line_13,
	EXTI_line_14,
	EXTI_line_15,
}Lines_t;

typedef enum{
	EXTI_PORTA,
	EXTI_PORTB,
	EXTI_PORTC,
}Ports_t;

typedef enum{
	RISING_TRIGGER,
	FALLING_TRIGGER,
	ON_CHANGE_TRIGGER,
}Trigger_t;

#define FOUR_BITS_HIGH	0b1111
#define NIBBLE_SIZE	4

#define FOUR	4
#define EAGHT	8
#define TWELVE	12
#define SIXTEEN 16

void MEXTI_vEnableExternalInterrupt(Lines_t line);
void MEXTI_vDisableExternalInterrupt(Lines_t line);
void MEXTI_vSetExternalInterruptConfig(Lines_t line,Ports_t port);
void MEXTI_vEnableSoftWareExternalInterrupt(Lines_t line);
void MEXTI_vEnableExternalEvent(Lines_t line);
void MEXTI_vDISableExternalEvent(Lines_t line);
void MEXTI_vSetExternalInterruptTriggerType(Lines_t line,Trigger_t TriggerType);
void MEXTI_SetCallBack(Lines_t line,void(*ptr)(void));

#endif /* MCAL_MEXTI_MEXTI_INTERFACE_H_ */
