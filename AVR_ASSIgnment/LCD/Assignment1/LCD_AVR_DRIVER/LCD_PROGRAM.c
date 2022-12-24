/*
 * LCD_PROGRAMME.c
 *
 *  Created on: Nov 25, 2022
 *      Author: Almodather
 */


//3power pins
// VSS:GND
// VDD:5VOLT
//VEE=Vo=POT:CONTRAST



// 3Control PINS
//RS:REGISTER SELECT:
// RS=0 command
// RS=1 Data

//RW: READ/WRITE
//RW=0 WRITE
//RW=1 READ
//E:Enable


//8 Data PINS

//D0--->D07

//A:ANODE 5volt
//K:CATHODE GND


#include "../STD_LIB/STD_Types.h"
#include "../STD_LIB/util.h"
#include <avr/delay.h>
#include "../MCAL/DIO/DIO_interface.h"
#include "LCD_PRIVATE.h"
#include "LCD_CONFIG.h"
#include "LCD_INTERFACE.h"

void LCD_void_Init(void)
{
	#if LCD_Selected_Mode==LCD_8Bit_Mode
	DIO_u8set_port_dir(LCD_u8_CTRL_PORT,ALL_PINS);
	DIO_u8set_port_dir(LCD_u8_DATA_PORT,ALL_PINS);


	_delay_ms(40);


	LCD_void_Write_Cmd(0b00111000);// N:1 two line   //N:0  one line
								     //F:0  5*7pixels //F:1 5*11 Pixels
	_delay_us(50);
	LCD_void_Write_Cmd(0b00001100);	//D=1 DISPLAY ON    // D:0 DISPLAY OFF
									//C:1 COURSOR ON    // c:0 COURSOR OFF
									//B:1 COURSOR BLINK	//B:0 CURSOR OFF

	_delay_us(50);
	LCD_void_Write_Cmd(0b00000001); //display clear
	_delay_ms(2);
	LCD_void_Write_Cmd(0x06);// Entry mode. (No display shift , AC increase)
	_delay_ms(1);

	#elif LCD_Selected_Mode==LCD_4Bit_Mode
		#if LCD_3PIN_IN_CTRL_PORT_IN_4PIN_MODE==LCD_FIRST_3PIN_IN_CTRL_PORT_IN_4PIN_MODE
			DIO_u8set_pin_dir(LCD_u8_CTRL_PORT,LCD_u8_DATA_PIN_0,DIO_u8_OUTPUT);
			DIO_u8set_pin_dir(LCD_u8_CTRL_PORT,LCD_u8_DATA_PIN_1,DIO_u8_OUTPUT);
			DIO_u8set_pin_dir(LCD_u8_CTRL_PORT,LCD_u8_DATA_PIN_2,DIO_u8_OUTPUT);
		#elif LCD_3PIN_IN_CTRL_PORT_IN_4PIN_MODE==LCD_LAST_3PIN_IN_CTRL_PORT_IN_4PIN_MODE
			DIO_u8set_pin_dir(LCD_u8_CTRL_PORT,LCD_u8_DATA_PIN_5,DIO_u8_OUTPUT);
			DIO_u8set_pin_dir(LCD_u8_CTRL_PORT,LCD_u8_DATA_PIN_6,DIO_u8_OUTPUT);
			DIO_u8set_pin_dir(LCD_u8_CTRL_PORT,LCD_u8_DATA_PIN_7,DIO_u8_OUTPUT);
		#endif

		#if LCD_4PIN_IN_DATA_PORT_IN_4PIN_MODE==LCD_FIRST_4PIN_IN_DATA_PORT_IN_4PIN_MODE
			DIO_u8set_pin_dir(LCD_u8_DATA_PORT,LCD_u8_DATA_PIN_0,DIO_u8_OUTPUT);
			DIO_u8set_pin_dir(LCD_u8_DATA_PORT,LCD_u8_DATA_PIN_1,DIO_u8_OUTPUT);
			DIO_u8set_pin_dir(LCD_u8_DATA_PORT,LCD_u8_DATA_PIN_2,DIO_u8_OUTPUT);
			DIO_u8set_pin_dir(LCD_u8_DATA_PORT,LCD_u8_DATA_PIN_3,DIO_u8_OUTPUT);
		#elif LCD_4PIN_IN_DATA_PORT_IN_4PIN_MODE==LCD_LAST_4PIN_IN_DATA_PORT_IN_4PIN_MODE
			DIO_u8set_pin_dir(LCD_u8_DATA_PORT,LCD_u8_DATA_PIN_4,DIO_u8_OUTPUT);
			DIO_u8set_pin_dir(LCD_u8_DATA_PORT,LCD_u8_DATA_PIN_5,DIO_u8_OUTPUT);
			DIO_u8set_pin_dir(LCD_u8_DATA_PORT,LCD_u8_DATA_PIN_6,DIO_u8_OUTPUT);
			DIO_u8set_pin_dir(LCD_u8_DATA_PORT,LCD_u8_DATA_PIN_7,DIO_u8_OUTPUT);
		#endif

		_delay_ms(40);

		LCD_void_Write_Cmd(0x02);
		LCD_void_Write_Cmd(0x28);// N:1 two line   //N:0  one line
									     //F:0  5*7pixels //F:1 5*11 Pixels
		_delay_us(50);
		LCD_void_Write_Cmd(0x0E);	//D=1 DISPLAY ON    // D:0 DISPLAY OFF
										//C:1 COURSOR ON    // c:0 COURSOR OFF
										//B:1 COURSOR BLINK	//B:0 CURSOR OFF

		_delay_us(50);
		LCD_void_Write_Cmd(0b00000001); //display clear
		_delay_ms(2);
		LCD_void_Write_Cmd(0x80);// Entry mode. (No display shift , AC increase)
		_delay_ms(1);


#endif
}

