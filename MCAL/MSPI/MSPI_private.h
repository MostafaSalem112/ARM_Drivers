/*
 * MSPI_private.h
 *
 *  Created on: Aug 24, 2023
 *      Author: Mostafa_Salem
 */

#ifndef MCAL_MSPI_MSPI_PRIVATE_H_
#define MCAL_MSPI_MSPI_PRIVATE_H_

#define SPI_BASE_ADDRESS	0x40013000

#define BIDIMODE	15
#define DFF			11
#define RXONLY		10
#define LSBFIRST	7
#define SPE			6
#define BR5			5
#define BR4			4
#define BR3			3
#define MSTR		2
#define CPOL		1
#define CPHA		0

#define TXE			1

typedef struct{
	u32 CR1;
	u32 SR;
	u32 DR;
	u32 CRCPR;
	u32 RXCRCR;
	u32 TXCRCR;
	u32 I2SCFGR;
	u32 I2SPR;
}SPI_t;

#define SPI		((volatile SPI_t*)(SPI_BASE_ADDRESS))

#endif /* MCAL_MSPI_MSPI_PRIVATE_H_ */
