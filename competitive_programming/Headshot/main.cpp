/*
Project name : Headshot
Created on : Sat Sep  6 17:09:16 2014
Author : Anant Pushkar
http://www.spoj.com/problems/HEADSHOT/
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
	string chamber;
	cin>>chamber;
	
	int zero_one=0 , zero_zero=0 , n = chamber.size();
	for(int i=0;i<n;++i){
		if(chamber[i]=='0' && chamber[(i+1)%n]=='0'){
			++zero_zero;
		}
		if(chamber[i]=='0' && chamber[(i+1)%n]=='1'){
			++zero_one;
		}
	}
	
	if(zero_zero==zero_one || zero_zero==n){
		printf("EQUAL\n");
	}else if(zero_zero>zero_one){
		printf("SHOOT\n");
	}else{
		printf("ROTATE\n");
	}
	
	return 0;
}

