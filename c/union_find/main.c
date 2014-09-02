/*
Project name : union_find
Created on : Sat Jul 19 09:53:39 2014
Author : Anant Pushkar
Union-FInd implementation in c
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
typedef long long int lld;
typedef unsigned long long int llu;
int debug=0;
typedef struct{
	int parent;
	int rank;
} set;

typedef struct{
	set* lookup;
	int size;
} container;

container* new_container(int n){
	container *c_ptr = (container*) malloc(sizeof(container));
	c_ptr->lookup    = (set*) calloc(n , sizeof(set));
	c_ptr->size      = n;
	while(n--){
		c_ptr->lookup[n].parent = n;
		c_ptr->lookup[n].rank   = 1;
	}
	return c_ptr;
}

set* find(container* c_ptr , int index){
	if(c_ptr->lookup[index].parent == index){
		return &c_ptr->lookup[index];
	}
	set* s = find(c_ptr , c_ptr->lookup[index].parent);
	c_ptr->lookup[index].parent = s->parent;
	return s;
}

void set_union(container* c_ptr , int i1 , int i2){
	set* s1 = find(c_ptr , i1);
	set* s2 = find(c_ptr , i2);
	
	if(s1->rank > s2->rank){
		s2->parent = s1->parent;
	}else if(s2->rank > s1->rank){
		s1->parent = s2->parent;
	}else{
		s1->parent = s2->parent;
		++s2->rank;
	}
}

int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int n;
	scanf("%d",&n);
	
	container *c_ptr = new_container(n);
	char cmd[2];
	int x , y;
	set* s;
	while(1){
		scanf("%s",cmd);
		if(cmd[0] == 'e'){
			break;
		}
		switch(cmd[0]){
			case 'u':
				scanf("%d %d",&x,&y);
				set_union(c_ptr,x,y);
				break;
			case 'f':
				scanf("%d",&x);
				s = find(c_ptr,x);
				printf("Set:%d , Rank:%d\n",s->parent,s->rank);
				break;
			default:
				printf("Invalid command\n");
				break;
		}
	}
	
	return 0;
}
