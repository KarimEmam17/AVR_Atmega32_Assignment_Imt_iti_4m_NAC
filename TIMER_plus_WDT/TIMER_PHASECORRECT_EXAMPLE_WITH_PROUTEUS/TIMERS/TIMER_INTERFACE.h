/*
 * TIMER_INTERFACE.h
 *
 *  Created on: Jan 25, 2023
 *      Author: Almodather
 */

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_


/***************************cpu frq****************************/
#define MICRO_CONTROLLER_FRQ 8000000
/********************************************************Timers******************/
#define Timer0					0
#define Timer1					1
#define Timer2					2
/**************************************PRESCALAR********************************************/

#define TiMER_NO_PRESCALAR		0
#define TiMER_1_PRESCALAR		1
#define TiMER_8_PRESCALAR		2
#define TiMER_64_PRESCALAR		3
#define TiMER_256_PRESCALAR		4
#define TiMER_1024_PRESCALAR	5
#define External_Clock_Source_On_T0_Pin_Clock_On_Falling_Edge		6
#define External_Clock_Source_On_T0_Pin_Clock_On_Rising_Edge		7

/**********************************FAST PWM FREQUANCE*************************************************************/
#define  TIMER_FREQ_31_25KHZ 			TiMER_1_PRESCALAR
#define  TIMER_FREQ_3_9KHZ 				TiMER_8_PRESCALAR
#define  TIMER_FREQ_500HZ 				TiMER_64_PRESCALAR
#define  TIMER_FREQ_122HZ 				TiMER_256_PRESCALAR
#define  TIMER_FREQ_30HZ 				TiMER_1024_PRESCALAR
/**********************************PHASE CORRECT PWM FREQUANCE*************************************************************/
#define  PHASE_CORRECT_OFFSET			10
#define  TIMER_FREQ_15_6KHZ 			(TiMER_1_PRESCALAR+PHASE_CORRECT_OFFSET)
#define  TIMER_FREQ_2KHZ 				(TiMER_8_PRESCALAR+PHASE_CORRECT_OFFSET)
#define  TIMER_FREQ_250HZ 				(TiMER_64_PRESCALAR+PHASE_CORRECT_OFFSET)
#define  TIMER_FREQ_61HZ 				(TiMER_256_PRESCALAR+PHASE_CORRECT_OFFSET)
#define  TIMER_FREQ_15HZ 				(TiMER_1024_PRESCALAR+PHASE_CORRECT_OFFSET)

/***************************************************** FUNCTION***************************/
void Timer_DelayInit(u8 COPY_u8_Timer_Num);

void TIMER_PWMINIT(u8 COPY_u8_TIMER_NUM,u8 COPY_u8_FREQUANCY);

void TIMER_PWMRUN(u8 COPY_u8_TIMER_NUM,u8 COPY_DUTY_CYCLE);

void TIMER_PWMSTOP(u8 COPY_u8_TIMER_NUM);

void Timer_Delay_MS_Sync(u8 COPY_u8_Timer_Num,u32 COPY_u32_DelayPeriod_MS);//this function  generate  delay in polling

void Timer_Delay_MS_ASync(u8 COPY_u8_Timer_Num,u32 COPY_u32_DelayPeriod_MS,void (*PTRFUNC)(void));//this function  generate  delay in ISR

/************ISR's*******************/
void __vector_10(void)__attribute__((signal));//this is ctc timer0  interrupt0

#endif /* TIMER_INTERFACE_H_ */
