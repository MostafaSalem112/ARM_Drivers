/*
 * MRCC_program.c
 *
 *  Created on: Aug 10, 2023
 *      Author: Mostafa_Salem
 */
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"
#include "MRCC_private.h"
#include "MRCC_config.h"
#include "MRCC_interface.h"



void MRCC_vInit(void){
	/*CSS(ON,OFF)*/
#if RCC_CSS_ENABLE == ENABLE
	SET_BIT(RCC->CR,CSSON);
#endif

	/**************************************************************************************************/
	/************************************ Clock Configuration *****************************************/
	/**************************************************************************************************/

#if RCC_SYS_CLK == RCC_HSI

	/*Select the Frequency of internal clock*/
	RCC->CR |= (RCC_HSI_FREQ << HSITRIM);

	/*Select the Clock Source as HSI*/
	CLR_BIT(RCC->CFGR,SW0);
	CLR_BIT(RCC->CFGR,SW1);

	/*Wait till the Clock Source is Selected*/
	while(!((GET_BIT(RCC->CFGR,SWS0) == BIT_RESET) && (GET_BIT(RCC->CFGR,SWS1) == BIT_RESET)));

#elif RCC_SYS_CLK == RCC_HSE

	/*HSEBYP CLR ==> Oscillator is Enabled NOT Bypassed    SET ==> Oscillator is Disabled and Bypassed*/
	CLR_BIT(RCC->CR,HSEBYP);

	/*Select the Clock Source as HSE*/
	SET_BIT(RCC->CFGR,SW0);
	CLR_BIT(RCC->CFGR,SW1);

	/*Wait till the Clock Source is Selected*/
	while(!((GET_BIT(RCC->CFGR,SWS0) == BIT_SET) && (GET_BIT(RCC->CFGR,SWS1) == BIT_RESET)));

#elif RCC_SYS_CLK == RCC_PLL

	/*Select PLL Main Source*/
#if RCC_PLL_SOURCE == RCC_HSI
	CLR_BIT(RCC->PLLCFGR,PLLSRC);
#elif RCC_PLL_SOURCE == RCC_HSE
	SET_BIT(RCC->PLLCFGR,PLLSRC);
#endif

	/*Select Prescalers for PLL clock*/
	RCC->PLLCFGR &= REGISTER_CLEAR;		// Clear PLLCFGR Register

	RCC->PLLCFGR |= (RCC_PLL_M_PRESCALER << PLLM);
	RCC->PLLCFGR |= (RCC_PLL_N_PRESCALER << PLLN);
	switch(RCC_PLL_P_PRESCALER){
	case PLLP_2:
		RCC->PLLCFGR |= (PLLP_2 << PLLP);break;
	case PLLP_4:
		RCC->PLLCFGR |= (PLLP_4 << PLLP);break;
	case PLLP_6:
		RCC->PLLCFGR |= (PLLP_6 << PLLP);break;
	case PLLP_8:
		RCC->PLLCFGR |= (PLLP_8 << PLLP);break;
	}

	/*Select the Clock Source as PLL*/
	CLR_BIT(RCC->CFGR,SW0);
	SET_BIT(RCC->CFGR,SW1);

	/*Wait till the Clock Source is Selected*/
	while(!((GET_BIT(RCC->CFGR,SWS0) == BIT_RESET) && (GET_BIT(RCC->CFGR,SWS1) == BIT_SET)));

#endif
	/********************************************************************************************************************/

	/******************** BUS Clock Prescalers **************************************/
	switch(RCC_AHB_PRESCALER){		// AHB clock division factor
	case PRESCR_1: 		RCC->CFGR |= (AHB_1   <<  HPRE);	break;
	case PRESCR_2: 		RCC->CFGR |= (AHB_2   <<  HPRE);	break;
	case PRESCR_4: 		RCC->CFGR |= (AHB_4   <<  HPRE);	break;
	case PRESCR_8: 		RCC->CFGR |= (AHB_8   <<  HPRE);	break;
	case PRESCR_16: 	RCC->CFGR |= (AHB_16  <<  HPRE);	break;
	case PRESCR_64: 	RCC->CFGR |= (AHB_64  <<  HPRE);	break;
	case PRESCR_128: 	RCC->CFGR |= (AHB_128 <<  HPRE);	break;
	case PRESCR_256: 	RCC->CFGR |= (AHB_256 <<  HPRE);	break;
	case PRESCR_512: 	RCC->CFGR |= (AHB_512 <<  HPRE);	break;
	}

	switch(RCC_APB1_PRESCALER){	// APB1 low-speed clock division factor
	case PRESCR_1: 		RCC->CFGR |= (APB_1   <<  PPRE1);	break;
	case PRESCR_2: 		RCC->CFGR |= (APB_2   <<  PPRE1);	break;
	case PRESCR_4: 		RCC->CFGR |= (APB_4   <<  PPRE1);	break;
	case PRESCR_8: 		RCC->CFGR |= (APB_8   <<  PPRE1);	break;
	case PRESCR_16: 	RCC->CFGR |= (APB_16  <<  PPRE1);	break;
	}

	switch(RCC_APB2_PRESCALER){	// APB2 high-speed clock division factor
	case PRESCR_1: 		RCC->CFGR |= (APB_1   <<  PPRE2);	break;
	case PRESCR_2: 		RCC->CFGR |= (APB_2   <<  PPRE2);	break;
	case PRESCR_4: 		RCC->CFGR |= (APB_4   <<  PPRE2);	break;
	case PRESCR_8: 		RCC->CFGR |= (APB_8   <<  PPRE2);	break;
	case PRESCR_16: 	RCC->CFGR |= (APB_16  <<  PPRE2);	break;
	}
	/*********************************************************************************************/

	/************************* Enable the Selected Clock Source **********************************/
#if RCC_HSI_ENABLE == ENABLE

	SET_BIT(RCC->CR,HSION);							//	ENABLE HSI Clock Source
	while(!(GET_BIT(RCC->CR,HSIRDY) == BIT_SET));	//	wait till the clock is Enabled

#elif RCC_HSE_ENABLE == ENABLE

	CLR_BIT(RCC->CR,HSION);
	SET_BIT(RCC->CR,HSEON);							//	ENABLE HSE Clock Source
	while(!(GET_BIT(RCC->CR,HSERDY) == BIT_SET));	//	wait till the clock is Enabled

#elif RCC_PLL_ENABLE == ENABLE

	CLR_BIT(RCC->CR,HSION);
	SET_BIT(RCC->CR,PLLON);							//	ENABLE PLL Clock Source
	while(!(GET_BIT(RCC->CR,PLLRDY) == BIT_SET));	//	wait till the clock is Enabled
#endif
	/*********************************************************************************************/
}

