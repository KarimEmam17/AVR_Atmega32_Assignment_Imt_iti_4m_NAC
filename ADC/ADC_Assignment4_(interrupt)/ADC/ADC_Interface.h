/*
 * ADC_INTERface.h
 *
 *  Created on: Dec 9, 2022
 *      Author: Almodather
 */
#ifndef ADC_INTERDACE_H_
#define	ADC_INTERDACE_H_


#define Voltage_Reference_Selections_for_ADC	AREF
#define Input_Channel_and_Gain_Selections		single_Ended_input_ADC0
#define ADC_Prescaler_Selections				ADC_Prescalar_128
#define ADC_ADLAR_Adjustment 					ADC_ADLAR_Right_Adjustment

/*   Voltage Reference Selections for ADC  */
#define AREF 								0 //AREF,internal Vref turned off =5v
#define	AVCC								1 //AVCC with external  capacitor  at AREF pin= meaning it  will be 5v +cap with  AREF
#define INTERNAL_2_56V_REFERENCE0			3  // internal 2.56 Voltage Referance with  external  capacitor  at  AREF pin

/*THE ADC PINS*/
#define ADC_U8_CH0 0
#define ADC_U8_CH1 1
#define ADC_U8_CH2 2
#define ADC_U8_CH3 3
#define ADC_U8_CH4 4
#define ADC_U8_CH5 5
#define ADC_U8_CH6 6
#define ADC_U8_CH7 7
/*Input Channel and Gain Selections*/

#define single_Ended_input_ADC0				0 //the input is ADC0 without  any  gain
#define single_Ended_input_ADC1				1 //the input is ADC1 without  any  gain
#define single_Ended_input_ADC2				2 //the input is ADC2 without  any  gain
#define single_Ended_input_ADC3				3 //the input is ADC3 without  any  gain
#define single_Ended_input_ADC4				4 //the input is ADC4 without  any  gain
#define single_Ended_input_ADC5				5 //the input is ADC5 without  any  gain
#define single_Ended_input_ADC6				6 //the input is ADC6 without  any  gain
#define single_Ended_input_ADC7				7 //the input is ADC7 without  any  gain

