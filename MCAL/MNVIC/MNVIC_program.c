/*
 * MNVIC_program.c
 *
 *  Created on: Aug 13, 2023
 *      Author: Mostafa_Salem
 */
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"
#include "MNVIC_private.h"
#include "MNVIC_config.h"
#include "MNVIC_interface.h"

PRIGROUP_t G_SelectedGroupsNo;

void MNVIC_vEnableInterrupt(INTERRUPT_POS_t A_InterruptPosition){
	SET_BIT(NVIC->ISER[A_InterruptPosition/REGISTER_SIZE],A_InterruptPosition%REGISTER_SIZE);
}

void MNVIC_vDisableInterrupt(INTERRUPT_POS_t A_InterruptPosition){
	SET_BIT(NVIC->ICER[A_InterruptPosition/REGISTER_SIZE],A_InterruptPosition%REGISTER_SIZE);
}

void MNVIC_vSetPendingFlag(INTERRUPT_POS_t A_InterruptPosition){
	SET_BIT(NVIC->ISPR[A_InterruptPosition/REGISTER_SIZE],A_InterruptPosition%REGISTER_SIZE);
}

void MNVIC_vClearPendingFlag(INTERRUPT_POS_t A_InterruptPosition){
	SET_BIT(NVIC->ICPR[A_InterruptPosition/REGISTER_SIZE],A_InterruptPosition%REGISTER_SIZE);
}

u8 	 MNVIC_u8GetPendingFlag(INTERRUPT_POS_t A_InterruptPosition){
	return GET_BIT(NVIC->ICPR[A_InterruptPosition/REGISTER_SIZE],A_InterruptPosition%REGISTER_SIZE);
}

u8	 MNVIC_u8GetActiveFlag(INTERRUPT_POS_t A_InterruptPosition){
	return GET_BIT(NVIC->IABR[A_InterruptPosition/REGISTER_SIZE],A_InterruptPosition%REGISTER_SIZE);
}
void MNVIC_vSetPriorityGroups(PRIGROUP_t PriGroup){
	G_SelectedGroupsNo = PriGroup;
	AIRCR = VECTKEY;
	u32 L_u32Temp = VECTKEY | (PriGroup << BYTE_SIZE);
	AIRCR = L_u32Temp;
}
void MNVIC_vSetInterruptPriority(INTERRUPT_POS_t A_InterruptPosition,GROUPS_t A_GroupNo,SUBGROUPS_t A_SubGroupNo){
	switch(G_SelectedGroupsNo){
	case GROUP_16_SUB_0:
		NVIC->IPR[A_InterruptPosition] = (A_GroupNo << NIBBLE_SIZE);
		break;
	case GROUP_8_SUB_2:
		NVIC->IPR[A_InterruptPosition] = (A_GroupNo << FIVE_BITS_SIZE) | (A_SubGroupNo << NIBBLE_SIZE);
		break;
	case GROUP_4_SUB_4:
		NVIC->IPR[A_InterruptPosition] = (A_GroupNo << SIX_BITS_SIZE) | (A_SubGroupNo << NIBBLE_SIZE);
		break;
	case GROUP_2_SUB_8:
		NVIC->IPR[A_InterruptPosition] = (A_GroupNo << SEVEN_BITS_SIZE) | (A_SubGroupNo << NIBBLE_SIZE);
		break;
	case GROUP_0_SUB_16:
		NVIC->IPR[A_InterruptPosition] = (A_SubGroupNo << NIBBLE_SIZE);
		break;
	}
}
