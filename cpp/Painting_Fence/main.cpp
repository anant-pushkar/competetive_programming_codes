/*
Project name : Painting_Fence
Created on : Thu Jul 17 20:52:43 2014
Author : Anant Pushkar
http://codeforces.com/contest/448/problem/C
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
vector<int> a;
int getMin(int start , int end){
	int min = INT_MAX;
	for(int i=start;i<end;++i){
		min = min>a[i] ? a[i] : min;
	}
	return min;
}
lld countStrokes(int start , int end , int base){
	if(debug)cout<<"Start:"<<start<<" End:"<<end<<" Base:"<<base<<endl;
	if(start == end){
		return 0;
	}
	int min = getMin(start,end);
	lld count;
	if(min>base){
		count = min-base;
		min  -= base;
	}else{
		count = 0;
		min   = 0;
	}
	
	int e=start;
	while(e<end && a[e]<=base){
		++e;
	}
	int s=e;
	
	while(e<end){
		while(e<end && a[e]>base){
			++e;
		}
		count += countStrokes(s,e,base+min);
		while(e<end && a[e]<=base){
			++e;
		}
		s = e;
	}
	if(debug)cout<<"Returning from "<<start<<" "<<end<<" "<<base<<" with : "<<(count<end-start ? count : end-start)<<endl;
	return count<end-start ? count : end-start;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	
	int n;
	scanf("%d",&n);
	a = vector<int>(n);
	
	for(int i=0;i<n;++i){
		scanf("%d",&a[i]);
	}
	
	printf("%lld\n",countStrokes(0,n,0));
	
	return 0;
}

