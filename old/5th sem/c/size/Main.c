/*
Project name : size
Created on : Thu Dec 12 11:26:17 IST 2013
dummy project to know size of various  primitive data types

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int debug=0;
typedef struct{int a;char b;} type1;
typedef struct{int a,b;} type2;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	printf("Size of int %d\n",sizeof(int));
	printf("Size of long %d\n",sizeof(long));
	printf("Size of long long %d\n",sizeof(long long));
	printf("Size of long int %d\n",sizeof(long int));
	printf("Size of long long int %d\n",sizeof(long long int));
	printf("Size of short %d\n",sizeof(short));
	printf("Size of float %d\n",sizeof(float));
	printf("Size of double %d\n",sizeof(double));
	printf("Size of char %d\n",sizeof(char));
	int *arr=(int*)calloc(3,sizeof(int));
	printf("Size of calloc(3,sizeof(int)) %d\n",sizeof(arr));
	int array[3];
	printf("Size of int[3] %d\n",sizeof(array));
	printf("Size of struct{int a;char b;} %d\n",sizeof(type1));
	printf("Size of struct{int a,b;} %d\n",sizeof(type2));
	return 0;
}
