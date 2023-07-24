/*
 * STEPPER.c
 *
 *  Created on: Dec 3, 2022
 *      Author: Almodather
 */

#include "STD_Types.h"
#include "util.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "Stepper_config.h"
#include "Stepper_INTERFACE.h"
#include<avr/delay.h>




void Stepper_Init(void)
{
	DIO_u8set_pin_dir(STEPPER_u8COIL_PORT,STEPPER_u8COIL_BLUE  ,DIO_u8_OUTPUT );
	DIO_u8set_pin_dir(STEPPER_u8COIL_PORT,STEPPER_u8COIL_PINK  ,DIO_u8_OUTPUT );
	DIO_u8set_pin_dir(STEPPER_u8COIL_PORT,STEPPER_u8COIL_YELLOW,DIO_u8_OUTPUT );
	DIO_u8set_pin_dir(STEPPER_u8COIL_PORT,STEPPER_u8COIL_ORANGE,DIO_u8_OUTPUT );
}

void Stepper_void_Rotate_CW_Full_STEP(void)
{
	DIO_u8set_pin_value(STEPPER_u8COIL_PORT,STEPPER_u8COIL_BLUE  ,DIO_u8_HIGH);
	DIO_u8set_pin_value(STEPPER_u8COIL_PORT,STEPPER_u8COIL_PINK  ,DIO_u8_LOW );
	DIO_u8set_pin_value(STEPPER_u8COIL_PORT,STEPPER_u8COIL_YELLOW,DIO_u8_LOW );
	DIO_u8set_pin_value(STEPPER_u8COIL_PORT,STEPPER_u8COIL_ORANGE,DIO_u8_LOW );

	_delay_ms(10);
	DIO_u8set_pin_value(STEPPER_u8COIL_PORT,STEPPER_u8COIL_BLUE  ,DIO_u8_LOW );
	DIO_u8set_pin_value(STEPPER_u8COIL_PORT,STEPPER_u8COIL_PINK  ,DIO_u8_HIGH);
	DIO_u8set_pin_value(STEPPER_u8COIL_PORT,STEPPER_u8COIL_YELLOW,DIO_u8_LOW );
	DIO_u8set_pin_value(STEPPER_u8COIL_PORT,STEPPER_u8COIL_ORANGE,DIO_u8_LOW );
	_delay_ms(10);
	DIO_u8set_pin_value(STEPPER_u8COIL_PORT,STEPPER_u8COIL_BLUE  ,DIO_u8_LOW );
	DIO_u8set_pin_value(STEPPER_u8COIL_PORT,STEPPER_u8COIL_PINK  ,DIO_u8_LOW );
	DIO_u8set_pin_value(STEPPER_u8COIL_PORT,STEPPER_u8COIL_YELLOW,DIO_u8_HIGH);
	DIO_u8set_pin_value(STEPPER_u8COIL_PORT,STEPPER_u8COIL_ORANGE,DIO_u8_LOW );
	_delay_ms(10);
	DIO_u8set_pin_value(STEPPER_u8COIL_PORT,STEPPER_u8COIL_BLUE  ,DIO_u8_LOW );
	DIO_u8set_pin_value(STEPPER_u8COIL_PORT,STEPPER_u8COIL_PINK  ,DIO_u8_LOW );
	DIO_u8set_pin_value(STEPPER_u8COIL_PORT,STEPPER_u8COIL_YELLOW,DIO_u8_LOW );
	DIO_u8set_pin_value(STEPPER_u8COIL_PORT,STEPPER_u8COIL_ORANGE,DIO_u8_HIGH);
	_delay_ms(10);
}


