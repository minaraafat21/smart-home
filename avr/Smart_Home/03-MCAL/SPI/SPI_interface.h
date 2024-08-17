/*
 * SPI_Interface.h
 *
 *  Created on: Aug 8, 2024
 *      Author: hikal
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

typedef enum{
	fosc_div_2,
	fosc_div_4,
	fosc_div_8,
	fosc_div_16,
	fosc_div_32,
	fosc_div_64,
	fosc_div_128,
} ClockDivision;


void SPI_voidInit_Master( ClockDivision copy_ClockDivisionType);
void SPI_voidInit_Slave	(void);
u8   SPI_u8Transcieve(u8 Copy_u8Value);

#endif /* SPI_INTERFACE_H_ */
