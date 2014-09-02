/*
Project name : Street
Created on : Mon May 19 17:15:35 2014
Author : Anant Pushkar
http://www.spoj.com/problems/STREET/
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
class Solver{
	int n , k , t;
	vector<int> h;
	vector<vector<int> > dp;
	int getDP(int i , int j){
		return dp[(i+t)%(t+1)][j];
	}
	void setDP(int i , int j , int val){
		dp[(i+t)%(t+1)][j] = val;
	}
	int getMin(int a , int b){
		int min = INT_MAX;
		for(int i=a;i<=b;++i)min = min>h[i] ? h[i] : min ;
		return min;
	}
public:
	Solver(){
		scanf("%d %d %d",&n,&k,&t);
		--t;
		h = vector<int>(n);
		for(int i=0;i<n;++i)scanf("%d",&h[i]);
		dp = vector<vector<int> >(t+1,vector<int>(k+1,0));
	}
	int solve(){
		int v1 , v2 , v3 , v , min;
		for(int i=0;i<=n;++i){
			min = getMin(i-t+1 , i);
			for(int j=1;j<=k;++j){
				v1 = getDP(i,j-1);
				v2 = getDP(i-1,j);
				v3 = getDP(i-t,j-1) + min*t;
				
				v = v1>v2 ? v1 : v2;
				v = v >v3 ? v  : v3;
				if(debug && v==v3)cout<<"errecting building at "<<i<<"("<<h[i]<<")"<<endl;
				setDP(i,j,v);
			}
		}
		return getDP(n,k);
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	Solver s;
	printf("%d\n",s.solve());
	return 0;
}

