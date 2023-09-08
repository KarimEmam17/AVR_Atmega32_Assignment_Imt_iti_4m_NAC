/*
 * External_interface.h
 *
 *  Created on: Dec 3, 2022
 *      Author: Almodather
 */

#ifndef EXTERNAL_INTERFACE_H_
#define EXTERNAL_INTERFACE_H_



#define EXTI_u8EXTI0  0
#define EXTI_u8EXTI1  1
#define EXTI_u8EXTI2  2

#define EXTI_u8EXTI0_LOW_LVL       0
#define EXTI_u8EXTI0_IOC           1
#define EXTI_u8EXTI0_FALLING_EDGE  2
#define EXTI_u8EXTI0_RISING_EDGE   3

#define EXTI_u8EXTI1_LOW_LVL       0
#define EXTI_u8EXTI1_IOC           1
#define EXTI_u8EXTI1_FALLING_EDGE  2
#define EXTI_u8EXTI1_RISING_EDGE   3


#define EXTI_u8EXTI2_FALLING_EDGE  0
#define EXTI_u8EXTI2_RISING_EDGE   1

#define EXTI_u8EXTI2_Clear_flag	   1


#define EXTI_u8ENABLE		0b1
#define EXTI_u8DISABLE		0b0

//void BLink_LED(void);


void __vector_1 (void)__attribute__((signal));
void __vector_2 (void)__attribute__((signal));
void __vector_3 (void)__attribute__((signal));

void EXTI_INIT(u8 Copy_u8INT_Index,u8 Copy_u8_Direct,u8 Copy_u8_Value);
void EXTI_voidSET_CallBack(u8 Copy_u8INT_Index, void (*PvoidCallBack)(void));

void EXTI_voidSet_MODE(u8 Copy_u8_INT_Index, u8 Copy_u8INT_Level);
void EXTI_voidSet_MODE_RUNTIME(u8 Copy_u8_INT_Index, u8 Copy_u8INT_Level);

void EXTI_voidGLOBAL_En_Dis(u8 Copy_u8En_Dis);

void EXTI_voidEnable(u8 Copy_u8_INT_Index);
void EXTI_voidDisable(u8 Copy_u8_INT_Index);


#endif /* EXTERNAL_INTERFACE_H_ */
