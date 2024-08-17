/*
 * main.c
 *
 *  Created on: Aug 13, 2024
 *      Author: Mina.W
 */

#include "../00-LIB/LSTD_types.h"
#include "../00-LIB/LBIT_math.h"
#include <avr/io.h>
#include <avr/delay.h>
#include <stdint.h>


#ifdef 	F_CPU
#undef 	F_CPU
#endif
#define F_CPU 						8000000L

#include "../02-HAL/LCD/LCD.h"
#include "../02-HAL/KEYPAD/KEYPAD.h"
#include "../02-HAL/STEPPER/STEPPER.h"
#include "../02-HAL/Servo/Servo.h"
#include "../02-HAL/HICU/HICU_interface.h"
#include "../03-MCAL/EXTI/EXTI.h"
#include "../03-MCAL/ADC/ADC_interface.h"
#include "../03-MCAL/TIM/TIM_interface.h"
#include "../03-MCAL/WDT/WDT_interface.h"
#include "../03-MCAL/UART/UART_interface.h"
#include "../03-MCAL/SPI/SPI_interface.h"
#include "../03-MCAL/TWI/TWI_interface.h"
#include "../03-MCAL/DIO/DIO_interface.h"

u8 UART_character = '\0';
u8 local_u8KeypadValue = '\0';
u16 correct_password = 1234;
u16 user_password_keypad = '\0';
u16 user_password_web = '\0';
u16 password_repeated_times_keypad = 0;
u16 password_repeated_times_web = 0;

void Toggle_led1(void){
	DIO_voidSetPinsValue(DIOA,DIO_PIN2,DIO_LOW);
	DIO_voidSetPinsValue(DIOA,DIO_PIN0,DIO_HIGH);
}

void Toggle_led2(void){
	DIO_voidSetPinsValue(DIOA,DIO_PIN2,DIO_HIGH);
	DIO_voidSetPinsValue(DIOA,DIO_PIN0,DIO_LOW);
}

void Red_blink(void){
	u32 counter=0;
	DIO_voidSetPinsValue(DIOA,DIO_PIN2,DIO_LOW);

	for(counter=0; counter<=10; counter++){

		DIO_voidSetPinsValue(DIOA,DIO_PIN0,DIO_HIGH);
		_delay_ms(300);
		DIO_voidSetPinsValue(DIOA,DIO_PIN0,DIO_LOW);
		_delay_ms(300);
		DIO_voidSetPinsValue(DIOA,DIO_PIN7,DIO_LOW);
		_delay_ms(300);
		DIO_voidSetPinsValue(DIOA,DIO_PIN7,DIO_HIGH);
	}

}

void keypad_mode(void){
	local_u8KeypadValue = KEYPAD_u8Scan();

	while(1){

			if (local_u8KeypadValue >= '0' && local_u8KeypadValue <= '9') {

				user_password_keypad = user_password_keypad * 10 + (local_u8KeypadValue - '0');
				LCD_voidClearDisplay();
				LCD_voidWriteNumber(user_password_keypad);
				_delay_ms(500);

			}
			else if(local_u8KeypadValue == '='){

				if(correct_password == user_password_keypad){
					LCD_voidSetCursorLocation(1, 0); // Line 1, Column 0
					LCD_voidwriteString((u8*) "Welcome Home!");

					Toggle_led2();	// green led on red led off
					Servo_voidMoveToLocation((u8)90);	// open lock
					_delay_ms(2000);
					Servo_voidMoveToLocation((u8)0);

					password_repeated_times_keypad = 0;
					user_password_keypad = '\0';
					_delay_ms(700);
					LCD_voidClearDisplay();
					break;
					}
				else{

					LCD_voidSetCursorLocation(1, 0); // Line 1, Column 0
					LCD_voidwriteString((u8*) "Wrong Password!");
					Toggle_led1();	// green led off red led on
					user_password_keypad = '\0';
					password_repeated_times_keypad++;
					if(password_repeated_times_keypad == 3){
						LCD_voidSetCursorLocation(1, 0); // Line 1, Column 0
						LCD_voidwriteString((u8*) "No more trials");
						_delay_ms(700);
						LCD_voidClearDisplay();
						password_repeated_times_keypad = 0;
						Red_blink();	// green led off red led blink
						break;
					}
					else{}
					_delay_ms(700);
					LCD_voidClearDisplay();
					break;

				}

			}
			else{}
			local_u8KeypadValue = KEYPAD_u8Scan();

	}
}

