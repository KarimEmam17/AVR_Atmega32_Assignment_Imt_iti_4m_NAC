/*
 * external_interrupt.c
 *
 *  Created on: Dec 3, 2022
 *      Author: Almodather
 */

#include "../STD_LIB/STD_Types.h"
#include "../STD_LIB/util.h"

#include <avr/delay.h>
#include "../MCAL/DIO/DIO_INTERFACE.h"
#include "External_interrupt_Private.h"
#include "EXTERNAL_INTERRUPT_config.h"
#include "External_interface.h"


void (*AvoidCallBack[3])(void)= {NULL,NULL,NULL};
/*
void BLink_LED(void)
{
	DIO_u8set_pin_value   (GROUP_A,DIO_u8_PIN_0,DIO_u8_HIGH);
	_delay_ms(1000);
	DIO_u8set_pin_value   (GROUP_A,DIO_u8_PIN_0,DIO_u8_LOW);
	_delay_ms(1000);
}
*/
void __vector_1 (void)//interrupt0
{
	if(AvoidCallBack[0]!=NULL)
	{AvoidCallBack[0]();}

}
void __vector_2 (void)//interrupt1
{
	if(AvoidCallBack[1]!=NULL)
	{AvoidCallBack[1]();}

}
void __vector_3 (void)//interrupt2
{
	if(AvoidCallBack[2]!=NULL)
	{
	AvoidCallBack[2]();
	}
}

void EXTI_INIT(u8 Copy_u8INT_Index,u8 Copy_u8_Direct,u8 Copy_u8_Value)  // this function  to initial the  external interrupt ..1st is the exterint num
{																		//2nd is the direction 3rd isthe value if it pull up  or low
	switch(Copy_u8INT_Index)
	{
		case EXTI_u8EXTI0:
			DIO_u8set_pin_dir(GROUP_D,DIO_u8_PIN_2,Copy_u8_Direct);
			DIO_u8set_pin_value(GROUP_D,DIO_u8_PIN_2,Copy_u8_Value);
			break;

		case EXTI_u8EXTI1:
			DIO_u8set_pin_dir(GROUP_D,DIO_u8_PIN_3,Copy_u8_Direct);
			DIO_u8set_pin_value(GROUP_D,DIO_u8_PIN_3,Copy_u8_Value);
			break;


		case EXTI_u8EXTI2:
			DIO_u8set_pin_dir(GROUP_B,DIO_u8_PIN_2,Copy_u8_Direct);
			DIO_u8set_pin_value(GROUP_B,DIO_u8_PIN_2,Copy_u8_Value);
			break;

	}


}

void EXTI_voidSet_MODE(u8 Copy_u8_INT_Index, u8 Copy_u8INT_Level)
{
	switch(Copy_u8_INT_Index)
	{
	case EXTI_u8EXTI0:
		Assign_Bit(EXTI_u8_MCUCR,0,get_bit(Copy_u8INT_Level,0));
		Assign_Bit(EXTI_u8_MCUCR,1,get_bit(Copy_u8INT_Level,1));
		break;
	case EXTI_u8EXTI1:
		Assign_Bit(EXTI_u8_MCUCR,2,get_bit(Copy_u8INT_Level,0));
		Assign_Bit(EXTI_u8_MCUCR,3,get_bit(Copy_u8INT_Level,1));
		break;
	case EXTI_u8EXTI2:

		Assign_Bit(EXTI_u8_MCUCSR,6,get_bit(Copy_u8INT_Level,0));

		break;
	}
}


void EXTI_voidSet_MODE_RUNTIME(u8 Copy_u8_INT_Index, u8 Copy_u8INT_Level)
{
	switch(Copy_u8_INT_Index)
	{
	case EXTI_u8EXTI0:
		Assign_Bit(EXTI_u8_MCUCR,0,get_bit(Copy_u8INT_Level,0));
		Assign_Bit(EXTI_u8_MCUCR,1,get_bit(Copy_u8INT_Level,1));
		break;
	case EXTI_u8EXTI1:
		Assign_Bit(EXTI_u8_MCUCR,2,get_bit(Copy_u8INT_Level,0));
		Assign_Bit(EXTI_u8_MCUCR,3,get_bit(Copy_u8INT_Level,1));
		break;
	case EXTI_u8EXTI2:
		Assign_Bit(EXTI_u8_GICR,5,EXTI_u8DISABLE);
		Assign_Bit(EXTI_u8_MCUCSR,6,get_bit(Copy_u8INT_Level,0)); //this  is mentioned  p65 in  extint 2 section
		Assign_Bit(EXTI_u8_GIFR,5,EXTI_u8EXTI2_Clear_flag);
		Assign_Bit(EXTI_u8_GICR,5,EXTI_u8ENABLE);
		break;
	}
}

void EXTI_voidSET_CallBack(u8 Copy_u8INT_Index,void(*pvoidCallBack)(void))
{
	AvoidCallBack[Copy_u8INT_Index]= pvoidCallBack;
}






void EXTI_voidEnable(u8 Copy_u8_INT_Index)
{
	switch(Copy_u8_INT_Index)
	{
	case EXTI_u8EXTI0:
		Assign_Bit(EXTI_u8_GICR,6,EXTI_u8ENABLE);
		break;
	case EXTI_u8EXTI1:
		Assign_Bit(EXTI_u8_GICR,7,EXTI_u8ENABLE);
		break;
	case EXTI_u8EXTI2:
		Assign_Bit(EXTI_u8_GICR,5,EXTI_u8ENABLE);
		break;
	}
}
void EXTI_voidDisable(u8 Copy_u8_INT_Index)
{
	switch(Copy_u8_INT_Index)
	{
	case EXTI_u8EXTI0:
		Assign_Bit(EXTI_u8_GICR,6,EXTI_u8DISABLE);
		break;
	case EXTI_u8EXTI1:
		Assign_Bit(EXTI_u8_GICR,7,EXTI_u8DISABLE);
		break;
	case EXTI_u8EXTI2:
		Assign_Bit(EXTI_u8_GICR,5,EXTI_u8DISABLE);
		break;
	}
}


void EXTI_voidGLOBAL_En_Dis(u8 Copy_u8En_Dis)
{
	switch(Copy_u8En_Dis)
	{
		case EXTI_u8ENABLE:
			set_bit(EXTI_u8_SREG,7);
			break;

		case EXTI_u8DISABLE:
			clear_bit(EXTI_u8_SREG,7);
			break;

	}
}
