/*
 * MUART_private.h
 *
 *  Created on: Aug 23, 2023
 *      Author: Mostafa_Salem
 */

#ifndef MCAL_MUART_MUART_PRIVATE_H_
#define MCAL_MUART_MUART_PRIVATE_H_


#define UART_BASE_ADDRESS	0x40011000

#define MANTISSA	4
#define TC			6
#define RXNE		5

typedef enum{
	SBK,
	RWU,
	RE,
	TE,
	IDLEIE,
	RXNEIE,
	TCIE,
	TXEIE,
	PEIE,
	PS,
	PCE,
	WAKE,
	M,
	UE,
	Reserved,
	OVER8,
}USART_CR1_t;

typedef struct{
	u32 SR;
	u32 DR;
	u32 BRR;
	u32 CR1;
	u32 CR2;
	u32 CR3;
	u32 GTPR;
}UART_t;

#define UART	((volatile UART_t*)(UART_BASE_ADDRESS))


#endif /* MCAL_MUART_MUART_PRIVATE_H_ */
