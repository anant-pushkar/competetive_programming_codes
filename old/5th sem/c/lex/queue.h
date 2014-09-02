#pragma once 
#include<stdio.h>
#include<stdlib.h>
struct _node{
	int val;
	struct _node *next;
};
typedef struct _node node;
struct _queue{
	node *front;
	node *back;
	int size;
};
typedef struct _queue queue;
queue* initQ();