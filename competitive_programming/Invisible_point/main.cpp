/*
Project name : Invisible_point
Created on : Sun Sep  7 13:26:15 2014
Author : Anant Pushkar
http://www.spoj.com/problems/ADV04J/
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
int max_pow(int n){
	int p=0 , m=n;
	while(m>0){
		++p;
		m = m>>1 ;
	}
	return p - ((n&(n-1))==0 ? 1 : 0);
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t;
	scanf("%d",&t);
	
	int n;
	while(t--){
		scanf("%d",&n);
		printf("%d\n",max_pow(n)+1);
	}
	
	return 0;
}

