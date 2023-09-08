/*
 * TWI_INTERFACE.h
 *
 *  Created on: Jul 23, 2023
 *      Author: Almodather
 */

#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_

#define Slave_Write		0
#define Slave_Read		1





// this  function  is  use  TWI  with 10khz speed
void TWI_INIT();

void TWI_START(u8 Copy_u8_SlaveAddress,u8 Copy_u8_ReadWrite);//Copy_u8_ReadWrite bit  choose  the status  if  it is read or  write  from  slave

void TWI_MasterSend_byte(u8 Copy_u8_DataByte);


void TWI_MasterRecive_byte_With_ACK(u8* Copy_u8_DataByte);

void TWI_MasterRecive_byte_With_NACK(u8* Copy_u8_DataByte);

void TWI_Stop();























#endif /* TWI_INTERFACE_H_ */
