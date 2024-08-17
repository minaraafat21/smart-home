/*
 * DIO_program.c
 *
 *  Created on: Aug 11, 2024
 *      Author: eng_youssef_goher
 */

#include	"../../00-LIB/LSTD_types.h"
#include	"DIO_interface.h"

void 	DIO_voidIniPins			(DIO_T * DIOx,u8 copy_u8PinsID,u8 copy_u8State){
	DIOx->DDR	&= ~(copy_u8PinsID);
	DIOx->DDR	|=	(copy_u8PinsID & copy_u8State);
}
void 	DIO_voidSetPinsValue	(DIO_T * DIOx,u8 copy_u8PinsID,u8 copy_u8Value){
	DIOx->PORT	&= ~(copy_u8PinsID);
	DIOx->PORT	|=	(copy_u8PinsID & copy_u8Value);
}
u8 		DIO_u8GetPinsValue		(DIO_T * DIOx,u8 copy_u8PinsID){
	return (DIOx->PIN	& copy_u8PinsID);
}
void 	DIO_voidTogglePins		(DIO_T * DIOx,u8 copy_u8PinsID){
	DIOx->PORT ^= copy_u8PinsID;
}
void 	DIO_voidSetPortValue	(DIO_T * DIOx,u8 copy_u8PortValue){
	DIOx->PORT=copy_u8PortValue;
}
