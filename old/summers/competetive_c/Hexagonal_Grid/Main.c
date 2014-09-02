/*
Project name : Hexagonal_Grid
Created on : Mon May 19 15:01:29 2014
Author : Anant Pushkar
https://www.hackerrank.com/contests/101mar14/challenges/hexagonal-grid
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
int debug=0;
typedef long long int lld;
int n;
char str[2][11];
int mem[10][10];
int getCount(int a , int b){
	if(debug)printf("%d,%d\n",a,b);
	if(a<-1 || b<-1)return 0;
	if(a==-1 && b==-1)return 1;
	if(a>=0 && b>=0 && mem[a][b]!=-1)return mem[a][b];
	
	int count=0;
	if( (a>=0 && str[0][a]=='1') || (b>=0 && str[1][b]=='1') ){
		if(debug)printf("removing 1\n");
		if(str[0][a]=='1')count = getCount(a-1,b);
		if(str[1][b]=='1')count = getCount(a,b-1);
	}else{
		if(a>=1 && b>=0 && a==b+1)count += getCount(a-1,b-1);
		if(a>=1 && b>=-1 && str[0][a-1]!='1') count += getCount(a-2,b);
		if(a>=-1 && b>=1 && str[1][b-1]!='1') count += getCount(a,b-2);
		if(a==b) count += getCount(a-1,b-1);
	}
	if(debug)printf("%d,%d = %d\n",a,b,count);
	mem[a][b] = count;
	return count;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int t;scanf("%d",&t);
	int i,j;
	while(t--){
		scanf("%d",&n);
		scanf("%s",str[0]);
		scanf("%s",str[1]);
		for(i=0;i<10;++i)for(j=0;j<10;++j)mem[i][j]=-1;
		printf("%s\n",getCount(n-1,n-1)>0 ? "YES" : "NO");
	}
	return 0;
}
