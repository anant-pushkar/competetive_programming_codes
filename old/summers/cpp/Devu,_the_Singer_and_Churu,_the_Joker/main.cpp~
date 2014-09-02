/*
Project name : Devu,_the_Singer_and_Churu,_the_Joker
Created on : Mon Jun 30 15:33:36 2014
Author : Anant Pushkar
http://codeforces.com/contest/439/problem/A
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
	int n,d;
	scanf("%d %d",&n,&d);
	
	int sum=(n-1)*10 , t;
	for(int i=0;i<n;++i){
		scanf("%d",&t);
		sum += t;
	}
	
	if(sum>d){
		printf("-1\n");
	}else{
		printf("%d\n",2*(n-1)+(d-sum)/5);
		
	}
	return 0;
}

