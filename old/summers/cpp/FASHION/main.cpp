/*
Project name : FASHION
Created on : Thu May 15 15:56:23 2014
Author : Anant Pushkar
http://www.spoj.com/problems/FASHION
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
#define NUM 1001

using namespace std;
typedef long long int lld;
typedef unsigned long long int llu;
bool debug=false;
int n , arr1[NUM] , arr2[NUM];
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int t,i,sum;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=0;i<n;++i) scanf("%d",&arr1[i]);
		for(i=0;i<n;++i) scanf("%d",&arr2[i]);
		
		sort(arr1,arr1+n);
		sort(arr2,arr2+n);
		
		sum=0;
		for(i=0;i<n;++i) sum += arr1[i]*arr2[i] ;
		printf("%d\n",sum);
	}
	return 0;
}

