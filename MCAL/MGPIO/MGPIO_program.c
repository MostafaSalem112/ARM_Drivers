/*
 * MGPIO_program.c
 *
 *  Created on: Aug 10, 2023
 *      Author: Mostafa_Salem
 */
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"
#include "MGPIO_private.h"
#include "MGPIO_config.h"
#include "MGPIO_interface.h"


void MGPIO_vSetPinMode(u8 A_u8PortID,u8 A_u8PinNo,u8 A_u8Mode){

	switch(A_u8PortID){
	case GPIO_PORTA:
		GPIOA->MODER &= ~(TWO_BITS_HIGH << (A_u8PinNo*CRUMB_SIZE));
		GPIOA->MODER |= (A_u8Mode << (A_u8PinNo*CRUMB_SIZE));
		break;
	case GPIO_PORTB:
		GPIOB->MODER &= ~(TWO_BITS_HIGH << (A_u8PinNo*CRUMB_SIZE));
		GPIOB->MODER |= (A_u8Mode << (A_u8PinNo*CRUMB_SIZE));
		break;
	case GPIO_PORTC:
		GPIOC->MODER &= ~(TWO_BITS_HIGH << (A_u8PinNo*CRUMB_SIZE));
		GPIOC->MODER |= (A_u8Mode << (A_u8PinNo*CRUMB_SIZE));
		break;
	}
}

void MGPIO_vSetPinOutPutType(u8 A_u8PortID,u8 A_u8PinNo,u8 A_u8OutPutType){

	if(A_u8OutPutType == GPIO_PUSHPULL){
		switch(A_u8PortID){
		case GPIO_PORTA:
			CLR_BIT(GPIOA->OTYPER,A_u8PinNo);
			break;
		case GPIO_PORTB:
			CLR_BIT(GPIOB->OTYPER,A_u8PinNo);
			break;
		case GPIO_PORTC:
			CLR_BIT(GPIOC->OTYPER,A_u8PinNo);
			break;
		}
	}
	else if(A_u8OutPutType == GPIO_OPENDRAIN){
		switch(A_u8PortID){
		case GPIO_PORTA:
			SET_BIT(GPIOA->OTYPER,A_u8PinNo);
			break;
		case GPIO_PORTB:
			SET_BIT(GPIOB->OTYPER,A_u8PinNo);
			break;
		case GPIO_PORTC:
			SET_BIT(GPIOC->OTYPER,A_u8PinNo);
			break;
		}
	}
}

void MGPIO_vSetPinOutPutSpeed(u8 A_u8PortID,u8 A_u8PinNo,u8 A_u8OutPutSpeed){

	switch(A_u8PortID){
	case GPIO_PORTA:
		GPIOA->OSPEEDR &= ~(TWO_BITS_HIGH << (A_u8PinNo*CRUMB_SIZE));
		GPIOA->OSPEEDR |= (A_u8OutPutSpeed << (A_u8PinNo*CRUMB_SIZE));
		break;
	case GPIO_PORTB:
		GPIOB->OSPEEDR &= ~(TWO_BITS_HIGH << (A_u8PinNo*CRUMB_SIZE));
		GPIOB->OSPEEDR |= (A_u8OutPutSpeed << (A_u8PinNo*CRUMB_SIZE));
		break;
	case GPIO_PORTC:
		GPIOC->OSPEEDR &= ~(TWO_BITS_HIGH << (A_u8PinNo*CRUMB_SIZE));
		GPIOC->OSPEEDR |= (A_u8OutPutSpeed << (A_u8PinNo*CRUMB_SIZE));
		break;
	}
}

void MGPIO_vSetPinInPutPull(u8 A_u8PortID,u8 A_u8PinNo,u8 A_u8PullType){

	switch(A_u8PortID){
	case GPIO_PORTA:
		GPIOA->PUPDR &= ~(TWO_BITS_HIGH << (A_u8PinNo*CRUMB_SIZE));
		GPIOA->PUPDR |= (A_u8PullType << (A_u8PinNo*CRUMB_SIZE));
		break;
	case GPIO_PORTB:
		GPIOB->PUPDR &= ~(TWO_BITS_HIGH << (A_u8PinNo*CRUMB_SIZE));
		GPIOB->PUPDR |= (A_u8PullType << (A_u8PinNo*CRUMB_SIZE));
		break;
	case GPIO_PORTC:
		GPIOC->PUPDR &= ~(TWO_BITS_HIGH << (A_u8PinNo*CRUMB_SIZE));
		GPIOC->PUPDR |= (A_u8PullType << (A_u8PinNo*CRUMB_SIZE));
		break;
	}
}

