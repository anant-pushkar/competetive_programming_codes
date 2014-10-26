/*
Project name : Registration_system
Created on : Mon Oct 20 00:07:41 2014
Author : Anant Pushkar
http://codeforces.com/problemset/problem/4/C
*/
#include<iostream>
#include<sstream>
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
class Solver{
	unordered_map<string , int> lookup;
	string make_name(string name , int i){
		stringstream ss;
		ss<<name<<i;
		return ss.str();
	}
public:
	string solve(string name){
		if(lookup.find(name)==lookup.end()){
			lookup[name] = 1;
			return "OK";
		}else{
			string uname = make_name(name , lookup[name]);
			++lookup[name];
			
			return uname;
		}
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t;
	cin>>t;
	
	Solver s;
	string name;
	while(t--){
		cin>>name;
		cout<<s.solve(name)<<endl;
	}
	return 0;
}


