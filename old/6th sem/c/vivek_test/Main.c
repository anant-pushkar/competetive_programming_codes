/*
Project name : vivek_test
Created on : Tue Jan 28 20:58:45 2014
Author : Anant Pushkar
ldcbdc
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int debug=0;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int i=0,j;
	for(i=0;i<=3;++i)for(j=3-i;j<3+i;++j)printf("i=%d j=%d\n",i,j);
	return 0;
}
