/*
Project name : test_project_for_graph_plotting
Created on : Wed Jan 15 01:55:52 2014
Author : Anant Pushkar
test project to test graph plotting filter
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
bool debug=false;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n;
	
	scanf("%d",&n);
	printf("%d\n",n);
	printf("^{\"type\":\"graph\",\"obj\":[[1,2,\"aev1\"],[2,3,\"sfref\"]]}\n");
	scanf("%d",&n);
	printf("%d\n",n+1);
	return 0;
}

