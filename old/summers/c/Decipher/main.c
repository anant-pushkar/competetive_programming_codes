/*
Project name : Decipher
Created on : Mon Jun  9 11:29:09 2014
Author : Anant Pushkar
http://www.spoj.com/problems/ROOTCIPH/
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
	lld t , a , b , c;
	scanf("%lld",&t);
	while(t--){
		scanf("%lld %lld %lld",&a,&b,&c);
		printf("%lld\n",a*a-2*b);
	}
	return 0;
}
