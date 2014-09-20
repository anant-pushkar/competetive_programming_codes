/*
Project name : Tower_Of_Hanoi_-_Revisited
Created on : Sat Sep 20 14:26:27 2014
Author : Anant Pushkar
http://www.spoj.com/problems/RANJAN02/
f(n) = f(n-1) + 1 + f(n-1) + 1 + f(n-1)
f(n) = 3f(n-1)+2
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
vector<lld> lookup;
void init(){
	lookup = vector<lld>(36 , 0);
	lookup[1] = 2;
	for(int i=2;i<36;++i){
		lookup[i] = 3*lookup[i-1] + 2;
	}
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	init();
	
	int t , n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		printf("%lld\n",lookup[n]);
	}
	
	return 0;
}

