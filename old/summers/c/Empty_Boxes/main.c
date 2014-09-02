/*
Project name : Empty_Boxes
Created on : Wed Jun 11 14:28:28 2014
Author : Anant Pushkar
http://www.spoj.com/problems/EBOXES/
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
	int x,n,k,t,f;
	scanf("%d",&x);
	while(x--){
		scanf("%d %d %d %d",&n,&k,&t,&f);
		printf("%d\n" , (f-n)/(k-1)*k+n);
	}
	return 0;
}
