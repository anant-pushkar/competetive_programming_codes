/*
Project name : CANDY
Created on : Sat Sep  6 12:44:13 2014
Author : Anant Pushkar
http://www.spoj.com/problems/LQDCANDY/
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
typedef long long int lld;
typedef unsigned long long int llu;
int debug=0;
lld get_next_pow(lld n){
	if((n&(n-1)) == 0){
		return n;
	}
	while( (n&(n-1)) > 0){
		n = n&(n-1);
	}
	return n<<1;
}
lld count_breaks(lld n){
	if((n&(n-1)) == 0){
		return 0;
	}
	lld mask=-1 , count=0;
	while( (n&mask) == n ){
		mask = mask<<1;
		++count;
	}
	
	n = n>>(count-1);
	if(debug)printf("n:%lld\n",n);
	
	count=0;
	while(n>0){
		++count;
		n = n>>1;
	}
	
	return count;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int t;
	scanf("%d",&t);
	
	lld n;
	while(t--){
		scanf("%lld",&n);
		printf("%lld %lld\n",get_next_pow(n) , count_breaks(n));
		if(debug)printf("========\n");
	}
	
	return 0;
}
