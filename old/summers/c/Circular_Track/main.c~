/*
Project name : Circular_Track
Created on : Mon Jun 16 15:43:40 2014
Author : Anant Pushkar
http://www.spoj.com/problems/SPEED/
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
typedef long long int lld;
typedef unsigned long long int llu;
int debug=0;
int gcd(int a , int b){
	a = a>0 ? a : -a;
	b = b>0 ? b : -b;
	if(a<b){
		a = a^b;
		b = a^b;
		a = a^b;
	}
	if(a%b==0){
		return b;
	}
	return gcd(b,a%b);
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int t,s1,s2,s,d;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&s1,&s2);
		d = gcd(s1,s2);
		s = s1-s2;
		s = s>0 ? s : -s;
		printf("%d\n",s/d);
	}
	return 0;
}
