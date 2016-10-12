#include "main.h"

int8_t next=0;
float b_color=1.0;
uint8_t data_ready;

int main(void)
{
	uart_init(BAUD_RATE);				//initialise UART0
#ifdef PROFILE
uint8_t a ;
	init_profiler();
	testMemoryTimeTest();


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
	init_cbuff(&RXBUFF,25,1);			//init RX buffer
	init_cbuff(&TXBUFF,25,0);			//init TX buffer

	while(1);
#endif

#ifdef BUFFER_INERACT
	uint8_t read_char,i=0;
	while(1)
	{
		init_cbuff(&RXBUFF,25,1);			//init RX buffer
		init_cbuff(&TXBUFF,25,0);			//init TX buffer

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
				LOG_0("\r\nSending from tx buffer\r\n",26);
				UART0_C2 |= UART0_C2_TIE_MASK;		//enable tx interrupt after copy from rxbuff complete
			}
			if(data_ready == 3)						//copied from tx buff complete
			{
				break;
				//delete heap memory
			}
		}
	}
#endif
	return 0;
}

void testMemoryTimeTest(){

	/*------------------------------------------------------------
	// Memory functions to profile here
	--------------------------------------------------------------*/
	//testMemMove();
	//testMemReverse();
	//testMemZero();

	//testitoa();
	//testatoi();
	//testftoa();
	//testMalloc();
	//testfree();
	//testAddCbuff();
	//testRemoveCbuff();
	testLogger();
}

void testMemMove(void){
	uint32_t length=1;
	while(length< 10000){
	length=length*10;
	char arr[length] ;
	char arr1[length];
	uint8_t * src = arr;
	uint8_t *dst = arr1;
	char stringarr[]={"\r\nMEMOVE for copying of length :"};
	int n = sizeof(stringarr)/sizeof(stringarr[0]);
	LOG_1("\r\nMEMOVE for copying of length :",n
			,length,4);
	start_time();
	int8_t k = memmove(src,dst,length);
	end_time();
	if(length ==1000){
		length =500;
	}if(length ==5000){
		length =501;
	}

	}
}

void testMemReverse(void){
	uint32_t length=1;
		while(length< 10000){
		length=length*10;
		char arr[length] ;
		uint8_t * src = arr;
		char stringarr[]={"\r\nMYMEMREVERSE for length :"};
		int n = sizeof(stringarr)/sizeof(stringarr[0]);
		LOG_1("\r\nMYMEMREVERSE for length :",n,length,4);
		start_time();
		int8_t k = my_reverse(src,length);
		end_time();
		if(length ==1000){
			length =500;
		}
		}

}


void testMemZero(void){
	uint32_t length=1;
		while(length< 10000){
		length=length*10;
		int arr[length] ;
		uint8_t * src = arr;
		LOG_1("\r\nMEMSET for copying of length :",32,length,sizeof(length));
		start_time();
		int8_t k = memset(src,0,length);
		end_time();
		if(length ==1000){
			length =500;
		}
		if(length ==5000){
					length =501;
				}

		}

}



void testitoa(void){
	uint32_t length=1;
		length=length*10;
		int arr[length] ;
		int8_t * src = arr;
		int32_t data =100;
		LOG_0("\r\nITOA test :",16);
		start_time();
		int8_t* k = my_itoa(src,data,16);
		end_time();
		if(length ==1000){
			length =500;
		}
		if(length ==5000){
					length =501;
				}
}


void testatoi(void){
	uint32_t length=1;
		length=length*10;
		int arr[length] ;
		int8_t * src = arr;
		int32_t data =100;
		LOG_0("\r\nATOI test :",16);
		start_time();
		int32_t k = my_atoi(src);
		end_time();
}


void testftoa(void){
		LOG_0("\r\nFTOA test :",15);
		start_time();
		float data =12.67;
		int32_t* k = ftoa(data);
		end_time();
}

void testMalloc(){
	int arr[] = {10, 100, 500, 1000};
	char *str;
	str = (char *) malloc(10000);
	for(int i=0; i<4;i++){
	start_time();
	char *str;
	LOG_1("\r\nMALLOC TEST WITH PREVIOUS HEAP :",36,arr[i],sizeof(arr[i]));
	str = (char *) malloc(arr[i]);
	end_time();
	free(str);
	}

}

void testfree(){
	cir_buff_t testcbuff;
	int size = 25;
	init_cbuff(&testcbuff,size,0);
	LOG_1("\r\nCIRCULAR BUFFER FREE TEST :",32,size,sizeof(size));
	start_time();
	free(&testcbuff);
	end_time();
}


void testAddCbuff(){
	cir_buff_t testcbuff;
	int size = 25;
	init_cbuff(&testcbuff,size,0);
	LOG_1("\r\nCIRCULAR BUFFER ADD TEST :",32,size,sizeof(size));
	start_time();
	int k = add_cbuff(&testcbuff,10);
	end_time();
}

void testRemoveCbuff(){
	cir_buff_t testcbuff;
	int size = 25;
	init_cbuff(&testcbuff,size,1);
	int k1 = add_cbuff(&testcbuff,10);
	LOG_1("\r\nCIRCULAR BUFFER REMOVE TEST :",32,size,sizeof(size));
	start_time();
	int k = del_cbuff(&testcbuff);
	end_time();
}




void testLogger(){
	cir_buff_t testcbuff;
	int size =1;
	start_time();
	//LOG_1("\r\nLOGGER TEST VERSION :",16,size,sizeof(size));
	LOG_0("\r\nLOGGER TEST VE0\r\n",18);
	end_time();
}




