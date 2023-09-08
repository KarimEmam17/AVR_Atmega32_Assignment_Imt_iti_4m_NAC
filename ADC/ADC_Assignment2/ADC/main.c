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
#include  "ADC_INTERFACE.h"
#include  "LCD_INTERFACE.h"
#include  "LCD_CONFIG.h"
//  this is  the lm35 example
void main (void)
{

	ADC_voidInit();
DIO_u8set_pin_dir(GROUP_C,DIO_u8_PIN_0,DIO_u8_OUTPUT);
DIO_u8set_pin_dir(GROUP_C,DIO_u8_PIN_1,DIO_u8_OUTPUT);
DIO_u8set_pin_dir(GROUP_C,DIO_u8_PIN_2,DIO_u8_OUTPUT);
u16 value_of_ADC_Conversion;
u16 LM35_u16_TEMP_Value;
u16 LM35_u16_mV_value;
while(1)
{
	ADC_SingleConversion (&value_of_ADC_Conversion);

	LM35_u16_mV_value=(5000*value_of_ADC_Conversion)/1024;
	LM35_u16_TEMP_Value=LM35_u16_mV_value/10;
	if(LM35_u16_TEMP_Value<25)
	{
		DIO_u8set_pin_value(GROUP_C,DIO_u8_PIN_0,DIO_u8_HIGH);
		DIO_u8set_pin_value(GROUP_C,DIO_u8_PIN_1,DIO_u8_LOW);
		DIO_u8set_pin_value(GROUP_C,DIO_u8_PIN_2,DIO_u8_LOW);

	}
	else if(LM35_u16_TEMP_Value<35)
	{
		DIO_u8set_pin_value(GROUP_C,DIO_u8_PIN_0,DIO_u8_LOW);
		DIO_u8set_pin_value(GROUP_C,DIO_u8_PIN_1,DIO_u8_HIGH);
		DIO_u8set_pin_value(GROUP_C,DIO_u8_PIN_2,DIO_u8_LOW);
	}
	else if(LM35_u16_TEMP_Value<55)
	{
			DIO_u8set_pin_value(GROUP_C,DIO_u8_PIN_0,DIO_u8_LOW);
			DIO_u8set_pin_value(GROUP_C,DIO_u8_PIN_1,DIO_u8_HIGH);
			DIO_u8set_pin_value(GROUP_C,DIO_u8_PIN_2,DIO_u8_HIGH);
	}


}


}
