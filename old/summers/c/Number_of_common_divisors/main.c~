/*
Project name : Number_of_common_divisors
Created on : Mon Jun 16 13:57:58 2014
Author : Anant Pushkar
http://www.spoj.com/problems/COMDIV/
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>
typedef long long int lld;
typedef unsigned long long int llu;
int debug=0;
int gcd(int a , int b){
	if(b%a==0){
		return a;
	}
	return gcd(b%a,a);
}
int countDivisors(int n){
	if(debug)printf("Finding divisor count of %d\n",n);
	int i,count=0;
	for(i=1;i<sqrt(n);++i){
		if(n%i==0){
			count += 2;
			if(debug)printf("%d,%d added\n",i,n/i);
		}
	}
	if(i*i==n){
		if(debug)printf("%d added\n",i);
		count += 1;
	}
	return count;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int t,a,b;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&a,&b);
		printf("%d\n",countDivisors(gcd(a,b)));
	}
	return 0;
}
