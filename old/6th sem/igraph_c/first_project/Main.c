/*
Project name : first_project
Created on : Wed Feb 26 14:03:57 2014
Author : Shashank Rajput
test project
*/
#include <igraph.h>
#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "slpa.h"
int main(void)
{
	create_graph();
	//create_from_file();
	//print_graph(&g);
	iterate(50,1,0.25,0.2,5);
	
	return 0;
}

