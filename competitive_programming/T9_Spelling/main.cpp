/*
Project name : T9_Spelling
Created on : Tue Oct 14 18:18:25 2014
Author : Anant Pushkar
https://code.google.com/codejam/contest/351101/dashboard#s=p2
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
#include<unordered_map>
using namespace std;
bool debug=false;
typedef long long int lld;
typedef unsigned long long int llu;
unordered_map<char , string> lookup;
void init(){
	lookup['a'] = "2";
	lookup['b'] = "22";
	lookup['c'] = "222";
	lookup['d'] = "3";
	lookup['e'] = "33";
	lookup['f'] = "333";
	lookup['g'] = "4";
	lookup['h'] = "44";
	lookup['i'] = "444";
	lookup['j'] = "5";
	lookup['k'] = "55";
	lookup['l'] = "555";
	lookup['m'] = "6";
	lookup['n'] = "66";
	lookup['o'] = "666";
	lookup['p'] = "7";
	lookup['q'] = "77";
	lookup['r'] = "777";
	lookup['s'] = "7777";
	lookup['t'] = "8";
	lookup['u'] = "88";
	lookup['v'] = "888";
	lookup['w'] = "9";
	lookup['x'] = "99";
	lookup['y'] = "999";
	lookup['z'] = "9999";
	lookup[' '] = "0";
	
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	init();
	int T;
	scanf("%d",&T);
	
	string s;
	getline(cin , s);
	for(int t=1;t<=T;++t){
		getline(cin , s);
		printf("Case #%d: ",t);
		cout<<lookup[s[0]];
		for(int i=1;i<s.size();++i){
			if(lookup[s[i-1]][0] == lookup[s[i]][0]){
				cout<<" ";
			}
			cout<<lookup[s[i]];
		}
		cout<<endl;
	}
	
	return 0;
}

