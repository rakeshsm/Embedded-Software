/*
 * nvic.c
 *
 *  Created on: Oct 10, 2016
 *      Author: VIJOY-PC
 */

#include "main.h"

/*--------------------------------------------------------------------------------
 * void UART0_IRQHandler (void)
 * The UART0 ISR handler receives the character fro the serial terminal and increments
 * the variable 'next' and 'b_color' accordingly when any of the characters
 * 'a' , 'w', 's' or 'd' are pressed and ignores any other character inputs.
 *
 * next - to change to the next color
 * 1    - Red led
 * 2    - Green led
 * 3    - Blue led
 * 4    - Red + Green led
 * 5    - Red + Blue led
 * 6    - Green + Blue led
 * 7    - Red + Green + Blue
 * 0(default) - All off
 *
 * b_ color - 	Brightness control for the leds
 * 				ranges from 0 to 1 with resolution of 0.1
 *
 --------------------------------------------------------------------------------*/
uint8_t rec_char,rec_length=0,i=0;					//store received chararcter in rec_char

void UART0_IRQHandler (void)
{
  if (UART0_S1&UART_S1_RDRF_MASK)
  	{
	  	rec_char = UART0_D;
		UART0_C2 &= ~UART0_C2_RIE_MASK; 		//Peripheral interrupt enable (RX)
#ifdef RGB_INTERACT
		if((rec_char == 'a') & (next > 0))
		{
			next--;
			LOG_0("\r\nPREVIOUS COLOR\r\n",18);
		}
		if((rec_char =='d') & (next < 7))
		{
			next++;
			LOG_0("\r\nNEXT COLOR\r\n",14);
		}
		if((rec_char =='w') & (b_color < 1))
		{
			b_color +=0.1;
			LOG_0("\r\nBRIGHTNESS +\r\n",16);
		}
		if((rec_char == 's') & (b_color > 0))
		{
			b_color -=0.1;
			LOG_0("\r\nBRIGHTNESS -\r\n",16);
		}
		UART0_C2 |=  UART0_C2_TIE_MASK;
#endif
#ifdef BUFFER_INERACT
											//add receiving character to the rx circular buffer
		add_cbuff(&RXBUFF,rec_char);
		rec_length++;						//length of input string
		if(rec_length==MAXLEN + 1)			//set data_ready after receiving complete string
		{
			data_ready=1;
			LOG_0("\r\nReceive buffer full\r\n",23);
			rec_length=0;
		}
		else
			data_ready=0;
#endif
  	}
/*--------------------------------------------------------------------------------------------
 * TX interrupt service for UART0
 --------------------------------------------------------------------------------------------*/

  if ((UART0_S1&UART_S1_TDRE_MASK)||(UART0_S1&UART_S1_TC_MASK))
    {
#ifdef BUFFER_INERACT
	  if(data_ready == 0)
		  UART0_D = rec_char;
	  if(data_ready==2)							//transmit when data is copied from rxbuff to txbuff
	  {
		  i=0;
		  while(i<MAXLEN)
		  {
			  rec_char = del_cbuff(&TXBUFF);			//output from tx buff
			  while(!((UART0_S1&UART_S1_TDRE_MASK)|(UART0_S1&UART_S1_TC_MASK)));
			  UART0_D = rec_char;
			  i++;
		  }

		  if(buffer_empty(&TXBUFF))
		  {
			  UART0_C2 &= ~UART0_C2_TIE_MASK; 	//Disable Interrupt Enable for TDRE if buffer is empty
			  data_ready=3;
		  }
	  }
#endif
	  UART0_C2 |=  UART0_C2_RIE_MASK;		//Peripheral interrupt enable (RX)
	  UART0_C2 &= ~UART0_C2_TIE_MASK; 		//Peripheral interrupt enable (TX)
    }
}

/*--------------------------------------------------------------------------------------------
 * Timer1 overflow interrupt service
 --------------------------------------------------------------------------------------------*/
void TPM1_IRQHandler(void)
{
	if(TPM1_SC |= TPM_SC_TOF_MASK)
	{
		overflow_count++;					//keep count of oveflow
		TPM1_SC |= TPM_SC_TOF_MASK;			//clear the tof bit by writing 1
	}
}

