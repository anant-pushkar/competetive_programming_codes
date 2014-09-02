/*
Project name : Cut_the_Silver_Bar
Created on : Tue Jun  3 15:58:13 2014
Author : Anant Pushkar
http://www.spoj.com/problems/SILVER/
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
	int n,p,v;
	while(1){
		scanf("%d",&n);
		if(n==0)
			break;
		v=1;p=0;
		while(n>0){
			n /= 2;
			++p;
			v *= 2;
		}
		printf("%d\n",p-1);
	}
	return 0;
}
