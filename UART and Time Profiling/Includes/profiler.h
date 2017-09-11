/*
 * profiler.h
 *
 *  Created on: Oct 11, 2016
 *      Author: VIJOY-PC
 */

#include "system_MKL25Z4.h"
#ifndef INCLUDES_PROFILER_H_
#define INCLUDES_PROFILER_H_

#define MOD_VAL 39		//to get time period of 10Us
#define T1CLK  	4

void start_time(void);
void end_time(void);
void init_profiler(void);


volatile extern uint32_t overflow_count;
#endif /* INCLUDES_PROFILER_H_ */
