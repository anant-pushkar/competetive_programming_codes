/*
Project name : max_freq
Created on : Fri Mar 21 13:31:32 2014
Author : Anant Pushkar
given an array, find number with max frequency
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int debug=0;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	
	int N,num,count[201];
	scanf("%d",&N);
	memset(count,0,sizeof(count));
	
	while(N--){
		scanf("%d",&num);
		++count[num+100];
	}
	
	int max_val=0 , max_index=-1 , i;
	for(i=0;i<201;++i)if(max_val<count[i]){
		max_val=count[i];
		max_index=i-100;
	}
	
	printf("%d\n",max_index);
	
	return 0;
}
