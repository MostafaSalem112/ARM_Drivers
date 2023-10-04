/*
 * MNVIC_interface.h
 *
 *  Created on: Aug 13, 2023
 *      Author: Mostafa_Salem
 */

#ifndef MCAL_MNVIC_MNVIC_INTERFACE_H_
#define MCAL_MNVIC_MNVIC_INTERFACE_H_


#define FOUR_BITS_HIGH	0b1111

#define NIBBLE_SIZE		4
#define FIVE_BITS_SIZE	5
#define SIX_BITS_SIZE	6
#define SEVEN_BITS_SIZE	7
#define BYTE_SIZE		8
#define REGISTER_SIZE	32

typedef enum{
	GROUP_16_SUB_0=3,
	GROUP_8_SUB_2,
	GROUP_4_SUB_4,
	GROUP_2_SUB_8,
	GROUP_0_SUB_16,
}PRIGROUP_t;

typedef enum{
	GROUP_0,
	GROUP_1,
	GROUP_2,
	GROUP_3,
	GROUP_4,
	GROUP_5,
	GROUP_6,
	GROUP_7,
	GROUP_8,
	GROUP_9,
	GROUP_10,
	GROUP_11,
	GROUP_12,
	GROUP_13,
	GROUP_14,
	GROUP_15,
}GROUPS_t;

typedef enum{
	SUBGROUP_0,
	SUBGROUP_1,
	SUBGROUP_2,
	SUBGROUP_3,
	SUBGROUP_4,
	SUBGROUP_5,
	SUBGROUP_6,
	SUBGROUP_7,
	SUBGROUP_8,
	SUBGROUP_9,
	SUBGROUP_10,
	SUBGROUP_11,
	SUBGROUP_12,
	SUBGROUP_13,
	SUBGROUP_14,
	SUBGROUP_15,
}SUBGROUPS_t;

typedef enum{
	WWDG,
	EXTI16_PVD,
	EXTI21_TAMP_STAMP,
	EXTI22_RTC_WKUP,
	FLASH,
	RCC,
	EXTI0,
	EXTI1,
	EXTI2,
	EXTI3,
	EXTI4,
	DMA1_Stream0,
	DMA1_Stream1,
	DMA1_Stream2,
	DMA1_Stream3,
	DMA1_Stream4,
	DMA1_Stream5,
	DMA1_Stream6,
	ADC,
	EXTI9_5 = 23,
	TIM1_BRK_TIM9,
	TIM1_UP_TIM10,
	TIM1_TRG_COM_TIM11,
	TIM1_CC,
	TIM2,
	TIM3,
	TIM4,
	I2C1_EV,
	I2C1_ER,
	I2C2_EV,
	I2C2_ER,
	SPI1,
	SPI2,
	USART1,
	USART2,
	EXTI15_10 = 40,
	EXTI17_RTC_Alarm,
	EXTI18_OTG_FS_WKUP,
	DMA1_Stream7 = 47,
	SDIO = 49,
	TIM5,
	SPI3,
	DMA2_Stream0 = 56,
	DMA2_Stream1,
	DMA2_Stream2,
	DMA2_Stream3,
	DMA2_Stream4,
	OTG_FS = 67,
	DMA2_Stream5,
	DMA2_Stream6,
	DMA2_Stream7,
	USART6,
	I2C3_EV,
	I2C3_ER,
	FPU = 81,
	SPI4 = 84,
}INTERRUPT_POS_t;

void MNVIC_vEnableInterrupt(INTERRUPT_POS_t A_InterruptPosition);
void MNVIC_vDisableInterrupt(INTERRUPT_POS_t A_InterruptPosition);
void MNVIC_vSetPendingFlag(INTERRUPT_POS_t A_InterruptPosition);
void MNVIC_vClearPendingFlag(INTERRUPT_POS_t A_InterruptPosition);
u8 	 MNVIC_u8GetPendingFlag(INTERRUPT_POS_t A_InterruptPosition);
u8	 MNVIC_u8GetActiveFlag(INTERRUPT_POS_t A_InterruptPosition);
void MNVIC_vSetPriorityGroups(PRIGROUP_t PriGroup);
void MNVIC_vSetInterruptPriority(INTERRUPT_POS_t A_InterruptPosition,GROUPS_t A_GroupNo,SUBGROUPS_t A_SubGroupNo);

#endif /* MCAL_MNVIC_MNVIC_INTERFACE_H_ */
