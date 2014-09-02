/*
Project name : FASHION
Created on : Thu May 15 15:52:37 2014
Author : Anant Pushkar
http://www.spoj.com/problems/FASHION/
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#define NUM 1001
typedef long long int lld;
typedef unsigned long long int llu;
int debug=0;\
int n , arr1[NUM] , arr2[NUM];
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int t,i;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=0;i<n;++i) scanf("%d",&arr1[i]);
		for(i=0;i<n;++i) scanf("%d",&arr2[i]);
	}
	return 0;
}
