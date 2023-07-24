/*
 * UART.c
 *
 *  Created on: Feb 6, 2023
 *      Author: Almodather
 */

#include "../STD_LIB/STD_Types.h"
#include "../STD_LIB/util.h"
#include "UART_PRIVATE.h"
#include "UART_config.h"
#include "UART_interface.h"


void UART_INIT(u16 COPY_u16_baudRATE)
{
	/*********ENABLE TX AND RX PINS**************************************/
	UART_UCSRB=0x18;

	/**SELECTING ASYNCHRONOUS MODE ,NO PARITYBIT ,1-stop biT and 8 bit characer size as data********************************************************************/
	UART_UCSRC=0x86;

	/**GETTING THE LOW BYTE IN UBRRL********************************************************************/
	UART_UBRRL=(u8) COPY_u16_baudRATE;

	/**GETTING THE LOW BYTE IN UBRRL********************************************************************/
	UART_UBRRH=(u8)(COPY_u16_baudRATE>>8);


}

void UART_SENDBYTE(u8  COPY_u8_DATABYTE)
{

	/***CHECKING WETHER THE DATA REGISTER IS EMPTY OR NOT******/
	if (get_bit(UART_UCSRA,UART_UCSRA_UDRE))
	{
		/******SENDING THE DATA BYTE OR SYMBOLE **************/
		UART_UDR=COPY_u8_DATABYTE;
		/******Waiting until THE DATA is SENT or TRANSMITTED To THE TX *************/
		while(!get_bit(UART_UCSRA,UART_UCSRA_TXC));
		/******CLEARING Transmission FLAG*********/
		set_bit(UART_UCSRA,UART_UCSRA_TXC);

	}
	else
	{

	}

}

void UART_RECEVBYTE(u8 *PTR_DATABYTE)
{
	/***CHECKING WETHER THE new DATA has been received or not ******/
		if (get_bit(UART_UCSRA,UART_UCSRA_RXC))
		{
			/******receving  THE  new DATA BYTE OR SYMBOLE **************/
			*PTR_DATABYTE=UART_UDR;

		}


}

void UART_SENDSTREAM(u8  *PTR_u8_DATABYTE,u8 COPY_u8_DATA_SIZE)
{
	/****LOOPING OVER DATA SIZE ****************/
	while (COPY_u8_DATA_SIZE--)
	{
		/*****SENDING BYTE BY BYTE***************/
		UART_SENDBYTE(*PTR_u8_DATABYTE);
		/*********MOVING TO NEXT ADDRESS*******************************/
		PTR_u8_DATABYTE++;

	}
}
