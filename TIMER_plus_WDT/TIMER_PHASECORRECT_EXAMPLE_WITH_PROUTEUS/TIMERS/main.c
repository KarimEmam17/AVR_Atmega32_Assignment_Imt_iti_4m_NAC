/*
 * main.c
 *
 *  Created on: Jan 21, 2023
 *      Author: Almodather
 */
#include <avr/delay.h>
#include "../STD_LIB/STD_Types.h"
#include "../STD_LIB/util.h"
#include "../MCAL/DIO/DIO_Private.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "Timer_Private.h"
#include "Timer_Config.h"
#include "TIMER_INTERFACE.h"


void main()
{

	DIO_u8set_pin_dir(GROUP_B,DIO_u8_PIN_3,DIO_u8_OUTPUT);
	/******PHASE CORRECT PWM duty cycle**********/
	TIMER_PWMINIT(Timer0,TIMER_FREQ_15_6KHZ);
	TIMER_PWMRUN(Timer0,20);
	while(1)
	{


	}




}