void Stepper_void_Rotate_ACW_Full_STEP(void)
{
	DIO_u8set_pin_value(STEPPER_u8COIL_PORT,STEPPER_u8COIL_BLUE  ,DIO_u8_LOW );
	DIO_u8set_pin_value(STEPPER_u8COIL_PORT,STEPPER_u8COIL_PINK  ,DIO_u8_LOW );
	DIO_u8set_pin_value(STEPPER_u8COIL_PORT,STEPPER_u8COIL_YELLOW,DIO_u8_LOW );
	DIO_u8set_pin_value(STEPPER_u8COIL_PORT,STEPPER_u8COIL_ORANGE,DIO_u8_HIGH);
	_delay_ms(10);
	DIO_u8set_pin_value(STEPPER_u8COIL_PORT,STEPPER_u8COIL_BLUE  ,DIO_u8_LOW );
	DIO_u8set_pin_value(STEPPER_u8COIL_PORT,STEPPER_u8COIL_PINK  ,DIO_u8_LOW );
	DIO_u8set_pin_value(STEPPER_u8COIL_PORT,STEPPER_u8COIL_YELLOW,DIO_u8_HIGH);
	DIO_u8set_pin_value(STEPPER_u8COIL_PORT,STEPPER_u8COIL_ORANGE,DIO_u8_LOW );
	_delay_ms(10);
	DIO_u8set_pin_value(STEPPER_u8COIL_PORT,STEPPER_u8COIL_BLUE  ,DIO_u8_LOW );
	DIO_u8set_pin_value(STEPPER_u8COIL_PORT,STEPPER_u8COIL_PINK  ,DIO_u8_HIGH);
	DIO_u8set_pin_value(STEPPER_u8COIL_PORT,STEPPER_u8COIL_YELLOW,DIO_u8_LOW );
	DIO_u8set_pin_value(STEPPER_u8COIL_PORT,STEPPER_u8COIL_ORANGE,DIO_u8_LOW );
	_delay_ms(10);
	DIO_u8set_pin_value(STEPPER_u8COIL_PORT,STEPPER_u8COIL_BLUE  ,DIO_u8_HIGH);
	DIO_u8set_pin_value(STEPPER_u8COIL_PORT,STEPPER_u8COIL_PINK  ,DIO_u8_LOW );
	DIO_u8set_pin_value(STEPPER_u8COIL_PORT,STEPPER_u8COIL_YELLOW,DIO_u8_LOW );
	DIO_u8set_pin_value(STEPPER_u8COIL_PORT,STEPPER_u8COIL_ORANGE,DIO_u8_LOW );
	_delay_ms(10);



}

