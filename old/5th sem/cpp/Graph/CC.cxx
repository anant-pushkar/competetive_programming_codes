#include "CC.h"
void CC::dfs(Graph g, int v)
{
	this->checkList[v]=1;
	CSet.push_back(v);
	std::vector<int> adj=g.adjList(v);
	for(int i=0;i<adj.size();i++){
		if(this->checkList[adj[i]]==0)
			this->dfs(g,adj[i]);
	}
}
CC::CC(Graph g):
checkList(std::vector<int>(g.nVertices(),0))
{
	for(int i=0;i<g.nVertices();i++){
		if(checkList[i]==0){
			CSet.clear();
			dfs(g,i);
			set.push_back(CSet);
		}
	}
}
