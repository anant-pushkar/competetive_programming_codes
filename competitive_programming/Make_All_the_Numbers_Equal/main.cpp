/*
Project name : Make_All_the_Numbers_Equal
Created on : Sun Oct  5 17:00:55 2014
Author : Anant Pushkar
https://www.hackerrank.com/contests/csindia14-er2/challenges/make-all-the-numbers-equal
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
int n;
lld k;
int *a;
inline int get_max(int a , int b){
	return a>b ? a : b;
}
inline int get_min_val(int a,int b){
	return a<b ? a : b;
}
pair<lld,lld> get_min(int start , int end){
	if(end==start){
		return pair<lld,lld>(0,INT_MIN);
	}
	if(end==start+1){
		return pair<lld,lld>(0,a[start]);
	}
	if(end==start+2){
		int max = get_max(a[start],a[start+1]);
		int min = get_min_val(a[start],a[start+1]);
		return pair<lld,lld>(max-min , max);
	}
	int max=INT_MIN , max_index=-1;
	for(int i=start;i<end;++i){
		if(max<a[i]){
			max_index = i;
			max = a[i];
		}
	}
	pair<lld,lld> left  = get_min(start,max_index);
	pair<lld,lld> right = get_min(max_index+1,end);
	lld left_move = left.second ==INT_MIN ? 0 : max-left.second ;
	lld right_move= right.second==INT_MIN ? 0 : max-right.second;
	
	return make_pair( left_move+right_move+left.first+right.first , max);
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	scanf("%d %lld",&n,&k);
	a = (int*) calloc(n,sizeof(int));
	
	for(int i=0;i<n;++i){
		scanf("%d",&a[i]);
	}
	
	pair<lld,lld> soln = get_min(0,n);
	cout<< (k>=soln.first ? k-soln.first+1 : 0)<<endl;
	
	
	return 0;
}

