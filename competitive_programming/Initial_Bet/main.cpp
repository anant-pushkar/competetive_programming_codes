/*
Project name : Initial_Bet
Created on : Thu Oct 16 21:11:26 2014
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
	int a,b,c,d,e;
	cin>>a>>b>>c>>d>>e;
	cout<<((a+b+c+d+e)%5==0 ? (a+b+c+d+e)/5 : -1)<<endl;
	return 0;
}

