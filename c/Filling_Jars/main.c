/*
Project name : Filling_Jars
Created on : Mon Jul 21 19:45:04 2014
Author : Anant Pushkar
https://www.hackerrank.com/challenges/filling-jars
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
	int n , m;
	scanf("%d %d",&n,&m);
	
	int a , b;
	lld sum=0 , k;
	while(m--){
		scanf("%d %d %lld",&a,&b,&k);
		sum += (b-a+1)*k;
	}
	printf("%lld\n",sum/n);
	return 0;
}
