/*
Project name : TOE2
Created on : Fri Jan 17 03:56:08 2014
Author : Anant Pushkar
http://www.spoj.com/problems/TOE2/
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<math.h>
using namespace std;
bool debug=false;
int pos[8][3]={
		{0,1,2},
		{3,4,5},
		{6,7,8},
		{0,3,6},
		{1,4,7},
		{2,5,8},
		{0,4,8},
		{2,4,6}
	};
inline int countWin(char grid[10],char c){
	int count=0;
	for(int i=0;i<8;++i){
		if(grid[pos[i][0]]==c && grid[pos[i][1]]==c && grid[pos[i][2]]==c)++count;
	}
	return count;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	char grid[10];
	int check,x,o,e,xwin,owin;
	while(1){
		scanf("%s",grid);
		if(strcmp(grid,"end")==0)break;
		x=0;o=0;e=0;
		for(int j=0;j<9;++j){
			if(grid[j]=='X')++x;
			else if(grid[j]=='O') ++o;
			else ++e;
		}
		if(debug)cout<<"x="<<x<<"o="<<o<<endl;
		if(x==o+1 || x==o){
			xwin=countWin(grid,'X');
			owin=countWin(grid,'O');
			if((e>0 && xwin==0 && owin==0) || (xwin>0 && owin>0)){
				printf("invalid\n");
			}else if(xwin>0){
				if(x=o+1)printf("valid\n");
				else printf("invalid\n");
			}else if(owin>0){
				if(x==o)printf("valid\n");
				else printf("invalid\n");
			}else printf("valid\n");
		}else printf("invalid\n");
	}
	return 0;
}

