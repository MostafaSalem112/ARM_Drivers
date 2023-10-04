/*
 * MGPIO_interface.h
 *
 *  Created on: Aug 10, 2023
 *      Author: Mostafa_Salem
 */

#ifndef MCAL_MGPIO_MGPIO_INTERFACE_H_
#define MCAL_MGPIO_MGPIO_INTERFACE_H_

// GPIO Ports
#define GPIO_PORTA 0
#define GPIO_PORTB 1
#define GPIO_PORTC 2

// GPIO Pins
#define GPIO_PIN0	0
#define GPIO_PIN1	1
#define GPIO_PIN2	2
#define GPIO_PIN3	3
#define GPIO_PIN4	4
#define GPIO_PIN5	5
#define GPIO_PIN6	6
#define GPIO_PIN7	7
#define GPIO_PIN8	8
#define GPIO_PIN9	9
#define GPIO_PIN10	10
#define GPIO_PIN11	11
#define GPIO_PIN12	12
#define GPIO_PIN13	13
#define GPIO_PIN14	14
#define GPIO_PIN15	15

// Pins Output Level
#define GPIO_LOW	0
#define GPIO_HIGH	1

// Pins Modes
#define GPIO_MODE_INPUT		0b00
#define GPIO_MODE_OUTPUT	0b01
#define GPIO_MODE_ALTFUN	0b10
#define GPIO_MODE_ANALOG	0b11

// Pins Output type
#define GPIO_PUSHPULL	0
#define GPIO_OPENDRAIN	1

// Pins Output Speed
#define GPIO_LOW_SPEED			0b00
#define GPIO_MEDIUM_SPEED		0b01
#define GPIO_HIGH_SPEED			0b10
#define GPIO_VERY_HIGH_SPEED	0b11

// Pins Pull Type
#define GPIO_NO_PULL	0b00
#define GPIO_PULL_UP	0b01
#define GPIO_PLL_DOWN	0b10

// Alternative Functions
#define ALTFUN_0	0b0000
#define ALTFUN_1	0b0001
#define ALTFUN_2	0b0010
#define ALTFUN_3	0b0011
#define ALTFUN_4	0b0100
#define ALTFUN_5	0b0101
#define ALTFUN_6	0b0110
#define ALTFUN_7	0b0111
#define ALTFUN_8	0b1000
#define ALTFUN_9	0b1001
#define ALTFUN_10	0b1010
#define ALTFUN_11	0b1011
#define ALTFUN_12	0b1100
#define ALTFUN_13	0b1101
#define ALTFUN_14	0b1110
#define ALTFUN_15	0b1111

#define CRUMB_SIZE	2
#define NIBBLE_SIZE	4
#define BYTE_SIZE	8
#define WORD_SIZE	16

#define TWO_BITS_HIGH	0b11
#define FOUR_BITS_HIGH	0b1111

// Prototypes
void MGPIO_vSetPinMode(u8 A_u8PortID,u8 A_u8PinNo,u8 A_u8Mode);
void MGPIO_vSetPinOutPutType(u8 A_u8PortID,u8 A_u8PinNo,u8 A_u8OutPutType);
void MGPIO_vSetPinOutPutSpeed(u8 A_u8PortID,u8 A_u8PinNo,u8 A_u8OutPutSpeed);
void MGPIO_vSetPinInPutPull(u8 A_u8PortID,u8 A_u8PinNo,u8 A_u8PullType);
u8 MGPIO_u8GetPinValue(u8 A_u8PortID,u8 A_u8PinNo);
void MGPIO_vSetPinValue(u8 A_u8PortID,u8 A_u8PinNo,u8 A_u8PinValue);
void MGPIO_vSetPinValue_Fast(u8 A_u8PortID,u8 A_u8PinNo,u8 A_u8PinValue);
void MGPIO_vSetAlternativeFunction(u8 A_u8PortID,u8 A_u8PinNo,u8 A_u8AltFun);


#endif /* MCAL_MGPIO_MGPIO_INTERFACE_H_ */
