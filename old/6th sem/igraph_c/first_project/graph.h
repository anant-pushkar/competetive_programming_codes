#pragma once
#include <igraph.h>
#include <stdlib.h>
int nVertices , nEdges;
igraph_t g;
igraph_spmatrix_t adjMat;
void create_graph();
void print_graph(igraph_t*);
void print_vector(igraph_vector_t *v, FILE *f) ;
void create_from_file();
