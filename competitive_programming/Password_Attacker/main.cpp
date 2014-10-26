/*
Project name : Password_Attacker
Created on : Sun Oct 12 16:19:12 2014
Author : Anant Pushkar
https://code.google.com/codejam/contest/4214486/dashboard
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
const int mod = 1000000007;
class Solver{
	vector<vector<llu> > lookup ;
public:
	Solver():
	lookup(vector<vector<llu> >(101 , vector<llu>(101 , 0))){
		lookup[1][1] = 1;
		for(int i=1;i<101;++i){
			for(int j=2;j<101;++j){
				lookup[i][j] = i*((lookup[i][j-1] + lookup[i-1][j-1])%mod);
				lookup[i][j] = lookup[i][j]%mod;
			}
		}
	}
	int solve(int m , int n){
		return lookup[m][n];
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int T;
	scanf("%d",&T);
	
	Solver s;
	int m , n;
	for(int t=1;t<=T;++t){
		scanf("%d %d",&m,&n);
		printf("Case #%d: %d\n",t,s.solve(m,n));
	}
	
	return 0;
}

