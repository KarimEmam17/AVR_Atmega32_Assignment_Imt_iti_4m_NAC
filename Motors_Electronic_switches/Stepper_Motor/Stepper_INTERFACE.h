/*
 * Stepper_INTERFACE.h
 *
 *  Created on: Dec 3, 2022
 *      Author: Almodather
 */

#ifndef STEPPER_INTERFACE_H_
#define STEPPER_INTERFACE_H_

#define STEPPER_Full_Steps  2048
#define STEPPER_360   360

#define STEPPER_u8Cw_Dir  1
#define STEPPER_u8ACw_Dir  0

void Stepper_void_Rotate_CW_Full_STEP(void);
void Stepper_void_Rotate_CW_HALF_STEP(void);

void Stepper_Init(void);
void Stepper_void_Rotate_ACW_Full_STEP(void);
void Stepper_void_Rotate_CW_HALF_STEP(void); //needed

void Stepper_void_Set_Angle_dir(u32 Copy_u32_Angle,u8 Copy_u8_Dir);

#endif /* STEPPER_INTERFACE_H_ */
