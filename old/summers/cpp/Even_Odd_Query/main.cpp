/*
Project name : Even_Odd_Query
Created on : Tue Jun 17 19:31:05 2014
Author : Anant Pushkar
https://www.hackerrank.com/contests/w5/challenges/even-odd-query
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
char* getResponse(const vector<int> &arr , int x , int y){
	if(x>y){
		return "Odd";
	}
	if(arr[x-1]==0){
		return "Even";
	}
	if(arr[x]==0){
		return "Odd";
	}
	if(arr[x-1]%2==0){
		return "Even";
	}else{
		return "Odd";
	}
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n;
	scanf("%d",&n);
	vector<int> arr(n);
	for(int i=0;i<n;++i){
		scanf("%d",&arr[i]);
	}
	int q;
	scanf("%d",&q);
	
	int x,y;
	while(q--){
		scanf("%d %d",&x,&y);
		printf("%s\n",getResponse(arr,x,y));
	}
	return 0;
}

