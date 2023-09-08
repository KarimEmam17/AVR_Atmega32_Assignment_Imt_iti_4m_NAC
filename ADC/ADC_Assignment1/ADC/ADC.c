/*
 * ADC.c
 *
 *  Created on: Dec 9, 2022
 *      Author: Almodather
 */


#include "../STD_LIB/STD_Types.h"
#include  "../STD_LIB/util.h"
#include "../MCAL/DIO/DIO_INTERFACE.h"
#include "ADC_Interface.h"
#include   "ADC_Private.h"


void ADC_voidInit(void)
{

	/* ADC ENABLE*/
	set_bit(ADC_U8_ADCSRA,ADCSRA_ADEN);
	/*Voltage Reference Selections for ADC*/
	#if Voltage_Reference_Selections_for_ADC==AREF
		clear_bit(ADC_U8_ADMUX,ADMUX_REFS1);
		clear_bit(ADC_U8_ADMUX,ADMUX_REFS0);
	#elif Voltage_Reference_Selections_for_ADC==AVCC
		clear_bit(ADC_U8_ADMUX,ADMUX_REFS1);
		set_bit(ADC_U8_ADMUX,ADMUX_REFS0);
	#elif Voltage_Reference_Selections_for_ADC==INTERNAL_2.56V_REFERENCE0
		set_bit(ADC_U8_ADMUX,ADMUX_REFS1);
		set_bit(ADC_U8_ADMUX,ADMUX_REFS0);
	#endif
		/*Input Channel and Gain Selections*/
	#if Input_Channel_and_Gain_Selections==single_Ended_input_ADC0
		DIO_u8set_pin_dir(GROUP_A,ADC_U8_CH0,DIO_u8_INPUT);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX4);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX3);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX2);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX1);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX0);
	#elif Input_Channel_and_Gain_Selections==single_Ended_input_ADC1
		DIO_u8set_pin_dir(GROUP_A,ADC_U8_CH1,DIO_u8_INPUT);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX4);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX3);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX2);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX1);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX0);
	#elif Input_Channel_and_Gain_Selections==single_Ended_input_ADC2
		DIO_u8set_pin_dir(GROUP_A,ADC_U8_CH2,DIO_u8_INPUT);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX4);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX3);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX2);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX1);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX0);
	#elif Input_Channel_and_Gain_Selections==single_Ended_input_ADC3
		DIO_u8set_pin_dir(GROUP_A,ADC_U8_CH3,DIO_u8_INPUT);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX4);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX3);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX2);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX1);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX0);
	#elif Input_Channel_and_Gain_Selections==single_Ended_input_ADC4
		DIO_u8set_pin_dir(GROUP_A,ADC_U8_CH4,DIO_u8_INPUT);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX4);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX3);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX2);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX1);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX0);
	#elif Input_Channel_and_Gain_Selections==single_Ended_input_ADC5
		DIO_u8set_pin_dir(GROUP_A,ADC_U8_CH5,DIO_u8_INPUT);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX4);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX3);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX2);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX1);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX0);
	#elif Input_Channel_and_Gain_Selections==single_Ended_input_ADC6
		DIO_u8set_pin_dir(GROUP_A,ADC_U8_CH6,DIO_u8_INPUT);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX4);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX3);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX2);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX1);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX0);
	#elif Input_Channel_and_Gain_Selections==single_Ended_input_ADC7
		DIO_u8set_pin_dir(GROUP_A,ADC_U8_CH7,DIO_u8_INPUT);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX4);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX3);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX2);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX1);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX0);
	#elif Input_Channel_and_Gain_Selections==Pos_differential_input_ADC0_NEGA_differential_input_ADC0_gain_10x
		DIO_u8set_pin_dir(GROUP_A,ADC_U8_CH0,DIO_u8_INPUT);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX4);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX3);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX2);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX1);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX0);
	#elif Input_Channel_and_Gain_Selections==Pos_differential_input_ADC1_NEGA_differential_input_ADC0_gain_10x
		DIO_u8set_pin_dir(GROUP_A,ADC_U8_CH0,DIO_u8_INPUT);
		DIO_u8set_pin_dir(GROUP_A,ADC_U8_CH1,DIO_u8_INPUT);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX4);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX3);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX2);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX1);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX0);
	#elif Input_Channel_and_Gain_Selections==Pos_differential_input_ADC0_NEGA_differential_input_ADC0_gain_200x
		DIO_u8set_pin_dir(GROUP_A,ADC_U8_CH0,DIO_u8_INPUT);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX4);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX3);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX2);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX1);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX0);
	#elif Input_Channel_and_Gain_Selections==Pos_differential_input_ADC1_NEGA_differential_input_ADC0_gain_200x
		DIO_u8set_pin_dir(GROUP_A,ADC_U8_CH0,DIO_u8_INPUT);
		DIO_u8set_pin_dir(GROUP_A,ADC_U8_CH1,DIO_u8_INPUT);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX4);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX3);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX2);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX1);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX0);
	#elif Input_Channel_and_Gain_Selections==Pos_differential_input_ADC2_NEGA_differential_input_ADC2_gain_10x
		DIO_u8set_pin_dir(GROUP_A,ADC_U8_CH2,DIO_u8_INPUT);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX4);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX3);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX2);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX1);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX0);
	#elif Input_Channel_and_Gain_Selections==Pos_differential_input_ADC3_NEGA_differential_input_ADC2_gain_10x
		DIO_u8set_pin_dir(GROUP_A,ADC_U8_CH2,DIO_u8_INPUT);
		DIO_u8set_pin_dir(GROUP_A,ADC_U8_CH3,DIO_u8_INPUT);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX4);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX3);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX2);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX1);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX0);
	#elif Input_Channel_and_Gain_Selections==Pos_differential_input_ADC2_NEGA_differential_input_ADC2_gain_200x
		DIO_u8set_pin_dir(GROUP_A,ADC_U8_CH2,DIO_u8_INPUT);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX4);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX3);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX2);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX1);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX0);
	#elif Input_Channel_and_Gain_Selections==Pos_differential_input_ADC3_NEGA_differential_input_ADC2_gain_200x
		DIO_u8set_pin_dir(GROUP_A,ADC_U8_CH2,DIO_u8_INPUT);
		DIO_u8set_pin_dir(GROUP_A,ADC_U8_CH3,DIO_u8_INPUT);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX4);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX3);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX2);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX1);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX0);
	#elif Input_Channel_and_Gain_Selections==Pos_differential_input_ADC0_NEGA_differential_input_ADC1_gain_1x
		DIO_u8set_pin_dir(GROUP_A,ADC_U8_CH0,DIO_u8_INPUT);
		DIO_u8set_pin_dir(GROUP_A,ADC_U8_CH1,DIO_u8_INPUT);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX4);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX3);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX2);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX1);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX0);
	#elif Input_Channel_and_Gain_Selections==Pos_differential_input_ADC1_NEGA_differential_input_ADC1_gain_1x
		DIO_u8set_pin_dir(GROUP_A,ADC_U8_CH1,DIO_u8_INPUT);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX4);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX3);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX2);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX1);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX0);
	#elif Input_Channel_and_Gain_Selections==Pos_differential_input_ADC2_NEGA_differential_input_ADC1_gain_1x
		DIO_u8set_pin_dir(GROUP_A,ADC_U8_CH1,DIO_u8_INPUT);
		DIO_u8set_pin_dir(GROUP_A,ADC_U8_CH2,DIO_u8_INPUT);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX4);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX3);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX2);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX1);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX0);
	#elif Input_Channel_and_Gain_Selections==Pos_differential_input_ADC3_NEGA_differential_input_ADC1_gain_1x
		DIO_u8set_pin_dir(GROUP_A,ADC_U8_CH1,DIO_u8_INPUT);
		DIO_u8set_pin_dir(GROUP_A,ADC_U8_CH3,DIO_u8_INPUT);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX4);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX3);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX2);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX1);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX0);
	#elif Input_Channel_and_Gain_Selections==Pos_differential_input_ADC4_NEGA_differential_input_ADC1_gain_1x
		DIO_u8set_pin_dir(GROUP_A,ADC_U8_CH1,DIO_u8_INPUT);
		DIO_u8set_pin_dir(GROUP_A,ADC_U8_CH4,DIO_u8_INPUT);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX4);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX3);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX2);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX1);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX0);
	#elif Input_Channel_and_Gain_Selections==Pos_differential_input_ADC5_NEGA_differential_input_ADC1_gain_1x
		DIO_u8set_pin_dir(GROUP_A,ADC_U8_CH1,DIO_u8_INPUT);
		DIO_u8set_pin_dir(GROUP_A,ADC_U8_CH5,DIO_u8_INPUT);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX4);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX3);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX2);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX1);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX0);
	#elif Input_Channel_and_Gain_Selections==Pos_differential_input_ADC6_NEGA_differential_input_ADC1_gain_1x
		DIO_u8set_pin_dir(GROUP_A,ADC_U8_CH1,DIO_u8_INPUT);
		DIO_u8set_pin_dir(GROUP_A,ADC_U8_CH6,DIO_u8_INPUT);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX4);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX3);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX2);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX1);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX0);
	#elif Input_Channel_and_Gain_Selections==Pos_differential_input_ADC7_NEGA_differential_input_ADC1_gain_1x
		DIO_u8set_pin_dir(GROUP_A,ADC_U8_CH1,DIO_u8_INPUT);
		DIO_u8set_pin_dir(GROUP_A,ADC_U8_CH7,DIO_u8_INPUT);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX4);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX3);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX2);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX1);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX0);
	#elif Input_Channel_and_Gain_Selections==Pos_differential_input_ADC0_NEGA_differential_input_ADC2_gain_1x
		DIO_u8set_pin_dir(GROUP_A,ADC_U8_CH0,DIO_u8_INPUT);
		DIO_u8set_pin_dir(GROUP_A,ADC_U8_CH2,DIO_u8_INPUT);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX4);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX3);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX2);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX1);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX0);
	#elif Input_Channel_and_Gain_Selections==Pos_differential_input_ADC1_NEGA_differential_input_ADC2_gain_1x
		DIO_u8set_pin_dir(GROUP_A,ADC_U8_CH1,DIO_u8_INPUT);
		DIO_u8set_pin_dir(GROUP_A,ADC_U8_CH2,DIO_u8_INPUT);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX4);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX3);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX2);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX1);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX0);
	#elif Input_Channel_and_Gain_Selections==Pos_differential_input_ADC2_NEGA_differential_input_ADC2_gain_1x
		DIO_u8set_pin_dir(GROUP_A,ADC_U8_CH2,DIO_u8_INPUT);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX4);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX3);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX2);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX1);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX0);
	#elif Input_Channel_and_Gain_Selections==Pos_differential_input_ADC3_NEGA_differential_input_ADC2_gain_1x
		DIO_u8set_pin_dir(GROUP_A,ADC_U8_CH3,DIO_u8_INPUT);
		DIO_u8set_pin_dir(GROUP_A,ADC_U8_CH2,DIO_u8_INPUT);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX4);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX3);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX2);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX1);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX0);
	#elif Input_Channel_and_Gain_Selections==Pos_differential_input_ADC4_NEGA_differential_input_ADC2_gain_1x
		DIO_u8set_pin_dir(GROUP_A,ADC_U8_CH4,DIO_u8_INPUT);
		DIO_u8set_pin_dir(GROUP_A,ADC_U8_CH2,DIO_u8_INPUT);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX4);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX3);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX2);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX1);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX0);
	#elif Input_Channel_and_Gain_Selections==Pos_differential_input_ADC5_NEGA_differential_input_ADC2_gain_1x
		DIO_u8set_pin_dir(GROUP_A,ADC_U8_CH5,DIO_u8_INPUT);
		DIO_u8set_pin_dir(GROUP_A,ADC_U8_CH2,DIO_u8_INPUT);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX4);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX3);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX2);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX1);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX0);
	#elif Input_Channel_and_Gain_Selections==Battery_1.22V_Vbg// ASk beshioo
		set_bit(ADC_U8_ADMUX,ADMUX_MUX4);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX3);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX2);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX1);
		clear_bit(ADC_U8_ADMUX,ADMUX_MUX0);
	#elif Input_Channel_and_Gain_Selections==calculate_the_0v_(GND)// ASk beshioo
		set_bit(ADC_U8_ADMUX,ADMUX_MUX4);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX3);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX2);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX1);
		set_bit(ADC_U8_ADMUX,ADMUX_MUX0);
	#endif

	/*	ADC Prescaler Selections*/
	#if ADC_Prescaler_Selections==ADC_Prescalar_2
		clear_bit(ADC_U8_ADCSRA,ADCSRA_ADPS2);
		clear_bit(ADC_U8_ADCSRA,ADCSRA_ADPS1);
		clear_bit(ADC_U8_ADCSRA,ADCSRA_ADPS0);
	#elif ADC_Prescaler_Selections==ADC_Prescalar_4
		clear_bit(ADC_U8_ADCSRA,ADCSRA_ADPS2);
		set_bit(ADC_U8_ADCSRA,ADCSRA_ADPS1);
		clear_bit(ADC_U8_ADCSRA,ADCSRA_ADPS0);
	#elif ADC_Prescaler_Selections==ADC_Prescalar_8
		clear_bit(ADC_U8_ADCSRA,ADCSRA_ADPS2);
		set_bit(ADC_U8_ADCSRA,ADCSRA_ADPS1);
		set_bit(ADC_U8_ADCSRA,ADCSRA_ADPS0);
	#elif ADC_Prescaler_Selections==ADC_Prescalar_16
		set_bit(ADC_U8_ADCSRA,ADCSRA_ADPS2);
		clear_bit(ADC_U8_ADCSRA,ADCSRA_ADPS1);
		clear_bit(ADC_U8_ADCSRA,ADCSRA_ADPS0);
	#elif ADC_Prescaler_Selections==ADC_Prescalar_32
		set_bit(ADC_U8_ADCSRA,ADCSRA_ADPS2);
		clear_bit(ADC_U8_ADCSRA,ADCSRA_ADPS1);
		set_bit(ADC_U8_ADCSRA,ADCSRA_ADPS0);
	#elif ADC_Prescaler_Selections==ADC_Prescalar_64
		set_bit(ADC_U8_ADCSRA,ADCSRA_ADPS2);
		set_bit(ADC_U8_ADCSRA,ADCSRA_ADPS1);
		clear_bit(ADC_U8_ADCSRA,ADCSRA_ADPS0);
	#elif ADC_Prescaler_Selections==ADC_Prescalar_128
		set_bit(ADC_U8_ADCSRA,ADCSRA_ADPS2);
		set_bit(ADC_U8_ADCSRA,ADCSRA_ADPS1);
		set_bit(ADC_U8_ADCSRA,ADCSRA_ADPS0);
	#endif

	/*right  or left  adjustment*/

	#if ADC_ADLAR_Adjustment==ADC_ADLAR_Right_Adjustment
	clear_bit(ADC_U8_ADMUX,ADMUX_ADLAR);
	#elif ADC_ADLAR_Adjustment==ADC_ADLAR_Left_Adjustment
	set_bit(ADC_U8_ADMUX,ADMUX_ADLAR);
	#endif
