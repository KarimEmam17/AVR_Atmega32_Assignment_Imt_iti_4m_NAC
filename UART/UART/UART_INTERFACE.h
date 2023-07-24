/*
 * UART_INTERFACE.h
 *
 *  Created on: Feb 6, 2023
 *      Author: Almodather
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_







/*************************************************MACROS*********************************************/

#define UART_2400_BPS		207
#define UART_4800_BPS		103
#define UART_9600_BPS		51
#define UART_19200_BPS		25
#define UART_115200_BPS		3


/********************* UART functions***********************************/
void UART_INIT(u16 COPY_u16_baudRATE);

void UART_SENDBYTE(u8  COPY_u8_DATABYTE);

void UART_RECEVBYTE(u8 *PTR_DATABYTE);

void UART_SENDSTREAM(u8  *PTR_u8_DATABYTE,u8 COPY_u8_DATA_SIZE);



#endif /* UART_INTERFACE_H_ */
