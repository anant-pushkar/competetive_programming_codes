#pragma once
#include<stdlib.h>
#include"array.h"
void Sort(Array,int);
void _mergeSort(int* , long int , long int );
void _merge(int* , long int , long int );
Array* initPq(int);
Array* makeHeap(Array*);
void heapify(Array* , int );
void swap(Array* , int , int);
void insert(Array* , int);
void bubbleUp(Array* , int);
int extractMin(Array*);
int countLessThan(Array* , int , int , int);
void _heapSort(Array*);
void _quickSort(Array* , int , int);