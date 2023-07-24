/*
 * main.c
 *
 *  Created on: Dec 3, 2022
 *      Author: Almodather
 */


#include <stdio.h>
#include "STD_Types.h"
#include "util.h"
#include "../MCAL/DIO/DIO_interface.h"
void main ()
{
	Stepper_Init();
	while(1)
	{
		Stepper_void_Set_Angle_dir(90,0);
	}
}
