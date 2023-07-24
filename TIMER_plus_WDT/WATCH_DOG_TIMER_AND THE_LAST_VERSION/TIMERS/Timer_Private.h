/*
 * Timer_Private.h
 *
 *  Created on: Jan 25, 2023
 *      Author: Almodather
 */

#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_


/***************************************************************SOME PRIVATE #define **************************************************/
#define Timer0_Stop				0xF8
#define TIMER1_STOP				0xFFF8

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

/****************************************************TIMER1 REGISTERS******************************************************************/
#define TIMER_TCCR1		*((volatile u16*)0x4E)////Timer/Counter Control Register  devide to  two  parts  low (TCCR1B)+ (TCCR1A)High we takes the lowest address because it is litttel-endines
#define TIMER_TCNT1		*((volatile u16*)0x4C)//timer counter Register devide to  two  parts  low (TCNT1L)+ (TCNT1H)High we takes the lowest addressbecause it is litttel-endines
#define TIMER_OCR1A		*((volatile u16*)0x4A)////Output Compare Register devide to  two  parts  low (OCR1AL)+ (OCR1AH)High we takes the lowest address because it is litttel-endines
#define TIMER_OCR1B	    *((volatile u16*)0x48)//Output Compare Register devide to  two  parts  low (OCR1BL)+ (OCR1BH)High we takes the lowest addressbecause it is litttel-endines
#define TIMER_ICR1		*((volatile u16*)0x46)//Output Compare Register  devide to  two  parts  low (ICR1L)+ (ICR1H)High we takes the lowest addressbecause it is litttel-endines

/*TIMER_TCCR1 REGISTER BITS*/
#define TIMER_TCCR1_COM1A1	15
#define TIMER_TCCR1_COM1A0	14
#define TIMER_TCCR1_COM1B1	13
#define TIMER_TCCR1_COM1B0	12
#define TIMER_TCCR1_FOC1A	11
#define TIMER_TCCR1_FOC1B	10
#define TIMER_TCCR1_WGM11	9
#define TIMER_TCCR1_WGM10	8
#define TIMER_TCCR1_ICNC1	7
#define TIMER_TCCR1_ICES1	6
#define TIMER_TCCR1_WGM13	4
#define TIMER_TCCR1_WGM12	3
#define TIMER_TCCR1_CS12	2
#define TIMER_TCCR1_CS11	1
#define TIMER_TCCR1_CS10	0


/******************************************************TIMER2 REGISTERS********************************************************************************/
#define TIMER_TCCR2		*((volatile u8*)0x45)				////Timer/Counter Control Register
#define TIMER_TCNT2		*((volatile u8*)0x44)				////Timer/Counter2 Register
#define TIMER_ OCR2		*((volatile u8*)0x43)				////Timer/Counter2 Output Compare Register


/*TIMER_TCCR2 REGISTER BITS*/
#define TIMER_TCCR2_FOC2	7
#define TIMER_TCCR2_WGM20 	6
#define TIMER_TCCR2_COM21	5
#define TIMER_TCCR2_COM20	4
#define TIMER_TCCR2_WGM21	3
#define TIMER_TCCR2_CS22	2
#define TIMER_TCCR2_CS21	1
#define TIMER_TCCR2_CS20	0







#endif /* TIMER_PRIVATE_H_ */
