/*
 * MRCC_config.h
 *
 *  Created on: Aug 10, 2023
 *      Author: Mostafa_Salem
 */

#ifndef MCAL_MRCC_MRCC_CONFIG_H_
#define MCAL_MRCC_MRCC_CONFIG_H_

/*************** Select the Clock Source *******************/
#define RCC_SYS_CLK		RCC_HSI			//	RCC_HSI ==> for High Speed Internal Clock
										//	RCC_HSE ==> for High Speed External Clock
										//	RCC_PLL ==> for PLL
#define RCC_HSE_ENABLE		DISABLE
#define RCC_HSI_ENABLE		ENABLE
#define RCC_PLL_ENABLE		DISABLE
/***********************************************************/

/***************** Select frequency for HSI ****************/
//	you can chose frequency from 1MHz to 16MHz
#define RCC_HSI_FREQ	16
/***********************************************************/

/*********************** Select Configurations of PLL Clock Source ***********************************/
#define RCC_PLL_SOURCE	RCC_HSE 		//	RCC_HSI ==> for High Speed Internal Clock
										//	RCC_HSE ==> for High Speed External Clock

//	f(VCO clock) = f(PLL clock input) × (PLLN / PLLM)
//	f(PLL general clock output) = f(VCO clock) / PLLP    ## its MAX value is 84MHz ##
#define RCC_PLL_M_PRESCALER		2		//	its range is from 2 to 63	## recommended to be 2 ##
#define RCC_PLL_P_PRESCALER		2		//	its range is {2,4,6,8}
#define RCC_PLL_N_PERSCALER		192		//	its range is from 192 to 432
/*****************************************************************************************************/

/********************************** Select Clock Configurations **************************************/
#define RCC_AHB_PRESCALER		1		// its range is {1,2,4,8,16,64,128,256,512}
#define RCC_APB1_PRESCALER		1		// its range is {1,2,4,8,16}
#define RCC_APB2_PRESCALER		1		// its range is {1,2,4,8,16}
/*****************************************************************************************************/

/********************************** Clock Security System Enable *************************************/
#define RCC_CSS_ENABLE		ENABLE
/*****************************************************************************************************/

#endif /* MCAL_MRCC_MRCC_CONFIG_H_ */
