/*
 * TIM_program.c
 *
 *  Created on: Aug 3, 2024
 *      Author: eng_youssef_goher
 */
#include "../../00-LIB/LSTD_types.h"
#include "../../00-LIB/LBIT_math.h"

#include "TIM_private.h"
#include "TIM_config.h"
#include "TIM_interface.h"

void TIM_voidIni(TIM_ID copy_TIM_ID){
	switch(copy_TIM_ID){
			case (TIM0):
			#if (TIM0_MODE== TIM0_TIM2_NORMAL)
					CLR_BIT(TIMS->TCCR0,WGM00);
					CLR_BIT(TIMS->TCCR0,WGM01);
					#if(OC0_FORCE_COMPARE==DISABLE_FORCE_OUTPUT_COMPARE)
						CLR_BIT(TIMS->TCCR0,FOC0);
					#elif(OC0_FORCE_COMPARE==ENABLE_FORCE_OUTPUT_COMPARE)
						SET_BIT(TIMS->TCCR0,FOC0);
					#else
						#error "OC0_FORCE_COMPARE Wrong define"
					#endif
					#if(OC0_MODE==OC_DISCONNECTED)
						CLR_BIT(TIMS->TCCR0,COM00);
						CLR_BIT(TIMS->TCCR0,COM01);
					#elif(OC0_MODE==OC_TOGGLE)
						SET_BIT(TIMS->TCCR0,COM00);
						CLR_BIT(TIMS->TCCR0,COM01);
					#elif(OC0_MODE==OC_CLEAR)
						CLR_BIT(TIMS->TCCR0,COM00);
						SET_BIT(TIMS->TCCR0,COM01);
					#elif(OC0_MODE==OC_SET)
						SET_BIT(TIMS->TCCR0,COM00);
						SET_BIT(TIMS->TCCR0,COM01);
					#else
						#error "OC0_MODE Wrong define"
					#endif
			#elif(TIM0_MODE== TIM0_TIM2_PWM_PHASECORRECT)
					SET_BIT(TIMS->TCCR0,WGM00);
					CLR_BIT(TIMS->TCCR0,WGM01);
					#if(OC0_MODE==OC_DISCONNECTED)
						CLR_BIT(TIMS->TCCR0,COM00);
						CLR_BIT(TIMS->TCCR0,COM01);
					#elif(OC0_MODE==OC_CLEAR_UP_SET_DOWN)
						CLR_BIT(TIMS->TCCR0,COM00);
						SET_BIT(TIMS->TCCR0,COM01);
					#elif(OC0_MODE==OC_SET_UP_CLEAR_DOWN)
						SET_BIT(TIMS->TCCR0,COM00);
						SET_BIT(TIMS->TCCR0,COM01);
					#else
						#error "OC0_MODE Wrong define"
					#endif
			#elif(TIM0_MODE== TIM0_TIM2_CTC)
					CLR_BIT(TIMS->TCCR0,WGM00);
					SET_BIT(TIMS->TCCR0,WGM01);
					#if(OC0_FORCE_COMPARE==DISABLE_FORCE_OUTPUT_COMPARE)
						CLR_BIT(TIMS->TCCR0,FOC0);
					#elif(OC0_FORCE_COMPARE==ENABLE_FORCE_OUTPUT_COMPARE)
						SET_BIT(TIMS->TCCR0,FOC0);
					#else
						#error "OC0_FORCE_COMPARE Wrong define"
					#endif
					#if(OC0_MODE==OC_DISCONNECTED)
						CLR_BIT(TIMS->TCCR0,COM00);
						CLR_BIT(TIMS->TCCR0,COM01);
					#elif(OC0_MODE==OC_TOGGLE)
						SET_BIT(TIMS->TCCR0,COM00);
						CLR_BIT(TIMS->TCCR0,COM01);
					#elif(OC0_MODE==OC_CLEAR)
						CLR_BIT(TIMS->TCCR0,COM00);
						SET_BIT(TIMS->TCCR0,COM01);
					#elif(OC0_MODE==OC_SET)
						SET_BIT(TIMS->TCCR0,COM00);
						SET_BIT(TIMS->TCCR0,COM01);
					#else
						#error "OC0_MODE Wrong define"
					#endif
			#elif(TIM0_MODE== TIM0_TIM2_FAST_PWM)
					SET_BIT(TIMS->TCCR0,WGM00);
					SET_BIT(TIMS->TCCR0,WGM01);
					#if(OC0_MODE==OC_DISCONNECTED)
						CLR_BIT(TIMS->TCCR0,COM00);
						CLR_BIT(TIMS->TCCR0,COM01);
					#elif(OC0_MODE==OC_CLEAR_COMPARE_SET_ON_BOTTOM)
						CLR_BIT(TIMS->TCCR0,COM00);
						SET_BIT(TIMS->TCCR0,COM01);
					#elif(OC0_MODE==OC_SET_COMPARE_CLEAR_ON_BOTTOM)
						SET_BIT(TIMS->TCCR0,COM00);
						SET_BIT(TIMS->TCCR0,COM01);
					#else
						#error "OC0_MODE Wrong define"
					#endif
			#else
				#error "TIM0_MODE Wrong define"
			#endif
				break;
			case (TIM1):
			#if (TIM1_MODE== TIM1_NORMAL)
				CLR_BIT(TIMS->TCCR1A,WGM10);
				CLR_BIT(TIMS->TCCR1A,WGM11);
				CLR_BIT(TIMS->TCCR1B,WGM12);
				CLR_BIT(TIMS->TCCR1B,WGM13);
				#if(OC1A_FORCE_COMPARE==DISABLE_FORCE_OUTPUT_COMPARE)
					CLR_BIT(TIMS->TCCR1A,FOC1A);
				#elif(OC1A_FORCE_COMPARE==ENABLE_FORCE_OUTPUT_COMPARE)
					SET_BIT(TIMS->TCCR1A,FOC1A);
				#else
					#error "OC1A_FORCE_COMPARE Wrong define"
				#endif
				#if(OC1B_FORCE_COMPARE==DISABLE_FORCE_OUTPUT_COMPARE)
					CLR_BIT(TIMS->TCCR1A,FOC1B);
				#elif(OC1B_FORCE_COMPARE==ENABLE_FORCE_OUTPUT_COMPARE)
					SET_BIT(TIMS->TCCR1A,FOC1B);
				#else
					#error "OC1B_FORCE_COMPARE Wrong define"
				#endif
				#if(OC1A_MODE==OC_DISCONNECTED)
					CLR_BIT(TIMS->TCCR1A,COM1A0);
					CLR_BIT(TIMS->TCCR1A,COM1A1);
				#elif(OC1A_MODE==OC_TOGGLE)
					SET_BIT(TIMS->TCCR1A,COM1A0);
					CLR_BIT(TIMS->TCCR1A,COM1A1);
				#elif(OC1A_MODE==OC_CLEAR)
					CLR_BIT(TIMS->TCCR1A,COM1A0);
					SET_BIT(TIMS->TCCR1A,COM1A1);
				#elif(OC1A_MODE==OC_SET)
					SET_BIT(TIMS->TCCR1A,COM1A0);
					SET_BIT(TIMS->TCCR1A,COM1A1);
				#else
					#error "OC1A_MODE Wrong define"
				#endif
				#if(OC1B_MODE==OC_DISCONNECTED)
					CLR_BIT(TIMS->TCCR1A,COM1B0);
					CLR_BIT(TIMS->TCCR1A,COM1B1);
				#elif(OC1B_MODE==OC_TOGGLE)
					SET_BIT(TIMS->TCCR1A,COM1B0);
					CLR_BIT(TIMS->TCCR1A,COM1B1);
				#elif(OC1B_MODE==OC_CLEAR)
					CLR_BIT(TIMS->TCCR1A,COM1B0);
					SET_BIT(TIMS->TCCR1A,COM1B1);
				#elif(OC1B_MODE==OC_SET)
					SET_BIT(TIMS->TCCR1A,COM1B0);
					SET_BIT(TIMS->TCCR1A,COM1B1);
				#else
					#error "OC1B_MODE Wrong define"
				#endif
			#elif(TIM1_MODE== TIM1_PWM_PHASECORRECT_8BIT)
				SET_BIT(TIMS->TCCR1A,WGM10);
				CLR_BIT(TIMS->TCCR1A,WGM11);
				CLR_BIT(TIMS->TCCR1B,WGM12);
				CLR_BIT(TIMS->TCCR1B,WGM13);
				#if(OC1A_MODE==OC_DISCONNECTED)
					CLR_BIT(TIMS->TCCR1A,COM1A0);
					CLR_BIT(TIMS->TCCR1A,COM1A1);
				#elif(OC1A_MODE==OC_CLEAR_UP_SET_DOWN)
					CLR_BIT(TIMS->TCCR1A,COM1A0);
					SET_BIT(TIMS->TCCR1A,COM1A1);
				#elif(OC1A_MODE==OC_SET_UP_CLEAR_DOWN)
					SET_BIT(TIMS->TCCR1A,COM1A0);
					SET_BIT(TIMS->TCCR1A,COM1A1);
				#else
					#error "OC1A_MODE Wrong define"
				#endif
				#if(OC1B_MODE==OC_DISCONNECTED)
					CLR_BIT(TIMS->TCCR1A,COM1B0);
					CLR_BIT(TIMS->TCCR1A,COM1B1);
				#elif(OC1B_MODE==OC_CLEAR_UP_SET_DOWN)
					CLR_BIT(TIMS->TCCR1A,COM1B0);
					SET_BIT(TIMS->TCCR1A,COM1B1);
				#elif(OC1B_MODE==OC_SET_UP_CLEAR_DOWN)
					SET_BIT(TIMS->TCCR1A,COM1B0);
					SET_BIT(TIMS->TCCR1A,COM1B1);
				#else
					#error "OC1B_MODE Wrong define"
				#endif
			#elif(TIM1_MODE== TIM1_PWM_PHASECORRECT_9BIT)
				CLR_BIT(TIMS->TCCR1A,WGM10);
				SET_BIT(TIMS->TCCR1A,WGM11);
				CLR_BIT(TIMS->TCCR1B,WGM12);
				CLR_BIT(TIMS->TCCR1B,WGM13);
				#if(OC1A_MODE==OC_DISCONNECTED)
					CLR_BIT(TIMS->TCCR1A,COM1A0);
					CLR_BIT(TIMS->TCCR1A,COM1A1);
				#elif(OC1A_MODE==OC_CLEAR_UP_SET_DOWN)
					CLR_BIT(TIMS->TCCR1A,COM1A0);
					SET_BIT(TIMS->TCCR1A,COM1A1);
				#elif(OC1A_MODE==OC_SET_UP_CLEAR_DOWN)
					SET_BIT(TIMS->TCCR1A,COM1A0);
					SET_BIT(TIMS->TCCR1A,COM1A1);
				#else
					#error "OC1A_MODE Wrong define"
				#endif
				#if(OC1B_MODE==OC_DISCONNECTED)
					CLR_BIT(TIMS->TCCR1A,COM1B0);
					CLR_BIT(TIMS->TCCR1A,COM1B1);
				#elif(OC1B_MODE==OC_CLEAR_UP_SET_DOWN)
					CLR_BIT(TIMS->TCCR1A,COM1B0);
					SET_BIT(TIMS->TCCR1A,COM1B1);
				#elif(OC1B_MODE==OC_SET_UP_CLEAR_DOWN)
					SET_BIT(TIMS->TCCR1A,COM1B0);
					SET_BIT(TIMS->TCCR1A,COM1B1);
				#else
					#error "OC1B_MODE Wrong define"
				#endif
			#elif(TIM1_MODE== TIM1_PWM_PHASECORRECT_10BIT)
				SET_BIT(TIMS->TCCR1A,WGM10);
				SET_BIT(TIMS->TCCR1A,WGM11);
				CLR_BIT(TIMS->TCCR1B,WGM12);
				CLR_BIT(TIMS->TCCR1B,WGM13);
				#if(OC1A_MODE==OC_DISCONNECTED)
					CLR_BIT(TIMS->TCCR1A,COM1A0);
					CLR_BIT(TIMS->TCCR1A,COM1A1);
				#elif(OC1A_MODE==OC_CLEAR_UP_SET_DOWN)
					CLR_BIT(TIMS->TCCR1A,COM1A0);
					SET_BIT(TIMS->TCCR1A,COM1A1);
				#elif(OC1A_MODE==OC_SET_UP_CLEAR_DOWN)
					SET_BIT(TIMS->TCCR1A,COM1A0);
					SET_BIT(TIMS->TCCR1A,COM1A1);
				#else
					#error "OC1A_MODE Wrong define"
				#endif
				#if(OC1B_MODE==OC_DISCONNECTED)
					CLR_BIT(TIMS->TCCR1A,COM1B0);
					CLR_BIT(TIMS->TCCR1A,COM1B1);
				#elif(OC1B_MODE==OC_CLEAR_UP_SET_DOWN)
					CLR_BIT(TIMS->TCCR1A,COM1B0);
					SET_BIT(TIMS->TCCR1A,COM1B1);
				#elif(OC1B_MODE==OC_SET_UP_CLEAR_DOWN)
					SET_BIT(TIMS->TCCR1A,COM1B0);
					SET_BIT(TIMS->TCCR1A,COM1B1);
				#else
					#error "OC1B_MODE Wrong define"
				#endif
			#elif(TIM1_MODE== TIM1_CTC_TOP_OCR1A)
				CLR_BIT(TIMS->TCCR1A,WGM10);
				CLR_BIT(TIMS->TCCR1A,WGM11);
				SET_BIT(TIMS->TCCR1B,WGM12);
				CLR_BIT(TIMS->TCCR1B,WGM13);
				#if(OC1A_FORCE_COMPARE==DISABLE_FORCE_OUTPUT_COMPARE)
					CLR_BIT(TIMS->TCCR1A,FOC1A);
				#elif(OC1A_FORCE_COMPARE==ENABLE_FORCE_OUTPUT_COMPARE)
					SET_BIT(TIMS->TCCR1A,FOC1A);
				#else
					#error "OC1A_FORCE_COMPARE Wrong define"
				#endif
				#if(OC1B_FORCE_COMPARE==DISABLE_FORCE_OUTPUT_COMPARE)
					CLR_BIT(TIMS->TCCR1A,FOC1B);
				#elif(OC1B_FORCE_COMPARE==ENABLE_FORCE_OUTPUT_COMPARE)
					SET_BIT(TIMS->TCCR1A,FOC1B);
				#else
					#error "OC1B_FORCE_COMPARE Wrong define"
				#endif
				#if(OC1A_MODE==OC_DISCONNECTED)
					CLR_BIT(TIMS->TCCR1A,COM1A0);
					CLR_BIT(TIMS->TCCR1A,COM1A1);
				#elif(OC1A_MODE==OC_TOGGLE)
					SET_BIT(TIMS->TCCR1A,COM1A0);
					CLR_BIT(TIMS->TCCR1A,COM1A1);
				#elif(OC1A_MODE==OC_CLEAR)
					CLR_BIT(TIMS->TCCR1A,COM1A0);
					SET_BIT(TIMS->TCCR1A,COM1A1);
				#elif(OC1A_MODE==OC_SET)
					SET_BIT(TIMS->TCCR1A,COM1A0);
					SET_BIT(TIMS->TCCR1A,COM1A1);
				#else
					#error "OC1A_MODE Wrong define"
				#endif
				#if(OC1B_MODE==OC_DISCONNECTED)
					CLR_BIT(TIMS->TCCR1A,COM1B0);
					CLR_BIT(TIMS->TCCR1A,COM1B1);
				#elif(OC1B_MODE==OC_TOGGLE)
					SET_BIT(TIMS->TCCR1A,COM1B0);
					CLR_BIT(TIMS->TCCR1A,COM1B1);
				#elif(OC1B_MODE==OC_CLEAR)
					CLR_BIT(TIMS->TCCR1A,COM1B0);
					SET_BIT(TIMS->TCCR1A,COM1B1);
				#elif(OC1B_MODE==OC_SET)
					SET_BIT(TIMS->TCCR1A,COM1B0);
					SET_BIT(TIMS->TCCR1A,COM1B1);
				#else
					#error "OC1B_MODE Wrong define"
				#endif
			#elif(TIM1_MODE== TIM1_FAST_PWM_8BIT)
				SET_BIT(TIMS->TCCR1A,WGM10);
				CLR_BIT(TIMS->TCCR1A,WGM11);
				SET_BIT(TIMS->TCCR1B,WGM12);
				CLR_BIT(TIMS->TCCR1B,WGM13);
				#if(OC1A_MODE==OC_DISCONNECTED)
					CLR_BIT(TIMS->TCCR1A,COM1A0);
					CLR_BIT(TIMS->TCCR1A,COM1A1);
				#elif(OC1A_MODE==OC_CLEAR_COMPARE_SET_ON_BOTTOM)
					CLR_BIT(TIMS->TCCR1A,COM1A0);
					SET_BIT(TIMS->TCCR1A,COM1A1);
				#elif(OC1A_MODE==OC_SET_COMPARE_CLEAR_ON_BOTTOM)
					SET_BIT(TIMS->TCCR1A,COM1A0);
					SET_BIT(TIMS->TCCR1A,COM1A1);
				#else
					#error "OC1A_MODE Wrong define"
				#endif
				#if(OC1B_MODE==OC_DISCONNECTED)
					CLR_BIT(TIMS->TCCR1A,COM1B0);
					CLR_BIT(TIMS->TCCR1A,COM1B1);
				#elif(OC1B_MODE==OC_CLEAR_COMPARE_SET_ON_BOTTOM)
					CLR_BIT(TIMS->TCCR1A,COM1B0);
					SET_BIT(TIMS->TCCR1A,COM1B1);
				#elif(OC1B_MODE==OC_SET_COMPARE_CLEAR_ON_BOTTOM)
					SET_BIT(TIMS->TCCR1A,COM1B0);
					SET_BIT(TIMS->TCCR1A,COM1B1);
				#else
					#error "OC1B_MODE Wrong define"
				#endif
			#elif(TIM1_MODE== TIM1_FAST_PWM_9BIT)
				CLR_BIT(TIMS->TCCR1A,WGM10);
				SET_BIT(TIMS->TCCR1A,WGM11);
				SET_BIT(TIMS->TCCR1B,WGM12);
				CLR_BIT(TIMS->TCCR1B,WGM13);
				#if(OC1A_MODE==OC_DISCONNECTED)
					CLR_BIT(TIMS->TCCR1A,COM1A0);
					CLR_BIT(TIMS->TCCR1A,COM1A1);
				#elif(OC1A_MODE==OC_CLEAR_COMPARE_SET_ON_BOTTOM)
					CLR_BIT(TIMS->TCCR1A,COM1A0);
					SET_BIT(TIMS->TCCR1A,COM1A1);
				#elif(OC1A_MODE==OC_SET_COMPARE_CLEAR_ON_BOTTOM)
					SET_BIT(TIMS->TCCR1A,COM1A0);
					SET_BIT(TIMS->TCCR1A,COM1A1);
				#else
					#error "OC1A_MODE Wrong define"
				#endif
				#if(OC1B_MODE==OC_DISCONNECTED)
					CLR_BIT(TIMS->TCCR1A,COM1B0);
					CLR_BIT(TIMS->TCCR1A,COM1B1);
				#elif(OC1B_MODE==OC_CLEAR_COMPARE_SET_ON_BOTTOM)
					CLR_BIT(TIMS->TCCR1A,COM1B0);
					SET_BIT(TIMS->TCCR1A,COM1B1);
				#elif(OC1B_MODE==OC_SET_COMPARE_CLEAR_ON_BOTTOM)
					SET_BIT(TIMS->TCCR1A,COM1B0);
					SET_BIT(TIMS->TCCR1A,COM1B1);
				#else
					#error "OC1B_MODE Wrong define"
				#endif
			#elif(TIM1_MODE== TIM1_FAST_PWM_10BIT)
				SET_BIT(TIMS->TCCR1A,WGM10);
				SET_BIT(TIMS->TCCR1A,WGM11);
				SET_BIT(TIMS->TCCR1B,WGM12);
				CLR_BIT(TIMS->TCCR1B,WGM13);
				#if(OC1A_MODE==OC_DISCONNECTED)
					CLR_BIT(TIMS->TCCR1A,COM1A0);
					CLR_BIT(TIMS->TCCR1A,COM1A1);
				#elif(OC1A_MODE==OC_CLEAR_COMPARE_SET_ON_BOTTOM)
					CLR_BIT(TIMS->TCCR1A,COM1A0);
					SET_BIT(TIMS->TCCR1A,COM1A1);
				#elif(OC1A_MODE==OC_SET_COMPARE_CLEAR_ON_BOTTOM)
					SET_BIT(TIMS->TCCR1A,COM1A0);
					SET_BIT(TIMS->TCCR1A,COM1A1);
				#else
					#error "OC1A_MODE Wrong define"
				#endif
				#if(OC1B_MODE==OC_DISCONNECTED)
					CLR_BIT(TIMS->TCCR1A,COM1B0);
					CLR_BIT(TIMS->TCCR1A,COM1B1);
				#elif(OC1B_MODE==OC_CLEAR_COMPARE_SET_ON_BOTTOM)
					CLR_BIT(TIMS->TCCR1A,COM1B0);
					SET_BIT(TIMS->TCCR1A,COM1B1);
				#elif(OC1B_MODE==OC_SET_COMPARE_CLEAR_ON_BOTTOM)
					SET_BIT(TIMS->TCCR1A,COM1B0);
					SET_BIT(TIMS->TCCR1A,COM1B1);
				#else
					#error "OC1B_MODE Wrong define"
				#endif
			#elif(TIM1_MODE== TIM1_PWM_PHASE_FRE_TOP_ICR1)
				CLR_BIT(TIMS->TCCR1A,WGM10);
				CLR_BIT(TIMS->TCCR1A,WGM11);
				CLR_BIT(TIMS->TCCR1B,WGM12);
				SET_BIT(TIMS->TCCR1B,WGM13);
				#if(OC1A_MODE==OC_DISCONNECTED)
					CLR_BIT(TIMS->TCCR1A,COM1A0);
					CLR_BIT(TIMS->TCCR1A,COM1A1);
				#elif(OC1A_MODE==OC_CLEAR_UP_SET_DOWN)
					CLR_BIT(TIMS->TCCR1A,COM1A0);
					SET_BIT(TIMS->TCCR1A,COM1A1);
				#elif(OC1A_MODE==OC_SET_UP_CLEAR_DOWN)
					SET_BIT(TIMS->TCCR1A,COM1A0);
					SET_BIT(TIMS->TCCR1A,COM1A1);
				#else
					#error "OC1A_MODE Wrong define"
				#endif
				#if(OC1B_MODE==OC_DISCONNECTED)
					CLR_BIT(TIMS->TCCR1A,COM1B0);
					CLR_BIT(TIMS->TCCR1A,COM1B1);
				#elif(OC1B_MODE==OC_CLEAR_UP_SET_DOWN)
					CLR_BIT(TIMS->TCCR1A,COM1B0);
					SET_BIT(TIMS->TCCR1A,COM1B1);
				#elif(OC1B_MODE==OC_SET_UP_CLEAR_DOWN)
					SET_BIT(TIMS->TCCR1A,COM1B0);
					SET_BIT(TIMS->TCCR1A,COM1B1);
				#else
					#error "OC1B_MODE Wrong define"
				#endif
			#elif(TIM1_MODE== TIM1_PWM_PHASE_FRE_TOP_OCR1A)
				SET_BIT(TIMS->TCCR1A,WGM10);
				CLR_BIT(TIMS->TCCR1A,WGM11);
				CLR_BIT(TIMS->TCCR1B,WGM12);
				SET_BIT(TIMS->TCCR1B,WGM13);
				#if(OC1A_MODE==OC_DISCONNECTED)
					CLR_BIT(TIMS->TCCR1A,COM1A0);
					CLR_BIT(TIMS->TCCR1A,COM1A1);
				#elif(OC1A_MODE==OC_CLEAR_UP_SET_DOWN)
					CLR_BIT(TIMS->TCCR1A,COM1A0);
					SET_BIT(TIMS->TCCR1A,COM1A1);
				#elif(OC1A_MODE==OC_SET_UP_CLEAR_DOWN)
					SET_BIT(TIMS->TCCR1A,COM1A0);
					SET_BIT(TIMS->TCCR1A,COM1A1);
				#else
					#error "OC1A_MODE Wrong define"
				#endif
				#if(OC1B_MODE==OC_DISCONNECTED)
					CLR_BIT(TIMS->TCCR1A,COM1B0);
					CLR_BIT(TIMS->TCCR1A,COM1B1);
				#elif(OC1B_MODE==OC_CLEAR_UP_SET_DOWN)
					CLR_BIT(TIMS->TCCR1A,COM1B0);
					SET_BIT(TIMS->TCCR1A,COM1B1);
				#elif(OC1B_MODE==OC_SET_UP_CLEAR_DOWN)
					SET_BIT(TIMS->TCCR1A,COM1B0);
					SET_BIT(TIMS->TCCR1A,COM1B1);
				#else
					#error "OC1B_MODE Wrong define"
				#endif
			#elif(TIM1_MODE== TIM1_PWM_PHASECORRECT_TOP_ICR1)
				CLR_BIT(TIMS->TCCR1A,WGM10);
				SET_BIT(TIMS->TCCR1A,WGM11);
				CLR_BIT(TIMS->TCCR1B,WGM12);
				SET_BIT(TIMS->TCCR1B,WGM13);
				#if(OC1A_MODE==OC_DISCONNECTED)
					CLR_BIT(TIMS->TCCR1A,COM1A0);
					CLR_BIT(TIMS->TCCR1A,COM1A1);
				#elif(OC1A_MODE==OC_CLEAR_UP_SET_DOWN)
					CLR_BIT(TIMS->TCCR1A,COM1A0);
					SET_BIT(TIMS->TCCR1A,COM1A1);
				#elif(OC1A_MODE==OC_SET_UP_CLEAR_DOWN)
					SET_BIT(TIMS->TCCR1A,COM1A0);
					SET_BIT(TIMS->TCCR1A,COM1A1);
				#else
					#error "OC1A_MODE Wrong define"
				#endif
				#if(OC1B_MODE==OC_DISCONNECTED)
					CLR_BIT(TIMS->TCCR1A,COM1B0);
					CLR_BIT(TIMS->TCCR1A,COM1B1);
				#elif(OC1B_MODE==OC_CLEAR_UP_SET_DOWN)
					CLR_BIT(TIMS->TCCR1A,COM1B0);
					SET_BIT(TIMS->TCCR1A,COM1B1);
				#elif(OC1B_MODE==OC_SET_UP_CLEAR_DOWN)
					SET_BIT(TIMS->TCCR1A,COM1B0);
					SET_BIT(TIMS->TCCR1A,COM1B1);
				#else
					#error "OC1B_MODE Wrong define"
				#endif
			#elif(TIM1_MODE== TIM1_PWM_PHASECORRECT_TOP_OCR1A)
				SET_BIT(TIMS->TCCR1A,WGM10);
				SET_BIT(TIMS->TCCR1A,WGM11);
				CLR_BIT(TIMS->TCCR1B,WGM12);
				SET_BIT(TIMS->TCCR1B,WGM13);
				#if(OC1A_MODE==OC_DISCONNECTED)
					CLR_BIT(TIMS->TCCR1A,COM1A0);
					CLR_BIT(TIMS->TCCR1A,COM1A1);
				#elif(OC1A_MODE==OC_CLEAR_UP_SET_DOWN)
					CLR_BIT(TIMS->TCCR1A,COM1A0);
					SET_BIT(TIMS->TCCR1A,COM1A1);
				#elif(OC1A_MODE==OC_SET_UP_CLEAR_DOWN)
					SET_BIT(TIMS->TCCR1A,COM1A0);
					SET_BIT(TIMS->TCCR1A,COM1A1);
				#else
					#error "OC1A_MODE Wrong define"
				#endif
				#if(OC1B_MODE==OC_DISCONNECTED)
					CLR_BIT(TIMS->TCCR1A,COM1B0);
					CLR_BIT(TIMS->TCCR1A,COM1B1);
				#elif(OC1B_MODE==OC_CLEAR_UP_SET_DOWN)
					CLR_BIT(TIMS->TCCR1A,COM1B0);
					SET_BIT(TIMS->TCCR1A,COM1B1);
				#elif(OC1B_MODE==OC_SET_UP_CLEAR_DOWN)
					SET_BIT(TIMS->TCCR1A,COM1B0);
					SET_BIT(TIMS->TCCR1A,COM1B1);
				#else
					#error "OC1B_MODE Wrong define"
				#endif
			#elif(TIM1_MODE== TIM1_CTC_TOP_ICR1)
				CLR_BIT(TIMS->TCCR1A,WGM10);
				CLR_BIT(TIMS->TCCR1A,WGM11);
				SET_BIT(TIMS->TCCR1B,WGM12);
				SET_BIT(TIMS->TCCR1B,WGM13);
				#if(OC1A_FORCE_COMPARE==DISABLE_FORCE_OUTPUT_COMPARE)
					CLR_BIT(TIMS->TCCR1A,FOC1A);
				#elif(OC1A_FORCE_COMPARE==ENABLE_FORCE_OUTPUT_COMPARE)
					SET_BIT(TIMS->TCCR1A,FOC1A);
				#else
					#error "OC1A_FORCE_COMPARE Wrong define"
				#endif
				#if(OC1B_FORCE_COMPARE==DISABLE_FORCE_OUTPUT_COMPARE)
					CLR_BIT(TIMS->TCCR1A,FOC1B);
				#elif(OC1B_FORCE_COMPARE==ENABLE_FORCE_OUTPUT_COMPARE)
					SET_BIT(TIMS->TCCR1A,FOC1B);
				#else
					#error "OC1B_FORCE_COMPARE Wrong define"
				#endif
				#if(OC1A_MODE==OC_DISCONNECTED)
					CLR_BIT(TIMS->TCCR1A,COM1A0);
					CLR_BIT(TIMS->TCCR1A,COM1A1);
				#elif(OC1A_MODE==OC_TOGGLE)
					SET_BIT(TIMS->TCCR1A,COM1A0);
					CLR_BIT(TIMS->TCCR1A,COM1A1);
				#elif(OC1A_MODE==OC_CLEAR)
					CLR_BIT(TIMS->TCCR1A,COM1A0);
					SET_BIT(TIMS->TCCR1A,COM1A1);
				#elif(OC1A_MODE==OC_SET)
					SET_BIT(TIMS->TCCR1A,COM1A0);
					SET_BIT(TIMS->TCCR1A,COM1A1);
				#else
					#error "OC1A_MODE Wrong define"
				#endif
				#if(OC1B_MODE==OC_DISCONNECTED)
					CLR_BIT(TIMS->TCCR1A,COM1B0);
					CLR_BIT(TIMS->TCCR1A,COM1B1);
				#elif(OC1B_MODE==OC_TOGGLE)
					SET_BIT(TIMS->TCCR1A,COM1B0);
					CLR_BIT(TIMS->TCCR1A,COM1B1);
				#elif(OC1B_MODE==OC_CLEAR)
					CLR_BIT(TIMS->TCCR1A,COM1B0);
					SET_BIT(TIMS->TCCR1A,COM1B1);
				#elif(OC1B_MODE==OC_SET)
					SET_BIT(TIMS->TCCR1A,COM1B0);
					SET_BIT(TIMS->TCCR1A,COM1B1);
				#else
					#error "OC1B_MODE Wrong define"
				#endif
			#elif(TIM1_MODE== TIM1_FAST_TOP_ICR1)
				CLR_BIT(TIMS->TCCR1A,WGM10);
				SET_BIT(TIMS->TCCR1A,WGM11);
				SET_BIT(TIMS->TCCR1B,WGM12);
				SET_BIT(TIMS->TCCR1B,WGM13);
				#if(OC1A_MODE==OC_DISCONNECTED)
					CLR_BIT(TIMS->TCCR1A,COM1A0);
					CLR_BIT(TIMS->TCCR1A,COM1A1);
				#elif(OC1A_MODE==OC_CLEAR_COMPARE_SET_ON_BOTTOM)
					CLR_BIT(TIMS->TCCR1A,COM1A0);
					SET_BIT(TIMS->TCCR1A,COM1A1);
				#elif(OC1A_MODE==OC_SET_COMPARE_CLEAR_ON_BOTTOM)
					SET_BIT(TIMS->TCCR1A,COM1A0);
					SET_BIT(TIMS->TCCR1A,COM1A1);
				#else
					#error "OC1A_MODE Wrong define"
				#endif
				#if(OC1B_MODE==OC_DISCONNECTED)
					CLR_BIT(TIMS->TCCR1A,COM1B0);
					CLR_BIT(TIMS->TCCR1A,COM1B1);
				#elif(OC1B_MODE==OC_CLEAR_COMPARE_SET_ON_BOTTOM)
					CLR_BIT(TIMS->TCCR1A,COM1B0);
					SET_BIT(TIMS->TCCR1A,COM1B1);
				#elif(OC1B_MODE==OC_SET_COMPARE_CLEAR_ON_BOTTOM)
					SET_BIT(TIMS->TCCR1A,COM1B0);
					SET_BIT(TIMS->TCCR1A,COM1B1);
				#else
					#error "OC1B_MODE Wrong define"
				#endif
			#elif(TIM1_MODE== TIM1_FAST_TOP_OCR1A)
				SET_BIT(TIMS->TCCR1A,WGM10);
				SET_BIT(TIMS->TCCR1A,WGM11);
				SET_BIT(TIMS->TCCR1B,WGM12);
				SET_BIT(TIMS->TCCR1B,WGM13);
				#if(OC1A_MODE==OC_DISCONNECTED)
					CLR_BIT(TIMS->TCCR1A,COM1A0);
					CLR_BIT(TIMS->TCCR1A,COM1A1);
				#elif(OC1A_MODE==OC_CLEAR_COMPARE_SET_ON_BOTTOM)
					CLR_BIT(TIMS->TCCR1A,COM1A0);
					SET_BIT(TIMS->TCCR1A,COM1A1);
				#elif(OC1A_MODE==OC_SET_COMPARE_CLEAR_ON_BOTTOM)
					SET_BIT(TIMS->TCCR1A,COM1A0);
					SET_BIT(TIMS->TCCR1A,COM1A1);
				#else
					#error "OC1A_MODE Wrong define"
				#endif
				#if(OC1B_MODE==OC_DISCONNECTED)
					CLR_BIT(TIMS->TCCR1A,COM1B0);
					CLR_BIT(TIMS->TCCR1A,COM1B1);
				#elif(OC1B_MODE==OC_CLEAR_COMPARE_SET_ON_BOTTOM)
					CLR_BIT(TIMS->TCCR1A,COM1B0);
					SET_BIT(TIMS->TCCR1A,COM1B1);
				#elif(OC1B_MODE==OC_SET_COMPARE_CLEAR_ON_BOTTOM)
					SET_BIT(TIMS->TCCR1A,COM1B0);
					SET_BIT(TIMS->TCCR1A,COM1B1);
				#else
					#error "OC1B_MODE Wrong define"
				#endif
			#else
				#error "TIM1_MODE Wrong define"
			#endif
				break;

			case (TIM2):
					#if (TIM2_MODE== TIM0_TIM2_NORMAL)
					CLR_BIT(TIMS->TCCR2,WGM20);
					CLR_BIT(TIMS->TCCR2,WGM21);
					#if(OC2_FORCE_COMPARE==DISABLE_FORCE_OUTPUT_COMPARE)
						CLR_BIT(TIMS->TCCR2,FOC2);
					#elif(OC2_FORCE_COMPARE==ENABLE_FORCE_OUTPUT_COMPARE)
						SET_BIT(TIMS->TCCR2,FOC2);
					#else
						#error "OC2_FORCE_COMPARE Wrong define"
					#endif
					#if(OC2_MODE==OC_DISCONNECTED)
						CLR_BIT(TIMS->TCCR2,COM20);
						CLR_BIT(TIMS->TCCR2,COM21);
					#elif(OC2_MODE==OC_TOGGLE)
						SET_BIT(TIMS->TCCR2,COM20);
						CLR_BIT(TIMS->TCCR2,COM21);
					#elif(OC2_MODE==OC_CLEAR)
						CLR_BIT(TIMS->TCCR2,COM20);
						SET_BIT(TIMS->TCCR2,COM21);
					#elif(OC2_MODE==OC_SET)
						SET_BIT(TIMS->TCCR2,COM20);
						SET_BIT(TIMS->TCCR2,COM21);
					#else
						#error "OC2_MODE Wrong define"
					#endif
			#elif(TIM2_MODE== TIM0_TIM2_PWM_PHASECORRECT)
					SET_BIT(TIMS->TCCR2,WGM20);
					CLR_BIT(TIMS->TCCR2,WGM21);
					#if(OC2_MODE==OC_DISCONNECTED)
						CLR_BIT(TIMS->TCCR2,COM20);
						CLR_BIT(TIMS->TCCR2,COM21);
					#elif(OC2_MODE==OC_CLEAR_UP_SET_DOWN)
						CLR_BIT(TIMS->TCCR2,COM20);
						SET_BIT(TIMS->TCCR2,COM21);
					#elif(OC2_MODE==OC_SET_UP_CLEAR_DOWN)
						SET_BIT(TIMS->TCCR2,COM20);
						SET_BIT(TIMS->TCCR2,COM21);
					#else
						#error "OC2_MODE Wrong define"
					#endif
			#elif(TIM2_MODE== TIM0_TIM2_CTC)
					CLR_BIT(TIMS->TCCR2,WGM20);
					SET_BIT(TIMS->TCCR2,WGM21);
					#if(OC2_FORCE_COMPARE==DISABLE_FORCE_OUTPUT_COMPARE)
						CLR_BIT(TIMS->TCCR2,FOC2);
					#elif(OC2_FORCE_COMPARE==ENABLE_FORCE_OUTPUT_COMPARE)
						SET_BIT(TIMS->TCCR2,FOC2);
					#else
						#error "OC2_FORCE_COMPARE Wrong define"
					#endif
					#if(OC2_MODE==OC_DISCONNECTED)
						CLR_BIT(TIMS->TCCR2,COM20);
						CLR_BIT(TIMS->TCCR2,COM21);
					#elif(OC2_MODE==OC_TOGGLE)
						SET_BIT(TIMS->TCCR2,COM20);
						CLR_BIT(TIMS->TCCR2,COM21);
					#elif(OC2_MODE==OC_CLEAR)
						CLR_BIT(TIMS->TCCR2,COM20);
						SET_BIT(TIMS->TCCR2,COM21);
					#elif(OC2_MODE==OC_SET)
						SET_BIT(TIMS->TCCR2,COM20);
						SET_BIT(TIMS->TCCR2,COM21);
					#else
						#error "OC2_MODE Wrong define"
					#endif
			#elif(TIM2_MODE== TIM0_TIM2_FAST_PWM)
					SET_BIT(TIMS->TCCR2,WGM20);
					SET_BIT(TIMS->TCCR2,WGM21);
					#if(OC2_MODE==OC_DISCONNECTED)
						CLR_BIT(TIMS->TCCR2,COM20);
						CLR_BIT(TIMS->TCCR2,COM21);
					#elif(OC2_MODE==OC_CLEAR_COMPARE_SET_ON_BOTTOM)
						CLR_BIT(TIMS->TCCR2,COM20);
						SET_BIT(TIMS->TCCR2,COM21);
					#elif(OC2_MODE==OC_SET_COMPARE_CLEAR_ON_BOTTOM)
						SET_BIT(TIMS->TCCR2,COM20);
						SET_BIT(TIMS->TCCR2,COM21);
					#else
						#error "OC2_MODE Wrong define"
					#endif
			#else
				#error "TIM2_MODE Wrong define"
			#endif
				break;
			default:

				break;

		}
}
void TIM_voidStart(TIM_ID copy_TIM_ID,TIMS_CLOCK_T copy_TIMS_CLOCK){
	switch(copy_TIM_ID){
			case (TIM0):
				switch(copy_TIMS_CLOCK){
					case TIMS_STOP:
						CLR_BIT(TIMS->TCCR0,CS00);
						CLR_BIT(TIMS->TCCR0,CS01);
						CLR_BIT(TIMS->TCCR0,CS02);
						break;
					case TIMS_DIVISION_1:
						SET_BIT(TIMS->TCCR0,CS00);
						CLR_BIT(TIMS->TCCR0,CS01);
						CLR_BIT(TIMS->TCCR0,CS02);
						break;
					case TIMS_DIVISION_8:
						CLR_BIT(TIMS->TCCR0,CS00);
						SET_BIT(TIMS->TCCR0,CS01);
						CLR_BIT(TIMS->TCCR0,CS02);
						break;
					case TIMS_DIVISION_64:
						SET_BIT(TIMS->TCCR0,CS00);
						SET_BIT(TIMS->TCCR0,CS01);
						CLR_BIT(TIMS->TCCR0,CS02);
						break;
					case TIMS_DIVISION_256:
						CLR_BIT(TIMS->TCCR0,CS00);
						CLR_BIT(TIMS->TCCR0,CS01);
						SET_BIT(TIMS->TCCR0,CS02);
						break;
					case TIMS_DIVISION_1024:
						SET_BIT(TIMS->TCCR0,CS00);
						CLR_BIT(TIMS->TCCR0,CS01);
						SET_BIT(TIMS->TCCR0,CS02);
						break;
					case TIM0_TIM1_T_PIN_FALLINGEVENT:
						CLR_BIT(TIMS->TCCR0,CS00);
						SET_BIT(TIMS->TCCR0,CS01);
						SET_BIT(TIMS->TCCR0,CS02);
						break;
					case TIM0_TIM1_T_PIN_RISINGEVENT:
						SET_BIT(TIMS->TCCR0,CS00);
						SET_BIT(TIMS->TCCR0,CS01);
						SET_BIT(TIMS->TCCR0,CS02);
						break;
					default:
						break;
				}
				break;
			case (TIM1):
				switch(copy_TIMS_CLOCK){
					case TIMS_STOP:
						CLR_BIT(TIMS->TCCR1B,CS10);
						CLR_BIT(TIMS->TCCR1B,CS11);
						CLR_BIT(TIMS->TCCR1B,CS12);
						break;
					case TIMS_DIVISION_1:
						SET_BIT(TIMS->TCCR1B,CS10);
						CLR_BIT(TIMS->TCCR1B,CS11);
						CLR_BIT(TIMS->TCCR1B,CS12);
						break;
					case TIMS_DIVISION_8:
						CLR_BIT(TIMS->TCCR1B,CS10);
						SET_BIT(TIMS->TCCR1B,CS11);
						CLR_BIT(TIMS->TCCR1B,CS12);
						break;
					case TIMS_DIVISION_64:
						SET_BIT(TIMS->TCCR1B,CS10);
						SET_BIT(TIMS->TCCR1B,CS11);
						CLR_BIT(TIMS->TCCR1B,CS12);
						break;
					case TIMS_DIVISION_256:
						CLR_BIT(TIMS->TCCR1B,CS10);
						CLR_BIT(TIMS->TCCR1B,CS11);
						SET_BIT(TIMS->TCCR1B,CS12);
						break;
					case TIMS_DIVISION_1024:
						SET_BIT(TIMS->TCCR1B,CS10);
						CLR_BIT(TIMS->TCCR1B,CS11);
						SET_BIT(TIMS->TCCR1B,CS12);
						break;
					case TIM0_TIM1_T_PIN_FALLINGEVENT:
						CLR_BIT(TIMS->TCCR1B,CS10);
						SET_BIT(TIMS->TCCR1B,CS11);
						SET_BIT(TIMS->TCCR1B,CS12);
						break;
					case TIM0_TIM1_T_PIN_RISINGEVENT:
						SET_BIT(TIMS->TCCR1B,CS10);
						SET_BIT(TIMS->TCCR1B,CS11);
						SET_BIT(TIMS->TCCR1B,CS12);
						break;
					default:
						break;
						}
				break;
			case (TIM2):
				switch(copy_TIMS_CLOCK){
					case TIMS_STOP:
						CLR_BIT(TIMS->TCCR2,CS20);
						CLR_BIT(TIMS->TCCR2,CS21);
						CLR_BIT(TIMS->TCCR2,CS22);
						break;
					case TIMS_DIVISION_1:
						SET_BIT(TIMS->TCCR2,CS20);
						CLR_BIT(TIMS->TCCR2,CS21);
						CLR_BIT(TIMS->TCCR2,CS22);
						break;
					case TIMS_DIVISION_8:
						CLR_BIT(TIMS->TCCR2,CS20);
						SET_BIT(TIMS->TCCR2,CS21);
						CLR_BIT(TIMS->TCCR2,CS22);
						break;
					case TIM2_DIVISION_32:
						SET_BIT(TIMS->TCCR2,CS20);
						SET_BIT(TIMS->TCCR2,CS21);
						CLR_BIT(TIMS->TCCR2,CS22);
						break;
					case TIMS_DIVISION_64:
						CLR_BIT(TIMS->TCCR2,CS20);
						CLR_BIT(TIMS->TCCR2,CS21);
						SET_BIT(TIMS->TCCR2,CS22);
						break;
					case TIM2_DIVISION_128:
						SET_BIT(TIMS->TCCR2,CS20);
						CLR_BIT(TIMS->TCCR2,CS21);
						SET_BIT(TIMS->TCCR2,CS22);
						break;
					case TIMS_DIVISION_256:
						CLR_BIT(TIMS->TCCR2,CS20);
						SET_BIT(TIMS->TCCR2,CS21);
						SET_BIT(TIMS->TCCR2,CS22);
						break;
					case TIMS_DIVISION_1024:
						SET_BIT(TIMS->TCCR2,CS20);
						SET_BIT(TIMS->TCCR2,CS21);
						SET_BIT(TIMS->TCCR2,CS22);
						break;
					default:
						break;
						}
				break;
			default:
				break;

		}

}
void TIM_voidStop(TIM_ID copy_TIM_ID){
	switch(copy_TIM_ID){
			case (TIM0):
				CLR_BIT(TIMS->TCCR0,CS00);
				CLR_BIT(TIMS->TCCR0,CS01);
				CLR_BIT(TIMS->TCCR0,CS02);
				break;
			case (TIM1):
				CLR_BIT(TIMS->TCCR1B,CS10);
				CLR_BIT(TIMS->TCCR1B,CS11);
				CLR_BIT(TIMS->TCCR1B,CS12);
				break;
			case (TIM2):
				CLR_BIT(TIMS->TCCR2,CS20);
				CLR_BIT(TIMS->TCCR2,CS21);
				CLR_BIT(TIMS->TCCR2,CS22);
				break;
			default:
				break;
		}
}
void TIM_voidEnableIntterput(TIM_INTERRUPT_ID copy_TIM_INTERRUPT_ID){
	switch(copy_TIM_INTERRUPT_ID){
		case(TOI0):
			SET_BIT(TIMS->TIMSK,TOIE0);
			break;
		case(OCI0):
			SET_BIT(TIMS->TIMSK,OCIE0);
			break;
		case(TOI1):
			SET_BIT(TIMS->TIMSK,TOIE1);
			break;
		case(OCI1B):
			SET_BIT(TIMS->TIMSK,OCIE1B);
			break;
		case(OCI1A):
			SET_BIT(TIMS->TIMSK,OCI1A);
			break;
		case(TICI1):
			SET_BIT(TIMS->TIMSK,TICIE1);
			break;
		case(TOI2):
			SET_BIT(TIMS->TIMSK,TOIE2);
			break;
		case(OCI2):
			SET_BIT(TIMS->TIMSK,OCIE2);
			break;
		default:
			break;
	}
	SET_BIT(TIMS->SREG,GIE);
}
void TIM_voidDisableIntterput(TIM_INTERRUPT_ID copy_TIM_INTERRUPT_ID){
	switch(copy_TIM_INTERRUPT_ID){
		case(TOI0):
			CLR_BIT(TIMS->TIMSK,TOIE0);
			break;
		case(OCI0):
			CLR_BIT(TIMS->TIMSK,OCIE0);
			break;
		case(TOI1):
			CLR_BIT(TIMS->TIMSK,TOIE1);
			break;
		case(OCI1B):
			CLR_BIT(TIMS->TIMSK,OCIE1B);
			break;
		case(OCI1A):
			CLR_BIT(TIMS->TIMSK,OCI1A);
			break;
		case(TICI1):
			CLR_BIT(TIMS->TIMSK,TICIE1);
			break;
		case(TOI2):
			CLR_BIT(TIMS->TIMSK,TOIE2);
			break;
		case(OCI2):
			CLR_BIT(TIMS->TIMSK,OCIE2);
			break;
		default:
			break;
		}
}
void TIM_voidGetISR(TIM_INTERRUPT_ID copy_TIM_INTERRUPT_ID,void (*pf)(void)){
	switch(copy_TIM_INTERRUPT_ID){
		case(TOI0):
			TIMER0_OVF_pf=pf;
			break;
		case(OCI0):
			TIMER0_COMP_pf=pf;
			break;
		case(TOI1):
			TIMER1_OVF_pf=pf;
			break;
		case(OCI1B):
			TIMER1_COMPB_pf=pf;
			break;
		case(OCI1A):
			TIMER1_COMPA_pf=pf;
			break;
		case(TICI1):
			TIMER1_CAPT_pf=pf;
			break;
		case(TOI2):
			TIMER2_OVF_pf=pf;
			break;
		case(OCI2):
			TIMER2_COMP_pf=pf;
			break;
		default:
			break;
			}
}
u16  TIM_u16GetTimerCount(TIM_ID copy_TIM_ID){
	switch(copy_TIM_ID){
		case (TIM0):
				return (u16) TIMS->TCNT0;
			break;
		case (TIM1):
				return (u16) TIMS->TCNT1;
			break;
		case (TIM2):
				return (u16) TIMS->TCNT2;
			break;
		default:
				return (u16) 0;
			break;

	}
}
void TIM_voidSetComperMatch(TIMS_COMPERMATCH_T copy_TIMS_COMPERMATCH_T,u16 copy_u16ComperMatchValue){
	switch(copy_TIMS_COMPERMATCH_T){
	case(OC0):
		TIMS->OCR0 =	(u8)copy_u16ComperMatchValue;
	break;
	case(OC1B):
		TIMS->OCR1B =	(u16)copy_u16ComperMatchValue;
		break;
	case(OC1A):
		TIMS->OCR1A =	(u16)copy_u16ComperMatchValue;
		break;
	case(ICR):
		TIMS->ICR1 =	(u16)copy_u16ComperMatchValue;
		break;
	case(OC2):
		TIMS->OCR2 = 	(u8)copy_u16ComperMatchValue;
		break;
	default:
		break;
	}
}
void TIM_voidSetCountRegister(TIM_ID copy_TIM_ID, u16 copy_u16CountValue){
	switch(copy_TIM_ID){
		case (TIM0):
			TIMS->TCNT0=	(u8)copy_u16CountValue;
			break;
		case (TIM1):
			TIMS->TCNT1=	(u16)copy_u16CountValue;
			break;
		case (TIM2):
			TIMS->TCNT2=	(u8)copy_u16CountValue;
			break;
		default:
			break;

		}
}
void TIM_voidMakeActionAsynchronous(TIM_ID copy_TIM_ID,u32 copy_Delay_ms,void (*pf)(void)){
	u32 TickTime=1024/TIM_CPU_F;
	u16 Drisredcounts=0;
	u32 OverFlowTime=0;
	switch(copy_TIM_ID){
			case (TIM0):
				OverFlowTime=TickTime*TIM0_OVERFLOW_COUNTS;
				TIM0_OverFlowTimes=(copy_Delay_ms*1000)/OverFlowTime;
				Drisredcounts=(copy_Delay_ms*1000)%OverFlowTime;
				TIM0_PreLoadCunts=TIM0_OVERFLOW_COUNTS-(Drisredcounts/TickTime);
				TIM_voidIni(TIM0);
				TIM_voidSetCountRegister(TIM0,TIM0_PreLoadCunts);
				TIM_voidEnableIntterput(TOI0);
				TIM0_ActionAsynchronou_ptr=pf;
				TIM_voidGetISR(TOI0,TIM0_ActionAsynchronou);
				TIM_voidStart(TIM0,TIMS_DIVISION_1024);
				break;
			case (TIM1):
				TickTime=8/TIM_CPU_F;
				OverFlowTime=TickTime*TIM1_OVERFLOW_COUNTS;
				TIM1_OverFlowTimes=(copy_Delay_ms*1000)/OverFlowTime;
				Drisredcounts=(copy_Delay_ms*1000)%OverFlowTime;
				TIM1_PreLoadCunts=TIM1_OVERFLOW_COUNTS-(Drisredcounts/TickTime);
				TIM_voidIni(TIM1);
				TIM_voidSetCountRegister(TIM1,TIM1_PreLoadCunts);
				TIM_voidEnableIntterput(TOI1);
				TIM1_ActionAsynchronou_ptr=pf;
				TIM_voidGetISR(TOI1,TIM1_ActionAsynchronou);
				TIM_voidStart(TIM1,TIMS_DIVISION_8);
				break;
			case (TIM2):
				OverFlowTime=TickTime*TIM2_OVERFLOW_COUNTS;
				TIM2_OverFlowTimes=(copy_Delay_ms*1000)/OverFlowTime;
				Drisredcounts=(copy_Delay_ms*1000)%OverFlowTime;
				TIM2_PreLoadCunts=TIM2_OVERFLOW_COUNTS-(Drisredcounts/TickTime);
				TIM_voidIni(TIM2);
				TIM_voidSetCountRegister(TIM2,TIM2_PreLoadCunts);
				TIM_voidEnableIntterput(TOI2);
				TIM2_ActionAsynchronou_ptr=pf;
				TIM_voidGetISR(TOI2,TIM2_ActionAsynchronou);
				TIM_voidStart(TIM2,TIMS_DIVISION_1024);
				break;
			default:
				break;

			}
}
void TIM_voidSetPWMDC(TIMS_COMPERMATCH_T copy_TIMS_COMPERMATCH_T,f32 copy_DC){

	switch(copy_TIMS_COMPERMATCH_T){
			case (OC0):
			#if((OC0_MODE==OC_CLEAR_COMPARE_SET_ON_BOTTOM)||(OC0_MODE==OC_CLEAR_UP_SET_DOWN))
				TIM_voidSetComperMatch(OC0,((copy_DC*TIM0_OVERFLOW_COUNTS)/100));
			#elif((OC0_MODE==OC_SET_COMPARE_CLEAR_ON_BOTTOM)||(OC0_MODE==OC_SET_UP_CLEAR_DOWN))
				TIM_voidSetComperMatch(OC0,(TIM0_OVERFLOW_COUNTS-((copy_DC*TIM0_OVERFLOW_COUNTS)/100)));
			#endif
				break;
			case (OC1A):
			#if((OC1A_MODE==OC_CLEAR_COMPARE_SET_ON_BOTTOM)||(OC1A_MODE==OC_CLEAR_UP_SET_DOWN))
				TIM_voidSetComperMatch(OC1A,((copy_DC*TIMS_TOP_TIM1)/100));
			#elif((OC1A_MODE==OC_SET_COMPARE_CLEAR_ON_BOTTOM)||(OC1A_MODE==OC_SET_UP_CLEAR_DOWN))
				TIM_voidSetComperMatch(OC1A,(TIMS_TOP_TIM1-((copy_DC*TIMS_TOP_TIM1)/100)));
			#endif
				break;
			case (OC1B):
			#if((OC1B_MODE==OC_CLEAR_COMPARE_SET_ON_BOTTOM)||(OC1B_MODE==OC_CLEAR_UP_SET_DOWN))
				TIM_voidSetComperMatch(OC1B,((copy_DC*TIMS_TOP_TIM1)/100));
			#elif((OC1B_MODE==OC_SET_COMPARE_CLEAR_ON_BOTTOM)||(OC1B_MODE==OC_SET_UP_CLEAR_DOWN))
				TIM_voidSetComperMatch(OC1B,(TIMS_TOP_TIM1-((copy_DC*TIMS_TOP_TIM1)/100)));
			#endif
				break;
			case (OC2):
			#if((OC2_MODE==OC_CLEAR_COMPARE_SET_ON_BOTTOM)||(OC2_MODE==OC_CLEAR_UP_SET_DOWN))
				TIM_voidSetComperMatch(OC2,((copy_DC*TIM2_OVERFLOW_COUNTS)/100));
			#elif((OC2_MODE==OC_SET_COMPARE_CLEAR_ON_BOTTOM)||(OC2_MODE==OC_SET_UP_CLEAR_DOWN))
				TIM_voidSetComperMatch(OC2,(TIM2_OVERFLOW_COUNTS-((copy_DC*TIM2_OVERFLOW_COUNTS)/100)));
			#endif
				break;
			default:
				break;

			}

}
static void TIM0_ActionAsynchronou(void){
	u32 static counter=0;
	if (counter==TIM0_OverFlowTimes+1){
		if(TIM0_ActionAsynchronou_ptr!=NULL){
			TIM_voidSetCountRegister(TIM0,TIM0_PreLoadCunts);
			TIM0_ActionAsynchronou_ptr();
		}
		counter=0;
	}
	else{
	counter++;
	}
}
static void TIM1_ActionAsynchronou(void){
	u32 static counter=0;
	if (counter==TIM1_OverFlowTimes+1){
		if(TIM1_ActionAsynchronou_ptr!=NULL){
			TIM_voidSetCountRegister(TIM1,TIM1_PreLoadCunts);
			TIM1_ActionAsynchronou_ptr();

		}
		counter=0;
	}
	else{
		counter++;
		}
}
static void TIM2_ActionAsynchronou(void){
	u32 static counter=0;
	if (counter==TIM2_OverFlowTimes+1){
		if(TIM2_ActionAsynchronou_ptr!=NULL){
			TIM_voidSetCountRegister(TIM2,TIM2_PreLoadCunts);
			TIM2_ActionAsynchronou_ptr();
		}
	counter=0;
	}
	else{
		counter++;
		}
}

