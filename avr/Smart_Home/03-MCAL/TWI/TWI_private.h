/*
 * TWI_private.h
 *
 *  Created on: Aug 8, 2024
 *      Author: eng_youssef_goher
 */

#ifndef __MCAL_TWI_TWI_PRIVATE_H_
#define __MCAL_TWI_TWI_PRIVATE_H_

typedef struct {
	__IO u8 TWBR;
	__IO u8 TWSR;
	__IO u8 TWAR;
	__IO u8 TWDR;
	__IO u8 RES[50];
	__IO u8 TWCR;

}TWI_T;

#define TWI 	((__IO TWI_T *)(0x20))


enum{
	TWINT=7,
	TWEA=6,
	TWSTA=5,
	TWSTO=4,
	TWWC=3,
	TWEN=2,
	TWIE=0,
};
/* Master */
/** TWI_START
    start condition transmitted */
#define TWI_START						0x08

/** TWI_REP_START
    repeated start condition transmitted */
#define TWI_REP_START					0x10

/* Master Transmitter */
/** TWI_MT_SLA_ACK
    SLA+W transmitted, ACK received */
#define TWI_MT_SLA_ACK					0x18

/** TWI_MT_SLA_NACK
    SLA+W transmitted, NACK received */
#define TWI_MT_SLA_NACK					0x20

/** TWI_MT_DATA_ACK
    data transmitted, ACK received */
#define TWI_MT_DATA_ACK					0x28

/** TWI_MT_DATA_NACK
    data transmitted, NACK received */
#define TWI_MT_DATA_NACK				0x30

/** TWI_MT_ARB_LOST
    arbitration lost in SLA+W or data */
#define TWI_MT_ARB_LOST					0x38

/* Master Receiver */
/** TWI_MR_ARB_LOST
    arbitration lost in SLA+R or NACK */
#define TWI_MR_ARB_LOST					0x38

/** TWI_MR_SLA_ACK
    SLA+R transmitted, ACK received */
#define TWI_MR_SLA_ACK					0x40

/** TWI_MR_SLA_NACK
    SLA+R transmitted, NACK received */
#define TWI_MR_SLA_NACK					0x48

/** TWI_MR_DATA_ACK
    data received, ACK returned */
#define TWI_MR_DATA_ACK					0x50

/** TWI_MR_DATA_NACK
    data received, NACK returned */
#define TWI_MR_DATA_NACK				0x58

/* Slave Transmitter */
/** TWI_ST_SLA_ACK
    SLA+R received, ACK returned */
#define TWI_ST_SLA_ACK					0xA8

/** TWI_ST_ARB_LOST_SLA_ACK
    arbitration lost in SLA+RW, SLA+R received, ACK returned */
#define TWI_ST_ARB_LOST_SLA_ACK			0xB0

/** TWI_ST_DATA_ACK
    data transmitted, ACK received */
#define TWI_ST_DATA_ACK					0xB8

/** TWI_ST_DATA_NACK
    data transmitted, NACK received */
#define TWI_ST_DATA_NACK				0xC0

/** TWI_ST_LAST_DATA
    last data byte transmitted, ACK received */
#define TWI_ST_LAST_DATA				0xC8

/* Slave Receiver */
/** TWI_SR_SLA_ACK
    SLA+W received, ACK returned */
#define TWI_SR_SLA_ACK					0x60

/** TWI_SR_ARB_LOST_SLA_ACK
    arbitration lost in SLA+RW, SLA+W received, ACK returned */
#define TWI_SR_ARB_LOST_SLA_ACK			0x68

/** TWI_SR_GCALL_ACK
    general call received, ACK returned */
#define TWI_SR_GCALL_ACK				0x70

/** TWI_SR_ARB_LOST_GCALL_ACK
    arbitration lost in SLA+RW, general call received, ACK returned */
#define TWI_SR_ARB_LOST_GCALL_ACK 		0x78

/** TWI_SR_DATA_ACK
    data received, ACK returned */
#define TWI_SR_DATA_ACK					0x80

/** TWI_SR_DATA_NACK
    data received, NACK returned */
#define TWI_SR_DATA_NACK				0x88

/** TWI_SR_GCALL_DATA_ACK
    general call data received, ACK returned */
#define TWI_SR_GCALL_DATA_ACK			0x90

/** TWI_SR_GCALL_DATA_NACK
    general call data received, NACK returned */
#define TWI_SR_GCALL_DATA_NACK			0x98

/** TWI_SR_STOP
    stop or repeated start condition received while selected */
#define TWI_SR_STOP						0xA0

/* Misc */
/** TWI_NO_INFO
    no state information available */
#define TWI_NO_INFO						0xF8

/** TWI_BUS_ERROR
    illegal start or stop condition */
#define TWI_BUS_ERROR					0x00

/**
 * TWI_STATUS_MASK
 * The lower 3 bits of TWSR are reserved on the ATmega163.
 * The 2 LSB carry the prescaler bits on the newer ATmegas.
 */
#define TWI_STATUS_MASK					(0XF8U)

/**
 * TWI_STATUS
 *
 * TWSR, masked by TW_STATUS_MASK
 */
#define TWI_STATUS						((TWI->TWSR) & TWI_STATUS_MASK)


/**	TWI_READ
    SLA+R address */
#define TWI_READ						1

/** TWI_WRITE
    SLA+W address */
#define TWI_WRITE						0

#endif /* 03_MCAL_TWI_TWI_PRIVATE_H_ */
