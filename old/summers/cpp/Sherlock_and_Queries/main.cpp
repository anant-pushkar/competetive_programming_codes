/*
Project name : Sherlock_and_Queries
Created on : Tue Jul  1 10:50:48 2014
Author : Anant Pushkar
https://www.hackerrank.com/contests/101jun14/challenges/sherlock-and-queries
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
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n,m;
	scanf("%d %d",&n,&m);
	
	vector<lld> a(n);
	for(int i=0;i<n;++i){
		scanf("%lld",&a[i]);
	}
	
	vector<int> b(m);
	for(int i=0;i<m;++i){
		scanf("%d",&b[i]);
	}
	
	vector<int> c(m);
	for(int i=0;i<m;++i){
		scanf("%d",&c[i]);
	}
	
	vector<lld> multiplier(n);
	
	
	return 0;
}

