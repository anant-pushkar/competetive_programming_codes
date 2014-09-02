/*
Project name : Beehive_Numbers
Created on : Sun May 25 10:06:24 2014
Author : Anant Pushkar
http://www.spoj.com/problems/BEENUMS/
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
bool debug=false;
typedef long long int lld;
typedef unsigned long long int llu;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	lld n,val;
	long double sq;
	while(true){
		scanf("%lld",&n);
		if(n==-1)break;
		n -= 1;
		if(n%3!=0)goto exit;
		n/=3;
		sq=4*n+1;sq=sqrt(sq);
		if(sq-(int)sq!=0)goto exit;
		n=sq;
		if(n%2!=1)goto exit;
		printf("Y\n");
		continue;
		exit:
			printf("N\n");
			continue;
	}
	return 0;
}

