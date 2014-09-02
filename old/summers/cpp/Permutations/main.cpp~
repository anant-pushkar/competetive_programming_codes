/*
Project name : Permutations
Created on : Mon Jun  9 18:20:24 2014
Author : Anant Pushkar
http://www.spoj.com/problems/PERMUT1/
n=1
	k=0 : 1
	k=1 : 0
	k=2 : 0
	k=3 : 0
	....
n=2
	k=0 : 1
	k=1 : 1
	k=2 : 0
	.....
n=3
	k=0 : 1
	k=1 : 2
	k=2 : 2
	k=3 : 1
	k=4 : 0
	....
n=4 
	k=0 : 1
	k=1 : 3
	k=2 : 5
	k=3 : 6
	k=4 : 5
	k=5 : 3
	k=6 : 1
	k=7 : 0
	.....
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
const int N=12;
const int K=98;
class Solver{
	vector<vector<lld> > lookup;
public:
	Solver():
		lookup(vector<vector<lld> >(N+1,vector<lld>(K+1,0))){
			
		lookup[1][0] = 1;
		for(int i=1;i<=K;++i)
			lookup[1][i] = 0;
		
		for(int i=2;i<=N;++i){
			lookup[i][0] = 1;
			for(int j=1;j<=i-1;++j){
				lookup[i][j] = lookup[i][j-1] + lookup[i-1][j];
			}
			for(int j=i;j<=i*(i-1)/2;++j){
				lookup[i][j] = lookup[i][j-1] + lookup[i-1][j] - lookup[i-1][j-i];
			}
		}
	}
	lld solve(int n , int k){
		return lookup[n][k];
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t,n,k;
	scanf("%d",&t);
	Solver s;
	while(t--){
		scanf("%d %d",&n,&k);
		printf("%lld\n",s.solve(n,k));
	}
	return 0;
}

