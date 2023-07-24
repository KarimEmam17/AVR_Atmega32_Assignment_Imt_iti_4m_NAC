/*
 * main.c
 *
 *  Created on: Dec 2, 2022
 *      Author: Almodather
 */

#include<stdio.h>
#include <avr/delay.h>
#include "../STD_LIB/STD_Types.h"
#include "../STD_LIB/util.h"
#include "../MCAL/DIO/DIO_interface.h"
void main()
{
	 DIO_u8set_pin_dir(GROUP_A,DIO_u8_PIN_0,DIO_u8_OUTPUT);
	while(1)
	{
		DIO_u8set_pin_value(GROUP_A,DIO_u8_PIN_0,DIO_u8_HIGH	);
		_delay_ms(1000);
		DIO_u8set_pin_value(GROUP_A,DIO_u8_PIN_0,DIO_u8_LOW	);
		_delay_ms(1000);
	}
}
