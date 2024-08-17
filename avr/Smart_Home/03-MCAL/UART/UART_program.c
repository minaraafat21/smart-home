/*
 * UART_program.c
 *
 *  Created on: Aug 7, 2024
 *      Author: eng_youssef_goher
 */

#include "../../00-LIB/LSTD_types.h"
#include "../../00-LIB/LBIT_math.h"

#include "UART_private.h"
#include "UART_config.h"
#include "UART_interface.h"
//UART
void UART_voidIni(u32 copy_u32BandRate){
	u16 UBRR_vlue=0;
	#if(UART_DOUBLE_SPEED==UART_DOUBLE_SPEED_ENABLED)
	SET_BIT(UART->UCSRA, U2X);
	#elif(UART_DOUBLE_SPEED==UART_DOUBLE_SPEED_DISABLED)
	CLR_BIT(UART->UCSRA, U2X);
	#else
	#error "wrong configration for UART_DOUBLE_SPEED"
	#endif
	#if(UART_RECEIVE==UART_RECEIVE_ENABLED)
	SET_BIT(UART->UCSRB,RXEN);
	#elif(UART_RECEIVE==UART_RECEIVE_DISABLED)
	CLR_BIT(UART->UCSRB,RXEN);
	#else
	#error "wrong configration for UART_RECEIVE"
	#endif
	#if(UART_TRANSMIT==UART_TRANSMIT_ENABLED)
	SET_BIT(UART->UCSRB,TXEN);
	#elif(UART_TRANSMIT==UART_TRANSMIT_DISABLED)
	CLR_BIT(UART->UCSRB,TXEN);
	#else
	#error "wrong configration for UART_TRANSMIT"
	#endif
	//select UCSRC
	SET_BIT(UART->UCSRC_UBRRH,URSEL);
	//select Asynchronous Operation
	CLR_BIT(UART->UCSRC_UBRRH, UMSEL);
	//select Parity Mode Disabled
	CLR_BIT(UART->UCSRC_UBRRH,UPM0);
	CLR_BIT(UART->UCSRC_UBRRH,UPM1);
	//SELECT Stop Bit Select
	CLR_BIT(UART->UCSRC_UBRRH,USBS);
	//Select Character Size 8-bit
	SET_BIT(UART->UCSRC_UBRRH,UCSZ0);
	SET_BIT(UART->UCSRC_UBRRH,UCSZ1);
	CLR_BIT(UART->UCSRB,UCSZ2);
	/*
	 * Equations for Calculating Baud Rate Register Setting
	 */
	#if(UART_DOUBLE_SPEED==UART_DOUBLE_SPEED_ENABLED)
	UBRR_vlue=((UART_CPU_F_MHZ*1E6)/(8*copy_u32BandRate))-1;
	#elif(UART_DOUBLE_SPEED==UART_DOUBLE_SPEED_DISABLED)
	UBRR_vlue=((UART_CPU_F_MHZ*1E6)/(16*copy_u32BandRate))-1;
	#else
	#error "wrong configration for UART_DOUBLE_SPEED"
	#endif
	UART->UBRRL=UBRR_vlue;
	//select UBRRH
	CLR_BIT(UART->UCSRC_UBRRH,URSEL);
	UART->UCSRC_UBRRH=((UBRR_vlue>>8)&(0x0F));
}
void UART_voidTransmit(u8 copy_u8Data){
	while(GET_BIT(UART->UCSRA,UDRE)==0);
	UART->UDR=copy_u8Data;
	while(GET_BIT(UART->UCSRA,TXC)==0);
}
u8 	 UART_u8Receive(void){
	#if(UART_RECEIVE==UART_RECEIVE_ENABLED)
	while(GET_BIT(UART->UCSRA,RXC)==0);
	#endif
	return UART->UDR;
}
u8	 UART_u8Transceive(u8 copy_u8Data){
	UART_voidTransmit(copy_u8Data);
	return UART_u8Receive();
}
void UART_voidTransmitString(u8* ptr_u8Data){
	u32 local_u32Counter=0;
	for(local_u32Counter=0;ptr_u8Data[local_u32Counter]!='\0';local_u32Counter++){
		UART_voidTransmit(ptr_u8Data[local_u32Counter]);
	}
}
