/*
Project name : NSTEPS
Created on : Thu May 15 11:14:01 2014
Author : Anant Pushkar
http://www.spoj.com/problems/NSTEPS/
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
	int t,x,y;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&x,&y);
		if(x==y){
			if(x%2==0)printf("%d\n",2*x);
			else printf("%d\n",2*x-1);
		}else if(x==y+2){
			if(y%2==0)printf("%d\n",2*y+2);
			else printf("%d\n",2*y+1);
		}else printf("No Number\n");
	}
	return 0;
}
