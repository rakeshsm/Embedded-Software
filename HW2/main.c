#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "hw1.h"

int main()
{
char mychar;
int myint;
float myfloat;
double mydouble;
short myshort;
long mylong;
long int mylongint;
long long mylonglong;
char * mychar1;
int * myint1;
float * myfloat1;
void * myvoid1;


printf("Size of Char is %lu \n",(unsigned long) sizeof(mychar));
printf("Size of int is %lu \n",(unsigned long) sizeof(myint));
printf("Size of float is %lu \n",(unsigned long) sizeof(myfloat));
printf("Size of double is %lu \n",(unsigned long) sizeof(mydouble));
printf("Size of short is %lu \n",(unsigned long) sizeof(myshort));
printf("Size of long is %lu \n",(unsigned long) sizeof(mylong));
printf("Size of long int is %lu \n",(unsigned long) sizeof(mylongint));
printf("Size of long long is %lu \n",(unsigned long) sizeof(mylonglong));
printf("Size of int8_t is %lu \n",(unsigned long) sizeof(int8_t));
printf("Size of uint8_t is %lu \n", (unsigned long) sizeof(uint8_t));

printf("Size of int16_t is %lu \n",(unsigned long) sizeof(int16_t));
printf("Size of int32_t is %lu \n",(unsigned long) sizeof(int32_t));

printf("Size of Char* is %lu \n",(unsigned long) sizeof(mychar1));
printf("Size of int* is %lu \n",(unsigned long) sizeof(myint1));
printf("Size of float* is %lu \n",(unsigned long) sizeof(myfloat1));
printf("Size of void* is %lu \n",(unsigned long) sizeof(myvoid1));

printf("Size of int8_t* is %lu \n" ,(unsigned long) sizeof(int8_t *));
printf("Size of int16_t* is %lu \n" ,(unsigned long) sizeof(int16_t *));
printf("Size of int32_t* is %lu \n" ,(unsigned long) sizeof(int32_t *));

	char s[100];
	printf("Enter the string\n");
	scanf("%99[^\n]", s);
	int arrsize = strlen(s);

	char temparr[arrsize];
	strcpy(temparr, s);

	char prevMemory = *(s-1);
	char postMemory = *(s+arrsize);
	
	printf("String before reverse = %s\n", s);
	
	char ret = reverse_string((char *)s, strlen(s));
	
	int strrevcheck1 = 1;
	int i=0;	
	for(i=0;i<strlen(s);i++){
		if(*(temparr+i) != *(s+strlen(s) -i -1))
			strrevcheck1= 0;
	}

	
	int strrevcheck2 = 1;
	i=0;
	for(i=0;i<strlen(s);i++){
		if((temparr[i]) != s[strlen(s) -i -1])
			strrevcheck2= 0;
	}

	int negcheck3 =1;
	if(prevMemory!=*(s-1) || postMemory!=*(s+strlen(s)))
		negcheck3=0;



	if (strrevcheck1==1 && strrevcheck2==1 && negcheck3 ==1 && ret==0)
		printf("String after  reverse = %s\n", s);
	else
		printf("Error, Not able to reverse");


 return 0;
}


