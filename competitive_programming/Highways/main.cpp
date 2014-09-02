/*
Project name : Highways
Created on : Mon Aug 25 16:00:45 2014
Author : Anant Pushkar
http://www.spoj.com/problems/HIGHWAYS/
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
struct CompareObj{
	bool operator()(const pair<int,lld> &p1 , const pair<int,lld> &p2){
		return p1.second>p2.second;
	}
};
class Solver{
	int n , m , s , e;
	vector<deque<pair<int,lld> > > adj_list;
	vector<lld> dist_to;
	priority_queue<pair<int,lld> , vector<pair<int,lld> > , CompareObj> pq;
	
	void visit(int v , lld dist){
		if(dist_to[v] <= dist ){
			return;
		}
		dist_to[v] = dist ;
		if(debug)cout<<"visiting "<<v<<" : "<<dist<<endl;
		pq.push(make_pair(v , dist));
	}
public:
	Solver(){
		scanf("%d %d %d %d",&n , &m , &s , &e);
		--s;--e;
		adj_list = vector<deque<pair<int,lld> > >(n);
		dist_to  = vector<lld>(n , LLONG_MAX);
		
		int x , y ;
		lld d;
		for(int i=0;i<m;++i){
			scanf("%d %d %lld",&x , &y , &d);
			--x;--y;
			adj_list[x].push_back(make_pair(y,d));
			adj_list[y].push_back(make_pair(x,d));
		}
	}
	lld solve(){
		visit(s , 0);
		
		int v , size;
		while(!pq.empty()){
			v = pq.top().first;
			pq.pop();
			
			if(debug)cout<<"expanding "<<v<<endl;
			if(v==e){
				return dist_to[e];
			}
			
			size = adj_list[v].size();
			for(int i=0;i<size;++i){
				visit(adj_list[v][i].first , dist_to[v]+adj_list[v][i].second);
			}
			
			if(debug)cout<<"======================"<<endl;
		}
		
		return -1;
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t ;
	lld d ;
	scanf("%d",&t);
	
	while(t--){
		Solver s;
		d = s.solve();
		if(d>=0){
			cout<<d<<endl;
		}else{
			cout<<"NONE"<<endl;
		}
	}
	
	return 0;
}