void main(void){

	DIO_voidIniPins(DIOA, DIO_PIN0|DIO_PIN3|DIO_PIN2|DIO_PIN7, DIO_OUTPUT);

	// initializations
	Servo_voidini();
	TIM_voidIni(TIM0);
	TIM_voidIni(TIM2);
	TIM_voidSetPWMDC(OC0,10);
	TIM_voidSetPWMDC(OC2,50);
	TIM_voidStart(TIM0,TIMS_DIVISION_1024);
	TIM_voidStart(TIM2,TIMS_DIVISION_1024);

	// EXTI
	DIO_voidIniPins(DIOD,DIO_PIN2,DIO_INPUT);
	Intrrupt_Init(EXT_INT0,TOGGLING);
	Intrrupt_GetFun(EXT_INT0,keypad_mode);
	Intrrupt_Enabled(EXT_INT0);

	LCD_voidini();         // data on: PORTC, control on: PORTD
	KEYPAD_voidini();	   // all on PORTB
	UART_voidIni(9600);

	while(1){

		UART_character = UART_u8Receive();
		//echo
		UART_voidTransmit(UART_character);

		// UART
		if(UART_character != '\0'){

			while(1){
				switch(UART_character){
				case 'H':
					DIO_voidSetPinsValue(DIOA,DIO_PIN3,DIO_HIGH);
					UART_voidTransmitString((u8*)": ");
					UART_voidTransmitString((u8*)"Light on the house \n\r");
					break;

				case 'L':
					DIO_voidSetPinsValue(DIOA,DIO_PIN3,DIO_LOW);
					UART_voidTransmitString((u8*)": ");
					UART_voidTransmitString((u8*)"Light off the house \n\r");
					break;

				case 'O':
					LCD_voidSetCursorLocation(1, 0); // Line 1, Column 0
					UART_voidTransmitString((u8*)": ");
					UART_voidTransmitString((u8*)"Password correct \n\r");
					LCD_voidwriteString((u8*) "Welcome Home!");

					Toggle_led2();	// green led on red led off
					Servo_voidMoveToLocation((u8)90);	// open lock
					_delay_ms(2000);
					Servo_voidMoveToLocation((u8)0);
					_delay_ms(700);
					LCD_voidClearDisplay();
					break;

				case 'S':  // 3 times wrong
					LCD_voidSetCursorLocation(1, 0); // Line 1, Column 0
					LCD_voidwriteString((u8*) "No more trials");
					UART_voidTransmitString((u8*)": ");
					UART_voidTransmitString((u8*)"Password incorrect for 3 times \n\r");
					Toggle_led1();	// green led off red led on
					_delay_ms(700);
					LCD_voidClearDisplay();
					DIO_voidSetPinsValue(DIOA,DIO_PIN7,DIO_LOW);
					Red_blink();

					break;

				case 'W':
					LCD_voidSetCursorLocation(1, 0); // Line 1, Column 0
					LCD_voidwriteString((u8*) "Wrong Password!");
					UART_voidTransmitString((u8*)": ");
					UART_voidTransmitString((u8*)"Password incorrect \n\r");
					_delay_ms(700);
					LCD_voidClearDisplay();
					Toggle_led1();	// green led off red led on
					break;

				default:
					break;
				}

				if (UART_character >= '0' && UART_character <= '9') {

					user_password_web = user_password_web * 10 + (UART_character - '0');
					LCD_voidClearDisplay();
					LCD_voidWriteNumber(user_password_web);
					_delay_ms(500);

				}
				else if(UART_character == 0x0D){        // we will see here if the enter is pressed
					LCD_voidwriteString((u8*) UART_character);
					UART_voidTransmitString((u8*)"\n\r");
					if(correct_password == user_password_web){
						LCD_voidSetCursorLocation(1, 0); // Line 1, Column 0
						LCD_voidwriteString((u8*) "Welcome Home!");

						Toggle_led2();	// green led on red led off
						Servo_voidMoveToLocation((u8)90);	// open lock
						_delay_ms(2000);
						Servo_voidMoveToLocation((u8)0);

						password_repeated_times_web = 0;
						user_password_web = '\0';
						_delay_ms(700);
						LCD_voidClearDisplay();
						break;
					}
					else{

						LCD_voidSetCursorLocation(1, 0); // Line 1, Column 0
						LCD_voidwriteString((u8*) "Wrong Password!");
						Toggle_led1();	// green led off red led on
						user_password_web = '\0';
						password_repeated_times_web++;
						if(password_repeated_times_web == 3){
							LCD_voidSetCursorLocation(1, 0); // Line 1, Column 0
							LCD_voidwriteString((u8*) "No more trials");
							_delay_ms(700);
							LCD_voidClearDisplay();
							password_repeated_times_web = 0;
							Red_blink();	// green led off red led blink
							break;
						}
						else{}
						_delay_ms(700);
						LCD_voidClearDisplay();
						break;

					}

				}
				else{}
				UART_character = UART_u8Receive();
				//echo
				UART_voidTransmit(UART_character);
			}

		}
		else{}
	}


	}


