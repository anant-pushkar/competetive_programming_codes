/*
Project name : Labyrinth
Created on : Tue Jun 10 13:41:40 2014
Author : Anant Pushkar
http://www.spoj.com/problems/LABYR1/
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
typedef long long int lld;
typedef unsigned long long int llu;
int debug=0;
int endX , endY , r , c , maxLen;
char grid[1000][1000];
int getMax(int arr[4]){
	int max=0 , val , i;
	for(i=0;i<4;++i){
		val = arr[i];
		max = val<max ? max : val ;
	}
	return max;
}
int dfs(int x , int y , int len , int px , int py){
	if(x>=r || x<0 || y>=c || y<0 || grid[x][y]=='#')
		return len;
	if(len+1>maxLen){
		maxLen = len+1;
		endX   = x;
		endY   = y;
	}
	int l1 = px==x-1 && py==y ? 0 : dfs(x-1,y,len+1,x,y);
	int l2 = px==x+1 && py==y ? 0 : dfs(x+1,y,len+1,x,y);
	int l3 = px==x && py==y-1 ? 0 : dfs(x,y-1,len+1,x,y);
	int l4 = px==x && py==y+1 ? 0 : dfs(x,y+1,len+1,x,y);
	int arr[4] = {l1,l2,l3,l4};
	int max = getMax(arr)+1;
	return max;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int t , i , j , x , y;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&c,&r);
		for(i=0;i<r;++i){
			scanf("%s",grid[i]);
			for(j=0;j<c;++j){
				if(grid[i][j]=='.'){
					x=i;y=j;
				}
			}
		}
		endX=-1;endY=-1;maxLen=0;
		dfs(x,y,0,x,y);
		
		maxLen=0;
		dfs(endX,endY,0,endX,endY);
		
		printf("Maximum rope length is %d.\n",maxLen-1);
	}
	return 0;
}
