/*
Project name : Police_Operation
Created on : Sat Aug 30 20:15:16 2014
Author : Anant Pushkar
https://www.hackerrank.com/contests/101aug14/challenges/police-operation
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
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n , h;
	scanf("%d %d",&n,&h);
	
	vector<int> pos(n);
	for(int i=0;i<n;++i){
		scanf("%d",&pos[i]);
	}
	
	lld next_cost;
	vector<lld> starts_at(n,0) , blends_at(n,0) , blends_to(n,0);
	blends_to[n-1]=pos[n-1];
	for(int i=m-2;i>-1;--i){
		
	}
	
	return 0;
}

