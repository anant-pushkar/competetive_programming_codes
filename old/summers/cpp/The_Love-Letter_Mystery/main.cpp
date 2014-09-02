/*
Project name : The_Love-Letter_Mystery
Created on : Tue May 20 20:20:33 2014
Author : Anant Pushkar
https://www.hackerrank.com/contests/w3/challenges/the-love-letter-mystery
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
#include<cmath>
using namespace std;
bool debug=false;
typedef long long int lld;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t;scanf("%d",&t);
	char str[10001];
	int l,m1,m2,count;
	while(t--){
		scanf("%s",str);
		l =strlen(str);
		m1=(l-1)/2;
		m2=l/2;
		count=0;
		while(m1>-1){
			count += abs(str[m1]-str[m2]);
			--m1;++m2;
		}
		printf("%d\n",count);
	}
	return 0;
}

