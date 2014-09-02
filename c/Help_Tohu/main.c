/*
Project name : Help_Tohu
Created on : Sun Aug 31 18:24:24 2014
Author : Anant Pushkar
http://www.spoj.com/problems/TOHU/
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
	int t;
	scanf("%d",&t);
	
	int n;
	long double sum , x;
	while(t--){
		scanf("%d",&n);
		sum = 0;
		for(int k=1;k<=n;++k){
			x = (long double)k;
			sum += 1/(x*(x+1)*(x+2));
		}
		printf("%.11Lg\n",sum);
	}
	
	return 0;
}
