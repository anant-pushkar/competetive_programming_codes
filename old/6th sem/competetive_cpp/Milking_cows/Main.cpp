/*
Project name : Milking_cows
Created on : Mon Jan 20 21:24:27 2014
Author : Anant Pushkar
codeforces 384 : C
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<deque>
#include<vector>
using namespace std;
bool debug=false;
typedef long long int lld;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	lld n,lcount=0,rcount=0;
	cin>>n;
	int arr[n],lsum[n],rsum[n];
	for(int i=0;i<n;++i)cin>>arr[i];
	for(lld i=0;i<n;i+=1){
		if(arr[i]==1)++rcount;
		rsum[i]=rcount;
	}
	for(lld i=n-1;i>=0;--i){
		if(arr[i]==0)++lcount;
		lsum[i]=lcount;
	}
	lld lval=0,rval=0;
	if(debug){
		for(int i=0;i<n;++i)cout<<rsum[i]<<" ";
		cout<<endl;
		for(int i=0;i<n;++i)cout<<lsum[i]<<" ";
		cout<<endl;
	}
	for(int i=0;i<n;++i){
		if(arr[i]==1)lval+=lsum[i];
		if(arr[i]==0)rval+=rsum[i];
	}
	cout<<(lval<rval?lval:rval)<<endl;
	return 0;
}

