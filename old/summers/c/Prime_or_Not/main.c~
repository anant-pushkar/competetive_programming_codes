/*
Project name : Prime_or_Not
Created on : Thu Jun 12 18:17:35 2014
Author : Anant Pushkar
http://www.spoj.com/problems/PON/
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>
typedef long long int lld;
typedef unsigned long long int llu;
int debug=0;
int isPrime(llu n){
	if(n%2==0){
		return n==2;
	}
	llu i;
	for(i=3;i<sqrtl(n)+1;i+=2){
		if(n%i==0)
			return 0;
	}
	return 1;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int t;
	scanf("%d",&t);
	llu n;
	while(t--){
		scanf("%llu",&n);
		printf("%s\n",isPrime(n)? "YES" : "NO");
	}
	return 0;
}
