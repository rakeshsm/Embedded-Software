/*
 * logger.c
 *
 *  Created on: Oct 10, 2016
 *      Author: VIJOY-PC
 */

#include "main.h"
/*-----------------------------------------------------------------------------------
 * void LOG_0(uint8_t * data, uint8_t len)
 *
 * This function prints out (printf in BBB ,serial transmit in FRDM) a string of ASCII
 * characters of specified length
 *
 * *data      - points to the first character of the ASCII string
 * len        - is the length of the string
 *
 * The log function can be disable by the compile time switch DEBUG.
 * Also the uart transmission inside the log function can be enabled by the FRDM switch
 * and the printf function can be enabled by BBB switch
 ------------------------------------------------------------------------------------*/
void LOG_0(uint8_t * data, uint8_t len)
{
#ifdef DEBUG
#ifdef FRDM
	for (int i=0;i<len;i++)
	{
		//Wait until TX buffer is emplty or transmission complete flag is set
		while(!((UART0_S1&UART_S1_TDRE_MASK)|(UART0_S1&UART_S1_TC_MASK)));
	    UART0_D = *data;	// Send the character
	    data++;				//point to next character
	}
#endif
#ifdef BBB
	for (int i=0;i<len;i++)
	{
		printf("\n%p",*data);
		*data++;
	}
#endif
#endif

}

/*-----------------------------------------------------------------------------------
 * void LOG_1(uint8_t * data, uint8_t len, uint32_t * param, uint8_t data_type_size)
 *
 * This function prints out (printf in BBB ,serial transmit in FRDM) a string of ASCII
 * characters of specified length along with a numeric parameter-integer.
 *
 * *data      - points to the first character of the ASCII string
 * len        - is the length of the string
 * *param     - points to the numeric parameter- integer
 * param_size - is the length of the parameter
 *
 * The log function can be disable by the compile time switch DEBUG.
 * Also the uart transmission inside the log function can be enabled by the FRDM switch
 * and the printf function can be enabled by BBB switch
 ------------------------------------------------------------------------------------*/
void LOG_1(uint8_t * data, uint8_t len, uint32_t  param, uint8_t data_type_size)
{
#ifdef DEBUG
#ifdef FRDM
	LOG_0(data,len);
	uint8_t dest[20];
	itoa(dest,param,10);
	LOG_0(dest,data_type_size);
#endif
#ifdef BBB
	for (int i=0;i<len;i++)
	{
		printf("\n%p",*data);
		*data++;
	}
	printf(":");
	printf("%d",param);
#endif
#endif
}
/*-----------------------------------------------------------------------------------
 * void LOG_2(uint8_t * data, uint8_t len, float param, uint8_t data_type_size)
 *
 * This function prints out (printf in BBB ,serial transmit in FRDM) a string of ASCII
 * characters of specified length along with a numeric parameter- floating point
 *
 * *data      - points to the first character of the ASCII string
 * len        - is the length of the string
 * *param     - points to the floating point parameter
 * param_size - is the length of the parameter
 *
 * The log function can be disable by the compile time switch DEBUG.
 * Also the uart transmission inside the log function can be enabled by the FRDM switch
 * and the printf function can be enabled by BBB switch
 ------------------------------------------------------------------------------------*/
void LOG_2(uint8_t * data, uint8_t len, float param)
{
#ifdef DEBUG
#ifdef FRDM
	uint8_t size = 8;
	LOG_0(data,len);
	char *dest;
	char temp[20];
	dest = temp;
	dest = ftoa(param);
	LOG_0(dest,size);
#endif
#ifdef BBB
	for (int i=0;i<len;i++)
	{
		printf("\n%p",*data);
		*data++;
	}
	printf(":");
	printf("%f",param);
#endif
#endif
}
/*-------------------------------------------------------------------------------------
 *int8_t  itoa(int8_t *str, int32_t data, int32_t base)
 *This function converts an integer type number (data) of base (base)
 *into an ASCII string (str)
 ------------------------------------------------------------------------------------*/
int8_t itoa(int8_t *str, int32_t data, int32_t base)
{
	int8_t* str1 = str;
	int isNeg = 0;
	if (data < 0)
	{
		isNeg = 1;
		data = -data;
	}

	if (data == 0)
	{
		*str++ = '\0';
		return 1;
	}

	int length = 0;
	while (data != 0)
	{
		int8_t reminder = data% base;
		data = data / base;
		if (reminder > 9)
		{
			*str++ = (reminder - 10) + 'a';
		}
		else
		{
			*str++ = reminder + '0';
		}
		length++;
	}
	if (isNeg)
	{
		*str++ = '-';
		length++;
	}
	*str++ = '\0'; //End of character

	int8_t* src = str1;

	int index = 0;
	uint8_t temp;
	while (index<length / 2)
	{
		temp = *(src + index);
		*(src + index) = *(src + length - index - 1);
		*(src + length - index - 1) = temp;
		index++;
	}
	if (index == (length/2))
		return 1;
	else
		return 0;
}


typedef union {
long	L;
float	F;
}	LF_t;

char *ftoa(float f)
{
	long mantissa, int_part, frac_part;
	short exp2;
	LF_t x;
	char *p;
	static char outbuf[15];

	if (f == 0.0)
	{
		outbuf[0] = '0';
		outbuf[1] = '.';
		outbuf[2] = '0';
		outbuf[3] = 0;
		return outbuf;
	}
	x.F = f;

	exp2 = (unsigned char)(x.L >> 23) - 127;
	mantissa = (x.L & 0xFFFFFF) | 0x800000;
	frac_part = 0;
	int_part = 0;

	if (exp2 >= 23)
		int_part = mantissa << (exp2 - 23);
	else if (exp2 >= 0)
	{
		int_part = mantissa >> (23 - exp2);
		frac_part = (mantissa << (exp2 + 1)) & 0xFFFFFF;
	}
	else /* if (exp2 < 0) */
		frac_part = (mantissa & 0xFFFFFF) >> -(exp2 + 1);

	p = outbuf;

	if (x.L < 0)
		*p++ = '-';

	if (int_part == 0)
		*p++ = '0';
	else
	{
		itoa(p, int_part, 10);
		while (*p)
			p++;
	}
	*p++ = '.';

	if (frac_part == 0)
		*p++ = '0';
	else
	{
		char m, max;
		max = sizeof (outbuf) - (p - outbuf) - 1;
		if (max > 7)
			max = 7;
		/* print BCD */
		for (m = 0; m < max; m++)
		{
			/* frac_part *= 10;	*/
			frac_part = (frac_part << 3) + (frac_part << 1);

			*p++ = (frac_part >> 24) + '0';
			frac_part &= 0xFFFFFF;
		}
		/* delete ending zeroes */
		for (--p; p[0] == '0' && p[-1] != '.'; --p)
			;
		++p;
	}
	*p = 0;

	return outbuf;
}
