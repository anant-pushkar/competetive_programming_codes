/*
Project name : Boredom
Created on : Fri Aug  8 21:04:55 2014
Author : Anant Pushkar
http://codeforces.com/contest/455/problem/0
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
const int size = 100001;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n , x , max=INT_MIN;
	scanf("%d",&n);
	
	vector<lld> count(size , 0);
	for(int i=0;i<n;++i){
		scanf("%d",&x);
		++count[x];
		max = max<x ? x : max;
	}
	
	count[0] = 0;
	count[2] = count[2]*2;
	for(int i=3;i<=max;++i){
		count[i] = (count[i-2]>count[i-3] ? count[i-2] : count[i-3]) + count[i]*i;
	}
	
	printf("%lld\n",count[max]>count[max-1] ? count[max] : count[max-1]);
	
	return 0;
}

