#pragma once
#include<stdlib.h>
typedef struct{
	int* head;
	long int count;
} Array;
long int Search(Array,int);
long int _binarySearch(int* arr , long int lo , long int hi , int k);