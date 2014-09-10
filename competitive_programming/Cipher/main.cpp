/*
Project name : Cipher
Created on : Wed Sep 10 14:29:16 2014
Author : Anant Pushkar
https://www.hackerrank.com/contests/w10/challenges/cipher
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
	int n , k;
	scanf("%d %d",&n,&k);
	
	string s;
	cin>>s;
	
	int window=0 , mask=0 , len = s.size() , count=0 , digit;
	queue<int> q;
	for(int i=0;i<len && count<n;++i){
		digit = static_cast<int>(s[i]-'1'+1)^mask;
		cout<<digit;
		q.push(digit);
		
		mask ^= digit;
		++window;
		++count;
		if(debug)cout<<" | window : "<<window<<" count : "<<count<<endl;
		if(window == k){
			mask ^= q.front();
			q.pop();
			--window;
		}
	}
	
	return 0;
}

