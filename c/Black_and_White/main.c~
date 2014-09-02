/*
Project name : Black_and_White
Created on : Thu Jul 31 13:43:21 2014
Author : Anant Pushkar
http://www.spoj.com/problems/BANDW/
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
	char s[501] , t[501];
	int len , count , total , i;
	while(1){
		scanf("%s %s",s,t);
		
		if(s[0]=='*' && t[0]=='*'){
			break;
		}
		
		len = strlen(s);
		count = s[0]==t[0] ? 0 : 1;
		total = 0;
		for(i=1;i<len;++i){
			if(s[i]!=t[i]){
				count  = 1;
			}else{
				total += count;
				count  = 0;
			}
		}
		total += count;
		
		printf("%d\n",total);
	}
	return 0;
}
