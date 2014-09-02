/*
Project name : OJUMPS
Created on : Sat May  3 11:51:06 2014
Author : Anant Pushkar
Codechef May challenge
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int debug=0;
typedef long long int lld;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	lld n;scanf("%lld",&n);
	if(n%3==0 || (n-1)%6==0)printf("yes\n");
	else printf("no\n");
	return 0;
}
