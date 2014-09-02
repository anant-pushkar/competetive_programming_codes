/*
Project name : Permutation_Shuffle
Created on : Sun Aug 24 22:00:37 2014
Author : Anant Pushkar
http://www.codechef.com/COOK49/problems/PERMSUFF
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
	vector<int> arr;
	vector<deque<int> > adj_list;
	vector<bool> visited;
	vector<int> bound;
	void preprocess(){
		for(int i=1;i<n;++i){
			adj_list[i].push_back(i-1);
		}
	}
	void collect(){
		queue<int> q ;
		
		int v , size;
		for(int i=0;i<n;++i)if(!visited[i]){
			q.push(i);
			
			while(!q.empty()){
				v = q.front();
				q.pop();
				
				bound[v] = i;
				visited[v] = true;
				
				size = adj_list[v].size();
				for(int i=0;i<size;++i)if(!visited[adj_list[v][i]]){
					q.push(adj_list[v][i]);
				}
			}
		}
	}
public:
	Solver(int a , int b):
	n(a),
	m(b),
	arr(vector<int>(a)),
	adj_list(vector<deque<int> >(a)),
	visited(vector<bool>(n,false)),
	bound(vector<int>(n)){
		for(int i=0;i<n;++i){
			scanf("%d",&arr[i]);
			--arr[i];
		}
		preprocess();
		for(int i=0;i<m;++i){
			scanf("%d %d",&a , &b);
			--a;--b;
			adj_list[a].push_back(b);
		}
		collect();
	}
	const char* solve(){
		if(debug){
			cout<<"Bound : ";
			for(int i=0;i<n;++i){
				cout<<bound[i]<<" ";
			}
			cout<<endl;
		}
		for(int i=0;i<n;++i){
			if(bound[arr[i]] > i){
				return "Impossible";
			}
		}
		return "Possible";
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t , n , m;
	scanf("%d",&t);
	
	while(t--){
		scanf("%d %d",&n,&m);
		Solver s(n,m);
		printf("%s\n" , s.solve());
	}
	
	return 0;
}

