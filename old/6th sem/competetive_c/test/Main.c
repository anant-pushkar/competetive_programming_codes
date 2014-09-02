/*
Project name : test
Created on : Fri Jan 17 19:08:33 2014
Author : Anant Pushkar
test project to test decription in project.json
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
