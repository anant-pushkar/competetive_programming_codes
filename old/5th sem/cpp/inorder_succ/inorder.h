#pragma once
#include<iostream>
static const int DEFAULT=999999;
struct Node{
	int data;
	Node* parent;
	Node* left;
	Node* right;
	Node(int val=DEFAULT , Node* p=NULL);
};
class BST{
	Node *root;
	int size;
	void insert(int n=DEFAULT);
	Node *find(int);
	Node *succesor(Node*,int);
	Node *findLeftMost(Node*);
public:
	BST(int size=0);
	int getSuccesor(int);
	
};