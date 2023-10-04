/*
 * MSPI_interface.h
 *
 *  Created on: Aug 24, 2023
 *      Author: Mostafa_Salem
 */

#ifndef MCAL_MSPI_MSPI_INTERFACE_H_
#define MCAL_MSPI_MSPI_INTERFACE_H_


#define SPI_SLAVE 0
#define SPI_MASTER 1


void MSPI_VInit(u8 A_u8ModeSelect);
u8	 MSPI_u8TransCeiver(u8 A_u8SentDada);


#endif /* MCAL_MSPI_MSPI_INTERFACE_H_ */
