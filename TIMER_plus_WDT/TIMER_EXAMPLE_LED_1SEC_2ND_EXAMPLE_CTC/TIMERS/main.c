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
	//this is example shows  that  how to  calculate 1 seconde on LED by  ctc
	DIO_u8set_pin_dir(GROUP_A,DIO_u8_PIN_0,DIO_u8_OUTPUT);
	DIO_u8set_pin_value(GROUP_A,DIO_u8_PIN_0,DIO_u8_HIGH);
	u32 num_CM=0;
	TIMER_OCR0=125;//-------> this mean that 1ms when  the counter reaches 125
	TIMER_TCCR0=0x0B;//64 prescalar and ovf AND CTC MODE
while(1)
{
	num_CM=0;

	while(num_CM<1000)
	{
		while(get_bit(TIMER_TIFR,1)==0);// compare match  flag
		set_bit(TIMER_TIFR,1);          //clear the flag
		num_CM++;
	}

	toggle_bit(DIO_U8_PORTA,0);

}




}
