/*
 * TWI_PRIVATE.h
 *
 *  Created on: Jul 23, 2023
 *      Author: Almodather
 */

#ifndef TWI_PRIVATE_H_
#define TWI_PRIVATE_H_

/***********************TWI Registers *******************************************/
#define TWI_TWCR	*((volatile u8*)0x56)
#define TWI_TWDR	*((volatile u8*)0x23)
#define TWI_TWAR	*((volatile u8*)0x22)
#define TWI_TWSR	*((volatile u8*)0x21)
#define TWI_TWBR	*((volatile u8*)0x20)

/**********************TWI Regesters's bits**************************************/
#define TWI_TWAR_TWA6	7
#define TWI_TWAR_TWA5 	6
#define TWI_TWAR_TWA4	5
#define TWI_TWAR_TWA3	4
#define TWI_TWAR_TWA2	3
#define TWI_TWAR_TWA1	2
#define TWI_TWAR_TWA0	1
#define TWI_TWAR_TWGCE	0

#define TWI_TWSR_TWS7	7
#define TWI_TWSR_TWS6 	6
#define TWI_TWSR_TWS5 	5
#define TWI_TWSR_TWS4	4
#define TWI_TWSR_TWS3	3
#define TWI_TWSR_TWPS1	1
#define TWI_TWSR_TWPS0	0

#define TWI_TWCR_TWINT	7
#define TWI_TWCR_TWEA	6
#define TWI_TWCR_TWSTA	5
#define TWI_TWCR_TWSTO	4
#define TWI_TWCR_TWWC	3
#define TWI_TWCR_TWEN	2
#define TWI_TWCR_TWIE	0

#endif /* TWI_PRIVATE_H_ */
