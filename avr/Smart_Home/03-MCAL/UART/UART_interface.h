/*
 * UART_interface.h
 *
 *  Created on: Aug 7, 2024
 *      Author: eng_youssef_goher
 */

#ifndef __MCAL_UART_UART_INTERFACE_H_
#define __MCAL_UART_UART_INTERFACE_H_

void UART_voidIni(u32 copy_u32BandRate);
void UART_voidTransmit(u8 copy_u8Data);
u8 	 UART_u8Receive(void);
u8	 UART_u8Transceive(u8 copy_u8Data);
void UART_voidTransmitString(u8* ptr_u8Data);

#endif /* 03_MCAL_UART_UART_INTERFACE_H_ */
