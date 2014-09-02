/*
Project name : Call_of_Duty
Created on : Sat Aug  9 21:20:09 2014
Author : Anant Pushkar

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
class Solver{
	int n , end;
	vector<deque<int> > adjList;
	vector<bool> lookup;
	vector<int> dist_to;
	queue<int> cycle;
	bool dfs(int v , int p){
		int has_met=false , size=adjList[v].size() , n;
		lookup[v] = true;
		
		for(int i=0;i<size;++i)if(adjList[v][i]!=p){
			n = adjList[v][i];
			if(lookup[n]){
				has_met = true;
				end = end==-1 ? n : end;
				if(debug)cout<<"end : "<<n<<endl;
			}else{
				has_met = has_met || dfs(n , v);
			}
		}
		
		if(debug && has_met){
			cout<<v<<" has met"<<endl;
		}
		
		if(has_met){
			cycle.push(v);
			has_met = v==end ? false : true;
		}
		
		return has_met ;
	}
	void propogate(){
		int v , dist , size;
		queue<int> q , d;
		while(!cycle.empty()){
			v = cycle.front();
			cycle.pop();
			
			q.push(v);
			d.push(0);
		}
		
		while(!q.empty()){
			v = q.front();q.pop();
			dist = d.front();d.pop();
			
			dist_to[v] = dist_to[v]>dist ? dist : dist_to[v];
			
			size = adjList[v].size();
			for(int i=0;i<size;++i)if(dist_to[adjList[v][i]]==INT_MAX){
				q.push(adjList[v][i]);
				d.push(dist+1);
			}
		}
	}
public:
	Solver(int x):
	n(x),
	adjList(vector<deque<int> >(n)),
	lookup(vector<bool>(n , false)),
	end(-1),
	dist_to(vector<int>(n,INT_MAX)){
		int a , b;
		for(int i=0;i<n;++i){
			scanf("%d %d",&a , &b);
			--a;--b;
			adjList[a].push_back(b);
			adjList[b].push_back(a);
		}
		dfs(0,0);
	}
	void print_lags(){
		propogate();
		for(int i=0;i<n;++i){
			cout<<dist_to[i]<<" ";
		}
		cout<<endl;
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n;
	scanf("%d",&n);
	
	Solver s(n);
	s.print_lags();
	
	return 0;
}