void __vector_4(void) __attribute__((signal));
void __vector_4(void){
if(TIMER2_COMP_pf!=NULL){
	TIMER2_COMP_pf();
}
}


void __vector_5(void) __attribute__((signal));
void __vector_5(void){
	if(TIMER2_OVF_pf!=NULL){
		TIMER2_OVF_pf();
	}
}
void __vector_6(void) __attribute__((signal));
void __vector_6(void){
	if(TIMER1_CAPT_pf!=NULL){
		TIMER1_CAPT_pf();
	}
}
void __vector_7(void) __attribute__((signal));
void __vector_7(void){
	if(TIMER1_COMPA_pf!=NULL){
		TIMER1_COMPA_pf();
	}
}
void __vector_8(void) __attribute__((signal));
void __vector_8(void){
	if(TIMER1_COMPB_pf!=NULL){
		TIMER1_COMPB_pf();
	}
}
void __vector_9(void) __attribute__((signal));
void __vector_9(void){
	if(TIMER1_OVF_pf!=NULL){
		TIMER1_OVF_pf();
	}
}

void __vector_10(void) __attribute__((signal));
void __vector_10(void){
	if(TIMER0_COMP_pf!=NULL){
		TIMER0_COMP_pf();
	}
}
void __vector_11(void) __attribute__((signal));
void __vector_11(void){
	if(TIMER0_OVF_pf!=NULL){
		TIMER0_OVF_pf();
	}
}
