/*
Project name : Pebble_Solver
Created on : Fri Aug 29 21:51:09 2014
Author : Anant Pushkar
http://www.spoj.com/problems/PEBBLE/
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
string bit_string;
vector<lld> lookup_one , lookup_zero;
lld solve(){
	int size = bit_string.size();
	lookup_one = vector<lld>(size , 0);
	lookup_zero= vector<lld>(size , 0);
	
	lookup_one[size-1]  = bit_string[size-1]=='1' ? 0 : 1;
	lookup_zero[size-1] = bit_string[size-1]=='0' ? 0 : 1;
	for(int i=size-2;i>-1;--i){
		if(bit_string[i]=='1'){
			lookup_one[i]  = lookup_one[i+1];
			lookup_zero[i] = lookup_one[i+1] + 1;
		}else{
			lookup_one[i]  = lookup_zero[i+1] + 1;
			lookup_zero[i] = lookup_zero[i+1];
		}
	}
	
	return lookup_zero[0];
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	
	int game=1;
	while(true){
		cin>>bit_string;
		if(cin.eof()){
			break;
		}
		printf("Game #%d: %lld\n",game,solve());
		++game;
	}
	return 0;
}


