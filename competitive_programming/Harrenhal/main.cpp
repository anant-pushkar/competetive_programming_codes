/*
Project name : Harrenhal
Created on : Sun Aug 31 11:08:21 2014
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
bool is_palindrome(const string &h){
	int i=0 , j=h.size()-1;
	while(i<j){
		if(h[i]!=h[j]){
			return false;
		}
		++i;
		--j;
	}
	return true;
}
bool is_palindromic(const deque<int> &h){
	int i=0 , j=h.size()-1;
	while(i<j){
		while(i<j && h[i]==0){
			++i;
		}
		while(i<j && h[j]==0){
			--j;
		}
		if(i>=j){
			break;
		}
		if(h[i]!=h[j]){
			return false;
		}
		++i;
		--j;
	}
	return true;
}
int solve(string &h){
	deque<int> freq;
	int count=1 , n = h.size();
	for(int i=0;i<n-1;++i){
		if(h[i]==h[i+1]){
			++count;
		}else{
			freq.push_back(count);
			count=1;
		}
	}
	freq.push_back(count);
	
	n = freq.size();
	int min , zero=0;
	count=0;
	while(zero<n && count<n){
		min = INT_MAX;
		for(int i=0;i<n;++i)if(freq[i]!=0){
			min = min>freq[i] ? min = freq[i] : min;
		}
		for(int i=0;i<n;++i)if(freq[i]!=0){
			freq[i] -= min;
			zero += freq[i]==0 ? 1 : 0;
		}
		if(min==INT_MAX){
			break;
		}
		++count;
		if(is_palindromic(freq)){
			++count;
			break;
		}
	}
	
	return count;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t;
	scanf("%d",&t);
	
	string h;
	while(t--){
		cin>>h;
		if(is_palindrome(h)){
			cout<<1<<endl;
		}else{
			cout<<solve(h)<<endl;
		}
	}
	
	return 0;
}

