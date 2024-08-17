/*
 * SPI_Private.h
 *
 *  Created on: Aug 8, 2024
 *      Author: hikal
 */

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

typedef struct{
	__IO u8 SPCR;
	__IO u8 SPSR;
	__IO u8 SPDR;
}SPI_T;

#define SPI ((__IO SPI_T *)0x2D)

enum{
	SPIE	=	7,
	SPE		=	6,
	DORD	=	5,
	MSTR	=	4,
	CPOL	=	3,
	CPHA	=	2,
	SPR1	=	1,
	SPR0	=	0,
};

enum{
	 SPIF	= 	7,
	 WCOL	= 	6,
	 SPI2X	=	0,
};

/*
 *  options For  Data Order
 */
#define SPI_DATA_ORDER_MSB_TRANSMITTED_FIRST		1
#define SPI_DATA_ORDER_LSB_TRANSMITTED_FIRST		2

/*
 * MASTER SLAVE
 */
#define SPI_MODE_SELECT_MASTER						3
#define SPI_MODE_SELECT_SLAVE						4

/*
 * Clock Polarity
 */
#define SPI_CLOCK_POLARITY_IDEAL_LOW				5
#define SPI_CLOCK_POLARITY_IDEAL_HIGH				6

/*
 * Clock Phase
 */
#define SPI_CLOCK_PHASE_SAMPLE_LEADING				7
#define SPI_CLOCK_PHASE_SAMPLE_TRAILING				8


#endif /* SPI_PRIVATE_H_ */
