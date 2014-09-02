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
	bool operator()(const pair<pair<int,int>,lld> &p1 , const pair<pair<int,int>,lld> &p2){
		return p1.second>p2.second;
	}
};
class Solver{
	int n , m , k;
	vector<deque<pair<int,lld> > > adj_list;
	vector<pair<int,lld> > dist_to;
	vector<bool> visited;
	priority_queue<pair<pair<int,int>,lld> , vector<pair<pair<int,int>,lld> > , CompareObj> pq;
	
	void visit(int v , lld dist , int p){
		if(visited[v]){
			return;
		}
		if(debug)cout<<"visiting "<<v<<" : "<<dist<<" p :"<<p<<endl;
		pq.push(make_pair(make_pair(v,p) , dist));
	}
public:
	Solver(){
		scanf("%d %d %d",&n , &m , &k);
		adj_list = vector<deque<pair<int,lld> > >(n);
		dist_to  = vector<pair<int,lld> >(n);
		visited  = vector<bool>(n, false);
		
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
		visit(0 , 0 , 0);
		dist_to[0] = make_pair(0 , 0);
		
		int v , size , p , count=0;
		lld d;
		while(!pq.empty()){
			v = pq.top().first.first;
			p = pq.top().first.second;
			d = pq.top().second;
			pq.pop();
			if(debug)cout<<"looking at "<<v<<endl;
			if(visited[v]){
				continue;
			}
			if(v<k){
				++count;
			}
			visited[v] = true;
			dist_to[v] = make_pair(p,d);
			
			if(count==k){
				break;
			}
			
			if(debug)cout<<"expanding "<<v<<" dist : "<<dist_to[v].second<<" p : "<<p<<endl;
			
			size = adj_list[v].size();
			for(int i=0;i<size;++i){
				visit(adj_list[v][i].first , adj_list[v][i].second , v);
			}
			
			if(debug)cout<<"======================"<<endl;
		}
		
		lld sum=0;
		visited  = vector<bool>(n, false);
		for(int i=1;i<k;++i)if(!visited[i]){
			p = i;
			while(p!=0 && ((p<k &&!visited[p]) || p>=k )){
				visited[p] = true;
				sum += dist_to[p].second;
				if(debug)cout<<"At "<<p<<" going to "<<dist_to[p].first<<" : "<<dist_to[p].second<<" sum :"<<sum<<endl;
				p = dist_to[p].first;
			}
		} 
		
		return sum;
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
		cout<<s.solve()<<endl;
	}
	
	return 0;
}