return;
}

/*this function  will work  on  10bits single time and  using  the  polling  methhod   */
void ADC_SingleConversion (u16	*CopyPtr_u16_value )
{
		/*start conversion */
	set_bit(ADC_U8_ADCSRA,ADCSRA_ADSC); //  this bit when  finishes it cleared it's self   and interrupt  fires if u  enable  the interrupt bit
	/*polling  method the best is by interrupt */
	while(get_bit(ADC_U8_ADCSRA,ADCSRA_ADIF) != 1); //  this work  on  the flag  when this bit is 0 it stuck  until  it turnes to  1
	// or we can use the interrupt that fires when the conversion is finished and and then  continue  takes the result
	/*clearing the flag */
	set_bit(ADC_U8_ADCSRA,ADCSRA_ADIF);

	*CopyPtr_u16_value=ADC_U8_ADCL;
	*CopyPtr_u16_value=(ADC_U8_ADCH<<8);
}

u16 ADC_u16Read(u8 Copy_u8Channel)
{
	u16 res;
	ADC_U8_ADMUX &=0b11100000;


	ADC_U8_ADMUX |=Copy_u8Channel;

	// start Signal conversion

	set_bit(ADC_U8_ADCSRA,6);

	while(get_bit(ADC_U8_ADCSRA,4) != 1); // polling on a flag

	set_bit(ADC_U8_ADCSRA,4);
	res =ADC_U8_ADCL>>6;
	res |=(((u16) ADC_U8_ADCH)<<2);

	return res;
}
