/*
Project name : Alice_Sieve
Created on : Mon Jun 16 13:47:33 2014
Author : Anant Pushkar
http://www.spoj.com/problems/ALICESIE/
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
typedef long long int lld;
typedef unsigned long long int llu;
int debug=0;
int getSieveCount(int n){
	return (n+1)/2;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		printf("%d\n",getSieveCount(n));
	}
	return 0;
}
