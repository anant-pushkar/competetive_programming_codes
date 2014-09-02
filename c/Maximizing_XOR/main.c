/*
Project name : Maximizing_XOR
Created on : Mon Jul 21 19:20:24 2014
Author : Anant Pushkar
https://www.hackerrank.com/challenges/maximizing-xor
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
typedef long long int lld;
typedef unsigned long long int llu;
int debug=0;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int l,r;
	scanf("%d",&l);
	scanf("%d",&r);
	
	int i , j , val=0;
	for(i=l;i<=r;++i){
		for(j=i+1;j<=r;++j){
			val = val>(i^j) ? val : (i^j);
		}
	}
	
	printf("%d\n",val);
	return 0;
}
