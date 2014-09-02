#include "Graph.h"
Graph::Graph(int v):
V(v),
E(0)
{
	for(int i=0;i<v;i++)
		adj.push_back(std::vector<int>(0));
}
int Graph::nVertices(){return V;}
int Graph::nEdges()   {return E;}
void Graph::addEdge(int v , int w)
{
	adj[v].push_back(w);
	adj[w].push_back(v);
	E++;
}
std::vector<int> Graph::adjList(int v)
{
	return adj[v];
}
