/*
Project name : test_comment
Created on : Fri Dec  6 15:37:54 IST 2013
This is a test project to test comment system

*/

#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
bool debug=false;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	return 0;
}

