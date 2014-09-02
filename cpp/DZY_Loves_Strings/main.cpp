/*
Project name : DZY_Loves_Strings
Created on : Fri Jul 18 21:01:50 2014
Author : Anant Pushkar
http://codeforces.com/contest/447/problem/B
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
	char s[1001];
	scanf("%s",s);
	
	int k;
	scanf("%d",&k);
	
	int val[26] , max=INT_MIN;
	for(int i=0;i<26;++i){
		scanf("%d",&val[i]);
		max = max<val[i] ? val[i] : max;
	}
	
	int l=strlen(s) , v=((l+k)*(l+k+1)/2-l*(l+1)/2)*max;
	for(int i=0;i<l;++i){
		v += val[s[i]-'a']*(i+1);
	}
	printf("%d\n",v);
	
	return 0;
}

