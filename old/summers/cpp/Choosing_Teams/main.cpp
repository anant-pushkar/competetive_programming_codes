/*
Project name : Choosing_Teams
Created on : Sun May 18 09:40:55 2014
Author : Anant Pushkar
http://codeforces.com/contest/432/problem/A
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
	int n,k;
	scanf("%d %d",&n,&k);
	int y[n];
	for(int i=0;i<n;++i)scanf("%d",&y[i]);
	sort(y,y+n);
	int count=0;
	for(int i=0;i+2<n;i+=3){
		if(y[i]+k<6 && y[i+1]+k<6 && y[i+2]+k<6)++count;
	}
	printf("%d\n",count);
	return 0;
}

