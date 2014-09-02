/*
Project name : Counter_game
Created on : Sat Aug  9 09:01:14 2014
Author : Anant Pushkar
https://www.hackerrank.com/contests/w8/challenges/counter-game
1 s
2 f
3 f
4 s
5 f
6 s
7 s
8 f
9 f
10 s
11 s
12 f
13 s
14 f
15 f
16 s

[s] [f] [f] [s] [f] [s] [s] [f] [f] [s] [s] [f]

8 4 2 1
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
class Solver{
	lld n;
	bool is_pow_2(lld x){
		return (x&(x-1))==0;
	}
	lld previous_pow(lld x){
		if(debug)cout<<"pre of "<<x<<" ";
		lld p=1;
		x = x>>1;
		while(x>0){
			p = p<<1;
			x = x>>1;
		}
		if(debug)cout<<p<<endl;
		return p;
	}
	bool first_win(lld x){
		if(debug)cout<<x<<endl;
		if(x==1 || x==4){
			return false;
		}else if(x==2 || x==3){
			return true;
		}
		
		if(is_pow_2(x)){
			return !first_win(x>>1);
		}
		return !first_win(x - previous_pow(x));
	}
public:
	Solver(lld x):
	n(x){
		
	}
	const char* solve(){
		return first_win(n) ? "Louise" : "Richard";
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t;
	scanf("%d",&t);
	
	lld n;
	while(t--){
		scanf("%lld",&n);
		Solver s(n);
		printf("%s\n",s.solve());
	}
	
	return 0;
}

