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
#include "WDT.h"



void main()
{
	u32 duty_cycle;
	u32 FRQuacnY;
	DIO_u8set_pin_dir(GROUP_B,DIO_u8_PIN_3,DIO_u8_OUTPUT);
	DIO_u8set_pin_dir(GROUP_D,DIO_u8_PIN_6,DIO_u8_INPUT);
	TIMER_PWMINIT(Timer0,TIMER_FREQ_2KHZ);
	TIMER_PWMCAPTURE_INIT();
	TIMER_PWMRUN(Timer0,200);
	while(1)
	{
		TIMER_PWMCATCH(&duty_cycle,&FRQuacnY);

		TIMER_OCR1A=duty_cycle;

		TIMER_OCR1B=FRQuacnY;
	}




}