u8 MGPIO_u8GetPinValue(u8 A_u8PortID,u8 A_u8PinNo){
	u8 L_u8PinValue = GPIO_LOW;
	switch(A_u8PortID){
	case GPIO_PORTA:
		L_u8PinValue = GET_BIT(GPIOA->IDR,A_u8PinNo);
		break;
	case GPIO_PORTB:
		L_u8PinValue = GET_BIT(GPIOB->IDR,A_u8PinNo);
		break;
	case GPIO_PORTC:
		L_u8PinValue = GET_BIT(GPIOC->IDR,A_u8PinNo);
		break;
	}
	return L_u8PinValue;
}

void MGPIO_vSetPinValue(u8 A_u8PortID,u8 A_u8PinNo,u8 A_u8PinValue){

	if(A_u8PinValue == GPIO_LOW){
		switch(A_u8PortID){
		case GPIO_PORTA:
			CLR_BIT(GPIOA->ODR,A_u8PinNo);
			break;
		case GPIO_PORTB:
			CLR_BIT(GPIOB->ODR,A_u8PinNo);
			break;
		case GPIO_PORTC:
			CLR_BIT(GPIOC->ODR,A_u8PinNo);
			break;
		}
	}
	else if(A_u8PinValue == GPIO_HIGH){
		switch(A_u8PortID){
		case GPIO_PORTA:
			SET_BIT(GPIOA->ODR,A_u8PinNo);
			break;
		case GPIO_PORTB:
			SET_BIT(GPIOB->ODR,A_u8PinNo);
			break;
		case GPIO_PORTC:
			SET_BIT(GPIOC->ODR,A_u8PinNo);
			break;
		}
	}
}

void MGPIO_vSetPinValue_Fast(u8 A_u8PortID,u8 A_u8PinNo,u8 A_u8PinValue){

	if(A_u8PinValue == GPIO_LOW){
		switch(A_u8PortID){
		case GPIO_PORTA:
			SET_BIT(GPIOA->BSRR,A_u8PinNo+WORD_SIZE);
			break;
		case GPIO_PORTB:
			SET_BIT(GPIOB->BSRR,A_u8PinNo+WORD_SIZE);
			break;
		case GPIO_PORTC:
			SET_BIT(GPIOC->BSRR,A_u8PinNo+WORD_SIZE);
			break;
		}
	}
	else if(A_u8PinValue == GPIO_HIGH){
		switch(A_u8PortID){
		case GPIO_PORTA:
			SET_BIT(GPIOA->BSRR,A_u8PinNo);
			break;
		case GPIO_PORTB:
			SET_BIT(GPIOB->BSRR,A_u8PinNo);
			break;
		case GPIO_PORTC:
			SET_BIT(GPIOC->BSRR,A_u8PinNo);
			break;
		}
	}
}

void MGPIO_vSetAlternativeFunction(u8 A_u8PortID,u8 A_u8PinNo,u8 A_u8AltFun){

	if(A_u8PinNo < BYTE_SIZE){
		switch(A_u8PortID){
		case GPIO_PORTA:
			GPIOA->AFRL &= ~(FOUR_BITS_HIGH << (A_u8PinNo*NIBBLE_SIZE));
			GPIOA->AFRL |= (A_u8AltFun << (A_u8PinNo*NIBBLE_SIZE));
			break;
		case GPIO_PORTB:
			GPIOB->AFRL &= ~(FOUR_BITS_HIGH << (A_u8PinNo*NIBBLE_SIZE));
			GPIOB->AFRL |= (A_u8AltFun << (A_u8PinNo*NIBBLE_SIZE));
			break;
		case GPIO_PORTC:
			GPIOC->AFRL &= ~(FOUR_BITS_HIGH << (A_u8PinNo*NIBBLE_SIZE));
			GPIOC->AFRL |= (A_u8AltFun << (A_u8PinNo*NIBBLE_SIZE));
			break;
		}
	}
	else if(A_u8PinNo >= BYTE_SIZE){
		switch(A_u8PortID){
		case GPIO_PORTA:
			GPIOA->AFRH &= ~(FOUR_BITS_HIGH << ((A_u8PinNo-BYTE_SIZE)*NIBBLE_SIZE));
			GPIOA->AFRH |= (A_u8AltFun << ((A_u8PinNo-BYTE_SIZE)*NIBBLE_SIZE));
			break;
		case GPIO_PORTB:
			GPIOB->AFRH &= ~(FOUR_BITS_HIGH << ((A_u8PinNo-BYTE_SIZE)*NIBBLE_SIZE));
			GPIOB->AFRH |= (A_u8AltFun << ((A_u8PinNo-BYTE_SIZE)*NIBBLE_SIZE));
			break;
		case GPIO_PORTC:
			GPIOC->AFRH &= ~(FOUR_BITS_HIGH << ((A_u8PinNo-BYTE_SIZE)*NIBBLE_SIZE));
			GPIOC->AFRH |= (A_u8AltFun << ((A_u8PinNo-BYTE_SIZE)*NIBBLE_SIZE));
			break;
		}
	}
}
