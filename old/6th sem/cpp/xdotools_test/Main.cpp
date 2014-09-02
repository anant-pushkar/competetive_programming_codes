/*
Project name : xdotools_test
Created on : Sat Mar  1 18:26:10 2014
Author : Anant Pushkar
dummy project to test xdotools functionality
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
using namespace std;
bool debug=false;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	
	return 0;
}

