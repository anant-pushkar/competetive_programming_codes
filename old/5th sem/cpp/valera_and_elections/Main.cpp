/*
Project name : valera_and_elections
Created on : Fri Dec 13 15:45:39 IST 2013
http://codeforces.com/contest/369/problem/C

*/

#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<deque>
#include<queue>
using namespace std;
bool debug=false;
class Graph{
	int nVertices;
	vector<deque<int> > adjList;
	vector<bool> lookup;
	queue<int> q;
	int countProblem(int v,int parent){
		if(debug)cout<<"Countung at "<<v<<","<<parent<<endl;
		int sum=0;
		for(int i=0;i<adjList[v].size();++i)if(adjList[v][i]!=parent){
			sum+=countProblem(adjList[v][i],v);
		}
		sum+=lookup[v]?1:0;
		if(sum==1)q.push(v);
		return sum;
	}
public:
	Graph(int n):
	nVertices(n),
	adjList(vector<deque<int> >(n)),
	lookup(vector<bool>(n,false)){
		int s,e,w;
		while(--n){
			cin>>s>>e>>w;
			--s;--e;
			adjList[s].push_back(e);
			adjList[e].push_back(s);
			if(w==2){
				lookup[s]=true;
				lookup[e]=true;
			}
		}
	}
	int solve(){
		countProblem(0,-1);
		return q.size();
	}
	void printQ(){
		while(!q.empty()){
			cout<<q.front()+1<<" ";
			q.pop();
		}
		cout<<endl;
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n;cin>>n;
	Graph g(n);
	cout<<g.solve()<<endl;
	g.printQ();
	return 0;
}

