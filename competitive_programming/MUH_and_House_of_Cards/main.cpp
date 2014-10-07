/*
Project name : MUH_and_House_of_Cards
Created on : Fri Sep 26 22:15:30 2014
Author : Anant Pushkar
http://codeforces.com/contest/471/problem/C
2 
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
	lld n;
	scanf("%lld",&n);
	
	int count=0;
	lld x=2 , i=2;
	while(x<=n){
		if(debug)cout<<"\tdiff: "<<n-x<<endl;
		if((n-x)%3==0){
			++count;
		}
		x = x + 3*i-1 ;
		++i;
		if(debug)cout<<"x : "<<x<<endl;
	}
	
	printf("%d\n",count);
	
	return 0;
}

