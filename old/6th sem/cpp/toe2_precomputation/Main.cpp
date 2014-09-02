/*
Project name : toe2_precomputation
Created on : Sat Jan 18 13:37:25 2014
Author : Anant Pushkar
precomputation for all states in toe2 problem spoj
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
bool debug=false;
bool gameOver(string grid){
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
	for(int i=0;i<8;++i){
		if(grid[pos[i][1]]!='.' && grid[pos[i][1]]==grid[pos[i][0]] && grid[pos[i][1]]==grid[pos[i][2]]){
			return true;
		}
	}
	return false;
}
vector<string> valid;
int idx;
void play(string grid,char move){
	//cout<<grid<<" "<<move<<endl;
	if(gameOver(grid)){
		valid[idx++]=grid;
		//++idx;
		return ;
	}
	string temp;
	for(int i=0;i<grid.size();++i)if(grid[i]=='.'){
		temp=grid;
		temp[i]=move;
		play(temp,(move=='O'?'X':'O'));
	}
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	valid=vector<string>(209089,".........");
	idx=0;
	play(".........",'X');
	//for(int i=0;i<idx;++i)cout<<valid[i]<<endl;
	//cout<<idx<<endl;
	return 0;
}

