/*
 * WDT.h
 *
 *  Created on: Feb 6, 2023
 *      Author: Almodather
 */

#ifndef WDT_H_
#define WDT_H_

/****WDT REGISTER*****/


#define WATCHDOG_WDTCR 			*((volatile u8*)0x41)

#define WATCHDOG_WDTCR_WDTOE	4
#define WATCHDOG_WDTCR_WDE		3
#define WATCHDOG_WDTCR_WDP2		2
#define WATCHDOG_WDTCR_WDP1		1
#define WATCHDOG_WDTCR_WDP0		0



/***WDT TIMING**********/

#define WDT_TIMING_16_3_MS		0
#define WDT_TIMING_32_5_MS		1
#define WDT_TIMING_65_MS		2
#define WDT_TIMING_0_13_S		3
#define WDT_TIMING_0_26_S		4
#define WDT_TIMING_0_52_S		5
#define WDT_TIMING_1_S			6
#define WDT_TIMING_2_1_S		7

/**************WDT OPERATION**********************/
#define WDT_START(TIMING)		WATCHDOG_WDTCR|= (1<<WATCHDOG_WDTCR_WDE) | TIMING

#define WDT_STOP()				do\
								{\
								\
								WATCHDOG_WDTCR|=(1<<WATCHDOG_WDTCR_WDTOE)| (1<<WATCHDOG_WDTCR_WDE); \
								WATCHDOG_WDTCR=0x00;\
								asm("WDR");\
								}while(0)



#define WDT_REFRESH()			asm("WDR");


#endif /* WDT_H_ */
