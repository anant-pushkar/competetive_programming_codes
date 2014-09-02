/*
Project name : SHPATH
Created on : Sat Dec  7 18:15:19 IST 2013
http://www.spoj.com/problems/SHPATH/

*/

#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<utility>
#include<map>
#include<set>
#include<climits>
#include<queue>
#include<algorithm>
using namespace std;
bool debug=false;
struct Order{
    bool operator()(pair<int,int> const& a, pair<int,int> const& b) const{
        return a.second > b.second ;
    }
};
class Graph{
	map<string,int> indexOf;
	int nVertices;
	vector<vector<pair<int,int> > > adjList;
	vector<pair<int,int> > target;
public:
	Graph(int num):
	nVertices(num),
	adjList(vector<vector<pair<int,int> > >(num)){
		string name;
		char str[100];
		int n,v,d;
		for(int i=0;i<num;++i){
			scanf("%s",str);name=string(str);
			indexOf[name]=i;
			scanf("%d",&n);
			adjList[i]=vector<pair<int,int> >(n);
			while(n--){
				scanf("%d %d",&v,&d);--v;
				adjList[i][n]=make_pair(v,d);
			}
		}
		scanf("%d",&n);
		target=vector<pair<int,int> >(n);
		for(int i=0;i<n;++i){
			scanf("%s",str);name=string(str);
			v=indexOf[name];
			scanf("%s",str);name=string(str);
			d=indexOf[name];
			target[i]=make_pair(v,d);
		}
	}
	vector<int> solve(){
		vector<int> distTo,soln(target.size());
		queue<int> q;
		int v;
		for(int i=0;i<target.size();++i){
			distTo=vector<int>(nVertices,INT_MAX);
			distTo[target[i].first]=0;
			q.push(target[i].first);
			while(!q.empty()){
				v=q.front();q.pop();
				for(int j=0;j<adjList[v].size();++j)if(distTo[adjList[v][j].first]>distTo[v]+adjList[v][j].second){
					q.push(adjList[v][j].first);
					distTo[adjList[v][j].first]=distTo[v]+adjList[v][j].second;
				}
			}
			soln[i]=distTo[target[i].second];
		}
		return soln;
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t,n;scanf("%d",&t);
	vector<int>soln;
	while(t--){
		scanf("%d",&n);
		Graph g(n);
		soln=g.solve();
		for(int i=0;i<soln.size();++i)printf("%d\n",soln[i]);
	}
	return 0;
}

