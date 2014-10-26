/*
Project name : Captain_Hammer
Created on : Mon Oct 20 01:30:39 2014
Author : Anant Pushkar
https://code.google.com/codejam/contest/2933486/dashboard#s=p1
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<deque>
#include<queue>
#include<utility>
#include<vector>
#include<climits>
#include<algorithm>
#include<stack>
#include<cmath>
#define _USE_MATH_DEFINES
using namespace std;
bool debug=false;
typedef long long int lld;
typedef unsigned long long int llu;
double calc_theta(double v , double d){
	double theta = asin(d*9.8000000/(v*v));
	return theta/M_PI*90;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int T;
	cin>>T;
	
	double v,d;
	for(int t=1;t<=T;++t){
		cin>>v>>d;
		printf("Case #%d: %0.7lf\n",t,calc_theta(v,d));
	}
	
	return 0;
}

