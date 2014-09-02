/*
Project name : Penney_Game
Created on : Mon May 26 15:55:51 2014
Author : Anant Pushkar
http://www.spoj.com/problems/NY10A/
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#define TTT 0
#define TTH 1
#define THT 2
#define THH 3
#define HTT 4
#define HTH 5
#define HHT 6
#define HHH 7
void getCount(char str[] , int count[]){
	int i;
	for(i=0;i<8;++i)
		count[i]=0;
	
	int l = strlen(str);
	for(i=2;i<l;++i){
		if(strncmp(str+i-2 , "TTT" , 3)==0)
			++count[TTT];
		if(strncmp(str+i-2 , "TTH" , 3)==0)
			++count[TTH];
		if(strncmp(str+i-2 , "THT" , 3)==0)
			++count[THT];
		if(strncmp(str+i-2 , "THH" , 3)==0)
			++count[THH];
		if(strncmp(str+i-2 , "HTT" , 3)==0)
			++count[HTT];
		if(strncmp(str+i-2 , "HTH" , 3)==0)
			++count[HTH];
		if(strncmp(str+i-2 , "HHT" , 3)==0)
			++count[HHT];
		if(strncmp(str+i-2 , "HHH" , 3)==0)
			++count[HHH];
	}
}
int main()
{
	char str[41];
	int t,n,count[8],i;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		printf("%d ",n);
		
		scanf("%s",str);
		getCount(str,count);
		
		for(i=0;i<8;++i){
			printf("%d ",count[i]);
		}
		printf("\n");
	}
	return 0;
}
