/*
 * TWI_program.c
 *
 *  Created on: Aug 8, 2024
 *      Author: eng_youssef_goher
 */
#include "../../00-LIB/LSTD_types.h"
#include "../../00-LIB/LBIT_math.h"

#include "TWI_private.h"
#include "TWI_config.h"
#include "TWI_interface.h"

#define TWI_MAX_SPEED	((f32)TWI_CPU_FREQUENCY_HZ/(f32)16)
#define TWI_MIN_SPEED	((f32)TWI_CPU_FREQUENCY_HZ/(f32)2056)
/*
 * TWI_voidInit()
 *
 * Set up the TWI module in the processor for I2C master mode.  SCL rate will
 * be a maximum of 500kHz if the CPU frequency is 8MHz.
 */
void TWI_voidInit(u32 copy_u32TWISpeed){
	//select Prescaler =1
	TWI->TWSR 	&=	0XFC; //make the 3LSB=0 "TWPS1 TWPS0" also you can use 0b11111100

	//select speed of TWI
	if(copy_u32TWISpeed>TWI_MAX_SPEED){
		TWI->TWBR	=	0;
	}
	else if(copy_u32TWISpeed<TWI_MIN_SPEED){
		TWI->TWBR	=	0xFF;
	}
	else{
		TWI->TWBR	= (u8)((((f32)TWI_CPU_FREQUENCY_HZ/copy_u32TWISpeed)-16)/2);
	}
	SET_BIT(TWI->TWCR,TWEN);
}

/*
 * TWI_u8Start()
 *
 * Generate a Start condition on the I2C bus.  Returns an error code if the bus
 * is not idle.
 */
ErrorState TWI_ErrorStateStart(void){
	TWI->TWCR	=		BIT_VLE(TWEN)|BIT_VLE(TWINT)|BIT_VLE(TWSTA);
	while(GET_BIT(TWI->TWCR,TWINT)==0); // wait until TWI end its job
	switch(TWI_STATUS){
	case TWI_START:
	case TWI_REP_START:
		return PASS;
		break;
	default:
		return FAIL;
		break;

	}
}

/*
 * TWI_voidStop()
 *
 * Generate a Stop condition on the I2C bus.
 */
void TWI_voidStop(void){
	TWI->TWCR	=		BIT_VLE(TWEN)|BIT_VLE(TWINT)|BIT_VLE(TWSTO);
	while(GET_BIT(TWI->TWCR,TWSTO)==1); // wait until TWI end its job When the STOP condition is executed on the bus, the TWSTO bit is cleared
}

/*
 * TWI_u8PutChar()
 *
 * Put a byte on the I2C bus.  Returns an error code if the bus is not idle.
 */
ErrorState TWI_ErrorStatePutChar(u8 copy_u8Data){
	TWI->TWDR=copy_u8Data;
	TWI->TWCR	=		BIT_VLE(TWEN)|BIT_VLE(TWINT);
	while(GET_BIT(TWI->TWCR,TWINT)==0); // wait until TWI end its job
	switch(TWI_STATUS){
		case TWI_MT_SLA_ACK:
		case TWI_MT_DATA_ACK:
		case TWI_MR_SLA_ACK:
			return PASS;
			break;
		default:
			return FAIL;
			break;
	}

}

/*
 * TWI_u8GetCharAck()
 *
 * Receive a byte from then put an Acknowledge on the I2C bus.
 */
u8 TWI_u8GetCharAck(void){
	TWI->TWCR	=		BIT_VLE(TWEN)|BIT_VLE(TWINT)|BIT_VLE(TWEA);
	while(GET_BIT(TWI->TWCR,TWINT)==0); // wait until TWI end its job
	return TWI->TWDR;
}

/*
 * TWI_u8GetCharNack()
 *
 * Receive a byte from then put a Not Acknowledge on the I2C bus.
 */
u8 TWI_u8GetCharNack(void){
		TWI->TWCR	=	BIT_VLE(TWEN)|BIT_VLE(TWINT);
		while(GET_BIT(TWI->TWCR,TWINT)==0); // wait until TWI end its job
		return TWI->TWDR;
}

/*
 * TWI_u8Write()
 *
 * Write a number of data bytes the I2C slave device.
 *
 * The steps below are followed:
 *
 *       1. Apply a Start condition on the bus
 *       2. Put the slave device address with bit-0 = 0 onto the bus
 *       3. Put the byte address to write to on the bus
 *       4. Put a data byte onto the bus
 *       5. Repeat step 5 for all data bytes
 *       6. Apply a Stop condition on the bus
 */
