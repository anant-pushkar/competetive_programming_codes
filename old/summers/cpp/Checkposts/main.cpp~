/*
Project name : Checkposts
Created on : Sun May 11 10:17:04 2014
Author : Anant Pushkar
http://codeforces.com/contest/427/problem/C
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
class Graph{
	vector<deque<int> > adjList , rList;
	vector<lld> cost;
	vector<bool> lookup;
	int E , V;
	void dfs(int v,const vector<deque<int> > &list , stack<int> &st){
		if(lookup[v]) return;
		lookup[v] = true;
		for(int i=0;i<list[v].size();++i)
			if(!lookup[list[v][i]]) dfs(list[v][i],list,st);	
		st.push(v);
	}
public:
	Graph(){
		scanf("%d",&V);
		cost = vector<lld>(V);
		adjList = vector<deque<int> >(V);
		rList = vector<deque<int> >(V);
		for(int i=0;i<V;++i)scanf("%lld",&cost[i]);
		
		int a,b;
		scanf("%d",&E);
		for(int i=0;i<E;++i){
			scanf("%d %d",&a,&b);
			--a;--b;
			adjList[a].push_back(b);
			rList[b].push_back(a);
		}
	}
	pair<lld,int> solve(){
		stack<int> s;
		lookup = vector<bool>(V,false);
		for(int i=0;i<V;++i)dfs(i,adjList,s);
		int v;
		
		lookup = vector<bool>(V,false);
		stack<int> c;
		vector<int> cList;
		lld minCost = 0 , nCost = 1 , index , min , count;
		while(!s.empty()){
			v=s.top();s.pop();
			if(lookup[v])continue;
			if(debug)cout<<"Vertex : "<<v<<endl;
			dfs(v,rList,c);
			cList = vector<int>(c.size());
			index=0;
			while(!c.empty()){
				cList[index++] = c.top();
				c.pop();
			}
			if(debug){
				cout<<"Connected component : ";
				for(int i=0;i<cList.size();++i)cout<<cList[i]<<" ";
				cout<<endl;
			}
			
			min = LLONG_MAX;
			for(int i=0;i<cList.size();++i)min = min>cost[cList[i]] ? cost[cList[i]] : min ;
			minCost += min;
			
			count=0;
			for(int i=0;i<cList.size();++i)if(cost[cList[i]]==min) ++count;
			nCost *= count%1000000007;
			nCost  = nCost%1000000007;
			
			if(debug)cout<<"minCost="<<minCost<<" "<<"count="<<count<<endl<<endl;
		}
		return make_pair(minCost,nCost);
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	Graph g;
	pair<lld,int> soln = g.solve();
	printf("%lld %d\n",soln.first,soln.second);
	
	return 0;
}

