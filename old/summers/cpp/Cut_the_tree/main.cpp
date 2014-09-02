/*
Project name : Cut_the_tree
Created on : Sat May 17 16:58:56 2014
Author : Anant Pushkar
https://www.hackerrank.com/contests/w2/challenges/cut-the-tree
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
class Tree{
	int n;
	vector<int> val;
	vector<deque<pair<int,int > > > adjList;
	vector<pair<int,int> > bal ;
	int populateFirst(int parent , int node){
		int sum=val[node] , tval;
		for(int i=0;i<adjList[node].size();++i)if(adjList[node][i].first!=parent){
			tval = populateFirst(node,adjList[node][i].first);
			bal[adjList[node][i].second].first = tval;
			sum += tval;
		}
		return sum;
	}
	void populateSecond(int parent , int node , int tval){
		int sum=0;
		for(int i=0;i<adjList[node].size();++i)if(adjList[node][i].first!=parent) sum+= bal[adjList[node][i].second].first;
		for(int i=0;i<adjList[node].size();++i)if(adjList[node][i].first!=parent){
			bal[adjList[node][i].second].second = sum - bal[adjList[node][i].second].first + tval + val[node];
			populateSecond(node,adjList[node][i].first,bal[adjList[node][i].second].second);
		}
	}
public:
	Tree(int num):
		n(num),
		val(vector<int>(num,0)),
		adjList(vector<deque<pair<int,int > > >(num)),
		bal(vector<pair<int,int> >(num-1,make_pair(-1,-1))){
		for(int i=0;i<n;++i)scanf("%d",&val[i]);
		int a,b;
		for(int i=0;i<n-1;++i){
			scanf("%d %d",&a,&b);
			--a;--b;
			adjList[a].push_back(make_pair(b,i));
			adjList[b].push_back(make_pair(a,i));
		}
	}
	int getMinDiff(){
		populateFirst(-1,0);
		populateSecond(-1,0,0);
		int min = INT_MAX , b;
		for(int i=0;i<n-1;++i){
			b = abs(bal[i].first - bal[i].second);
			min = min>b ? b : min;
		}
		return min;
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n;
	scanf("%d",&n);
	Tree t(n);
	printf("%d\n",t.getMinDiff());
	return 0;
}