void Stepper_void_Rotate_CW_HALF_STEP(void)
{

	DIO_u8set_pin_value(STEPPER_u8COIL_PORT,STEPPER_u8COIL_BLUE  ,DIO_u8_HIGH);
	DIO_u8set_pin_value(STEPPER_u8COIL_PORT,STEPPER_u8COIL_PINK  ,DIO_u8_LOW );
	DIO_u8set_pin_value(STEPPER_u8COIL_PORT,STEPPER_u8COIL_YELLOW,DIO_u8_LOW );
	DIO_u8set_pin_value(STEPPER_u8COIL_PORT,STEPPER_u8COIL_ORANGE,DIO_u8_LOW );

	_delay_ms(10);
	DIO_u8set_pin_value(STEPPER_u8COIL_PORT,STEPPER_u8COIL_BLUE  ,DIO_u8_HIGH);
	DIO_u8set_pin_value(STEPPER_u8COIL_PORT,STEPPER_u8COIL_PINK  ,DIO_u8_HIGH);
	DIO_u8set_pin_value(STEPPER_u8COIL_PORT,STEPPER_u8COIL_YELLOW,DIO_u8_LOW );
	DIO_u8set_pin_value(STEPPER_u8COIL_PORT,STEPPER_u8COIL_ORANGE,DIO_u8_LOW );

	_delay_ms(10);
	DIO_u8set_pin_value(STEPPER_u8COIL_PORT,STEPPER_u8COIL_BLUE  ,DIO_u8_LOW );
	DIO_u8set_pin_value(STEPPER_u8COIL_PORT,STEPPER_u8COIL_PINK  ,DIO_u8_HIGH);
	DIO_u8set_pin_value(STEPPER_u8COIL_PORT,STEPPER_u8COIL_YELLOW,DIO_u8_LOW );
	DIO_u8set_pin_value(STEPPER_u8COIL_PORT,STEPPER_u8COIL_ORANGE,DIO_u8_LOW );
	_delay_ms(10);
	DIO_u8set_pin_value(STEPPER_u8COIL_PORT,STEPPER_u8COIL_BLUE  ,DIO_u8_LOW );
	DIO_u8set_pin_value(STEPPER_u8COIL_PORT,STEPPER_u8COIL_PINK  ,DIO_u8_HIGH);
	DIO_u8set_pin_value(STEPPER_u8COIL_PORT,STEPPER_u8COIL_YELLOW,DIO_u8_HIGH);
	DIO_u8set_pin_value(STEPPER_u8COIL_PORT,STEPPER_u8COIL_ORANGE,DIO_u8_LOW );
	_delay_ms(10);
	DIO_u8set_pin_value(STEPPER_u8COIL_PORT,STEPPER_u8COIL_BLUE  ,DIO_u8_LOW );
	DIO_u8set_pin_value(STEPPER_u8COIL_PORT,STEPPER_u8COIL_PINK  ,DIO_u8_LOW );
	DIO_u8set_pin_value(STEPPER_u8COIL_PORT,STEPPER_u8COIL_YELLOW,DIO_u8_HIGH);
	DIO_u8set_pin_value(STEPPER_u8COIL_PORT,STEPPER_u8COIL_ORANGE,DIO_u8_LOW );
	_delay_ms(10);
	DIO_u8set_pin_value(STEPPER_u8COIL_PORT,STEPPER_u8COIL_BLUE  ,DIO_u8_LOW );
	DIO_u8set_pin_value(STEPPER_u8COIL_PORT,STEPPER_u8COIL_PINK  ,DIO_u8_LOW );
	DIO_u8set_pin_value(STEPPER_u8COIL_PORT,STEPPER_u8COIL_YELLOW,DIO_u8_HIGH);
	DIO_u8set_pin_value(STEPPER_u8COIL_PORT,STEPPER_u8COIL_ORANGE,DIO_u8_HIGH);
	_delay_ms(10);
	DIO_u8set_pin_value(STEPPER_u8COIL_PORT,STEPPER_u8COIL_BLUE  ,DIO_u8_LOW );
	DIO_u8set_pin_value(STEPPER_u8COIL_PORT,STEPPER_u8COIL_PINK  ,DIO_u8_LOW );
	DIO_u8set_pin_value(STEPPER_u8COIL_PORT,STEPPER_u8COIL_YELLOW,DIO_u8_LOW );
	DIO_u8set_pin_value(STEPPER_u8COIL_PORT,STEPPER_u8COIL_ORANGE,DIO_u8_HIGH);
	_delay_ms(10);
	DIO_u8set_pin_value(STEPPER_u8COIL_PORT,STEPPER_u8COIL_BLUE  ,DIO_u8_HIGH);
	DIO_u8set_pin_value(STEPPER_u8COIL_PORT,STEPPER_u8COIL_PINK  ,DIO_u8_LOW );
	DIO_u8set_pin_value(STEPPER_u8COIL_PORT,STEPPER_u8COIL_YELLOW,DIO_u8_LOW );
	DIO_u8set_pin_value(STEPPER_u8COIL_PORT,STEPPER_u8COIL_ORANGE,DIO_u8_HIGH);
	_delay_ms(10);

}



void Stepper_void_Set_Angle_dir(u32 Copy_u32_Angle,u8 Copy_u8_Dir)
{
	u32 LOC_u32_Steps =(Copy_u32_Angle*STEPPER_Full_Steps )/STEPPER_360;
	u16 LOC_u16Index;
	u32 var =LOC_u32_Steps/4;

	if(Copy_u8_Dir== STEPPER_u8Cw_Dir)
	{
		for(LOC_u16Index=0;LOC_u16Index<var;LOC_u16Index++)
		{
			Stepper_void_Rotate_CW_Full_STEP();
		}
	}
	else
	{
		for(LOC_u16Index=0;LOC_u16Index<var;LOC_u16Index++)
			{
					Stepper_void_Rotate_ACW_Full_STEP();
			}
	}
}
