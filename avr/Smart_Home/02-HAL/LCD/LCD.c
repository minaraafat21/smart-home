/*
 * LCD.c
 *
 *  Created on: Jul 28, 2024
 *      Author: eng_youssef_goher
 */

#include "../../00-LIB/LSTD_types.h"
#include "../../00-LIB/LBIT_math.h"
#include <avr/io.h>
#include <avr/delay.h>

#include "LCD.h"


void LCD_voidSendData(u8 copy_u8Data){
	//send data make RS_PIN=1
	SET_BIT(LCD_Control_Port,LCD_RS_PIN);
	//write RW=0
	CLR_BIT(LCD_Control_Port,LCD_RW_PIN);
	//enable => high
	SET_BIT(LCD_Control_Port,LCD_E_PIN);
	LCD_Data_Port=copy_u8Data;
	_delay_ms(1);
	//enable => LOW (Caputre Data)
	CLR_BIT(LCD_Control_Port,LCD_E_PIN);
	//delay for multiple call
	_delay_ms(1);
}
void LCD_voidSendCommand(u8 copy_u8Command){
	//send Command make RS_PIN=0
	CLR_BIT(LCD_Control_Port,LCD_RS_PIN);
	//write RW=0
	CLR_BIT(LCD_Control_Port,LCD_RW_PIN);
	//enable => high
	SET_BIT(LCD_Control_Port,LCD_E_PIN);
	LCD_Data_Port=copy_u8Command;
	_delay_ms(2);
	//enable => LOW (Caputre Data)
	CLR_BIT(LCD_Control_Port,LCD_E_PIN);
	//delay for multiple call
	_delay_ms(10);
}

void LCD_voidini(void){
	LCD_Data_DDR=0xFF;
	SET_BIT(LCD_Control_DDR,LCD_RS_PIN);
	SET_BIT(LCD_Control_DDR,LCD_RW_PIN);
	SET_BIT(LCD_Control_DDR,LCD_E_PIN);
	_delay_ms(30);
	LCD_voidSendCommand(LCD_FunictionSet8bit);
	_delay_ms(2);
	LCD_voidSendCommand(Display_ON_Control);
	_delay_ms(2);
	LCD_voidSendCommand(Clear_display);
	_delay_ms(2);
	LCD_voidSendCommand(Entery_mode_set);
	_delay_ms(2);

}
void LCD_voidSetCursorLocation(u8 copy_u8Row,u8 copy_u8Column){
	if((copy_u8Column>=0) &&(copy_u8Column<16)){
	switch(copy_u8Row){
	case 0:
		LCD_voidSendCommand(DDR_ADDRESS+0+copy_u8Column);
	break;
	case 1:
		LCD_voidSendCommand(DDR_ADDRESS+0x40+copy_u8Column);
	break;
	default:
	break;
	}
	}
	else{
		// unvaild column
	}
}
void LCD_voidClearDisplay(void){
	LCD_voidSendCommand(Clear_display);
}
void LCD_voidSaveCustomchar(u8 *ptr_u8toCustomchar,u8 copy_u8SaveLocation);

void LCD_voidwriteString(u8 *ptr_u8toString){
	u8 local_u8counter=0;
	for(local_u8counter=0;ptr_u8toString[local_u8counter]!='\0';local_u8counter++){
		LCD_voidSendData(ptr_u8toString[local_u8counter]);
	}
}

void LCD_voidWriteNumber(u32 copy_u32DataValue) {
    if (copy_u32DataValue == 0) {
        LCD_voidSendData('0');
    } else {
        u8 buffer[11]={0};
        s8 i = 0;

        while (copy_u32DataValue > 0) {
            buffer[i++] = (copy_u32DataValue % 10) + '0';
            copy_u32DataValue /= 10;
        }

        while (i > 0) {
            LCD_voidSendData(buffer[--i]);
        }
    }
}
void LCD_voidWriteFloatNumber(f32 copy_f32DataValue,u8 copy_u8decimalPlaces) {
    // Buffer to hold the integer part and fractional part strings
	u8 buffer[32];
    u32 integerPart = (u32)copy_f32DataValue;
    f32 fractionalPart = copy_f32DataValue - integerPart;
    u8 i = 0;

    // Handle the integer part
    if (integerPart == 0) {
        buffer[i++] = '0';
    } else {
    	u8 intBuffer[11];
    	u8 intIndex = 0;

        if (integerPart < 0) {
            buffer[i++] = '-';
            integerPart = -integerPart;
        }

        while (integerPart > 0) {
            intBuffer[intIndex++] = (integerPart % 10) + '0';
            integerPart /= 10;
        }

        while (intIndex > 0) {
            buffer[i++] = intBuffer[--intIndex];
        }
    }

    // Add the decimal point
    buffer[i++] = '.';

    // Handle the fractional part
    for (u8 j = 0; j < copy_u8decimalPlaces; j++) {
        fractionalPart *= 10;
        u8 digit = (u8)fractionalPart;
        buffer[i++] = digit + '0';
        fractionalPart -= digit;
    }

    // Null-terminate the string
    buffer[i] = '\0';

    // Send each character to the LCD
    for (u8 k = 0; buffer[k] != '\0'; k++) {
        LCD_voidSendData(buffer[k]);
    }
}
