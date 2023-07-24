/*
 * main.c
 *
 *  Created on: Feb 6, 2023
 *      Author: Almodather
 */

#include <avr/delay.h>
#include "../STD_LIB/STD_Types.h"
#include "../STD_LIB/util.h"
#include "../MCAL/DIO/DIO_Private.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "UART_INTERFACE.h"
#define F_CPU 	8000000
void main ()
{
	DIO_u8set_pin_dir(GROUP_D,DIO_u8_PIN_0,DIO_u8_INPUT);
	DIO_u8set_pin_dir(GROUP_D,DIO_u8_PIN_1,DIO_u8_OUTPUT);
	DIO_u8set_pin_dir(GROUP_A,DIO_u8_PIN_0,DIO_u8_OUTPUT);
	UART_INIT(UART_9600_BPS);
	u8 value ='S';
	while(1)
	{
		UART_RECEVBYTE(&value);
		if (value == 'F')
		{
			DIO_u8set_pin_value(GROUP_A,DIO_u8_PIN_0,DIO_u8_HIGH);
		}
		_delay_ms(1000);
		DIO_u8set_pin_value(GROUP_A,DIO_u8_PIN_0,DIO_u8_LOW);
	}

}
