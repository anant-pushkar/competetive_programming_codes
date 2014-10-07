/*
Project name : Hungarian_Algo
Module name  : {module}
Created on : Wed Sep 10 14:43:01 2014
Author : Anant Pushkar
Implementation of Hungarian ALgorithm for maximum weighted bipartite matchinf
*/
#pragma once
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
class WeightedBipartiteGraph;
class BinaryBipartiteGraph{
	std::vector<std::vector<bool> > adj_mat;
	int n , m;
public:
	BinaryBipartiteGraph(int );
	BinaryBipartiteGraph(WeightedBipartiteGraph &wbg);
};
class WeightedBipartiteGraph{
	std::vector<std::vector<int> > adj_mat;
	int n , m;
public:
	WeightedBipartiteGraph(int );
	int get_edge_weight(int , int);
	int get_n_edges();
	int get_n_vertices();
};
