/*
 * MDMA_program.c
 *
 *  Created on: Aug 28, 2023
 *      Author: Mostafa_Salem
 */
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"
#include "MDMA_private.h"
#include "MDMA_config.h"
#include "MDMA_interface.h"

void (*DMA_GPfun)(void) = NULL;

void MDMA_vInit(STREAM_t A_StreamNo){
	CLR_BIT(DMA->StreemRegisters[A_StreamNo].SxCR,0);

	DMA->StreemRegisters[A_StreamNo].SxCR &= ~(0b11 << 16);
	DMA->StreemRegisters[A_StreamNo].SxCR |=  (0b11 << 16);

	DMA->StreemRegisters[A_StreamNo].SxCR &= ~(0b11 << 6);
	DMA->StreemRegisters[A_StreamNo].SxCR |=  (0b10 << 6);

	SET_BIT(DMA->StreemRegisters[A_StreamNo].SxCR,8);

	DMA->StreemRegisters[A_StreamNo].SxCR &= ~(0b11 << 13);
	DMA->StreemRegisters[A_StreamNo].SxCR |=  (0b10 << 13);

	DMA->StreemRegisters[A_StreamNo].SxCR &= ~(0b11 << 11);
	DMA->StreemRegisters[A_StreamNo].SxCR |=  (0b10 << 11);

	SET_BIT(DMA->StreemRegisters[A_StreamNo].SxFCR,2);

	DMA->StreemRegisters[A_StreamNo].SxFCR &= ~(0b11 << 0);
	DMA->StreemRegisters[A_StreamNo].SxFCR |=  (0b11 << 0);

	SET_BIT(DMA->StreemRegisters[A_StreamNo].SxCR,9);
	SET_BIT(DMA->StreemRegisters[A_StreamNo].SxCR,10);

	SET_BIT(DMA->StreemRegisters[A_StreamNo].SxCR,4);
}

void MDMA_vClearInterruptFlags(void){
	DMA->HIFCR |= (0b111111 << 0);
}

void MDMA_vEnableStream(STREAM_t A_StreamNo){
	MDMA_vClearInterruptFlags();
	SET_BIT(DMA->StreemRegisters[A_StreamNo].SxCR,0);
}

void MSMA_vSetAddresses(STREAM_t A_StreamNo,u32 SourceAddres,u32 DistinationAddress,u16 NumberOfDataItems){
	DMA->StreemRegisters[A_StreamNo].SxNDTR = NumberOfDataItems;
	DMA->StreemRegisters[A_StreamNo].SxPAR = SourceAddres;
	DMA->StreemRegisters[A_StreamNo].SxM0AR = DistinationAddress;
}

void MDMA_vSetCallBack(void (*ptr)(void)){
	DMA_GPfun = ptr;
}

void DMA1_stream0_IRQHandler(){
	if(DMA_GPfun != NULL){
		DMA_GPfun();
	}
}
