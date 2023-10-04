/*
 * MDMA_private.h
 *
 *  Created on: Aug 28, 2023
 *      Author: Mostafa_Salem
 */

#ifndef MCAL_MDMA_MDMA_PRIVATE_H_
#define MCAL_MDMA_MDMA_PRIVATE_H_

#define DMA_BASE_ADDRESS		0x40026000

typedef struct{
	u32 SxCR;
	u32 SxNDTR;
	u32 SxPAR;
	u32 SxM0AR;
	u32 SxM1AR;
	u32 SxFCR;
}STREEMS_t;

typedef struct{
	u32 LISR;
	u32 HISR;
	u32 LIFCR;
	u32 HIFCR;
	STREEMS_t StreemRegisters[8];
}DMA_t;

#define DMA		((volatile DMA_t*)(DMA_BASE_ADDRESS))


#endif /* MCAL_MDMA_MDMA_PRIVATE_H_ */
