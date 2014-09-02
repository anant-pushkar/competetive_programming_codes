/*
Project name : Bitmap
Created on : Sun Feb 16 14:07:48 2014
Author : Anant Pushkar
http://www.spoj.com/problems/BITMAP/
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<deque>
#include<vector>
#include<queue>
#include<utility>
using namespace std;
bool debug=false;
typedef long long int lld;
int n,m,x,y,d;
vector<string> grid;
vector<vector<int> > dist;
queue<pair<int,int> > q;
inline void enqueue(int a,int b){
	if(a>=0 && a<n && b>=0 && b<m && dist[a][b]==-1){
		q.push(make_pair(a,b));
		dist[a][b]=d+1;
	}
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t;cin>>t;
	while(t--){
		cin>>n>>m;
		grid=vector<string>(n);
		dist=vector<vector<int> >(n,vector<int>(m,-1));
		for(int i=0;i<n;++i)cin>>grid[i];
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				if(grid[i][j]=='1'){
					q.push(make_pair(i,j));
					dist[i][j]=0;
				}
			}
		}
		while(!q.empty()){
			x=q.front().first;
			y=q.front().second;
			q.pop();
			d=dist[x][y];
			
			enqueue(x-1,y);
			enqueue(x+1,y);
			enqueue(x,y-1);
			enqueue(x,y+1);
		}
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				cout<<dist[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}

