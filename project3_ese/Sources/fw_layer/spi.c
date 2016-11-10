/*
 * spi.c
 *
 *  Created on: Nov 7, 2016
 *      Author: rakes
 */
#include <main.h>

void spi0_init(void)
{// Turn on port C
	//SPI0 module initialization
		  SIM_SCGC4 |= SIM_SCGC4_SPI0_MASK; // Turn on clock to SPI0 module
		  SIM_SCGC5 |= SIM_SCGC5_PORTC_MASK; // Turn on clock to Port D module
		  GPIOC_PSOR |= GPIO_PSOR_PTSO(0x10); // PTD0 = 1 (CS inactive)
		    GPIOC_PDDR |= GPIO_PDDR_PDD(0x10); // PTD0 pin is GPIO output
		    PORTC_PCR4 = PORT_PCR_MUX(0x1);    //Set PTD0 to mux 1 [SPI0_PCS0]
		    PORTC_PCR5 = PORT_PCR_MUX(0x2);    //Set PTD1 to mux 2 [SPI0_SCK]
		    PORTC_PCR6 = PORT_PCR_MUX(0x2);    //Set PTD2 to mux 2 [SPI0_MOSI]
		    PORTC_PCR7 = PORT_PCR_MUX(0x2);    //Set PTD3 to mux 2 [SPIO_MISO]


		  //SETUP SPI0 PERIPHERAL

		  SPI0_C1 = SPI_C1_SPE_MASK | SPI_C1_MSTR_MASK |SPI_C1_CPHA_MASK; // Enable SPI0 module, master mode //SETS SPI ENABLE AND SPI MASTER BITS
		  //SPI0_C2 = 0x19;
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





