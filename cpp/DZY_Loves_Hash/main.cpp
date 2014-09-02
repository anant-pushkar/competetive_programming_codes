/*
Project name : DZY_Loves_Hash
Created on : Fri Jul 18 20:51:55 2014
Author : Anant Pushkar
http://codeforces.com/contest/447/problem/A
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
	int p,n,t;
	scanf("%d %d",&p,&n);
	
	vector<bool> lookup(p,false);
	bool check=true;
	lld x;
	t=1;
	while(n--){
		scanf("%lld",&x);
		if(check && lookup[x%p]){
			printf("%d\n",t);
			check = false;
		}
		lookup[x%p] = true;
		++t;
	}
	if(check){
		printf("-1\n");
	}
	
	return 0;
}