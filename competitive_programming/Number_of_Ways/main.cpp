/*
Project name : Number_of_Ways
Created on : Mon Sep 29 19:36:21 2014
Author : Anant Pushkar
http://codeforces.com/contest/466/problem/C
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
	int n;
	scanf("%d",&n);
	
	vector<int> arr(n);
	for(int i=0;i<n;++i){
		scanf("%d",&arr[i]);
	}
	
	vector<lld> sum(n);
	sum[0] = arr[0];
	for(int i=1;i<n;++i){
		sum[i] = sum[i-1]+arr[i];
	}
	
	if(sum[n-1]%3!=0 || n<3){
		cout<<0<<endl;
		return 0;
	}
	
	if(debug){
		cout<<"SUM : ";
		for(int i=0;i<n;++i){
			cout<<sum[i]<<" ";
		}
		cout<<endl;
	}
	
	queue<int> q1 , q2;
	for(int i=0;i<n-1;++i){
		if(sum[i]==sum[n-1]/3){
			q1.push(i);
		}
		if(sum[i]==2*(sum[n-1]/3)){
			q2.push(i);
		}
	}
	
	lld soln=0;
	while(!q1.empty()){
		while(!q2.empty()){
			if(q2.front()>q1.front()){
				break;
			}
			if(debug)cout<<"poping "<<q2.front()<<endl;
			q2.pop();
		}
		if(debug)cout<<"adding "<<q2.size()<<endl;
		soln += q2.size();
		q1.pop();
	}
	
	cout<<soln<<endl;
	
	return 0;
}

