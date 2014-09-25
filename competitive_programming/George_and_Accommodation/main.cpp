/*
Project name : George_and_Accommodation
Created on : Thu Sep 25 22:06:08 2014
Author : Anant Pushkar
http://codeforces.com/contest/467/problem/A
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
	
	int a , b , count = 0;
	while(n--){
		scanf("%d %d",&a,&b);
		count += a+2<=b ? 1 : 0;
	}
	printf("%d\n",count);
	
	return 0;
}

