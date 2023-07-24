/*
 * SPI_INTERFACE.h
 *
 *  Created on: Jul 15, 2023
 *      Author: Almodather
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_


/***************************************************interface  macros ********************************************************/
										/***********Master/Slave  types************************/
#define SLAVE_TYPE				0
#define Master_TYPE 			1
										/**********Data order**********************************/
#define MSB_FIRST               0
#define LSB_FIRST				1
										/**********Data Mode***********************************/
#define SAMPLE_R_SETUP_F		0
#define SETUP_R_SAMPLE_F		1
#define SAMPLE_F_SETUP_R		2
#define SETUP_F_SAMPLE_R		3
										/********clock  pre-scalars***************************/
#define SPI_PRESCALER_2			0
#define SPI_PRESCALER_4			1
#define SPI_PRESCALER_8			2
#define SPI_PRESCALER_16		3
#define SPI_PRESCALER_32		4
#define SPI_PRESCALER_64		5
#define SPI_PRESCALER_128		7


/*******************SPI Functions prototype ****************/

void  SPI_init(u8 Copy_u8_Master_Slave_Type,u8 Copy_u8_dataOrder,u8 Copy_u8_DataMode, u8 Copy_clkprescaler);

void SPI_MasterSendRecv(u8 Copy_u8_SendData,u8* PTR_RecvData);

void SPI_SlaveSendRecv(u8 Copy_u8_SendData,u8* PTR_RecvData);




#endif /* SPI_INTERFACE_H_ */
