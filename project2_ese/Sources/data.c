#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "data.h"
#include "memory.h"

int8_t*  my_itoa(int8_t *str, int32_t data, int32_t base) {
	int8_t* str1 = str;
	int isNeg = 0;
	if (data < 0)
	{
		isNeg = 1;
		data = -data;
	}

	if (data == 0) {
		*str++ = '\0';
		return str1;
	}

	int length = 0;
	while (data != 0) {
		int8_t reminder = data% base;
		data = data / base;
		if (reminder > 9) {
			*str++ = reminder - 10 + 'a';
		}
		else {
			*str++ = reminder + '0';
		}
		length++;
	}
	if (isNeg) {
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
	if (index == (length/2)) {
		return str1;
	}else {
		return NULL;

	}

}




int32_t  my_atoi(int8_t *str) {
	int isNeg = 0;
	if (*str == '-')
	{
		isNeg = -1;
		str++;
	}

	int32_t aint = 0;

	while (*str != '\0') {
		aint = aint * 10 + *++str - '0';
	}

	if (isNeg)
		aint = -aint;

	return aint;
}


void dump_memory(uint8_t * start, uint32_t length) {
	if (start != NULL && length > 0) {
		while (length != 0) {
			printf("%x", *start++);
			length--;
		}
	}
}


uint32_t big_to_little(uint32_t data) {
	return little_to_big(data);
}


uint32_t little_to_big(uint32_t data) {

	uint32_t bit0, bit1, bit2, bit3;
	bit0 = (data & 0x000000ff) << 24u;
	bit1 = (data & 0x0000ff00) << 8u;
	bit2 = (data & 0x00ff0000) >> 8u;
	bit3 = (data & 0xff000000) >> 24u;

	return  (bit0 | bit1 | bit2 | bit3);

}
