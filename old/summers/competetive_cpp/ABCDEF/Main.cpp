/*
Project name : ABCDEF
Created on : Thu May  8 14:29:04 2014
Author : Anant Pushkar
http://www.spoj.com/problems/ABCDEF/
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
vector<int> arr;
int n;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int i=0;
	arr = vector<int>(100);
	while(scanf("%d",&arr[i++])==1);
	sort(arr.begin(),arr.end());
	n=i;
	if(debug){
		for(int i=0;i<n;++i)cout<<arr[i]<<" ";
		cout<<endl;
	}
	
	int index=0;
	lld sum[1000000];
	if(debug)cout<<"Generating Sums : ";
	for(int i=0;i<n;++i){
		while(i<n-1 && arr[i]==arr[i+1])++i;
		for(int j=0;j<n;++j){
			while(j<n-1 && arr[j]==arr[j+1])++j;
			for(int k=0;k<n;++k){
				while(k<n-1 && arr[k]==arr[k+1])++k;
				sum[index++]=arr[i]*arr[j]+arr[k];
				if(debug)cout<<sum[index-1]<<endl;
			}
		}
	}
	queue<lld> q;
	for(int i=0;i<index;++i){
		for(int j=0;j<n;++j)if(arr[j]!=0 && sum[i]%arr[j]==0){
			while(j<n-1 && arr[j]==arr[j+1])++j;
			q.push(sum[i]/arr[j]);
		}
	}
	lld s;
	vector<int>::iterator it;
	lld count=0;
	while(!q.empty()){
		s  = q.front();
		for(int i=0;i<n;++i){
			it = lower_bound(arr.begin(),arr.end(),s-arr[i]);
			if(it!=arr.end() && *it==s-arr[i])++count;
		}
	}
	printf("%lld\n",count);
	
	return 0;
}

