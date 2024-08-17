/*
 * STEPPER.h
 *
 *  Created on: Jul 30, 2024
 *      Author: eng_youssef_goher
 */

#ifndef STEPPER_STEPPER_H_
#define STEPPER_STEPPER_H_

#define STEPPER_SPPED					(100) // inHZ

#define STEPPER_STEPS_Delay 			(1.0/(STEPPER_SPPED*4.0))
#define STEPPER_STEPS_Delay_ms 			STEPPER_STEPS_Delay*1000
#define STEPPER_PIN0					0
#define STEPPER_PIN1					1
#define STEPPER_PIN2					2
#define STEPPER_PIN3					3
#define STEPPER_PIN4					4
#define STEPPER_PIN5					5
#define STEPPER_PIN6					6
#define STEPPER_PIN7					7

#define STEPPER_BLUE_PIN 				STEPPER_PIN0
#define STEPPER_PINK_PIN 				STEPPER_PIN1
#define STEPPER_YELLOW_PIN 				STEPPER_PIN2
#define STEPPER_ORANGE_PIN 				STEPPER_PIN3


#define STEPPER_PORT					PORTA
#define STEPPER_DDR						DDRA

#define Potion_BLUE_COIL				1
#define Potion_BLUE_PINK_COIL			2
#define Potion_PINK_COIL				3
#define Potion_PINK_YELLOW_COIL			4
#define Potion_YELLOW_COIL				5
#define Potion_YELLOW_ORANGE_COIL		6
#define Potion_ORANGE_COIL				7
#define Potion_ORANGE_BLUE_COIL			8

#define NUMBER_OF_STEPS 				4
#define STEPPER_LEFT					0
#define STEPPER_RIGHT 					1
void STEPPER_voidini(void);
void STEPPER_voidGoToPotion(u8 copy_u8Potion);
void STEPPER_voidRotat(u8 copy_u8Dircation);

#endif /* STEPPER_STEPPER_H_ */