void MRCC_vEnablePeripheralClock(Peripherals_t preipheral){

	if(preipheral < ONE_REGISTER_SIZE){
		SET_BIT(RCC->AHB1ENR,preipheral);
	}
	else if((preipheral >= ONE_REGISTER_SIZE) && (preipheral < TWO_REGISTERS_SIZE)){
		SET_BIT(RCC->AHB2ENR,(preipheral-ONE_REGISTER_SIZE));
	}
	else if((preipheral >= TWO_REGISTERS_SIZE) && (preipheral < THREE_REGISTERS_SIZE)){
		SET_BIT(RCC->APB1ENR,(preipheral-TWO_REGISTERS_SIZE));
	}
	else if((preipheral >= THREE_REGISTERS_SIZE) && (preipheral < FOUR_REGISTERS_SIZE)){
		SET_BIT(RCC->APB2ENR,(preipheral-THREE_REGISTERS_SIZE));
	}
}

void MRCC_vDisablePeripheralClock(Peripherals_t preipheral){

	if(preipheral < ONE_REGISTER_SIZE){
		CLR_BIT(RCC->AHB1ENR,preipheral);
	}
	else if((preipheral >= ONE_REGISTER_SIZE) && (preipheral < TWO_REGISTERS_SIZE)){
		CLR_BIT(RCC->AHB2ENR,(preipheral-ONE_REGISTER_SIZE));
	}
	else if((preipheral >= TWO_REGISTERS_SIZE) && (preipheral < THREE_REGISTERS_SIZE)){
		CLR_BIT(RCC->APB1ENR,(preipheral-TWO_REGISTERS_SIZE));
	}
	else if((preipheral >= THREE_REGISTERS_SIZE) && (preipheral < FOUR_REGISTERS_SIZE)){
		CLR_BIT(RCC->APB2ENR,(preipheral-THREE_REGISTERS_SIZE));
	}

}
