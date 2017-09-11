/*
 * main.h
 *
 *  Created on: Oct 30, 2016
 *      Author: VIJOY-PC
 */

#ifndef INCLUDES_SYSTEM_MAIN_H_
#define INCLUDES_SYSTEM_MAIN_H_

#include "uart.h"
#include "buffer.h"
#include "nvic.h"

#include "msg.h"
#include "frdm_msg.h"
#include "led.h"

#include "MKL25Z4.h"
#include "stdint.h"
#include "logger.h"
#include "dma.h"
#include "profiler.h"
#include "memory.h"
#include "nRF24L01.h"
#include "spi.h"
#define Get_Status
#define Read_Register
#define Write_Register
#define Read_PayLoad
#define Write_PayLoad



#define LOG			//to enable uart logging
//#define MSG
//#define DMA_test
//#define DMA_OPT

#endif /* INCLUDES_SYSTEM_MAIN_H_ */
