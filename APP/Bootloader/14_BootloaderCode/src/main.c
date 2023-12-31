#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"

#include "MRCC_interface.h"
#include "MGPIO_interface.h"
#include "MNVIC_Interface.h"
#include "MEXTI_interface.h"
#include "MSYSTICK_Interface.h"

#include "MUSART_Interface.h"

#include "MFPEC_Interface.h"


#include "SPARSER_Interface.h"

volatile u8 u8RecBuffer[100] = {0}   ;
volatile u8 u8RecCounter     =  0    ;
volatile u8 TimeOutFlag      =  0    ;
volatile u8 u8BLWriteReq     =  1    ;

typedef void (*Function_t)(void) ;

Function_t  Addr_To_Call = 0;  // void (*Addr_To_Call)(void)

void Func_CallBack(void){

	/*Some Code*/

	TimeOutFlag = 1 ;

#define SCB_VTOR  *((volatile u32 *)0xE000ED08)

	/*Move Vector table*/
	SCB_VTOR     = 0x08004000 ; //starting of Sector 1

	/*set Address to call with RESET_ISR(Startup code of Application)*/
	Addr_To_Call = *(Function_t *)0x08004004 ;

	Addr_To_Call();

}


void main(void)
{
	u8 LOC_u8RecStatus = 0;
	/*************************************************************************************************************************/
	/********************************Step 1: initialize System Clock is 16MHz from HSI****************************************/
	/*************************************************************************************************************************/

	/*System Clock is 16MHz from HSI*/
	MRCC_voidInitSystemClk();

	/*************************************************************************************************************************/
	/********************************************Step 2: Enable peripherls clock**********************************************/
	/*************************************************************************************************************************/

	/*Enable GPIO Peripheral clock*/
	MRCC_voidEnablePeripheralClock(AHB1,_PERIPHERAL_EN_GPIOA ) ;

	/*Enable RCC For USART1*/
	MRCC_voidEnablePeripheralClock(APB2, PERIPHERAL_EN_USART1); //Enable CLK Of UART1   At APB2

	/*Enable FPEC*/
	MRCC_voidEnablePeripheralClock(AHB1,_PERIPHERAL_EN_FPEC ) ;

	/*************************************************************************************************************************/
	/********************************************Step 3: Configur UART1 ,UART2  Pins******************************************/
	/*************************************************************************************************************************/

	MGPIO_voidSetPinMode(_GPIOA_PORT, _PIN_9, _MODE_ALTF);     //TX-->UART1
	MGPIO_voidSetPinMode(_GPIOA_PORT, _PIN_10, _MODE_ALTF);    //RX-->UART1
	MGPIO_voidSetPinAltFn(_GPIOA_PORT, _PIN_9, _ALTFN_7);      //TX-->UART1
	MGPIO_voidSetPinAltFn(_GPIOA_PORT, _PIN_10, _ALTFN_7);     //RX-->UART1


	/*************************************************************************************************************************/
	/********************************************Step 4: initialize Output Pins  in System ***********************************/
	/*************************************************************************************************************************/
	for(u8 PIN = 0 ;PIN <3 ;PIN++ )
	{
		/*Set Pin Mode --> Output*/
		MGPIO_voidSetPinMode(_GPIOA_PORT, PIN, _MODE_OUTPUT) ;
		/*Out put Push Pull*/
		MGPIO_voidSetPinOutPutType(_GPIOA_PORT,PIN,_OUTPUT_TYPE_PUSH_PULL);
		/*Pin Speed*/
		MGPIO_voidSetPinOutSpeed(_GPIOA_PORT, PIN, _OUTPUT_SPEED_LOW);
	}
	MGPIO_voidWriteData(_GPIOA_PORT,_PIN_1, _HIGH) ; //indicate to I am in BootLoader Code
	MGPIO_voidWriteData(_GPIOA_PORT,_PIN_2, _HIGH) ;
	/*************************************************************************************************************************/
	/********************************************Step 5: Enable Peripherials interrupt from NVIC *****************************/
	/*************************************************************************************************************************/

	//MNVIC_voidEnableInterrupt(37) ;              //Enable uart1 from NVIC

	/*************************************************************************************************************************/
	/********************************************Step 6: Initialize USART1 ***************************************************/
	/*************************************************************************************************************************/

	MSUART_voidInit();

	/*************************************************************************************************************************/
	/********************************************Step 6:  initialize system Peripherials *************************************/
	/*************************************************************************************************************************/
	MUSART_voidEnable(1) ; //Enable UART 1

	MUSART_u8SendData(1,(u8*)"Ahmed",5);

	/*SysTick Init*/
	MSTK_voidInit(); /*Enable SysTick AHB/8 = 2MHZ , 1 count = 0.5 Micro second  */

	/*Send Data Serial*/

	MSTK_voidSetIntervalSingle( 15000000 , Func_CallBack );

	/* Loop forever */


	while( TimeOutFlag == 0 )
	{

		LOC_u8RecStatus = MUSART1_u8ReceiveCharSync(&u8RecBuffer[u8RecCounter]);

		if( LOC_u8RecStatus == 1 )
		{
            /*Stop timer Application code in processing*/
			MSTK_voidStopTimer();

			/*Indicate The end of the Record*/
			if( u8RecBuffer[u8RecCounter] == '\n' ){

				if( u8BLWriteReq == 1 ){
                    /*Erase The Application Area*/
					MFPEC_voidEraseAppArea();
					/*Set WriteReq Flag = 0 */
					u8BLWriteReq = 0 ;

				}
                /*Parse The record and wite it to flash*/
				PARSE_voidParseRecord( u8RecBuffer );
                /*send ok to the tool to send the next record*/
				//MUSART1_voidSendSrtingSynch((u8 *)"ok");
				u8RecCounter = 0 ;

			}
			else{ u8RecCounter++ ; }

			/*End of hex file */
			if( u8RecBuffer[8] == '1' ){
                /*wait 1 sec then jump to application code*/
				MSTK_voidSetIntervalSingle( 1000000 , Func_CallBack );
				MGPIO_voidWriteData(_GPIOA_PORT,_PIN_0, _HIGH) ; //indicate to successful flashing
			}

		}

	}

}