/*
Project name : Borya_and_Hanabi
Created on : Sat Jun 21 18:51:57 2014
Author : Anant Pushkar
http://codeforces.com/contest/442/problem/A
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<deque>
#include<queue>
#include<utility>
#include<vector>
#include<climits>
#include<algorithm>
#include<stack>
using namespace std;
bool debug=false;
typedef long long int lld;
typedef unsigned long long int llu;
bool is_miscible(const vector<bool> &v1 , const vector<bool> &v2){
	bool check = false , check1=false , check2=false;
	for(int i=0;i<v1.size();++i){
		check = check || v1[i]&&v2[i];
		check1 = check1 || v1[i];
		check2 = check2 || v2[i];
	}
	return (!check)&&(check1||check2);
}
vector<bool> getCol(const vector<vector<bool> > &v , int index){
	int size = v.size();
	vector<bool> col(size);
	for(int i=0;i<size;++i){
		col[i] = v[i][index];
	}
	return col;
}
void mixRow(vector<vector<bool> > &v , int i1 , int i2){
	int size=v[i1].size();
	for(int i=0;i<size;++i){
		v[i1][i] = v[i1][i] | v[i2][i];
		v[i2][i] = v[i1][i];
	}
}
void mixCol(vector<vector<bool> > &v , int i1 , int i2){
	int size=v[i1].size();
	for(int i=0;i<size;++i){
		v[i][i1] = v[i][i1] | v[i][i2];
		v[i][i2] = v[i][i1];
	}
}
void print(const vector<vector<bool> > &v){
	int row = v.size() , col=v[0].size();
	for(int i=0;i<row;++i){
		for(int j=0;j<col;++j){
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n;
	scanf("%d",&n);
	char cards[n][3];
	vector<vector<bool> > grid(5,vector<bool>(5,false)) , grid2(5,vector<bool>(5,false));
	for(int i=0;i<n;++i){
		scanf("%s",&cards[i]);
		if(cards[i][0]=='R'){
			if(debug)cout<<"Red"<<cards[i][1]-'1'<<endl;
			grid[0][cards[i][1]-'1'] = true;
			grid2[0][cards[i][1]-'1'] = true;
		}
		if(cards[i][0]=='G'){
			if(debug)cout<<"Green"<<cards[i][1]-'1'<<endl;
			grid[1][cards[i][1]-'1'] = true;
			grid2[1][cards[i][1]-'1'] = true;
		}
		if(cards[i][0]=='B'){
			if(debug)cout<<"Blue"<<cards[i][1]-'1'<<endl;
			grid[2][cards[i][1]-'1'] = true;
			grid2[2][cards[i][1]-'1'] = true;
		}
		if(cards[i][0]=='Y'){
			if(debug)cout<<"Yellow"<<cards[i][1]-'1'<<endl;
			grid[3][cards[i][1]-'1'] = true;
			grid2[3][cards[i][1]-'1'] = true;
		}
		if(cards[i][0]=='W'){
			if(debug)cout<<"White"<<cards[i][1]-'1'<<endl;
			grid[4][cards[i][1]-'1'] = true;
			grid2[4][cards[i][1]-'1'] = true;
		}
	}
	if(debug)print(grid);
	int row=5 , col=5;
	for(int i=0;i<5;++i){
		for(int j=i+1;j<5;++j){
			if(is_miscible(grid[i],grid[j])){
				mixRow(grid,i,j);
				--row;
				if(debug)print(grid);
			}
		}
	}
	for(int i=0;i<5;++i){
		for(int j=i+1;j<5;++j){
			if(is_miscible(getCol(grid2,i),getCol(grid2,j))){
				mixCol(grid2,i,j);
				--col;
				if(debug)print(grid2);
			}
		}
	}
	if(debug)cout<<"row : "<<row<<" col : "<<col<<endl;
	printf("%d\n",row+col-2);
	
	return 0;
}

