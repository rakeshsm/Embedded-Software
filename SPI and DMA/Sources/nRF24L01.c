#include <main.h>


uint8_t nrf_read_register(unsigned char reg) //read command
{
	NRF_CS_ENABLE();
	spi_send((reg)|NRF24_COMMAND_R_REGISTER);
	uint8_t regValue = nrf_status_read();
	NRF_CS_DISABLE();
	return regValue;
}



uint8_t nrf_status_read()
{
	uint8_t statusValue = spi_send(NOP);
}

void nrf_write_register(unsigned char reg, unsigned char val) //write command
{
	NRF_CS_ENABLE();
	spi_send((reg)|NRF24_COMMAND_W_REGISTER);
	spi_send(val);
	NRF_CS_DISABLE();
}

void nrf_flush_tx_fifo(){
	NRF_CS_ENABLE();
	spi_send(NRF24_COMMAND_FLUSH_TX);
	NRF_CS_DISABLE();
}

void nrf_flush_rx_fifo(){
	NRF_CS_ENABLE();
	spi_send(NRF24_COMMAND_FLUSH_RX);
	NRF_CS_DISABLE();
}

void nrf_transmit_data(){
	NRF_CS_ENABLE();
	spi_send(NRF24_COMMAND_W_TX_PAYLOAD);
	spi_send(0xff); //Random data, loop for multiple
	NRF_CS_DISABLE();
}



