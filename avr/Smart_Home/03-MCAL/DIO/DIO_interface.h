/*
 * DIO_interface.h
 *
 *  Created on: Aug 11, 2024
 *      Author: eng_youssef_goher
 */

#ifndef __MCAL_DIO_DIO_INTERFACE_H_
#define __MCAL_DIO_DIO_INTERFACE_H_

typedef struct
{
    volatile u8 PIN;
    volatile u8 DDR;
    volatile u8 PORT;
}DIO_T;


#define DIOA   			((DIO_T *)0x39)
#define DIOB   			((DIO_T *)0x36)
#define DIOC   			((DIO_T *)0x33)
#define DIOD  			((DIO_T *)0x30)

#define DIO_PIN0		(0x01U)
#define DIO_PIN1		(0x02U)
#define DIO_PIN2		(0x04U)
#define DIO_PIN3		(0x08U)
#define DIO_PIN4		(0x10U)
#define DIO_PIN5		(0x20U)
#define DIO_PIN6		(0x40U)
#define DIO_PIN7		(0x80U)

#define DIO_ALL_PINS	(0xFFU)

#define DIO_HIGH		(0xFFU)
#define DIO_LOW			(0x00U)

#define DIO_INPUT		(0x00U)
#define DIO_OUTPUT		(0xFFU)

void 	DIO_voidIniPins			(DIO_T * DIOx,u8 copy_u8PinsID,u8 copy_u8State);
void 	DIO_voidSetPinsValue	(DIO_T * DIOx,u8 copy_u8PinsID,u8 copy_u8Value);
u8 		DIO_u8GetPinsValue		(DIO_T * DIOx,u8 copy_u8PinsID);
void 	DIO_voidTogglePins		(DIO_T * DIOx,u8 copy_u8PinsID);
void 	DIO_voidSetPortValue	(DIO_T * DIOx,u8 copy_u8PortValue);
#endif /* 03_MCAL_DIO_DIO_INTERFACE_H_ */
