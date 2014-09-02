/*
Project name : Jzzhu_and_Children
Created on : Sat Jul 19 18:32:08 2014
Author : Anant Pushkar
http://codeforces.com/contest/450/problem/0
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
inline int nTimes(int a , int m){
	return a/m + (a%m==0 ? 0 : 1) ;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n , m;
	scanf("%d %d",&n,&m);
	
	vector<int> a(n);
	for(int i=0;i<n;++i){
		scanf("%d",&a[i]);
	}
	
	int maxVal = 0 , maxIndex=-1 , val;
	for(int i=0;i<n;++i){
		val = nTimes(a[i],m);
		if(maxVal <= val){
			maxVal  = val;
			maxIndex= i+1;
		}
	}
	
	printf("%d\n",maxIndex);
	
	return 0;
}

