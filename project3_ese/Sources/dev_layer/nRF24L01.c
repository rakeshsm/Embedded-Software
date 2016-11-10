#include <main.h>


uint8_t nrf_status_read()
{
	uint8_t statusValue = spi_send(NOP);
}

uint8_t nrf_read_register(unsigned char reg) //read command
{
	NRF_CS_ENABLE();
		spi_send((reg)|NRF_COMMAND_R_REGISTER);
		uint8_t regValue = nrf_status_read();
		NRF_CS_DISABLE();
		return regValue;
}


void nrf_write_Tx_Payload(unsigned char* val, uint8_t num) //write command
{
	    NRF_CS_ENABLE();
		spi_send(NRF_COMMAND_W_TX_PAYLOAD);
		while(num--){
		spi_send(*val);
		val++;
		}
		NRF_CS_DISABLE();
}



void nrf_write_register(unsigned char reg, unsigned char val) //write command
{
	NRF_CS_ENABLE();
		spi_send((reg)|NRF_COMMAND_W_REGISTER);
		spi_send(val);
		NRF_CS_DISABLE();
}

void nrf_flush_tx_fifo(){
	NRF_CS_ENABLE();
	spi_send(NRF_COMMAND_FLUSH_TX);
	NRF_CS_DISABLE();
}

void nrf_flush_rx_fifo(){
	NRF_CS_ENABLE();
	spi_send(NRF_COMMAND_FLUSH_RX);
	NRF_CS_DISABLE();
}

void nrf_transmit_data(){
	NRF_CS_ENABLE();
	spi_send(NRF_COMMAND_W_TX_PAYLOAD);
	spi_send(0xFF); //Random data, loop for multiple
	NRF_CS_DISABLE();
}



