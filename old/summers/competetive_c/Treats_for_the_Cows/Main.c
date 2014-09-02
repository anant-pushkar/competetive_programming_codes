/*
Project name : Treats_for_the_Cows
Created on : Wed May 28 14:21:34 2014
Author : Anant Pushkar
http://www.spoj.com/problems/TRT/
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
int debug=0;
typedef long long int lld;
int v[2000] , n;
lld lookup[2000][2000];
void init(){
	int i,j;
	for(i=0;i<n;++i)
		for(j=0;j<n;++j)
			lookup[i][j] = -1;
}
lld getMax(int start , int end , int age){
	if(start==end){
		lookup[start][end] = v[start]*age;
		return v[start]*age;
	}
	
	if(lookup[start][end] != -1)
		return lookup[start][end];
	
	int v1 = v[start]*age + getMax(start+1 , end , age+1) ;
	int v2 = v[end]  *age + getMax(start , end-1 , age+1) ;
	
	lookup[start][end] = v1>v2 ? v1 : v2;
	return lookup[start][end];
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int i;
	scanf("%d",&n);
	
	init();
	for(i=0;i<n;++i)
		scanf("%d",&v[i]);
	
	printf("%lld\n",getMax(0,n-1,1));
	
	return 0;
}
