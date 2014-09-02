/*
Project name : Musical_Chairs
Created on : Mon Jun 16 13:32:36 2014
Author : Anant Pushkar
http://www.spoj.com/problems/ANARC08H/
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
typedef long long int lld;
typedef unsigned long long int llu;
int debug=0;
int josephus(int n , int k){
	int ans = 0 , i;
	for(i=1;i<=n;++i){
		ans = (ans+k)%i;
	}
	return ans;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int n,d;
	while(1){
		scanf("%d %d",&n,&d);
		if(n==0 && d==0){
			break;
		}
		printf("%d %d %d\n",n,d,josephus(n,d)+1);
	}
	return 0;
}
