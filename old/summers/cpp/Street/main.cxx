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
	vector<vector<pair<int , int> > > minMem;
	pair<int,int> getMin(int a , int b){
		if(a<0 || b<0 || a>n-1 || b>n-1)return make_pair(0,a);
		if(minMem[a][b].first!=-1)return minMem[a][b];
		int min = INT_MAX , index=a;
		for(int i=a;i<=b;++i){
			min = min>h[i] ? h[i] : min ;
			index = min==h[i] ? i : index;
		}
		minMem[a][b] = make_pair(min,index);
		return minMem[a][b];
	}
public:
	Solver(){
		scanf("%d %d %d",&n,&k,&t);
		h = vector<int>(n);
		for(int i=0;i<n;++i)scanf("%d",&h[i]);
		dp = vector<vector<int> >(n,vector<int>(k+1,0));
		minMem = vector<vector<pair<int , int> > >(n,vector<pair<int , int> >(n,make_pair(-1,-1)));
	}
	int solve(){
		int v1 , v2 , v3 , v;
		pair<int,int> min;
		for(int i=0;i<n;++i){
			for(int j=1;j<=k;++j){
				v1 = dp[i][j-1];
				v2 = i==0? 0 : dp[i-1][j];
				v3 = 0;
				min = getMin(i-t+1 , i);
				for(int x=t;x>0;--x){
					v = (i>=x? dp[i-x][j-1] : 0) + min.first*x;
					v3= v>v3 ? v : v3;
					if(i-x+1 == min.second)min = getMin(i-x+2 , i);
				}
				
				v = v1>v2 ? v1 : v2;
				v = v >v3 ? v  : v3;
				dp[i][j] = v;
			}
		}
		return dp[n-1][k];
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	Solver s;
	printf("%d\n",s.solve());
	return 0;
}
