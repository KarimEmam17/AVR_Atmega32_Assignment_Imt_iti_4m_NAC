/*
 * LCD_INTERFACE.h
 *
 *  Created on: Nov 25, 2022
 *      Author: Almodather
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_


#define Clear_LCD 0b00000001

void LCD_void_Init(void);
void LCD_void_Write_Cmd(u8 Copy_u8Cmd);
void LCD_void_Write(u8 Copy_u8Val);
void LCD_void_Write_Data(u8 Copy_u8Data);
void LCD_void_set_DDRAM_ADD(u8 Copy_u8DDRAM_ADD);
void LCD_void_Write_String(u8 *Ptr_u8string,u8 Copy_u8x_Pos,u8 Copy_u8y_Pos);
void LCD_void_set_CGRAM_ADD(u8 Copy_u8CGRAM_ADD);
u32  LCD_u8_Count_Num_Digits(u32 Copy_u32_Num_VAL);
void LCD_void_Write_Spaces(u32 Copy_u32_Num_Spaces);

void LCD_void_Write_Num(u32 Copy_u32Num,u8 Copy_u8x_Pos,u8 Copy_u8y_Pos);


#endif /* LCD_INTERFACE_H_ */
