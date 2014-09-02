/*
Project name : Tree_Game
Created on : Sun Aug 24 23:00:12 2014
Author : Anant Pushkar
http://www.codechef.com/COOK49/problems/TREEGAME
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
	int n , max_level;
	vector<deque<int> > adj_list;
	vector<int> level_count;
	void count(){
		queue<int> v , l , p;
		
		v.push(0);
		l.push(0);
		p.push(0);
		
		int node , level , parent , size;
		while(!v.empty()){
			node = v.front();
			v.pop();
			
			level = l.front();
			l.pop();
			
			parent = p.front();
			p.pop();
			
			if(debug)cout<<"Node "<<node<<", level "<<level<<endl;
			
			
			++level_count[level];
			
			size = adj_list[node].size();
			for(int i=0;i<size;++i)if(adj_list[node][i]!=parent){
				v.push(adj_list[node][i]);
				l.push(level+1);
				p.push(node);
			}
			
			max_level = max_level<level ? level : max_level;
		}
	}
public:
	Solver(int x):
	n(x),
	level_count(vector<int>(x , 0)),
	adj_list(vector<deque<int> >(x)),
	max_level(0){
		int a , b;
		for(int i=0;i<n-1;++i){
			scanf("%d %d",&a , &b);
			--a;--b;
			adj_list[a].push_back(b);
			adj_list[b].push_back(a);
		}
		count();
	}
	int solve(){
		int steps=0 , top=-1 , bottom=max_level;
		
		while(top<bottom){
			++top;
			++steps;
			if(debug)cout<<steps<<" # top : "<<top<<endl;
			
			if(top>=bottom){
				break;
			}
			
			--level_count[bottom];
			++steps;
			if(level_count[bottom]==0){
				--bottom;
			}
			if(debug)cout<<steps<<" # bottom : "<<bottom<<endl;
		}
		
		return steps;
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t , n;
	scanf("%d",&t);
	
	while(t--){
		scanf("%d",&n);
		Solver s(n);
		cout<<s.solve()<<endl;
	}
	
	return 0;
}

