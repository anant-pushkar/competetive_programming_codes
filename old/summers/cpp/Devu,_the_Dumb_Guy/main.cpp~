/*
Project name : Devu,_the_Dumb_Guy
Created on : Mon Jun 30 15:40:16 2014
Author : Anant Pushkar
http://codeforces.com/contest/439/problem/B
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
	int n , x;
	scanf("%d %d",&n,&x);
	
	vector<int> c(n);
	for(int i=0;i<n;++i){
		scanf("%d",&c[i]);
	}
	sort(c.begin(),c.end());
	
	lld val=x , sum=0;
	for(int i=0;i<n;++i){
		sum += val*c[i];
		if(val!=1)--val;
	}
	printf("%lld\n",sum);
	
	return 0;
}

