/*
 * MEXI_program.c
 *
 *  Created on: Aug 14, 2023
 *      Author: Mostafa_Salem
 */
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"
#include "MEXTI_private.h"
#include "MEXTI_config.h"
#include "MEXTI_interface.h"

void (*EXTI_GPfun[16])(void) = {NULL};

void MEXTI_vEnableExternalInterrupt(Lines_t line){

	SET_BIT(EXTI->IMR,line);
}

void MEXTI_vDisableExternalInterrupt(Lines_t line){

	CLR_BIT(EXTI->IMR,line);
}

void MEXTI_vSetExternalInterruptConfig(Lines_t line,Ports_t port){
	if(line < FOUR){
		SYSCFG->EXTICR1 &= ~(FOUR_BITS_HIGH << (line*NIBBLE_SIZE));
		SYSCFG->EXTICR1 |= (port << (line*NIBBLE_SIZE));
	}
	else if(line >= FOUR  && line < EAGHT){
		SYSCFG->EXTICR2 &= ~(FOUR_BITS_HIGH << ((line-FOUR)*NIBBLE_SIZE));
		SYSCFG->EXTICR2 |= (port << ((line-FOUR)*NIBBLE_SIZE));
	}
	else if(line >= EAGHT  && line < TWELVE){
		SYSCFG->EXTICR3 &= ~(FOUR_BITS_HIGH << ((line-EAGHT)*NIBBLE_SIZE));
		SYSCFG->EXTICR3 |= (port << ((line-EAGHT)*NIBBLE_SIZE));
	}
	else if(line >= TWELVE  && line < SIXTEEN){
		SYSCFG->EXTICR4 &= ~(FOUR_BITS_HIGH << ((line-TWELVE)*NIBBLE_SIZE));
		SYSCFG->EXTICR4 |= (port << ((line-TWELVE)*NIBBLE_SIZE));
	}
}

void MEXTI_vEnableSoftWareExternalInterrupt(Lines_t line){

	SET_BIT(EXTI->SWIER,line);
}

void MEXTI_vEnableExternalEvent(Lines_t line){

	SET_BIT(EXTI->EMR,line);
}

void MEXTI_vDISableExternalEvent(Lines_t line){

	SET_BIT(EXTI->EMR,line);
}

void MEXTI_vSetExternalInterruptTriggerType(Lines_t line,Trigger_t TriggerType){

	switch(TriggerType){
	case RISING_TRIGGER:
		CLR_BIT(EXTI->FTSR,line);
		SET_BIT(EXTI->RTSR,line);
		break;
	case FALLING_TRIGGER:
		CLR_BIT(EXTI->RTSR,line);
		SET_BIT(EXTI->FTSR,line);
		break;
	case ON_CHANGE_TRIGGER:
		SET_BIT(EXTI->RTSR,line);
		SET_BIT(EXTI->FTSR,line);
		break;
	}
}

void MEXTI_SetCallBack(Lines_t line,void(*ptr)(void)){

	EXTI_GPfun[line]=ptr;
}

void EXTI0_IRQHandler(void){
	if(EXTI_GPfun[0] != NULL){
		EXTI_GPfun[0]();
		SET_BIT(EXTI->PR,EXTI_line_0);
	}
}

void EXTI1_IRQHandler(void){
	if(EXTI_GPfun[1] != NULL){
		EXTI_GPfun[1]();
		SET_BIT(EXTI->PR,EXTI_line_1);
	}
}

void EXTI2_IRQHandler(void){
	if(EXTI_GPfun[2] != NULL){
		EXTI_GPfun[2]();
		SET_BIT(EXTI->PR,EXTI_line_2);
	}
}

void EXTI3_IRQHandler(void){
	if(EXTI_GPfun[3] != NULL){
		EXTI_GPfun[3]();
		SET_BIT(EXTI->PR,EXTI_line_3);
	}
}

void EXTI4_IRQHandler(void){
	if(EXTI_GPfun[4] != NULL){
		EXTI_GPfun[4]();
		SET_BIT(EXTI->PR,EXTI_line_4);
	}
}

void EXTI5_IRQHandler(void){
	if(EXTI_GPfun[5] != NULL){
		EXTI_GPfun[5]();
		SET_BIT(EXTI->PR,EXTI_line_5);
	}
}

void EXTI6_IRQHandler(void){
	if(EXTI_GPfun[6] != NULL){
		EXTI_GPfun[6]();
		SET_BIT(EXTI->PR,EXTI_line_6);
	}
}

void EXTI7_IRQHandler(void){
	if(EXTI_GPfun[7] != NULL){
		EXTI_GPfun[7]();
		SET_BIT(EXTI->PR,EXTI_line_7);
	}
}

void EXTI8_IRQHandler(void){
	if(EXTI_GPfun[8] != NULL){
		EXTI_GPfun[8]();
		SET_BIT(EXTI->PR,EXTI_line_8);
	}
}

void EXTI9_IRQHandler(void){
	if(EXTI_GPfun[9] != NULL){
		EXTI_GPfun[9]();
		SET_BIT(EXTI->PR,EXTI_line_9);
	}
}

void EXTI10_IRQHandler(void){
	if(EXTI_GPfun[10] != NULL){
		EXTI_GPfun[10]();
		SET_BIT(EXTI->PR,EXTI_line_10);
	}
}

void EXTI11_IRQHandler(void){
	if(EXTI_GPfun[11] != NULL){
		EXTI_GPfun[11]();
		SET_BIT(EXTI->PR,EXTI_line_11);
	}
}

void EXTI12_IRQHandler(void){
	if(EXTI_GPfun[12] != NULL){
		EXTI_GPfun[12]();
		SET_BIT(EXTI->PR,EXTI_line_12);
	}
}

void EXTI13_IRQHandler(void){
	if(EXTI_GPfun[13] != NULL){
		EXTI_GPfun[13]();
		SET_BIT(EXTI->PR,EXTI_line_13);
	}
}

void EXTI14_IRQHandler(void){
	if(EXTI_GPfun[14] != NULL){
		EXTI_GPfun[14]();
		SET_BIT(EXTI->PR,EXTI_line_14);
	}
}

void EXTI15_IRQHandler(void){
	if(EXTI_GPfun[15] != NULL){
		EXTI_GPfun[15]();
		SET_BIT(EXTI->PR,EXTI_line_15);
	}
}
