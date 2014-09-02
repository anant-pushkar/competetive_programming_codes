/*
Project name : Triple_Fat_Ladies
Created on : Sat May 17 09:53:31 2014
Author : Anant Pushkar
http://www.spoj.com/problems/EIGHTS/
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
	int t;scanf("%d",&t);
	llu k;
	int num[4] = {192 , 442 , 692 , 942};
	while(t--){
		scanf("%llu",&k);
		--k;
		printf("%llu\n",(1000*(k/4) + num[k%4]));
	}
	return 0;
}
