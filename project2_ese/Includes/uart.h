/*
 * uart.h
 *
 *  Created on: Oct 10, 2016
 *      Author: VIJOY-PC
 */

#ifndef INCLUDES_UART_H_
#define INCLUDES_UART_H_

#include <stdint.h>

void uart_init(uint32_t baud);
void UART0_IRQHandler (void);

#define BAUD_RATE       38400

#endif /* INCLUDES_UART_H_ */
