/*
Project name : Cards
Created on : Thu May 29 12:09:22 2014
Author : Anant Pushkar
http://www.spoj.com/problems/CRDS/
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#define SIZE 1000001
#define MOD  1000007
int debug=0;
typedef long long int lld;
int lookup[SIZE];
void init(){
	int i;
	for(i=0;i<SIZE;++i)
		lookup[i]=-1;
	lookup[0] = 0;
	lookup[1] = 2;
}
int getSoln(int n){
	if(n<0 || n>=SIZE) 
		return -1;
	if(lookup[n] != -1) 
		return lookup[n];
	lookup[n] = getSoln(n-1) + (3*n - 1)%MOD;
	lookup[n] = lookup[n]%MOD;
	return lookup[n];
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int t , n;
	scanf("%d",&t);
	init();
	while(t--){
		scanf("%d",&n);
		printf("%d\n",getSoln(n));
	}
	return 0;
}
