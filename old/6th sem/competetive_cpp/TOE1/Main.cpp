/*
Project name : TOE1
Created on : Sat Jan 18 14:21:15 2014
Author : Anant Pushkar
spoj : basic if-else implementation
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
	int t;scanf("%d",&t);
	while(t--){
		scanf("%s",grid);
		scanf("%s",grid+3);
		scanf("%s",grid+6);
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
			if(xwin>0 && owin>0){
				printf("no\n");
			}else if(xwin>0){
				if(x=o+1)printf("yes\n");
				else printf("no\n");
			}else if(owin>0){
				if(x==o)printf("yes\n");
				else printf("no\n");
			}else printf("yes\n");
		}else printf("no\n");
	}
	return 0;
}

