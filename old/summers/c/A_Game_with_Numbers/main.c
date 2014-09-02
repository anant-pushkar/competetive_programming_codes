/*
Project name : A_Game_with_Numbers
Created on : Sat May 24 22:26:08 2014
Author : Anant Pushkar
http://www.spoj.com/problems/NGM/
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
	llu n;
	scanf("%llu",&n);
	if(n%10 == 0)printf("2\n");
	else printf("1\n%llu\n",n%10);
		
	return 0;
}
