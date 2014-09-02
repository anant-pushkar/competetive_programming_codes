/*
Project name : AE00
Created on : Fri May 16 10:22:25 2014
Author : Anant Pushkar
http://www.spoj.com/problems/AE00/
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>
typedef long long int lld;
typedef unsigned long long int llu;
int debug=0;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int n;
	scanf("%d",&n);
	if(n<4){
		printf("%d\n",n);
		return 0;
	}
	int i,j;
	llu count=3;
	for(i=3;i<n;++i){
		for(j=1;j<=sqrt(i+1);++j)if((i+1)%j==0){
			++count;
		}
	}
	
	printf("%llu\n",count);
	
	return 0;
}
