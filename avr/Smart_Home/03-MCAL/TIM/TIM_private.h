/*
 * TIM_private.h
 *
 *  Created on: Aug 3, 2024
 *      Author: Mina.W
 */

#ifndef __MCAL_TIM_TIM_PRIVATE_H_
#define __MCAL_TIM_TIM_PRIVATE_H_
/*
 * ATMAGE32 TIMERS
 */
typedef struct{
	volatile u8 	OCR2;
	volatile u8 	TCNT2;
	volatile u8 	TCCR2;
	volatile u16	ICR1;
	volatile u16	OCR1B;
	volatile u16	OCR1A;
	volatile u16	TCNT1;
	volatile u8		TCCR1B;
	volatile u8		TCCR1A;
	volatile u8	 	RES1[2];
	volatile u8	 	TCNT0;
	volatile u8	 	TCCR0;
	volatile u8	 	RES2[4];
	volatile u8	 	TIFR;
	volatile u8	 	TIMSK;
	volatile u8	 	RES3[2];
	volatile u8	 	OCR0;
	volatile u8	 	RES4[2];
	volatile u8	 	SREG;
}TIM_T ;
#define  GIE			7
#define TIMS ((volatile TIM_T*)(0x43U))
/*
 *TCCR2
 */
enum{
	 FOC2	=7,
	 WGM20	=6,
	 COM21	=5,
	 COM20	=4,
	 WGM21	=3,
	 CS22	=2,
	 CS21	=1,
	 CS20	=0
};
/*
 *TCCR1B
 */
enum{
	 ICNC1	=7,
	 ICES1	=6,
	 WGM13	=4,
	 WGM12	=3,
	 CS12	=2,
	 CS11	=1,
	 CS10	=0
};
/*
 *TCCR1A
 */
enum{
	COM1A1	=7,
	COM1A0	=6,
	COM1B1	=5,
	COM1B0	=4,
	FOC1A	=3,
	FOC1B	=2,
	WGM11	=1,
	WGM10	=0
};
/*
 *TCCR1
 */
enum{
	FOC0	=7,
	WGM00	=6,
	COM01	=5,
	COM00	=4,
	WGM01	=3,
	CS02	=2,
	CS01	=1,
	CS00	=0
};
/*
 *TIFR
 */
enum{
	OCF2	=7,
	TOV2	=6,
	ICF1	=5,
	OCF1A	=4,
	OCF1B	=3,
	TOV1	=2,
	OCF0	=1,
	TOV0	=0
};

/*
 *TIMSK
 */
enum{
	OCIE2	=7,
	TOIE2	=6,
	TICIE1	=5,
	OCIE1A	=4,
	OCIE1B	=3,
	TOIE1	=2,
	OCIE0	=1,
	TOIE0	=0
};

/*
 *TIM0 & TIM2 Waveform Generation Mode Options
 */
#define TIM0_TIM2_NORMAL				18
#define TIM0_TIM2_PWM_PHASECORRECT		19
#define TIM0_TIM2_CTC					20
#define TIM0_TIM2_FAST_PWM				21

/*
 *TIM1 Waveform Generation Mode Options
 */
#define TIM1_NORMAL						1
#define TIM1_PWM_PHASECORRECT_8BIT		2
#define TIM1_PWM_PHASECORRECT_9BIT		3
#define TIM1_PWM_PHASECORRECT_10BIT		4
#define TIM1_CTC_TOP_OCR1A				5
#define TIM1_FAST_PWM_8BIT				6
#define TIM1_FAST_PWM_9BIT				7
#define TIM1_FAST_PWM_10BIT				8
#define TIM1_PWM_PHASE_FRE_TOP_ICR1		9
#define TIM1_PWM_PHASE_FRE_TOP_OCR1A	10
#define TIM1_PWM_PHASECORRECT_TOP_ICR1	11
#define TIM1_PWM_PHASECORRECT_TOP_OCR1A	12
#define TIM1_CTC_TOP_ICR1				13
#define TIM1_FAST_TOP_ICR1				15
#define TIM1_FAST_TOP_OCR1A				16

/*
 * Force Output Compare Options
 */
#define ENABLE_FORCE_OUTPUT_COMPARE		1
#define DISABLE_FORCE_OUTPUT_COMPARE	2

/*
 * Compare Output Mode, non-PWM Mode
 */
#define OC_DISCONNECTED					1
#define OC_TOGGLE						2
#define OC_CLEAR						3
#define OC_SET							4

/*
 * Compare Output Mode, Fast PWM Mode
 */
#define OC_CLEAR_COMPARE_SET_ON_BOTTOM	6
#define OC_SET_COMPARE_CLEAR_ON_BOTTOM	7

/*
 * Compare Output Mode, Phase Correct PWM Mode
 */
#define OC_CLEAR_UP_SET_DOWN			9
#define OC_SET_UP_CLEAR_DOWN			10

/*
 * TIMS ISR
 */
static void(*TIMER2_COMP_pf)(void)=NULL;
static void(*TIMER2_OVF_pf)(void)=NULL;
static void(*TIMER1_CAPT_pf)(void)=NULL;
static void(*TIMER1_COMPA_pf)(void)=NULL;

static void(*TIMER1_COMPB_pf)(void)=NULL;
static void(*TIMER1_OVF_pf)(void)=NULL;
static void(*TIMER0_COMP_pf)(void)=NULL;
static void(*TIMER0_OVF_pf)(void)=NULL;

/*
 * ActionAsynchronou Part
 */
static void (*TIM0_ActionAsynchronou_ptr)(void)=NULL;
static void (*TIM1_ActionAsynchronou_ptr)(void)=NULL;
static void (*TIM2_ActionAsynchronou_ptr)(void)=NULL;

static void TIM0_ActionAsynchronou(void);
static void TIM1_ActionAsynchronou(void);
static void TIM2_ActionAsynchronou(void);
static u8 	TIM0_PreLoadCunts=0;
static u16 	TIM1_PreLoadCunts=0;
static u8 	TIM2_PreLoadCunts=0;
static u32 	TIM0_OverFlowTimes=0;
static u32 	TIM1_OverFlowTimes=0;
static u32 	TIM2_OverFlowTimes=0;
#endif /* 03_MCAL_TIM_TIM_PRIVATE_H_ */
