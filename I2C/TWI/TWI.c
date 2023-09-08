/*
 * TWI.c
 *
 *  Created on: Jul 23, 2023
 *      Author: Almodather
 */


#include "../STD_LIB/STD_Types.h"
#include "../STD_LIB/util.h"
#include "TWI_PRIVATE.h"
#include "TWI_config.h"
#include "TWI_interface.h"


/**********************function defintion ****************************/
void TWI_INIT()
{
	TWI_TWSR=0;

	TWI_TWBR=32;

}
//Copy_u8_ReadWrite bit  choose  the status  if  it is read or  write  from  slave
void TWI_START(u8 Copy_u8_SlaveAddress,u8 Copy_u8_ReadWrite)
{
set_bit(TWI_TWCR,TWI_TWCR_TWINT);
set_bit(TWI_TWCR,TWI_TWCR_TWSTA);
set_bit(TWI_TWCR,TWI_TWCR_TWEN);

while ((TWI_TWSR !=0x08) && (TWI_TWSR != 0x10));
TWI_TWDR=(Copy_u8_SlaveAddress<<1)|Copy_u8_ReadWrite;

set_bit(TWI_TWCR,TWI_TWCR_TWINT);
set_bit(TWI_TWCR,TWI_TWCR_TWEN);

switch(Copy_u8_ReadWrite)
{
	case Slave_Write:
		while ((TWI_TWSR !=0x18) && (!get_bit(TWI_TWCR,TWI_TWCR_TWINT)));
		break;

	case Slave_Read:
		while ((TWI_TWSR !=0x40) && (!get_bit(TWI_TWCR,TWI_TWCR_TWINT)));
		break;
}
}
void TWI_MasterSend_byte(u8 Copy_u8_DataByte)
{
	 TWI_TWDR=Copy_u8_DataByte;
	 set_bit(TWI_TWCR,TWI_TWCR_TWINT);
	 set_bit(TWI_TWCR,TWI_TWCR_TWEN);
	 while ((TWI_TWSR !=0x28) && (!get_bit(TWI_TWCR,TWI_TWCR_TWINT)));

}


void TWI_MasterRecive_byte_With_ACK(u8* Copy_u8_DataByte)
{

	set_bit(TWI_TWCR,TWI_TWCR_TWINT);
	set_bit(TWI_TWCR,TWI_TWCR_TWEA);
	set_bit(TWI_TWCR,TWI_TWCR_TWEN);
	while ((TWI_TWSR !=0x50) && (!get_bit(TWI_TWCR,TWI_TWCR_TWINT)));
	*Copy_u8_DataByte=TWI_TWDR;


}


void TWI_MasterRecive_byte_With_NACK(u8* Copy_u8_DataByte)
{

	set_bit(TWI_TWCR,TWI_TWCR_TWINT);
	set_bit(TWI_TWCR,TWI_TWCR_TWEN);
	while ( (!get_bit(TWI_TWCR,TWI_TWCR_TWINT)));
	*Copy_u8_DataByte=TWI_TWDR;



}

void TWI_Stop()
{

	set_bit(TWI_TWCR,TWI_TWCR_TWINT);
	set_bit(TWI_TWCR,TWI_TWCR_TWSTO);
	set_bit(TWI_TWCR,TWI_TWCR_TWEN);

	while (!get_bit(TWI_TWCR,TWI_TWCR_TWSTO));


}







