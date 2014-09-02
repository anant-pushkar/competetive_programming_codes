/*
Project name : Rectangular_Game
Created on : Sat May 17 12:29:24 2014
Author : Anant Pushkar
https://www.hackerrank.com/contests/101mar14/challenges/rectangular-game
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
	int n,a,b,x=INT_MAX,y=INT_MAX;
	scanf("%d",&n);
	while(n--){
		scanf("%d %d",&a,&b);
		x = x>a ? a : x;
		y = y>b ? b : y;
	}
	lld pro = (lld)x * (lld)y ;
	printf("%lld\n",pro);
	return 0;
}
