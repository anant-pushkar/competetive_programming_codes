/*
Project name : Hargups_Dilemma
Created on : Sat Aug  9 21:08:09 2014
Author : Anant Pushkar

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
	int n , q;
	scanf("%d %d",&n,&q);
	
	vector<lld> a(n) ;
	for(int i=0;i<n;++i){
		scanf("%lld",&a[i]);
	}
	sort(a.begin() , a.end());
	
	vector<lld> sum(n,0);
	sum[0] = a[0];
	for(int i=1;i<n;++i){
		sum[i] = sum[i-1] + a[i];
		sum[i] = sum[i]%1000000007;
	}
	
	int p;
	for(int i=0;i<q;++i){
		scanf("%d",&p);
		printf("%lld\n",sum[p-1]);
	}
	
	return 0;
}

