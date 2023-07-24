/*
 * Timer.c
 *
 *  Created on: Jan 25, 2023
 *      Author: Almodather
 */


#include "../STD_LIB/STD_Types.h"
#include  "../STD_LIB/util.h"
#include "../MCAL/DIO/DIO_INTERFACE.h"

#include "Timer_Private.h"
#include "Timer_Config.h"
#include "TIMER_INTERFACE.h"

/************************************************************************************************/

/************************GLOBAL VAR SHARED BEtWEEN FUNC*****************************************/

static u8 COPY_STATIC_Timer0_Prescalar ;
static u8 COPY_STATIC_Timer1_Prescalar ;
static u8 COPY_STATIC_Timer2_Prescalar ;


/************************GLOBAL VAR Used  WIth ISR ************************************************************************/
static u32 COPY_STATIC_TIMER0_DELAYPERIOD;
static u32 COPY_STATIC_TIMER1_DELAYPERIOD;
static u32 COPY_STATIC_TIMER2_DELAYPERIOD;


/**************GLOBAL POINTER TO  FUNCTION USED IN CALL  BACK FUNCTION ***************/
static void (*PTRFUNC_TIMER0_ISR)(void)=NULL;
static void (*PTRFUNC_TIMER1_ISR)(void)=NULL;
static void (*PTRFUNC_TIMER2_ISR)(void)=NULL;

/***********************************************************************************************/
static void Timer_Start(u8 COPY_u8_Timer_Num)
{
	switch (COPY_u8_Timer_Num)
		{
		case Timer0:
			/*STOPPING TIMER0 */
			TIMER_TCCR0 &=Timer0_Stop;

			/******Reseting  Timer/counter  register *******/

			TIMER_TCNT0=0;
			/***********STARTING  THE TIMER0***************/
			TIMER_TCCR0 |=COPY_STATIC_Timer0_Prescalar;
			break;

		case Timer1:
			/*STOPPING TIMER0 */
			TIMER_TCCR1 &=TIMER1_STOP;

			/******Reseting  Timer/counter  register *******/

			TIMER_TCNT1=0;
			/***********STARTING  THE TIMER0***************/
			TIMER_TCCR1 |=COPY_STATIC_Timer1_Prescalar;
			break;

		case Timer2:
			break;

		default:
			break;
		}
}

static void Timer_Stop(u8 COPY_u8_Timer_Num)
{
	switch (COPY_u8_Timer_Num)
		{
		case Timer0:
			/*STOPPING TIMER0 */
			TIMER_TCCR0 &=Timer0_Stop;
			break;

		case Timer1:
			break;

		case Timer2:
			break;

		default:
			break;
		}
}


void Timer_DelayInit(u8 COPY_u8_Timer_Num)
{
	switch (COPY_u8_Timer_Num)
	{
	case Timer0:
		/*********************SET The prescalar to Global VAR To USE It With START_FUNC------------->64------------>FRQ 8MHz *****************************/
		COPY_STATIC_Timer0_Prescalar=TiMER_64_PRESCALAR;
		/************ACTIVE THE CTC MODE************/
		set_bit(TIMER_TCCR0,TIMER_TCCR0_WGM01);
		/*******************setting OCR0 VALUE TO  MAKE ADELAY 1ms at prescalar64 and FRQ 8MHZ ************************/

		TIMER_OCR0=125;
		break;

	case Timer1:
		/*********************SET The prescalar to Global VAR To USE It With START_FUNC *****************************/
				COPY_STATIC_Timer1_Prescalar=TiMER_64_PRESCALAR;
		break;

	case Timer2:
		/*********************SET The prescalar to Global VAR To USE It With START_FUNC *****************************/
				COPY_STATIC_Timer2_Prescalar=TiMER_64_PRESCALAR;
		break;

	default:
		break;
	}
}

void TIMER_PWMINIT(u8 COPY_u8_TIMER_NUM,u8 COPY_u8_FREQUANCY)
{
	switch (COPY_u8_TIMER_NUM)
		{
		case Timer0:
			COPY_STATIC_Timer0_Prescalar=COPY_u8_FREQUANCY;
			switch(COPY_u8_FREQUANCY)
			{
				/****case in  range of FAST  PWM*********************/
				case TIMER_FREQ_31_25KHZ ... TIMER_FREQ_30HZ:
					/************set tccr0 to fast pwm******************/
					set_bit(TIMER_TCCR0,TIMER_TCCR0_WGM00);
					set_bit(TIMER_TCCR0,TIMER_TCCR0_WGM01);
					/***********set tccr0 to non inverted mode ****************/
					set_bit(TIMER_TCCR0,TIMER_TCCR0_COM01);
					clear_bit(TIMER_TCCR0,TIMER_TCCR0_COM00);
				break;
				/****case in  range of phase correct PWM*********************/
				case TIMER_FREQ_15_6KHZ ... TIMER_FREQ_15HZ:
					/**********REMOVING THE PHASE CORRECT OFFSET*************************************************/
					COPY_STATIC_Timer0_Prescalar-=PHASE_CORRECT_OFFSET;
					/************set tccr0 to PHASE CORRECT PWM******************/
					set_bit(TIMER_TCCR0,TIMER_TCCR0_WGM00);
					clear_bit(TIMER_TCCR0,TIMER_TCCR0_WGM01);
					/***********set tccr0 to non inverted mode ****************/
					set_bit(TIMER_TCCR0,TIMER_TCCR0_COM01);
					clear_bit(TIMER_TCCR0,TIMER_TCCR0_COM00);
				break;
			}
			break;

		case Timer1:

			break;

		case Timer2:

			break;

		default:
			break;
		}
}

