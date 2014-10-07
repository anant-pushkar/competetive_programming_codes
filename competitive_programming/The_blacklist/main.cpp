/*
Project name : The_blacklist
Created on : Sat Sep 27 18:17:11 2014
Author : Anant Pushkar

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
int n , k;
vector< vector<int> > cost;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	
	scanf("%d %d",&n,&k);
	cost = vector<vector<int> >(k , vector<int>(n));
	for(int i=0;i<k;++i){
		for(int j=0;j<n;++j){
			scanf("%d",&cost[i][j]);
		}
	}
	
	vector<vector<lld> > dp(k , vector<lld>(n,INT_MAX)) ;
	vector<vector<int> > mask(k , vector<int>(n,0));
	for(int i=0;i<k;++i){
		dp[i][0] = cost[i][0];
		mask[i][0] = (1<<i);
	}
	
	lld v1 , v2 , m; 
	for(int i=1;i<n;++i){
		for(int j=0;j<k;++j){
			v1 = dp[j][i-1];
			v2 = LLONG_MAX;
			m = 0;
			for(int p=0;p<k;++p)if(p!=j && ((1<<j)&mask[p][i-1])==0){
				v2 = v2>=dp[p][i-1] ? dp[p][i-1] : v2;
				m  = mask[p][i-1];
			}
			if(v1<v2){
				dp[j][i] = v1 + cost[j][i];
				mask[j][i] = mask[j][i-1];
			}else{
				dp[j][i] = v2 + cost[j][i];
				mask[j][i] = m|(1<<j);
			}
		}
	}
	
	if(debug){
		for(int i=0;i<k;++i){
			for(int j=0;j<n;++j){
				cout<<dp[i][j]<<" ";
			}
			cout<<endl;
		}
	}	
	
	v1 = LLONG_MAX;
	for(int i=0;i<k;++i){
		v1 = v1>dp[i][n-1] ? dp[i][n-1] : v1;
	}
	printf("%lld\n",v1);
	
	return 0;
}

