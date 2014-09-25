/*
Project name : George_and_Job
Created on : Thu Sep 25 22:19:32 2014
Author : Anant Pushkar
http://codeforces.com/contest/467/problem/C
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
int n , m , k;
vector<int> val;
vector<lld> s;
inline lld get_max(lld a , lld b){
	return a>b ? a : b;
}
lld get_max(vector<lld> &lookup , vector<lld> &arr , int l){
	if(debug){
		cout<<l<<" : ";
		for(int i=0;i<n;++i){
			cout<<lookup[i]<<" ";
		}
		cout<<endl;
	}
	if(l==k){
		lld max = INT_MIN;
		for(int i=0;i<n;++i){
			max = max<lookup[i] ? lookup[i] : max;
		}
		return max;
	}
	lld v1 , v2;
	arr[0] = lookup[0];
	for(int i=1;i<n;++i){
		v1 = arr[i-1];
		v2 = i-m>-1 ? lookup[i-m]+s[i]-s[i-m] : 0;
		arr[i] = get_max(v1 , v2);
	}
	
	return get_max(arr , lookup , l+1);
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	
	scanf("%d %d %d",&n,&m,&k);
	
	val = vector<int>(n);
	s   = vector<lld>(n,0);
	for(int i=0;i<n;++i){
		scanf("%d",&val[i]);
		s[i] = val[i] + (i>0 ? s[i-1] : 0);
	}
	
	vector<lld> lookup(n,0) , arr(n);
	lld sum=0;
	for(int i=0;i<m-1;++i){
		sum += val[i];
	}
	for(int i=m-1;i<n;++i){
		sum += val[i];
		lookup[i] = get_max(sum , i>0?lookup[i-1]:0);
		sum -= val[i-m+1];
	}
	
	printf("%lld\n",get_max(lookup , arr , 1));
	
	return 0;
}

