/*
Project name : Bytelandian_Blingors_Network
Created on : Wed Jul 30 13:06:38 2014
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
class Set{
	int n;
	vector<int> parent;
	vector<int> wt;
public:
	Set(int num):
	n(num),
	parent(vector<int>(num)),
	wt(vector<int>(num,1)){
		for(int i=0;i<n;++i){
			parent[i] = i;
		}
	}
	int find(int a){
		int p = parent[a];
		while(parent[p]!=p){
			p = parent[p];
		}
		
		parent[a] = p;
		return p;
	}
	void join(int a , int b){
		int p1 = find(a) , p2 = find(b);
		if(p1==p2){
			return;
		}else if(wt[p1]>wt[p2]){
			parent[p2] = p1;
			parent[b]  = p1;
		}else if(wt[p1]<wt[p2]){
			parent[p1] = p2;
			parent[a]  = p2;
		}else{
			parent[p1] = p2;
			++wt[p2];
		}
	}
	bool equal(int a , int b){
		return find(a) == find(b);
	}
};
struct Edge{
	int start , end , cost;
	
	Edge(int s , int e , int c):
	start(s),
	end(e),
	cost(c){
		
	}
};
bool compare_edge_cost(const Edge &e1 , const Edge &e2){
	return e1.cost < e2.cost;
}
ostream& operator<<(ostream &out , const Edge &e){
	out<<"from:"<<e.start<<" to:"<<e.end<<" cost:"<<e.cost;
}
class Solver{
	int n;
	deque<Edge> edge_list;
	Set s;
	int get_cost(const Edge &e){
		if(s.equal(e.start , e.end)){
			if(debug)cout<<"Rejecting "<<e<<endl;
			return -1;
		}
		s.join(e.start , e.end);
		
		if(debug)cout<<"Adding "<<e<<endl;
		return e.cost;
	}
public:
	Solver(int num):
	n(num),
	s(Set(num)){
		int n_neig , neig , cost;
		char name[11];
		
		for(int i=0;i<n;++i){
			scanf("%s",name);
			scanf("%d",&n_neig);
			
			for(int j=0;j<n_neig;++j){
				scanf("%d %d",&neig , &cost);
				edge_list.push_back(Edge(i , neig-1 , cost));
			}
		}
		
		sort(edge_list.begin() , edge_list.end() , compare_edge_cost);
	}
	int solve(){
		int count=0 , cost=0 , index=0 , total_cost=0 , nEdges=edge_list.size();
		while(count<n-1 && index<nEdges){
			cost = get_cost(edge_list[index++]);
			
			if(cost!=-1){
				++count;
				total_cost += cost;
			}
		}
		return total_cost;
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int s , n;
	scanf("%d",&s);
	
	while(s--){
		scanf("%d",&n);
		Solver s(n);
		printf("%d\n",s.solve());
	}
	return 0;
}

