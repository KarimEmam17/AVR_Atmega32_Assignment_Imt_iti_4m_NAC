/*
 * keypad_interface.h
 *
 *  Created on: Nov 26, 2022
 *      Author: Almodather
 */

#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

#define KPD_u8_ROWS		4
#define KPD_u8_COLS		4
#define KPD_u8_KEYS_NUM  (KPD_u8_COLS*KPD_u8_ROWS)

#define KPD_u8_KEY_PRESSED     	0
#define KPD_u8_KEY_NOT_PRESSED 	1

void KPD_void_Get_Status(u8 *Ptr_u8_KPD_Status);
void KPD_void_Init(void);
#endif /* KEYPAD_INTERFACE_H_ */
