/*
 * UART_private.h
 *
 *  Created on: Aug 7, 2024
 *      Author: eng_youssef_goher
 */

#ifndef __MCAL_UART_UART_PRIVATE_H_
#define __MCAL_UART_UART_PRIVATE_H_



typedef struct {
	__IO u8 UBRRL;
	__IO u8 UCSRB;
	__IO u8 UCSRA;
	__IO u8 UDR;
	__IO u8 Dummy[19];
	__IO u8 UCSRC_UBRRH;
}UART_T;

#define UART  ((__IO UART_T *) 0x29)
/*
 * UCARB
 */
enum{
	RXCIE=7,
	TXCIE=6,
	UDRIE=5,
	RXEN=4,
	TXEN=3,
	UCSZ2=2,
	RXB8=1,
	TXB8=0
};

/*
 * UCSRA
 */
enum{
	 RXC=7,
	 TXC=6,
	 UDRE=5,
	 FE=4,
	 DOR=3,
	 PE=2,
	 U2X=1,
	 MPCM=0
};

enum{
	URSEL=7,
	UMSEL=6,
	UPM1=5,
	UPM0=4,
	USBS=3,
	UCSZ1=2,
	UCSZ0=1,
	UCPOL=0
};

/*
 * Double the USART Transmission Speed
 */
#define UART_DOUBLE_SPEED_ENABLED		1
#define UART_DOUBLE_SPEED_DISABLED		2

/*
 * USART Receive
 */
#define UART_RECEIVE_ENABLED			3
#define UART_RECEIVE_DISABLED			4

/*
 * USART Transmit
 */
#define UART_TRANSMIT_ENABLED			5
#define UART_TRANSMIT_DISABLED			6



#endif /* 03_MCAL_UART_UART_PRIVATE_H_ */
