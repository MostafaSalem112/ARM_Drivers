/*
 * MUART_program.c
 *
 *  Created on: Aug 23, 2023
 *      Author: Mostafa_Salem
 */
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"
#include "MUART_private.h"
#include "MUART_config.h"
#include "MUART_interface.h"

void (*UART_GPFun)(void) = NULL;

void MUART_vInit(void){
	u32 Mantissa;
	u32 Fraction;

#if (OVER_SAMPLING == OVER_SAMPLING_16)
	CLR_BIT(UART->CR1,OVER8);
#elif (OVER_SAMPLING == OVER_SAMPLING_8)
	SET_BIT(UART->CR1,OVER8);
#endif

	Mantissa = (SYSTEM_CLOCK)/(OVER_SAMPLING*BAUD_RATE);
	Fraction = (f32)(((f32)SYSTEM_CLOCK)/(OVER_SAMPLING*BAUD_RATE)) - Mantissa;
	Fraction*= OVER_SAMPLING;
	UART->BRR = (Mantissa << MANTISSA) | Fraction;

	SET_BIT(UART->CR1,TE);
	SET_BIT(UART->CR1,RE);
}

void MUART_vSendData(u8 A_u8Data){
	UART->DR = A_u8Data;
	while(!(GET_BIT(UART->SR,TC)));
	CLR_BIT(UART->SR,TC);
}

void MUART_vSendString(u8* A_Pu8String){
	u8 i =0;
	while(A_Pu8String[i] != NULL){
		MUART_vSendData(A_Pu8String[i]);
		i++;
	}
}

u8 MUART_u8ReceiveData(void){
	u8 L_ReceivedData;
	while(!(GET_BIT(UART->SR,RXNE)));
	L_ReceivedData = UART->DR;
	return L_ReceivedData;
}

u8 MUART_u8ReceiveDataFromWIFI(u32 copy_u32MaxTimeToWait){
	u32 timeout=0;
	u8 data=0;
	
	while(GET_BIT(UART -> SR, 5) == 0)
	{
		timeout++;
		if(timeout == copy_u32MaxTimeToWait)
		{
			data = 128;
			break;
		}
	}
	if(data == 0)
	{
		data = UART -> DR;
	}
	CLR_BIT(UART -> SR, 5);
    return data;
}

void MUART_vEnable(void){
	SET_BIT(UART->CR1,UE);
}

void MUART_vDisable(void){
	CLR_BIT(UART->CR1,UE);
}

void MUART_vEnableReceptionInterrupt(void){
	SET_BIT(UART->CR1,RXNEIE);
}

void MUART_vCallBack(void(*ptr)(void)){
	UART_GPFun = ptr;
}

void USART1_IRQHandler(void){
	if(UART_GPFun != NULL){
		UART_GPFun();
	}
}