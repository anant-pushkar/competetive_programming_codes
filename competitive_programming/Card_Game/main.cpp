/*
Project name : Card_Game
Created on : Mon Oct 13 09:37:10 2014
Author : Anant Pushkar
https://code.google.com/codejam/contest/4214486/dashboard#s=p2
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
#include<list>
using namespace std;
bool debug=false;
typedef long long int lld;
typedef unsigned long long int llu;
class Solver{
	int n , k;
	vector<vector<int> > dp;
	vector<int> a;
	inline bool is_ap(int a , int b , int c){
		return b-a == k && c-b == k;
	}
	int get_len(int start , int end){
		if(end<start+3){
			dp[start][end] = end-start;
			return end-start;
		}
		if(end==start+3){
			dp[start][end] = is_ap(a[start] , a[start+1] , a[start+2]) ? 0 : 3;
			return dp[start][end];
		}
		if(dp[start][end]!=INT_MIN){
			return dp[start][end];
		}
		
		int min_len=end-start;
		
		for(int i=start+1;i<end;++i){
			min_len = min(min_len , get_len(start,i)+get_len(i,end));
		}
		
		for(int i=1;i+start<end;i+=3)if(is_ap(a[start] , a[i+start] , a[end-1]) && get_len(start+1,i+start)==0 && get_len(start+i+1,end-1)==0){
			min_len = 0;
		}
		
		dp[start][end] = min_len;
		
		return min_len;
	}
public:
	Solver(){
		scanf("%d %d",&n , &k);
		dp = vector<vector<int> >(n+1 , vector<int>(n+1,INT_MIN));
		a  = vector<int>(n);
		
		int x;
		for(int i=0;i<n;++i){
			scanf("%d",&x);
			a[i] = x;
		}
	}
	int solve(){
		int len = get_len(0,n);
		if(debug){
			for(int i=0;i<=n;++i){
				for(int j=i+1;j<=n;++j){
					cout<<i<<","<<j<<" : "<<dp[i][j]<<endl;
				}
			}
		}
		return len;
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int T;
	scanf("%d",&T);
	
	for(int t=1;t<=T;++t){
		Solver s;
		printf("Case #%d: %d\n",t,s.solve());
	}
	
	return 0;
}

