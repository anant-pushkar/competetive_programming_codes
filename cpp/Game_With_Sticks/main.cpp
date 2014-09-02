/*
Project name : Game_With_Sticks
Created on : Thu Jul 24 21:02:11 2014
Author : Anant Pushkar
http://codeforces.com/contest/451/problem/0
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
	int n , m;
	vector<vector<int> > lookup;
	inline int get_min(int a , int b){
		return a>b ? b : a;
	}
public:
	Solver(int a , int b):
	n(a),
	m(b),
	lookup(vector<vector<int> >(a , vector<int>(b,0))){
		
	}
	string solve(){
		int min = get_min(m,n);
		if(min%2==0){
			return "Malvika";
		}else{
			return "Akshat";
		}
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n , m;
	scanf("%d %d",&n,&m);
	
	Solver s(n,m);
	cout<<s.solve()<<endl;
	
	return 0;
}