void LCD_void_Write_Cmd(u8 Copy_u8Cmd)
{
	u8 LOC_Copy_u8Cmd;
	#if LCD_Selected_Mode==LCD_8Bit_Mode
	DIO_u8set_pin_value(LCD_u8_CTRL_PORT,LCD_u8_RS_PIN,LCD_u8_RS_CMD);
	LCD_void_Write(Copy_u8Cmd);
	#elif LCD_Selected_Mode==LCD_4Bit_Mode
	LOC_Copy_u8Cmd=(Copy_u8Cmd & 0b11110000);
	DIO_u8set_pin_value(LCD_u8_CTRL_PORT,LCD_u8_RS_PIN,LCD_u8_RS_CMD);
	LCD_void_Write(LOC_Copy_u8Cmd);
	LOC_Copy_u8Cmd=((Copy_u8Cmd<<4) & 0b11110000);
	DIO_u8set_pin_value(LCD_u8_CTRL_PORT,LCD_u8_RS_PIN,LCD_u8_RS_CMD);
	LCD_void_Write(LOC_Copy_u8Cmd);
	#endif


}
void LCD_void_Write_Data(u8 Copy_u8Data)
{
	u8 LOC_Copy_u8Data;
	#if LCD_Selected_Mode==LCD_8Bit_Mode
	DIO_u8set_pin_value(LCD_u8_CTRL_PORT,LCD_u8_RS_PIN,LCD_u8_RS_DATA);
	LCD_void_Write(Copy_u8Data);
	#elif  LCD_Selected_Mode==LCD_4Bit_Mode
	LOC_Copy_u8Data=(Copy_u8Data & 0b11110000);
	DIO_u8set_pin_value(LCD_u8_CTRL_PORT,LCD_u8_RS_PIN,LCD_u8_RS_DATA);
	LCD_void_Write(LOC_Copy_u8Data);
	LOC_Copy_u8Data=((Copy_u8Data<<4) & 0b11110000);
	DIO_u8set_pin_value(LCD_u8_CTRL_PORT,LCD_u8_RS_PIN,LCD_u8_RS_DATA);
	LCD_void_Write(LOC_Copy_u8Data);
	#endif

}

 void LCD_void_Write(u8 Copy_u8val)
{
	DIO_u8set_pin_value(LCD_u8_CTRL_PORT,LCD_u8_RW_PIN,LCD_u8_RW_WRITE);
	//DIO_u8set_port_value(LCD_u8_DATA_PORT,Copy_u8val);
	#if LCD_Selected_Mode==LCD_8Bit_Mode
		DIO_u8set_pin_value(LCD_u8_DATA_PORT,LCD_u8_DATA_PIN_0,get_bit(Copy_u8val,0));
		DIO_u8set_pin_value(LCD_u8_DATA_PORT,LCD_u8_DATA_PIN_1,get_bit(Copy_u8val,1));
		DIO_u8set_pin_value(LCD_u8_DATA_PORT,LCD_u8_DATA_PIN_2,get_bit(Copy_u8val,2));
		DIO_u8set_pin_value(LCD_u8_DATA_PORT,LCD_u8_DATA_PIN_3,get_bit(Copy_u8val,3));
		DIO_u8set_pin_value(LCD_u8_DATA_PORT,LCD_u8_DATA_PIN_4,get_bit(Copy_u8val,4));
		DIO_u8set_pin_value(LCD_u8_DATA_PORT,LCD_u8_DATA_PIN_5,get_bit(Copy_u8val,5));
		DIO_u8set_pin_value(LCD_u8_DATA_PORT,LCD_u8_DATA_PIN_6,get_bit(Copy_u8val,6));
		DIO_u8set_pin_value(LCD_u8_DATA_PORT,LCD_u8_DATA_PIN_7,get_bit(Copy_u8val,7));


		DIO_u8set_pin_value(LCD_u8_CTRL_PORT,LCD_u8_ENABLE_PIN,DIO_u8_HIGH);
		_delay_ms(2);
		DIO_u8set_pin_value(LCD_u8_CTRL_PORT,LCD_u8_ENABLE_PIN,DIO_u8_LOW);
		_delay_ms(2);
	#elif LCD_Selected_Mode==LCD_4Bit_Mode
		#if   LCD_4PIN_IN_DATA_PORT_IN_4PIN_MODE==LCD_FIRST_4PIN_IN_DATA_PORT_IN_4PIN_MODE
			DIO_u8set_pin_value(LCD_u8_DATA_PORT,LCD_u8_DATA_PIN_0,get_bit(Copy_u8val,4));
			DIO_u8set_pin_value(LCD_u8_DATA_PORT,LCD_u8_DATA_PIN_1,get_bit(Copy_u8val,5));
			DIO_u8set_pin_value(LCD_u8_DATA_PORT,LCD_u8_DATA_PIN_2,get_bit(Copy_u8val,6));
			DIO_u8set_pin_value(LCD_u8_DATA_PORT,LCD_u8_DATA_PIN_3,get_bit(Copy_u8val,7));
			DIO_u8set_pin_value(LCD_u8_CTRL_PORT,LCD_u8_ENABLE_PIN,DIO_u8_HIGH);
			_delay_ms(2);
			DIO_u8set_pin_value(LCD_u8_CTRL_PORT,LCD_u8_ENABLE_PIN,DIO_u8_LOW);
			_delay_ms(2);

		#elif LCD_4PIN_IN_DATA_PORT_IN_4PIN_MODE==LCD_LAST_4PIN_IN_DATA_PORT_IN_4PIN_MODE
			DIO_u8set_pin_value(LCD_u8_DATA_PORT,LCD_u8_DATA_PIN_4,get_bit(Copy_u8val,4));
			DIO_u8set_pin_value(LCD_u8_DATA_PORT,LCD_u8_DATA_PIN_5,get_bit(Copy_u8val,5));
			DIO_u8set_pin_value(LCD_u8_DATA_PORT,LCD_u8_DATA_PIN_6,get_bit(Copy_u8val,6));
			DIO_u8set_pin_value(LCD_u8_DATA_PORT,LCD_u8_DATA_PIN_7,get_bit(Copy_u8val,7));
			DIO_u8set_pin_value(LCD_u8_CTRL_PORT,LCD_u8_ENABLE_PIN,DIO_u8_HIGH);
			_delay_ms(2);
			DIO_u8set_pin_value(LCD_u8_CTRL_PORT,LCD_u8_ENABLE_PIN,DIO_u8_LOW);
			_delay_ms(2);

		#endif
	#endif

}


