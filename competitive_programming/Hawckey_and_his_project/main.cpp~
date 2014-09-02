/*
Project name : Hawckey_and_his_project
Created on : Sat Aug  9 21:01:46 2014
Author : Anant Pushkar

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
	
	int x , y ;
	lld min_x=INT_MAX , max_x=INT_MIN , min_y=INT_MAX , max_y=INT_MIN;
	while(n--){
		scanf("%d %d",&x , &y);
		min_x = min_x>x ? x : min_x;
		min_y = min_y>y ? y : min_y;
		max_x = max_x<x ? x : max_x;
		max_y = max_y<y ? y : max_y;
	}
	
	printf("%lld\n",(max_x-min_x)*(max_y-min_y));
	
	return 0;
}

