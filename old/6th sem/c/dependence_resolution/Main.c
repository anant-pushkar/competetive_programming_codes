/*
Project name : dependence_resolution
Created on : Tue Dec 17 21:56:59 2013
test project to test dependence resolution
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"d1.h"
#include"d3.h"
int debug=0;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int t,n;scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		switch(n){
		case 1:
			callD1();
			break;
		case 2:
			callD3();
			break;
		}
	}
	return 0;
}
