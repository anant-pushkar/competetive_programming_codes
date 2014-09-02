/*
Project name : data_plot_test
Created on : Wed Jan 15 08:23:20 2014
Author : Anant Pushkar
test project to test data plot filter
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int debug=0;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int n;
	scanf("%d",&n);
	printf("%d\n",n+1);
	printf("^{\"type\":\"data\",\"obj\":[1,2,2,3,3,4,5,6,6,7]}");
	return 0;
}
