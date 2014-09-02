/*
Project name : Sam_and_sub-strings
Created on : Tue May 20 22:06:01 2014
Author : Anant Pushkar
https://www.hackerrank.com/contests/w3/challenges/sam-and-substrings
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
#define SIZE 200001
#define MOD  1000000007
using namespace std;
bool debug=false;
typedef long long int lld;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	char str[SIZE];
	scanf("%s",str);
	int len = strlen(str);
	if(debug)cout<<"len : "<<len<<endl<<"|"<<str[0]<<"|"<<str[1]<<"|"<<str[2]<<"|"<<endl;
	vector<lld> lookup(len,0);
	lookup[0] = str[0]-'0';
	if(debug)cout<<0<<" : "<<lookup[0]<<endl;
	for(int i=1;i<len;++i){
		lookup[i] = (lookup[i-1]*10+(i+1)*(str[i]-'0'))%MOD;
		if(debug)cout<<i<<" : "<<lookup[i]<<endl;
	}
	
	lld sum=0;
	for(int i=0;i<len;++i){
		sum += lookup[i]%MOD;
	}
	printf("%lld\n",sum%MOD);
	
	return 0;
}