void TIMER_PWMRUN(u8 COPY_u8_TIMER_NUM,u8 COPY_DUTY_CYCLE)
{
	switch (COPY_u8_TIMER_NUM)
			{
			case Timer0:
				TIMER_OCR0=COPY_DUTY_CYCLE;
				Timer_Start(Timer0);

				break;

			case Timer1:

				break;

			case Timer2:

				break;

			default:
				break;
			}
}

void TIMER_PWMSTOP(u8 COPY_u8_TIMER_NUM)
{
	switch (COPY_u8_TIMER_NUM)
				{
				case Timer0:
					Timer_Stop(Timer0);

					break;

				case Timer1:

					break;

				case Timer2:

					break;

				default:
					break;
				}
}
void Timer_Delay_MS_Sync(u8 COPY_u8_Timer_Num,u32 COPY_u32_DelayPeriod_MS)//this function  generate  delay in polling
{
	switch (COPY_u8_Timer_Num)
		{
		case Timer0:

			/*start timer 0*/


			Timer_Start(Timer0);
			/*looping over delay period*/
			while(COPY_u32_DelayPeriod_MS--)
			{
				/*waiting untile 1ms of delay passes*/
				while (get_bit(TIMER_TIFR,TIMER_TIFR_OCF0));
				/*clearing the flag bit CTC*/
				set_bit(TIMER_TIFR,TIMER_TIFR_OCF0);
			}
			/*start timer 0*/
			Timer_Stop(Timer0);
			break;

		case Timer1:
			/*********************SET The prescalar to Global VAR To USE It With START_FUNC *****************************/

			break;

		case Timer2:
			/*********************SET The prescalar to Global VAR To USE It With START_FUNC *****************************/

			break;

		default:
			break;
		}



}
void Timer_Delay_MS_ASync(u8 COPY_u8_Timer_Num,u32 COPY_u32_DelayPeriod_MS,void (*PTRFUNC)(void))
{
	/********************this function  generate  delay in ISR*********************/
	/**********Enable global  interrupt*************/
	set_bit(TIMER_SREG,TIMER_SREG_I);

	switch (COPY_u8_Timer_Num)
			{
			case Timer0:
				set_bit(TIMER_TIMSK,TIMER_TIMSK_OCIE0);
				/**************SAVING THE delay PERIOD TO CHECK IT AT ISR ***********/
				COPY_STATIC_TIMER0_DELAYPERIOD=COPY_u32_DelayPeriod_MS;
				/********setting callback  function address***********/
				PTRFUNC_TIMER0_ISR=PTRFUNC;
				/*start timer 0*/
				Timer_Start(Timer0);
				/*******Enable clear to  compare match  interrupt  ************/


				break;

			case Timer1:
				/*********************SET The prescalar to Global VAR To USE It With START_FUNC *****************************/
				/**************SAVING THE delay PERIOD TO CHECK IT AT ISR ***********/
				COPY_STATIC_TIMER1_DELAYPERIOD=COPY_u32_DelayPeriod_MS;
				/********setting callback  function address***********/
				PTRFUNC_TIMER1_ISR=PTRFUNC;
				break;

			case Timer2:
				/*********************SET The prescalar to Global VAR To USE It With START_FUNC *****************************/
				/**************SAVING THE delay PERIOD TO CHECK IT AT ISR ***********/
				COPY_STATIC_TIMER2_DELAYPERIOD=COPY_u32_DelayPeriod_MS;
				/********setting callback  function address***********/
				PTRFUNC_TIMER2_ISR=PTRFUNC;
				break;

			default:
				break;
			}

}

void TIMER1_CUSTOM_FREQ_PWM_INIT(u16 COPY_u16_periodic_time_US)
{
	/*********setting non inverted mode  in  channel  A and B , selecting phase correct with  top at ICR1(mode 10 )*********************/
	TIMER_TCCR1=0xA210;
	/*********setting the periodic time  in  microseconde *********/
	TIMER_ICR1=COPY_u16_periodic_time_US/2;
	/***********select prescalar 8prescalar to  get 1us tick  *************/
	COPY_STATIC_Timer1_Prescalar=TiMER_8_PRESCALAR;
}

void TIMER1_CUSTOM_FREQ_PWM_RUN(u8 CUSTOM_Channel,u16 COPY_u16_DUTYCYCLE)
{
	switch (CUSTOM_Channel)
	{
	case TIMER_CUSTOM_CHANNEL_A:
		/****setting the duty cycle****/
		TIMER_OCR1A=COPY_u16_DUTYCYCLE;
		Timer_Start(Timer1);
		break;
	case TIMER_CUSTOM_CHANNEL_B:
		/******setting the duty cycle*******/
		TIMER_OCR1B=COPY_u16_DUTYCYCLE;
		Timer_Start(Timer1);
		break;
	}

}
/*******************TIMER ISR'S****************************************************************************************************/

/***********timer0 compare match  interrupt service routine   ISR****************/
void __vector_10 (void)
{


	if (PTRFUNC_TIMER0_ISR !=NULL)

	{
		if(COPY_STATIC_TIMER0_DELAYPERIOD)
		{
			/**********decrement by 1ms *********/
			COPY_STATIC_TIMER0_DELAYPERIOD--;
		}
		else
		{
			/*****call back  function ********/
			PTRFUNC_TIMER0_ISR();
			/*********disable the interrupt************/
			clear_bit(TIMER_TIMSK,TIMER_TIMSK_OCIE0);
			/*****stop  the timer*************/
			Timer_Stop(Timer0);


		}


	}

}




















