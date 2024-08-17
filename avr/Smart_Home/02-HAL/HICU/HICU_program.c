#include "../../00-LIB/LSTD_types.h"
#include "../../00-LIB/LBIT_math.h"

#include "HICU_private.h"
#include "HICU_config.h"
#include "HICU_interface.h"
#include "../../03-MCAL/TIM/TIM_interface.h"
#include "../../03-MCAL/EXTI/EXTI.h"


#define HICU_TIM_TICKTIME_US	((f32)HICU_TIM_PRESCALR/HICU_CPU_F_MHZ)

#if(HICU_ATTACH_TIM==HICU_ATTACH_TIM_TIM0)
	#define HICU_ATTACHED_TIM		TIM0
	#define HICU_TIM_TYPE			u8
#elif(HICU_ATTACH_TIM==HICU_ATTACH_TIM_TIM1)
	#define HICU_ATTACHED_TIM		TIM1
	#define HICU_TIM_TYPE			u16
#elif(HICU_ATTACH_TIM==HICU_ATTACH_TIM_TIM2)
	#define HICU_ATTACHED_TIM		TIM2
	#define HICU_TIM_TYPE			u8
#else
	#error "HICU_ATTACH_TIM configration is not correct"
#endif

#if(HICU_ATTACH_EXTI==HICU_ATTACH_EXTI_EXTI0)
	#define HICU_ATTACHED_EXTI		EXT_INT0
#elif(HICU_ATTACH_EXTI==HICU_ATTACH_EXTI_EXTI1)
	#define HICU_ATTACHED_EXTI		EXT_INT1
#elif(HICU_ATTACH_EXTI==HICU_ATTACH_EXTI_EXTI2)
	#define HICU_ATTACHED_EXTI		EXT_INT2
#else
	#error "HICU_ATTACH_EXTI configration is not correct"
#endif

void HICU_voidAttachICU(void){
	Intrrupt_Init(HICU_ATTACHED_EXTI,RISING);
	Intrrupt_GetFun(HICU_ATTACHED_EXTI,HICU_voidICUAlgorithm);
	Intrrupt_Enabled(HICU_ATTACHED_EXTI);
}
void HICU_voidGetPWMVlues(f32 * ptr_f32DutyCycle,f32 * ptr_f32Frequncy){
	*ptr_f32DutyCycle=DutyCycle;
	*ptr_f32Frequncy=Frequncy;
}

static void HICU_voidICUAlgorithm(void){
	static volatile HICU_STATE_T State=HICU_ICU_FIRST_RISING;
	static volatile HICU_TIM_TYPE Local_TIMTypeTempCount=0;
	static volatile HICU_TIM_TYPE Local_TIMTypePWMTimeONCount=0;
	static volatile HICU_TIM_TYPE Local_TIMTypePWMTimeOFFCount=0;
	switch(State){
		case(HICU_ICU_FIRST_RISING):
				 Local_TIMTypeTempCount=TIM_u16GetTimerCount(HICU_ATTACHED_TIM);
				 Intrrupt_Init(HICU_ATTACHED_EXTI,FALLING);
				 State=HICU_ICU_FALLING;
		break;
		case(HICU_ICU_FALLING):
				 Local_TIMTypePWMTimeONCount=TIM_u16GetTimerCount(HICU_ATTACHED_TIM)-Local_TIMTypeTempCount;
				 Local_TIMTypeTempCount=TIM_u16GetTimerCount(HICU_ATTACHED_TIM);
				 Intrrupt_Init(HICU_ATTACHED_EXTI,RISING);
				 State=HICU_ICU_SECOND_RISING;
		break;
		case(HICU_ICU_SECOND_RISING):
				 Local_TIMTypePWMTimeOFFCount=TIM_u16GetTimerCount(HICU_ATTACHED_TIM)-Local_TIMTypeTempCount;
				 Frequncy= (f32)1000000/(((f32)(Local_TIMTypePWMTimeONCount+Local_TIMTypePWMTimeOFFCount))*HICU_TIM_TICKTIME_US);
				 DutyCycle= ((f32)Local_TIMTypePWMTimeONCount/((f32)Local_TIMTypePWMTimeONCount+Local_TIMTypePWMTimeOFFCount))*100;
				 State=HICU_ICU_FIRST_RISING;
		break;
		default:
		break;

	}
}
