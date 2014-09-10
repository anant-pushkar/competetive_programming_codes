/*
Project name : Alternating_Characters
Created on : Wed Sep 10 13:31:48 2014
Author : Anant Pushkar
https://www.hackerrank.com/contests/w10/challenges/alternating-characters
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
	int t;
	scanf("%d",&t);
	
	string s;
	int len , count;
	while(t--){
		cin>>s;
		len = s.size();
		count = 0;
		for(int i=0;i<len-1;++i)if(s[i]==s[i+1]){
			++count;
		}
		cout<<count<<endl;
	}
	
	return 0;
}

