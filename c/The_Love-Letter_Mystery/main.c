/*
Project name : The_Love-Letter_Mystery
Created on : Mon Jul 21 18:35:27 2014
Author : Anant Pushkar
https://www.hackerrank.com/challenges/the-love-letter-mystery
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
typedef long long int lld;
typedef unsigned long long int llu;
int debug=0;
int getMinOp(char str[]){
	int l = strlen(str);
	if(l<2){
		return 0;
	}
	int i = l/2 + (l%2) , j = l/2 - 1;
	int diff , count = 0;
	while(i<l){
		diff = str[i]-str[j];
		diff = diff>0 ? diff : -diff;
		count += diff;
		
		++i;
		--j;
	}
	return count;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int t;
	scanf("%d",&t);
	
	char str[10002];
	while(t--){
		scanf("%s",str);
		printf("%d\n",getMinOp(str));
	}
	return 0;
}
