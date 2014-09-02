/*
Project name : Valera_and_Antique_Items
Created on : Sun Jun 29 11:02:10 2014
Author : Anant Pushkar
http://codeforces.com/contest/441/problem/A
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
	int N,v,S,K;
	scanf("%d %d",&N,&v);
	bool isBiddable;
	queue<int> s;
	for(int n=1;n<=N;++n){
		scanf("%d",&K);
		isBiddable = false;
		for(int k=0;k<K;++k){
			scanf("%d",&S);
			if(v>S){
				isBiddable = true;
			}
		}
		if(isBiddable){
			s.push(n);
		}
	}
	printf("%d\n",s.size());
	while(!s.empty()){
		printf("%d ",s.front());
		s.pop();
	}
	printf("\n");
	return 0;
}

