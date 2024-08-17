/*
 * WDT_program.c
 *
 *  Created on: Aug 6, 2024
 *      Author: eng_youssef_goher
 */
#include "../../00-LIB/LSTD_types.h"
#include "../../00-LIB/LBIT_math.h"

#include "WDT_private.h"
#include "WDT_config.h"
#include "WDT_interface.h"


void WDT_voidStart(WDT_MODE_T Mode){
	switch(Mode){
		case WDT_MODE_16K:
			CLR_BIT(WDTCR,WDP0);
			CLR_BIT(WDTCR,WDP1);
			CLR_BIT(WDTCR,WDP2);
			break;
		case WDT_MODE_32K:
			SET_BIT(WDTCR,WDP0);
			CLR_BIT(WDTCR,WDP1);
			CLR_BIT(WDTCR,WDP2);
			break;
		case WDT_MODE_64K:
			CLR_BIT(WDTCR,WDP0);
			SET_BIT(WDTCR,WDP1);
			CLR_BIT(WDTCR,WDP2);
			break;
		case WDT_MODE_128K:
			SET_BIT(WDTCR,WDP0);
			SET_BIT(WDTCR,WDP1);
			CLR_BIT(WDTCR,WDP2);
			break;
		case WDT_MODE_256K:
			CLR_BIT(WDTCR,WDP0);
			CLR_BIT(WDTCR,WDP1);
			SET_BIT(WDTCR,WDP2);
			break;
		case WDT_MODE_512K:
			SET_BIT(WDTCR,WDP0);
			CLR_BIT(WDTCR,WDP1);
			SET_BIT(WDTCR,WDP2);
							break;
		case WDT_MODE_1024K:
			CLR_BIT(WDTCR,WDP0);
			SET_BIT(WDTCR,WDP1);
			SET_BIT(WDTCR,WDP2);
			break;
		case WDT_MODE_2048K:
			SET_BIT(WDTCR,WDP0);
			SET_BIT(WDTCR,WDP1);
			SET_BIT(WDTCR,WDP2);
			break;
		default:
			break;
	}
	SET_BIT(WDTCR,WDE);
}

void WDT_voidDisable(void){
	WDTCR|=0x18;
	WDTCR=0;
}












