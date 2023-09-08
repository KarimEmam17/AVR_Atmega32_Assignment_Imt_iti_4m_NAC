/*
 * main.c
 *
 *  Created on: Dec 3, 2022
 *      Author: Almodather
 */

#include "../STD_LIB/STD_Types.h"
#include "../STD_LIB/util.h"

#include <avr/delay.h>
#include "../MCAL/DIO/DIO_INTERFACE.h"
#include "EXTERNAL_INTERRUPT_config.h"
#include "External_interface.h"

u8 flag0=0;
u8 flag1=0;
void BLink_LED0(void){
	if(flag0%2==0)
	{
	DIO_u8set_pin_value(GROUP_A,DIO_u8_PIN_0,DIO_u8_HIGH);
	flag0++;
	}
	else
	{
	DIO_u8set_pin_value(GROUP_A,DIO_u8_PIN_0,DIO_u8_LOW);
	flag0++;
	}

}
void BLink_LED1(void){
	if(flag1%2==0)
	{
	DIO_u8set_pin_value(GROUP_A,DIO_u8_PIN_1,DIO_u8_HIGH);
	flag1++;
	}
	else
	{
	DIO_u8set_pin_value(GROUP_A,DIO_u8_PIN_1,DIO_u8_LOW);
	flag1++;
	}
}


void main(void){
//lab 1 imt toggle 2LED
	EXTI_INIT(EXTI_u8EXTI0,DIO_u8_INPUT,DIO_u8_HIGH);
	EXTI_INIT(EXTI_u8EXTI1,DIO_u8_INPUT,DIO_u8_HIGH);

	DIO_u8set_pin_dir(GROUP_A,DIO_u8_PIN_0,DIO_u8_OUTPUT);
	DIO_u8set_pin_dir(GROUP_A,DIO_u8_PIN_1,DIO_u8_OUTPUT);


	EXTI_voidSET_CallBack(EXTI_u8EXTI0,BLink_LED0);
	EXTI_voidSET_CallBack(EXTI_u8EXTI1,BLink_LED1);
	EXTI_voidSet_MODE(EXTI_u8EXTI0,EXTI_u8EXTI0_FALLING_EDGE);
	EXTI_voidSet_MODE(EXTI_u8EXTI1,EXTI_u8EXTI1_FALLING_EDGE);
	EXTI_voidEnable(EXTI_u8EXTI0);
	EXTI_voidEnable(EXTI_u8EXTI1);
	EXTI_voidGLOBAL_En_Dis(EXTI_u8ENABLE);

	while(1){




	}

}

