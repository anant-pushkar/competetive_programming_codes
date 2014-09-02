/*
Project name : Chocolate_Feast
Created on : Mon Jul 21 19:32:10 2014
Author : Anant Pushkar
https://www.hackerrank.com/challenges/chocolate-feast
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
typedef long long int lld;
typedef unsigned long long int llu;
int debug=0;
int m;
lld get_count(lld n){
	if(debug)printf("called on %lld\n",n);
	if(n/m==0){
		return 0;
	}
	return n/m + get_count(n%m + n/m);
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int t , n , c;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d %d",&n,&c,&m);
		printf("%lld\n",n/c + get_count(n/c));
	}
	return 0;
}
