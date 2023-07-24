/*
 * main.c
 *
 *  Created on: Nov 20, 2022
 *      Author: Almodather
 */

#include <avr/io.h>
#include <avr/delay.h>
#include "STD_TYPES.h"
#include "Util.h"
#include "../MCAL/DIO/DIO_INTERFACE.h"
#include  "LCD_INTERFACE.h"
#include  "LCD_CONFIG.h"
void main  ()
{
	u8 status1,status2;
	u8 *status_clockwise=&status1,*status_anticlockwise=&status2;

	DIO_u8set_pin_dir(GROUP_C,DIO_u8_PIN_0,DIO_u8_OUTPUT);
	DIO_u8set_pin_dir(GROUP_C,DIO_u8_PIN_1,DIO_u8_OUTPUT);
	DIO_u8set_pin_dir(GROUP_C,DIO_u8_PIN_2,DIO_u8_OUTPUT);
	DIO_u8set_pin_value(GROUP_C,DIO_u8_PIN_2,DIO_u8_HIGH);//enable the motor

	DIO_u8set_pin_dir(GROUP_C,DIO_u8_PIN_7,DIO_u8_INPUT);//pull  push  button  pull up  res
	DIO_u8set_pin_value(GROUP_C,DIO_u8_PIN_7,DIO_u8_HIGH);//pull  push  button  clock wise


	DIO_u8set_pin_dir(GROUP_D,DIO_u8_PIN_0,DIO_u8_INPUT);//pull  push  button pull up  res
	DIO_u8set_pin_value(GROUP_D,DIO_u8_PIN_0,DIO_u8_HIGH);//pull  push  button  anticlockwise
	LCD_void_Init();
	LCD_void_Write_Cmd(Clear_LCD);
	u8 status_LCD[]="clockwise";
	u8 status_LCD_2[]="anticlockwise";
	while(1)
	{
		LCD_void_Write_Cmd(Clear_LCD);
		DIO_u8get_pin_value(GROUP_C,DIO_u8_PIN_7,status_clockwise);
		DIO_u8get_pin_value(GROUP_D,DIO_u8_PIN_0,status_anticlockwise);
		if ((status1==0) &&(status2!=0))//clockwise
		{
			while((status1==0) &&(status2!=0))
			{
			DIO_u8set_pin_value(GROUP_C,DIO_u8_PIN_0,DIO_u8_HIGH);
			DIO_u8set_pin_value(GROUP_C,DIO_u8_PIN_1,DIO_u8_LOW);
			LCD_void_Write_String(status_LCD,0,0);
			DIO_u8get_pin_value(GROUP_C,DIO_u8_PIN_7,status_clockwise);
			DIO_u8get_pin_value(GROUP_D,DIO_u8_PIN_0,status_anticlockwise);
			}
		}
		else if ((status1!=0) &&(status2==0))//anticlockwise
			{
			while((status1!=0) &&(status2==0))
				{
				DIO_u8set_pin_value(GROUP_C,DIO_u8_PIN_0,DIO_u8_LOW);
				DIO_u8set_pin_value(GROUP_C,DIO_u8_PIN_1,DIO_u8_HIGH);
				LCD_void_Write_String(status_LCD_2,0,0);
				DIO_u8get_pin_value(GROUP_C,DIO_u8_PIN_7,status_clockwise);
				DIO_u8get_pin_value(GROUP_D,DIO_u8_PIN_0,status_anticlockwise);
				}
			}
		else
			{
				DIO_u8set_pin_value(GROUP_C,DIO_u8_PIN_0,DIO_u8_LOW);
				DIO_u8set_pin_value(GROUP_C,DIO_u8_PIN_1,DIO_u8_LOW);
			}

	}

}
