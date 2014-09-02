/*
Project name : Halloween_party
Created on : Mon Jul 21 19:05:13 2014
Author : Anant Pushkar
https://www.hackerrank.com/challenges/halloween-party
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
	int t , k;
	scanf("%d",&t);
	
	lld max;
	while(t--){
		scanf("%d",&k);
		max  = k/2;
		max *= k-max;
		printf("%lld\n",max);
	}
	return 0;
}
