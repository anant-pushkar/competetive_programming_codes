/*
Project name : Angry_Children
Created on : Mon Jul 21 22:14:31 2014
Author : Anant Pushkar
https://www.hackerrank.com/challenges/angry-children
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>
typedef long long int lld;
typedef unsigned long long int llu;
int debug=0;
int cmpfunc (const void * a, const void * b){
   return ( *(int*)a - *(int*)b );
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int n , k;
	scanf("%d",&n);
	scanf("%d",&k);
	
	int count[n] , i , j;
	for(i=0;i<n;++i){
		scanf("%d",&count[i]);
	}
	
	qsort(count , n , sizeof(int) , cmpfunc);
	
	i=0;
	j=k-1;
	int min = INT_MAX , diff;
	while(j<n){
		diff = count[j]-count[i];
		min  = min>diff ? diff : min;
		++i;
		++j;
	}
	printf("%d\n",min);
	
	return 0;
}
