#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "memory.h"

int8_t my_memmove(uint8_t * src, uint8_t * dst, uint32_t length) {
	int8_t ret = 1;
	uint8_t dummyarr[length];
	uint8_t * tmp = dummyarr;
	uint8_t * tmp1 = tmp;
	uint32_t len = length;
	if (src != NULL && dst != NULL) {
		while (len) {
			*tmp++ = *src++;
			len--;
		}
		len = length;
		while (length) {
			*dst++ = *tmp1++;
			length--;
		}
	}else {
		printf("Not moved\n");
		ret = 0;
		}
	return ret;
	}



int8_t my_memzero(uint8_t * src, uint32_t length) {
	int8_t ret = 1;
	if (src != NULL && length > 0) {
		while (length) {
			length--;
			*src++ = 0;
		}
	}
	else {
		ret = 0;
	}
	return ret;
}

int8_t my_reverse(uint8_t * src, uint32_t length) {
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
		return 1;
	}else {
		return 0;

	}
}
