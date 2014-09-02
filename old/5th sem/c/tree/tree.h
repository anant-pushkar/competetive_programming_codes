#pragma once 
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct _node{
	int val;
	struct _node* left;
	struct _node* right;
};
typedef struct _node node;
node *generateRandom(int,int,int);
int getParents(int,node*);
int getLeastCommonParent(int,int,node*);
int checkBalance(node*);
node *generateBST(int);
node *getSubTree(node*,int);
node* getDList(node*);