void LCD_void_set_DDRAM_ADD(u8 Copy_u8DDRAM_ADD)
{
	LCD_void_Write_Cmd( LCD_u8_DDRAM_ADD_MASK|Copy_u8DDRAM_ADD);// set the position to display
}

void LCD_void_Write_String(u8 *Ptr_u8string,u8 Copy_u8x_Pos,u8 Copy_u8y_Pos)
{
	u8 LOC_DDRAM_ADD= Copy_u8x_Pos+(Copy_u8y_Pos*LCD_u8_DDRAM_ADD_LINE_MASK);
	LCD_void_set_DDRAM_ADD(LOC_DDRAM_ADD);
	while(*Ptr_u8string !='\0')
	{
		if(LOC_DDRAM_ADD==16)
		{
			LOC_DDRAM_ADD=64;
			LCD_void_set_DDRAM_ADD(LOC_DDRAM_ADD);
		}
		else if(LOC_DDRAM_ADD==80)
		{
			LOC_DDRAM_ADD=0;
			LCD_void_set_DDRAM_ADD(LOC_DDRAM_ADD);
		}
		LCD_void_Write_Data(*Ptr_u8string);
		Ptr_u8string++;
		LOC_DDRAM_ADD++;
	}
}

void LCD_void_set_CGRAM_ADD(u8 Copy_u8CGRAM_ADD)
{
	LCD_void_Write_Cmd( LCD_u8_CGRAM_ADD_MASK|Copy_u8CGRAM_ADD);
}

