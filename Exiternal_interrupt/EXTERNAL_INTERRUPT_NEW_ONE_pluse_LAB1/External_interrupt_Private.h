/*
 * External_interrupt_Private.h
 *
 *  Created on: Dec 3, 2022
 *      Author: Almodather
 */

#ifndef EXTERNAL_INTERRUPT_PRIVATE_H_
#define EXTERNAL_INTERRUPT_PRIVATE_H_



#define  EXTI_u8_MCUCR    *((volatile u8*)0x55)     // ----> this register is responsbale for selected the mode of  int 1,0
#define  EXTI_u8_MCUCSR   *((volatile u8*)0x54)		// ----> this register is responsbale for selected the mode of  int 2
#define  EXTI_u8_GICR     *((volatile u8*)0x5B)
#define  EXTI_u8_GIFR	  *((volatile u8*)0x5A)
#define  EXTI_u8_SREG     *((volatile u8*)0x5F)

#define NULL ((void *)0)

#endif /* EXTERNAL_INTERRUPT_PRIVATE_H_ */


