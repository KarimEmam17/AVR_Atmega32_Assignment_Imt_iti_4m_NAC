/*
 * main.c
 *
 *  Created on: Nov 19, 2022
 *      Author: Almodather
 */
#include <stdio.h>
#include <avr/io.h>
#include <avr/delay.h>
#include "STD_TYPES.h"
#include "Util.h"
void main ()
{
	DDRA=255; //all  the  GA is output ob11111111
	//PORTA=255; //all  the GA is HIGH
	DDRC=0;
	while (1)
	{
		if((get_bit(PINC,0) == 0)&&(get_bit(PINC,1) == 0)&&(get_bit(PINC,2) == 0))
		{    //shifting  right
			for(u8 i=0;i<8;i++)
			{
				PORTA=clear_bit(PORTA,i);
				_delay_ms(250);

				PORTA=set_bit(PORTA,i);
			}

		}
		else if((get_bit(PINC,0) == 0)&&(get_bit(PINC,1) == 0)&&(get_bit(PINC,2) == 1))
		{    //shift  left
			for(u8 i=7;i>-1;i--)
				{
					PORTA=clear_bit(PORTA,i);
					_delay_ms(250);

					PORTA=set_bit(PORTA,i);
				}
		}
		else if((get_bit(PINC,0) == 0)&&(get_bit(PINC,1) == 1)&&(get_bit(PINC,2) == 0))
		{
			//flashing
			PORTA=0;
			_delay_ms(250);
			PORTA=255;
			_delay_ms(250);
		}
		else if((get_bit(PINC,0) == 0)&&(get_bit(PINC,1) == 1)&&(get_bit(PINC,2) == 1))

		{
			// ping_pong
			for(u8 i=7;i>-1;i--)
			{
				PORTA=set_bit(PORTA,i);
				_delay_ms(250);
				PORTA=clear_bit(PORTA,i);
				_delay_ms(250);
				PORTA=set_bit(PORTA,i);
				_delay_ms(250);
			}
			for(u8 i=0;i<8;i++)
			{
						PORTA=clear_bit(PORTA,i);
						_delay_ms(250);

						PORTA=set_bit(PORTA,i);
						_delay_ms(250);
			}



		}
		else if((get_bit(PINC,0) == 1)&&(get_bit(PINC,1) == 0)&&(get_bit(PINC,2) == 0))
		{
			// diverging
			for(u8 i=4,j=3;i<8 && j>-1;i++,j--)
			{
				PORTA=clear_bit(PORTA,i);
				PORTA=clear_bit(PORTA,j);
				_delay_ms(250);
				PORTA=set_bit(PORTA,i);
				PORTA=set_bit(PORTA,j);
			}
		}
		else if((get_bit(PINC,0) == 1)&&(get_bit(PINC,1) == 0)&&(get_bit(PINC,2) == 1))
		{
			// converging
			for(u8 i=0,j=7;i<4 && j>3;i++,j--)
				{
					PORTA=clear_bit(PORTA,i);
					PORTA=clear_bit(PORTA,j);
					_delay_ms(250);
					PORTA=set_bit(PORTA,i);
					PORTA=set_bit(PORTA,j);
				}
		}
		else if((get_bit(PINC,0) == 1)&&(get_bit(PINC,1) == 1)&&(get_bit(PINC,2) == 0))
		{
		//   converging_diverging
		for(u8 i=0,j=7;i<4 && j>3;i++,j--)
						{
							PORTA=clear_bit(PORTA,i);
							PORTA=clear_bit(PORTA,j);
							_delay_ms(250);
							PORTA=set_bit(PORTA,i);
							PORTA=set_bit(PORTA,j);
						}
		for(u8 i=4,j=3;i<8 && j>-1;i++,j--)
				{
					PORTA=clear_bit(PORTA,i);
					PORTA=clear_bit(PORTA,j);
					_delay_ms(250);
					PORTA=set_bit(PORTA,i);
					PORTA=set_bit(PORTA,j);
				}
		}
		else if((get_bit(PINC,0) == 1)&&(get_bit(PINC,1) == 1)&&(get_bit(PINC,2) == 1))
		{
			//  incremental
			for(u8 i=0;i<8;i++)
			{
				if (i==0)
				{PORTA=255;}
				PORTA=clear_bit(PORTA,i);
				_delay_ms(250);

			}
		}


	}

}
