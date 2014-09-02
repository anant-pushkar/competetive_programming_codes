/*
Project name : Will_it_ever_stop
Created on : Sat May 24 16:52:29 2014
Author : Anant Pushkar
http://www.spoj.com/problems/WILLITST/
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
	llu n;
	scanf("%llu",&n);
	if( (n&(n-1)) == 0 )printf("TAK\n");
	else printf("NIE\n");
	return 0;
}

