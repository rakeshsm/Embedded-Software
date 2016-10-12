/*
 * profiler.h
 *
 *  Created on: Oct 11, 2016
 *      Author: VIJOY-PC
 */

#include "system_MKL25Z4.h"
#ifndef INCLUDES_PROFILER_H_
#define INCLUDES_PROFILER_H_

#define MOD_VAL 65535
#define T1CLK  	CPU_INT_FAST_CLK_HZ

void start_time(void);
uint16_t end_time(void);
void init_profiler(void);

extern uint8_t overflow_count;
#endif /* INCLUDES_PROFILER_H_ */
