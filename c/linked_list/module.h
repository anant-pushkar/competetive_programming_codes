/*
Project name : linked_list
Module name  : module
Created on : Wed Aug  6 17:59:06 2014
Author : Anant Pushkar
Linked list library basd on stanford text
*/
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
struct _node{
	int val;
	struct _node *next;
};
typedef struct _node node;

struct _list{
	node* head;
	node* tail;
	int size;
};
typedef struct _list list;
node *new_node();
list *new_list();
node* push(node** , int );
void init_list(list * , int );
void push_to_head(list*  , int );
void push_to_tail(list* , int );
list* create_list(int );
void print_list(list *);
int get_length(list *);
node* find_node(list * , int );
int get_count(list * , int );
node* get_nth(list* , int);
void delete_list(list*);
int pop_from_head(list *);
int pop_from_tail(list*);
void insert_nth(list* , int , int);
void reverse(list*);
void quicksort(list *);
void remove_duplicates(list* );

