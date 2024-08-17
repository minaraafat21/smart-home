/*
 * TWI_interface.h
 *
 *  Created on: Aug 8, 2024
 *      Author: eng_youssef_goher
 */

#ifndef __MCAL_TWI_TWI_INTERFACE_H_
#define __MCAL_TWI_TWI_INTERFACE_H_


/*
 * define an ErrorStates
 */

typedef enum{
	PASS,
	FAIL,
}ErrorState;
/*
 * TWI_voidInit()
 *
 * Set up the TWI module in the processor for I2C master mode.  SCL rate will
 * be a maximum of 500kHz if the CPU frequency is 8MHz.
 */
void TWI_voidInit(u32 copy_u32TWISpeed);

/*
 * TWI_u8Start()
 *
 * Generate a Start condition on the I2C bus.  Returns an error code if the bus
 * is not idle.
 */
ErrorState TWI_ErrorStateStart(void);

/*
 * TWI_voidStop()
 *
 * Generate a Stop condition on the I2C bus.
 */
void TWI_voidStop(void);

/*
 * TWI_u8PutChar()
 *
 * Put a byte on the I2C bus.  Returns an error code if the bus is not idle.
 */
ErrorState TWI_ErrorStatePutChar(u8 copy_u8Data);

/*
 * TWI_u8GetCharAck()
 *
 * Receive a byte from then put an Acknowledge on the I2C bus.
 */
u8 TWI_u8GetCharAck(void);

/*
 * TWI_u8GetCharNack()
 *
 * Receive a byte from then put a Not Acknowledge on the I2C bus.
 */
u8 TWI_u8GetCharNack(void);

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
ErrorState TWI_ErrorStateWrite(u8 copy_u8SlaveAdrs, u8 copy_u8Len, u8 copy_u8adrs, u8 *ptr_u8buf);

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
ErrorState TWI_ErrorStateRead(u8 copy_u8SlaveAdrs, u8 copy_u8Len, u8 copy_u8adrs, u8 *ptr_u8buf);

#endif /* 03_MCAL_TWI_TWI_INTERFACE_H_ */
