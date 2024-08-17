/*
 * TWI_config.h
 *
 *  Created on: Aug 8, 2024
 *      Author: eng_youssef_goher
 */

#ifndef __MCAL_TWI_TWI_CONFIG_H_
#define __MCAL_TWI_TWI_CONFIG_H_

/*
 * CPU clock frequency in the must be at least 16 times higher than the SCL frequency
 * MASTER or SLAVE Clock_max= CPU_FREQUENCY/16
 * MASTER Clock_min =CPU_FREQUENCY/2056
 */

#define TWI_CPU_FREQUENCY_HZ		8000000U

/*
 * MAX Number OF RESTARTS until the bus accepts Start condition
 */

#define MAX_RESTARTS 				20


#endif /* 03_MCAL_TWI_TWI_CONFIG_H_ */
