/*
 * MSYSTICK_private.h
 *
 *  Created on: Aug 15, 2023
 *      Author: Mostafa_Salem
 */

#ifndef MCAL_MSYSTIKC_MSYSTICK_PRIVATE_H_
#define MCAL_MSYSTIKC_MSYSTICK_PRIVATE_H_

#define SYSTICK_BASE_ADDRESS	0xE000E010

#define ENABLE		0
#define TICKINT		1
#define CLKSOURCE	2
#define COUNTFLAG	16

typedef struct{
	u32 CTRL;
	u32 LOAD;
	u32 VAL;
	u32 CALIB;
}SYSTICK_t;

#define SYSTICK		((volatile SYSTICK_t*)(SYSTICK_BASE_ADDRESS))

#endif /* MCAL_MSYSTIKC_MSYSTICK_PRIVATE_H_ */
