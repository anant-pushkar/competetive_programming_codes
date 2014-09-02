/*
Project name : Utopian_Tree
Created on : Mon Jul 21 18:18:42 2014
Author : Anant Pushkar
https://www.hackerrank.com/challenges/utopian-tree
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
typedef long long int lld;
typedef unsigned long long int llu;
int debug=0;
int lookup[61];
void init(){
	lookup[0]=1;
	int i=0;
	while(i<60){
		lookup[i+1] = 2*lookup[i];
		++i;
		if(i>61){
			break;
		}
		lookup[i+1] = 1 + lookup[i];
		++i;
	}
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int t , n;
	init();
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		printf("%d\n",lookup[n]);
	}
	return 0;
}
