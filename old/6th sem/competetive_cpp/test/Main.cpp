/*
Project name : test
Created on : Tue Jan 14 21:49:02 2014
Author : Anant Pushkar
dbgbfn
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
	
	return 0;
}

