/*
 * HICU_private.h
 *
 *  Created on: Aug 6, 2024
 *      Author: eng_youssef_goher
 */

#ifndef __HAL_HICU_HICU_PRIVATE_H_
#define __HAL_HICU_HICU_PRIVATE_H_

/***
 *
 * options for TIMERS Attach TIM0,TIM1,TIM2
 *
 ***/


#define HICU_ATTACH_TIM_TIM0			1
#define HICU_ATTACH_TIM_TIM1			2
#define HICU_ATTACH_TIM_TIM2			3

/***
 *
 * options for EXTI Attach EXTI0,EXTI1,EXTI2
 *
 ***/
#define HICU_ATTACH_EXTI_EXTI0			4
#define HICU_ATTACH_EXTI_EXTI1			5
#define HICU_ATTACH_EXTI_EXTI2			6

static void HICU_voidICUAlgorithm(void);

static volatile f32 DutyCycle=0;
static volatile f32 Frequncy=0;

typedef enum{
	HICU_ICU_FIRST_RISING,
	HICU_ICU_FALLING,
	HICU_ICU_SECOND_RISING,
}HICU_STATE_T;


#endif /* 02_HAL_HICU_HICU_PRIVATE_H_ */
