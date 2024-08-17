/*
 * STEPPER.c
 *
 *  Created on: Jul 30, 2024
 *      Author: eng_youssef_goher
 */
#include "../../00-LIB/LSTD_types.h"
#include "../../00-LIB/LBIT_math.h"
#include <avr/io.h>
#include <avr/delay.h>

#include "STEPPER.h"

static void STEPPER_voidMoveRight	(void);
static void STEPPER_voidMoveLeft	(void);

static const u8 glople_u8arraySteps[NUMBER_OF_STEPS]={
		Potion_BLUE_COIL,
		Potion_PINK_COIL,
		Potion_YELLOW_COIL,
		Potion_ORANGE_COIL
};

void STEPPER_voidini(void){
	SET_BIT(STEPPER_DDR,STEPPER_BLUE_PIN);
	SET_BIT(STEPPER_DDR,STEPPER_PINK_PIN);
	SET_BIT(STEPPER_DDR,STEPPER_YELLOW_PIN);
	SET_BIT(STEPPER_DDR,STEPPER_ORANGE_PIN);
}
void STEPPER_voidGoToPotion(u8 copy_u8Potion){
	switch(copy_u8Potion){
	case(Potion_BLUE_COIL):
		SET_BIT(STEPPER_PORT,STEPPER_BLUE_PIN);
		CLR_BIT(STEPPER_PORT,STEPPER_PINK_PIN);
		CLR_BIT(STEPPER_PORT,STEPPER_YELLOW_PIN);
		CLR_BIT(STEPPER_PORT,STEPPER_ORANGE_PIN);

	break;
	case(Potion_BLUE_PINK_COIL):
		SET_BIT(STEPPER_PORT,STEPPER_BLUE_PIN);
		SET_BIT(STEPPER_PORT,STEPPER_PINK_PIN);
		CLR_BIT(STEPPER_PORT,STEPPER_YELLOW_PIN);
		CLR_BIT(STEPPER_PORT,STEPPER_ORANGE_PIN);
		break;
	case(Potion_PINK_COIL):
		CLR_BIT(STEPPER_PORT,STEPPER_BLUE_PIN);
		SET_BIT(STEPPER_PORT,STEPPER_PINK_PIN);
		CLR_BIT(STEPPER_PORT,STEPPER_YELLOW_PIN);
		CLR_BIT(STEPPER_PORT,STEPPER_ORANGE_PIN);
		break;
	case(Potion_PINK_YELLOW_COIL):
		CLR_BIT(STEPPER_PORT,STEPPER_BLUE_PIN);
		SET_BIT(STEPPER_PORT,STEPPER_PINK_PIN);
		SET_BIT(STEPPER_PORT,STEPPER_YELLOW_PIN);
		CLR_BIT(STEPPER_PORT,STEPPER_ORANGE_PIN);
		break;
	case(Potion_YELLOW_COIL):
		CLR_BIT(STEPPER_PORT,STEPPER_BLUE_PIN);
		CLR_BIT(STEPPER_PORT,STEPPER_PINK_PIN);
		SET_BIT(STEPPER_PORT,STEPPER_YELLOW_PIN);
		CLR_BIT(STEPPER_PORT,STEPPER_ORANGE_PIN);
		break;
	case(Potion_YELLOW_ORANGE_COIL):
		CLR_BIT(STEPPER_PORT,STEPPER_BLUE_PIN);
		CLR_BIT(STEPPER_PORT,STEPPER_PINK_PIN);
		SET_BIT(STEPPER_PORT,STEPPER_YELLOW_PIN);
		SET_BIT(STEPPER_PORT,STEPPER_ORANGE_PIN);
		break;
	case(Potion_ORANGE_COIL):
		CLR_BIT(STEPPER_PORT,STEPPER_BLUE_PIN);
		CLR_BIT(STEPPER_PORT,STEPPER_PINK_PIN);
		CLR_BIT(STEPPER_PORT,STEPPER_YELLOW_PIN);
		SET_BIT(STEPPER_PORT,STEPPER_ORANGE_PIN);
		break;
	case(Potion_ORANGE_BLUE_COIL):
		SET_BIT(STEPPER_PORT,STEPPER_BLUE_PIN);
		CLR_BIT(STEPPER_PORT,STEPPER_PINK_PIN);
		CLR_BIT(STEPPER_PORT,STEPPER_YELLOW_PIN);
		SET_BIT(STEPPER_PORT,STEPPER_ORANGE_PIN);
		break;
	default:
		break;
	}
	_delay_ms((u32)1000);
}
void STEPPER_voidRotat(u8 copy_u8Dircation){
	switch(copy_u8Dircation){
	case(STEPPER_LEFT):
		STEPPER_voidMoveLeft();
			break;
		case(STEPPER_RIGHT):
		STEPPER_voidMoveRight();
			break;
		default:
			break;

	}


}
static void STEPPER_voidMoveRight	(void){
	s8 local_u8counter=0;
	for(local_u8counter=0;local_u8counter<NUMBER_OF_STEPS;local_u8counter++){
		STEPPER_voidGoToPotion(	glople_u8arraySteps[local_u8counter]);
	}

}
static void STEPPER_voidMoveLeft	(void){
	s8 local_u8counter=NUMBER_OF_STEPS-1;
	for(local_u8counter=NUMBER_OF_STEPS-1;local_u8counter>=0;local_u8counter--){
			STEPPER_voidGoToPotion(	glople_u8arraySteps[local_u8counter]);
		}
}
