/*
Project name : Around_the_World_in_N_Ways
Created on : Mon May 19 21:10:13 2014
Author : Anant Pushkar
https://www.hackerrank.com/contests/apc/challenges/around-the-world-in-n-ways
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#define MOD 1000000007
#define SIZE 10000001
typedef long long int lld;
typedef unsigned long long int llu;
int debug=0;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int t;scanf("%d",&t);
	int n , a , b , c , d;
	while(t--){
		scanf("%d",&n);
		if(n==1)c=1;
		else if(n==2)c=2;
		else if(n==3)c=4;
		else{
			a=1;b=2;c=4;
			while(n--!=3){
				d=a+b+c;
				b=c;
				a=b;
				c=d;
			}
		}
		printf("%d\n",c);
	}
	return 0;
}
