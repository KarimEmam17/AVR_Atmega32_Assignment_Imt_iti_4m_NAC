/*
 * main.c
 *
 *  Created on: Nov 18, 2022
 *      Author: KARIM
 */


#include <util/delay.h>
#include "STD_Types.h"
#include "util.h"
#include "../MCAL/DIO/DIO_INTERFACE.h"
#define Number_0  0x3F //0b00111111
#define Number_2  0x5B //0b01011011
#define Number_1  0x06 //0b00000110
#define Number_3  0x4F
#define Number_4  0x66
#define Number_5  0x6D
#define Number_6  0x7C
#define Number_7  0x07
#define Number_8  0x7F
#define Number_9  0x6F

void main()
{

	DIO_u8set_port_dir(GROUP_C,ALL_PINS);
	DIO_u8set_port_dir(GROUP_D,ALL_PINS);
	//255=0b11111111=0xff  group  D output
	u8 arr[10]={Number_0,Number_1,Number_2,Number_3,Number_4,Number_5,Number_6,Number_7,Number_8,Number_9};
	while(1)
	{
		DIO_u8set_pin_value(GROUP_D,DIO_u8_PIN_5,DIO_u8_LOW);
		DIO_u8set_pin_value(GROUP_D,DIO_u8_PIN_3,DIO_u8_HIGH);
		for(u8 i=0;i<11;i++)
			{
				u8 ones=i%10;
				u8 tens =i/10;
				DIO_u8set_pin_value(GROUP_D,DIO_u8_PIN_1,DIO_u8_LOW);
				DIO_u8set_pin_value(GROUP_D,DIO_u8_PIN_0,DIO_u8_HIGH);
				DIO_u8set_port_value(GROUP_C,arr[ones]);
				_delay_ms(15);
				DIO_u8set_pin_value(GROUP_D,DIO_u8_PIN_0,DIO_u8_LOW);
				DIO_u8set_pin_value(GROUP_D,DIO_u8_PIN_1,DIO_u8_HIGH);
				DIO_u8set_port_value(GROUP_C,arr[tens]);
				_delay_ms(15);

			}
		DIO_u8set_pin_value(GROUP_D,DIO_u8_PIN_3,DIO_u8_LOW);
		DIO_u8set_pin_value(GROUP_D,DIO_u8_PIN_4,DIO_u8_HIGH);
		for(u8 i=0;i<4;i++)
			{
						u8 ones=i%10;
						u8 tens =i/10;
						DIO_u8set_pin_value(GROUP_D,DIO_u8_PIN_1,DIO_u8_LOW);
						DIO_u8set_pin_value(GROUP_D,DIO_u8_PIN_0,DIO_u8_HIGH);
						DIO_u8set_port_value(GROUP_C,arr[ones]);
						_delay_ms(15);
						DIO_u8set_pin_value(GROUP_D,DIO_u8_PIN_0,DIO_u8_LOW);
						DIO_u8set_pin_value(GROUP_D,DIO_u8_PIN_1,DIO_u8_HIGH);
						DIO_u8set_port_value(GROUP_C,arr[tens]);
						_delay_ms(15);

			}
		DIO_u8set_pin_value(GROUP_D,DIO_u8_PIN_4,DIO_u8_LOW);
		DIO_u8set_pin_value(GROUP_D,DIO_u8_PIN_5,DIO_u8_HIGH);
		for(u8 i=0;i<11;i++)
			{
						u8 ones=i%10;
						u8 tens =i/10;
						DIO_u8set_pin_value(GROUP_D,DIO_u8_PIN_1,DIO_u8_LOW);
						DIO_u8set_pin_value(GROUP_D,DIO_u8_PIN_0,DIO_u8_HIGH);
						DIO_u8set_port_value(GROUP_C,arr[ones]);
						_delay_ms(15);
						DIO_u8set_pin_value(GROUP_D,DIO_u8_PIN_0,DIO_u8_LOW);
						DIO_u8set_pin_value(GROUP_D,DIO_u8_PIN_1,DIO_u8_HIGH);
						DIO_u8set_port_value(GROUP_C,arr[tens]);
						_delay_ms(15);

			}



	}
}
