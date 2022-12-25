/*
 * main.c
 *
 *  Created on: Nov 26, 2022
 *      Author: Almodather
 */

#include <avr/delay.h>
#include "../STD_LIB/STD_Types.h"
#include "../STD_LIB/util.h"
//#include "../MCAL/DIO/DIO_interface.h"

#include "../STD_LIB/STD_Types.h"
#include "../STD_LIB/util.h"
#include "keypad_interface.h"
#include "../MCAL/DIO/DIO_interface.h"
#include  "LCD_INTERFACE.h"
#include  "LCD_CONFIG.h"
int main()
{

	u8 arr[KPD_u8_KEYS_NUM];
	KPD_void_Init();
	LCD_void_Init();
	//DIO_u8set_pin_dir(GROUP_B,DIO_u8_PIN_0,DIO_u8_HIGH);//LED
	f32 LOC_U32First_num;
	f32 LOC_U32Second_num;
	u8 LOC_U8operation;
	u8 flag=0;
	u8 posx,posy;
	while(1)
	{
		/*

		 KPD_void_Get_Status(arr);
		if(arr[0]==0)
		{
			DIO_u8set_pin_value(GROUP_B,DIO_u8_PIN_0,DIO_u8_HIGH);
		}
		else{
			DIO_u8set_pin_value(GROUP_B,DIO_u8_PIN_0,DIO_u8_LOW);
		}*/

		KPD_void_Get_Status(arr);
		if(arr[0]==KPD_u8_KEY_PRESSED)
		{
			LCD_void_Write_Cmd(Clear_LCD);
			LOC_U32First_num=0;
			LOC_U32Second_num=0;
			LOC_U8operation='=';
			posx=0;
			posy=0;
			flag=0;
		}
		if(arr[1]==KPD_u8_KEY_PRESSED)
		{
			LCD_void_Write_Cmd(Clear_LCD);
			if ((LOC_U8operation== '+') ||(LOC_U8operation== '-')||(LOC_U8operation== '*')|| (LOC_U8operation== '/') )
			{
				LOC_U32Second_num=(LOC_U32Second_num*10)+0;
				LCD_void_Wirte_Float_Num(LOC_U32Second_num);
			}
			else if(LOC_U8operation=='=')
			{
				LOC_U32First_num=(LOC_U32First_num*10)+0;
				LCD_void_Wirte_Float_Num(LOC_U32First_num);
			}
		}
		if(arr[2]==KPD_u8_KEY_PRESSED)
		{
			LCD_void_Write_Cmd(Clear_LCD);
			if(LOC_U8operation== '+')
			{
				LOC_U32First_num=LOC_U32First_num+LOC_U32Second_num;
				LCD_void_Wirte_Float_Num(LOC_U32First_num);
			}
			else if(LOC_U8operation== '-')
			{
				LOC_U32First_num=LOC_U32First_num-LOC_U32Second_num;
				LCD_void_Wirte_Float_Num(LOC_U32First_num);
			}
			else if(LOC_U8operation== '*')
			{
				LOC_U32First_num=LOC_U32First_num*LOC_U32Second_num;
				LCD_void_Wirte_Float_Num(LOC_U32First_num);
			}
			else if(LOC_U8operation== '/')
			{
				LOC_U32First_num=LOC_U32First_num/LOC_U32Second_num;
				LCD_void_Wirte_Float_Num(LOC_U32First_num);
			}
			LOC_U8operation='=';
			LOC_U32Second_num=0;
		}
		if(arr[3]==KPD_u8_KEY_PRESSED)
		{
			LOC_U8operation='+';
		}
		if(arr[4]==KPD_u8_KEY_PRESSED)
		{
			LCD_void_Write_Cmd(Clear_LCD);
			if ((LOC_U8operation== '+') ||(LOC_U8operation== '-')||(LOC_U8operation== '*')|| (LOC_U8operation== '/') )
			{
				LOC_U32Second_num=(LOC_U32Second_num*10)+1;
				LCD_void_Wirte_Float_Num(LOC_U32Second_num);
			}
			else if(LOC_U8operation=='=')
			{
				LOC_U32First_num=(LOC_U32First_num*10)+1;
				LCD_void_Wirte_Float_Num(LOC_U32First_num);
			}
		}
		if(arr[5]==KPD_u8_KEY_PRESSED)
		{
			LCD_void_Write_Cmd(Clear_LCD);
			if ((LOC_U8operation== '+') ||(LOC_U8operation== '-')||(LOC_U8operation== '*')|| (LOC_U8operation== '/') )
			{
				LOC_U32Second_num=(LOC_U32Second_num*10)+2;
				LCD_void_Wirte_Float_Num(LOC_U32Second_num);
			}
			else if(LOC_U8operation=='=')
			{
				LOC_U32First_num=(LOC_U32First_num*10)+2;
				LCD_void_Wirte_Float_Num(LOC_U32First_num);
			}
		}

		if(arr[6]==KPD_u8_KEY_PRESSED)
		{
			LCD_void_Write_Cmd(Clear_LCD);
			if ((LOC_U8operation== '+') ||(LOC_U8operation== '-')||(LOC_U8operation== '*')|| (LOC_U8operation== '/') )
			{
				LOC_U32Second_num=(LOC_U32Second_num*10)+3;
				LCD_void_Wirte_Float_Num(LOC_U32Second_num);
			}
			else if(LOC_U8operation=='=')
			{
				LOC_U32First_num=(LOC_U32First_num*10)+3;
				LCD_void_Wirte_Float_Num(LOC_U32First_num);
			}
		}
		if(arr[7]==KPD_u8_KEY_PRESSED)
		{
			LOC_U8operation='-';
		}
		if(arr[8]==KPD_u8_KEY_PRESSED)
		{
			LCD_void_Write_Cmd(Clear_LCD);
			if ((LOC_U8operation== '+') ||(LOC_U8operation== '-')||(LOC_U8operation== '*')|| (LOC_U8operation== '/') )
			{
				LOC_U32Second_num=(LOC_U32Second_num*10)+4;
				LCD_void_Wirte_Float_Num(LOC_U32Second_num);
			}
			else if(LOC_U8operation=='=')
			{
				LOC_U32First_num=(LOC_U32First_num*10)+4;
				LCD_void_Wirte_Float_Num(LOC_U32First_num);
			}
		}
		if(arr[9]==KPD_u8_KEY_PRESSED)
		{
			LCD_void_Write_Cmd(Clear_LCD);
			if ((LOC_U8operation== '+') ||(LOC_U8operation== '-')||(LOC_U8operation== '*')|| (LOC_U8operation== '/') )
			{
				LOC_U32Second_num=(LOC_U32Second_num*10)+5;
				LCD_void_Wirte_Float_Num(LOC_U32Second_num);
			}
			else if(LOC_U8operation=='=')
			{
				LOC_U32First_num=(LOC_U32First_num*10)+5;
				LCD_void_Wirte_Float_Num(LOC_U32First_num);
			}
		}
		if(arr[10]==KPD_u8_KEY_PRESSED)
		{
			LCD_void_Write_Cmd(Clear_LCD);
			if ((LOC_U8operation== '+') ||(LOC_U8operation== '-')||(LOC_U8operation== '*')|| (LOC_U8operation== '/') )
			{
				LOC_U32Second_num=(LOC_U32Second_num*10)+6;
				LCD_void_Wirte_Float_Num(LOC_U32Second_num);
			}
			else if(LOC_U8operation=='=')
			{
				LOC_U32First_num=(LOC_U32First_num*10)+6;
				LCD_void_Wirte_Float_Num(LOC_U32First_num);
			}
		}
		if(arr[11]==KPD_u8_KEY_PRESSED)
		{
			LOC_U8operation='*';
		}
		if(arr[12]==KPD_u8_KEY_PRESSED)
		{
			LCD_void_Write_Cmd(Clear_LCD);
			if ((LOC_U8operation== '+') ||(LOC_U8operation== '-')||(LOC_U8operation== '*')|| (LOC_U8operation== '/') )
			{
				LOC_U32Second_num=(LOC_U32Second_num*10)+7;
				LCD_void_Wirte_Float_Num(LOC_U32Second_num);
			}
			else if(LOC_U8operation=='=')
			{
				LOC_U32First_num=(LOC_U32First_num*10)+7;
				LCD_void_Wirte_Float_Num(LOC_U32First_num);
			}
		}
		if(arr[13]==KPD_u8_KEY_PRESSED)
		{
			LCD_void_Write_Cmd(Clear_LCD);
			if ((LOC_U8operation== '+') ||(LOC_U8operation== '-')||(LOC_U8operation== '*')|| (LOC_U8operation== '/') )
			{
				LOC_U32Second_num=(LOC_U32Second_num*10)+8;
				LCD_void_Wirte_Float_Num(LOC_U32Second_num);
			}
			else if(LOC_U8operation=='=')
			{
				LOC_U32First_num=(LOC_U32First_num*10)+8;
				LCD_void_Wirte_Float_Num(LOC_U32First_num);
			}
		}
		if(arr[14]==KPD_u8_KEY_PRESSED)
		{
			LCD_void_Write_Cmd(Clear_LCD);
			if ((LOC_U8operation== '+') ||(LOC_U8operation== '-')||(LOC_U8operation== '*')|| (LOC_U8operation== '/') )
			{
				LOC_U32Second_num=(LOC_U32Second_num*10)+9;
				LCD_void_Wirte_Float_Num(LOC_U32Second_num);
			}
			else if(LOC_U8operation=='=')
			{
				LOC_U32First_num=(LOC_U32First_num*10)+9;
				LCD_void_Wirte_Float_Num(LOC_U32First_num);
			}
		}
		if(arr[15]==KPD_u8_KEY_PRESSED)
		{
			LOC_U8operation='/';
		}


	}

	return  0;
}
