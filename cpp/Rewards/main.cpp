/*
Project name : Rewards
Created on : Thu Jul 17 19:32:04 2014
Author : Anant Pushkar
http://codeforces.com/contest/448/problem/0
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
	int a,b,n,aCount=0 , bCount=0;
	
	for(int i=0;i<3;++i){
		scanf("%d",&a);
		aCount += a;
	}
	
	for(int i=0;i<3;++i){
		scanf("%d",&b);
		bCount += b;
	}
	
	scanf("%d",&n);
	
	n -= bCount/10 + (bCount%10==0 ? 0 : 1) ;
	n -= aCount/5 + (aCount%5==0 ? 0 : 1) ;
	
	if(n<0){
		printf("NO\n");
	}else{
		printf("YES\n");
	}
	
	return 0;
}

