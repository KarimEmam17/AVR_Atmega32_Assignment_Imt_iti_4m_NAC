/*
 * Timer_Private.h
 *
 *  Created on: Jan 25, 2023
 *      Author: Almodather
 */

#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_

/*********************************************************GENERAL REGISTERS USED WITH Register****************************************/

#define TIMER_SREG		*((volatile u8*)0x5F) //Status Register
/*TIMER_SREG REGISTER BIT*/
#define TIMER_SREG_I	7 //Bit 7 – I: Global Interrupt Enable



/*********************************************************GENERAL REGISTERS USED WITH TIMERS****************************************/



#define TIMER_TIMSK		*((volatile u8*)0x59) //Timer/Counter Interrupt Mask Register

/*TIMER_TIMSK REGISTER BITS*/
#define TIMER_TIMSK_OCIE2		7
#define TIMER_TIMSK_TOIE2		6
#define TIMER_TIMSK_TICIE1		5
#define TIMER_TIMSK_OCIE1A		4
#define TIMER_TIMSK_OCIE1B		3
#define TIMER_TIMSK_TOIE1		2
#define TIMER_TIMSK_OCIE0		1
#define TIMER_TIMSK_TOIE0		0


#define TIMER_TIFR		*((volatile u8*)0x58) //Timer/Counter Interrupt Flag Register

/*TIMER_TIFR REGISTER BITS*/

#define TIMER_TIFR_OCF2			7
#define TIMER_TIFR_TOV2			6
#define TIMER_TIFR_ICF1			5
#define TIMER_TIFR_OCF1A		4
#define TIMER_TIFR_OCF1B		3
#define TIMER_TIFR_TOV1			2
#define TIMER_TIFR_OCF0			1
#define TIMER_TIFR_TOV0			0

/******************************************************************TIMER0 REGISTERS************************************************/
#define TIMER_TCCR0		*((volatile u8*)0x53) //Timer/Counter Control
#define TIMER_TCNT0		*((volatile u8*)0x52) //Timer/Counter Register
#define TIMER_OCR0		*((volatile u8*)0x5C) //Timer/Counter0 Output Compare Register

/*TIMER_TCCR0 REGISTER BITS*/
#define TIMER_TCCR0_FOC0	7
#define TIMER_TCCR0_WGM00 	6
#define TIMER_TCCR0_COM01	5
#define TIMER_TCCR0_COM00	4
#define TIMER_TCCR0_WGM01	3
#define TIMER_TCCR0_CS02	2
#define TIMER_TCCR0_CS01	1
#define TIMER_TCCR0_CS00	0



#endif /* TIMER_PRIVATE_H_ */
