/*
Project name : Flowers_Flourish_from_France
Created on : Thu Jun  5 16:19:45 2014
Author : Anant Pushkar
http://www.spoj.com/problems/MFLAR10/
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<ctype.h>
typedef long long int lld;
typedef unsigned long long int llu;
int debug=0;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	char str[200] , c , C;
	int i;
	while(1){
		scanf("%199[^\n]",str);
		if(strlen(str)==1 && str[0]=='*')
			break;
		i=0;
		while(str[i]==' ')
			++i;
		c = str[i];
		if(islower(c))
			C = (char)(c-'a'+'A');
		else
			C = (char)(c-'A'+'a');
		while(i<strlen(str)-1){
			if(str[i]==' ' && (str[i+1]==c || str[i+1]==C) )
				++i;
			else{
				printf("N\n");
				scanf("%c",&str[0]);
				continue;
			}
		}
		printf("Y\n");
		scanf("%c",&str[0]);
	}
	return 0;
}
