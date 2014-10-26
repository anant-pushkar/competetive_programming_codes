/*
Project name : Ground_Stations
Created on : Sat Oct 11 20:00:37 2014
Author : Anant Pushkar
http://www.codechef.com/ACMAMR14/problems/ACM14AM2'
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
#include<unordered_set>
using namespace std;
bool debug=false;
typedef long long int lld;
typedef unsigned long long int llu;
class Solver{
	int m;
	llu count;
	deque<deque<int> > adj_list;
	void add_node(int n){
		adj_list[n].push_back(adj_list.size());
		adj_list.push_back(deque<int>());
	}
	pair<int,int> bipartite_count(int node){
		int n = adj_list[node].size();
		vector<pair<int,int> > count_list(n);
		
		for(int i=0;i<n;++i){
			count_list[i] = bipartite_count(adj_list[node][i]);
		}
		
		for(int i=0;i<n;++i){
			for(int j=i+1;j<n;++j){
				count += count_list[i].first*count_list[j].first + count_list[i].second*count_list[j].second ;
			}
		}
		
	}
pubblic:
	Solver(int x):
	m(x){
		adj_list.push_back(deque<int>());
	}
	void start(){
		int type , v;
		for(int i=0;i<m;++i){
			scanf("%d %d",&type , &v);
			if(type==0){
				add_node(v);
			}
		}
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t;
	scanf("%d",&t);
	
	int m;
	while(t--){
		scanf("%d",&m);
		Solver s(m);
		s.start();
	}
	
	return 0;
}

