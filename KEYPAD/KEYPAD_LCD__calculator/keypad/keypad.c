/*
 * keypad.c
 *
 *  Created on: Nov 26, 2022
 *      Author: Almodather
 */

#include <util/delay.h>
#include "../STD_LIB/STD_Types.h"
#include "../STD_LIB/util.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "keypad_private.h"
#include "keypad_config.h"
#include "keypad_interface.h"

u8  KPD_Au8_ROWS_Pins[KPD_u8_ROWS]={KPD_u8_ROW_0_PIN,KPD_u8_ROW_1_PIN,KPD_u8_ROW_2_PIN,KPD_u8_ROW_3_PIN};

u8  KPD_Au8_COLS_Pins[KPD_u8_COLS]={KPD_u8_COL_0_PIN,KPD_u8_COL_1_PIN,KPD_u8_COL_2_PIN,KPD_u8_COL_3_PIN};

void KPD_void_Init(void)
{
	u8 LOC_u8Col_index;
	u8 LOC_u8ROW_index;
	for( LOC_u8Col_index=0;LOC_u8Col_index<KPD_u8_COLS;LOC_u8Col_index++)
	{
		DIO_u8set_pin_dir(KDP_u8_COLS_PORT,KPD_Au8_COLS_Pins[LOC_u8Col_index],DIO_u8_OUTPUT);
	}
	for( LOC_u8ROW_index=0;LOC_u8ROW_index<KPD_u8_ROWS;LOC_u8ROW_index++)
	{
		DIO_u8set_pin_dir(KDP_u8_ROWS_PORT,KPD_Au8_ROWS_Pins[LOC_u8ROW_index],DIO_u8_INPUT);
		DIO_u8set_pin_value(KDP_u8_ROWS_PORT,KPD_Au8_ROWS_Pins[LOC_u8ROW_index],DIO_u8_HIGH);
	}
}

void KPD_void_Get_Status(u8 *Ptr_u8_KPD_Status)
{
	u8 LOC_u8Col_Index;
	u8 LOC_u8Row_Index;
	u8 LOC_u8key_NUM;
	for(LOC_u8Col_Index=0;LOC_u8Col_Index<KPD_u8_COLS;LOC_u8Col_Index++)
	{
		DIO_u8set_pin_value(KDP_u8_COLS_PORT,KPD_Au8_COLS_Pins[LOC_u8Col_Index],DIO_u8_LOW);

		for(LOC_u8Row_Index=0;LOC_u8Row_Index<KPD_u8_ROWS;LOC_u8Row_Index++)
		{
			LOC_u8key_NUM=LOC_u8Col_Index+(LOC_u8Row_Index*4);
			DIO_u8get_pin_value(KDP_u8_ROWS_PORT,KPD_Au8_ROWS_Pins[LOC_u8Row_Index],&Ptr_u8_KPD_Status[LOC_u8key_NUM]);
		}
		DIO_u8set_pin_value(KDP_u8_COLS_PORT,KPD_Au8_COLS_Pins[LOC_u8Col_Index],DIO_u8_HIGH);
	}

}
