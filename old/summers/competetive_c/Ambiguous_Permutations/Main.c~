/*
Project name : Ambiguous_Permutations
Created on : Thu May 22 11:39:17 2014
Author : Anant Pushkar
http://www.spoj.com/problems/PERMUT2/
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
int debug=0;
typedef long long int lld;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int n,i,count;
	int pos[100000] , num[100000];
	while(1){
		scanf("%d",&n);
		if(n==0)break;
		for(i=0;i<n;++i){
			scanf("%d",&num[i]);
			pos[num[i]-1]=i+1;
		}
		count=0;
		for(i=0;i<n;++i)if(pos[i]==num[i])++count;
		if(count==n)printf("ambiguous\n");
		else printf("not ambiguous\n");
	}
	return 0;
}
