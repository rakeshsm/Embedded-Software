/*
 * unitest.c
 *
 *  Created on: Oct 11, 2016
 *      Author: VIJOY-PC
 */
#include "main.h"
#include "string.h"
#include "stdlib.h"

extern uint8_t flag_once;
void buffer_test(void)
{
	uint8_t dumdata=55;
	init_cbuff(&RXBUFF,25);			//init RX buffer
	init_cbuff(&TXBUFF,25);			//init TX buffer
	uint8_t buff_res,pass_count=0;

		LOG_0("\r\nBUFFER UNIT TEST:\r\n",21);

		LOG_0("\r\nEMPTY buffer",14);
		clear_buffer(&RXBUFF);							//empty fully
		buff_res=del_cbuff(&RXBUFF);
		LOG_0("\r\nRemove item TEST -->",22);			//remove test for empty buffer
		if(buff_res ==0) {
			LOG_0("PASS\r\n",6);
			LOG_0("\rBuffer is empty\r\n",19);
			pass_count++;
		}
		else
			LOG_0("FAIL\r\n",6);

		LOG_0("\r\nFILL buffer",13);				//remove test for full buffer
		fill_buffer(&RXBUFF,dumdata);					//fill buffer
		buff_res=del_cbuff(&RXBUFF);
		LOG_0("\r\nRemove item TEST -->",22);
		if(buff_res ==0) {
			LOG_0("FAIL\r\n",6);
			LOG_0("\rBuffer is empty\r\n",19);
		}
		else
		{
			LOG_0("PASS\r\n",6);
			pass_count++;
		}
//-----------------------------------------------------------------------------------------//

		LOG_0("\r\nEMPTY buffer",14);				//add test for empty buffer
		clear_buffer(&RXBUFF);							//empty fully
		LOG_0("\r\nAdding item TEST -->",22);
		buff_res=add_cbuff(&RXBUFF,dumdata);
		if(buff_res ==0) {
			LOG_0("FAIL\r\n",6);
			LOG_0("\rBuffer is full\r\n",18); }
		else
		{
			LOG_0("PASS\r\n",6);
			pass_count++;
		}

		LOG_0("\r\nFILL buffer",13);				//add test for full buffer
		fill_buffer(&RXBUFF,dumdata);					//fill buffer
		buff_res=add_cbuff(&RXBUFF,dumdata);
		LOG_0("\r\nAdding item TEST -->",22);
		if(buff_res ==0) {
			LOG_0("PASS\r\n",6);
			LOG_0("\rBuffer is full\r\n",18);
			pass_count++;
		}
		else
			LOG_0("FAIL\r\n",6);
//----------------------------------------------------------------------------------------//
		LOG_0("\r\nEMPTY buffer",14);
		clear_buffer(&RXBUFF);							//empty fully
		LOG_0("\r\nBuffer full TEST -->",22);
		buff_res=buffer_full(&RXBUFF);
		if(buff_res ==0) {
			LOG_0("PASS\r\n",6);
			LOG_0("\rBuffer is not full\r\n",22);
			pass_count++;
		}
		else
			LOG_0("FAIL\r\n",6);

		LOG_0("\r\nFILL buffer",13);
		fill_buffer(&RXBUFF,dumdata);					//fill buffer
		LOG_0("\r\nBuffer full TEST -->",22);
		buff_res=buffer_full(&RXBUFF);
		if(buff_res ==0)
			LOG_0("FAIL\r\n",6);
		else
		{
			LOG_0("PASS\r\n",6);
			LOG_0("\rBuffer is full\r\n",18);
			pass_count++;
		}
//---------------------------------------------------------------------------------------//
		LOG_0("\r\nEMPTY buffer",14);
		clear_buffer(&RXBUFF);							//empty fully//empty buffer

		LOG_0("\r\nBuffer empty TEST -->",23);
		buff_res=buffer_empty(&RXBUFF);
		if(buff_res ==0)
			LOG_0("FAIL\r\n",6);
		else
		{
			LOG_0("PASS\r\n",6);
			LOG_0("\rBuffer is empty\r\n",19);
			pass_count++;
		}

		LOG_0("\r\nFILL buffer",13);
		fill_buffer(&RXBUFF,dumdata);					//fill buffer

		LOG_0("\r\nBuffer empty TEST -->",23);
		buff_res=buffer_empty(&RXBUFF);
		if(buff_res ==0)
		{
			LOG_0("PASS\r\n",6);
			LOG_0("\rBuffer is full\r\n",18);
			pass_count++;
		}
		else
			LOG_0("FAIL\r\n",6);

		LOG_0("\r\n-----------------------------------------------\r\n",51);
		LOG_0("\rUNIT TEST SUITE:",17);
		if(pass_count !=8)
			LOG_0("FAIL",4);
		else
			LOG_0("PASS",4);
}

//fn for buffer complete fill
void fill_buffer(cir_buff_t *cptr,uint8_t data)
{
	uint8_t i=0;
	while(i<30)
	{
		i++;
		add_cbuff(cptr,data);
	}
}

//fn for buffer empty
void clear_buffer(cir_buff_t *cptr)
{
	uint8_t i=0,dummdata;
	while(i<30)
	{
		i++;
		dummdata=del_cbuff(cptr);
	}

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
	//testLogger();
}

void testMemMove(void){
	uint32_t length=1;
	while(length< 10000){
	length=length*10;
	char arr[length] ;
	char arr1[length];
	uint8_t * src = arr;
	const uint8_t *dst;
	char stringarr[]={"\r\nMEMOVE for copying of length :"};
	int n = sizeof(stringarr)/sizeof(stringarr[0]);
	LOG_1("\r\nMEMOVE for copying of length :",n
			,length,4);
	start_time();
	int8_t* k = memmove(src,dst,length);
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
		uint8_t arr[length] ;
		uint8_t* src;
		src = arr;
		LOG_1("\r\nMEMSET for copying of length :",32,length,sizeof(length));
		start_time();
		int8_t* k = memset(src,0,length);
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
		int8_t arr[length] ;
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
		int8_t arr[length] ;
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
		char* k = ftoa(data);
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
	init_cbuff(&testcbuff,size);
	LOG_1("\r\nCIRCULAR BUFFER FREE TEST :",32,size,sizeof(size));
	start_time();
//	free(&testcbuff);
	end_time();
}


void testAddCbuff(){
	cir_buff_t testcbuff;
	int size = 25;
	init_cbuff(&testcbuff,size);
	LOG_1("\r\nCIRCULAR BUFFER ADD TEST :",32,size,sizeof(size));
	start_time();
	int k = add_cbuff(&testcbuff,10);
	end_time();
}

void testRemoveCbuff(){
	cir_buff_t testcbuff;
	int size = 25;
	init_cbuff(&testcbuff,size);
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
	LOG_0("\r\nLOGGER TEST VE0\r\n",18);
	end_time();
}
