/*
Project name : Coke_madness
Created on : Mon Jun 16 15:59:40 2014
Author : Anant Pushkar
http://www.spoj.com/problems/RPLC/
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
	int t , T , n , val;
	lld min , sum;
	scanf("%d",&T);
	for(t=1;t<=T;++t){
		scanf("%d",&n);
		min = INT_MAX;
		sum = 0;
		while(n--){
			scanf("%d",&val);
			sum += val;
			min = min>sum ? sum : min ;
			if(debug)printf("min:%lld sum:%lld\n",min,sum);
		}
		printf("Scenario #%d: %lld\n",t,min>0 ? 1 : -min+1);
	}
	return 0;
}
