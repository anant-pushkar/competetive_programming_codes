/*
Project name : Build_a_Fence
Created on : Sat May 24 17:00:28 2014
Author : Anant Pushkar
http://www.spoj.com/problems/FENCE1/
*/
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
typedef long long int lld;
typedef unsigned long long int llu;
int debug=0;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	double l;
	while(1){
		scanf("%lf",&l);
		if(l==0)break;
		printf("%0.2f\n",(l*l/(2*M_PI)));
	}
	return 0;
}
