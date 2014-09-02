/*
Project name : TRIKA
Created on : Fri Dec 20 18:20:59 2013
http://www.spoj.com/problems/TRIKA/
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<utility>
using namespace std;
bool debug=false;
const int inf=1<<29;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n,m;scanf("%d %d",&n,&m);
	int x,y;scanf("%d %d",&x,&y);
	vector<vector<int> > court(n+1,vector<int>(m+1));
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			scanf("%d",&court[i][j]);
		}
	}
	vector<vector<int> > lookup(n+1,vector<int>(m+1,inf));
	queue<pair<int,int> > q;
	pair<int,int> p;
	
	lookup[x][y]=0;
	q.push(make_pair(x,y));
	while(!q.empty()){
		p=q.front();q.pop();
		if(p.first==n && p.second==m)break;
		if(p.first+1<=n && lookup[p.first+1][p.second]>lookup[p.first][p.second]+court[p.first+1][p.second]){
			lookup[p.first+1][p.second]=lookup[p.first][p.second]+court[p.first+1][p.second];
			q.push(make_pair(p.first+1,p.second));
		}
		if(p.second+1<=m && lookup[p.first][p.second+1]>lookup[p.first][p.second]+court[p.first][p.second+1]){
			lookup[p.first][p.second+1]=lookup[p.first][p.second]+court[p.first][p.second+1];
			q.push(make_pair(p.first,p.second+1));
		}
	}
	int bal=court[x][y]-lookup[n][m];
	if(bal<0)printf("N\n");
	else printf("Y %d\n",bal);
	return 0;
}

