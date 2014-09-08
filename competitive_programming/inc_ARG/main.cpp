/*
Project name : inc_ARG
Created on : Sun Sep  7 21:02:02 2014
Author : Anant Pushkar
http://codeforces.com/contest/465/problem/0
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
	
	string bits;
	cin>>bits;
	
	int count=0;
	for(int i=0;i<n;++i){
		if(bits[i]=='1'){
			++count;
		}else{
			++count;
			break;
		}
	}
	
	printf("%d\n",count);
	
	return 0;
}

