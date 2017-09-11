#include "main.h"

int8_t next=0;
float b_color=1.0;
uint8_t data_ready;

int main(void)
{
	uart_init(BAUD_RATE);				//initialise UART0

#ifdef PROFILE
	init_profiler();
	/*------------------------------------------------------------*/
	//
	testMemoryTimeTest();
	//uncomment functions in testMemoryTimeTest(); for profiling them
	/*--------------------------------------------------------------*/
	while(1);
#endif

#ifdef RGB_INTERACT
	led_init();							//initialise RGB led
	LOG_0("\r\na -> PREVIOUS\r\n",17);
	LOG_0("\r\nd -> NEXT\r\n",13);
	LOG_0("\r\nw -> BRIGHTNESS ++\r\n",22);
	LOG_0("\r\ns -> BRIGHTNESS --\r\n",22);
	LOG_0("\r\nPRESS ANY OF THE ABOVE KEYS\r\n",31);
    while(1)							//infinite loop
    {
    	switch(next)
    	{
    	case 1:
    		R(b_color);
    		G(0);
    		B(0);
    		break;
    	case 2:
    	    R(0);
    	    G(b_color);
    	    B(0);
    	    break;
    	case 3:
    	  	R(0);
    	    G(0);
    	    B(b_color);
    	    break;
    	case 4:
    	  	R(b_color);
    	    G(b_color);
    	    B(0);
    	    break;
    	case 5:
    	  	R(b_color);
    	    G(0);
    	    B(b_color);
    	    break;
    	case 6:
    	  	R(0);
    	    G(b_color);
    	    B(b_color);
    	    break;
    	case 7:
    	  	R(b_color);
    	    B(b_color);
    	    G(b_color);
    	    break;
    	default:
    	    R(0);
    	    B(0);
    	    G(0);
    	    break;
    	}

    }
#endif

#ifdef LOGGER_TEST
	LOG_0("\r\nUart Logger function testing",30);
	LOG_0("\r\n-------------------------------------",39);
	LOG_0("\r\nTesting123,Serial print test,no params",40);
	LOG_1("\r\nThis is an integer number:",28,200,sizeof(200));
	LOG_1("\r\nThis is an integer number:",28,4096,sizeof(4096));
	LOG_1("\r\nThis is an integer number:",28,123456,sizeof(123456));
	LOG_2("\r\nThis is a floating number:",29,1543.321);

	while(1);						//infinite loop
#endif


#ifdef UNIT_TEST
	buffer_test();
	Destroy(&RXBUFF);
	LOG_0("\r\nFreeing up heap\r\n",19);
	while(1);
#endif

#ifdef BUFFER_INERACT
	uint8_t read_char,i=0;
	while(1)
	{
		init_cbuff(&RXBUFF,25);			//init RX buffer
		init_cbuff(&TXBUFF,25);			//init TX buffer

		LOG_0("\r\nEnter your string\r\n",21);
		LOG_0("\r\nStoring in receive buffer\r\n",29);

		data_ready=0;
		while(1)									//infinite loop
		{
			//receive in RX buff ,loop to copy contents from UART0_D into RX BUFFER
			if(data_ready == 1)						//incoming data in rx buff complete
			{
				i=0;
				while(i<MAXLEN)
				{
					read_char = del_cbuff(&RXBUFF);	//read from rx buff
					add_cbuff(&TXBUFF,read_char);	//write to tx buff
					i++;
				}
				data_ready=2;
				LOG_0("\r\nSending from TXBUFF\r\n",23);
				UART0_C2 |= UART0_C2_TIE_MASK;		//enable tx interrupt after copy from rxbuff complete
			}
			if(data_ready == 3)						//copied from tx buff complete
			{
				break;
				Destroy(&RXBUFF);					//delete heap memory
				Destroy(&TXBUFF);
				LOG_0("\r\nFreeing up heap\r\n",19);
			}
		}
	}
#endif
	return 0;
}
