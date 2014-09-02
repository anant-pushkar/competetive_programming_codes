/*
Project name : COMPILER
Created on : Sat May  3 12:38:10 2014
Author : Anant Pushkar
Codechef May challenge
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#define LEN 1000001
int debug=0;
typedef long long int lld;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int t,i;scanf("%d",&t);
	char str[LEN];
	int count,pre_len;
	while(t--){
		scanf("%s",str);
		count=0;
		pre_len=0;
		for(i=0;i<strlen(str);++i){
			if(str[i] == '<')++count;
			else if(str[i] == '>'){
				if(count>0)--count;
				else break;
				if(count==0)pre_len=i+1;
			}
		}
		printf("%d\n",pre_len);
		
	}
	return 0;
}
