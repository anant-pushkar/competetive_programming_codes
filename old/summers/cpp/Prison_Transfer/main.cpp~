/*
Project name : Prison_Transfer
Created on : Sat May 10 14:40:44 2014
Author : Anant Pushkar
http://codeforces.com/contest/427/problem/B
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
#define EXPANSION 0
#define PROPOGATION 1
using namespace std;
bool debug=false;
typedef long long int lld;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n , t , c;
	scanf("%d %d %d",&n,&t,&c);
	int arr[n];
	for(int i=0;i<n;++i)scanf("%d",&arr[i]);
	
	int state=EXPANSION , count=0 , index=0 , s=0;
	while(index<n){
		if(arr[index]>t){
			while(index<n && arr[index]>t)++index;
			s=index;
			state=EXPANSION;
			continue;
		}else if(state==EXPANSION){
			if(index-s==c-1){
				state=PROPOGATION;
				++count;
			}
		}
		else if(state==PROPOGATION) ++count;
		++index;
	}
	printf("%d\n",count);
	return 0;
}

