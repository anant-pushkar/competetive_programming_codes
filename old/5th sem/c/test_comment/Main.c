/*
Project name : test_comment
Created on : Fri Dec  6 15:37:22 IST 2013
This is a test project to test comment system

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int debug=0;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	
	return 0;
}
