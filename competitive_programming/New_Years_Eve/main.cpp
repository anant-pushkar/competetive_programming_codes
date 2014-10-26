/*
Project name : New_Years_Eve
Created on : Mon Oct 13 09:00:30 2014
Author : Anant Pushkar
https://code.google.com/codejam/contest/4214486/dashboard#s=p1
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
vector<pair<int,int> > pos;
void init(){
	int index=0;
	pos = vector<pair<int,int> >(160000);
	for(int i=0;i<400;++i){
		for(int j=0;j<=i;++j){
			pos[index++] = make_pair(i,j);
		}
	}
}
class Solver{
	int b , l , n;
	deque<deque<double> > dp;
	void distribute(int x , int y ){
		double val = dp[x][y];
		if(val<=250){
			return;
		}
		val -= 250;
		dp[x][y] = 250;
		
		if(x+1>=l){
			return;
		}
		
		dp[x+1][y] += val/3;
		dp[x+1][pos[y].first+1+y] += val/3;
		dp[x+1][pos[y].first+2+y] += val/3;
	}
public:
	Solver(){
		scanf("%d %d %d",&b , &l , &n);
		for(int i=0;i<l;++i){
			dp.push_back(deque<double>( (i+1)*(i+2)/2 , 0) );
		}
	}
	double solve(){
		dp[0][0] = 750*b;
		for(int i=0;i<l;++i){
			for(int j=0;j<(i+1)*(i+2)/2;++j){
				distribute(i,j);
			}
		}
		
		return dp[l-1][n-1];
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int T;
	scanf("%d",&T);
	init();
	
	for(int t=1;t<=T;++t){
		Solver s;
		printf("Case #%d: %lf\n",t,s.solve());
	}
	return 0;
}


