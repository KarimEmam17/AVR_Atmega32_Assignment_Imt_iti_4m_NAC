/*
 * SPI.c
 *
 *  Created on: Jul 15, 2023
 *      Author: Almodather
 */
#include "../STD_LIB/STD_Types.h"
#include "../STD_LIB/util.h"
#include "SPI_PRIVATE.h"
#include "SPI_confg.h"
#include "SPI_interface.h"
/********************************function defition  *****************************/


void  SPI_init(u8 Copy_u8_Master_Slave_Type,u8 Copy_u8_dataOrder,u8 Copy_u8_DataMode, u8 Copy_clkprescaler){


	if(Copy_clkprescaler%2==0)
	{
		set_bit(SPI_SPSR,SPI_SPSR_SPI2X);
	}

	Copy_clkprescaler/=2;

	Assign_Bit(SPI_SPCR,SPI_SPCR_MSTR,Copy_u8_Master_Slave_Type);
	Assign_Bit(SPI_SPCR,SPI_SPCR_DORD,Copy_u8_dataOrder);
	Assign_Bit(SPI_SPCR,SPI_SPCR_CPHA,Copy_u8_DataMode);


	SPI_SPCR|=Copy_clkprescaler;
	set_bit(SPI_SPCR,SPI_SPCR_SPE);


}

void SPI_MasterSendRecv(u8 Copy_u8_SendData,u8* PTR_RecvData){

	SPI_SPDR=Copy_u8_SendData;
	while(!get_bit(SPI_SPSR,SPI_SPCR_SPIE));
	*PTR_RecvData=SPI_SPDR;





}

void SPI_SlaveSendRecv(u8 Copy_u8_SendData,u8* PTR_RecvData)
{

	if(get_bit(SPI_SPSR,SPI_SPCR_SPIE))
	{

		*PTR_RecvData=SPI_SPDR;
		SPI_SPDR=Copy_u8_SendData;
	}



}

















