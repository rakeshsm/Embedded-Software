/*
 * cbuffer.h
 *
 *  Created on: Oct 10, 2016
 *      Author: VIJOY-PC
 */

#ifndef INCLUDES_CBUFFER_H_
#define INCLUDES_CBUFFER_H_

typedef struct
{
     uint8_t *start;			//start of buffer
     uint8_t *head;
     uint8_t *tail;
     uint8_t *end;			//buffer end address
     uint16_t num_items;	//number of items currently in buffer
     uint16_t size;			//total size of buffer
}cir_buff_t;

cir_buff_t RXBUFF,TXBUFF;
//uint8_t R_arr[50],T_arr[50];


uint8_t buffer_full(cir_buff_t *cptr);				//Check for buffer full
uint8_t buffer_empty(cir_buff_t *cptr);				//Check for buffer empty

uint8_t init_cbuff(cir_buff_t *cptr,uint8_t size);	//initialise buffer
uint8_t add_cbuff(cir_buff_t *cptr,uint8_t data);	//Add data to buffer
uint8_t del_cbuff(cir_buff_t *cptr);				//Removing data from buffer

uint8_t Destroy(cir_buff_t *cptr);


#endif /* INCLUDES_CBUFFER_H_ */
