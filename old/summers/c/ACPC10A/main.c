/*
Project name : ACPC10A
Created on : Thu May 15 16:09:24 2014
Author : Anant Pushkar
http://www.spoj.com/problems/ACPC10A/
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
	int a,b,c;
	while(1){
		scanf("%d %d %d",&a,&b,&c);
		if(a==0 && b==0 && c==0)break;
		if(2*b==a+c)printf("AP %d\n",c+b-a);
		else printf("GP %d\n",c*b/a);
	}
	return 0;
}
