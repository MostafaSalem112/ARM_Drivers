/*
 * MRCC_interface.h
 *
 *  Created on: Aug 10, 2023
 *      Author: Mostafa_Salem
 */

#ifndef MCAL_MRCC_MRCC_INTERFACE_H_
#define MCAL_MRCC_MRCC_INTERFACE_H_

#define BIT_RESET 	0
#define BIT_SET		1

#define REGISTER_CLEAR 0

#define ONE_REGISTER_SIZE 		32
#define TWO_REGISTERS_SIZE 		64
#define THREE_REGISTERS_SIZE	96
#define FOUR_REGISTERS_SIZE		128

#define DISABLE 0
#define ENABLE 	1

#define RCC_HSI 0
#define RCC_HSE 1
#define RCC_PLL 2

#define PLLP_2 	0
#define PLLP_4 	1
#define PLLP_6 	2
#define PLLP_8 	3


#define PRESCR_1	1
#define PRESCR_2	2
#define PRESCR_4	4
#define PRESCR_8	8
#define PRESCR_16	16
#define PRESCR_64	64
#define PRESCR_128	128
#define PRESCR_256	256
#define PRESCR_512	512

#define AHB_1 		0b0000
#define AHB_2 		0b1000
#define AHB_4 		0b1001
#define AHB_8 		0b1010
#define AHB_16	 	0b1011
#define AHB_64	 	0b1100
#define AHB_128 	0b1101
#define AHB_256 	0b1110
#define AHB_512 	0b1111

#define APB_1		0b000
#define APB_2		0b100
#define APB_4		0b101
#define APB_8		0b110
#define APB_16		0b111

typedef enum{
	RCC_GPIOA	=	0,
	RCC_GPIOB	=	1,
	RCC_GPIOC	=	2,
	RCC_CRC		=	12,
	RCC_DMA1	=	21,
	RCC_DMA2	=	22,
	RCC_OTGFS	=	39,
	RCC_TIM2	=	64,
	RCC_TIM3	=	65,
	RCC_TIM4	=	66,
	RCC_TIM5	=	67,
	RCC_WWDG	=	75,
	RCC_SPI2	=	78,
	RCC_SPI3	=	79,
	RCC_USART2	=	81,
	RCC_I2C1	=	85,
	RCC_I2C2	=	86,
	RCC_I2C3	=	87,
	RCC_PWR		=	92,
	RCC_TIM1	=	96,
	RCC_USART1	=	100,
	RCC_USART6	=	101,
	RCC_ADC1	=	104,
	RCC_SDIO	=	107,
	RCC_SPI1	=	108,
	RCC_SPI4	=	109,
	RCC_SYSCFG	=	110,
	RCC_TIM9	=	112,
	RCC_TIM10	=	113,
	RCC_TIM11	=	114,
}Peripherals_t;

/*************************** Prototypes *********************************************/

void MRCC_vInit(void);
void MRCC_vEnablePeripheralClock(Peripherals_t preipheral);
void MRCC_vDisablePeripheralClock(Peripherals_t preipheral);


#endif /* MCAL_MRCC_MRCC_INTERFACE_H_ */
