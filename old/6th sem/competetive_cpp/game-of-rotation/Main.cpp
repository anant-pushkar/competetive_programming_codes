/*
Project name : game-of-rotation
Created on : Sat May  3 14:00:33 2014
Author : Anant Pushkar
Hackerrank April Challenge
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
using namespace std;
bool debug=false;
typedef long long int lld;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n;scanf("%d",&n);
	vector<lld> arr(n);
	lld sum=0 , val=0 , max=LLONG_MIN;
	for(int i=0;i<n;++i){
		scanf("%lld",&arr[i]);
		sum += arr[i];
		val += arr[i]*(i+1);
	}
	
	for(int i=0;i<n;++i){
		val = val - sum + n*arr[i] ;
		if(val>max)max=val;
	}
	
	printf("%lld\n",max	);
	
	return 0;
}

