/*
Project name : Princess_Farida
Created on : Fri Aug  1 14:05:21 2014
Author : Anant Pushkar
http://www.spoj.com/problems/FARIDA/
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
inline lld get_max(lld a , lld b){
	return a>b ? a : b;
}
class Solver{
	int n;
	vector<int> arr;
public:
	Solver(int num):
	n(num),
	arr(vector<int>(num)){
		for(int i=0;i<n;++i){
			scanf("%d",&arr[i]);
		}
	}
	lld solve(){
		if(n==0){
			return 0;
		}
		if(n==1){
			return arr[0];
		}
		if(n==2){
			return get_max(arr[0] , arr[1]);
		}
		lld a=arr[0] , b=get_max(arr[0] , arr[1]) , temp;
		for(int i=2;i<n;++i){
			temp = get_max(a+arr[i] , b);
			a = b;
			b = temp;
		}
		return b;
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int  T , n;
	scanf("%d",&T);
	
	for(int t=1;t<=T;++t){
		scanf("%d",&n);
		Solver s(n);
		printf("Case %d: %lld\n",t,s.solve());
	}
	
	return 0;
}

