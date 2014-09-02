/*
Project name : longest_path_in_tree
Created on : Sun Feb 16 14:51:04 2014
Author : Anant Pushkar
http://www.spoj.com/problems/PT07Z/
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<deque>
#include<vector>
using namespace std;
bool debug=false;
typedef long long int lld;
vector<deque<int> > adjList;
int m;
int dfs(int s,int p){
	int a=0,b=0,d;
	for(int i=0;i<adjList[s].size();++i)if(adjList[s][i]!=p){
		d=dfs(adjList[s][i],s)+1;
		if(d>a){
			b=a;a=d;
		}else if(d>b){
			b=d;
		}
	}
	m=a+b>m?a+b:m;
	if(debug)cout<<"dfs("<<s<<","<<p<<")="<<m<<endl;
	return a;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n,a,b;
	cin>>n;
	adjList=vector<deque<int> >(n);
	for(int i=0;i<n-1;++i){
		cin>>a>>b;
		adjList[a-1].push_back(b-1);
		adjList[b-1].push_back(a-1);
	}
	m=0;
	dfs(0,0);
	cout<<m<<endl;
	return 0;
}

