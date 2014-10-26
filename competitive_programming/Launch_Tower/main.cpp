/*
Project name : Launch_Tower
Created on : Sat Oct 11 18:04:46 2014
Author : Anant Pushkar
http://www.codechef.com/ACMAMR14/problems/ACM14AM3
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
char s[20001];
int n;
vector<int> last_index;
void populate_last(){
	last_index = vector<int>(n , -1);
	vector<int> last(26,-1);
	for(int i=0;i<n;++i){
		if(last[s[i]-'0']!=-1){
			last_index[i] = last[s[i]-'0'];
		}
		last[s[i]-'0'] = i;
	}
}
int solve(int m , int l){
	populate_last();
	
	vector<vector<int> > dp(n , vector<int>(m,0));
	dp[0][(s[0]-'0')%m] = 1;
	
	int count=dp[0][l] , index , offset;
	for(int i=1;i<n;++i){
		offset = s[i]-'0';
		for(int j=0;j<m;++j){
			index = (10*j+offset)%m;
			if(debug)cout<<j<<"->"<<index<<endl;
			dp[i][index] += dp[i-1][j];
		}
		++dp[i][offset%m];
		
		count += dp[i][l];
		
		if(debug){
			cout<<i<<"# offset:"<<offset<<" count:"<<count<<endl;
			for(int j=0;j<m;++j){
				cout<<dp[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	
	return count;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	scanf("%s",s);
	n = strlen(s);
	
	int q , m , l;
	scanf("%d",&q);
	while(q--){
		scanf("%d %d",&m,&l);
		cout<<solve(m,l)<<endl;
	}
	
	return 0;
}

