/*
Project name : The_Child_and_Toy
Created on : Tue Jul  1 16:23:26 2014
Author : Anant Pushkar
http://codeforces.com/contest/437/problem/C
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
#include<list>
using namespace std;
bool debug=false;
typedef long long int lld;
typedef unsigned long long int llu;
struct Node{
	int index,val;
	
	Node():
	index(-1),
	val(0){}
};
bool compare(const Node* ptr1 , const Node* ptr2){
	return ptr1->val > ptr2->val;
}
class Solver{
	int n,m;
	vector<int> cost;
	vector<Node> size;
	vector<vector<int> > adjList;
	vector<Node*> sizeList;
public:
	Solver(int nNodes , int nEdges):
	n(nNodes),
	m(nEdges),
	cost(vector<int>(nNodes)),
	size(vector<Node>(nNodes)),
	sizeList(vector<Node*>(nNodes)),
	adjList(vector<vector<int> >(nNodes,vector<int>(nNodes,0))){
		for(int i=0;i<n;++i){
			scanf("%d",&cost[i]);
			sizeList[i] = &size[i];
			size[i].index = i;
		}
		int a,b;
		for(int i=0;i<m;++i){
			scanf("%d %d",&a,&b);
			--a;--b;
			
			adjList[a][b] = 1;
			size[a].val += cost[b];
			
			adjList[b][a] = 1;
			size[b].val += cost[a];;
		}
		if(debug){
			cout<<"cost : ";
			for(int i=0;i<n;++i){
				cout<<cost[i]<<" ";
			}
			cout<<endl;
		}
	}
	int solve(){
		int sum=0 , node;
		if(debug){
			cout<<"size : ";
			for(int i=0;i<n;++i){
				cout<<size[i].val<<" ";
			}
			cout<<endl;
		}
		for(int i=0;i<n;++i){
			make_heap(sizeList.begin()+i,sizeList.end(),compare);
			node = sizeList[i]->index;
			sum += size[node].val;
			if(debug)cout<<"Removing "<<node<<" sum:"<<sum<<endl;
			for(int j=0;j<n;++j)if(adjList[j][node]==1){
				adjList[j][node] = 0;
				adjList[node][j] = 0;
				size[j].val -= cost[node];
				size[node].val = INT_MIN;
			}
			if(debug){
				cout<<"size : ";
				for(int i=0;i<n;++i){
					cout<<size[i].val<<" ";
				}
				cout<<endl;
			}
		}
		return sum;
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n,m;
	scanf("%d %d",&n,&m);
	Solver s(n,m);
	printf("%d\n",s.solve());
	return 0;
}

