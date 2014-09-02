/*
Project name : Marbles
Created on : Mon May 26 14:03:59 2014
Author : Anant Pushkar
http://www.spoj.com/problems/MARBLES/
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
int debug=0;
typedef long long int lld;
lld multiplier(lld n,lld count){
	lld p=1;
	while(count--){
		p *= n;
		--n;
	}
	return p;
}
lld getSoln(lld n , lld k){
	k = k-1<n-k ? k-1 : n-k;
	return multiplier(n-1,k) / multiplier(k,k);
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int t;scanf("%d",&t);
	lld n , k;
	while(t--){
		scanf("%lld %lld",&n,&k);
		printf("%lld\n",getSoln(n,k));
	}
	return 0;
}
