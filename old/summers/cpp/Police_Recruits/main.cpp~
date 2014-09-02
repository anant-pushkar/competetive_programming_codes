/*
Project name : Police_Recruits
Created on : Sat May 10 14:32:52 2014
Author : Anant Pushkar
http://codeforces.com/contest/427/problem/A
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
	int n;scanf("%d",&n);
	int p=0 , c=0 , x;
	while(n--){
		scanf("%d",&x);
		if(x==-1){
			if(p>0)--p;
			else ++c;		
		}else{
			p += x;
		}
	}
	printf("%d\n",c);
	return 0;
}

