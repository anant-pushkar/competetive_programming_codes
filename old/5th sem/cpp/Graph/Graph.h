#pragma once
#include<vector>
class Graph{
	int E;								 //number of Edges
	int V; 								 //number of vertices
	std::vector< std::vector<int> > adj; //vector contaoning edjecendy lists
public:
	Graph(int v);
	int nVertices();
	int nEdges();
	void addEdge(int v , int w);
	std::vector<int> adjList(int v);
};