#pragma once
#include<vector>
#include "Graph.h"
class Hamiltonian{
	int count;
	std::vector<int> checkList;
	void dfs(Graph g, int v,int s);
public:
	std::vector<int> cycle;
	Hamiltonian(Graph g);
	int cycleSize();
};