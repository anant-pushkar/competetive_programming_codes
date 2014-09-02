/*
Project name : CSTREET
Created on : Fri Jan 17 02:44:37 2014
Author : Anant Pushkar
http://www.spoj.com/problems/CSTREET/
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<deque>
#include<queue>
using namespace std;
bool debug=false;
struct Comparator{
	bool operator()(const pair<int,int>& lhs, const pair<int,int>& rhs){
		return lhs.second>rhs.second;
	}
};
class Graph{
	int nVertices,nEdges;
	vector<deque<pair<int,int> > >adjList;
public:
	Graph(int n,int m):
	nVertices(n),
	nEdges(m),
	adjList(vector<deque<pair<int,int> > >(n)){
		int a,b,c;
		while(m--){
			scanf("%d %d %d",&a,&b,&c);
			--a;--b;
			adjList[a].push_back(make_pair(b,c));
			adjList[b].push_back(make_pair(a,c));
		}
	}
	int solve(){
		std::priority_queue<pair<int,int>, std::vector<pair<int,int> >, Comparator> pq;
		int cost=0,count=1,v,d;
		vector<bool> lookup(nVertices,false);
		
		lookup[0]=true;
		for(int i=0;i<adjList[0].size();++i)pq.push(adjList[0][i]);
		
		while(count<nVertices){
			do{
				v=pq.top().first;
				d=pq.top().second;
				pq.pop();
			}while(!pq.empty() && lookup[v]);
			if(debug)cout<<"Processing "<<v+1<<endl;
			lookup[v]=true;
			++count;
			cost+=d;
			for(int i=0;i<adjList[v].size();++i){
				if(debug)cout<<"Adding "<<adjList[v][i].first+1<<endl;
				pq.push(adjList[v][i]);
			}
			if(debug)cout<<endl;
		}
		return cost;
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t,p,n,m;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&p);
		scanf("%d",&n);
		scanf("%d",&m);
		Graph g(n,m);
		printf("%d\n",g.solve()*p);
	}
	return 0;
}

