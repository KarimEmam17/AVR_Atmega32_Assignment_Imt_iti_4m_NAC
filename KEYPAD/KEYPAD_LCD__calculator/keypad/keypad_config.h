/*
 * keypad_config.h
 *
 *  Created on: Nov 26, 2022
 *      Author: Almodather
 */

#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_



#define KPD_u8_KEYS_NUM  (KPD_u8_COLS*KPD_u8_ROWS)

#define KDP_u8_ROWS_PORT  GROUP_A


#define KPD_u8_ROW_0_PIN  DIO_u8_PIN_0
#define KPD_u8_ROW_1_PIN  DIO_u8_PIN_1
#define KPD_u8_ROW_2_PIN  DIO_u8_PIN_2
#define KPD_u8_ROW_3_PIN  DIO_u8_PIN_3

#define KDP_u8_COLS_PORT  GROUP_A

#define KPD_u8_COL_0_PIN  DIO_u8_PIN_4
#define KPD_u8_COL_1_PIN  DIO_u8_PIN_5
#define KPD_u8_COL_2_PIN  DIO_u8_PIN_6
#define KPD_u8_COL_3_PIN  DIO_u8_PIN_7

#endif /* KEYPAD_CONFIG_H_ */
