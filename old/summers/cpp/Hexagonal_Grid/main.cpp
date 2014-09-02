/*
Project name : Hexagonal_Grid
Created on : Sat May 17 14:57:19 2014
Author : Anant Pushkar
https://www.hackerrank.com/contests/101mar14/challenges/hexagonal-grid
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
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t;scanf("%d",&t);
	int n,i,count;
	char str1[11] , str2[11];
	while(t--){
		scanf("%d",&n);
		scanf("%s",str1);
		scanf("%s",str2);
		count=0;
		for(i=0;i<n;++i){
			count += str1[i]=='1' ? 1 : 0;
			count += str2[i]=='1' ? 1 : 0;
		}
		if(count%2==0)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

