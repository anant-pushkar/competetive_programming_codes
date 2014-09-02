/*
Project name : Football_Kit
Created on : Sun May 18 09:50:37 2014
Author : Anant Pushkar
http://codeforces.com/contest/432/problem/B
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
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n;scanf("%d",&n);
	int x[n] , y[n] ;
	vector<int> count(100001,0);
	for(int i=0;i<n;++i){
		scanf("%d %d",&x[i],&y[i]);
		++count[x[i]];
	}
	int a,b,c;
	for(int i=0;i<n;++i){
		a = b = n-1; 
		c = count[y[i]];
		a += c;
		b -= c;
		printf("%d %d\n",a,b);
	}
	return 0;
}

