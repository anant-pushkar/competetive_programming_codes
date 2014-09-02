/*
Project name : Caisa_and_Sugar
Created on : Sat Aug 30 13:02:11 2014
Author : Anant Pushkar
http://codeforces.com/contest/463/problem/0
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
	int n,s;
	scanf("%d %d",&n,&s);
	s *= 100;
	
	int x , y , max=INT_MIN , val;
	while(n--){
		scanf("%d %d",&x,&y);
		val = 100*x+y;
		y   = y!=0 ? 100-y : 0;
		if(val<=s){
			max = max<y ? y : max;
		}
	}
	
	printf("%d\n",max==INT_MIN ? -1 : max);
	
	return 0;
}

