/*
Project name : Service_Lane
Created on : Mon Jul 21 18:28:09 2014
Author : Anant Pushkar
https://www.hackerrank.com/challenges/service-lane
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
typedef long long int lld;
typedef unsigned long long int llu;
int debug=0;
int getMin(int width[] , int i , int j){
	int min = INT_MAX , index=i;
	while(index<=j){
		min = min>width[index] ? width[index] : min;
		++index;
	}
	return min;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int n , t;
	scanf("%d %d",&n , &t);
	
	int width[n] , i;
	for(i=0;i<n;++i){
		scanf("%d",&width[i]);
	}
	
	int j;
	while(t--){
		scanf("%d %d",&i,&j);
		printf("%d\n",getMin(width,i,j));
	}
	return 0;
}
