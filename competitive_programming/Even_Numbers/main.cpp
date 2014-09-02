/*
Project name : Even_Numbers
Created on : Mon Aug 25 18:38:01 2014
Author : Anant Pushkar
http://www.spoj.com/problems/EC_CONB/
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
inline int invert(int x){
	int y=0;
	while(x != 0){
		y = y<<1;
		y = y | (x&1);
		x = x>>1;
		if(debug)cout<<"y:"<<y<<endl;
	}
	
	return y;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n , x;
	scanf("%d",&n);
	
	while(n--){
		scanf("%d",&x);
		printf("%d\n" , x%2==0 ? invert(x) : x);
	}
	
	return 0;
}