u32  LCD_u8_Count_Num_Digits(u32 Copy_u32_Num_VAL)
{
	u8 LOC_u8_Last_Digit;
	u8 LOC_u16_Counter=0;
	while(Copy_u32_Num_VAL != 0)  //how to get all digits of a number
	{
		LOC_u8_Last_Digit = Copy_u32_Num_VAL % 10;   //Last digit
		LOC_u16_Counter++;
		Copy_u32_Num_VAL = Copy_u32_Num_VAL /10;
	}
	return LOC_u16_Counter;
}

void LCD_void_Write_Spaces(u32 Copy_u32_Num_Spaces)
{
	u32 LOC_u32_Num_Spaces;
	for(LOC_u32_Num_Spaces=0; LOC_u32_Num_Spaces<=Copy_u32_Num_Spaces ;LOC_u32_Num_Spaces++)
	{
		LCD_void_Write_Data(' ');
	}
}

static void swap(u8 *PTR_u8Num1,u8 *PTR_u8Num2){
	u8 LOC_u8_Temp = *PTR_u8Num1 ;
	*PTR_u8Num1 = *PTR_u8Num2 ;
	*PTR_u8Num2 = LOC_u8_Temp ;
}

static void reverse(u8 *PTR_u8Arr,u8 Copy_u8Length){
	u8 LOC_u8Start = 0 ;
	u8 LOC_u8End   = Copy_u8Length-1;
	while(LOC_u8Start<LOC_u8End){
		swap(&PTR_u8Arr[LOC_u8Start],&PTR_u8Arr[LOC_u8End]);
		LOC_u8Start++;
		LOC_u8End--;
	}

}

void LCD_void_Write_Num(u32 Copy_u32Num,u8 Copy_u8x_Pos,u8 Copy_u8y_Pos)
{
	u8 LOC_u8Rem ;
	u8 LOC_u8ArrIndex = 0;
	u8 ARR_u8Str[11];
	if(Copy_u32Num ==0)
	{
		ARR_u8Str[LOC_u8ArrIndex] = '0';
		LOC_u8ArrIndex++;
	}
	while(Copy_u32Num !=0){
		LOC_u8Rem = Copy_u32Num%10 ;
		ARR_u8Str[LOC_u8ArrIndex] = LOC_u8Rem + '0' ;
		LOC_u8ArrIndex++;
		Copy_u32Num = Copy_u32Num/10;

	}

	ARR_u8Str[LOC_u8ArrIndex] = '\0';
	reverse(ARR_u8Str,LOC_u8ArrIndex);
	LCD_void_Write_String(ARR_u8Str,Copy_u8x_Pos,Copy_u8y_Pos);
}










