/*
Project name : Minimum_Scalar_Product
Created on : Tue Oct 14 18:31:36 2014
Author : Anant Pushkar
https://code.google.com/codejam/contest/32016/dashboard#s=p0
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
	int T;
	scanf("%d",&T);
	
	int n;
	lld sum;
	for(int t=1;t<=T;++t){
		scanf("%d",&n);
		vector<int> a(n) , b(n);
		for(int i=0;i<n;++i){
			scanf("%d",&a[i]);
		}
		for(int i=0;i<n;++i){
			scanf("%d",&b[i]);
		}
		sort(a.begin() , a.end());
		sort(b.begin() , b.end() , greater<int>());
		
		sum=0;
		for(int i=0;i<n;++i){
			sum += static_cast<lld>(a[i])*b[i];
		}
		
		printf("Case #%d: %lld\n" , t , sum);
	}
	
	return 0;
}

