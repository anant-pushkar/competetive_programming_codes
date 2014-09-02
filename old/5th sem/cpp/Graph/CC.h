#pragma once
#include<vector>
#include "Graph.h"
class CC{
	std::vector<int> CSet;
	std::vector<int> checkList;
	void dfs(Graph g, int v);
public:
	std::vector<std::vector<int> > set;
	CC(Graph g);
};