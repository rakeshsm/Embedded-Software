/*
 * spi.c
 *
 *  Created on: Nov 7, 2016
 *      Author: rakes
 */
#include <main.h>

void spi0_init(void)
{
	// Turn on port C
	SIM_SCGC5 |= SIM_SCGC5_PORTC_MASK;
	// Turn on SPI0 clock
	SIM_SCGC4 |= SIM_SCGC4_SPI0_MASK;

	// Set up ports for SPI0
	PORTC->PCR[4] |= PORT_PCR_MUX(1); // ss as gpio pin
	PORTC->PCR[5] |= PORT_PCR_MUX(2);
	PORTC->PCR[6] |= PORT_PCR_MUX(2);
	PORTC->PCR[7] |= PORT_PCR_MUX(2);

	// Set port C, pin 8 data direction to output
	PTC_BASE_PTR->PDDR |= 1<<4;

	SPI_C1_REG(SPI0) = SPI_C1_SPE_MASK;
	SPI_C2_REG(SPI0) = 0x00;

	SPI_C1_REG(SPI0) = SPI_C1_MSTR_MASK |
			SPI_C1_SPE_MASK|0x00;
	// prescaler=1, divisor=4 , 24MHz/4 = 6MHz
	SPI0_BR = SPI_BR_SPPR(0x03) | SPI_BR_SPR(0x08) ;
}

void spi1_init(void)
{
	// SPI1 PortD Slave
	SIM_SCGC5 |= SIM_SCGC5_PORTD_MASK;      //Turn on clock to D module
	SIM_SCGC4 |= SIM_SCGC4_SPI1_MASK;       //Enable SPI0 clock

	PORTD_PCR4 = PORT_PCR_MUX(0x2);    //Set PTD0 to mux 2 [SPI0_PCS0]
	PORTD_PCR5 = PORT_PCR_MUX(0x2);    //Set PTD1 to mux 2 [SPI0_SCK]
	PORTD_PCR6 = PORT_PCR_MUX(0x2);    //Set PTD2 to mux 2 [SPI0_MOSI]
	PORTD_PCR7 = PORT_PCR_MUX(0x2);    //Set PTD3 to mux 2 [SPIO_MISO]


	SPI1_C1 = 0x00;   //Set SPI0 to Master & SS pin to auto SS
	SPI1_BR = (SPI_BR_SPPR(0x02) | SPI_BR_SPR(0x08));     //Set baud rate prescale divisor to 3 & set baud rate divisor to 64 for baud rate of 15625 hz

	SPI1_C1 |= SPI_C1_SPE_MASK;    //Enable SPI0

}


uint8_t spi_send(unsigned char spiMsg)
{
	uint8_t rx_ret = 0;
	while(WAIT_SPTEF);
	SPI_D_REG(SPI0) = spiMsg;
	while(WAIT_SPRF);
	rx_ret = SPI_D_REG(SPI0);
	return (rx_ret);
}





