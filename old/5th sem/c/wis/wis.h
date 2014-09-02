#pragma once
#include<stdio.h>
#include<stdlib.h>
typedef struct{
	int start;
	int end;
	double weight;
}Interval;
typedef struct{
	int *arr;
	int count;
	double weight;
}Schedule;
Interval* generateIntervalSet(int);
void printIntervalSet(Interval*,int);
int* populatePrevious(Interval* , int);
void printfPrevious(int* , int);
void traverse(Interval* , int* , int);

