#include <stdio.h>
#include <stdint.h>

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

typedef int8_t INT8;
typedef uint8_t BYTE;
typedef int8_t INT8;
typedef uint8_t UNINT8;
typedef int16_t INT16;
typedef uint16_t UINT16;
typedef int32_t INT32;
typedef uint32_t UNINT32;
typedef int64_t INT64;
typedef uint64_t UINT64;




printf("Size of Char is %lu \n", sizeof(mychar));
printf("Size of int is %lu \n", sizeof(myint));
printf("Size of float is %lu \n", sizeof(myfloat));
printf("Size of double is %lu \n", sizeof(mydouble));
printf("Size of short is %lu \n",sizeof(myshort));
printf("Size of long is %lu \n", sizeof(mylong));
printf("Size of long int is %lu \n", sizeof(mylongint));
printf("Size of long long is %lu \n", sizeof(mylonglong));
printf("Size of int8_t is %lu \n", sizeof(int8_t));
printf("Size of uint8_t is %lu \n", sizeof(uint8_t));

printf("Size of int16_t is %lu \n",sizeof(int16_t));
printf("Size of int32_t is %lu \n",sizeof(int32_t));

printf("Size of Char* is %lu \n", sizeof(mychar1));
printf("Size of int* is %lu \n", sizeof(myint1));
printf("Size of float* is %lu \n", sizeof(myfloat1));
printf("Size of void* is %lu \n", sizeof(myvoid1));

printf("Size of int8_t* is %lu \n" ,sizeof(int8_t *));
printf("Size of int16_t* is %lu \n" ,sizeof(int16_t *));
printf("Size of int32_t* is %lu \n" ,sizeof(int32_t *));


 return 0;
}


