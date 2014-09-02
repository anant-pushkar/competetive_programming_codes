#pragma once
#include<stdio.h>
#include<stdlib.h>
struct _node{
	int val;
	struct _node *next;
};
typedef struct _node node;