/*
Project name : Mice_and_Maze
Created on : Fri Aug  1 18:46:07 2014
Author : Anant Pushkar
http://www.spoj.com/problems/MICEMAZE/
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
struct compare_vertex{
	bool operator()(const pair<int,int> &p1 , const pair<int,int> p2){
		return p1.second<p2.second;
	}
};
typedef priority_queue<pair<int,int> , vector<pair<int,int> > , compare_vertex> node_pq;
class Solver{
	int n , e , t , m;
	vector<deque<pair<int,int> > > adjList;
	vector<int> min_dist;
	node_pq pq;
	void push_node(int index , int dist){
		if(min_dist[index] < dist){
			return;
		}
		pq.push(make_pair(index , dist));
		min_dist[index] = dist;
	}
public:
	Solver(){
		scanf("%d",&n);
		adjList = vector<deque<pair<int,int> > >(n);
		min_dist= vector<int>(n , INT_MAX);
		
		scanf("%d",&e);
		--e;
		scanf("%d",&t);
		scanf("%d",&m);
		
		int x , y , z;
		for(int i=0;i<m;++i){
			scanf("%d %d %d",&x , &y , &z);
			--x;--y;
			adjList[y].push_back(make_pair(x , z));
		}
	}
	int solve(){
		push_node(e , 0);
		
		int size;
		pair<int,int> vertex;
		while(!pq.empty()){
			vertex = pq.top();
			pq.pop();
			
			size = adjList[vertex.first].size();
			for(int i=0;i<size;++i){
				push_node(adjList[vertex.first][i].first , vertex.second + adjList[vertex.first][i].second);
			}
		}
		
		int count = 0;
		for(int i=0;i<n;++i){
			count += min_dist[i]<=t ? 1 : 0;
		}
		
		return count;
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	Solver s;
	printf("%d\n",s.solve());
	return 0;
}

