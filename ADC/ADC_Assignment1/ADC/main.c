/*
 * main.c
 *
 *  Created on: Dec 9, 2022
 *      Author: Almodather
 */

#include <avr/delay.h>
#include "../STD_LIB/STD_Types.h"
#include "../STD_LIB/util.h"
#include "../MCAL/DIO/DIO_interface.h"
#include  "LCD_INTERFACE.h"
#include  "LCD_CONFIG.h"
void main (void)
{
ADC_voidInit();
DIO_u8set_pin_dir(GROUP_C,DIO_u8_PIN_0,DIO_u8_OUTPUT);
DIO_u8set_pin_dir(GROUP_C,DIO_u8_PIN_1,DIO_u8_OUTPUT);
DIO_u8set_pin_dir(GROUP_C,DIO_u8_PIN_2,DIO_u8_OUTPUT);
u16 value_of_ADC_Conversion;
while(1)
{
	ADC_SingleConversion (&value_of_ADC_Conversion);

	if(value_of_ADC_Conversion>=0 && value_of_ADC_Conversion<=255)
	{
		DIO_u8set_pin_value(GROUP_C,DIO_u8_PIN_0,DIO_u8_HIGH);
		DIO_u8set_pin_value(GROUP_C,DIO_u8_PIN_1,DIO_u8_LOW);
		DIO_u8set_pin_value(GROUP_C,DIO_u8_PIN_2,DIO_u8_LOW);

	}
	else if(value_of_ADC_Conversion>=256 && value_of_ADC_Conversion<=700)
	{
		DIO_u8set_pin_value(GROUP_C,DIO_u8_PIN_0,DIO_u8_LOW);
		DIO_u8set_pin_value(GROUP_C,DIO_u8_PIN_1,DIO_u8_HIGH);
		DIO_u8set_pin_value(GROUP_C,DIO_u8_PIN_2,DIO_u8_LOW);
	}
	else if(value_of_ADC_Conversion>=701 && value_of_ADC_Conversion<=1023)
	{
			DIO_u8set_pin_value(GROUP_C,DIO_u8_PIN_0,DIO_u8_LOW);
			DIO_u8set_pin_value(GROUP_C,DIO_u8_PIN_1,DIO_u8_LOW);
			DIO_u8set_pin_value(GROUP_C,DIO_u8_PIN_2,DIO_u8_HIGH);
	}


}


}
