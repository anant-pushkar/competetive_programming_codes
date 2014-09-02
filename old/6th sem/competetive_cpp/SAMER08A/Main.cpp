/*
Project name : SAMER08A
Created on : Wed Mar 12 10:23:53 2014
Author : Anant Pushkar
http://www.spoj.com/problems/SAMER08A/
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<deque>
#include<queue>
#include<utility>
#include<vector>
using namespace std;
bool debug=false;
typedef long long int lld;
const int inf=1<<30;
struct Comparator{
	bool operator()(const pair<int,pair<int,int> > &lhs, const pair<int,pair<int,int> > &rhs){
		return lhs.second.second > rhs.second.second;
	}
};
typedef priority_queue<pair<int,pair<int,int> > , vector<pair<int,pair<int,int> > >, Comparator> p_queue;
class Graph{
	int nVertices , nEdges , s , d;
	vector<deque<pair<int,int> > > adjList;
	vector<vector<bool> > blacklist;
	int getAlmostShortest(){
		vector<int> distTo=vector<int>(nVertices,inf) ;
		queue<pair<int,pair<int,int> > > pq;
		
		distTo[s]=0;
		for(int i=0;i<adjList[s].size();++i)if(!blacklist[s][adjList[s][i].first]){
			pq.push(make_pair(s,adjList[s][i]));
		}
		
		int v;
		pair<int,int> e;
		while(!pq.empty()){
			e=pq.front().second;
			v=pq.front().first;
			pq.pop();
			if(blacklist[v][e.first] || distTo[e.first]<distTo[v]+e.second)continue;
			
			distTo[e.first]=distTo[v]+e.second;
			for(int i=0;i<adjList[e.first].size();++i)if(!blacklist[e.first][adjList[e.first][i].first]){
				pq.push(make_pair(e.first,adjList[e.first][i]));
			}
		}
		return distTo[d];
	}
	void deleteShortest(){
		vector<int> distTo=vector<int>(nVertices,inf) ;
		vector<queue<int> > edgeTo=vector<queue<int> >(nVertices);
		queue<pair<int,pair<int,int> > > pq;
		
		distTo[s]=0;
		for(int i=0;i<adjList[s].size();++i){
			pq.push(make_pair(s,adjList[s][i]));
		}
		
		int v;
		pair<int,int> e;
		while(!pq.empty()){
			e=pq.front().second;
			v=pq.front().first;
			pq.pop();
			if(distTo[e.first]<distTo[v]+e.second)continue;
			
			distTo[e.first]=distTo[v]+e.second;
			edgeTo[e.first].push(v);
			for(int i=0;i<adjList[e.first].size();++i){
				pq.push(make_pair(e.first,adjList[e.first][i]));
			}
		}
		
		queue<int> list;
		list.push(d);
		int u;
		while(!list.empty()){
			v=list.front();list.pop();
			while(!edgeTo[v].empty()){
				u=edgeTo[v].front();
				blacklist[u][v]=true;
				list.push(u);
				edgeTo[v].pop();
			}
		}
	}
public:
	Graph(int n , int m):
	nVertices(n),
	nEdges(m),
	blacklist(vector<vector<bool> >(n,vector<bool>(n,false))),
	adjList(vector<deque<pair<int,int> > >(n)){
		scanf("%d %d",&s,&d);
		int u,v,p;
		for(int i=0;i<m;++i){
			scanf("%d %d %d",&u,&v,&p);
			adjList[u].push_back(make_pair(v,p));
		}
	}
	int solve(){
		deleteShortest();
		int d=getAlmostShortest();
		return d!=inf ? d : -1 ;
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n,m;
	while(1){
		scanf("%d %d",&n,&m);
		if(n==0 && m==0)break;
		Graph g(n,m);
		printf("%d\n",g.solve());
	}
	return 0;
}

