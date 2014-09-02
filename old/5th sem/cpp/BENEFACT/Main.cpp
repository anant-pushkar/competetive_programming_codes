/*
Project name : BENEFACT
Created on : Sat Dec  7 17:57:09 IST 2013
http://www.spoj.com/problems/BENEFACT/

*/

#include<iostream>
#include<cstring>
#include<cstdio>
#include<utility>
#include<deque>
#include<vector>
using namespace std;
bool debug=false;
class Graph{
	int n;
	vector< deque <pair<int,int> > > adjList;
public:
	Graph(int num):
	n(num),
	adjList(vector< deque<pair<int,int> > >(num)){
		int x,y,d;
		for(int i=0;i<num;++i){
			scanf("%d %d %d",&x,&y,&d);--x;--y;
			adjList[x].push_back(make_pair(y,d));
			adjList[y].push_back(make_pair(x,d));
		}
	}
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
		int t,n;scanf("%d",&t);
		while(t--){
			scanf("%d",&n);
			Graph g(n);
		}
	return 0;
}

