/*
Project name : Sansa_and_XOR
Created on : Mon Aug 25 23:58:19 2014
Author : Anant Pushkar
https://www.hackerrank.com/contests/w9/challenges/sansa-and-xor
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
	int n , soln;
public:
	Solver(int x):
	n(x){
		int a , count=0 ;
		soln = 0;
		for(int i=0;i<n;++i){
			cin>>a;
			count = count - i + (n-i) ;
			soln  = soln ^ (count%2==1 ? a : 0);
		}
	}
	int solve(){
		return soln;
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t , n;
	cin>>t;
	
	while(t--){
		cin>>n;
		Solver s(n);
		cout<<s.solve()<<endl;
	}
	
	return 0;
}

