/*
 * interrupt.h
 *
 *  Created on: Aug 16, 2023
 *      Author: eng_youssef_goher
 */

#ifndef EXTI_H_
#define EXTI_H_

/*ID of EXinterrupt*/
#define EXT_INT0 0
#define EXT_INT1 1
#define EXT_INT2 2

/*modes of EXinterrupt*/
#define RISING		0
#define FALLING 	1
#define LOW_LEVEL	2
#define TOGGLING 	3

#define GIE	7
/*functions of EXinterrupt*/
void Intrrupt_Init(u8 copy_u8Intrrupt_id,u8 copy_u8Intrrupt_mode);
void Intrrupt_Enabled(u8 copy_u8Intrrupt_id);
void Intrrupt_Disabled(u8 copy_u8Intrrupt_id);
void Intrrupt_GetFun(u8 copy_u8Intrrupt_id,void (*pf)(void));
#endif /* EXTI_H_ */