ErrorState TWI_ErrorStateWrite(
    u8 copy_u8SlaveAdrs,  	/* Device slave address */
    u8 copy_u8Len,			/* Number of bytes to write */
    u8 copy_u8adrs,			/* Device register to start writing to */
    u8 *ptr_u8buf			/* RAM address of the bytes to write */
) {
    u8 local_u8RestartsCounter = MAX_RESTARTS;
    u8 local_u8DataCounter = 0;

    // Check for a valid length
    if (copy_u8Len <= 0) {
        return PASS;
    } else {
        // Attempt to write the data, retrying if necessary
        for (local_u8RestartsCounter = MAX_RESTARTS; local_u8RestartsCounter > 0; local_u8RestartsCounter--) {
            if (TWI_ErrorStateStart() == PASS) {
                // Send the slave address with the write flag
                if (TWI_ErrorStatePutChar((copy_u8SlaveAdrs << 1) | TWI_WRITE) == PASS) {
                    // Send the device register address
                    if (TWI_ErrorStatePutChar(copy_u8adrs) == PASS) {
                        // Write the data bytes
                        for (local_u8DataCounter = 0; local_u8DataCounter < copy_u8Len; local_u8DataCounter++) {
                            if (TWI_ErrorStatePutChar(ptr_u8buf[local_u8DataCounter]) == FAIL) {
                                return FAIL;  // Stop on failure
                            }
                        }
                        TWI_voidStop();  // Stop the communication
                        return PASS;     // Indicate success
                    } else {
                        continue;  // Retry on failure
                    }
                } else {
                    continue;  // Retry on failure
                }
            } else {
                continue;  // Retry on failure
            }
        }
    }

    return FAIL;  // Indicate failure after all retries
}

/*
 * TWI_u8Read()
 *
 * Random read.  Read len data bytes from the I2C slave device to buf starting at
 * the device word address.
 *
 * The steps below are followed:
 *
 *   1.  Apply a Start condition on the bus
 *   2.  Put the Slave Device address with bit0 = 0 (write) onto the bus
 *   3.  Put the byte address to read from on the bus
 *   4.  Apply a Repeated Start condition on the bus
 *   5.  Receive a data byte from the bus and apply an Acknowledge
 *   6.  Repeat step 5 for all data bytes except last one
 *   7.  Receive the last data byte from the bus and apply a Not Acknowledge
 *   8.  Apply a Stop condition on the bus
 */
ErrorState TWI_ErrorStateRead(
    u8 copy_u8SlaveAdrs,	/* Device slave address */
    u8 copy_u8Len,			/* Number of bytes to read */
    u8 copy_u8adrs,			/* Device register to start reading from */
    u8 *ptr_u8buf			/* RAM address of where to put read bytes */
) {
    u8 local_u8RestartsCounter = MAX_RESTARTS;
    u8 local_u8DataCounter = 0;

    // Check for a valid length
    if (copy_u8Len <= 0) {
        return PASS;
    } else {
        // Attempt to read the data, retrying if necessary
        for (local_u8RestartsCounter = MAX_RESTARTS; local_u8RestartsCounter > 0; local_u8RestartsCounter--) {
            if (TWI_ErrorStateStart() == PASS) {
                // Send the slave address with the write flag
                if (TWI_ErrorStatePutChar((copy_u8SlaveAdrs << 1) | TWI_WRITE) == PASS) {
                    // Send the device register address
                    if (TWI_ErrorStatePutChar(copy_u8adrs) == PASS) {
                        // Restart and send the slave address with the read flag
                        if (TWI_ErrorStateStart() == PASS) {
                            if (TWI_ErrorStatePutChar((copy_u8SlaveAdrs << 1) | TWI_READ) == PASS) {
                                // Read the data bytes
                                for (local_u8DataCounter = 0; local_u8DataCounter < copy_u8Len - 1; local_u8DataCounter++) {
                                    ptr_u8buf[local_u8DataCounter] = TWI_u8GetCharAck();
                                }
                                // Read the last byte with NACK
                                ptr_u8buf[local_u8DataCounter] = TWI_u8GetCharNack();
                                TWI_voidStop();  // Stop the communication
                                return PASS;     // Indicate success
                            } else {
                                continue;  // Retry on failure
                            }
                        } else {
                            continue;  // Retry on failure
                        }
                    } else {
                        continue;  // Retry on failure
                    }
                } else {
                    continue;  // Retry on failure
                }
            } else {
                continue;  // Retry on failure
            }
        }
    }

    return FAIL;  // Indicate failure after all retries
}

