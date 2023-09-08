/*
 * main.c
 *
 *  Created on: Nov 25, 2022
 *      Author: Almodather
 */


#include <avr/delay.h>
#include "../STD_LIB/STD_Types.h"
#include "../STD_LIB/util.h"
#include "../MCAL/DIO/DIO_interface.h"
#include  "LCD_INTERFACE.h"
#include  "LCD_CONFIG.h"

int main  ()
{


	LCD_void_Init();
	u8 x[6]={'k','a','r','i','m','\0'};
	u8 y[2]={' ','\0'};
	LCD_void_Write_Cmd(Clear_LCD);
	///LCD_void_Write_Num(123456,0,0);
	while(1)
	{
		for (u8 var=0;var<6;var++)
		{	u8 other;
			y[0]=x[var];
			if(var%2==0)
			{
				other=1;
			}
			else
			{
				other=0;
			}

			_delay_ms(30);

			LCD_void_Write_String(y,var,other);
			_delay_ms(30);

		}
		LCD_void_Write_Cmd(Clear_LCD);
		for (u8 var=0;var<6;var++)
				{	u8 other;
					y[0]=x[var];
					if(var%2==0)
					{
						other=0;
					}
					else
					{
						other=1;
					}

					_delay_ms(30);

					LCD_void_Write_String(y,var,other);
					_delay_ms(30);

				}
		LCD_void_Write_Cmd(Clear_LCD);
	}
	return 0;

}
