/*
Project name : AP_-_Complete_The_Series__Easy_
Created on : Sat May 24 22:34:51 2014
Author : Anant Pushkar
http://www.spoj.com/problems/AP2/
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
	llu t;
	scanf("%llu",&t);
	llu a3,l3,s,a,d,n,i;
	while(t--){
		scanf("%llu %llu %llu",&a3,&l3,&s);
		n = (2*s)/(a3+l3);
		d = n!=5 ? (l3-a3)/(n-5) : 0;
		a = a3 - 2*d;
		printf("%llu\n",n);
		for(i=0;i<n;++i){
			printf("%llu ",a);
			a += d;
		}
	}
	return 0;
}
