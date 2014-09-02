/*
Project name : Pashmak_and_Garden
Created on : Sat Aug 23 21:13:21 2014
Author : Anant Pushkar
http://codeforces.com/contest/459/problem/A
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
inline int get_side(int a , int b , int c , int d){
	int s1 = abs(c-a) , s2 = abs(d-b);
	if(s1 != s2){
		return s1==0 ? s2 : s2==0 ? s1 : -1;
	}else{
		return s1;
	}
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int x1 , y1 , x2 , y2;
	scanf("%d %d %d %d",&x1 , &y1 , &x2 , &y2);
	
	int side = get_side(x1,y1,x2,y2);
	if(side<0){
		printf("-1\n");
		return 0;
	}
	
	if(x1-x2==0){
		printf("%d %d %d %d\n",side+x1 , y1 , side+x1 , y2);
	}else if(y1-y2==0){
		printf("%d %d %d %d\n",x1 , side+y1 , x2 , side+y2);
	}else{
		printf("%d %d %d %d\n",x1,y2,x2,y1);
	}
	
	
	return 0;
}

