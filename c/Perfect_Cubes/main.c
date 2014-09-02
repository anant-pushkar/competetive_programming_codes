/*
Project name : Perfect_Cubes
Created on : Wed Jul 30 14:06:27 2014
Author : Anant Pushkar

*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
typedef long long int lld;
typedef unsigned long long int llu;
int debug=0;
int cubes[101];
int lookup[101][101];
void init(){
	int i;
	for(i=0;i<=100;++i){
		cubes[i] = i*i*i;
	}
}
void clear_lookup(){
	int i , j;
	for(i=0;i<100;++i){
		for(j=0;j<=100;++j){
			lookup[i][j] = 0;
		}
	}
}
int search_cubes(int val){
	if(val < 8){
		return -1;
	}
	int start = 0 , end = 100 , mid;
	while(end-start>1){
		mid = (start+end)/2;
		if(cubes[mid]>val){
			end = mid;
		}else if(cubes[mid]<val){
			start = mid+1;
		}else{
			return mid;
		}
	}
	return cubes[start]==val ? start : -1;
}
void enumerate(){
	int i , j , k , index;
	for(i=2;i<=100;++i){
		clear_lookup();
		for(j=2;j<=100;++j){
			for(k=j+1;k<=100;++k){
				index = search_cubes(cubes[i]-cubes[j]-cubes[k]);
				if(lookup[index][k]==0 && lookup[index][j]==0 && index!=-1){
					printf("Cube = %d, Triple = (%d,%d,%d)\n" , i , j , k , index);
					lookup[index][k]=1;
					lookup[index][j]=1;
					lookup[j][index]=1;
					lookup[k][index]=1;
					lookup[j][k] = 1;
					lookup[k][j] = 1;
				}
			}
		}
	}
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	init();
	enumerate();
	return 0;
}
