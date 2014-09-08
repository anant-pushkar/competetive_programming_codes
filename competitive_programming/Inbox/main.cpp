/*
Project name : Inbox
Created on : Sun Sep  7 21:08:23 2014
Author : Anant Pushkar
http://codeforces.com/contest/465/problem/B
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
	vector<int> status(n);
	
	int total=0;
	for(int i=0;i<n;++i){
		scanf("%d",&status[i]);
		total += status[i];
	}
	
	int count=0 , start;
	for(int i=0;i<n;++i){
		if(status[i]==1){
			start = i;
			while( (i<n-1 && status[i+1]==1) || (i<n-2 && status[i+1]==0 && status[i+2]==1)){
				i += (i<n-1 && status[i+1]==1) ? 1 : 2;
				total -= 1;
			}
			count += i-start+1 ;
			if(total!=0 && i<n-2 && status[i+1]==0){
				count += 1;
			}
		}
	}
	
	printf("%d\n",count);
	
	return 0;
}

