/*
Project name : Project_File_Dependencies
Created on : Fri Aug 29 19:32:14 2014
Author : Anant Pushkar
http://www.spoj.com/problems/PFDEP/
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
	int n , m;
	vector<deque<int> > adj_list;
	vector<bool> lookup;
	stack<int> s;
	void dfs(int v){
		if(lookup[v]){
			return;
		}
		lookup[v] = true;
		int size = adj_list[v].size();
		for(int i=0;i<size;++i){
			dfs(adj_list[v][i]);
		}
		s.push(v+1);
	}
	void solve(){
		for(int i=n-1;i>-1;--i){
			dfs(i);
		}
	}
public:
	Solver(int a , int b):
	n(a),
	m(b),
	lookup(vector<bool>(a,false)),
	adj_list(vector<deque<int> >(a)){
		int t , t0 , k;
		for(int i=0;i<m;++i){
			scanf("%d %d",&t0,&k);
			--t0;
			for(int j=0;j<k;++j){
				scanf("%d",&t);
				--t;
				adj_list[t].push_back(t0);
			}
		}
		for(int i=0;i<n;++i){
			sort(adj_list[i].begin() , adj_list[i].end() , greater<int>());
		}
	}
	void print_soln(){
		solve();
		while(!s.empty()){
			printf("%d ",s.top());
			s.pop();
		}
		printf("\n");
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n,m;
	scanf("%d %d",&n,&m);
	
	Solver s(n,m);
	s.print_soln();
	
	return 0;
}

