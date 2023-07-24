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
#include "SPI_INTERFACE.h"
#define F_CPU 	8000000
void main ()
{

	u8 Counter=0;
	u8 Recv_data;
	DIO_u8set_pin_dir(GROUP_B,DIO_u8_PIN_4,DIO_u8_OUTPUT);
	DIO_u8set_pin_dir(GROUP_B,DIO_u8_PIN_5,DIO_u8_OUTPUT);
	DIO_u8set_pin_dir(GROUP_B,DIO_u8_PIN_7,DIO_u8_OUTPUT);
	DIO_u8set_pin_dir(GROUP_B,DIO_u8_PIN_6,DIO_u8_INPUT);


	SPI_init(Master_TYPE,MSB_FIRST,SAMPLE_R_SETUP_F,SPI_PRESCALER_8);


	while (1)
	{

		SPI_MasterSendRecv(Counter,&Recv_data);
		_delay_ms(1000);
		Counter++;

	}
return;
}
