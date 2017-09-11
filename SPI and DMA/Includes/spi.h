/*
 * spi.h
 *
 *  Created on: Nov 7, 2016
 *      Author: rakes
 */
#ifndef INCLUDES_SPI_H_
#define INCLUDES_SPI_H_

void spi_init(void);
uint8_t spi_send(unsigned char spiMsg);
#define NRF_CS_ENABLE() (PTC_BASE_PTR->PCOR |= 1<<4)
#define NRF_CS_DISABLE() (PTC_BASE_PTR->PSOR |= 1<<4)
#define WAIT_SPTEF ( !(SPI_S_REG(SPI0) & SPI_S_SPTEF_MASK))
#define WAIT_SPRF ( !(SPI_S_REG(SPI0) & SPI_S_SPRF_MASK))

#endif /* INCLUDES_SPI_H_ */
