/*
Project name : Pashmak_and_Flowers
Created on : Sat Aug 23 21:23:54 2014
Author : Anant Pushkar
http://codeforces.com/contest/459/problem/B
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
	lld n;
	scanf("%lld",&n);
	
	vector<int> arr(n);
	for(int i=0;i<n;++i){
		scanf("%d",&arr[i]);
	}
	sort(arr.begin() , arr.end());
	
	lld small=1 , large=1 ;
	int diff=arr[n-1] - arr[0] , index=0;
	while(index<n && arr[index]==arr[index+1]){
		++small;
		++index;
	}
	
	index = n-1;
	while(index>-1 && arr[index]==arr[index-1]){
		++large;
		--index;
	}
	
	printf("%d %lld\n",diff , small+large<=n ? small*large : n*(n-1)/2 );
	
	return 0;
}

