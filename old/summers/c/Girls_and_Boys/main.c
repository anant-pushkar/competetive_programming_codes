/*
Project name : Girls_and_Boys
Created on : Sat May 24 20:01:29 2014
Author : Anant Pushkar
http://www.spoj.com/problems/GIRLSNBS/
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
	int a,b;
	while(1){
		scanf("%d %d",&a,&b);
		if(a==-1 && b==-1)break;
		if(a<b){
			a = a^b;
			b = a^b;
			a = a^b;
		}
		printf("%d\n",(int)ceil((double)a/(b+1)));
	}
	return 0;
}
