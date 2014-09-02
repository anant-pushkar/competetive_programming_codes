/*
Project name : A_concrete_simulation
Created on : Fri Aug  1 14:41:23 2014
Author : Anant Pushkar
http://www.spoj.com/problems/ACS/
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
typedef long long int lld;
typedef unsigned long long int llu;
int debug=0;
int ** arr;
int *r , *c;
void init(){
	arr = (int**)calloc(1234 , sizeof(int*));
	r = (int*) calloc(1234 , sizeof(int));
	c = (int*) calloc(5678 , sizeof(int));
	
	int i , j , val=1;
	for(i=0;i<1234;++i){
		arr[i] = (int*)calloc(5678 , sizeof(int));
		for(j=0;j<5678;++j){
			arr[i][j] = val++;
		}
	}
	for(i=0;i<1234;++i){
		r[i] = i;
	}
	for(i=0;i<5678;++i){
		c[i] = i;
	}
}
void swap_row(int x , int y){
	int *ptr = arr[x];
	arr[x] = arr[y];
	arr[y] = ptr;
	
	int temp = r[x];
	r[x] = r[y];
	r[y] = temp;
}
void swap_col(int x , int y){
	int i;
	for(i=0;i<1234;++i){
		arr[i][x] = arr[i][x]^arr[i][y];
		arr[i][y] = arr[i][x]^arr[i][y];
		arr[i][y] = arr[i][x]^arr[i][y];
	}
	
	int temp = c[x];
	c[x] = c[y];
	c[y] = temp;
}

int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	char q[2];
	int x , y , i;
	init();
	while(scanf("%s %d",q , &x)){
		switch(q[0]){
			case 'R':
				scanf("%d",&y);
				swap_row(x-1,y-1);
				break;
			case 'C':
				scanf("%d",&y);
				swap_col(x-1,y-1);
				break;
			case 'Q':
				scanf("%d",&y);
				printf("%d\n",arr[x-1][y-1]);
				break;
			case 'W':
				i=2;
				y=1;
				while(x>5678){
					if(x%i==0){
						x /= i;
						y *= i;
					}
					++i;
				}
				printf("%d %d\n",r[y-1]+1,c[x-1]+1);
				break;
		}
	}
	return 0;
}
