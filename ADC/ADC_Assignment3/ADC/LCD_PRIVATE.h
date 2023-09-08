/*
 * LCD_PRIVATE.h
 *
 *  Created on: Nov 25, 2022
 *      Author: Almodather
 */

#ifndef LCD_PRIVATE_H_
#define LCD_PRIVATE_H_

#define  LCD_u8_RS_CMD			0
#define  LCD_u8_RS_DATA			1

#define LCD_u8_RW_WRITE			0
#define LCD_u8_RW_READ			1


#define LCD_u8_DDRAM_ADD_MASK 	   		0b10000000 /// busy flag
#define LCD_u8_CGRAM_ADD_MASK 	   		0b01000000 //
#define LCD_u8_DDRAM_ADD_LINE_MASK 		64

#endif /* LCD_PRIVATE_H_ */
