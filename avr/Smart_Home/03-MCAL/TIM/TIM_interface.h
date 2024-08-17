/*
 * TIM_interface.h
 *
 *  Created on: Aug 3, 2024
 *      Author: eng_youssef_goher
 */

#ifndef __MCAL_TIM_TIM_INTERFACE_H_
#define __MCAL_TIM_TIM_INTERFACE_H_

#define TIM0_OVERFLOW_COUNTS	256U
#define TIM1_OVERFLOW_COUNTS	65536U
#define TIM2_OVERFLOW_COUNTS	256U

/*
 *	AVR TIMS ID
 */
typedef enum{
	TIM0,
	TIM1,
	TIM2
}TIM_ID;

/*
 *	AVR TIMS Interrupt ID
 */
typedef enum{
	TOI0,
	OCI0,
	TOI1,
	OCI1B,
	OCI1A,
	TICI1,
	TOI2,
	OCI2
}TIM_INTERRUPT_ID;

/*
 *	TIM0 & TIM1 Clock Select
 */
typedef enum{
TIMS_STOP,
TIMS_DIVISION_1,
TIMS_DIVISION_8,
TIM2_DIVISION_32,
TIMS_DIVISION_64,
TIM2_DIVISION_128,
TIMS_DIVISION_256,
TIMS_DIVISION_1024,
TIM0_TIM1_T_PIN_FALLINGEVENT,
TIM0_TIM1_T_PIN_RISINGEVENT,
}TIMS_CLOCK_T;

/*
 * ComperMatch ID
 */
typedef enum{
	OC0,
	OC1B,
	OC1A,
	OC2,
	ICR
}TIMS_COMPERMATCH_T;
void TIM_voidIni(TIM_ID copy_TIM_ID);
void TIM_voidStart(TIM_ID copy_TIM_ID,TIMS_CLOCK_T copy_TIMS_CLOCK);
void TIM_voidStop(TIM_ID copy_TIM_ID);
void TIM_voidEnableIntterput(TIM_INTERRUPT_ID copy_TIM_INTERRUPT_ID);
void TIM_voidDisableIntterput(TIM_INTERRUPT_ID copy_TIM_INTERRUPT_ID);
void TIM_voidGetISR(TIM_INTERRUPT_ID copy_TIM_INTERRUPT_ID,void (*pf)(void));
u16  TIM_u16GetTimerCount(TIM_ID copy_TIM_ID);
void TIM_voidSetComperMatch(TIMS_COMPERMATCH_T copy_TIMS_COMPERMATCH_T, u16 copy_u16ComperMatchValue);
void TIM_voidSetCountRegister(TIM_ID copy_TIM_ID, u16 copy_u16CountValue);
void TIM_voidMakeActionAsynchronous(TIM_ID copy_TIM_ID,u32 copy_Delay_ms,void (*pf)(void));
void TIM_voidSetPWMDC(TIMS_COMPERMATCH_T copy_TIMS_COMPERMATCH_T,f32 copy_DC);
#endif /* 03_MCAL_TIM_TIM_INTERFACE_H_ */
