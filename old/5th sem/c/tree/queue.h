#pragma once 
#include<stdio.h>
#include<stdlib.h>
#include"tree.h"
struct _link{
	node *n;
	struct _link *next;
	int level;
};
typedef struct _link link;
struct _queue{
	link *front;
	link *back;
	int size;
};
typedef struct _queue queue;
queue* initQ();
node* getFront(queue*);