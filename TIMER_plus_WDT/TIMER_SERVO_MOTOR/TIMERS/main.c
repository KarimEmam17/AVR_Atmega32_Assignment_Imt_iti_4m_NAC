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

#define F_CPU	8000000UL
void main()
{
/******servo  motor****************/
	DIO_u8set_pin_dir(GROUP_D,DIO_u8_PIN_5,DIO_u8_OUTPUT);
	TIMER1_CUSTOM_FREQ_PWM_INIT(20000);
	while(1)
	{
		TIMER1_CUSTOM_FREQ_PWM_RUN(TIMER_CUSTOM_CHANNEL_A,500);
		_delay_ms(1000);



		TIMER1_CUSTOM_FREQ_PWM_RUN(TIMER_CUSTOM_CHANNEL_A,1000);
		_delay_ms(1000);

		TIMER1_CUSTOM_FREQ_PWM_RUN(TIMER_CUSTOM_CHANNEL_A,750);
		_delay_ms(1000);
	}




}
