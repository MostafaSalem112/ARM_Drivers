/*
 * MSPI_program.c
 *
 *  Created on: Aug 24, 2023
 *      Author: Mostafa_Salem
 */
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"
#include "MSPI_private.h"
#include "MSPI_config.h"
#include "MSPI_interface.h"

void MSPI_VInit(u8 A_u8ModeSelect){
	CLR_BIT(SPI->CR1,BIDIMODE);
	CLR_BIT(SPI->CR1,DFF);
	CLR_BIT(SPI->CR1,RXONLY);
	CLR_BIT(SPI->CR1,LSBFIRST);
	CLR_BIT(SPI->CR1,BR3);
	CLR_BIT(SPI->CR1,BR4);
	CLR_BIT(SPI->CR1,BR5);
	CLR_BIT(SPI->CR1,CPOL);
	CLR_BIT(SPI->CR1,CPHA);

	switch(A_u8ModeSelect){
	case SPI_SLAVE:CLR_BIT(SPI->CR1,MSTR);break;
	case SPI_MASTER:SET_BIT(SPI->CR1,MSTR);break;
	}

	SET_BIT(SPI->CR1,SPE);
}
u8	 MSPI_u8TransCeiver(u8 A_u8SentDada){
	SPI->DR = (u32)A_u8SentDada;
	while(!GET_BIT(SPI->SR,TXE));
	return (u8)SPI->DR;
}

