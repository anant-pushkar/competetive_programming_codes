/*
Project name : first_igraph
Created on : Mon Feb 10 15:42:37 2014
Author : Anant Pushkar
first test program to test igraph
*/
#include <igraph.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int debug=0;
typedef long long int lld;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	igraph_integer_t diameter;
	igraph_t graph;
	igraph_erdos_renyi_game(&graph, IGRAPH_ERDOS_RENYI_GNP, 1000, 5.0/1000,
	IGRAPH_UNDIRECTED, IGRAPH_NO_LOOPS);
	igraph_diameter(&graph, &diameter, 0, 0, 0, IGRAPH_UNDIRECTED, 1);
	printf("Diameter of a random graph with average degree 5: %d\n",
	(int) diameter);
	igraph_destroy(&graph);
	return 0;
}
