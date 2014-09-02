/*
Project name : Candy_III
Created on : Fri May 16 10:50:19 2014
Author : Anant Pushkar
http://www.spoj.com/problems/CANDY3/
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
	lld t,n,a,i,sum;
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		sum=0;
		for(i=0;i<n;++i){
			scanf("%lld",&a);
			sum += a%n;
			sum = sum%n;
		}
		if(sum%n==0)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
