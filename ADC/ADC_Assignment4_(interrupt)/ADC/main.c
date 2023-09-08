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

volatile f32 result=0;
extern u32 flag;
void main (void)
{



f32 analog;

	ADC_voidInit_Interrupt();
	LCD_void_Init();
	// inti. ADC via interrupt mode the converted analog value in digital value
	ADC_u16Read_Interput();

	while(1)
	{

		if (flag==1){
		//	DIO_u8Set_Pin_value(GROUP_A,DIO_u8_PIN_1 ,DIO_u8_HIGH);
		//displaying on LCD 16x2 the digital value
		LCD_void_Wirte_Float_Num(result);


		LCD_void_Write_Spaces(16);

		//calculating the analog value through this math equation
		analog= (result*5000)/1024.0;

		//displaying on LCD 16x2 the analog value
		LCD_void_Wirte_Float_Num(analog);

		// waiting to see the result displayed on the LCD
		_delay_ms(500);
		//display clear the LCD to enable new value to be written
		LCD_void_Write_Cmd(Clear_LCD);
		flag=0;
		}

}

}
