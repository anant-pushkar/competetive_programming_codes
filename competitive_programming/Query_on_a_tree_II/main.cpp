/*
Project name : Query_on_a_tree_II
Created on : Sun Aug  3 09:47:53 2014
Author : Anant Pushkar
http://www.spoj.com/problems/QTREE2/
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
#include<cmath>
using namespace std;
bool debug=false;
typedef long long int lld;
typedef unsigned long long int llu;
inline void exchange(int &a , int &b){
	++a;++b;
	a = a^b;
	b = a^b;
	a = a^b;
	--a;--b;
}
class Solver{
	int n , n_level;
	vector<deque<pair<int,int> > > adjList;
	vector<int>  dist_to , level;
	deque<vector<int> > parent;
	bool level_check;
	void dfs(int v , int p , int dist , int count , int l){
		int size = adjList[v].size();
		dist_to[v]  = dist;
		parent[0][v]= p;
		level[v]    = level[p]+1;
		if(count==0){
			++l;
			count = (1<<l);
		}
		level_check = level_check && p==0;
		for(int i=0;i<size;++i)if(adjList[v][i].first!=p){
			dfs(adjList[v][i].first , v , dist+adjList[v][i].second , count-1 , l);
		}
	}
	void populate_parent(){
		while(!level_check){
			parent.push_back(vector<int>(n,-1));
			++n_level;
			
			level_check = true;
			for(int i=0;i<n;++i){
				parent[n_level][i] = parent[n_level-1][ parent[n_level-1][i] ];
				level_check = level_check && parent[n_level][i]==0;
			}
		}
	}
	void print_parent_list(){
		for(int i=0;i<=n_level;++i){
			for(int j=0;j<n;++j){
				printf("%02d ",parent[i][j]);
			}
			cout<<endl;
		}
	}
	void print_vector(const vector<int> &v){
		int size = v.size();
		for(int i=0;i<size;++i){
			cout<<v[i]<<" ";
		}
		cout<<endl;
	}
	
	int get_lca(int v1 , int v2){
		if(level[v1]<level[v2]){
			exchange(v1,v2);
		}
		
		int l=n_level;
		while(level[v1]>level[v2]){
			while(l>0 && level[parent[l][v1]]<level[v2]){
				--l;
			}
			v1 = parent[l][v1];
		}
		
		l=n_level;
		while(v1!=v2){
			while(l>0 && parent[l][v1] == parent[l][v2]){
				--l;
			}
			v1 = parent[l][v1];
			v2 = parent[l][v2];
		}
		if(debug)cout<<"LCA : "<<v1<<endl;
		return v1;
	}
	
	int get_dist(int a , int b){
		int lca = get_lca(a , b);
		return dist_to[a] + dist_to[b] - 2*dist_to[lca];
	}
	int get_kth(int a , int b , int k){
		int lca = get_lca(a , b) , level_diff = abs(level[a]-level[lca]);
		
		if(k-1>level_diff){
			return get_kth(b , lca , level[b]-level[lca] - k+level_diff+2);
		}
		
		int l=n_level;
		while(k>1){
			while(l>0 && k-1<level[a]-level[parent[l][a]]){
				--l;
			}
			k -= level[a]-level[parent[l][a]];
			a  = parent[l][a];
		}
		return a+1;
	}
public:
	Solver(int num):
	n(num),
	adjList(vector<deque<pair<int,int> > >(num)),
	parent(deque<vector<int> >(1 , vector<int>(num , -1))),
	dist_to(vector<int>(num , -1)),
	level(vector<int>(num , 0)),
	level_check(true),
	n_level(0){
		int a , b , c;
		for(int i=0;i<n-1;++i){
			scanf("%d %d %d",&a , &b , &c);
			--a;--b;
			adjList[a].push_back(make_pair(b,c));
			adjList[b].push_back(make_pair(a,c));
		}
		dfs(0 , 0 , 0 , 0 , 0);
		populate_parent();
		if(debug){
			cout<<"Parent : "<<endl;
			print_parent_list();
			
			cout<<"level : "<<endl;
			print_vector(level);
			
			cout<<"dist_to : "<<endl;
			print_vector(dist_to);
		}
	}
	void solve_queries(){
		string q;
		int a , b , k;
		while(true){
			cin>>q;
			if(q=="DONE"){
				break;
			}
			if(q=="DIST"){
				scanf("%d %d",&a,&b);
				printf("%d\n",get_dist(a-1,b-1));
			}else if(q=="KTH"){
				scanf("%d %d %d",&a,&b,&k);
				printf("%d\n" , get_kth(a-1,b-1,k));
			}else if(q=="LCA"){
				scanf("%d %d",&a,&b);
				printf("%d\n",get_lca(a-1,b-1)+1);
			}
		}
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
		s.solve_queries();
	}
	
	return 0;
}

