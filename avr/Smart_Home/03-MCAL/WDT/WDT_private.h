/*
 * WDT_private.h
 *
 *  Created on: Aug 6, 2024
 *      Author: eng_youssef_goher
 */

#ifndef __MCAL_WDT_WDT_PRIVATE_H_
#define __MCAL_WDT_WDT_PRIVATE_H_

#define WDTCR		(*((volatile u8 *)(0X41U)))

enum{
	WDTOE=4,
	WDE=3,
	WDP2=2,
	WDP1=1,
	WDP0=0,
};

#endif /* 03_MCAL_WDT_WDT_PRIVATE_H_ */
