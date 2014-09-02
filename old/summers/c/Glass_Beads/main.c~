/*
Project name : Glass_Beads
Created on : Tue Jun 10 13:34:32 2014
Author : Anant Pushkar
http://www.spoj.com/problems/BEADS/
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
	int t,i,len,index;
	scanf("%d",&t);
	char str[20001];
	while(t--){
		scanf("%s",str);
		len = strlen(str);
		for(i=len;i<2*len;++i)
			str[i] = str[i-len];
		index=0;
		for(i=1;i<len;++i){
			if(strncmp(str+index,str+i,len)>0){
				index=i;
			}
		}
		printf("%d\n",index+1);
	}
	return 0;
}

