/*
 * MRCC_private.h
 *
 *  Created on: Aug 10, 2023
 *      Author: Mostafa_Salem
 */

#ifndef MCAL_MRCC_MRCC_PRIVATE_H_
#define MCAL_MRCC_MRCC_PRIVATE_H_

/****************** Bits of CR Register *********************************/
#define HSION	0
#define HSIRDY  1
#define HSITRIM 3
#define HSEON	16
#define HSERDY  17
#define HSEBYP	18
#define CSSON	19
#define PLLON	24
#define PLLRDY  25
/***********************************************************************/

/******************* Bits of PLLCFGR Register **************************/
#define PLLM	0
#define PLLN	6
#define PLLP	16
#define PLLSRC	22
/**********************************************************************/

/******************* Bits of RCC_CFGR Register ************************/
#define SW0		0
#define SW1		1
#define SWS0	2
#define SWS1	3
#define HPRE	4
#define PPRE1	10
#define PPRE2	13
/**********************************************************************/

/*********************** RCC BASE ADDRESS *******************************/
#define RCC_BASE_ADDRESS 0x40023800
/************************************************************************/

/*********************** RCC Registers **********************************/
typedef struct {
	u32 CR;
	u32 PLLCFGR;
	u32 CFGR;
	u32 CIR;
	u32 AHB1RSTR;
	u32 AHB2RSTR;
	u32 Reserved1;
	u32 Reserved2;
	u32 APB1RSTR;
	u32 APB2RSTR;
	u32 Reserved3;
	u32 Reserved4;
	u32 AHB1ENR;
	u32 AHB2ENR;
	u32 Reserved5;
	u32 Reserved6;
	u32 APB1ENR;
	u32 APB2ENR;
}RCC_t;

#define RCC ((volatile RCC_t*)(RCC_BASE_ADDRESS))
/***********************************************************************/

#endif /* MCAL_MRCC_MRCC_PRIVATE_H_ */
