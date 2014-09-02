/*
Project name : Between_the_Mountains
Created on : Wed Jun  4 14:37:29 2014
Author : Anant Pushkar
http://www.spoj.com/problems/ACPC11B/
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
	int t , n , h[1000] , val , i , m , min;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=0;i<n;++i)
			scanf("%d",&h[i]);
		scanf("%d",&m);
		min = INT_MAX;
		while(m--){
			scanf("%d",&val);
			for(i=0;i<n;++i){
				min = min<abs(val-h[i]) ? min : abs(val-h[i]);
			}
		}
		printf("%d\n",min);
	}
	return 0;
}
