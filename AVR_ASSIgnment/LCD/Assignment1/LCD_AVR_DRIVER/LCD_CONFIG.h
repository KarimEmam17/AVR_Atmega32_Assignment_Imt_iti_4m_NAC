/*
 * LCD_CONFIG.h
 *
 *  Created on: Nov 25, 2022
 *      Author: Almodather
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#define LCD_4Bit_Mode 			0
#define LCD_8Bit_Mode 			1
#define LCD_Selected_Mode		LCD_4Bit_Mode

#define LCD_FIRST_3PIN_IN_CTRL_PORT_IN_4PIN_MODE	0b00000111
#define LCD_LAST_3PIN_IN_CTRL_PORT_IN_4PIN_MODE		0b11100000
#define LCD_3PIN_IN_CTRL_PORT_IN_4PIN_MODE			LCD_FIRST_3PIN_IN_CTRL_PORT_IN_4PIN_MODE

#define LCD_FIRST_4PIN_IN_DATA_PORT_IN_4PIN_MODE	0b00001111
#define LCD_LAST_4PIN_IN_DATA_PORT_IN_4PIN_MODE		0b11110000
#define LCD_4PIN_IN_DATA_PORT_IN_4PIN_MODE			LCD_LAST_4PIN_IN_DATA_PORT_IN_4PIN_MODE


#define  LCD_u8_CTRL_PORT		GROUP_C
#define  LCD_u8_RS_PIN			DIO_u8_PIN_0
#define  LCD_u8_RW_PIN			DIO_u8_PIN_1
#define  LCD_u8_ENABLE_PIN		DIO_u8_PIN_2

#define  LCD_u8_DATA_PORT		GROUP_D
#define  LCD_u8_DATA_PIN_0		DIO_u8_PIN_0
#define  LCD_u8_DATA_PIN_1		DIO_u8_PIN_1
#define  LCD_u8_DATA_PIN_2		DIO_u8_PIN_2
#define  LCD_u8_DATA_PIN_3		DIO_u8_PIN_3
#define  LCD_u8_DATA_PIN_4		DIO_u8_PIN_4
#define  LCD_u8_DATA_PIN_5		DIO_u8_PIN_5
#define  LCD_u8_DATA_PIN_6		DIO_u8_PIN_6
#define  LCD_u8_DATA_PIN_7		DIO_u8_PIN_7


#endif /* LCD_CONFIG_H_ */
