/*
Project name : Andrey_and_Problem
Created on : Sat Jun 21 20:14:20 2014
Author : Anant Pushkar
http://codeforces.com/contest/442/problem/B
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
using namespace std;
bool debug=false;
typedef long long int lld;
typedef unsigned long long int llu;
void print( const vector<double> &v){
	int size=v.size();
	for(int i=0;i<size;++i){
		cout<<v[i]<<" ";
	}
	cout<<endl;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n;
	scanf("%d",&n);
	vector<double> p(n);
	for(int i=0;i<n;++i){
		scanf("%lf",&p[i]);
	}
	if(debug)print(p);
	vector<double> lookup(n);
	lookup[0] = p[0];
	double p1,p2;
	for(int i=1;i<n;++i){
		if(debug)print(lookup);
		p1 = (1-lookup[i-1])*p[i] + lookup[i-1]*(1-p[i]);
		p2 = p[i];
		lookup[i] = p1>p2 ? p1 : p2;
	}
	if(debug)print(lookup);
	double max=0;
	for(int i=0;i<n;++i){
		max = max<lookup[i] ? lookup[i] : max;
	}
	printf("%0.12lf\n",max);
	return 0;
}

