/*
 * MSYSTICK_program.c
 *
 *  Created on: Aug 15, 2023
 *      Author: Mostafa_Salem
 */
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"
#include "MSYSTICK_private.h"
#include "MSYSTICK_config.h"
#include "MSYSTICK_interface.h"

void (*SYSTICK_GPFun)(void);
u8 L_u8PeriodicFlag;

void MSYSTICK_vInit(void){
	switch(SYSTICK_CLOCK_SOURCE){
	case AHB_CLOCK:
		SET_BIT(SYSTICK->CTRL,CLKSOURCE);
		break;
	case AHB_CLOCK_DIV_8:
		CLR_BIT(SYSTICK->CTRL,CLKSOURCE);
		break;
	}
}

void MSYSTICK_vDelay_us(u32 A_u32Time_us){
	u32 L_TimerFrequency;
	f32 L_TickTime;
	u32 L_Tick_No;

	switch(SYSTICK_CLOCK_SOURCE){
	case AHB_CLOCK:
		L_TimerFrequency = SYSTICK_AHB_CLOCK;
		break;
	case AHB_CLOCK_DIV_8:
		L_TimerFrequency = SYSTICK_AHB_CLOCK/AHB_PRESCALER;
		break;
	}

	L_TickTime = MICROS_IN_SECOND/(f32)L_TimerFrequency;
	L_Tick_No = A_u32Time_us/L_TickTime;

	SYSTICK->VAL = ZERO;
	SYSTICK->LOAD = L_Tick_No;

	SET_BIT(SYSTICK->CTRL,ENABLE);

	while(!(GET_BIT(SYSTICK->CTRL,COUNTFLAG)));

	CLR_BIT(SYSTICK->CTRL,ENABLE);
}

void MSYSTICK_vDelay_ms(u32 A_u32Time_ms){
	u32 L_TimerFrequency;
	f32 L_TickTime;
	u32 L_Tick_No;

	switch(SYSTICK_CLOCK_SOURCE){
	case AHB_CLOCK:
		L_TimerFrequency = SYSTICK_AHB_CLOCK;
		break;
	case AHB_CLOCK_DIV_8:
		L_TimerFrequency = SYSTICK_AHB_CLOCK/AHB_PRESCALER;
		break;
	}

	L_TickTime = MILLIS_IN_SECOND/(f32)L_TimerFrequency;
	L_Tick_No = A_u32Time_ms/L_TickTime;

	SYSTICK->VAL = ZERO;
	SYSTICK->LOAD = L_Tick_No;

	SET_BIT(SYSTICK->CTRL,ENABLE);

	while(!(GET_BIT(SYSTICK->CTRL,COUNTFLAG)));

	CLR_BIT(SYSTICK->CTRL,ENABLE);
}

u32 MSYSTICK_u32GetElapsedTime_ms(void){
	u32 L_TimerFrequency;
	f32 L_TickTime;
	u32 L_ElapsedTick_No;
	u32 L_ElapsedTime;
	u32 L_Load;
	u32 L_Value;

	switch(SYSTICK_CLOCK_SOURCE){
	case AHB_CLOCK:
		L_TimerFrequency = SYSTICK_AHB_CLOCK;
		break;
	case AHB_CLOCK_DIV_8:
		L_TimerFrequency = SYSTICK_AHB_CLOCK/AHB_PRESCALER;
		break;
	}
	L_TickTime = MILLIS_IN_SECOND/(f32)L_TimerFrequency;

	L_Load = SYSTICK->LOAD;
	L_Value = SYSTICK->VAL;
	L_ElapsedTick_No = L_Load - L_Value;
	L_ElapsedTime = L_ElapsedTick_No*L_TickTime;

	return	L_ElapsedTime;
}

u32 MSYSTICK_u32GetRemainingTime_ms(void){
	u32 L_TimerFrequency;
	f32 L_TickTime;
	u32 L_RemainingTick_No;
	u32 L_RemainingTime;

	switch(SYSTICK_CLOCK_SOURCE){
	case AHB_CLOCK:
		L_TimerFrequency = SYSTICK_AHB_CLOCK;
		break;
	case AHB_CLOCK_DIV_8:
		L_TimerFrequency = SYSTICK_AHB_CLOCK/AHB_PRESCALER;
		break;
	}
	L_TickTime = MILLIS_IN_SECOND/(f32)L_TimerFrequency;

	L_RemainingTick_No = SYSTICK->VAL;
	L_RemainingTime = L_RemainingTick_No*L_TickTime;

	return	L_RemainingTime;
}

void MSYSTICK_SetInterval_Single(u32 A_u32Time_ms,void(*ptr)(void)){
	u32 L_TimerFrequency;
	f32 L_TickTime;
	u32 L_Tick_No;

	SYSTICK_GPFun = ptr;
	L_u8PeriodicFlag = 0;

	switch(SYSTICK_CLOCK_SOURCE){
	case AHB_CLOCK:
		L_TimerFrequency = SYSTICK_AHB_CLOCK;
		break;
	case AHB_CLOCK_DIV_8:
		L_TimerFrequency = SYSTICK_AHB_CLOCK/AHB_PRESCALER;
		break;
	}
	L_TickTime = MILLIS_IN_SECOND/(f32)L_TimerFrequency;
	L_Tick_No = A_u32Time_ms/L_TickTime;

	SYSTICK->VAL = ZERO;
	SYSTICK->LOAD = L_Tick_No;

	SET_BIT(SYSTICK->CALIB,TICKINT);
	SET_BIT(SYSTICK->CTRL,ENABLE);
}

void MSYSTICK_SetInterval_Periodic(u32 A_u32Time_ms,void(*ptr)(void)){
	u32 L_TimerFrequency;
	f32 L_TickTime;
	u32 L_Tick_No;

	SYSTICK_GPFun = ptr;
	L_u8PeriodicFlag = 1;

	switch(SYSTICK_CLOCK_SOURCE){
	case AHB_CLOCK:
		L_TimerFrequency = SYSTICK_AHB_CLOCK;
		break;
	case AHB_CLOCK_DIV_8:
		L_TimerFrequency = SYSTICK_AHB_CLOCK/AHB_PRESCALER;
		break;
	}
	L_TickTime = MILLIS_IN_SECOND/(f32)L_TimerFrequency;
	L_Tick_No = A_u32Time_ms/L_TickTime;

	SYSTICK->VAL = ZERO;
	SYSTICK->LOAD = L_Tick_No;

	SET_BIT(SYSTICK->CALIB,TICKINT);
	SET_BIT(SYSTICK->CTRL,ENABLE);
}

void MSYSTICK_vStopTimer(void){
	CLR_BIT(SYSTICK->CTRL,ENABLE);
}

void SysTick_Handler(void){
	if(SYSTICK_GPFun != NULL){
		SYSTICK_GPFun();
		if(L_u8PeriodicFlag == 0){
			CLR_BIT(SYSTICK->CTRL,ENABLE);
		}
	}
}
