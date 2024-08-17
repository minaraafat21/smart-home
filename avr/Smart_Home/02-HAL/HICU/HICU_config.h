/*
 * HICU_config.h
 *
 *  Created on: Aug 6, 2024
 *      Author: eng_youssef_goher
 */

#ifndef __HAL_HICU_HICU_CONFIG_H_
#define __HAL_HICU_HICU_CONFIG_H_

/***
 *
 * options for TIMERS Attach TIM0,TIM1,TIM2
 * HICU_ATTACH_TIM_TIM0
 * HICU_ATTACH_TIM_TIM1
 * HICU_ATTACH_TIM_TIM2
 *
 ***/

#define HICU_ATTACH_TIM		HICU_ATTACH_TIM_TIM1

/***
 *
 * options for EXTI Attach EXTI0,EXTI1,EXTI2
 * HICU_ATTACH_EXTI_EXTI0
 * HICU_ATTACH_EXTI_EXTI1
 * HICU_ATTACH_EXTI_EXTI2
 *
 ***/

#define HICU_ATTACH_EXTI 	HICU_ATTACH_EXTI_EXTI1


/*
 * CPU_F in Mhz
 */
#define HICU_CPU_F_MHZ			8

/*
 * prescalr of
 */
#define HICU_TIM_PRESCALR		1024

#endif /* 02_HAL_HICU_HICU_CONFIG_H_ */







