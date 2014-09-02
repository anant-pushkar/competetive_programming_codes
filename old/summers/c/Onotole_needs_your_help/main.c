/*
Project name : Onotole_needs_your_help
Created on : Mon May 26 21:45:58 2014
Author : Anant Pushkar
http://www.spoj.com/problems/OLOLO/
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
	int N ;
	lld n , x=1^1;
	scanf("%d",&N);
	while(N--){
		scanf("%lld",&n);
		x = x^n;
	}
	printf("%lld\n",x);
	return 0;
}
