/*
 * DIO.h
 *
 *  Created on: Nov 20, 2022
 *      Author: Almodather
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_


#define GROUP_A		0
#define GROUP_B		1
#define GROUP_C		2
#define GROUP_D		3


#define DIO_u8_PIN_0	0
#define DIO_u8_PIN_1	1
#define DIO_u8_PIN_2	2
#define DIO_u8_PIN_3	3
#define DIO_u8_PIN_4	4
#define DIO_u8_PIN_5	5
#define DIO_u8_PIN_6	6
#define DIO_u8_PIN_7	7
#define ALL_PINS  		0b11111111

#define DIO_u8_HIGH		1
#define DIO_u8_LOW		0

#define DIO_u8_ERROR_INIT_VAl	0
#define DIO_u8_PORT_ID_ERROR	3
#define DIO_u8_PIN_ID_ERROR		6
#define DIO_u8_PIN_VAL_ERROR	9
#define DIO_u8_PIN_DIR_ERROR	12
#define DIO_u8_PORT_VAL_ERROR	15
#define DIO_u8_PORT_DIR_ERROR	18

#define DIO_u8_INPUT	0
#define DIO_u8_OUTPUT	1



u8 DIO_u8set_port_dir  (u8 Copy_u8_port_ID,u8 Copy_u8_port_dir);
u8 DIO_u8set_port_value(u8 Copy_u8_port_ID,u8 Copy_u8_port_val);
u8 DIO_u8set_pin_value (u8 Copy_u8_port_ID,u8 Copy_u8_pin_ID,u8 Copy_u8_pin_val);
u8 DIO_u8set_pin_dir   (u8 Copy_u8_port_ID,u8 Copy_u8_pin_ID,u8 Copy_u8_pin_dir);


u8 DIO_u8get_pin_value(u8 Copy_u8_port_ID,u8 Copy_u8_pin_ID,u8 *Copy_u8_pin_val);
u8 DIO_u8Get_port_value(u8 Copy_u8_port_ID,u8 *Copy_u8_port_val);
// name_return type_restof name     Copy_type_restofname
#endif /* DIO_INTERFACE_H_ */
