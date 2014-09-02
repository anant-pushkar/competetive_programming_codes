/*
Project name : BOOKS1
Created on : Fri May  9 11:14:41 2014
Author : Anant Pushkar
http://www.spoj.com/problems/BOOKS1/
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
int m , k;
vector<unsigned int> arr;
bool f(llu x,bool print){
	if(debug)cout<<"x : "<<x<<" ";
	llu a=0;
	int count=0;
	for(int i=0;i<m;++i){
		if(a+arr[i]<=x){
			a += arr[i];
			if(print)printf("%u ",arr[i]);
		}else{
			++count;
			a=0;
			if(print)printf("/ ");
		}
		if(count > k){
			goto exit;
		}
	}
	exit:
		if(print)printf("\n");
		return count<=k;
}
llu search(llu sum , llu min){
	llu s=min , e=sum+1 , m;
	bool check;
	while(e-s>1){
		m = (s+e)/2;
		check= f(m,true);
		if(check) e = m;
		else s = m;
	}
	return s;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int N ;
	scanf("%d",&N);
	arr = vector<unsigned int>(500);
	llu sum=0,min=ULLONG_MAX,x;
	while(N--){
		scanf("%d %d",&m,&k);
		for(int i=0;i<m;++i){
			scanf("%u",&arr[i]);
			if(i<m-k+1)sum += arr[i];
			min  = min>arr[i] ? arr[i] : min;
		}
		for(int i=m-k+1;i<m;++i){
			x=sum-arr[i-m+k-1]+arr[i];
			if(x>sum) sum=x;
		}
		x = search(sum,min);
		f(x,true);
	}
	return 0;
}

