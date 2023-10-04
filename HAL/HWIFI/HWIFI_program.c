#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"
#include "../../MCAL/MUART/MUART_interface.h"
#include "HWIFI_private.h"
#include "HWIFI_config.h"
#include "HWIFI_interface.h"


void HWIFI_voidInit(void)
{
	u8 Local_u8Output=0;
	
	while(Local_u8Output == 0)
	{
		MUART_vSendString("AT\r\n");
		Local_u8Output = HWIFI_u8CommandValidate(100000,0);
	}
	
	Local_u8Output=0;
	while(Local_u8Output == 0)
	{
		MUART_vSendString("AT+CWMODE=1\r\n");
		Local_u8Output = HWIFI_u8CommandValidate(100000,0);
	}
}

void HWIFI_voidConnectToNetwork (void)
{
	u8 Local_u8Output=0;
	
	while(Local_u8Output == 0)
	{
		MUART_vSendString("AT+CWJAP_CUR=\"HUAWEI Y9 2019\",\"12312345\"\r\n");
		Local_u8Output = HWIFI_u8CommandValidate(100000,0);
	}
	
}

void HWIFI_voidConnectToServer (void)
{
	u8 Local_u8Output=0;
	
	while(Local_u8Output == 0)
	{
		MUART_vSendString("AT+CIPSTART=\"TCP\",\"http://mostafasalem.freevar.com/\",80\r\n");
		Local_u8Output = HWIFI_u8CommandValidate(100000,0);
	}
	
	
}

u8 HWIFI_u8GetData (u8 *data_array)
{
	u8 status;
	
	HWIFI_voidConnectToServer();
	
	MUART_vSendString("AT+CIPSEND=46\r\n");
	status = HWIFI_u8CommandValidate(50000,0);
	
	MUART_vSendString("GET http://mostafasalem.freevar.com/status.txt");
	status = HWIFI_u8CommandValidate(100000,data_array);
	return status;
}


static u8 HWIFI_u8CommandValidate (u32 Copy_u32TimeOutm,u8 *data_array)
{
	u8 Local_u8Counter=0;
	u8 Local_u8ReceivedChar=0;
	
	u8 Local_u8Response[100]={0};
	u32 Local_u32DataIndex=0;
	
	while(Local_u8ReceivedChar < 128)
	{
		Local_u8ReceivedChar = MUART_u8ReceiveDataFromWIFI(Copy_u32TimeOutm);
		Local_u8Response[Local_u8Counter++] = Local_u8ReceivedChar;
	}
	
	for(Local_u8Counter=0; Local_u8Counter<100; Local_u8Counter++)
	{
		if(Local_u8Response[Local_u8Counter] == 'O' && Local_u8Response[Local_u8Counter+1] == 'K')
		{
			return 1;
		}
		else if(Local_u8Response[Local_u8Counter] == 'N' && Local_u8Response[Local_u8Counter+1] == 'D' && Local_u8Response[Local_u8Counter+3] == 'O' && Local_u8Response[Local_u8Counter+4] == 'K')
		{
			/* +IPD,1:0CLOSED */

			while(!(Local_u8Response[Local_u8Counter+16+Local_u32DataIndex]=='C' && Local_u8Response[Local_u8Counter+17+Local_u32DataIndex]=='L')){
				data_array[Local_u32DataIndex]=Local_u8Response[Local_u8Counter+16+Local_u32DataIndex];
				Local_u32DataIndex++;
			}

			return 1;
		}			
		else
		{
			return 0;
		}
	}
	return 0;
}
