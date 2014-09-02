/*
Project name : Evaluate_the_polynomial
Created on : Thu Jun 12 19:49:40 2014
Author : Anant Pushkar
http://www.spoj.com/problems/POLEVAL/
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
typedef long long int lld;
typedef unsigned long long int llu;
int debug=0;
lld eval(int n , int c[] , int x){
	lld val = c[0];
	int i;
	for(i=1;i<=n;++i){
		if(debug)printf("val : %lld\n",val);
		val = val*x + c[i];
	}
	return val;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int n , c[1001] , k , x , i , t=1;
	while(1){
		scanf("%d",&n);
		if(n==-1){
			break;
		}
		for(i=0;i<=n;++i){
			scanf("%d",&c[i]);
		}
		scanf("%d",&k);
		printf("Case %d:\n",t++);
		for(i=0;i<k;++i){
			scanf("%d",&x);
			printf("%lld\n",eval(n,c,x));
		}
	}
	return 0;
}
