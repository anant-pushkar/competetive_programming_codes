/*
Project name : PLAY_WITH_MATH
Created on : Fri Aug  1 18:16:04 2014
Author : Anant Pushkar

*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
typedef long long int lld;
typedef unsigned long long int llu;
int debug=0;
int get_gcd(int a , int b){
	if(a<b){
		a = a^b;
		b = a^b;
		a = a^b;
	}
	if(a%b==0){
		return b;
	}
	return get_gcd(b , a%b);
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int t;
	scanf("%d",&t);
	
	int a , b , gcd;
	while(t--){
		scanf("%d %d",&a,&b);
		gcd = get_gcd(a,b);
		printf("%d %d\n" , b/gcd , a/gcd);
	}
	
	return 0;
}
