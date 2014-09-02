/*
Project name : Appleman_and_Easy_Task
Created on : Tue Aug 26 19:31:42 2014
Author : Anant Pushkar
http://codeforces.com/contest/462/problem/0
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
int n;
vector<string> grid;
inline int check(int x , int y){
	if(x<0 || x>=n || y<0 || y>=n){
		return 0;
	}
	return grid[x][y]=='o' ? 1 : 0;
}
bool is_true(){
	int count;
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			count=0;
			count += check(i-1,j);
			count += check(i+1,j);
			count += check(i,j-1);
			count += check(i,j+1);
			
			if(count%2==1){
				return false;
			}
		}
	}
	return true;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	
	scanf("%d" , &n);
	grid = vector<string>(n);
	for(int i=0;i<n;++i){
		cin>>grid[i];
	}
	printf("%s\n" , is_true() ? "YES" : "NO");
	
	
	return 0;
}

