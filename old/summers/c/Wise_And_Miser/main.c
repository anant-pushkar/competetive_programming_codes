/*
Project name : Wise_And_Miser
Created on : Thu Jun  5 16:04:24 2014
Author : Anant Pushkar
http://www.spoj.com/problems/MISERMAN/
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
typedef long long int lld;
typedef unsigned long long int llu;
int debug=0;
int min(int a , int b , int c){
	return a>b ? b>c ? c : b : a>c ? c : a ;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int n , m , i , j , soln = INT_MAX;
	scanf("%d %d",&n,&m);
	int cost[n][m+2] ;
	for(i=0;i<n;++i){
		cost[i][0]   = INT_MAX;
		cost[i][m+1] = INT_MAX;
		for(j=1;j<=m;++j)
			scanf("%d",&cost[i][j]);
	}
	for(i=1;i<n;++i){
		for(j=1;j<=m;++j){
			cost[i][j] += min(cost[i-1][j-1] , cost[i-1][j] , cost[i-1][j+1]);
		}
	}
	if(debug){
		for(i=0;i<n;++i){
			for(j=0;j<m;++j)
				printf("%d ",cost[i][j]);
			printf("\n");
		}
	}
	for(i=1;i<=m;++i)
		soln = soln<cost[n-1][i] ? soln : cost[n-1][i];
	printf("%d\n",soln);
	return 0;
}
