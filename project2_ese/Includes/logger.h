/*
 * logger.h
 *
 *  Created on: Oct 10, 2016
 *      Author: VIJOY-PC
 */

#ifndef INCLUDES_LOGGER_H_
#define INCLUDES_LOGGER_H_

#include <stdint.h>

void LOG_0(uint8_t * data, uint8_t len);
void LOG_1(uint8_t * data, uint8_t len, uint32_t param, uint8_t data_type_size);
void LOG_2(uint8_t * data, uint8_t len, float param, uint8_t data_type_size);

int8_t itoa(int8_t *str, int32_t data, int32_t base);
void ftoa( uint8_t *str, float data, uint8_t num_fract);

#define MAXLEN 20
extern uint8_t data_ready;

#endif /* INCLUDES_LOGGER_H_ */
