/*
Project name : Hungarian_Algo
Module name  : {module}
Created on : Wed Sep 10 14:43:01 2014
Author : Anant Pushkar
Implementation of Hungarian ALgorithm for maximum weighted bipartite matchinf
*/
#include "module.h"
using namespace std;
bool debug;

BinaryBipartiteGraph::BinaryBipartiteGraph(int n_vertices):
n(n_vertices),
adj_mat(vector<vector<bool> >(n , vector<bool>(n , false))){
	
}

BinaryBipartiteGraph::BinaryBipartiteGraph(WeightedBipartiteGraph &wbg):
n(wbg.get_n_vertices()),
adj_mat(vector<vector<bool> >(wbg.get_n_vertices() , vector<bool>(wbg.get_n_vertices() , false))){
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			adj_mat[i][j] = wbg.get_edge_weight(i,j)==0;
		}
	}
}

WeightedBipartiteGraph::WeightedBipartiteGraph(int n_vertices):
n(n_vertices){
	
}

int WeightedBipartiteGraph::get_edge_weight(int x , int y){
	return adj_mat[x][y];
}

int WeightedBipartiteGraph::get_n_vertices(){
	return n;
}
