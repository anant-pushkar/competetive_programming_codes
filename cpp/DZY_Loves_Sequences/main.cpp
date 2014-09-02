/*
Project name : DZY_Loves_Sequences
Created on : Fri Jul 18 21:10:07 2014
Author : Anant Pushkar
http://codeforces.com/contest/447/problem/C
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
#define NOT_FOUND 0
#define FOUND 1
using namespace std;
bool debug=false;
typedef long long int lld;
typedef unsigned long long int llu;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n;
	scanf("%d",&n);
	
	vector<int> a(n+1);
	for(int i=0;i<n;++i){
		scanf("%d",&a[i]);
		if(debug)cout<<a[i]<<" ";
	}
	if(debug)cout<<endl<<endl;
	a[n] = INT_MAX;
	
	int i=0 , len=0;
	while(i<n && a[i]<a[i+1]){
		++i;
		++len;
	}
	
	int temp = a[i+1] , index=i;
	
	int max = len;
	for(;i<n;++i){
		if(debug)cout<<"i:"<<i<<" "<<a[i]<<endl;
		if(a[i]>=a[i+1]){
			if(i!=n-1 && a[i+2]<=a[i]+1){
				len   = i-index;
				index = i;
			}else{
				i  = i+1;
				len= 1;
			}
		}
		++len;
		max = max<len ? len : max;
		if(debug){
			cout<<"len:"<<len<<" max:"<<max<<" temp:"<<temp<<" index:"<<index<<endl;
			for(int j=0;j<n;++j){
				cout<<a[j]<<" ";
			}
			cout<<endl<<endl;
		}
	}
	printf("%d\n",max);
	
	return 0;
}

