/*
 * MDMA_interface.h
 *
 *  Created on: Aug 28, 2023
 *      Author: Mostafa_Salem
 */

#ifndef MCAL_MDMA_MDMA_INTERFACE_H_
#define MCAL_MDMA_MDMA_INTERFACE_H_

#define NULL	0

typedef enum{
	DMA_STREAM0,
	DMA_STREAM1,
	DMA_STREAM2,
	DMA_STREAM3,
	DMA_STREAM4,
	DMA_STREAM5,
	DMA_STREAM6,
	DMA_STREAM7,
}STREAM_t;

void MDMA_vInit(STREAM_t A_u8StreamNo);
void MDMA_vClearInterruptFlags(void);
void MDMA_vEnableStream(STREAM_t A_u8StreamNo);
void MSMA_vSetAddresses(STREAM_t A_StreamNo,u32 SourceAddres,u32 DistinationAddress,u16 NumberOfDataItems);
void MDMA_vSetCallBack(void (*ptr)(void));

#endif /* MCAL_MDMA_MDMA_INTERFACE_H_ */
