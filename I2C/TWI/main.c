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
#include "TWI_INTERFACE.h"
#define F_CPU 	8000000
int main()
{

	//for  reciveing
	TWI_INIT();
	u8 x;
	TWI_START(0x0A,Slave_Read);
	_delay_ms(15);
	TWI_MasterRecive_byte_With_NACK(&x);
	_delay_ms(15);
	TWI_MasterRecive_byte_With_ACK(&x);
	_delay_ms(10);
	TWI_MasterRecive_byte_With_ACK(&x);
	_delay_ms(10);
	TWI_MasterRecive_byte_With_ACK(&x);
	_delay_ms(10);
	TWI_MasterRecive_byte_With_ACK(&x);
	_delay_ms(10);
	TWI_MasterRecive_byte_With_ACK(&x);


	TWI_Stop();



/*
 * for sending one  time
	TWI_INIT();
	TWI_START(0x0A,Slave_Write);
	TWI_MasterSend_byte(0x50);
	TWI_MasterSend_byte(0x20);
	TWI_MasterSend_byte(0x30);
	TWI_MasterSend_byte(0x10);
	TWI_MasterSend_byte(0x15);
	TWI_Stop();
	*/
	while (1)
	{



	}
return 0;
}
