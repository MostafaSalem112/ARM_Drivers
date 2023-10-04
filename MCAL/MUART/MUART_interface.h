/*
 * MUART_interface.h
 *
 *  Created on: Aug 23, 2023
 *      Author: Mostafa_Salem
 */

#ifndef MCAL_MUART_MUART_INTERFACE_H_
#define MCAL_MUART_MUART_INTERFACE_H_

#define NULL 0

#define OVER_SAMPLING_16	0
#define OVER_SAMPLING_8		1

void MUART_vInit(void);
void MUART_vSendData(u8 A_u8Data);
void MUART_vSendString(u8* A_Pu8String);
u8	 MUART_u8ReceiveData(void);
u8   MUART_u8ReceiveDataFromWIFI(u32 copy_u32MaxTimeToWait);
void MUART_vEnable(void);
void MUART_vDisable(void);
void MUART_vEnableReceptionInterrupt(void);
void MUART_vCallBack(void(*ptr)(void));

#endif /* MCAL_MUART_MUART_INTERFACE_H_ */
