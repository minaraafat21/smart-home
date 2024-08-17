/*
 * WDT_interface.h
 *
 *  Created on: Aug 6, 2024
 *      Author: eng_youssef_goher
 */

#ifndef __MCAL_WDT_WDT_INTERFACE_H_
#define __MCAL_WDT_WDT_INTERFACE_H_

typedef enum{
	WDT_MODE_16K, 	//5.0V ->16.3ms
	WDT_MODE_32K,	//5.0V ->32.5ms
	WDT_MODE_64K,	//5.0V ->65ms
	WDT_MODE_128K,	//5.0V ->0.13s
	WDT_MODE_256K,	//5.0V ->0.26s
	WDT_MODE_512K,	//5.0V ->0.52s
	WDT_MODE_1024K,	//5.0V ->1.0s
	WDT_MODE_2048K,	//5.0V ->2.1s
}WDT_MODE_T;


void WDT_voidStart(WDT_MODE_T Mode);
void WDT_voidDisable(void);

#endif /* 03_MCAL_WDT_WDT_INTERFACE_H_ */
