/*
Project name : Fedor_and_New_Game
Created on : Thu Sep 25 22:10:20 2014
Author : Anant Pushkar
http://codeforces.com/contest/467/problem/B
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
int get_dist(int a , int b , int n){
	int c = a^b , count = 0;
	for(int i=0;i<n;++i){
		count += (c&1);
		c = c>>1;
	}
	return count;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n , m , k;
	scanf("%d %d %d",&n,&m,&k);
	
	vector<int> mask(m);
	for(int i=0;i<m;++i){
		scanf("%d",&mask[i]);
	}
	
	int fedor;
	scanf("%d",&fedor);
	
	int count = 0;
	for(int i=0;i<m;++i){
		count += get_dist(fedor , mask[i] , n)<=k ? 1 : 0;
	}
	printf("%d\n",count);
	
	return 0;
}

