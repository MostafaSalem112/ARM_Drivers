/*
 * MSYSTICK_interface.h
 *
 *  Created on: Aug 15, 2023
 *      Author: Mostafa_Salem
 */

#ifndef MCAL_MSYSTIKC_MSYSTICK_INTERFACE_H_
#define MCAL_MSYSTIKC_MSYSTICK_INTERFACE_H_

#define NULL	0

#define AHB_CLOCK			0
#define AHB_CLOCK_DIV_8		1

#define AHB_PRESCALER		8
#define ZERO				0
#define MILLIS_IN_SECOND	1000
#define MICROS_IN_SECOND	1000000

void MSYSTICK_vInit(void);
void MSYSTICK_vDelay_us(u32 A_u32Time_us);
void MSYSTICK_vDelay_ms(u32 A_u32Time_ms);
u32 MSYSTICK_u32GetElapsedTime(void);
u32 MSYSTICK_u32GetRemainingTime(void);
void MSYSTICK_SetInterval_Single(u32 A_u32Time_ms,void(*ptr)(void));
void MSYSTICK_SetInterval_Periodic(u32 A_u32Time_ms,void(*ptr)(void));
void MSYSTICK_vStopTimer(void);

#endif /* MCAL_MSYSTIKC_MSYSTICK_INTERFACE_H_ */
