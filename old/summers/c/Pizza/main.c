/*
Project name : Pizza
Created on : Mon May 26 20:20:16 2014
Author : Anant Pushkar
http://www.spoj.com/problems/EGYPIZZA/
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
typedef long long int lld;
typedef unsigned long long int llu;
int debug=0;
int getPizzaCount(int a , int b , int c){
	int count = 0;
	count += c;
	b = b>c ? b-c : 0;
	count += a/2 + b/4 ;
	if(a%2 == 1 && b%4==3)
		count += 2;
	else if(a%2!=0 || b%4!=0)
		count += 1;
		
	return count + 1 ;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int n , a=0 , b=0 , c=0 ;
	scanf("%d",&n);
	
	char str[4];
	while(n--){
		scanf("%s",str);
		if(strcmp(str,"1/2")==0)
			++a;
		if(strcmp(str,"1/4")==0)
			++b;
		if(strcmp(str,"3/4")==0)
			++c;
	}
	
	printf("%d\n",getPizzaCount(a,b,c));
	return 0;
}
