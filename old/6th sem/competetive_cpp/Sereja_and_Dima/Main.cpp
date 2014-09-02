/*
Project name : Sereja_and_Dima
Created on : Thu Jan 30 12:53:31 2014
Author : Anant Pushkar
codeforces 381 A
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<deque>
#include<vector>
using namespace std;
bool debug=false;
typedef long long int lld;
vector<int> arr;
vector< vector<int> > lookup;
int getMax(int start , int end){
	if(lookup[start][end]!=-1)return lookup[start][end];
	if(start>=end)return 0;
	if(arr[start]>arr[end-1]){
		return arr[start] + (arr[end-1]>arr[start+1]?getMax(start+1,end-1):getMax(start+2,end));
	}
	return arr[end-1] + (end-1>start? arr[end-2]>arr[start]?getMax(start,end-2) : getMax(start+1,end-1) : 0 );
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n;scanf("%d",&n);
	arr=vector<int>(n);
	int sum=0;
	for(int i=0;i<n;++i){
		scanf("%d",&arr[i]);
		sum+=arr[i];
	}
	lookup=vector< vector<int> >(n+1,vector<int>(n+1,-1));
	printf("%d %d\n",getMax(0,n),sum-getMax(0,n));
	
	return 0;
}

