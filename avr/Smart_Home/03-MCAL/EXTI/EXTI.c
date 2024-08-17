/*
 * EXTI.c
 *
 *  Created on: Aug 16, 2023
 *      Author: eng_youssef_goher
 */
#include <avr/io.h>
#include "../../00-LIB/LSTD_types.h"
#include "../../00-LIB/LBIT_math.h"
#include "EXTI.h"

/*ID of EXinterrupt*/
//#define EXT_INT0 0
//#define EXT_INT1 1
//#define EXT_INT2 2

/*modes of EXinterrupt*/
//#define RISING		0
//#define FALLING 	1
//#define LOW_LEVEL	2
//#define TOGGLING 	3
static void(*INT0_pf)(void)=NULL;
static void(*INT1_pf)(void)=NULL;
static void(*INT2_pf)(void)=NULL;


void Intrrupt_Init(u8 copy_u8Intrrupt_id,u8 copy_u8Intrrupt_mode){
	switch(copy_u8Intrrupt_id){
		case EXT_INT0:
			switch(copy_u8Intrrupt_mode){
			case RISING:
				SET_BIT(MCUCR,ISC01);
				SET_BIT(MCUCR,ISC00);
				break;
			case FALLING:
				SET_BIT(MCUCR,ISC01);
				CLR_BIT(MCUCR,ISC00);
				break;
			case LOW_LEVEL:
				CLR_BIT(MCUCR,ISC01);
				CLR_BIT(MCUCR,ISC00);
				break;
			case TOGGLING:
				CLR_BIT(MCUCR,ISC01);
				SET_BIT(MCUCR,ISC00);
				break;
			}
				break;

	case EXT_INT1:
			switch(copy_u8Intrrupt_mode){
						case RISING:
							SET_BIT(MCUCR,ISC11);
							SET_BIT(MCUCR,ISC10);
							break;
						case FALLING:
							SET_BIT(MCUCR,ISC11);
							CLR_BIT(MCUCR,ISC10);
							break;
						case LOW_LEVEL:
							CLR_BIT(MCUCR,ISC11);
							CLR_BIT(MCUCR,ISC10);
							break;
						case TOGGLING:
							CLR_BIT(MCUCR,ISC11);
							SET_BIT(MCUCR,ISC10);
							break;
					}
				break;

		case EXT_INT2:
			switch(copy_u8Intrrupt_mode){
						case RISING:
							SET_BIT(MCUCSR,ISC2);
							break;
						case FALLING:
							CLR_BIT(MCUCSR,ISC2);
							break;
						}

				break;
		default:
			break;
		}
}
void Intrrupt_Enabled(u8 copy_u8Intrrupt_id){
	switch(copy_u8Intrrupt_id){
	case EXT_INT0:
		SET_BIT(GICR,INT0);
			break;
	case EXT_INT1:
		SET_BIT(GICR,INT1);
			break;
	case EXT_INT2:
		SET_BIT(GICR,INT2);
			break;
	default:
		break;
	}
	SET_BIT(SREG,GIE);
}
void Intrrupt_Disabled(u8 copy_u8Intrrupt_id){
	switch(copy_u8Intrrupt_id){
		case EXT_INT0:
			CLR_BIT(GICR,INT0);
				break;
		case EXT_INT1:
			CLR_BIT(GICR,INT1);
				break;
		case EXT_INT2:
			CLR_BIT(GICR,INT2);
				break;
		default:
			break;
		}
}
void Intrrupt_GetFun(u8 copy_u8Intrrupt_id,void (*pf)(void)){
	switch(copy_u8Intrrupt_id){
			case EXT_INT0:
				INT0_pf=pf;
					break;
			case EXT_INT1:
				INT1_pf=pf;
					break;
			case EXT_INT2:
				INT2_pf=pf;
					break;
			default:
				break;
			}
}

void __vector_1(void) __attribute__((signal));
void __vector_1(void){
if(INT0_pf!=NULL){
	INT0_pf();
}
}


void __vector_2(void) __attribute__((signal));
void __vector_2(void){
	if(INT1_pf!=NULL){
		INT1_pf();
	}
}
void __vector_3(void) __attribute__((signal));
void __vector_3(void){
	if(INT2_pf!=NULL){
		INT2_pf();
	}
}