#define Pos_differential_input_ADC0_NEGA_differential_input_ADC0_gain_10x	8  //the differential is the difference between two signals sent and the gain is how it will be represented if it will be multiplied by the gain
#define Pos_differential_input_ADC1_NEGA_differential_input_ADC0_gain_10x	9  //the differential is the difference between two signals sent and the gain is how it will be represented if it will be multiplied by the gain
#define Pos_differential_input_ADC0_NEGA_differential_input_ADC0_gain_200x	10 //the differential is the difference between two signals sent and the gain is how it will be represented if it will be multiplied by the gain
#define Pos_differential_input_ADC1_NEGA_differential_input_ADC0_gain_200x	11 //the differential is the difference between two signals sent and the gain is how it will be represented if it will be multiplied by the gain
#define Pos_differential_input_ADC2_NEGA_differential_input_ADC2_gain_10x	12 //the differential is the difference between two signals sent and the gain is how it will be represented if it will be multiplied by the gain
#define Pos_differential_input_ADC3_NEGA_differential_input_ADC2_gain_10x	13  //the differential is the difference between two signals sent and the gain is how it will be represented if it will be multiplied by the gain
#define Pos_differential_input_ADC2_NEGA_differential_input_ADC2_gain_200x	14  //the differential is the difference between two signals sent and the gain is how it will be represented if it will be multiplied by the gain
#define Pos_differential_input_ADC3_NEGA_differential_input_ADC2_gain_200x	15  //the differential is the difference between two signals sent and the gain is how it will be represented if it will be multiplied by the gain
#define Pos_differential_input_ADC0_NEGA_differential_input_ADC1_gain_1x	16  //the differential is the difference between two signals sent and the gain is how it will be represented if it will be multiplied by the gain
#define Pos_differential_input_ADC1_NEGA_differential_input_ADC1_gain_1x	17  //the differential is the difference between two signals sent and the gain is how it will be represented if it will be multiplied by the gain
#define Pos_differential_input_ADC2_NEGA_differential_input_ADC1_gain_1x	18  //the differential is the difference between two signals sent and the gain is how it will be represented if it will be multiplied by the gain
#define Pos_differential_input_ADC3_NEGA_differential_input_ADC1_gain_1x	19  //the differential is the difference between two signals sent and the gain is how it will be represented if it will be multiplied by the gain
#define Pos_differential_input_ADC4_NEGA_differential_input_ADC1_gain_1x	20  //the differential is the difference between two signals sent and the gain is how it will be represented if it will be multiplied by the gain
#define Pos_differential_input_ADC5_NEGA_differential_input_ADC1_gain_1x	21 //the differential is the difference between two signals sent and the gain is how it will be represented if it will be multiplied by the gain
#define Pos_differential_input_ADC6_NEGA_differential_input_ADC1_gain_1x	22 //the differential is the difference between two signals sent and the gain is how it will be represented if it will be multiplied by the gain
#define Pos_differential_input_ADC7_NEGA_differential_input_ADC1_gain_1x	23 //the differential is the difference between two signals sent and the gain is how it will be represented if it will be multiplied by the gain
#define Pos_differential_input_ADC0_NEGA_differential_input_ADC2_gain_1x	24  //the differential is the difference between two signals sent and the gain is how it will be represented if it will be multiplied by the gain
#define Pos_differential_input_ADC1_NEGA_differential_input_ADC2_gain_1x	25  //the differential is the difference between two signals sent and the gain is how it will be represented if it will be multiplied by the gain
#define Pos_differential_input_ADC2_NEGA_differential_input_ADC2_gain_1x	26  //the differential is the difference between two signals sent and the gain is how it will be represented if it will be multiplied by the gain
#define Pos_differential_input_ADC3_NEGA_differential_input_ADC2_gain_1x	27  //the differential is the difference between two signals sent and the gain is how it will be represented if it will be multiplied by the gain
#define Pos_differential_input_ADC4_NEGA_differential_input_ADC2_gain_1x	28  //the differential is the difference between two signals sent and the gain is how it will be represented if it will be multiplied by the gain
#define Pos_differential_input_ADC5_NEGA_differential_input_ADC2_gain_1x	29  //the differential is the difference between two signals sent and the gain is how it will be represented if it will be multiplied by the gain

#define Battery_1_22V_Vbg	30
//Single But i don't know when we use it
#define calculate_the_0v_(GND)	31 //this is used for  calculate the 0V of the ground

/*		ADC Prescaler Selections			*/
#define ADC_Prescalar_2   	0
//#define ADC_Prescalar_2 	1	// Ask  beshio from  the datasheet
#define ADC_Prescalar_4 	2
#define ADC_Prescalar_8		3
#define ADC_Prescalar_16 	4
#define ADC_Prescalar_32 	5
#define ADC_Prescalar_64 	6
#define ADC_Prescalar_128	7

/*   ADC Auto Trigger Source Selections  */
#define Free_Running_mode				0
#define Analog_Comparator				1
#define External_Interrupt_Request_0	2
#define Timer_0_Compare_Match			3
#define Timer_0_Overflow				4
#define Timer_Compare_Match_B			5
#define Timer_1_Overflow				6
#define Timer_1_Capture_Event			7

/*	ADC_ADLAR_Adjustment	*/
#define ADC_ADLAR_Right_Adjustment		0 //10bits ADCL--->ADCH 8 & 9
#define ADC_ADLAR_Left_Adjustment		1 //8bits single shot

void ADC_voidInit(void);
void ADC_SingleConversion (u16	*CopyPtr_u16_value );

void __vector_16 (void)__attribute__((signal));
void ADC_voidInit_Interrupt(void);
void ADC_u16Read_Interput(void);



#endif
