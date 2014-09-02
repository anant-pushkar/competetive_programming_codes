/*
Project name : Two_squares_or_not_two_squares
Created on : Thu May 29 15:24:23 2014
Author : Anant Pushkar
http://www.spoj.com/problems/TWOSQRS/
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>
#define MAX 100000000
typedef unsigned long long int llu;
int debug=0;
int isSquare(llu n){
	if(n%4>1)
		return 0;
	if(n<MAX){
		int root = sqrt(n);
		return root*root == n;
	}
	int r = n%MAX;
	if(!isSquare(r))
		return 0;
	n -= r;
	n /= MAX;
	n -= 2*sqrt(r);
	if(n%MAX!=0)
		return 0;
	return isSquare(n/MAX);
}
int isSqSum(llu n){
	if(n%4==3)
		return 0;
	llu i;
	for(i=0;i*i<n/2+1;++i)
		if(isSquare(n-i*i))	
			return 1;
	return 0;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int c ;
	scanf("%d",&c);
	llu n;
	while(c--){
		scanf("%llu",&n);
		if(isSqSum(n))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
