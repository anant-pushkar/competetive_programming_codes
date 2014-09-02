/*
Project name : population_count
Created on : Tue Dec 24 19:54:29 2013
Author : Anant Pushkar
Test project to test algorithm to count number of set bits in an integer
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
bool debug=false;
int pop(unsigned x) {
	x = x - ((x >> 1) & 0x55555555);
	x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
	x = (x + (x >> 4)) & 0x0F0F0F0F;
	x = x + (x >> 8);
	x = x + (x >> 16);
	return x & 0x0000003F;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	unsigned t,n;scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		printf("%d\n",pop(n));
	}
	return 0;
}

