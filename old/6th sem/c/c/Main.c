/*
Project name : c
Created on : Sun Jan 12 20:36:22 2014
Author : Anant Pushkar
sbvjd
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
